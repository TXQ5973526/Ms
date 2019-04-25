.. currentmodule:: pyb

class LCD -- 用于控制 带触摸传感器的lcd模块
========================================================

LCD类用于控制 带触摸传感器的lcd模块（LCD32MKv1.0）。LCD为一个128x32像素的单色屏幕，部分为NHD-C12832A1Z。

Py面板需连接到X或Y位置，然后使用以下指令制作LCD对象::

    lcd = pyb.LCD('X')      # if pyskin is in the X position 若py面板在X位置
    lcd = pyb.LCD('Y')      # if pyskin is in the Y position 若py面板在y位置

然后::

    lcd.light(True)                 # turn the backlight on 打开背光
    lcd.write('Hello world!\n')     # print text to the screen 将文本打印到屏幕

此驱动实现一个用于设置/获取像素的双缓冲区。例如，制作一个弹跳点，尝试::

    x = y = 0
    dx = dy = 1
    while True:
        # update the dot's position 更新点的位置
        x += dx
        y += dy

        # make the dot bounce of the edges of the screen 使屏幕边缘的点反弹
        if x <= 0 or x >= 127: dx = -dx
        if y <= 0 or y >= 31: dy = -dy

        lcd.fill(0)                 # clear the buffer 清除缓冲区
        lcd.pixel(x, y, 1)          # draw the dot 绘制点
        lcd.show()                  # show the buffer 展示缓冲区
        pyb.delay(50)               # pause for 50ms 暂停50ms


构造函数
------------

.. class:: pyb.LCD(skin_position)

   在给定面板位置构建一个LCD对象。 ``skin_position`` 可为‘X’或‘Y’,，且应匹配LCDpy面板插入的位置。


Methods
-------

.. method:: LCD.command(instr_data, buf)

   向LCD发送任意指令。传输0以使 ``instr_data`` 发送指令，否则传输1以发送数据。 ``buf`` 为指令/数据发送的缓冲区。

.. method:: LCD.contrast(value)

   设置LCD的对比。有效值介于0至47之间。

.. method:: LCD.fill(colour)

   使用给定颜色填充屏幕（0对应白，1对应黑）。

   此方法写入隐藏缓冲区。使用 ``show()`` 来显示缓冲区。

.. method:: LCD.get(x, y)

   获取 ``(x, y)`` 位置的像素。返回0或1。

   此方法从可见缓冲区中读取。

.. method:: LCD.light(value)

   打开/关闭背光。True或1打开，False或0关闭。

.. method:: LCD.pixel(x, y, colour)

   将 ``(x, y)`` 位置的像素设置为给定颜色（0或1）。

   该方法写入到隐藏缓冲区。使用 ``show()`` 显示缓冲区。

.. method:: LCD.show()

   在屏幕上显示隐藏缓冲区。

.. method:: LCD.text(str, x, y, colour)

   使用给定颜色（0或1）将给定文本绘制到 ``(x, y)`` 位置。

   此方法写入到隐藏缓冲区。使用 ``show()`` 显示缓冲区。

.. method:: LCD.write(str)

   将字符串 ``str`` 写入到屏幕中。将立即显示。
