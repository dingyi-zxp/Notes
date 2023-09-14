# 数值数据表示

## 数的机器码表示

- 真值 -> 用于书写表示
	- 将用 + - 表示**正负二进制数称为正值** 

### 机器码
机器码用于**机器内部使用** 

将符号和数字一起编码表示的二进制数称为机器码，将符号数值化
- 原码 Signed magnitude
- 反码 One's complement
- 补码 Two's complement
- 移码 Biased notation

#### 原码表示法 *signed magnitude* 
- 增加符号位
- 最高位为符号位
	- 0: 正数
	- 1: 负数

<img alt="原码表示公式" src="https://ssl-pubpic.51yund.com/1359243624.png" style="width:50%;"/>

#### 反码表示法 *One's Complement* 
- 二进制的各位数码取反（负数
- 符号位与原码相同

#### 补码
- 正值直接取原来的二进制码，符号位为0
- 负值逐位取反，末位加一，符号位为1

<img alt="补码" src="https://ssl-pubpic.51yund.com/1359261160.png" />

**补码特性** 

- 零有唯一的表示方式
	- +0.0000 = -0.0000 = 0.0000
- 运算简单，只需要设置加法器
- 符号位可以直接参与运算
- 减法可以变成假发，统一运算电路

**补码加减法** 
<img src="https://ssl-pubpic.51yund.com/1359261174.png" />

#### 移码
- 补码符号位取反

### 基本术语
- 计算机利用寄存器存储数据
- 寄存器中每个位称bit(Binary DigiT)
- 最高有效位（MSB 最低有效位（LSB

<img src="https://ssl-pubpic.51yund.com/1359261240.png" />


