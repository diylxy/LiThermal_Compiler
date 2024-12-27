# LiThermal 热成像相机编译工具链
用于LiThermal 热成像相机的编译工具链和编译所需的staging_dir文件。  
如果有报错，建议使用Ubuntu 22.04 LTS或以下版本编译。  
## 最新版下载
[![Make project](https://github.com/diylxy/LiThermal_Compiler/actions/workflows/makeProject.yml/badge.svg)](https://github.com/diylxy/LiThermal_Compiler/actions/workflows/makeProject.yml)  
最新构建结果点上面那个Make Project，打开后打开最新（最上面）那个，在底下`Artifacts`里有个`UDISK.tar`，下载后得到`UDISK.tar.zip`，解压缩2次，直到得到1个文件夹UDISK，里面包含3个文件，把这3个文件复制到相机的MTP设备中（经测试，不需要killall等其它操作），之后长按电源键重启相机。  
## 下面内容供开发人员参考，也是旧版说明，如有不一致的地方，以上面的为准
## 编译后的操作
编译完成后，把产生的UDISK文件夹内的**所有文件**复制到USB MTP设备（指的是在热成像相机启动后电脑识别到的USB设备，不是烧录固件后通过TF卡读卡器读出的可见分区）的根目录下。  
**注意**：要复制**文件夹内的所有文件**，而不是连带文件夹一起复制过去。  
**注意**：如果使用Actions编译的tar文件，则需要先解压出UDISK文件夹。  
## [最新代码的Github Actions编译结果点这里](https://github.com/diylxy/LiThermal_Compiler/actions/workflows/makeProject.yml)
## 手动编译教程
安装依赖  
```bash
sudo apt install cmake make
```
拉取代码和编译工具链  
```bash
git clone --recursive https://github.com/diylxy/LiThermal_Compiler.git
cd LiThermal_Compiler
```
编译  
```bash
./build.sh
```
**注意**：`build.sh`**必须**在本仓库根目录下执行。  
**注意**：如果你对代码进行了修改，请**删去**`build.sh`中的以下内容，以免你修改的代码被覆盖  
```bash
if [ -d $ROOTPATH/LiThermal ]; then
    echo "Updating..."
    git submodule update --init --recursive
    cd LiThermal
    git checkout master
    git pull origin master
    cd ..
else
    echo "Folder not exist, cloning..."
    git clone https://github.com/diylxy/LiThermal.git
fi
```
