#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "bmp280_i2c.h"
#include "adxl345_i2c.h"
#include "ds18b20.h"
#include "i2c_avr.h"
//#define F_CPU 8000000// Clock Speed

static int8_t USART_PutChar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(USART_PutChar, NULL, _FDEV_SETUP_WRITE);

static int8_t USART_PutChar(char c, FILE *stream) {
	if (c == '\n')
		USART_PutChar('\r', stream);
	USART_SendByte(c);
	return 0;
}

int main() {
	uint8_t bmp280_connection, bmp280_data_received = 0;
	uint8_t adxl345_data_received = 0;
	uint8_t ds18b20_data_received = 0;
	int32_t temperature;
	int16_t temp;
	float pressure, alt;
	float zero = 0;
	float x, y, z;
	float module_g;

	USART_Init(9600);
	I2CInit(F_CPU, 100000);

	stdout = &mystdout;

	printf("BEGIN");
	bmp280_connection = BMP280_begin(BMP280_DEFAULT_ADDRESS);
	if (bmp280_connection == 1) {
		printf("BMP280 connection OK\n");
	} else {
		printf("BMP280 connection not OK\n");
		return 0;
	}

	int adxl_connection = ADXL345_begin(ADXL345_DEFAULT_ADDRESS);
	if (adxl_connection == 1) {
		printf("ADXL INIT OK");
	} else {
		printf("ADXL INIT NOT OK");
		return 0;
	}


	for (int i = 0; i < 10; i++) {
		BMP280_receiveData(&temperature, &pressure, &alt);
		zero += alt;
	}
	zero /= 10;

	while (1) {
		// pressure reading
		bmp280_data_received = BMP280_receiveData(&temperature, &pressure,
				&alt);
		// acceleration reading
		adxl345_data_received = ADXL345_readXYZ(&x, &y, &z);
		// calculate module of acceleration
		module_g = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		// temperature reading
		ds18b20_data_received = ds18b20read_temp(&temp);

		if (bmp280_data_received == 1 & adxl345_data_received == 1
				& ds18b20_data_received == 1) {
			printf(
					" temp = %ld\n press = %.4f\n alt = %.4f\n x = %.6f\n y = %.6f\n z = %.6f\n module_g = %.6f\n temp = %4f\r\n",
					temperature, pressure, alt - zero, x, y, z, module_g,
					temp / 16.0);
		} else {
			printf("Some measurement not OK\n");
			return 0;
		}

		_delay_ms(250);

	}
	return 0;

}
