# Basic Commands

## About File Folder
### rmdir 删除空目录
> rmdir 用于删除空目录。rmdir命令可以从一个目录种删除一个或多个空子目录。

#### 语法
```Basic
rmdir (选项)(参数)
```

```Basic
选项

-p or --parents：删除制定目录后，若该目录的上层目录变成空目录，则其一并删除。
--ignore-fail-on-non-empty：rmdir命令忽略由于删除非空目录时导致的错误信息；
-v or -verboes：显示命令的详细执行过程;
```

> 创建www父文件后在创建子文件Test。`rmdir -pv www`不能直接删除。`rmdir -pv www/Test`可以删除。


### ls 查看目录或文件信息
#### 选项
```Basic
$ ls       # 仅列出当前目录可见文件
$ ls -l    # 列出当前目录可见文件详细信息
$ ls -hl   # 列出详细信息并以可读大小显示文件大小
$ ls -al   # 列出所有文件（包括隐藏）的详细信息
$ ls --human-readable --size -1 -S --classify # 按文件大小排序
$ du -sh * | sort -h # 按文件大小排序(同上)
$ ls -m #水平输出文件列表
$ ls -t 最近修改的文件显示在最上面。
$ ls -n # 显示UID和GID
# ls -ld /etc/ 显示文件夹信息
```

### chown 修改文件目录所有者
```Shell
chown [user] [F]
```
所有者不能进行修改，只有root用户可以进行修改。

### chgrp 修改文件所属组
```Basic
chgrp [group] [F]
```

### find
> 在指定目录下查找文件
`find (选项) (参数)`

```Basic
-name nameFile
find ./dir -name nameFile

-empty
Search for empty files and directories.
find ./GFG -empty

-perm
Search for file with entered permissions 
find ./GFG -perm 773

-user
Search for file with About user

-group 
Search for file with About group

-size
Search for file size

-exec
执行后面的程序
find ./dir -name nameFile -exec cp [] f1 f2
```

### 重定向
```Basic
> 重定向
>> 追加
```

`>` 内容上只能添加表面数据

### grep
> plobal searcn regular expression and print out the line 全面搜索正则表达式并把行打印出来

### cut
> 显示行中的指定部分，删除文件中指定字段
```Basic
-b：仅显示行中指定直接范围的内容；
-c：仅显示行中指定范围的字符；
	-c 1-4 1-4列的内容
-d：指定字段的分隔符，默认的字段分隔符为“TAB”；
-f：显示指定字段的内容；
-n：与“-b”选项连用，不分割多字节字符；

[root@localhost text]# cut -f 1 test.txt
No
01
02
03

[root@localhost text]# cut -f2 -d";" test2.txt
Name
tom
jack
alex
```

### sort
> 对文本文件中所有行进行排序。
```Basic
sort [OPTION]... [FILE]...
-u, --unique                           同时使用-c，严格检查排序；不同时使用-c，输出排序后去重的结果。
-r, --reverse                  将结果倒序排列。

```

### wc
> 统计文件的字节数、字数、行数
```Basic

-c # 统计字节数，或--bytes：显示Bytes数。
-l # 统计行数，或--lines：显示列数。
-m # 统计字符数，或--chars：显示字符数。
-w # 统计字数，或--words：显示字数。一个字被定义为由空白、跳格或换行字符分隔的字符串。
-L # 打印最长行的长度，或--max-line-length。

wc test.txt
# 输出结果
7     8     70     test.txt
# 行数 单词数 字节数 文件名
```

<++>




