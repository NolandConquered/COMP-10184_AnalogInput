#include <Arduino.h> 
// I, Nolan Carter, student number 000817341, certify that this material is my original work.
// No other person's work has been used without due acknowledgement and neither have I made my work available to anyone else.
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 

float mapfloat (float input, float lowIn, float highIn, float lowOut, float highOut){
  return (input - lowIn) * (highOut - lowOut) / (highIn - lowIn) + lowOut;
}
 
void loop() { 
  int iVal; 
  float oVal;
  String judgement;
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  oVal = mapfloat(iVal,0,1023,0,50);

  if (oVal < 10){ judgement = ", which is Cold!"; } 
  else if (oVal < 15){ judgement = ", which is Cool"; }
  else if (oVal < 25){ judgement = ", which is Perfect"; }
  else if (oVal < 30){ judgement = ", which is Warm"; }
  else if (oVal < 35){ judgement = ", which is Hot"; }
  else{ judgement = ", which is Too Hot!"; }
  
  // print value to the USB port 
  //Serial.println("Digitized Value = " + String(iVal) +" is equivalent to an Analog Voltage = "+String(mapfloat(iVal,0,1023,0,3.3))+"V"); 
  Serial.println("Digitized Value = " + String(iVal) +" is equivalent to a temperature input of "+String(oVal)+" deg. C"+judgement);
 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
}
