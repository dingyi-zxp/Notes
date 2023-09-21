# ARP
> Address Resolution Protocol 地址解析协议。在传输一个IP数据包时，确认源IP地址和目的IP地址后，通过主机的`路由表`确认IP数据包下一跳。然而，网络层的下一城是数据链路层，所以还需要知道MAC地址。


ARP需要借助`ARP请求和ARP响应`两种类型来确定MAC地址。
![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/34.jpg)

主机通过`广播发送ARP请求`，这个包包含了想知道的MAC地址的主机IP地址。

当同链路的所有设备收到ARP请求后，会去才开ARP请求包里的内容，如果ARP请求包中的目的IP地址与自己的IP地址一致，那么这个设备就会把自己的MAC地址塞入`ARP响应包`返回给主机。

操作系统会把第一次通过的ARP获取的MAC地址缓存起来，以便下一次直接从缓存中找到对应IP地址的MAC

MAC缓存是有一定期限的，超过期限缓存内容会被清除。

## RAPR
RAPR和ARP协议相反。它是把已知的MAC地址求IP。

> 比如将打印机服务器等小型嵌入式设备接入到网络时就经常会用得到。

通过需要架设一台 RARP 服务器，在这个服务器上著出设备的MAC地及其IP地址。然后将这个设备接入网络：
- 设备会发送 `我的MAC地址是XXX，请告诉我，我的IP地址是什么`的请求。
- RARP服务器收到这个信息后返回 `MAC为xxx设备，IP地址为xx`的信息给这个设备。
- 最后设备根据RARP服务所回答的信息设置自己的IP地址

![](https://cdn.xiaolincoding.com/gh/xiaolincoder/ImageHost/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C/IP/35.jpg)
