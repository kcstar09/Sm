#define trigPin 9
#define echoPin 10
#define redLed 2
#define greenLed 3
#define buzzer 4   // Buzzer connected to pin 4

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Tank depth assumption = 20 cm
  int tankDepth = 20;

  // Water level = tankDepth - distance
  int waterLevel = tankDepth - distance;

  // Control LEDs + Buzzer
  if (waterLevel <= 0) {
    // Tank empty
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (waterLevel >= 10) {
    // Water reached 10 cm
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, HIGH);   // Turn buzzer ON
  } 
  else {
    // In between
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}