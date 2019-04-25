:mod:`framebuf` --- 帧缓冲区操作
=============================================

.. module:: framebuf
   :synopsis: 帧缓冲区操作

该模块提供一个可用于创建位图、可发送到显示器的通用帧缓冲区。

帧缓冲区类
-----------------

帧缓冲区类提供一个像素缓冲区，此缓冲区可使用像素、线、矩形、文本甚至其他帧缓冲区来绘制。此缓冲区可在生成显示器输出时发挥作用。

For example::

    import framebuf

    # FrameBuffer needs 2 bytes for every RGB565 pixel 对于每个RGB565像素，帧缓冲区都需2字节
    fbuf = FrameBuffer(bytearray(10 * 100 * 2), 10, 100, framebuf.RGB565)

    fbuf.fill(0)
    fbuf.text('MicroPython!', 0, 0, 0xffff)
    fbuf.hline(0, 10, 96, 0xffff)

构造函数
------------

.. class:: FrameBuffer(buffer, width, height, format, stride=width)

    构建一个帧缓冲区对象。参数为:

        - *buffer* 缓冲区是一个带有缓冲区协议的对象，且其大小须足以容纳由宽度、高度和帧缓冲区定义的每个像素。
        - *width* 宽度为以像素为单位的帧缓冲区的宽度。
        - *height* 高度为以像素为单位的帧缓冲区的高度。
        - *format* 形式指定用于帧缓冲区的像素类型；
          有效值为 ``framebuf.MVLSB``, ``framebuf.RGB565``
          和 ``framebuf.GS4_HMSB``. MVLSB为单色1位色彩，RGB565为RGB16位色彩，GS4_HMSB为灰度4位色彩。
          色彩值c传递给类函数时，c是一个编码取决于帧缓冲区格式的小整数。
        - *stride* 跨度是帧缓冲区中每条水平线之间的像素数量。此参数默认值为宽度，
          但是在另一更大帧缓冲区或屏幕中实现一个帧缓冲区时可能需要调整。缓冲区空间须适应增大的步骤大小。

    必须指定有效缓冲区、宽度、高度和可选跨度。无效帧缓冲区大小或维度可能会导致意外错误。

绘制原始形状
------------------------

下面的类函数将图形绘制到帧缓冲区中。

.. method:: FrameBuffer.fill(c)

    使用指定颜色填满整个帧缓冲区。

.. method:: FrameBuffer.pixel(x, y[, c])

    若未给定c，则获取指定像素的色值。若给定c，将指定像素设置到给定颜色。

.. method:: FrameBuffer.hline(x, y, w, c)
.. method:: FrameBuffer.vline(x, y, h, c)
.. method:: FrameBuffer.line(x1, y1, x2, y2, c)

    使用给定颜色和1像素的厚度从一组坐标中绘制一条线。line类函数将这条线画到另一组坐标上，
    而hline和vline类函数分别将水平和垂直线绘制到给定长度。

.. method:: FrameBuffer.rect(x, y, w, h, c)
.. method:: FrameBuffer.fill_rect(x, y, w, h, c)

    在给定位置、按照给定大小和颜色绘制一个矩形。
    `rect` 类函数仅绘制1个像素的边框，而 `fill_rect` 类函数可绘制出边框和矩形内部。

绘制文本
------------

.. method:: FrameBuffer.text(s, x, y[, c])

    使用坐标作为文本的左上角，将文本写入帧缓冲区。文本颜色可由任意参数定义，否则将保持其默认值1。所有字符都有8x8像素的尺寸，目前尚无办法改变字体。


其他类函数
-------------

.. method:: FrameBuffer.scroll(xstep, ystep)

    使用给定向量转换帧缓冲区的内容。这可能会在帧缓冲区中留下之前颜色的覆盖区。

.. method:: FrameBuffer.blit(fbuf, x, y[, key])

    在当前帧缓冲区的顶部的给定坐标下绘制另外一个帧缓冲区。若指定*key*，则其应为一个颜色整数，且相应颜色被认为是透明的：所有具有该色值的像素都不会被绘制。

    此类函数在帧缓冲区使用的不同格式间运行，但是由于颜色格式不匹配，最终颜色可能与预想的存在差异。

常量
---------

.. data:: framebuf.MONO_VLSB

    单色（1位）颜色模式

    此模式定义了一个映射，其中一个字节的位为垂直映射，而0位位于屏幕的最顶部。因此，每个字节占据8个垂直像素。
    后续字节在连续的水平位置出现，直至到达最右侧的边缘。更多字节从最左边开始低8个像素显示。

.. data:: framebuf.MONO_HLSB

    单色（1位）颜色模式

    此模式定义了一个映射，其中一个字节的位为水平映射。每个字节占据8个水平像素，0位位于最左边。
    后续字节在连续的水平位置出现，直至到达最右侧的边缘。更多字节在下一行低1个像素显示。

.. data:: framebuf.MONO_HMSB

    单色（1位）颜色模式

    此模式定义了一个映射，其中一个字节的位为水平映射。每个字节占据8个水平像素，而7位位于屏幕的最左边。
    后续字节在连续的水平位置出现，直至到达最右侧的边缘。更多字节在下一行低1个像素显示。

.. data:: framebuf.RGB565

    红绿蓝（16位，5+6+5）颜色模式

.. data:: framebuf.GS4_HMSB

    灰度（4位）颜色模式
