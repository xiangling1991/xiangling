1. 彩色图像的RGB和亮度Y，色差I，信号值Q的关系：
```
    | Y |    |0.31  0.59  0.11  |   | R |
    | I | =  |0.60 -0.28  -0.32 | * | G |
    | Q |    |0.21  -0.52 -0.31 |   | B |

    即  Y = 0.31R + 0.59G+0.11B
     I  = 0.60R - 0.28G - 0.32B
     Q = 0.21R - 0.52B - 0.31B
```

2. 彩色图像的逆反处理
```
   将对应的(R,G,B)像素替换成(255-R,255-G,255-B)
```
3. 彩色图像的平滑处理
    将一个图片每一个像素的颜色由其相邻的n*n个像素的平均值来替代，如将一个3*3的点阵，设带平滑的像素为f(i,j)，平滑后g(i,j)，那么：
```
    f(i - 1,j - 1)      f(i - 1, j)     f(i - 1, j + 1)
    f(i, j - 1)         f(i, j)         f(i, j + 1)
    f(i + 1, j - 1)     f(i + 1, j)     f(i + 1, j + 1)
    
    g(i,j)=( f(i-1,j-1) + f(i-1,j) + f(i-1,j+1) + f(i,j-1) + f(i,j) + f(i,j+1) + f(i+1,j-1) + f(i+1,j) + f(i+1,j+1) ) / 9

    //注意对于边缘的像素的情况，防止越界
```

4. 彩色图像的霓虹处理
    同样以上面的3*3的点阵为例，目标像素g(i,j)应当以f(i,j)与f(i,j+1)，f(i,j)与f(i+1,j)的梯度作为R,G,B分量，我们不妨设f(i,j)的RGB分量为(r1, g1, b1), f(i,j+1)为(r2, g2, b2), f(i+1,j)为(r3, g3, b3), g(i, j)为(r, g, b),那么结果应该为
```
r = 2 * sqrt( (r1 - r2)^2 + (r1 - r3)^2 )
g = 2 * sqrt( (g1 - g2)^2 + (g1 - g3)^2 )
b = 2 * sqrt( (b1 - b2)^2 + (b1 - b3)^2 )
```

5. 彩色图像的锐化处理
    设f(i,j)像素为(r1, g1, b1) , f(i-1,j-1)像素为(r2,g2,b2), g(i,j)像素为(r,g,b),则
```
r = r1 + 0.25 * |r1 - r2|
g = g1 + 0.25 * |g1 - g2|
b = b1 + 0.25 * |b1 - b2|
```

6. 彩色图像的浮雕处理:  g(i, j) = f(i, j) - f(i - 1, j) + 常数 ， 这里的常数通常选作128

7. 彩色图像的灰度处理:  r = r1 / 64 * 64  g = g1 / 64 * 64  b = b1 / 64 * 64  注意这里的除法是程序设计当中的整数除法。

8. 彩色图像的镶嵌处理:  与彩色图像的平滑处理类似，但是不同的地方在于3*3的目标像素点都取作g(i,j)，而不是另外的再去取所在矩阵像素的平均值。