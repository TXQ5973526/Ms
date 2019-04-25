LED亮度渐变
===========

除开关LED外，也可使用 `Pulse-Width Modulation (PWM) <http://en.wikipedia.org/wiki/Pulse-width_modulation>`_,
控制LED的亮度，此为从数字引脚中获取输出变量的常用方法。运用此方法，我们可实现LED的亮度渐变:

.. image:: http://upload.wikimedia.org/wikipedia/commons/a/a9/Fade.gif

元件
----------

您需要:

- 标准5或3mm的LED
- 100 Ohm 电阻
- 多条电线
- `面包板 <http://en.wikipedia.org/wiki/Breadboard>`_ (选用，但可方便工作)

连线
--------------------

此教程中我们将使用引脚 ``X1`` 。将电阻的一端连接到 ``X1`` ，另一端连接到LED的正极（即较长脚）。将LED的负极连接到地线。

.. image:: img/fading_leds_breadboard_fritzing.png

代码
----
查看 :ref:`quickref`, 我们即可发现 ``X1`` 连接到定时器5（ ``TIM5 CH1`` ）的通道1。
因此我们将创建一个用于定时器5的 ``Timer`` 对象，然后创建一个用于通道1的 ``TimerChannel`` 对象::

    from pyb import Timer
    from time import sleep

    # timer 5 will be created with a frequency of 100 Hz 定时器将以100Hz的频率创建
    tim = pyb.Timer(5, freq=100)
    tchannel = tim.channel(1, Timer.PWM, pin=pyb.Pin.board.X1, pulse_width=0)

脉宽调制（PWM）中的LED的亮度由更改脉宽来控制，即为LED在每个循环中所占的时间。
定时器频率为100Hz时，每个循环耗时0.01秒（10毫秒）。

实现本教程开始时展示的渐变效果，我们需将脉宽设置为一个较小值，然后慢慢增加脉宽来点亮LED，在到达最大亮度后重新开始::

    # maximum and minimum pulse-width, which corresponds to maximum
    # and minimum brightness 与最大和最小亮度对应的最大和最小脉宽
    max_width = 200000
    min_width = 20000

    # how much to change the pulse-width by each step 每一步骤对脉宽改变的幅度
    wstep = 1500
    cur_width = min_width

    while True:
      tchannel.pulse_width(cur_width)

      # this determines how often we change the pulse-width. It is
      # analogous to frames-per-second 此处决定我们改变脉宽的频率，类似于每秒帧数
      sleep(0.01)

      cur_width += wstep

      if cur_width > max_width:
        cur_width = min_width

呼吸灯效果
----------------

若我们想要实现呼吸灯效果，即LED亮度由暗到亮再由亮到暗的变化，我们只需在到达最大亮度后反转 ``wstep`` 的信号，
并在到达最小亮度时在此反转。因此我们将 ``while`` 循环更改为::

    while True:
      tchannel.pulse_width(cur_width)

      sleep(0.01)

      cur_width += wstep

      if cur_width > max_width:
        cur_width = max_width
        wstep *= -1
      elif cur_width < min_width:
        cur_width = min_width
        wstep *= -1

高级练习
-----------------

您可能已经注意到LED亮度变暗的速度较慢，但是亮度增加的速度很快。这一是因为我们的眼睛对亮度的反应呈对数形式 (`Weber's Law <http://www.telescope-optics.net/eye_intensity_response.htm>`_
)，当LED的亮度呈线性改变时，即相同时长中改变的幅度相同。您将如何解决这一问题呢？（提示：对数函数的反函数是什么？）

附录
--------

我们也可使用数字模拟转换器（DAC）来达到同样效果。PWM方法有其优点：每次都以相同电流驱动LED，但是时长不同。
这更好地实现了对亮度的控制，因为LED在驱动电流和亮度之间未必存在线性关系。
