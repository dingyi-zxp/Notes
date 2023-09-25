# Linux文件系统
> Linux系统重要的概念：一切都是文件。在Unix系统中，把一切资源都看作是文件，包括硬件设备。Unix系统把每个硬件都堪称一个文件，统称为设备文件，用户可以读写文件的方式实现对硬件的访问。

![]( https://pic3.zhimg.com/80/v2-e5856860a1b5ee6dae5624b7b2f881aa_720w.webp )

![](https://pic3.zhimg.com/80/v2-0583e93c6a45fc39a74193abad61d56a_720w.webp)

常见目录说明：

/bin： 存放二进制可执行文件(ls,cat,mkdir等)，常用命令一般都在这里；

/etc： 存放系统管理和配置文件；

/home： 存放所有用户文件的根目录，是用户主目录的基点，比如用户user的主目录就是/home/user，可以用~user表示；

/usr ： 用于存放系统应用程序；

/opt： 额外安装的可选应用程序包所放置的位置。一般情况下，我们可以把tomcat等都安装到这里；

/proc： 虚拟文件系统目录，是系统内存的映射。可直接访问这个目录来获取系统信息；

/root： 超级用户（系统管理员）的主目录（特权阶级o）；

/sbin: 存放二进制可执行文件，只有root才能访问。这里存放的是系统管理员使用的系统级别的管理命令和程序。如ifconfig等；

/dev： 用于存放设备文件；

/mnt： 系统管理员安装临时文件系统的安装点，系统提供这个目录是让用户临时挂载其他的文件系统；

/boot： 存放用于系统引导时使用的各种文件；

/lib ： 存放着和系统运行相关的库文件 ；

/tmp： 用于存放各种临时文件，是公用的临时文件存储点；

/var： 用于存放运行时需要改变数据的文件，也是某些大文件的溢出区，比方说各种服务的日志文件（系统启动日志等。）等；

/lost+found： 这个目录平时是空的，系统非正常关机而留下“无家可归”的文件（windows下叫什么.chk）就在这里。


## /etc/passwd
> 保存用户账户相关信息

![](https://www.cyberciti.biz/media/ssb.images/uploaded_images/passwd-file-791527.png)

1. Username
2. Password
	1. X 表示用户是用户密码；用户密码保存在 `/etc/shadow` 文件中;没有系统会认为没有 Password 会直接登录
3. UID
4. GIG
5. User ID Info
6. Home directory
7. Command/Shell
	1. 系统程序一般Shell => `/bin/nologin` 为不需要登录。

### 初始组和附加组
#### 初始组
初始组是用户登录系统时的组
- 创建新用户时候，没有指定所属主，会默认创建一个与用户名相同的组，作为该用户的主组。
- 使用`useradd`命令时`-g`参数可以指定主组。
- 用户只能所属一个组
- 用户的主组不能被删除
- 用户不能被移出主组，但可以更换主组
- 珊瑚被删除时，它的主组若没有其他所属组，会自动删除

#### 附加组
- `useradd -g` 添加
- 可以拥有 >=0 个
- 用户的附加组和主机可以相同
- 附加组可以字节被删除无需关心是否所属于用户
- 附加组可以新增和删除任意个所属用户
- 用户被删除时所属附属组不会收影响


### /etc/shadow
The **/etc/shadow** is a tex-based password file.
![](https://www.cyberciti.biz/faqs/uploaded_images/shadow-file-718705.png)
1. username
2. password
	1. Encrypted password is in hash format.
	2. `$1$`is MD5
	3. `$2a$` is Blowfish
	4. `$2y$` is Blowfish
	5. `$5$` is SHA-256
	6. `$6$` is SHA-512
	7. `$y$` is yescrypt
3. Last password change: The data of the last passwod change. Since Jan 1, 1970(Unix time)。每度过一天+1
4. MiniMum: The minimum number of days required between password changes.0 mean that there are no minimum password age.
5. Maximum:  The maximum number of days the password is valid, after that user is forced to change her password again.
6. Warn: The number of days before password is to expire that user is warned that his/her password must be changed

### /etc/group
保存组相关的信息
![](https://www.cyberciti.biz/media/new/faq/2006/02/etc_group_file.jpg)

1. Group_name
2. Password
3. GID
4. Group List
