.. currentmodule:: pyb

class Switch -- 开关对象
=============================

开关对象是用于控制按钮开关。

用法::

     sw = pyb.Switch()       # create a switch object 创建一个开关对象
     sw.value()              # get state (True if pressed, False otherwise) 获取状态（若按下，则为True，否则将为False）
     sw()                    # shorthand notation to get the switch state 获取开关状态的简写表示法
     sw.callback(f)          # register a callback to be called when the
                             #   switch is pressed down 记录一个按下开关时调用的回调
     sw.callback(None)       # remove the callback 删除回调

示例::

     pyb.Switch().callback(lambda: pyb.LED(1).toggle())


构造函数
------------

.. class:: pyb.Switch()

   创建并返回一个开关对象。


方法
-------

.. method:: Switch.__call__()

   直接调用开关对象以获取其值：若按下则为 ``True`` ，否则为 ``False`` 。

.. method:: Switch.value()

   获取开关状态。若按下则返回 `True` ，否则将返回 `False` 。

.. method:: Switch.callback(fun)

   记录按下开关时调用的给定函数。若 ``fun`` 为 ``None`` ，则禁用回调。
