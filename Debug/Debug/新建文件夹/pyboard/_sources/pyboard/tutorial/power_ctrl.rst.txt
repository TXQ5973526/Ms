电源管理
=============

:meth:`pyb.wfi` 用于在等待类似中断的事件时减少电量消耗。您可能在以下情况中使用::

    while True:
        do_some_processing()
        pyb.wfi()

使用 :meth:`pyb.freq` 控制频率::

    pyb.freq(30000000) # set CPU frequency to 30MHz 将CPU频率设置为30MHz
