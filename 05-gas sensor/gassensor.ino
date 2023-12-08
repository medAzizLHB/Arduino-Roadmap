int red_LED_PIN = 11;
int green_LED_PIN = 9;
int blue_LED_PIN =  10;
int buzzer = 6;
int smoke_detector = A0;
int safety_lim = 60; //Sets  smoke density safe limit

void setup() {
  pinMode(red_LED_PIN, OUTPUT);
  pinMode(green_LED_PIN, OUTPUT);
  pinMode(blue_LED_PIN, OUTPUT);
  pinMode(buzzer,  OUTPUT);
  pinMode(smoke_detector, INPUT);
  Serial.begin(9600); //baud rate
}

void  loop() {
  int sensor_read = analogRead(smoke_detector); 
  	//reads and  stores the reading from the detector in sensor_read

  Serial.print("Smoke  Density: ");
  Serial.println(sensor_read);
  
  if (sensor_read > safety_lim)
    // Checks if reading is beyond safety limit
  {
	analogWrite(red_LED_PIN,255);
    analogWrite(green_LED_PIN, 0);
    tone(buzzer,500, 100); //piezo rings 
  }
  else
  {
    analogWrite(green_LED_PIN, 255);
    analogWrite(red_LED_PIN,0);
    noTone(buzzer); //peizo wont ring
  }
  delay(50);
}
