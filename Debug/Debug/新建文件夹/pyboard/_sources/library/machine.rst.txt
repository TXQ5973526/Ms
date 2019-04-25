:mod:`machine` --- 硬件相关的函数
====================================================

.. module:: machine
   :synopsis: 硬件相关的函数

模块包含与硬件相关的特定函数。

.. _machine_callbacks:

请使用 ``pyb`` 模块函数/方法来控制您的OpenMV Cam。 ``machine`` 模块是为理解为其他MicroPython板编写的其他MicroPython代码。

复位相关的函数
-----------------------

.. function:: reset()

   重置设备，其方式与按下外部RESET按钮类似。

.. function:: reset_cause()

   获取重置的原因。 见 :ref:`constants <machine_constants>` 查看可能的返回值。

中断相关的函数
---------------------------

.. function:: disable_irq()

   禁用中断请求。返回先前的IRQ状态： ``False`` / ``True`` 分别对应禁用/启用IRQ。这个返回值可被传递，以使irq将IRQ恢复到初始状态。

.. function:: enable_irq(state)

   启用中断请求。
   若 ``state`` 为 ``True``（默认值），则启用IRQ。
   若 ``state`` 为 ``False`` ，则禁用IRQ。该函数最常见用途为使 ``disable_irq`` 返回的值退出关键部分。

电源相关的函数
-----------------------

.. function:: freq()

    见 ``pyb.freq()`` 。

.. function:: idle()

   把时钟拨到中央处理器上，有助于在短时间或长时间内减少电力消耗。一旦触发任何中断，外围设备继续工作和执行恢复（在许多端口上，这包括按毫秒级定时间隔进行的系统定时器中断）。

.. function:: sleep()

   终止cpu并禁用除WLAN外的所有外围设备。从请求睡眠的时间点开始执行回复。为实现唤醒，应首先配置唤醒源。

.. function:: deepsleep()

   终止cpu和所有外围设备（包括网络接口）。与复位相同，从主脚本开始恢复执行。为实现唤醒，应首先配置唤醒源，
   如 ``Pin`` 变化或 ``RTC`` 超时。重置原因可用以检查以知晓我们来自 ``machine.DEEPSLEEP`` 。 

.. only:: port_wipy

    .. function:: wake_reason()

        Get the wake reason. See :ref:`constants <machine_constants>` for the possible return values.

其他功能
-----------------------

.. only:: port_wipy

    .. function:: rng()

        硬件生成24bit随机数字(int)。

.. function:: unique_id()

   返回一个具有板子/SoC唯一标识符的字节字符串。若基础硬件允许，板子/ SOC的实例各个不同。长度根据硬件不同而不同（若您想要一个较短的ID，请使用具有完整值的子字符串）。在一些MicroPython端口中，ID与网络MAC地址相对应。

.. function:: time_pulse_us(pin, pulse_level, timeout_us=1000000)

   在给定引脚上为脉冲计时，并返回以微秒计的脉冲持续时长。为低脉冲计时时，pulse_level参数应为0；为高脉冲计时时，该参数应为1。

   若引脚的当前输入值与pulse_level不同，该函数首先(*)需等待，直至引脚输入与pulse_level相等；然后为引脚与pulse_level相等的时段计时。若引脚已与pulse_level相等，则计时立即开始。

   若有正在等待在上方标记有(*)情况的超时，则函数将返回-2，若在上方标记有(**)的主度量中有超时，则函数返回-1。这两种情况中的超时相同，且由timeout_us给定（以微秒计）。

.. _machine_constants:

常量
---------

.. data:: machine.IDLE
          machine.SLEEP
          machine.DEEPSLEEP

    IRQ 唤醒值。

.. data:: machine.PWRON_RESET
          machine.HARD_RESET
          machine.WDT_RESET
          machine.DEEPSLEEP_RESET
          machine.SOFT_RESET

    重置原因。

.. data:: machine.WLAN_WAKE
          machine.PIN_WAKE
          machine.RTC_WAKE

    唤醒原因。

类
-------

.. only:: not port_wipy

 .. toctree::
   :maxdepth: 1

   machine.Pin.rst
   machine.Signal.rst
   machine.UART.rst
   machine.SPI.rst
   machine.I2C.rst
   machine.RTC.rst
   machine.Timer.rst
   machine.WDT.rst

.. only:: port_wipy

 .. toctree::
   :maxdepth: 1

   machine.Pin.rst
   machine.UART.rst
   machine.SPI.rst
   machine.I2C.rst
   machine.RTC.rst
   machine.Timer.rst
   machine.WDT.rst
   machine.ADC.rst
   machine.SD.rst
