# 安装
cmake-3.24.2-windows-x86_64.msi
+ 勾选添加到环境变量
+ 勾选 Create Cmake Desktop Icon

# 需要安装 mingw-get-setup.exe
在 windows 中
cmake .. 替换成 cmake -G "MinGW Makefiles" ..
make  .  替换成 mingw32-make.exe all

在build 文件夹中 运行 cmake ..