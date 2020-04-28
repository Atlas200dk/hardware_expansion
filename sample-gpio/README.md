# sample-gpio

#### 介绍
Atlas200DK 开发板 用户使用7个GPIO 的使用样例 供用户参考。

#### 软件架构
此样例是用MindeStudio 新建一个Custom工程，在此工程基础上封装了一个 gpio类 ，此类在src/GPIO文件夹中, 在Custom.cpp 中调用gpio类函数进行gpio控制。

#### 使用说明

1.参考 gpio 类

2.参考 Custom.cpp 

 以下函数返回值为 0->success -1->failed

 （第一个参数是你要操作的GPIO口 id ,数值为 0，1，3，4，5，6，7）分别对应开发板上的7个GPIO口

 gpio io_ctrl;

 io_ctrl.gpio_set_direction(3,1) //设置GPIO3 为输出属性   （第二个参数 为 1 是设置输出属性，0 为输入属性）

 io_ctrl.gpio_set_direction(3,0) //设置GPIO3 为输入属性     

 io_ctrl.gpio_set_value(3,1); // 设置GPIO3 为高电平 ，前提是设置GPIO3为输出属性

 io_ctrl.gpio_set_value(3,0); // 设置GPIO3 为低电平 ，前提是设置GPIO3为输出属性

 io_ctrl.gpio_get_value(3,&value) //读取GPIO0 的电平高低数值放入 value中，0代表低电平  1 代表高电平

 7个IO对应开发板的位置 参考：
 https://ascend.huawei.com/doc/Atlas%20200%20DK/1.3.0.0/zh/zh-cn_topic_0188003537.html

 建议：如果想用IO作为输入口循环检测，建议使用GIOP0,1 两个口，读写速度比较快，其他3，4，5，6，7是用扩展芯片扩展的IO口。
