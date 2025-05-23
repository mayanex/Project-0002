#include <HX711_ADC.h> 
HX711_ADC LoadCell(4, 5);
float x = 20;
float weight;

void setup() {
  // put your setup code here, to run once:
 // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  LoadCell.begin(); // start connection to HX711
  LoadCell.start(2000); // load cells gets 1000ms of time to stabilize
  /////////////////////////////////////
  LoadCell.setCalFactor(x); // Calibarate your LOAD CELL with 100g weight, and change the value according to readings
  /////////////////////////////////////
}

void loop() {
  // put your main code here, to run repeatedly:
 LoadCell.update(); // retrieves data from the load cell
weight = LoadCell.getData(); // get output value
  
  
  if (weight<=0){
  //LoadCell.update(); // retrieves data from the load cell
  weight = 0;
  //Serial.println(weight);
  
}
else if (weight>0){
  LoadCell.update(); // retrieves data from the load cell
  weight = LoadCell.getData();
  //Serial.println(weight);
  Serial.println(weight);
  delay(2000);
}
}
