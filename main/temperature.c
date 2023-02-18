#include <stdio.h>
//#include <driver/gpio.h>
#include <driver/adc.h>
//#include <driver/i2c.h>
//#include <esp_adc/adc_oneshot.h>
//#include <esp_adc/adc_continuous>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <u8g2.h>
#include "u8g2_esp32_hal.h"

void app_main(void)
{
	while(1){
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);

	int adc_reading = adc1_get_raw(ADC1_CHANNEL_0);
	int tempC = (adc_reading - 500)/10;
	printf("Temperature: %d\n", tempC);
	vTaskDelay(3000/portTICK_PERIOD_MS);
	}
}


