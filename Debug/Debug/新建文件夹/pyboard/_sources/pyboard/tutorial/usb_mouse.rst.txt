将pyboard用作USB鼠标
=====================================

Pyboard是一个USB设备，可配置为代替默认USB闪存驱动器的鼠标。

要实现这一功能，首先我们需编辑 ``boot.py`` 文件来改变USB配置。
若您从未接触过您的 ``boot.py`` 文件，此文件应形似下示::

    # boot.py -- run on boot-up 启动时运行
    # can run arbitrary Python, but best to keep it minimal 可运行任何Python，但最好保持其最小化

    import pyb
    #pyb.main('main.py') # main script to run after this one 在此之后运行的主要脚本
    #pyb.usb_mode('VCP+MSC') # act as a serial and a storage device 用作一个串行和储存设备
    #pyb.usb_mode('VCP+HID') # act as a serial device and a mouse 用作一个串行设备和鼠标

启用鼠标模式，取消文件最后一行的注释，使其形如::

    pyb.usb_mode('VCP+HID') # act as a serial device and a mouse 用作一个串行设备和鼠标

若您已更改您的 ``boot.py`` 文件，则其运行需要的最小代码为::

    import pyb
    pyb.usb_mode('VCP+HID')

此代码使pyboard在启动时将自身配置为VCP（虚拟COM端口，即串行端口）和HID（人机接口设备，在我们这种情况下即为鼠标）USB设备。

使用RST开关弹出/卸载pyboard驱动并重置。您的个人电脑现在应扫描到显示为鼠标的pyboard！

手动发送鼠标事件
----------------------------

要使py-mouse正常工作，我们需要向个人电脑发送鼠标事件。首先我们使用REPL提示符手动进行。使用串行程序连接到您的pyboard，并输入以下内容::

    >>> hid = pyb.USB_HID()
    >>> hid.send((0, 10, 0, 0))

您的鼠标应向右移动10个像素！在以上指令中，您正在发送4条信息：按键状态、x、y和屏幕滚动。数字10即告知电脑鼠标在x方向上移动了10个像素。

现在让鼠标左右摆动::

    >>> import math
    >>> def osc(n, d):
    ...   for i in range(n):
    ...     hid.send((0, int(20 * math.sin(i / 10)), 0, 0))
    ...     pyb.delay(d)
    ...
    >>> osc(100, 50)

``osc`` 函数的首个参数为发送的鼠标事件的数量，第二个参数为事件间的延迟（以毫秒为单位）。尝试使用不同数字。

**练习：使鼠标在圆圈内运动。**

使用加速度计制作一个鼠标
-------------------------------------

现在使用加速度计，使鼠标以pyboard的角度移动。以下代码可直接在REPL提示符中输入，
或放入 ``main.py`` 文件中。此处，我们选择后者。这样我们才可学习如何进入安全模式。

此时，pyboard用作一个串行USB设备和HID（鼠标）。所以您无法访问文件系统来编辑您的 ``main.py`` 文件。

您也无法编辑您的 ``boot.py`` 以退出HID模式并返回使用USB驱动的常规模式。

退出这一模式，我们需返回安全模式。我们在【安全模式教程】（重置教程）中已对此进行说明，此处再作说明:

1. 按下USR开关。
2. 按下USR开关，然后按下再松开RST开关。
3. LED将循环亮起绿色、橙色再到绿色+橙色，然后再次循环。
4. 始终按住USR，直至仅橙色LED亮起，然后松开USR开关。
5. 橙色LED应快速闪烁4次，然后熄灭。
6. 现在您就处于安全模式了。

在安全模式下， ``boot.py`` 和 ``main.py`` 文件未执行，因此pyboard以默认设置启动。
这意味着现在您可访问文件系统（USB驱动应显示），且您可编辑 ``main.py`` 。
（保持 ``boot.py`` 的原有状态，因为结束编辑 ``main.py`` 后我们仍要返回HID状态。）

在 ``main.py`` 中输入以下代码::

    import pyb

    switch = pyb.Switch()
    accel = pyb.Accel()
    hid = pyb.USB_HID()

    while not switch():
        hid.send((0, accel.x(), accel.y(), 0))
        pyb.delay(20)

保存您的文件，弹出/卸载您的pyboard驱动，并使用RST开关重置。现在pyboard应用作鼠标，板的角度会使鼠标移动。试试您能否保持鼠标不动！

按下USR开关以停止鼠标运动。

您将注意到y轴是反的。这个问题很容易解决：在上面的 ``hid.send()`` 行中的y坐标前添加负号。

将pyboard恢复至常态
--------------------------------

若您保持pyboard的状态不变，则每次插入时pyboard都会显示为鼠标。您可能想将其恢复至常态。
首先您需要进入安全模式（见上），然后编辑 ``boot.py`` 文件。
在 ``boot.py`` 文件中，为带有 ``VCP+HID`` 设置的行添加注释，其将形如::

    #pyb.usb_mode('VCP+HID') # act as a serial device and a mouse 用作一个串行设备和鼠标

保存您的文件，弹出/卸载驱动，并重置pyboard。现在pyboard返回至正常运行模式。
