# sample-uart

#### 介绍
本样例介绍如何使用Atlas200DK 开发板 UART1 串口发送数据，接收数据

#### 软件架构
软件架构说明
此样例是用MindeStudio 新建一个Custom工程，在此工程基础上封装了一个 uart类 ，此类在src/UART文件夹中, 在Custom.cpp 中调用uart类函数进行uart发送数据，接收数据。

 
#### 使用说明

1.  参考 uart类 
2.  参考 Custom.cpp 中 uart_test_axample()函数,包含了打开串口 ctrl_uart.uart_open()，发送数据ctrl_uart.uart_send(....)    ,在while(1)中接收数据ctrl_uart.uart_read(....),并且打印出接收的数据 ctrl_uart.uart_close()关闭打开的串口.
3.  Atlas200DK 串口说明 和对应开发板管脚 UART1是16，18脚，详细查看：
    https://ascend.huawei.com/doc/Atlas%20200%20DK/1.3.0.0/zh/zh-cn_topic_0188003538.html

