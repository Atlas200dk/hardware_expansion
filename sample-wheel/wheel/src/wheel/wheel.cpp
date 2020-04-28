/**
* @file wheel.cpp
*/

#include <memory>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "hiaiengine/log.h"

#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

#include "wheel.h"

const unsigned char stop[70] = {0x01,0x04,0xe2,0xe4,0xe8,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
                                0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                0x00,0x00,0x00,0x00,0x00,0x00};



wheel::wheel(void)
{

}

wheel::~wheel(void)
{

}


int wheel::wheel_init(void)
{
    for(unsigned char i=0;i<70;i++)
    {
         if(i2c_ctrl.atlas_i2c_write(0x60,i,stop[i])!=0)
         {
            break;
         }
    }
    return 0;
}

int wheel::wheel_left_move(int direction,unsigned char speed)
{
    if(direction == 1)
    {
        i2c_ctrl.atlas_i2c_write(0x60,0x2b,0x10);
        i2c_ctrl.atlas_i2c_write(0x60,0x2d,0x00);
        i2c_ctrl.atlas_i2c_write(0x60,0x2f,0x00);
        i2c_ctrl.atlas_i2c_write(0x60,0x31,0x10);
    }
    else if(direction == -1)
    {
        i2c_ctrl.atlas_i2c_write(0x60,0x2b,0x00);
        i2c_ctrl.atlas_i2c_write(0x60,0x2d,0x10);
        i2c_ctrl.atlas_i2c_write(0x60,0x2f,0x10);
        i2c_ctrl.atlas_i2c_write(0x60,0x31,0x00);
    }
    i2c_ctrl.atlas_i2c_write(0x60,0x29,speed);

    return 0;
}

int wheel::wheel_right_move(int direction,unsigned char speed)
{
    if(direction == 1)
    {
        i2c_ctrl.atlas_i2c_write(0x60,0x33,0x00);
        i2c_ctrl.atlas_i2c_write(0x60,0x35,0x10);
        i2c_ctrl.atlas_i2c_write(0x60,0x37,0x10);
        i2c_ctrl.atlas_i2c_write(0x60,0x39,0x00);
    }
    else if(direction == -1)
    {
        i2c_ctrl.atlas_i2c_write(0x60,0x33,0x10);
        i2c_ctrl.atlas_i2c_write(0x60,0x35,0x00);
        i2c_ctrl.atlas_i2c_write(0x60,0x37,0x00);
        i2c_ctrl.atlas_i2c_write(0x60,0x39,0x10);
    }
    i2c_ctrl.atlas_i2c_write(0x60,0x3d,speed);

    return 0;
}







