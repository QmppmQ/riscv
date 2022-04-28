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

需要的工具
1.Verilator
  参考https://verilator.org/guide/latest/install.html
  版本不能太老 这里用的4.211 下最新版一般没问题
### 下载&编译 verilator

* 参考[https://verilator.org/guide/latest/install.html](https://verilator.org/guide/latest/install.html)
```bash
cd ~
# Prerequisites:
sudo apt-get install git perl python3 make autoconf g++ flex bison ccache
sudo apt-get install libgoogle-perftools-dev numactl perl-doc
sudo apt-get install libfl2  # Ubuntu only (ignore if gives error)
sudo apt-get install libfl-dev  # Ubuntu only (ignore if gives error)
sudo apt-get install zlibc zlib1g zlib1g-dev  # Ubuntu only (ignore if gives error)

git clone https://github.com/verilator/verilator   # Only first time

# Every time you need to build:
# unsetenv VERILATOR_ROOT  # For csh; ignore error if on bash
unset VERILATOR_ROOT  # For bash
cd ~/verilator
git pull         # Make sure git repository is up-to-date
#git tag          # See what versions exist
#git checkout master      # Use development branch (e.g. recent bug fixes)
#git checkout stable      # Use most recent stable release
#git checkout v{version}  # Switch to specified release version

autoconf         # Create ./configure script
./configure      # Configure and create Makefile
sudo make -j `nproc`  # Build Verilator itself (if error, try just 'make')
sudo make install
```

* 检查 verilator 环境
```bash
verilator -V
```

2.riscv-gnu-toolchain:	https://github.com/riscv-collab/riscv-gnu-toolchain
  这里用的tag:2022.03.25或者2022.03.09的版本 某些版本会导致编译报错或者编译完的可执行文件不能被处理器正确运行
```
git clone https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain/
git checkout 2022.03.25 #或者选择下面版本
# git checkout 2022.03.09
```
riscv-gnu-toolchain中的qemu太大且编译并不需要，clone后可以排除qemu这个子仓库
```
cd riscv-gnu-toolchain/
git rm qemu
```
Git clone的主仓库并不包含子仓库的内容，所以需要继续更新子仓库。
```
git submodule init
git submodule update --progress
```
目前发现子模块的riscv-binutils2.38版本存在问题，会导致后续编译器报错找不到一些伪指令，建议使用2.37版本或者2.36.1版本，且更新riscv-dejagnu子模块
```
cd ~/riscv-gnu-toolchain/riscv-dejagnu/
git checkout
cd ~/riscv-gnu-toolchain/riscv-binutils/
git checkout riscv-binutils-2.37 #或者选择下面版本
# git checkout riscv-binutils-2.36.1
```
构建工具链需要几个标准包。在 Ubuntu 上，执行以下命令：
```
sudo apt-get install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
```
### 编译 riscv-gnu-toolchain

* 选择安装位置是/opt/riscv，编译newlib版本，with-arch参数rv32imc，with-abi参数ilp32
* rv32imc(int multiple compress)-ilp32(32-bit soft-float)
```bash
cd riscv-gnu-toolchain/
./configure --prefix=/opt/riscv  --with-arch=rv32imc --with-abi=ilp32
sudo make -j $(nproc)
```

* 添加到环境，如果需要自动生效，建议添加到~/.bashrc
```bash
echo $PATH
# export PATH=/opt/riscv/bin:$PATH #临时变量，重启后失效
echo -e "export PATH=/opt/riscv/bin:\$PATH" >> ~/.bashrc  #添加到~/.bashrc，不要重复添加
source ~/.bashrc
echo $PATH
```


* 如果你安装位置不是`/opt/riscv`，就需要软连接，如果使用前面`--prefix=/opt/riscv`配置就不需要
```bash
# sudo ln -s /your-installation /opt/riscv #如果你安装在了其他位置，请软连接到/opt/riscv
```
* 最后检查环境
```bash
riscv32-unknown-elf-gcc -v
```

3.core-v-verif
### 下载 core-v-verif 
* 参考[https://github.com/openhwgroup/core-v-verif](https://github.com/openhwgroup/core-v-verif)
```bash
git clone https://github.com/openhwgroup/core-v-verif.git
```

* 暂时切换到某一老版本，新版本暂未适配
```bash
cd core-v-verif/
git checkout a739efc45be10aaddb103b81f443ba93606c0569 # 2022.1.4，1.5开始修改Common.mk
# git checkout cd2fe0fa6c3f5e6d0b240af65272aaeb9f6e79b6 # 2021.12.8版本，命令不同
```

* 运行hello-world检查环境
```bash
cd core-v-verif/cv32e40p/sim/core/ # 此路径下有Makefile文件 主要运行指令在这里完成
make clean
make custom CUSTOM_PROG=hello-world # 用ri5cy核运行hello-world程序
```

## 实现
### 验证功能

* 获取RTL设计
```bash
git clone https://github.com/QmppmQ/riscv.git # 本仓库
```


* 将原先处理器的RTL设计替换成本仓库的RTL设计
```bash
cp -r $your_path/riscv/rtl_bk_22.3.10 $your_path/core-v-verif/core-v-cores/cv32e40p/rtl
```

* 将LeNet神经网络代码编译出汇编文件后放到core-v-verif中的自定义代码文件夹
```bash
cd riscv/
riscv32gcc -S lenet.c #编译lenet.c出lenet.s汇编文件
cp -r $your_path/riscv/lenet.s $your_path/core-v-verif/cv32e40p/tests/programs/custom/lenet/lenet.S  # 注意这里放在lenet目录下的lenet.S S是大写 custom目录下的lenet文件夹需要自己新建
```
core-v-verif/cv32e40p/tests/programs/custom/lenet/ 目录下还需要一个.yaml文件，可以直接复制其他custom代码的文件 这里直接复制hello-world下的test.yaml
```
cp core-v-verif/cv32e40p/tests/programs/custom/hello-world/test.yaml core-v-verif/cv32e40p/tests/programs/custom/lenet/
```

* 验证
```bash
cd core-v-verif/cv32e40p/sim/core/
make clean
make custom CUSTOM_PROG=lenet # 使用修改后的ri5cy处理器运行通过自定义指令编写的lenet.c代码
```

