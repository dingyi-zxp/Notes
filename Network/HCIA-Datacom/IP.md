# 基本认识
IP在TCP/IP参考模型中处于第三层网络层。

> 网络层主要的作用：`实现主机与主机之间的通信，叫做点对点(end to end) 通信`。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/2.jpg)

## 网络层和数据链路层
> IP的作用主机之间通信用的，MAC作用则是实现`直连`的两个设备之间通信，而IP则负责在 没有直连 的两个网络之间通信传输。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/3.jpg)

源IP地址和目标IP地址在传输过程中不会变化的（前提：没有使用NAT网络，只有源MAC地址和目标MAC地址一直在变化。

## IP 地址分类
IP地址分类为：A、B、C、D、E类

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/7.jpg)

黄色位分类号，用来区分IP地址类别。

### A、B、C类地址
A、B、C类地址主要分为两部分，分别位为`网络号和主机号`

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/8.jpg)

#### 最大主机个数
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/9.jpg)

在IP地址中，有两个特殊的IP，一个是全为1和全为0

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/10.jpg)

- 主机号全为 1 指定某个网络下的所有主机，用于广播
- 主机号全为 0 指定某个网络


#### 广播网络
> 广播网络地址用于在同一个链路中互相连接的主机之间发送数据包。

广播地址分为两种：
1. 在本网络内广播的角做本地广播。
2. 在不同网络之间的广播叫做直接广播。
	1. 例如网络地址为 192.168.0.0/24 的主机向 192.168.1.255/24 的目标地址发送 IP 包。收到这个包的路由器，将数据转发给 192.168.1.0/24，从而使得所有 192.168.1.1~192.168.1.254 的主机都能收到这个包（由于直接广播有一定的安全问题，多数情况下会在路由器上设置为不转发。） 。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/11.jpg)


### D,E类地址
D类和E类地址没有主机号，不可用于主机IP，D类常用于`多播`，E类用于预留的分类，暂时未使用。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/12.jpg)

#### 多播地址
> 多播地址**将包发送给特定组内所有主机** 
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/13.jpg)

多播使用的D类地址，其前四位是`1110`表示多播地址，剩下28位是多播组编号。
从 224.0.0.0 ~ 239.255.255.255 都是多播的可用范围，其划分为以下三类：

224.0.0.0 ~ 224.0.0.255 为预留的组播地址，只能在局域网中，路由器是不会进行转发的。
224.0.1.0 ~ 238.255.255.255 为用户可用的组播地址，可以用于 Internet 上。
239.0.0.0 ~ 239.255.255.255 为本地管理组播地址，可供内部网在内部使用，仅在特定的本地范围内有效。

#### IP分类的优点
1. 可以快速找出网络地址和主机地址
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/14.jpg)

#### IP分类的缺点
1. 同一个网络下没有地址层次。比如一个公司里用了 B 类地址，但是可能需要根据生产环境、测试环境、开发环境来划分地址层次，而这种 IP 分类是没有地址层次划分的功能，所以这就缺少地址的灵活性
2. A、B、C类有个尴尬处境，就是不能很好的与现实网络匹配。
	1. C 类地址能包含的最大主机数量实在太少了，只有 254 个，估计一个网吧都不够用。
	2. 而 B 类地址能包含的最大主机数量又太多了，6 万多台机器放在一个网络下面，一般的企业基本达不到这个规模，闲着的地址就是浪费。

这两个缺点可以通过`CIDR`无分类地址解决。


## 无分类地址CIDR
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/15.jpg)
子网掩码，掩码的意思就是掩盖掉主机号，剩余的就是网络号。
将子网掩码和 IP 地址按位计算 AND，就可得到网络号。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/16.jpg)

### 网络号和主机号
两台主机需要通信，需要判断是否在同一个广播域中，即网络地址相同。网络地址相同，表明接收方在本网络上，可以把数据包直接发送到目标主机。

路由器寻址工作中，也是通过这样来找到对应的网络号，把数据包转发给对应的网络。
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/17.jpg)

### 公有IP管理
> 私有IP地址通常是内部IT人员管理，公有IP地址由`ICANN`互联网名称与数字地址分配机构。

IANA 是 ICANN 的其中一个机构，它负责分配互联网 IP 地址，是按州的方式层层分配。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/24.jpg)

- ARIN 北美地区
- LACNIC 拉丁美洲和一些加勒比群岛
- RIPE NCC 欧洲、中东和中亚
- AfriNIC 非洲地区
- APNIC 亚太地区

其中，在中国是由 CNNIC 的机构进行管理，它是中国国内唯一指定的全局 IP 地址管理的组织。

### IP地址与路由控制
IP地址的网络地址这部分用于进行路由控制。


路由控制表中记录网络地址与下一步应该发送至路由器的地址。在主机和路由器上都会有各自路由器控制表。


在发送 IP 包时，首先要确定 IP 包首部中的目标地址，再从路由控制表中找到与该地址具有相同网络地址的记录，根据该记录将 IP 包转发给相应的下一个路由器。如果路由控制表中存在多条相同网络地址的记录，就选择相同位数最多的网络地址，也就是最长匹配。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/25.jpg)

#### 环回地址是不会流向网络
环回地址是在同一台计算机上的程序之间进行网络通信时所使用的一个默认地址。

计算机使用一个特殊的 IP 地址 127.0.0.1 作为环回地址。与该地址具有相同意义的是一个叫做 localhost 的主机名。使用这个 IP 或主机名时，数据包不会流向网络。

### IP分片与重组
> 每种数据链路的最大传输单元`MTU`都不是相同的，如 FDDI 数据链路 MTU 4352、以太网的 MTU 是 1500 字节等。
> 每种数据链路的 MTU 之所以不同，是因为每个不同类型的数据链路的使用目的不同。使用目的不同，可承载的 MTU 也就不同。

当IP数据包大小大于MTU时，IP数据包就会被分片。分片之后只能在目标主机进行重组，路由器是不会进行重组。


假设发送方发送一个 4000 字节的大数据报，若要传输在以太网链路，则需要把数据报分片成 3 个小数据报进行传输，再交由接收方重组成大数据报。
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/26.jpg)

> 在分组传输中，一旦某个分片丢失，会造成整个IP数据报作废，所以引用了TCP的`MSS`也就是在TCP层进行分片不由IP层分片，对于UDP尽量不发送大于`MTU`的数据报文。

### IPv6
IPv6为128位，有更好的安全性和扩展性。
#### IPv6优点
1. 可自动配置，即使没有DHCP服务器也可以实现自动分配IP地址。
2. 包头包首部长度晒用固定值40字节，去掉包头校验和，简化首部结构，减轻路由器负荷，提高transmission power。
3. 有应对伪造IP地址的网络安全功能以及防止线路窃听功能，提升安全性。


#### 识别
IPv4 地址长度共 32 位，是以每 8 位作为一组，并用点分十进制的表示方式。

IPv6 地址长度是 128 位，是以每 16 位作为一组，每组用冒号 「:」 隔开。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/27.jpg)
如果出现连续的 0 时还可以将这些 0 省略，并用两个冒号 「::」隔开。但是，一个 IP 地址中只允许出现一次两个连续的冒号
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/28.jpg)

#### 结构
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/29.jpg)

#### IPv6单播地址类型
对于一对一通信的 IPv6 地址，主要划分了三类单播地址，每类地址的有效范围都不同。

- 同一个链路单播通信，不经过路由器，可以使用**链路本地单播地址** ，IPv4没有此类型
- 在内网里单播通信，可以使用**唯一本地地址** ，相当于IPv4私有IP
- 在互联网通信，可以使用**全局单播地址** ，相当于IPv4公有IP

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/30.jpg)

#### IPv4 IPv6首部
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/31.jpg)
- 取消首部校验和字段。因为在数据链路层和传输层都会校验，因此 IPv6 直接取消了 IP 的校验。
- 取消了分片/重新组装相关字段。 分片与重组是耗时的过程，IPv6 不允许在中间路由器进行分片与重组，这种操作只能在源与目标主机，这将大大提高了路由器转发的速度。
- 取消选项字段。 选项字段不再是标准 IP 首部的一部分了，但它并没有消失，而是可能出现在 IPv6 首部中的「下一个首部」指出的位置上。删除该选项字段使的 IPv6 的首部成为固定长度的 40 字节。


