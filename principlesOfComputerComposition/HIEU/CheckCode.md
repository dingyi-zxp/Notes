# 奇偶校验
奇偶校验用来检测数据传输过程中是否发生错误，是众多校验码中最为简单的一种。

奇校验： 原始码流+校验位 总共奇数个1
偶校验： 原始码流+校验位 总共有偶数个1

## 算法
在原始码流后面，加上校验位。校验位只有以为，要么是0，要么是1。校验码还可以在码流前面。

![](https://pic2.zhimg.com/80/v2-2c0f22d050dcbccef85eacee21de747d_720w.webp)

红色表示校验位
![](https://pic1.zhimg.com/80/v2-ed494a01b2527927febaac2845b51d9c_720w.webp)

### 应用举例
奇偶校验最常见的应用场景是ASCII码。
> ASCII码占用一个字节，低7位是有效为，最高位是作奇偶校验

![](https://pic4.zhimg.com/80/v2-75e6aec0f7a6185d3c177b934968459f_720w.webp)

> 奇校验一个重要的特征是产生不了全0代码

# CRC校验
> Cyclic Redundancy Check 循环冗余校验是一种根据网络数据包或计算机文件等数据产生简短固定位数校验码的一种通信编码技术，主要用来检测或校验数据传输或保证后可能出现的错误。利用除法及余数的原理来做错误侦测。

常见应用于以太网/USB通信，压缩解压，视频编码图像存储，磁盘读写等。

## CRC参数模型
完整的CRC参数模型包含：WIDTH，POLY，INLY，INIT，REFIN，REFOUT，XOROUT。

- NAME:参数模型名称。
- WIDTH：生成CRC数据位宽； CRC-8生成的CRC为8位
- POLY：十六进制多项式，省略最高位1，如x8 + x2 +x +1，二进制1 0000 0111，省略最高位1，转换为十六进制为0x07。
- INIT：CRC初始值，和WIDTH位宽一致。
- REFIN：true/false，在进行计算之前，原始数据是否翻转，如原始数据：0x34 = 0011 0100,如果REFIN为true，进行翻转之后为0010 1100 = 0x2c
- REFOUT：true/false，运算完成后，得到CRC值是否进行翻转，如计算得到的CRC值:0x97=1001 01111，如果REFOUT为true，进行翻转后为1110 1001 = 0xE9
- XOROUT：计算结果与此参数进行异或运算后得到最终的CRC值，和WIDTH位宽一致。

![](https://pic2.zhimg.com/80/v2-91f148259b466e4a75a10c6607370855_1440w.webp)


### CRC计算
#### 原始数据：0x34使用CRC-8/MAXINg参数模型
![](https://pic2.zhimg.com/80/v2-2237c19868f68ce99205668ccd9debb5_720w.webp)

# 海明码

