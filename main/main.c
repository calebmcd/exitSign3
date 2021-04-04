// -----------------------------------------------------------------------------------------------
//	Project: Exit Sign V3
//	Created by: Caleb McDougall
//	Start Date: 3/4/2020
//	Version: 3.0.0
//
//	Description:
//		IOT/Google Assistant controlled LED exit sign. Built and developed using the
//		Eclipse ESP32 Toolchain.
// -----------------------------------------------------------------------------------------------

#include <led_strip.h>

#define LED_STRIP_LENGTH 17U
#define LED_STRIP_RMT_INTR_NUM 19U

static struct led_color_t led_strip_buf_1[LED_STRIP_LENGTH];
static struct led_color_t led_strip_buf_2[LED_STRIP_LENGTH];

struct led_strip_t led_strip = {
    .rgb_led_type = RGB_LED_TYPE_WS2812,
    .rmt_channel = RMT_CHANNEL_1,
    .rmt_interrupt_num = LED_STRIP_RMT_INTR_NUM,
    .gpio = GPIO_NUM_21,
    .led_strip_buf_1 = led_strip_buf_1,
    .led_strip_buf_2 = led_strip_buf_2,
    .led_strip_length = LED_STRIP_LENGTH
};
led_strip.access_semaphore = xSemaphoreCreateBinary();

bool led_init_ok = led_strip_init(&led_strip);
