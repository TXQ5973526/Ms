.. currentmodule:: machine
.. _machine.RTC:

RTC类 -- 实时时钟
============================

RTC是一个独立的时钟，可追踪日期和时间。

用法示例::

    rtc = machine.RTC()
    rtc.init((2014, 5, 1, 4, 13, 0, 0, 0))
    print(rtc.now())


构造函数
------------

.. class:: RTC(id=0, ...)

   创建一个RTC对象。初始化参数请参见init。

方法
-------

.. method:: RTC.init(datetime)

   初始化RTC。日期时间为下列形式的元组：
   
      ``(year, month, day[, hour[, minute[, second[, microsecond[, tzinfo]]]]])``

.. method:: RTC.now()

   获取当前的日期时间元组。

.. method:: RTC.deinit()

   将RTC重置为2015年1月1日，并再次开始运行。

.. method:: RTC.alarm(id, time, \*, repeat=False)

   设置RTC闹钟。时间可为一个将闹钟设定为当前时间+ time_in_ms的毫秒值或一个日期时间元组。若该时间以毫秒传递，则重复可设置为 ``True`` ，以使闹钟具有周期性。

.. method:: RTC.alarm_left(alarm_id=0)

   获取闹钟终止前所剩的毫秒数。

.. method:: RTC.cancel(alarm_id=0)

   取消正在运行的闹钟。

.. method:: RTC.irq(\*, trigger, handler=None, wake=machine.IDLE)

   创建一个由实时时钟闹钟触发的IRQ对象。

      - ``trigger`` 须为 ``RTC.ALARM0``
      - ``handler`` 触发回调时调用的函数。
      - ``wake`` 指定睡眠模式，从该模式下中断可唤醒系统。

常量
---------

.. data:: RTC.ALARM0

    irq 触发源
