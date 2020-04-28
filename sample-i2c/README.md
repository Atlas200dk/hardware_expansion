# sample-i2c

#### 介绍
Atlas200DK 开发板 用户使用I2C 的使用样例，开发板用户使用的I2C 口是 SDA->PIN3   SCL->PIN5 供用户参考。

#### 软件架构
软件架构说明 此样例是用MindeStudio 新建一个Custom工程，在此工程基础上封装了一个 i2c类 ，此类在src/I2C文件夹中, 在Custom.cpp 中调用i2c类函数进行i2c读写数据。


#### 使用说明

1.参考 i2c类

2.参考 Custom.cpp 中 
i2c_ctrl.atlas_i2c_write(0x20,0x03,0x3f) 函数 向slave地址为0x20的设备 的0x03寄存器写入数据 0x3f   函数返回值为 0->success -1->failed

i2c_ctrl.atlas_i2c_read(0x20,0x03,&read_value) 函数 读取slave地址为0x20的设备 的0x03寄存器数值到read_value中，函数返回值为 
0->success -1->failed


