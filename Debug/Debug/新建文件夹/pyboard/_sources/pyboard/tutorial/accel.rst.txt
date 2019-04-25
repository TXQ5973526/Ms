加速度计
=================

此章节中，您将会学习如何使用LED的左倾或右倾状态读取加速度计和信号。

使用加速度计
-----------------------

Pyboard有一个可用于探测板和运动角度的加速度计（在小弹簧上的一个小块）。
在x、y、z方向上各有一个感应器。创建一个pyb.Accel()对象并调用x()方法，即可获取加速度计的值。 ::

    >>> accel = pyb.Accel()
    >>> accel.x()
    7

这将返回一个带有一个介于-30和30间的有符号整数。注意：测量噪声很大，这意味着即使您将板保持完美，
您测量的数据中仍会有一些变化。因此，您不应使用x()函数的准确值，而应观察去其是否处在某一范围中。

我们将通过使用加速度计来打开灯来开始（若其不平整）。 ::

    accel = pyb.Accel()
    light = pyb.LED(3)
    SENSITIVITY = 3

    while True:
        x = accel.x()
        if abs(x) > SENSITIVITY:
            light.on()
        else:
            light.off()

        pyb.delay(100)

我们创建对象，然后获取加速度计x方向上的数值。若x方向上的数值比某一特定数值 ``SENSITIVITY`` 大，则LED开启，否则LED将关闭。
此循环的 ``pyb.delay()`` 较小，
否则LED将会在X数值接近 ``SENSITIVITY`` 时不停闪烁。尝试在pyboard上运行这一过程，将板左右倾斜以使LED开启或关闭。

**练习：改变上述脚本，使得蓝色LED在您将板倾斜角度更大时更亮。提示：您需改变值的范围，亮度介于0至255之间。**

Spirit水平
---------------------

上述示例只能灵敏感应x方向上的角度，但是若我们使用 ``y()`` 值和更多LED，我们可将pyboard打开至spirit水平。 ::

    xlights = (pyb.LED(2), pyb.LED(3))
    ylights = (pyb.LED(1), pyb.LED(4))

    accel = pyb.Accel()
    SENSITIVITY = 3

    while True:
        x = accel.x()
        if x > SENSITIVITY:
            xlights[0].on()
            xlights[1].off()
        elif x < -SENSITIVITY:
            xlights[1].on()
            xlights[0].off()
        else:
            xlights[0].off()
            xlights[1].off()

        y = accel.y()
        if y > SENSITIVITY:
            ylights[0].on()
            ylights[1].off()
        elif y < -SENSITIVITY:
            ylights[1].on()
            ylights[0].off()
        else:
            ylights[0].off()
            ylights[1].off()

        pyb.delay(100)

我们从创建x和y方向上的LED对象的元组开始。元组是python中的不可变对象，也就意味着他们一旦被创建，就无法更改。
我们如前所述继续进行，但是为正负x值打开不同的LED。在y方向上也是如此。这一步骤并不复杂，但大有裨益。
在您的pyboard上运行此步骤，则您应看到：当以不同角度倾斜板时，不同LED亮起。
