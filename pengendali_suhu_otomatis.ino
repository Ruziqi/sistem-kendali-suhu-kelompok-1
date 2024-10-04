// Pin definitions
int motorPin = 8;    // Pin for motor control (connected to base of transistor)
int sensor = A1;    // Pin for TMP36 temperature sensor
//float voltage = 0.0;
void setup() {
  pinMode(motorPin, OUTPUT);   // Set motor pin as output
  Serial.begin(9600);          // Begin serial communication for debugging
}

void loop() {
  int adc = analogRead(sensor);
  //Convert the sensor reading to voltage (TMP36 gives 10mV per degree Celsius)
  float voltage = ADC * (5.0 / 1023);  // 5V reference and 10-bit ADC
  float temperatureC = voltage * 100.0;  // Convert to Celsius

  
  Serial.print("voltage: ");
  Serial.println(voltage);
   Serial.print("tempe: ");
  Serial.println(temperatureC);

  if (temperatureC>29.0){
    digitalWrite(motorPin, HIGH);
  } else{
    digitalWrite(motorPin, LOW);
  }
  delay(500);  // Delay 1 second before the next reading
  
}