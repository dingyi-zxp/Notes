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



