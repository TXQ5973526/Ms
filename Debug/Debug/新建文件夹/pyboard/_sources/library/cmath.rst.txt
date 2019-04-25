:mod:`cmath` -- 复数的数学函数
==========================================================

.. module:: cmath
   :synopsis: 复数的数学函数

|see_cpython_module| :mod:`python:cmath`.

``cmath`` 模块提供一些对复数有效的基本数学函数。

函数
---------

.. function:: cos(z)

   返回 ``z`` 的余弦。

.. function:: exp(z)

   返回 ``z`` 的指数。

.. function:: log(z)

   返回 ``z`` 的自然对数。分支切割线沿着负实轴。

.. function:: log10(z)

   返回以 ``z`` 以10为底的对数。分支切割线沿着负实轴。

.. function:: phase(z)

   返回数字 ``z`` 的相位，范围为(-pi, +pi]。

.. function:: polar(z)

   以元组返回 ``z`` 的极坐标形式。

.. function:: rect(r, phi)

   使用模块 ``r`` 和相位 ``phi`` 来返回复数。

.. function:: sin(z)

   返回 ``z`` 的正弦。

.. function:: sqrt(z)

   返回 ``z`` 的平方根。

常量
---------

.. data:: e

   自然函数的底

.. data:: pi

   圆的周长与其直径的比值
