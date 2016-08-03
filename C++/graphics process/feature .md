##介绍图像的处理-羽化特效

```
float mSize = 0.5f;
public Bitmap render(Bitmap bitmap)
{
    if(!bitmap) 
        return null;
    
    final int SIZE = 32768;
    int width = bitmap.GetWidth();
    int height = bitmap.GetHeight();
    int ratio = width > height ? height * SIZE / width : width * SIZE / height;
    
    int cx = width >> 1;
    int cy = height >> 1;
    int max = cx * cx + cy * cy;
    int min = (int)(max * (1 - mSize));
    int diff = max - min;
    
    int[] pixels = new int[width * height];
    bitmap.GetPixels(pixels, 0, width, 0, 0, width, height);
    
    for(int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++) {
            int pixel = pixels[i * width + j];
            int r = (pixel & 0xff0000) >> 16;
            int g = (pixel & 0x00ff00) >> 8;
            int b = (pixel & 0x0000ff);
            
            int dx = cx - j;
            int dy = cy - i;
            
            if (width > height) 
                dx = (dx * ratio) >> 15;
            else
                dy = (dy * ratio) >> 15;
            
            int dstSq = dx * dx + dy * dy;
            float v = ((float) dstSq / diff) * 255;
            r = (int)(r + v);
            g = (int)(g + v);
            b = (int)(b + v);
            r = (r > 255 ? 255 : (r < 0 ? 0: r));
            g = (g > 255 ? 255 : (g < 0 ? 0: g));
            b = (b > 255 ? 255 : (b < 0 ? 0: b));
            pixels[i * width + j] = (pixel & 0xff0000) + (r << 16) + (g << 8) + b;
        }
    }
    
    return Bitmap.CreateBitmap(pixels, width, height, Config.ARGB_8888);
}
```

::注::
    羽化就是使选定范围的图边缘达到朦胧的效果。
    羽化值越大，朦胧范围越宽，羽化值越小，朦胧范围越窄，
    
算法分析：
    - 通过对rgb值增加额外的V值实现朦胧效果
    - 通过控制V值的大小实现范围控制
    - V = 255 * 当前点Point距中点距离的平方s1 / (顶点距中点的距离平方 *mSize)s2;
    - s1 又根据ratio修正dx dy直