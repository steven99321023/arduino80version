// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
double i;
void setup()
{  
  Serial.begin(9600);
  
  emon1.current(5, 65.0);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1470);  // Calculate Irms only
  
  Serial.print("P : ");
  i=Irms*110.0;
  
  Serial.print(i);	       // Apparent power
  
  Serial.print("  ");
  /*Serial.print("Irms : ");
  Serial.println(Irms);*/		       // Irms
  if(i>70&i<85){Serial.println(" Paper ");}
  if(i>115&i<130){Serial.println(" 2 Fan ");}
  if(i>245&i<260){Serial.println(" Hair drier ");}
  if(i>1125&i<1150){Serial.println(" !Water! ");}
  if(i>155&i<165){Serial.println(" Paper + 2 Fan ");}
  if(i>285&i<305){Serial.println(" Paper + Hair drier ");}
  if(i>1160&i<1180){Serial.println(" Paper + !Water! ");}
  if(i>325&i<345){Serial.println(" 2 Fan + Hair drier ");}
  if(i>1210&i<1230){Serial.println(" 2 Fan +!Water! ");}
  if(i>1330&i<1350){Serial.println(" Hair drier + !Water! ");}
  if(i>370&i<390){Serial.println(" Paper + 2 Fan + Hair drier ");}
  if(i>1240&i<1260){Serial.println(" Paper + 2 Fan + !Water! ");}
  if(i>1375&i<1390){Serial.println(" Paper + Hair drier + !Water! ");}
  if(i>1410&i<1435){Serial.println(" 2 Fan + Hair drier + !Water! ");}
  //if(i>75&i<85){Serial.println(" Paper + 2 Fan + Hair drier + !Water! ");}
 
  delay(1000);
}