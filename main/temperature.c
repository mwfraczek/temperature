#include <stdio.h>
#include <driver/adc.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define PIN_SDA 21
#define PIN_SCL 22

void app_main(void)
{
adc1_config_width(ADC_WIDTH_BIT_12);
adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);

int adc_reading = adc1_get_raw(ADC1_CHANNEL_0);
int tempC = (adc_reading - 500)/10;
printf("Temperature: %d\n", tempC);
vTaskDelay(3000/portTICK_PERIOD_MS);
}
