    1. 第一部分为位图文件头BITMAPFILEHEADER,是一个结构体，如下：

```
typedef unsigned short WORD;
typedef unsigned int   DWORD;
typedef struct tagBITMAPFILEHEADER {
    WORD      bfType;               //指定文件类型，必须是0x4D42，即字符串"BM"
    DWORD     bfSize;               //指定文件大小，包括这14个字节
    WORD      bfReserved1;          //保留字，不考虑
    WORD      bfReserved2;          //同上
    DWORD     bfOffBits;            //从头文件到实际的位图数据的偏移字节数，即前三个部分的长度之和
} BITMAPFILEHEADER;  
```

    2. 第二部分为位图信息头BITMAPINFOHEADER，如下：

```
typedef struct tagBITMAPINFOHEADER {
    DWORD       biSize;             //指定这个结构体的长度，为40
    LONG        biWidth;            //指定图像的宽度，单位：像素
    LONG        biHeight;           //指定图像的高度，单位：像素
    WORD        biPlanes;           //必须是1
    WORD        biBitCount;         //指定表示颜色要用到的位数，常用的值为1(黑白)/4(16位色图)/8(256色)/24(真彩色图)
    DWORD       biCompression;      //指定位图是否压缩，有效值为BI_RGB,BI_RLE8，BI_RLE4，BI_BITFIELDS,其中BI_RGB为非压缩
    DWORD       biSizeImage;        //指定位图数据占用的字节数，公式：biSizeImage = biWidth' ×　biHeight(biWidth'而不是biWidth,biWidth'必须是4的整数倍),如果biCompression为BI_RGB，则该项可能为0
    LONG        biXPelsPerMeter;    //指定目标设备的水平分辨率，单位是每米的像素个数
    LONG        biYPelsPerMeter;    //指定目标设备的垂直分辨率
    DWORD       biClrUsed;          //指定本图像实际用到的颜色数，如果该值为0，则用到的颜色数为2^biBitCount
    DWORD       biClrImportant;     //指定本图像中重要的颜色数，如果该值为0，则认为都是重要的
}BITMAPINFOHEADER;
```
    该结构体固定长度为40个字节，LONG为32位整数
    3. 调色板Palette，这里是对需要调色板的位图而言，有些位图，如真彩色，是不需要调色板的，
     BITMAPINFOHEADER后直接是位图数据。
     
```
typedef struct tagRGBQUAD {
    BYTE    rgbBlue;                //该颜色的蓝色分量
    BYTE    rgbGreen;               //该颜色的绿色分量
    BYTE    rgbRed;                 //该颜色的红色分量
    BYTE    rgbReserved;            //保留值
} RGBQUAD;
```

    4. 第四部分是实际的图像数据。对于用到调色板的位图，图像数据就是该像素在调色板中的索引值
。对于真彩色图，图像数据就是实际的R、G、B值。

 - 注意点：
    - 每一行的字节数必须是4的整倍数，如果不是，则需要补齐。
    - 一般来说.bMP文件的数据从下到上，从左到右的。也就是说，从文件中最先读到的是图象最下
        面一行的左边第一个象素，然后是左边第二个象素……接下来是倒数第二行左边第一个象素，
        左边第二个象素……依次类推 ，最后得到的是最上面一行的最右一个象素。