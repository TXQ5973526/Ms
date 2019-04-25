LCD160CR面板
=================

此教程展示了如何开始使用LCD160CR面板。

.. image:: http://micropython.org/resources/LCD160CRv10-positions.jpg
    :alt: LCD160CRv1.0 picture
    :width: 800px

有关显示驱动程序的具体文件，请参见
:mod:`lcd160cr` 模块。

插入显示屏
-----------------------

此显示屏可直接插入pyboard（支持所有版本的pyboard）。您可将显示屏插入pyboard的顶部，X或Y位置均可。
显示屏应覆盖pyboard的1/2。具体操作请参见上图，图片的左半部分显示X位置，右半部分为Y位置。

获取驱动
------------------

您可使用电源/启用引脚和I2C总线直接控制显示器，但是使用 `lcd160cr` 模块提供的驱动更为方便。
此驱动包含在最新版本的pyboard固件中 (见 `此处 <http://micropython.org/download>`__)。
您也可在GitHub中 `这里 <https://github.com/micropython/micropython/blob/master/drivers/display/lcd160cr.py>`__获取这一驱动；
使用这一版本，您需将文件复制到您的板上一个通过导入查找的目录中（通常为lib/目录）。

一旦您安装了驱动，您需要使用以下代码来导入::

    import lcd160cr

测试显示屏
-------------------

这是一个可用于检测显示屏特性的程序，也可用作开始创建使用LCD的代码的基础。此检测程序包含在最新版的pyboard固件中，也可在GitHub中获取
`这里 <https://github.com/micropython/micropython/blob/master/drivers/display/lcd160cr_test.py>`__.

从MicroPython提示符中运行此检测程序，请::

    >>> import lcd160cr_test

它会打印出一些简短介绍。您需要知道您的显示屏连接的位置（X或Y），然后您即可运行（假设您的显示屏连接在X位置）::

    >>> test_all('X')

绘制图形
---------------------

您须首先实例化一个控制显示屏的LCD160CR对象。请使用::

    >>> import lcd160cr
    >>> lcd = lcd160cr.LCD160CR('X')

此处假设您的显示屏连接在X位置上。若其在Y位置，则使用 ``lcd = lcd160cr.LCD160CR('Y')`` 替代.

尝试使用以下代码清除屏幕并绘制一条线::

    >>> lcd.set_pen(lcd.rgb(255, 0, 0), lcd.rgb(64, 64, 128))
    >>> lcd.erase()
    >>> lcd.line(10, 10, 50, 80)

下一示例在屏幕上绘制任意矩形。您可通过在提示符中先输入“Ctrl-E”，然后再粘贴文本后点击“Ctrl-D”，将其复制粘贴到MicroPython提示符中。 ::

    from random import randint
    for i in range(1000):
        fg = lcd.rgb(randint(128, 255), randint(128, 255), randint(128, 255))
        bg = lcd.rgb(randint(0, 128), randint(0, 128), randint(0, 128))
        lcd.set_pen(fg, bg)
        lcd.rect(randint(0, lcd.w), randint(0, lcd.h), randint(10, 40), randint(10, 40))

使用触摸传感器
----------------------

显示屏包括一个可报告屏幕上基于强度的触控的位置（以像素为单位）的电阻式触控传感。使用以下代码查看屏幕上是否有触碰::

    >>> lcd.is_touched()

此指令将返回 ``False`` 或 ``True`` 。触碰屏幕时运行此指令以查看结果。

您可使用此函数获取触碰的位置::

    >>> lcd.get_touch()

此指令将返回一个3元组，其中第一项为0或1取决于是否当前是否存在某物在触碰屏幕（若有，则为1），元组中的第二项和第三项即为当前（或最近的）触碰的x或y坐标。

将MicroPython输入导向到显示屏
-----------------------------------------------

显示屏支持来自UART的输入，并实现基本VT100指令，也就意味着其可用作一个简单的通用终端。现在我们将pyboard设置为将其输出重新导向到显示屏。

首先您需创建一个UART对象::

    >>> import pyb
    >>> uart = pyb.UART('XA', 115200)

此指令假定您的显示屏连接到X位置。若其连接在Y位置，则使用 ``uart = pyb.UART('YA', 115200)`` 替代.

现在，将REPL输出连接到UART::

    >>> pyb.repl_uart(uart)

现在开始，您在提示符中输入的和您接收的任何内容都将出现在显示屏上。

运行此代码无需任何设置指令，您可将显示屏用于监测UART的输出（而不仅来自pyboard）。
所需条件只有显示屏有电源线、地线和power/enable引脚置高。显示器UART输入的任何参数将打印到显示屏。
您可使用 `set_uart_baudrate` 方法将UART的波特率从默认值115200更改为其他值。
