
#!python
import glob
TOOLCHAIN='/home/august/programs/gcc-arm-none-eabi-4_9-2015q3'
sdkdir="/mnt/osxold/programs/nrf51sdk"

PREFIX=TOOLCHAIN+'/bin/arm-none-eabi-'
env = Environment(CC = TOOLCHAIN+'/bin/arm-none-eabi-gcc', CXX = TOOLCHAIN+'/bin/arm-none-eabi-g++',
	AS=PREFIX+"as")


cfiles="{SDKDIR}/components/libraries/button/app_button.c \
{SDKDIR}/components/libraries/util/app_error.c \
{SDKDIR}/components/libraries/fifo/app_fifo.c \
{SDKDIR}/components/libraries/timer/app_timer.c \
{SDKDIR}/components/libraries/util/nrf_assert.c \
{SDKDIR}/components/libraries/uart/app_uart_fifo.c \
{SDKDIR}/components/drivers_nrf/delay/nrf_delay.c \
{SDKDIR}/components/drivers_nrf/common/nrf_drv_common.c \
{SDKDIR}/components/drivers_nrf/gpiote/nrf_drv_gpiote.c \
{SDKDIR}/components/drivers_nrf/uart/nrf_drv_uart.c \
{SDKDIR}/examples/bsp/bsp.c \
{SDKDIR}/examples//bsp/bsp_btn_ble.c \
{SDKDIR}/components/ble/common/ble_advdata.c \
{SDKDIR}/components/ble/ble_advertising/ble_advertising.c \
{SDKDIR}/components/ble/common/ble_conn_params.c \
{SDKDIR}/components/ble/common/ble_srv_common.c \
{SDKDIR}/components/toolchain/system_nrf51.c \
{SDKDIR}/components/softdevice/common/softdevice_handler/softdevice_handler.c \
{SDKDIR}/components/softdevice/common/softdevice_handler/softdevice_handler_appsh.c \
{SDKDIR}/components/ble/device_manager/device_manager_peripheral.c \
{SDKDIR}/components/drivers_nrf/pstorage/pstorage.c \
{SDKDIR}/components/libraries/scheduler/app_scheduler.c \
{SDKDIR}/components/ble/ble_services/ble_bas/ble_bas.c \
{SDKDIR}/components/libraries/timer/app_timer_appsh.c \
{SDKDIR}/components/drivers_nrf/twi_master/nrf_drv_twi.c \
{SDKDIR}/components/libraries/uart/retarget.c \
".format(SDKDIR=sdkdir).split()

asmfiles= ["src/gcc_startup_nrf51.s"]
#glob.glob("src/*.c")
elftarget='build/midilib_test.elf'
t=env.Program(target=elftarget, source=
glob.glob("src/*.c")+
glob.glob("src/*.cpp")+
cfiles+asmfiles)

#env.Append(CCFLAGS='-O3')
env.Append(CXXFLAGS='-std=gnu++11')
#env.Append(CPPPATH = ['/usr/local/include/'])
#env.Append(CCFLAGS = ['-g','-O3'])
env.Append(CCFLAGS = " -DBOARD_PCA10028 -DSOFTDEVICE_PRESENT -DNRF51 -DS110 -DBLE_STACK_SUPPORT_REQD -DSWI_DISABLE0 -mcpu=cortex-m0 -mthumb -mabi=aapcs --std=gnu99 -Wall -O0 -g3 -mfloat-abi=soft -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin --short-enums -I./config -I{SDKDIR}/components/libraries/util -I{SDKDIR}/components/toolchain/gcc -I{SDKDIR}/components/toolchain -I{SDKDIR}/components/ble/common -I{SDKDIR}/components/drivers_nrf/common -I{SDKDIR}/components/softdevice/s110/headers -I{SDKDIR}/components/ble/ble_services/ble_lbs -I{SDKDIR}/components/drivers_nrf/config -I{SDKDIR}/examples/bsp -I{SDKDIR}/components/libraries/fifo -I{SDKDIR}/components/drivers_nrf/gpiote -I{SDKDIR}/components/drivers_nrf/uart -I{SDKDIR}/components/libraries/uart -I{SDKDIR}/components/device -I{SDKDIR}/components/softdevice/common/softdevice_handler -I{SDKDIR}/components/drivers_nrf/delay -I{SDKDIR}/components/libraries/timer -I{SDKDIR}/components/drivers_nrf/hal -I{SDKDIR}/components/libraries/button -I{SDKDIR}/components/ble/device_manager -I{SDKDIR}/components/drivers_nrf/pstorage -I{SDKDIR}/components/ble/ble_advertising -I{SDKDIR}/components/libraries/trace -I{SDKDIR}/components/ble/ble_services/ble_bas -I{SDKDIR}/components/libraries/scheduler".format(SDKDIR=sdkdir).split())

env.Append(CPPPATH = [
sdkdir+"/components/drivers_nrf/twi_master/",
])

env.Append(LINKFLAGS = "-Xlinker -Map=midilib.map -mthumb -mabi=aapcs -L {SDKDIR}/components/toolchain/gcc -Tfreedrum_gcc_nrf51.ld -mcpu=cortex-m0 -Wl,--gc-sections --specs=nano.specs -lc -lnosys".format(SDKDIR=sdkdir).split())



env.Command(elftarget+".hex", elftarget, PREFIX+"objcopy -O ihex $SOURCE $TARGET")
# Show memory usage
all=env.Command("all", elftarget+".hex", PREFIX+"size $SOURCE")
Default(all)

env.Command("flash", all, "./nrfjprog.sh --flash "+elftarget+".hex")
