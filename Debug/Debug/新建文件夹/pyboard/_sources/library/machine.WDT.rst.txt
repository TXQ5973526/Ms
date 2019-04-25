.. currentmodule:: machine
.. _machine.WDT:

WDT类 -- 看门狗定时器
===========================

WDT用于在应用程序崩溃且最终进入不可恢复状态时重启系统。一旦开始，就不可停止或重新配置。启用后，应用需定期“喂养”看门狗，以防止其终止并重置系统。

用法示例::

    from machine import WDT
    wdt = WDT(timeout=2000)  # enable it with a timeout of 2s
    wdt.feed()

此类的可用性: pyboard, openmvcam, WiPy.

构造函数
------------

.. class:: WDT(id=0, timeout=5000)

   创建一个WDT对象并启动。超时须以秒钟数给定，且可接受的最大值为1s。一旦开始运行后，超时就无法更改，且WDT也无法停止。

方法
-------

.. method:: wdt.feed()

   “喂养”看门狗，以防止其重置系统。该应用应将该调用用于合适位置，并确保只在验证一切正常运行后才“喂养”看门狗。
