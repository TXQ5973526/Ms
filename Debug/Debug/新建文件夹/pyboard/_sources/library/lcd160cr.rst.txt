:mod:`lcd160cr` --- 控制LCD160CR显示屏
===============================================

.. module:: lcd160cr
   :synopsis: 控制LCD160CR显示屏

该模块提供对MicroPython LCD160CR显示屏的控制。

.. image:: http://micropython.org/resources/LCD160CRv10-persp.jpg
    :alt: LCD160CRv1.0 picture
    :width: 640px

更多资源可通过以下连接获取:

* `LCD160CRv1.0 reference manual <http://micropython.org/resources/LCD160CRv10-refmanual.pdf>`_ (100KiB PDF)
* `LCD160CRv1.0 schematics <http://micropython.org/resources/LCD160CRv10-schematics.pdf>`_ (1.6MiB PDF)

class LCD160CR
--------------

LCD160CR类提供连接显示屏的接口。创建此类的一个实例，使用其方法绘制到LCD，并获取触碰面板的状态。

例如::

    import lcd160cr

    lcd = lcd160cr.LCD160CR('X')
    lcd.set_orient(lcd160cr.PORTRAIT)
    lcd.set_pos(0, 0)
    lcd.set_text_color(lcd.rgb(255, 0, 0), lcd.rgb(0, 0, 0))
    lcd.set_font(1)
    lcd.write('Hello MicroPython!')
    print('touch:', lcd.get_touch())

构造函数
------------

.. class:: LCD160CR(connect=None, \*, pwr=None, i2c=None, spi=None, i2c_addr=98)

    构建一个LCD160CR对象。参数为:

        - *connect* 为指定LCD显示屏到板的物理连接的字符串，有效值为“X”、“Y”、“XY”和“YX”。
          显示屏在X面板位置连接到板时，使用“X”，在Y面板位置时则使用“Y”。
          当显示屏连接到pyboard的左边或右边则分别使用“XY”和“YX”。
        - *pwr* 是连接到LCD的电源/启用引脚的引脚对象。
        - *i2c* 是连接到LCD的I2C接口的I2C对象。
        - *spi* 是连接到LCD的SPI接口的SPI对象。
        - *i2c_addr* 是显示屏的I2C地址。

    必须指定一个有效连接或所有PWR、I2C和SPI。若给定有效连接，则所有未作为参数传输的PWR、I2C和SPI（也就是说，其为 ``None`` ）将根据连接值创建。
    若需要，这会允许覆盖显示屏的默认接口。

    默认值为:

        - “X” 用于X面板且使用:
          ``pwr=Pin("X4")``, ``i2c=I2C("X")``, ``spi=SPI("X")``
        - “Y” 用于Y面板且使用:
          ``pwr=Pin("Y4")``, ``i2c=I2C("Y")``, ``spi=SPI("Y")``
        - “XY” 用于右边且使用:
          ``pwr=Pin("X4")``, ``i2c=I2C("Y")``, ``spi=SPI("X")``
        - “YX” 用于左边且使用:
          ``pwr=Pin("Y4")``, ``i2c=I2C("X")``, ``spi=SPI("Y")``

    有关显示屏如何连接到pyboard的信息，请参见 `this image <http://micropython.org/resources/LCD160CRv10-positions.jpg>`_

静态方法
--------------

.. staticmethod:: LCD160CR.rgb(r, g, b)

    返回一个代表给定RGB颜色值的16位整数。此16位值可用于设置字体颜色（见
    :meth:`LCD160CR.set_text_color`）、笔颜色（见 :meth:`LCD160CR.set_pen`）以及绘制个人像素。

.. staticmethod:: LCD160CR.clip_line(data, w, h):

    剪切给定列式数据。供内部使用。

实例成员
----------------

以下的实例成员可公开访问。

.. data:: LCD160CR.w
.. data:: LCD160CR.h

    显示屏的宽度和高度（以像素为单位）。这些成员在调用 :meth:`LCD160CR.set_orient` 时更新且被认为是只读的。

设置指令
--------------

.. method:: LCD160CR.set_power(on)

    打开或关闭显示屏，取决于给定值：0或 ``False`` 将关闭显示屏，1或 ``True`` 将打开显示屏。

.. method:: LCD160CR.set_orient(orient)

    设置显示屏的方向。方向参数可为以下之一： `PORTRAIT`, `LANDSCAPE`, `PORTRAIT_UPSIDEDOWN`, `LANDSCAPE_UPSIDEDOWN`.

.. method:: LCD160CR.set_brightness(value)

    设置显示屏的亮度，介于0至31之间。

.. method:: LCD160CR.set_i2c_addr(addr)

    设置显示屏的I2C地址。地址值须清除低2位。

.. method:: LCD160CR.set_uart_baudrate(baudrate)

    设置UART接口的波特率。

.. method:: LCD160CR.set_startup_deco(value)

    设置显示屏的启动装饰。value参数可为逻辑的或 `STARTUP_DECO_NONE`, `STARTUP_DECO_MLOGO`, `STARTUP_DECO_INFO`.

.. method:: LCD160CR.save_to_flash()

    将以下参数保存至Flash，则参数可在重启和通电时保持不变：初始装饰、方向、亮度、UART波特率和I2C地址。

像素访问方法
--------------------

以下方法在显示屏上操作个人像素。

.. method:: LCD160CR.set_pixel(x, y, c)

    将特定像素设置为给定颜色。颜色应为16位整数，可使用 `LCD160CR.rgb()` 创建。

.. method:: LCD160CR.get_pixel(x, y)

    获取特定像素的16位值。

.. method:: LCD160CR.get_line(x, y, buf)

    低电平函数使一行像素进入给定缓冲区。读取 *n* 像素，缓冲区长度应为 *2*n+1* 字节。首个字节为空白字节，应忽略，后续字节表示始于坐标 *(x, y)* 的行的像素。

.. method:: LCD160CR.screen_dump(buf, x=0, y=0, w=None, h=None)

    将屏幕上的内容转储到给定缓冲区中。参数x和y指定起始坐标，参数w和h指定区域的大小。
    若w或h为 *None* ，则其将取最大值，即屏幕的尺寸减去给定x和y值。
    缓冲区需足以容纳 *2*w*h* 字节。若其小于该尺寸，则仅可储存初始水平行。

.. method:: LCD160CR.screen_load(buf)

    从给定缓冲区中加载整个屏幕。

绘制文本
------------

绘制文本需设置位置、颜色和字体，并使用 `write` 来绘制文本。

.. method:: LCD160CR.set_pos(x, y)

    使用 :meth:`LCD160CR.write`来设置文本输出的位置。其位置为文本的左上角

.. method:: LCD160CR.set_text_color(fg, bg)

    设置文本的前景和背景颜色。

.. method:: LCD160CR.set_font(font, scale=0, bold=0, trans=0, scroll=0)

    设置文本的字体。后续调用 `write` 将使用新配置的字体。参数为:

        - *font* 为使用的字体家族，有效值为0、1、2、3。
        - *scale* 位每个字符像素的标量值，其中像素绘制为边长为标量+1的正方形。该值介于0至63之间。
        - *bold* 控制像素的数量以覆盖每个字符像素，产生加粗效果。粗体的低2位为水平方向需覆盖的像素数量，
          下一个2位为垂直方向。例如，加粗值5将在水平和垂直方向个覆盖1像素。
        - *trans* 可为0或1，若设置为1，字符可使用透明背景绘制。
        - *scroll* 可为0或1，若设置为1，则在文本移动到下一行时，显示屏将进行软滚动。

.. method:: LCD160CR.write(s)

    使用当前位置、颜色和字体将文本写入到显示屏中。随着文本写入，位置自动递增。显示屏支持例如换行和退格等基本VT100控制代码。

绘制原始图形
------------------------

原始绘制指令使用由 `set_pen` 设置的前景和背景颜色。

.. method:: LCD160CR.set_pen(line, fill)

    设置原始图形的线条和填充颜色。

.. method:: LCD160CR.erase()

    将整个显示屏擦除来填充颜色。

.. method:: LCD160CR.dot(x, y)

    使用钢笔线条颜色在给定位置绘制单一像素。

.. method:: LCD160CR.rect(x, y, w, h)
.. method:: LCD160CR.rect_outline(x, y, w, h)
.. method:: LCD160CR.rect_interior(x, y, w, h)

    在给定的位置按照给定大小绘制一个矩形，用钢笔线条的颜色画出边框，然后用钢笔填充内部颜色。 `rect` 函数绘制边框和内部，而其他函数仅能完成其中一项。

.. method:: LCD160CR.line(x1, y1, x2, y2)

    使用钢笔线条颜色在给定坐标间画一条线。

.. method:: LCD160CR.dot_no_clip(x, y)
.. method:: LCD160CR.rect_no_clip(x, y, w, h)
.. method:: LCD160CR.rect_outline_no_clip(x, y, w, h)
.. method:: LCD160CR.rect_interior_no_clip(x, y, w, h)
.. method:: LCD160CR.line_no_clip(x1, y1, x2, y2)

    这些函数如上所述，但请勿在输入坐标上进行任何剪切。它们比剪切版本快，当您确定坐标位于显示屏中时即可使用它们。

.. method:: LCD160CR.poly_dot(data)

    使用钢笔线条颜色画一个点的序列。数据应为一个字节缓冲区，每个连续的字节对对应坐标对(x, y)。

.. method:: LCD160CR.poly_line(data)

    与 `LCD160CR.poly_dot()` 类似，但在点间画线。

触屏函数
--------------------

.. method:: LCD160CR.touch_config(calib=False, save=False, irq=None)

    配置触摸面板:

        - 若 `calib` 为 ``True`` ，则调用将触发电阻式触摸传感器的触摸校准。这需要用户触摸屏幕的不同位置。
        - 若 `save` 为 ``True`` ，则触碰参数将保存至NVRAM，以在重置/通电时保持不变。
        - 若irq为 ``True``，在检测到触碰力时，显示屏将配置为拉低IRQ线。若irq为 ``False`` ，则禁用此特性。若irq为 ``None``（默认值），则此设置不发生变化。

.. method:: LCD160CR.is_touched()

    返回一个布尔值：若当前屏幕上有一个触碰力，则为 ``True`` ，否则为 ``False`` 。

.. method:: LCD160CR.get_touch()

    返回一个(active, x, y)的3元组。若当前屏幕上有一个触碰力，则active为1，否则为0。X和y值表示当前或最近的触碰的位置。

高级指令
-----------------

.. method:: LCD160CR.set_spi_win(x, y, w, h)

    设置SPI数据写入的窗口。

.. method:: LCD160CR.fast_spi(flush=True)

    准备好显示屏接受SPI总线上的RGB像素数据，将第一个字节的位置重置到
    :meth:`LCD160CR.set_spi_win`.
    设置的窗口的左上角。此函数返回一个可用于写入像素数据的SPI对象。

    像素应以5-6-5格式作为16位RGB值发送。目标计数器将随着数据发送而增加，数据可以任意大小的块来发送。目标计数器到达由
    :meth:`LCD160CR.set_spi_win` 指定的窗口的末端后，将环绕到窗口的右上角。

.. method:: LCD160CR.show_framebuf(buf)

    在显示屏中显示给定缓冲区。缓冲区应为包含16位RGB像素数值的数组，且将从左上角开始被写入由 :meth:`LCD160CR.set_spi_win` 指定的区域中。

    `framebuf <framebuf.html>`_ 模块可用于构建帧缓冲区，并提供基本绘图。与直接绘制到屏幕相比，使用帧缓冲器可以提高动画的性能。

.. method:: LCD160CR.set_scroll(on)

    打开或关闭滚动。这这将控制全局的窗口区域滚动。

.. method:: LCD160CR.set_scroll_win(win, x=-1, y=0, w=0, h=0, vec=0, pat=0, fill=0x07e0, color=0)

    配置滚动的窗口区域:

        - *win* 配置的窗口id。有用于一般用途的0..7标准窗口。Window 8为文本滚动窗口（断续器）。
        - *x*, *y*, *w*, *h* 指定显示屏中窗口的位置。
        - *vec* 指定滚动的方向和速度：其为 ``0bF.ddSSSSSSSSSSSS``形式的16位值。dd 为0, 1, 2, 3 for +x, +y, -x, -y滚动。
          F设置速度格式，其中0意为窗口每帧移动S % 256像素，1意为窗口每S帧移动1像素。
        - *pat* 是背景的16位模式掩码。
        - *fill* 为填充颜色。
        - *color* 为文本或模式前景的额外颜色。

.. method:: LCD160CR.set_scroll_win_param(win, param, value)

    设置滚动窗口区域的单一参数:

        - *win* 为窗口id，0..8。
        - *param* 为配置的参数数量，0..7，对应 `set_scroll_win` 函数中的参数。
        - *value* 为设置的值。

.. method:: LCD160CR.set_scroll_buf(s)

    设置在Window中滚动的字符串。参数s须为长度小于等于32的字符串。

.. method:: LCD160CR.jpeg(buf)

    显示一个JPEG。buf 应包括整个JPEG数据。JPEG数据不应包括EXIF信息。支持以下编码：基线DCT、霍夫曼代码、
    每样本8位、三色组件和YCbCr4:2:2。JPEG的起始点是由 :meth:`LCD160CR.set_pos`设置的。

.. method:: LCD160CR.jpeg_start(total_len)
.. method:: LCD160CR.jpeg_data(buf)

    显示一个包含多个缓冲区数据的JPEG 。此处须以单独调用 `jpeg_start` 来开始，
    指定JPEG中字节的总数。须通过一次或多次调用 `jpeg_data` 指令将字节数量传输到显示屏。

.. method:: LCD160CR.feed_wdt()

    首次调用此函数将启动显示屏的内部看门狗定时器。后续的调用将“喂养”看门狗。超时时长约为30秒。

.. method:: LCD160CR.reset()

    重置显示屏。

常量
---------

.. data:: lcd160cr.PORTRAIT
          lcd160cr.LANDSCAPE
          lcd160cr.PORTRAIT_UPSIDEDOWN
          lcd160cr.LANDSCAPE_UPSIDEDOWN

   显示屏的方向，由 :meth:`LCD160CR.set_orient`使用。

.. data:: lcd160cr.STARTUP_DECO_NONE
          lcd160cr.STARTUP_DECO_MLOGO
          lcd160cr.STARTUP_DECO_INFO

   启动装饰的类型，可进行或运算，由
   :meth:`LCD160CR.set_startup_deco`使用。
