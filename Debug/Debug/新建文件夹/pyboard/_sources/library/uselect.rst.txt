:mod:`uselect` -- 在一组流中等待事件
========================================================================

.. module:: uselect
   :synopsis: 在一组流中等待事件

该模块实现相应 `CPython` 模块的子集，如下所示。更多信息，请参见

|see_cpython_module| :mod:`python:select`.

该模块提供用以在流中等待事件的函数（选择用于操作的流）。

函数
---------

.. function:: poll()

   创建轮询类的实例。

.. function:: select(rlist, wlist, xlist[, timeout])

   等待一组对象上的活动。

   这个函数为兼容性设计，效率不高。建议使用 ``Poll`` 。

.. _class: Poll

``Poll`` 类
--------------

方法
~~~~~~~

.. method:: poll.register(obj[, eventmask])

   注册用于轮询的 ``obj`` 。 ``eventmask`` 是下列的逻辑或：

   * ``select.POLLIN``  - 用于读取的数据
   * ``select.POLLOUT`` - 可写入更多数据
   * ``select.POLLERR`` - 出现误差
   * ``select.POLLHUP`` - 检测到流结束/连接终止

   *eventmask* 默认值为 ``select.POLLIN | select.POLLOUT``.

.. method:: poll.unregister(obj)

   注销轮询的 *obj* 。

.. method:: poll.modify(obj, eventmask)

   修改用于 *obj* 的 *eventmask* 。

.. method:: poll.poll([timeout])

   等待至少一个已注册对象准备就绪。返回元组的列表( ``obj`` , ``event`` , ...)， 
    ``event`` 元素为一个上述select.POLL*常量的组合，且指定流中发生的事件。元组中可能有其他元素，这取决于平台和版本，故请勿假设其大小为2。在超时情况下，则返回一个空列表。

   超时以毫秒计。


   .. admonition:: 与CPython区别
      :class: attention

      如上所述，返回的元组可能包括多于2个元素。

.. method:: poll.ipoll([timeout])

   与 :meth:`poll.poll` 类似，但是返回一个产生被调用函数所有元组的迭代器。该函数提供高效的、无位置的在流中进行轮询的方法。

   .. admonition:: 与CPython区别
      :class: attention

      该函数是MicroPython的扩展。
