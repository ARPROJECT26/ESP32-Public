#include <stdio.h>
#include <Wire.h>
// get this library from https://github.com/PaulStoffregen/Time
#include <TimeLib.h>
//#include "PrayerTimes.h"

//based on : https://github.com/AsepKurniawanKoto/JWS-Arduino/tree/master/JWS_Semesin

#include "definisi.h"
#include "konstanta.h"
#include "prayer.h"
#include "trigonometri.h"

//double times[sizeof(TimeName) / sizeof(char*)];


void setup() {
  Serial.begin(9600);
  // latitude, longtitude, timezone, fajrAngle, sunriseAngle, duhaAngle, maghribAngle, ishaAngle, dhurAdjust, asrAdjust, date, month, year
  // data = real * 256
prayerData = { -1843, 27683, 1792, 5120, 213, -1152, 1024, 4608, 0, 0, 0,0,0};
}

void loop() {

  Serial.println("PTimes:");
  /*
    int dst=1;

    set_calc_method(ISNA);
    set_asr_method(Shafii);
    set_high_lats_adjust_method(AngleBased);
    set_fajr_angle(15);
    set_isha_angle(15);

    //MEKKA
    //float latitude=21.427378;
    //float longitude=39.814838;
    //get_prayer_times(year(), month(), day(), latitude, longitude, dst, times);
    get_prayer_times(2015, 5, 8, 46.9500f, 7.4458f, 2, times);
  */
//setTime(int hr,int min,int sec,int day, int month, int yr);
setTime(12,59,11,16,9,2024);


  Serial.print("YEAR:");
  Serial.println(year());
  Serial.print("MONTH:");
  Serial.println(month());
  Serial.print("DAY:");
  Serial.println(day());

  prayerData.tanggal = day();
  prayerData.bulan = month();
  prayerData.tahun = year();
  get_prayer_times();

  for (int i = 0; i < 9; i++) {
    // char tmp[10];
    int hours, minutes;
    get_float_time_parts(waktuSholatDouble[i], hours, minutes);
    // p("%d \t %10s %s \t %02d:%02d \n\r",i,TimeName[i],dtostrf(times[i],2,2,tmp),hours,minutes);

    Serial.print(i);
    Serial.print(" \t ");
    Serial.print(strWaktuSholat[i]);
    Serial.print(" \t\t ");
    //Serial.print(waktuSholatDouble[i]);
    //Serial.print(" \t ");
    Serial.print(hours);
    Serial.print(":");
    Serial.print(minutes);
    Serial.println();

  }
  delay(10000);
}

/*
  void getNextPTime(double &pTime, char* pTimeName)
  {
  double times[sizeof(TimeName)/sizeof(char*)];
  double currTime=hour()+minute()/60.0;
  int i;

  set_calc_method(ISNA);
  set_asr_method(Shafii);
  set_high_lats_adjust_method(AngleBased);
  set_fajr_angle(15);
  set_isha_angle(15);

  //get_prayer_times(year(), month(), day(), 46.9500, 7.4458, 1, times);
  get_prayer_times(year(), month(), day(), 46.9500, 7.4458, 2, times);
  for (i=0;i<sizeof(times)/sizeof(double);i++){
    if (times[i] >= currTime) break;
  }
  if ( (times[i]-currTime) <0 ) {
    i=0;
  }
  pTime=times[i];
  sprintf(pTimeName,"%s",TimeName[i]);
  }*/