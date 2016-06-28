#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10 megohm between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10 megohm resistor between pins 4 & 8, pin 8 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_9 = CapacitiveSensor(4,9);        // 10 megohm resistor between pins 4 & 8, pin 8 is sensor pin, add wire, foil

const long numReadings = 5;
const int numSensors = 4;

long readings1[numReadings];
long readings2[numReadings];
long readings3[numReadings];
long readings4[numReadings];

long total1;
long total2;
long total3;
long total4;

long average1;
long average2;
long average3;
long average4;

long startDelay = 5000; //Delay before sensing in milliseconds

int startupBuzzes = 2;

void setup()                    
{

   //cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode (11,OUTPUT);
   pinMode (10, OUTPUT);
   
   for (long thisReading = 0; thisReading < numReadings; thisReading++){
   readings1[thisReading]=0;
   readings2[thisReading]=0;
   readings3[thisReading]=0;
   readings4[thisReading]=0;
   }

}

void loop()
{
  
    long start = millis();
    
    total1 = 0;
    total2 = 0;
    total3 = 0;
    total4 = 0;
    
    if (start > startDelay)
    {
      
      for(long thisReading=0; thisReading<numReadings; thisReading++)
      {
        
        readings1[thisReading] = cs_4_2.capacitiveSensor(40);
        readings2[thisReading] = cs_4_6.capacitiveSensor(40);
        readings3[thisReading] = cs_4_8.capacitiveSensor(40);
        readings4[thisReading] = cs_4_9.capacitiveSensor(40);
        
        total1 = total1 + readings1[thisReading];
        total2 = total2 + readings2[thisReading];
        total3 = total3 + readings3[thisReading];
        total4 = total4 + readings4[thisReading];
        
        delay(10);
        
      }
      
        average1 = total1/numReadings;
        average2 = total2/numReadings;
        average3 = total3/numReadings;
        average4 = total4/numReadings;

    if (average1 > 120 && average2 > 120 && average3 > 120 && average4 > 120) {
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
    } else if ((average1 > 120 && average2 > 120) && (average3 < 120 || average4 < 120)) {
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
    } else if ((average1 < 120 || average2 < 120) && (average3 > 120 && average4 > 120)) {
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
    } else if ((average1 < 120 || average2 < 120) && (average3 < 120 || average4 < 120)) {
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
    }
   
    Serial.print(start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug window spacing

    Serial.print(average1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(average2);                  // print sensor output 2
    Serial.print("\t");
    Serial.print(average3);                // print sensor output 3
    Serial.print("\t");
    Serial.println(average4);                // print sensor output 3*/
    
    delay(1000);
    
    } else {
      long delayCorrection = startDelay - startupBuzzes*200;
      delay(delayCorrection);
      
      for (int buzzLoop = 0; buzzLoop < startupBuzzes; buzzLoop++){
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      delay(300);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      delay(300);
      }
      
    }
}
