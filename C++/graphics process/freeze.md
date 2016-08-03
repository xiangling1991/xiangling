##图片处理算法-冰冻

```
public Bitmap render(Bitmap bitmap)
{
    if(!bitmap)
        return null;
    
    int width = bitmap.GetWidth();
    int height = bitmap.GetHeight();
    
    int[] pixels = new int[width * height];
    bitmap.GetPixels(pixels, 0, width, 0, 0, width, height);
    
    for(int i = 0; i< height; i++) {
       for(int j=0 ; j<width ; j++) {
            int pixel = pixels[i*width +j];
            int r = (pixel & 0x00ff0000)>>16;
            int g = (pixel & 0x0000ff00)>>8;
            int b = (pixel & 0x000000ff);

            r = better(r-g-b);
            g = better(g-r-b);
            b = better(b-r-g);
            pixels[i*width +j] = (pixel & 0xff000000) + (r<<16)+ (g<<8) +b;
       }
    }
    
    return Bitmap.CreateBitmap(pixels, width, height, Config.ARGB_8888);
}

public int better(int value) 
{
    value = value * 3 / 2;
    if(value < 0)
        value = -value;
    if(value > 255)
        value = 255;
    
    return value;
}
```
对rgb 值一次做better处理，同时在下一步用到上一步已经处理好的值。