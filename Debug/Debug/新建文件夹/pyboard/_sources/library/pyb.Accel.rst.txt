.. currentmodule:: pyb

class Accel -- 加速计控制
====================================

Accel为控制加速计的对象。用法示例::

    accel = pyb.Accel()
    for i in range(10):
        print(accel.x(), accel.y(), accel.z())

未处理值介于-32和31之间。


构造函数
------------

.. class:: pyb.Accel()

   创建并返回一个加速计对象。

方法
-------

.. method:: Accel.filtered_xyz()

   获取x、y、z的滤波值的3元组。

   实现的注意事项：该方法目前实现为4个样本的总和，从之前的3次函数调用和当前调用中抽取样本。因此，返回值为原始x()、y()和z()调用大小的4倍。

.. method:: Accel.tilt()

   获取倾斜寄存器。

.. method:: Accel.x()

   获取x轴值

.. method:: Accel.y()

   获取y轴值。

.. method:: Accel.z()

   获取z轴值。

硬件的注意事项
-------------

加速计使用I2C总线来与处理器通信。因此，读取时，X9和X10引脚应为未占用状态（除用于I2C）。
其他使用引脚的设备，即无法同时使用的设备为UART 1、定时器4以及频道1和2。
