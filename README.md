# "Owl'S"操作系统说明文档

![](pics/boot_animation.png)

[TOC]

## 一、队员组成

|  学号   |  姓名  |        分工        | 比例 |
| :-----: | :----: | :----------------: | :--: |
| 1552687 | 蓝楚迪 | 项目管理，文件系统 |      |
| 1650257 | 陈雨蕾 |                    |      |

## 二、开发环境

* 系统环境：`Ubuntu-14.04.5`
* 编译程序：`nasm-2.13.03`
* 模拟器：`bochs-2.6.9`
* 开发语言：`c`、`assembly`

* 项目管理平台：[GitHub](https://github.com/NSowtril/Owl-S)

## 三、系统设计说明

### 3.1 "Owl'S"概要

我们的OS项目参照了Orange‘S提供的源码，在其基础上进行了完善和扩充，取名为Owl’S。

Owl’S是一个基于微内核的操作系统，系统调用仅仅用于实现一套消息传递机制，我们通过对该系统调用进行封装来完成各项任务。我们参照了Orange’S的IPC机制，完成对自定消息的相应处理。

同时，通过Owl‘S的输入输出系统，实现了开机动画和一些简单的小游戏，实现多控制台。

Owl‘S对Orange‘S的文件系统进行了改进。Orange’S的文件系统是一个扁平的文件系统，且不具有文件记忆功能。通过封装和利用Orange’S的文件系统管理机制，Owl‘S实现了多级文件系统和文件系统恢复功能，能够记忆并恢复用户文件。在改进文件系统的基础上，实现了一系列文件操作相关的基本指令。

### 3.2 系统组成结构

* 引导：` boot/`
* 内核：`kernel/`
* 文件系统：`fs/`
* 代码库：`lib/`
* 头文件集：`include/`
  * 系统相关：`sys/`

#### 3.2.1 内核

#### 3.2.2 进程管理

#### 3.2.3 输入/输出系统

#### 3.2.4 文件系统

### 3.3 项目组工作

* 实现控制台操作

* 改写文件系统，实现多级文件系统

* 实现文件系统的记忆和恢复

* 实现文件系统的基本用户操作

* 实现易用的命令行指令

* 实现应用：

  * 应用1
  * 应用2
  * 应用3


## 四、"Owl'S"功能说明

### 4.1 功能概览

```
help				# 显示系统指令帮助
clear				# 清屏
[shift]+[↑/↓]		# 滚屏
[alt]+[Fn]			# 切换控制台
echo [string]		# 打印一行信息

procmng				# 进入进程管理
pause [pid]			# 挂起进程
resume [pid]		# 唤醒进程
kill [pid]			# 终止进程

pwd					# 打印当前工作目录路径
ls					# 打印当前目录下所有文件
touch [filename]	# 在当前目录下创建新文件。filename：文件名
cat [filename]		# 打印filename文件内容。
vi [filename]		# 修改filename文件内容。
mkdir [dirname]		# 新建文件夹
cd [dirname]		# 进入文件夹
```

### 4.2 功能说明

#### help

![](pics/help.png)

#### clear

![](pics/clear.png)

#### [Alt]+[F2]（切换控制台）

![](pics/tty2.png)

> 同时按下[alt]+[F1]或[alt]+[F2]可切换到tty0或tty1

#### echo

![](pics/echo.png)

#### 文件系统相关

##### ls

![](pics/ls.png)

##### mkdir

![](pics/mkdir.png)

##### cd

![](pics/cd.png)

> cd [已存在目录]：进入该文件，提示符前显示当前路径
>
> cd .. ：进入父目录
>
> cd     ：默认进入根目录
>
> cd [不存在目录]：操作失败，提示错误信息
>
> cd [非目录文件]：操作失败，提示错误信息

##### touch

![](pics/touch.png)

> 创建成功：显示当前目录下所有文件
>
> 输入文件名已存在：创建失败，提示错误信息
>
> 输入文件名不合法：创建失败，提示错误信息

##### vi

![](pics/vi.png)

>vi [已存在文件]：请求输入一行文字，按下回车后保存
>
>vi [不存在文件]：修改失败，提示错误信息

##### cat

![](pics/cat.png)

>cat [已存在文件]：打印文件内容
>
>cat [不存在文件]：查看失败，提示错误信息

#### procmng(进程管理)

![](pics/procmng.png)

> 进程管理界面：显示进程的pID、名称、优先级与运行状态

##### pause（挂起）

![](pics/pause.png)

> pause [用户进程ID]：进程挂起，运行状态变为0
>
> pause [系统任务ID]：无法挂起，提示错误信息
>
> pause [不存在的进程ID]：操作失败，提示错误信息

##### resume（唤醒）

![](pics/resume.png)

> resume [用户进程ID]：唤醒进程，运行状态变为1
>
> resume [不存在的进程ID]：操作失败，提示错误信息

## 五、参考文献

## 六、小结