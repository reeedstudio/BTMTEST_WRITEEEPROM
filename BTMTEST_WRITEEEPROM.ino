// DEMO OF EEPROM TEST OF BTM
#include <EEPROM.h>
#include <Wire.h>

#include "eeprom_manage.h"
#include "BTMGlobalDfs.h"

#define VOL     1
#define OHM     0
#define AMP     0
#define MAMP    0

#if VOL
int volX[8] =   {50, 1200, 1300, 3600, 3700, 13400, 13500, 30000};
float volY[8] = {40, 1200, 1420, 3760, 3850, 13650, 13780, 30300};
float volY_n[8]={43, 1060, 1170, 3520, 3300, 13030, 13130, 29400};
#endif

#if OHM
long ohmX[8]  = {10, 1000, 1100, 10000, 11000, 100000, 110000, 1000000};
float ohmY[8] = {11, 1001, 1101, 10001, 11001, 100001, 110001, 1000001};
#endif

#if AMP
int ampX[4]   = {50, 210, 230, 2000};
float ampY[4] = {51, 211, 231, 2001};
float ampY_n[4]={49, 209, 229, 1999};
#endif

#if MAMP
int mampX[2]      = {30, 200};
float mampY[2]    = {31, 201};
float mampY_n[2]  = {29, 199};
#endif


void writeVol()
{
#if VOL
    EEPROM.write(1, 0x55);
    for(int i = 0; i<8; i++)
    {
        EEPM.write(EEPADDRVOLX+2*i, &volX[i], sizeof(int));
        EEPM.write(EEPADDRVOLY+4*i, &volY[i], sizeof(float));
        EEPM.write(EEPADDRVOLY_N+4*i, &volY_n[i], sizeof(float));
    }
#endif
}

void writeOhm()
{
#if OHM
    EEPROM.write(1, 0x55);
    for(int i = 0; i<8; i++)
    {
        EEPM.write(EEPADDROHMX+4*i, &ohmX[i], sizeof(long));
        EEPM.write(EEPADDROHMY+4*i, &ohmY[i], sizeof(float));
        
        ohmX[i] = 0;
    }
    
    for(int i = 0; i<8; i++)
    {
        EEPM.read(EEPADDROHMX+4*i, &ohmX[i], sizeof(long));
        Serial.print(ohmX[i]);
        Serial.print('\t');
    }
    
    Serial.println();
#endif
}

void writeAmp()
{
#if AMP
    EEPROM.write(1, 0x55);
    
    for(int i = 0; i<4; i++)
    {
        EEPM.write(EEPADDRAMPX+2*i, &ampX[i], sizeof(int));
        EEPM.write(EEPADDRAMPY+4*i, &ampY[i], sizeof(float));
        EEPM.write(EEPADDRAMPY_N+4*i, &ampY_n[i], sizeof(float));
    }
#endif
}

void writeMAmp()
{
#if MAMP
    for(int i = 0; i<2; i++)
    {
        EEPM.write(EEPADDRMAMPX+2*i, &mampX[i], sizeof(int));
        EEPM.write(EEPADDRMAMPY+4*i, &mampY[i], sizeof(float));
        EEPM.write(EEPADDRMAMPY_N+4*i, &mampY_n[i], sizeof(float));
    }
#endif
}

void setup()
{
    Serial.begin(38400);

    Serial.println("hello world");
    
    writeVol();
    writeOhm();
    writeAmp();
    writeMAmp();
    
    Serial.println("write over");
}

void loop()
{
    
}
