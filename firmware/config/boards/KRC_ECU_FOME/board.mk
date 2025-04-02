# List of all the board related files.
BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp

SHORT_BOARD_NAME = KRC_ECU_FOME

# Override DEFAULT_ENGINE_TYPE
DDEFS += -DFIRMWARE_ID=\"KRC_ECU_FOME\"
IS_STM32F407 = yes

# TS_SECONDARY_UxART_PORT
# DDEFS += -DSTM32_SERIAL_USE_USART3=TRUE 
# DDEFS += -DTS_SECONDARY_UxART_PORT=SD3 -DEFI_TS_SECONDARY_IS_SERIAL=TRUE
# DDEFS += -DEFI_AUX_SERIAL=FALSE

# Knock
DDEFS += -DSTM32_ADC_USE_ADC3=TRUE
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE

# EGT
DDEFS += -DEFI_MAX_31855=TRUE

# reduce memory usage monitoring
DDEFS += -DRAM_UNUSED_SIZE=100

# Lua size
DDEFS += -DLUA_USER_HEAP=32000

# Critical LED (Err)
DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::E8
