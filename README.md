# riscv

#### 介绍
本项目基于riscv指令集处理器ri5cy(https://github.com/openhwgroup/cv32e40p)，通过添加自定义卷积指令加速卷积运算。

#### 硬件架构

ri5cy处理器采用了四级流水线设计，包括取指（Instruction Fetch，简称IF）、译码（Instruction Decode，简称ID）、执行（Instruction Execute，简称EX）和写回（Write-Back，简称WB）四个阶段
![输入图片说明](https://images.gitee.com/uploads/images/2021/0312/193626_27950d03_8797935.png "ri5cy架构.png")

通过在译码模块riscv_decoder中添加自定义卷积指令，并且在执行模块riscv_ex_stage中调用卷积加速模块riscv_mac_ops，使得处理器可以加速卷积运算。
![输入图片说明](https://images.gitee.com/uploads/images/2021/0312/191900_f1627663_8797935.png "加速系统架构.png")

卷积加速模块使用winograd算法加速运算。


#### 安装教程

`gitclone https://gitee.com/qmppmq/riscv/master`

#### 已添加指令

![输入图片说明](https://images.gitee.com/uploads/images/2021/0312/200845_412da748_8797935.png "已添加指令.png")

指令皆为R-type格式

![输入图片说明](https://images.gitee.com/uploads/images/2021/0312/200852_57492315_8797935.png "R-type格式.png")

卷积汇编指令示例

```
.insn r 0x2b, 2, 0, a4, a5, a3
```



#### 使用说明

1.  在riscv_decoder中添加自定义指令，并且在riscv_ex_stage中调用执行模块进行运算。
2.  在./verilator-model目录下修改汇编文件examples.s，处理器会运行examples.s编译后的程序。
3.  在./verilator-model目录下
```
make
./testbench
```
4.  生成波形图model.vcd


