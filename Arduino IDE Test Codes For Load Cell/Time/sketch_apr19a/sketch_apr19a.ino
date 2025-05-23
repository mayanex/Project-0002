int counter = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Increment the counter by one
  counter++;  // or counter += 1;

  // Print the current value of the counter
  Serial.print("Counter: ");
  Serial.println(counter);

  // Add a delay to avoid overwhelming the serial monitor
  delay(1000); 
  counter = 0;
}