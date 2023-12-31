# 字符编码做什么事情

>	在计算机眼里所有的文字都是0和1组成的字符串，为了让汉字可以在屏幕上显示，需要做一下两件事：

1. 给汉字一个独一无二的数字编码，做一个数字编号到汉字的mapping关系。
2. 把数字编号能用0和1来表示

第二件事不是字节把数字编号用二进制表示出来那么简单，还要处理多个字连在一起如何分隔的问题。

第2件事情通常解决方案要么规定好每个字节长度，要么就是在用0和1表示的时候，不仅需要表示出数字编码，还要暗示给计算机接下来多少个连续byte构成一个字。

通常所说的Unicode，只做了第一件事，并且是给全世界所有语言的所有文字或字母一个独一无二的数字编码，这样只要设计一种机制做第二件事情来表示Unicode，就可以显示全世界范围内的任何文字了。Unicode具体对所有语言的每个字母、文字数字编号可以从Unicode官网查询。

## 常见中文编码的关系
![](https://pic4.zhimg.com/80/v2-0d0285e7b9433eeedf7e705d6e082d13_720w.webp)

ASCII被所有兼容，常见的UTF8与GBK之间出了ASCII部分只蛙诶没有交集，这也是平时业务中导致乱码的场景，使用UTF*8去读取GBK编码的文字，可能会看到各种乱码。GB系列的几种编码，GB18030兼容GBK，GBK又兼容GB2312.


## GB2312 GBK GB18030编码

> GB 全称 GuoBiao国标，GBK全程GuoBiaoKuozhan国标扩展。**GB18030编码** 兼容GBK,GBK兼容GB2312。

### GB2312
**最早一版的中文编码** ，**每个字占据2bytes** 。由于要和ASCII兼容，2bytes最高位不可以为0了（否则会与ATCII会冲突 。在GB2312中收录6763汉字和682特殊字符。

GB2312编码表有个值得注意的点，这个表中也有一些数字和字母，与ASCII里面的字母非常像。例如A3B2对应的是数字2（如下图），但是ASCII里面50（十进制）对应的也是数字2。他们的区别就是输入法中所说的“半角”和“全角”。全角的数字2占两个字节。

![](https://pic3.zhimg.com/80/v2-69e860395dbb458f82e6a9a930cec78a_720w.webp)

在打字或编程中都是使用边角，即ASCII来编写数字或英文字母。特别是编程中，如果使用全角的数字或字母，编译器可以不会识别。

### GBK
由于GB2312只有6763个汉字，我汉语博大精深，只有6763个字怎么够？于是GBK中在保证不和GB2312、ASCII冲突（即兼容GB2312和ASCII）的前提下，也用每个字占据2bytes的方式又编码了许多汉字。经过GBK编码后，可以表示的汉字达到了20902个，另有984个汉语标点符号、部首等。值得注意的是这20902个汉字还包含了繁体字，但是该繁体字与台湾Big5编码不兼容，因为同一个繁体字很可能在GBK和Big5中数字编码是不一样的。

### GB18030
这时候显然只用2bytes表示一个字已经不够用了（2bytes最多只有65536种组合，然而为了和ASCII兼容，最高位不能为0就已经直接淘汰了一半的组合，只剩下3万多种组合无法满足全部汉字要求）。因此GB18030多出来的汉字使用4bytes编码。当然，为了兼容GBK，这个四字节的前两位显然不能与GBK冲突（实操中发现后两位也并没有和GBK冲突）。

### UTF8
UTF8可以表示出世界上所有的文字。UTF8与前面说的GB系列编码不兼容，所以如果一个文件中即有UTF8编码的文字，又有GB18030编码的文字，那绝对会有乱码。

Unicode赋予了全世界所有文字和符号一个独一无二的数字编号，UTF8所做的事情就是把这个数字编号表示出来（即解决前文提到的第2件事情）。UTF8解决字符间分隔的方式是数二进制中最高位连续1的个数来决定这个字是几字节编码。0开头的属于单字节，和ASCII码重合，做到了兼容。

![](https://pic3.zhimg.com/80/v2-ed2d91622887f113588d1e1c96a8c22e_720w.webp)
以三字节为例，开头第一个字节的”1110”，有连续三个1，说明包括本字节在内，接下来三个字节一起构成了一个文字。凡是不属于文字首字节的byte都以“10”开头，上表中标注X的位置才是真正用来表示Unicode数值的



