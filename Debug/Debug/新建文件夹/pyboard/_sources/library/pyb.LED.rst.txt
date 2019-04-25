.. currentmodule:: pyb
.. _pyb.LED:

LED类 – LED对象
=======================

LED对象控制一个独立的LED（发光二极管）。

构造函数
------------

.. class:: pyb.LED(id)

   创建一个与给定LED相关联的LED对象：

     - ``id`` 是LED的编号，取值1-4。


方法
-------

.. only:: port_pyboard

   .. method:: LED.intensity([value])

      获取或设置LED亮度。亮度范围介于0（关）至255（全开）。若未给定参数，返回LED亮度。若给定一个参数，则设置LED亮度并返回 ``None`` 。

      *Note:* 仅有LED(3)和LED(4)亮度平稳变化，其使用定时器PWM来实现。LED(3)使用定时器(2)，LED(4)使用定时器(3)。
      这些定时器仅配置为PWM，若相关LED的亮度设置为介于1至254的值。否则这些定时器可用于一般用途。

.. method:: LED.off()

   关闭LED。

.. method:: LED.on()

   打开LED，达到最大强度。

.. method:: LED.toggle()

   切换LED的开（最大强度）关。若LED在非零强度下，则会被认为已打开，随之被切换为关。
