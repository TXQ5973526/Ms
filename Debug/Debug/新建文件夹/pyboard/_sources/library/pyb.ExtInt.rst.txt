.. currentmodule:: pyb
.. _pyb.ExtInt:

ExtInt类 – 配置I/O引脚以中断外部事件
==================================================================

共有22条中断线。其中16条来自GPIO引脚，其余6条来自内部资源。

对于0-15线，一条给定的线可从任意端口映射到相应的线。所以0线可映射到Px0，此时x即A、B、C……1线可映射到Px1，此时x即A、B、C…… ::

    def callback(line):
        print("line =", line)

注意：ExtInt自动将GPIO线配置为输入。 ::

    extint = pyb.ExtInt(pin, pyb.ExtInt.IRQ_FALLING, pyb.Pin.PULL_UP, callback)

每在引脚上发现一个下降沿，就会调用这一回调函数。注意：机械按钮有反弹，按下或松开开关通常会产生多个沿。

详细解释与消除抖动的具体方法，请参见: http://www.eng.utah.edu/~cs5780/debouncing.pdf for a detailed

在同一引脚上注册2个回调会引发异常。

若将引脚作为整数传递，则假定它映射到其中一个内部中断源，且须在16-22之间。

所有引脚对象通过引脚映射器来得到一个GPIO引脚。::

    extint = pyb.ExtInt(pin, mode, pull, callback)

有效模式为 pyb.ExtInt.IRQ_RISING, pyb.ExtInt.IRQ_FALLING,
pyb.ExtInt.IRQ_RISING_FALLING, pyb.ExtInt.EVT_RISING,
pyb.ExtInt.EVT_FALLING, and pyb.ExtInt.EVT_RISING_FALLING.

只有IRQ_xxx模式经过测试。EVT_xxx模式与睡眠模式和WFE指令有关。

有效拉力值为pyb.Pin.PULL_UP, pyb.Pin.PULL_DOWN, pyb.Pin.PULL_NONE。

另有一个C API，因此需EXTI中断行的驱动程序也可使用该代码。有效函数，请参见extint.h，用法示例请参见usrsw.h。.



构造函数
------------

.. class:: pyb.ExtInt(pin, mode, pull, callback)

   创建一个ExtInt对象：

     - ``pin`` 是激活中断的引脚（可为一个引脚对象或任何有效名）。
     - ``mode`` 可为下列之一:
       - ``ExtInt.IRQ_RISING`` - 触发上升沿;
       - ``ExtInt.IRQ_FALLING`` - 触发下降沿;
       - ``ExtInt.IRQ_RISING_FALLING`` - 触发上升或下降沿.
     - ``pull`` 可为下列之一:
       - ``pyb.Pin.PULL_NONE`` - 无上拉或下拉电阻;
       - ``pyb.Pin.PULL_UP`` - 启用上拉电阻;
       - ``pyb.Pin.PULL_DOWN`` - 启用下拉电阻.
     - ``callback`` 是中断触发时调用的函数。回调函数必须接受确切的1个参数，即触发中断的线。

Class methods
-------------

.. classmethod:: ExtInt.regs()

   转储EXTI寄存器的值。


方法
-------

.. method:: ExtInt.disable()

   禁用与ExtInt对象关联的中断。这可能对消除抖动有关有帮助。

.. method:: ExtInt.enable()

   启用禁用的中断。

.. method:: ExtInt.line()

   返回引脚映射的行号。

.. method:: ExtInt.swint()

   从软件触发回调。


常量
---------

.. data:: ExtInt.IRQ_FALLING

   中断下降沿。

.. data:: ExtInt.IRQ_RISING

   中断上升沿。

.. data:: ExtInt.IRQ_RISING_FALLING

   中断上升或下降沿。
