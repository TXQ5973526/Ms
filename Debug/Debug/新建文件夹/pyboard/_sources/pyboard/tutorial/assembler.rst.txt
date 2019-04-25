.. _pyboard_tutorial_assembler:

内联汇编
================

此章节中，您将学习如何在MicroPython中写入内联汇编。

**Note**: 此章节是为已对微控制器和汇编语言有所了解的用户的进阶级教程。

MicroPython可以内联汇编，其允许您将汇编程序作为Python函数写入，其命名方式类似于常规Python函数的命名。

返回一个值
-----------------

内联汇编函数由一个特殊的函数装饰器表示。我们从最简单的示例开始::

    @micropython.asm_thumb
    def fun():
        movw(r0, 42)

您可在脚本或REPL中键入此。此函数无需任何参数，并返回数字42。 ``r0`` 为一个寄存器，且函数返回的此寄存器中的值即为返回值。
MicroPython通常将 ``r0`` 解译为一个整数，并为调用方将其转换为一个整数对象。

若您运行 ``print(fun())`` ，您将看到其打印出42。

访问外设
---------------------

对于略微复杂的内容，我们先打开一个LED::

    @micropython.asm_thumb
    def led_on():
        movwt(r0, stm.GPIOA)
        movw(r1, 1 << 13)
        strh(r1, [r0, stm.GPIO_BSRRL])

这一代码使用了一些新概念:

  - ``stm`` 是一个为轻松访问pyboard的微控制器的寄存器提供了一系列常量的模块。
    尝试运行``import stm`` ，然后在REPL中
    运行 ``help(stm)`` 。其功能为提供所有可用常量的列表。

  - ``stm.GPIOA`` 是GPIOA外设的地址。在pyboard中，红色LED在端口A、引脚PA13。

  - ``movwt`` 将一个32位的数字移入寄存器。
    这是一个可轻松转换为2个thumb指令的函数：先是 ``movw`` ，
    然后是 ``movt``.
    ``movt`` 也会将当前值右移16位。

  - ``strh`` 储存了一个半字（16位）。
    上述指令将 ``r1`` 较低的16位存入内存中的 ``r0 + stm.GPIO_BSRRL`` 位置。其作用为将所有端口A上的引脚设置为高，
    即 ``r0`` 中的相应位所设置的。在上述示例中，
    ``r0`` 中的第13位已设置，因此PA13被拉高。这就点亮了红色LED。

接受参数
-------------------

内联汇编函数可接受多达4个参数。若使用这4个参数，则须将之命名为 ``r0``, ``r1``, ``r2`` 和 ``r3`` ，以反映寄存器和调用惯例。

这是一个添加参数的函数::

    @micropython.asm_thumb
    def asm_add(r0, r1):
        add(r0, r0, r1)

此即执行计算 ``r0 = r0 + r1``。由于结果
写作 ``r0``，此即返回的结果。尝试 ``asm_add(1, 2)``，其应返回3。

循环
-----

我们可用 ``label(my_label)`` 为标签赋值，并使用 ``b(my_label)`` 或
类似于 ``bgt(my_label)`` 的条件分支将其分化为支。

以下示例使绿色LED闪烁 ``r0`` 次。 ::

    @micropython.asm_thumb
    def flash_led(r0):
        # get the GPIOA address in r1 获取r1中的GPIOA地址
        movwt(r1, stm.GPIOA)

        # get the bit mask for PA14 (the pin LED #2 is on) 获取PA14的位掩码（LED #2所在的引脚）
        movw(r2, 1 << 14)

        b(loop_entry)

        label(loop1)

        # turn LED on 开启LED
        strh(r2, [r1, stm.GPIO_BSRRL])

        # delay for a bit
        movwt(r4, 5599900)
        label(delay_on)
        sub(r4, r4, 1)
        cmp(r4, 0)
        bgt(delay_on)

        # turn LED off
        strh(r2, [r1, stm.GPIO_BSRRH])

        # delay for a bit 延迟1位
        movwt(r4, 5599900)
        label(delay_off)
        sub(r4, r4, 1)
        cmp(r4, 0)
        bgt(delay_off)

        # loop r0 times
        sub(r0, r0, 1)
        label(loop_entry)
        cmp(r0, 0)
        bgt(loop1)

扩展阅读
---------------

更多关于内联汇编支持的指令的信息，请参考 :ref:`reference documentation <asm_thumb2_index>`.
