# LiThermal 热成像相机编译工具链
用于LiThermal 热成像相机的编译工具链和编译所需的staging_dir文件。  
如果有报错，建议使用Ubuntu 22.04 LTS或以下版本编译。
## 编译后的操作
编译完成后，把产生的UDISK文件夹内的**所有文件**复制到USB MTP设备（指的是在热成像相机启动后电脑识别到的USB设备，不是烧录固件后通过TF卡读卡器读出的可见分区）的根目录下。  
**注意**：要复制**文件夹内的所有文件**，而不是连带文件夹一起复制过去。  
**注意**：如果使用Actions编译的tar文件，则需要先解压出UDISK文件夹。  
## [最新代码的Github Actions编译结果点这里](https://github.com/diylxy/LiThermal_Compiler/actions)
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