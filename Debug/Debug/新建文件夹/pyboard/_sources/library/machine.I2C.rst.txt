.. currentmodule:: machine
.. _machine.I2C:

I2C类 – 双线串行协议
=======================================

I2C是一个设备间通信的双线串行协议。其物理层包含两条线：SCL和SDA，分别为时钟和数据线。

I2C对象在特定总线上创建。可在创建时或创建后初始化。

打印I2C对象可提供关于其配置的信息。

为实现高速I2C，请尽量不要使用该对象，而使用 ``pyb.I2C`` 。该类是为通过位拆裂完成的低速软件I2C设计的。

例::

    from machine import I2C

    i2c = I2C(freq=400000)          # create I2C peripheral at frequency of 400kHz 以400kHz的频率创建I2C外设
                                    # depending on the port, extra parameters may be required 取决于端口，可能需要额外参数
                                    # to select the peripheral and/or pins to use 选择要使用的外部和/或引脚

    i2c.scan()                      # scan for slaves, returning a list of 7-bit addresses 扫描从属设备，返回一个7位地址的列表

    i2c.writeto(42, b'123')         # write 3 bytes to slave with 7-bit address 42 使用7位地址42将3个字节写入从属设备
    i2c.readfrom(42, 4)             # read 4 bytes from slave with 7-bit address 42 使用7位地址42将4个字节读入从属设备

    i2c.readfrom_mem(42, 8, 3)      # read 3 bytes from memory of slave 42, 从从属设备42的内存中读取3个字节
                                    #   starting at memory-address 8 in the slave 从从属设备的内存地址8开始
    i2c.writeto_mem(42, 2, b'\x10') # write 1 byte to memory of slave 42 将1个字节写入从属设备42的内存
                                    #   starting at address 2 in the slave 从从属设备的地址2开始

构建函数
------------

.. class:: I2C(id=-1, \*, scl, sda, freq=400000)

   构建并返回一个新的I2C对象。参数的描述，请参见下文init方法:

      - *id* 标识一个特定的I2C外设。默认值-1选择一个可处理（在大多数情况下）任意SCL和SDA引脚的I2C的软件实现。若id为-1，则SCL和SDA须被指定。其他允许的id值取决于特定端口/板，此种情况下可能需要或允许指定SCL和SDA。
      - *scl* 应为一个指定用于SCL的引脚对象。
      - *sda* 应为一个指定用于SDA的引脚对象。
      - *freq* 应为一个设置SCL的最大频率的整数。

通用方法
---------------

.. method:: I2C.init(scl, sda, \*, freq=400000)

  使用给定参数初始化I2C总线：

     - *scl* 是用于SCL线的引脚对象
     - *sda* 是用于SDA线的引脚对象
     - *freq* 是SCL时钟频率

.. method:: I2C.deinit()

   Turn off the I2C bus.

   Availability: WiPy.

.. method:: I2C.scan()

   扫描介于0x08和0x77之间的所有I2C地址，并返回一个包含所有响应对象的列表。若在总线上发送地址（包括一个读位）后将SDA线拉低，设备就会响应。

原始I2C操作
------------------------

以下方法实现了原始I2C主总线操作，且可组合起来执行任何I2C事务。若您需对总线进行更多控制，即可使用该方法，否则可使用标准方法（见下）。

.. method:: I2C.start()

   在总线上发送一个起始位（SDA转换为低，SCL为高）。

   Availability: ESP8266.

.. method:: I2C.stop()

   在总线上发送一个终止位（SDA转换为高，SCL为高）。

   Availability: ESP8266.

.. method:: I2C.readinto(buf, nack=True)

   从总线中读取字节，并存入缓冲区中。读取的字节数量即为缓冲区的长度。接收除最后一个字节外的所有字节后，将在总线上发送ACK，NACK将在最后一个字节后发送。

   Availability: ESP8266.

.. method:: I2C.write(buf)

   将所有字节从缓冲区中写入总线。检查每个字节后是否接收到ACK，若未接收到，则报告OS错误。

   Availability: ESP8266.

标准总线操作
-----------------------

以下方法实现了针对给定从属设备的标准I2C主机读写操作。

.. method:: I2C.readfrom(addr, nbytes, stop=True)

   从addr指定的从属设备中读取nbytes。使用读取的数据返回一个字节对象。

.. method:: I2C.readfrom_into(addr, buf, stop=True)

   从addr指定的从属设备中读取到缓冲区中。读取的字节数量即为缓冲区的长度。

.. method:: I2C.writeto(addr, buf, stop=True)

   将字节从缓冲区中读取到addr指定的从属设备中。

   终止参数(仅在WiPy上可用)显示是否应在传输结束时发送一个终止位。若为False，则传输应在稍后继续进行。


内存操作
-----------------

一些I2C设备可作为读取和写入的内存设备(或一组寄存器)。此时，有两个与I2C处理相关的地址：从属地址与内存地址。以下方法是与设备通信的便捷函数。

.. method:: I2C.readfrom_mem(addr, memaddr, nbytes, \*, addrsize=8)

   从memaddr指定的内存地址开始，从addr 指定的从属设备中将nbytes读取到缓冲区中。addrsize参数指定以位为单位的地址大小（在ESP8266上，该参数未被识别，地址大小通常为8位）。使用读取的数据返回一个字节对象。

.. method:: I2C.readfrom_mem_into(addr, memaddr, buf, \*, addrsize=8)

   从memaddr指定的内存地址开始，从addr 指定的从属设备中将nbytes读取到缓冲区中。读取的字节数量即为缓冲区的长度。addrsize参数指定以位为单位的地址大小（在ESP8266上，该参数未被识别，地址大小通常为8位）。

.. method:: I2C.writeto_mem(addr, memaddr, buf, \*, addrsize=8)

   从memaddr指定的内存地址开始，将缓冲区读取到addr 指定的从属设备中。addrsize参数指定以位为单位的地址大小（在ESP8266上，该参数未被识别，地址大小通常为8位）。
