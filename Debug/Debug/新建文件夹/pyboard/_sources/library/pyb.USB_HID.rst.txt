.. currentmodule:: pyb

class USB_HID -- USB 人机接口设备 (HID)
=================================================

USB_HID类允许创建代表USB人机接口设备（HID）的对象。其可用于模拟如鼠标或键盘等外设。

在您使用此类前，您需要使用 `pyb.usb_mode()` 来将USB模式设置为包括HID接口。

构造函数
------------

.. class:: pyb.USB_HID()

   创建一个新的USB_HID对象。


方法
-------

.. method:: USB_HID.recv(data, \*, timeout=5000)

   在总线上接收数据:

     - ``data`` 可为一个整数，即接收的字节的数量，或一个使用接收字节填充的可变缓冲区。
     - ``timeout`` 为等待接收的超时时长（以毫秒为单位）。

   返回值：若 ``data`` 为一个整数，则返回一个接收字节的新缓冲区或读取进data的字节数量。

.. method:: USB_HID.send(data)

   通过USB HID接口发送数据:

     - ``data`` 为发送的数据（一个整数的元组/列表，或一个字节数组）。
