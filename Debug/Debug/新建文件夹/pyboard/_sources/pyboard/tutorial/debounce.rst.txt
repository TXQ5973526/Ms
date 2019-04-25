引脚输入去抖
======================

用作来自开关或其他机械设备输入的引脚可能有许多噪音，当开关首次按下或松开时迅速从低变为高。
此噪音可用电容器（去抖电路）来消除。也可使用确保引脚上的值稳定的简单函数来消除。

下面的函数即可完成此功能。其获取给定引脚的当前值，并等待此值改变。
新的引脚值须能在连续20毫秒内保持稳定以使其可记录此改变。若仍存在噪音，您自行调整持续时间（例如50毫秒）。 ::

    import pyb

    def wait_pin_change(pin):
        # wait for pin to change value 等待引脚改变值
        # it needs to be stable for a continuous 20ms 引脚值需在连续20毫秒内保持稳定
        cur_value = pin.value()
        active = 0
        while active < 20:
            if pin.value() != cur_value:
                active += 1
            else:
                active = 0
            pyb.delay(1)


这样使用::

    import pyb

    pin_x1 = pyb.Pin('X1', pyb.Pin.IN, pyb.Pin.PULL_DOWN)
    while True:
        wait_pin_change(pin_x1)
        pyb.LED(4).toggle()
