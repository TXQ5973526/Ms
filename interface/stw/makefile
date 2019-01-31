#--------------------------------- 编译参数 ------------------------------------
ifneq ($(V),1)
Q		:= @
NULL	:= 2>/dev/null
endif

TARGET := Wali
OPT    := -O0
CSTD   := -std=c11
CXXSTD := -std=c++11

INC_FLAGS += -I ./CORE
INC_FLAGS += -I ./FWLIB/inc
INC_FLAGS += -I ./USER
INC_FLAGS += -I ./SYSTEM

DEFINES += -D __weak="__attribute__((weak))"
DEFINES += -D __packed="__attribute__((__packed__))"
DEFINES += -D USE_HAL_DRIVER
DEFINES += -D STM32F407xx
DEFINES += -D STM32F40_41xxx
DEFINES += -D USE_STDPERIPH_DRIVER

LDSCRIPT := STM32F407VETx_FLASH.ld

FP_FLAGS += -mfpu=fpv4-sp-d16
FP_FLAGS += -mfloat-abi=softfp

ARCH_FLAGS += -mthumb
ARCH_FLAGS += -mcpu=cortex-m4


CWARN_FLAGS += -Wall -Wshadow
#CWARN_FLAGS += -Wundef  -Wextra  -Wredundant-decls
CWARN_FLAGS += -fno-common -ffunction-sections -fdata-sections
CWARN_FLAGS += -Wimplicit-function-declaration  
#CWARN_FLAGS += -Wmissing-prototypes
CWARN_FLAGS += -Wstrict-prototypes

CXXWARN_CXXFLAGS += -Wall -Wshadow
#CXXWARN_CXXFLAGS += -Wundef  -Wextra  -Wredundant-decls
CXXWARN_CXXFLAGS += -fno-common -ffunction-sections -fdata-sections
CXXWARN_CXXFLAGS += -Weffc++

LDLIBS		+= -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group


#----------------------------- 搜索工程目录下的源代码 ---------------------------

AS_SRC := $(shell ..\bin\find ./ -name '*.s')  
AS_OBJ := $(AS_SRC:%.s=%.o)

C_SRC := $(shell ..\bin\find ./ -name '*.c')  
C_OBJ := $(C_SRC:%.c=%.o)  

CXX_SRC := $(shell ..\bin\find ./ -name '*.cpp')  
CXX_OBJ := $(CXX_SRC:%.cpp=%.o)


#--------------------------------- 参数整合 ------------------------------------
# C flags
CFLAGS := $(OPT) $ $(CSTD) $(INC_FLAGS) $(FP_FLAGS) 
CFLAGS += $(DEFINES) $(ARCH_FLAGS) $(CWARN_FLAGS) -g

# C++ flags
CXXFLAGS := $(OPT) $ $(CSTD) $(INC_FLAGS) $(FP_FLAGS) 
CXXFLAGS += $(DEFINES) $(ARCH_FLAGS) $(CXXWARN_CXXFLAGS) -g 

# Linker flags
LDFLAGS		:= --static
LDFLAGS		+= -Wl,-Map=$(TARGET).map -Wl,--gc-sections
LDFLAGS		+= -T$(LDSCRIPT) $(ARCH_FLAGS) $(LDLIBS)

# OBJ
OBJ = $(AS_OBJ) $(C_OBJ) $(CXX_OBJ)

#-------------------------------- 编译器调用指令 --------------------------------
PREFIX	:= ../gcc/bin/arm-none-eabi

CC		:= $(PREFIX)-gcc
CXX		:= $(PREFIX)-g++
LD		:= $(PREFIX)-gcc
AR		:= $(PREFIX)-ar
AS		:= $(PREFIX)-as
OBJCOPY	:= $(PREFIX)-objcopy
OBJDUMP	:= $(PREFIX)-objdump
GDB		:= $(PREFIX)-gdb


#----------------------------------- 编译对象 -----------------------------------
.SUFFIXES: .elf .bin .hex .list .map .images
.SECONDEXPANSION:
.SECONDARY:

#需要生成的文件
all: elf bin

elf: $(TARGET).elf
bin: $(TARGET).bin
hex: $(TARGET).hex
list: $(TARGET).list
images: $(TARGET).images

%.images: %.bin %.hex %.list %.map
	@printf "*** $* images generated ***\n"
	
%.bin: %.elf          
	@printf "  OBJCOPY $(*).bin\n"
	$(Q)$(OBJCOPY) -Obinary $(*).elf $(*).bin
	
%.hex: %.elf
	@printf "  OBJCOPY $(*).hex\n"
	$(Q)$(OBJCOPY) -Oihex $(*).elf $(*).hex
	
%.list: %.elf
	@printf "  OBJDUMP $(*).list\n"
	$(Q)$(OBJDUMP) -S $(*).elf > $(*).list
	
%.elf %.map: $(OBJ) $(LDSCRIPT)
	@printf "  LD      $(TARGET).elf\n"
	$(Q)$(LD) $(OBJ) $(LDFLAGS) -o $(TARGET).elf
	
$(AS_OBJ): %.o:%.s
	@printf "  AS      $(*).cpp\n"
	$(Q)$(CC) $(ARCH_FLAGS) $(FP_FLAGS) -g -Wa,--no-warn -x assembler-with-cpp -o $(*).o -c $(*).s
	
$(C_OBJ): %.o:%.c
	@printf "  CC      $(*).c\n"
	$(Q)$(CC) $(CFLAGS) -o $(*).o -c $(*).c
	
$(CXX_OBJ): %.o:%.cxx
	@printf "  CXX     $(*).cpp\n"
	$(Q)$(CXX) $(CXXFLAGS) -o $(*).o -c $(*).cpp
	
clean:
	@#printf "  CLEAN\n"
	$(Q)$(RM) $(shell ..\bin\find -name '*.o' -o -name '*.d' -o -name '*.elf' -o -name '*.bin') 
	$(Q)$(RM) $(shell ..\bin\find -name '*.hex' -o -name '*.srec' -o -name '*.list' -o -name '*.map') 
	$(Q)$(RM) $(shell ..\bin\find -name 'generated.*' -o -name '*.srec' -o -name '*.list' -o -name '*.map') 

OOCD		 := openocd
#OOCDFLAGS	 := -f /usr/local/share/openocd/scripts/interface/stlink-v2.cfg
#OOCDFLAGS	 += -f /usr/local/share/openocd/scripts/target/stm32f4x.cfg
OOCDFLAGS        += -f openocd.cfg

flash: $(TARGET).hex
	@printf "  OPEN_OCD FLASH $<\n"
	$(Q)$(OOCD) $(OOCDFLAGS) -c "program $(TARGET).hex verify reset exit" 

debug: $(TARGET).elf
	@printf "  GDB DEBUG $<\n"
	$(Q)$(GDB) -iex 'target extended | $(OOCD) $(OOCDFLAGS) -c "gdb_port pipe"' \
	-iex 'monitor reset halt' -ex 'load'  $(TARGET).elf
	
.PHONY: images clean elf bin hex list flash debug











