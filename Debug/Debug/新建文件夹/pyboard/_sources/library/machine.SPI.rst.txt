.. currentmodule:: machine
.. _machine.SPI:

SPI类 -- 串行外设接口总线协议(主机)
=====================================================================

SPI由主机驱动的同步串行协议。总线的物理层包括3条线：SCK、MOSI、 MISO。多个设备可共享同一总线。
每台设备应有一个单独的、4th信号、SS（从属选择），在总线上选择一台特定设备以进行通信。
SS信号的处理应在用户编码（通过machine.Pin类）中进行。

构造函数
------------

.. class:: SPI(id, ...)

   在给定总线上构建一个SPI对象， ``id`` 。 ``id`` 的值取决于特定端口及其硬件。
   值0、1等常用于选择硬件SPI block #0、#1等。值-1常用于SPI（若由端口支持）的位拆裂（软件）实现。

   若无额外参数，创建SPI对象但未进行初始化（该对象有来自总线最后一次初始化的设置，若存在的话）。
   若给定额外参数，则初始化总线。初始化参数，请参见 ``init`` 。

方法
-------

.. method:: SPI.init(baudrate=1000000, \*, polarity=0, phase=0, bits=8, firstbit=SPI.MSB, sck=None, mosi=None, miso=None, pins=(SCK, MOSI, MISO))

   使用给定参数初始化SPI总线：

     - ``baudrate`` 为SCK的时钟频率。
     - ``polarity`` 可为0或1，并为闲置时钟线所在的层级。
     - ``phase`` 可为0或1，分别对应第一和第二时钟脉冲边缘的采样数据。
     - ``bits`` 为每次传输的位宽。所有硬件都支持的位宽为8位。
     - ``firstbit`` 可为 ``SPI.MSB`` 或 ``SPI.LSB`` 。
     - ``sck``, ``mosi``, ``miso`` 是总线信号所用的引脚（machine.Pin）对象。对于大多数硬件SPI模块（由 ``id`` 参数选择并用于构造函数）
     而言，引脚为固定不可更改的。在某些情况下，硬件模块允许位硬件SPI模块设置2-3个可选引脚集。
     只有在位拆裂SPI驱动中，任意引脚分配才有可能（ ``id``  = -1）。
     - ``pins`` - WiPy端口不允许 ``sck`` 、 ``mosi`` 、 ``miso`` 参数，但允许将之指定为一个 ``pins`` 参数的元组。

.. method:: SPI.deinit()

   关闭SPI总线。

.. method:: SPI.read(nbytes, write=0x00)

    当持续写入由 ``write`` 给定的单个字节时，读取由 ``nbytes`` 指定的字节数。用读取的数据返回一个 ``bytes`` 对象。

.. method:: SPI.readinto(buf, write=0x00)

    当持续写入由 ``write`` 给定的单个字节时，读取入由 ``buf`` 指定的缓冲区。返回 ``None`` 。

    注意：在WiPy中，该函数返回读取的字节数。

.. method:: SPI.write(buf)

    写入buf内包含的字节。返回 ``None``.

    注意：在WiPy中，该函数返回写入的字节数。

.. method:: SPI.write_readinto(write_buf, read_buf)

    读取入 ``read_buf`` 时，从 ``write_buf`` 中写入字节。缓冲区可为相同或不同的，但须有相同长度。返回 ``None`` 。 

    注意：在WiPy中，该函数返回写入的字节数。

常量
---------

.. data:: SPI.MASTER

   将SPI总线初始化；仅适用于WiPy。

.. data:: SPI.MSB

   将首位设置为最重要的位。

.. data:: SPI.LSB

   将首位设置为最不重要的位。
