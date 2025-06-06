/*
 * gps.h
 *
 *  Created on: Nov 25, 2023
 *      Author:  BatuhanErdogan
 */

#ifndef INC_GPS_H_
#define INC_GPS_H_

#include "main.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#define validCondition ((strstr(nmeaSnt, "$GPGLL") != 0) && strlen(nmeaSnt) > 49 && strstr(nmeaSnt, "*") != 0)
#define validCondition2 (strstr(sumNumber, number) != NULL)

typedef struct {
    char* latRAW;
    char* lonRAW;
    char* NS;
    char* EW;
    char* UTC;
} gpsRawData;

typedef struct {
    char latDeg[3];
    char latMin[8];
    char lonDeg[4];
    char lonMin[8];
    char H[3];
    char M[3];
    char S[3];
} gpsWellData;

typedef struct{
		char* latRAW;
		char* NS;
		char* lonRAW;
		char* EW;
		char* UTC;
}GPS_RAW_t;

typedef struct{
	char latDeg[2];
	char latMin[7];
	char lonDeg[3];
	char lonMin[7];
	char H[2];
	char M[2];
	char S[2];
}GPS_WELL_t;

extern char* sep;
extern char* enter;
extern char buffStr[255];
extern char nmeaSnt[80];
extern char *rawSum;
extern char sumNumber[3];
extern GPS_RAW_t gpsRaw;
extern GPS_WELL_t gpsWell;
void initGPS(
		UART_HandleTypeDef* uartGetGPS,
		UART_HandleTypeDef* uartSendGPS,
		uint8_t* buff, uint8_t len,
		uint8_t* isReady,
		char* sepp
		);

void separationGPSData(
		UART_HandleTypeDef* uartSendGPS,
		uint8_t* buff
		);

void gpsSeparationRAW();
void gpsSeparationWELL(int8_t UTC_Diff);
void sendLaLoUTC(UART_HandleTypeDef* uartSendGPS);
uint8_t CharToInt(int8_t);
void IntToChar(uint8_t);
int nmea0183_checksum(char *msg);

#endif /* INC_GPS_H_ */
