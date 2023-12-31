# TCP
 > TCP Transmission Control Protocol 传输控制协议；面向连接的协议，在收发数据前需要建立可靠连接。 
> TCP连接需要经历三次对话才能建立。
> TCP 协议是一种面向连接的、可靠的、基于数字流 的运输层网络协议，TCP是全双工模式 ，所以需
要四次挥手来关闭连接。
> - 面向连接：一定是【一对一】才可以连接，不像UDP协议可以一个主机同时可以向多个主机发送信息，一对多是无法做到的
> - 可靠的：网络链路出现怎样的链路变化，都可以保证一个报文能到达接收端
> - 字节流：用户信息通过TCP协议传输时，信息可能被操作系统分组成多个TCP报文，如果接收方的程序不知道消息的边界，是无法读出一个有效的用户信息的。TCP报文是有序的，当前一个TCP报文没有收到的时候，即使接收到后面的TCP报文，那么也不能给应用层去处理，同时能对重复的报文会进行自动丢弃。
## TCP包首部 

网络传输数据包由两部分部分组成                                                                  
1. 协议所要用到的首部，标明协议应该如何读取数据。 
2. 另一部分是上层串来的数据。                    


![TCP header](https://static.coonote.com/v2-2aa192d35fb785d6ff699035d060dc47_1440w.jpg)         
![](https://static.coonote.com/20180520124426161.jpg)

### TCP头部说明
- 源端口和目的端口：**各占2字节** 端口是传输层与应用层的服务接口，传输层的复用和分用功能都要通过端口才能实现；
- 序号：占**4字节** 。TCP连接中传送的数据流中的每一个字节都编上一个序号。序号字段的值则指的是报文段**所发送的数据的第一字节的序号** ；
- 确认号：**4字节** 。期望收到对方的下一个报文段的数据的第一个字节序号。
- 数据偏移/首部长度：4字节。指出TCP报文段的数据起始处距离TCP报文段的起始处有多少bit。“数据偏移”的单位是32位字。
- 保留：6位。保留为今后使用，
- 紧急URG：URG=1表明紧急字段有效，让系统知道此报文段有紧急数据，尽快传输（相当于高优先级的数据
- 确认ACK：ACK=1时确认号字段才有效；ACK=0时，确认号无效
- PSH（Push：接收TCP收到PSH=1的报文段，就会尽快地交付应用进程，而不再等到整个缓存都填满后再向上交付
- RST（ReSeT：当RST=1时，表明TCP连接中出现严重差错，必须释放连接，然后重新建立运输连接
- 同步SYN：SYN=1表示这是一个连接请求或连接接受报文
- 终止FIN：用来释放一个连接。FIN=1表明此报文段的发送端的数据已经发送完毕，并要求释放运输连接
- 检验和：2字段。检验和字段检验的范围包括首部和数据两部分。计算检验和时，要在TCP报文段的前面加上12字节的伪首部
- 紧急指针：占16位，指出在报文段中紧急数据共有多少字节（紧急数据在报文数据的最前面
- 选项：长度可变。TCP最初只规定一种选项，即最大报文长度MSS。MSS 告诉对方 TCP：“我的缓存所能接收的报文段的数据字段的最大长度是 MSS 个字节.” [MSS(Maximum Segment Size)是 TCP 报文段中的数据字段的最大长度.数据字段加上 TCP 首部才等于整个的 TCP 报文段]
- 填充：为了使整个首部长度是4字节的整数倍
- 其他选项：
	- 窗口扩大：3字节。其中有一个字节表示移位值S。新的窗口值等于TCP首部中的窗口位数增大到（16+S，相当于把窗口值左移动S位后获取实际窗口大小
	- 时间戳：占10字节，其中最主要的字段时间戳字节（4字节和时间戳回送回答字段（4字段
	- 选择确认：接收方收到了和前面的字节流不断的2字节。如果这些字节的序号都在接收窗口之内，那么接受者就先手下这些数据，但要把这些信息准确地告诉发送，使发送方不要再重复发送这些已收到的数据。


#### 重点介绍
1. 序号：seq序号，32位，用来表示从TCP源端向目的端发送的字节流，发起方发送数据时对此进行标记。
2. 确认序号： ack序号，32位，只有ACK标志位1时，确认序号才有效，ack=seq+1
3. 标识为：共6个
	1. ACK:确认序号有效
	2. FIN：释放一个连接
	3. PSH：接收方应该尽快将这个报文交给应用层
	4. RST：重置连接
	5. SYN：发起一个新连接
	6. URP：紧急指针（urgent pointer
	
**注意** 

不要将确认序号ack与标志位重点 ACK搞混了。
确认方ack发起方seq+1，两端配对。

## TCP连接
TCP连接用于保证可靠性和流量控制维护的某些状态信息，这些信息的组合，包括Socket、序列号和窗口大小称为连接
![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230428466.png)


建立一个TCP连接需要客户端与服务端达成上述三个信息的共识：
1. Socket：由IP地址和端口号组成
2. 序列号：解决乱序问题
等
3. 窗口大小：用来做流量控制

### 如何唯一确定一个TCP连接
TCP四元组可以唯一的确定一个连接，四元组包括:
1. 源地址
2. 源端口
3. 目的地址
4. 目的端口

![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230433082.png)

源地址和目的地址的字段（32位 是在IP头部中，作用是通过IP协议发送报文给对方主机。

源端口和目的端口的字段（16位 是在TCP头部中，作用告诉TCP协议应该把报文发送给那个进程

#### 一个IP服务端监听一个端口，它的TCP最大连接数是多少？
对IPv4客户端IP数最多位2^32，客户端端口数最多为2^16，服务端单机最多TCP连接数量约为2^48次方。

服务端最大并发TCP连接数不能达到理论上线，会受以下因素影响：
- 文件描述符限制，每个TCP连接都是一个文件，如果文件描述被占满了，会发生Too many open files。Linux对可以打开的文件描述符的数量分别作了三个方向限制：
	- 系统级：当系统可以打开的最大量，通过`cat /proc/sys/fs/file-max`可以查看
	- 用户级：指定用户可以打开的最大数量通过`cat /etc/security/limits.conf`查看
	- 进程级：单个进程可以打开的最大数量，通过`cat /proc/sys/fs/nr_open`查看
- 内存限制，每个TCP连接都会占用一定内存，操作系统的内存是有限的，内存被资源占满后会发生OOM。

## UDP和TCP的区别，分别应用的场景
UDP不提供复杂的控制机制，利用IP提供面向**无连接** 的通信服务

UDP协议非常的简，头部8字节
![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230439961.png)
- 目标和源端口：主要是让UDP把报文发给指定端口
- 包长度： 该字段保存UDP首部长度和数据长度和
- 校验和：为了提供可靠UDP首部和数据设计，防止收到在网络传输中受损的UDP包

### TCP和UDP的区别
1. 连接
- TCP 面向连接的传输层协议，传输数据需要先建立连接
- UDP不需要连接，即刻传输数据

2. 服务对象
- TCP只能一对一的两点服务
- UDP支持一对多，一对一、多对多的交互通信

3. 可靠性
- TCP 可靠交付数据
- UDP 尽最大努力交付，不能保证数据。

4. 拥塞控制、流量控制
- TCP 拥有拥塞控制和流量控制来保证数据传输的可靠性
- UDP 没有这些功能，即使网络拥堵了，也不会影响UDP发送速率

5. 首部开销
- TCP 首都较长，默认20字节使用选项字段会变得更长最大60字节
- UDP 只有固定的8字节

6. 传输方式
- TCP 是流式传输，没有边界，保证顺序和可靠
- UDP 是一个包一个包发送，有边界，可以会丢包和乱序

7. 分片不同
- TCP 数据大小如果大于MSS大小，会在传输层进行分片，目标主机收到后，也同样在传输层组装TCP数据包，如果中途丢失一个分片，只需要传输丢失的分片。
- UDP 数据大小如果大于MTU大小，On IP层进行分片，目标主机收到后，在IP层组装数据，接着在传给传输层。


> TCP有可变长的 **选项** 字段，UDP头部不会改变，UDP不需要记录

#### 头长度
TCP计算负载数据长度：
![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230445811.png)
IP总长度和IP首部长度，在IP首部格式是已知的。TCP首部长度是在TCP首部已知。所以可以获得TCP数据长度。

UDP也是基于IP层，也可以通公式获得，那为什么还需要报长度？
- 第一种说法：因为为了网络设备硬件设计和处理方便，首部长度需要是 4 字节的整数倍。如果去掉 UDP 的「包长度」字段，那 UDP 首部长度就不是 4 字节的整数倍了，所以我觉得这可能是为了补全 UDP 首部长度是 4 字节的整数倍，才补充了「包长度」字段。
- 第二种说法：如今的 UDP 协议是基于 IP 协议发展的，而当年可能并非如此，依赖的可能是别的不提供自身报文长度或首部长度的网络层协议，因此 UDP 报文首部需要有长度字段以供计算。


#### TCP和UDP可以使用同一个端口
>数据链路层中，通过MAC地址来寻找局域网中的主机。在网络层可以通过IP地址来寻找网络中互连的主机或路由器。在传输层需要通过端口寻址，来识别同一计算机中同时通信的不同应用程序。

传输层的端口号的作用是为了区分同一主机上不同应用程序的数据包。

TCP和UDP传输层中在内核是两个独立的软件模块

主机收到数据包后，可以在IP包头的 协议号 字段知道该数据包是TCP/UDP，所以可以根据这个信息确定送给哪个模块（TCP/UDP 处理，送给TCP/UDP模块的报文根据 端口号 确定送给哪个程序处理。

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/network/port/tcp%E5%92%8Cudp%E6%A8%A1%E5%9D%97.jpeg)

TCP/UDP各自端口号是互相独立的；如果TCP端口号为80，UDP端口号也为80 二者不会冲突。

## TCP 连接建立
TCP 是面向连接协议，在使用TCP前必须要建立连接，建立连接需要通过**三次握手** 来进行。
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost4/%E7%BD%91%E7%BB%9C/TCP%E4%B8%89%E6%AC%A1%E6%8F%A1%E6%89%8B.drawio.png)

最开始客户端和服务端处于`CLOSE`状态。先是服务端主动监听某个端口处于`LISTEN`状态。

![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230500953.png)


客户端会随机初始化序号`client_isn`，将序号置于TCP首部的 序号 字段，同时把`SYN` 标志位置为1，表示SYN报文。接着把第一个SYN报文发送给服务端，表示向服务端发起连接，该报文不包含应用层数据，之后客户端处于`SYN-SENT`状态。


![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230504118.png)

服务端接收到客户端`SYN`报文后，首先客户端也随机初始化自己的序号`server_isn`,将此序号填入TCP首部 序号 字段中，其次把TCP首部的 确认应答号 字段填入`client_isn + 1`，接着把 SYN 和 ACK标志位置为1。最后把报文发送给可符号，报文也不含应用层数据，之后服务端处于`SYN-RCVD`状态。

![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230508297.png)

客户端收到服务端报文后，还要向服务端回应最后一个报文，首先应该答报文TCP首部ACK标志为1，其次 确认应答号 字段填入`server_isn + 1`,最后把报文发送给服务端，这次报文可以携带客户端到服务端的数据，之后客户端处于`ESTABLISHED`状态。

服务端收到客户端的应答报文后，也会进入`ESTABLISHED`状态。

> 第三次握手是可以携带数据，前两次握手是不可以携带数据的
>
> 完成三次握手后，双方都处于`ESTABLISHED`状态，此时连接已经建立完成，C/S可以互相发送数据。

### Linux查看TCP状态
`netstat -napt`
![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230520683.png)


## 为什么是三次握手？不是四次或两次？
通常回答：三次握手才能保证双方才具有接收和发送的能力

> TCP连接： 由于保证可靠性和流量控制维护的某些状态信息，这些信息的组合，包括*Socket、序列号和窗口大小* 称为连接

- 三次握手才可以阻止重复历史连接的初始化（主要原因
- 三次握手才可以同双方的初始序列号
- 三次握手才可以避免资源浪费

### 避免历史连接
RFC793指出TCP连接使用三次握手的首要原因

The principle reason for the three-way handshake is to prevent old duplicate connection initiations from causing confusion.

三次握手主要原因是为了**防止旧的重复连接初始化造成混乱** 

> 客户端先发送了 SYN（seq = 90）报文，然后客户端宕机了，而且这个 SYN 报文还被网络阻塞了，服务端并没有收到，接着客户端重启后，又重新向服务端建立连接，发送了 SYN（seq = 100）报文（注意！不是重传 SYN，重传的 SYN 的序列号是一样的）。

![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230525514.png)

- 一个 旧SYN报文 比最新的 SYN报文早到达服务端，那么服务端就会回一个 `SYN+ACK` 报文给服务端，此报文的确认号为`91(90+1)`
- 客户端接收到后，发现自己预期收到的确认号应该是100+1而不是90+1，于是会回RST报文。
- 服务端接收到RST报文后就会释放连接
- 后续最新的SYN抵达服务端后，客户端与服务端就可以正常完成三次握手了。

上述的 旧SYN报文 称为历史连接，TCP使用三次握手建立连接**最主要的原因是为了防止 历史连接 初始化了连接** 

如果是两次握手连接，就无法阻止历史连接。
> 在两次握手的情况下，服务端没有中间端状态给客户端来阻止历史连接，导致服务端可以建立一个历史连接，造成资源浪费。

为了解决这种现象，最好是在服务端发送数据前（建立连接前，阻止掉历史连接，这样就不会造成资源浪费。

**TCP使用三次握手建立连接最主要的原因是为了防止 历史连接 初始化了连接** 


### 同步算法初始序列号
> TCP 协议通信双方，必须维护一个 **序列号** ，序列号是可靠传输的一个关键因素。
- 接收方可以去除重复数据；
- 接收方可以根据数据包的序列号按序号接收；
- 可以表示发送出去的数据包中，那些是已经被对方收到的（通过ACK报文中的序列号知道；

客户端发送携带 初始序列号 的 SYN 报文的时候，需要服务端回一个 ACK 应答报文，表示客户端的SYN报文已被服务端成功接收，当服务端发送 初始序列号 给客户端的时候，依然也要得到客户端的应答回应；**这样的一来一回，才能保证双方的初始序列号能被可靠的同步** 

![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230639121.png)

> 四次握手也可以实现可靠同步双方的初始序列号，但第二步和第三步可以优化成一步，所以就成了三次握手。

两次握手只保证了一方的初始序列号能被对方成功接收，没有办法保证双方的初始序列号都能被确认接收。


### 避免资源浪费
> 只有 两次握手，客户端发生的 SYN报文在网络阻塞，客户端没有接收到ACK报文，就会重新发送SYN报文，`由于没有三次握手，客户端不清楚客户端时候收到了自己回复的ACK报文，所以服务端每收到一个SYN就只能先主动建立连接`
如果客户端附送的SYN报文在网络中阻塞了，重复发送的SYN报文，服务端在收到请求后就会建立多个冗余的无效链接，造成不必要的资源浪费。

![](https://cdn.xiaolincoding.com//mysql/other/format,png-20230309230636571.png)

即两次握手会造成消息滞留情况下，服务端重复接受无用的连接请求 SYN 报文，而造成重复分配资源。


TCP 建立连接时，通过三次握手能防止历史连接的建立，能减少双方不必要的资源开销，能帮助双方同步初始化序列号。序列号能够保证数据包不重复、不丢弃和按序传输。

不使用「两次握手」和「四次握手」的原因：

- 「两次握手」：无法防止历史连接的建立，会造成双方资源的浪费，也无法可靠的同步双方序列号；
- 「四次握手」：三次握手就已经理论上最少可靠连接建立，所以不需要使用更多的通信次数

