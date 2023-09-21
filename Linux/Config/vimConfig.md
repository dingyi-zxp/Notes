# Tmux basic
1. 创建窗口 `control b c`
2. 指定切换窗口 `control b [窗口号]`
3. 切换右边窗口 `control b n`
4. 切换左边窗口 `control b p`
5. 关闭当前窗口 `control b shift 7`
6. 在当前窗口创建右边小窗口	`control b shift 5 `
7. 创建上下分屏 `control b shift ''`
8. index不同分屏 `control b 上下左右`
9. 快速切换小分屏 `control b q`
10. 小窗口最大化 `control b z` 在按一次就会缩小
11. 关闭小窗口 `control b x`
12. 查看所有窗口 `control b w`
13. 关闭工作空间 `control b d`
14. 回到工作空间 `tmux attach | a` 回到工作空间
15. 查看所有工作空间 `tmus ls`
16. 连接指定的工作空间 `tmus attach -t [序号]`

## tmux配置快捷键
1. `control b` => `control s`
2. `control b nuie` 创建指定位置的小窗口
3. `option f` 全屏
4. `option nuie` 小窗口快速移动
5. `option space` 切换窗口显示方式
6. `option > < |` 更换小窗口位置


# vim 
1. 'control n' 选定一个词汇
	1. `-` `=` 挑选上一个还是下一个
	2. `N` 选定下一个词汇 
	3. `q` 取消 

2. `选中后 S 符号` "选中的字段左右添加符号"
