#include <HX711_ADC.h> 
HX711_ADC LoadCell(4, 5);

int taree = 6;
int a = 0;
float b = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (taree, INPUT_PULLUP);
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(1000); // load cells gets 1000ms of time to stabilize
  /////////////////////////////////////
  LoadCell.setCalFactor(900); // Calibarate your LOAD CELL with 100g weight, and change the value according to readings
  /////////////////////////////////////

  delay(600);
}

void loop() {
  // put your main code here, to run repeatedly:

  LoadCell.update(); // retrieves data from the load cell
  float i = LoadCell.getData(); // get output value
  //float ii = i-i;

if (i<0){
  float i = 0;
  Serial.println(i);
}
else if (i>0){
  float i = LoadCell.getData();
  Serial.println(i);
}

 delay(100);
}