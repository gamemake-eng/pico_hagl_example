# Mostly copied from https://github.com/tuupola/pico_effects/blob/master/CMakeLists.txt
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Default path to the SDK
if (NOT PICO_SDK_PATH)
  set(PICO_SDK_PATH "../pico-sdk")
endif ()

# Pull in Pico SDK (must be before project)
include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(hagl_test C CXX ASM)

pico_sdk_init()

add_executable(hagl_test main.c)

pico_set_program_name(hagl_test "hagl test")
pico_set_program_version(hagl_test "0.1")

pico_enable_stdio_usb(hagl_test 1)
pico_enable_stdio_uart(hagl_test 0)

target_link_libraries(hagl_test pico_stdlib)

target_link_libraries(hagl_test
        hardware_spi
        hardware_dma
        hagl
        hagl_hal
        )

pico_add_extra_outputs(hagl_test)

add_subdirectory(lib/hagl)
add_subdirectory(lib/hagl_pico_mipi)


target_compile_definitions(hagl_test PRIVATE
#  HAGL_HAL_USE_SINGLE_BUFFER
  HAGL_HAL_USE_DOUBLE_BUFFER
#  HAGL_HAL_USE_TRIPLE_BUFFER
#  HAGL_HAL_USE_DMA
  HAGL_HAL_DEBUG
#  HAGL_HAL_PIXEL_SIZE=2
)

# This is for some generic ST7735 display I found on Amazon :/

target_compile_definitions(hagl_test PRIVATE
	MIPI_DISPLAY_PIN_CS=17
	MIPI_DISPLAY_PIN_DC=20
	MIPI_DISPLAY_PIN_RST=21
	MIPI_DISPLAY_PIN_BL=13
	MIPI_DISPLAY_PIN_CLK=18
	MIPI_DISPLAY_PIN_MOSI=19
	MIPI_DISPLAY_PIN_MISO=-1
	MIPI_DISPLAY_PIN_POWER=-1
	MIPI_DISPLAY_PIN_VSYNC=-1

	MIPI_DISPLAY_SPI_PORT=spi0
	MIPI_DISPLAY_SPI_CLOCK_SPEED_HZ=68000000

	MIPI_DISPLAY_PIXEL_FORMAT=MIPI_DCS_PIXEL_FORMAT_16BIT
	MIPI_DISPLAY_ADDRESS_MODE=MIPI_DCS_ADDRESS_MODE_RGB|MIPI_DCS_ADDRESS_MODE_MIRROR_Y|MIPI_DCS_ADDRESS_MODE_MIRROR_X

	MIPI_DISPLAY_WIDTH=128
	MIPI_DISPLAY_HEIGHT=160
	MIPI_DISPLAY_OFFSET_X=2
	MIPI_DISPLAY_OFFSET_Y=1

	MIPI_DISPLAY_INVERT=0
)
