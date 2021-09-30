const int sensorInputPin = A1;
const int r_load = 33000;
const long r_zero = 41763;
const float X_min = 0.850;
const float X_max = 1.469;
const float a = 3.922237;
const float b = -8.418636;

void setup() {
  pinMode(sensorInputPin, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  int rawInput = analogRead(sensorInputPin);
  long r_sensor = ((1024.0 * r_load) / rawInput) - r_load;
  float rSrO = (float)rS / (float)rO;
  if (rSrO > X_max) Serial.println("Out of range (above 100 ppm).");
  else if(rSrO < X_min) Serial.println("Out of range (below 1 ppm).");
  else{
    float ppm = a * pow((float)rS / (float)rO, b);
    Serial.print("Gas concentration: ");
    Serial.print(ppm);
    Serial.println(" ppm");
  }
  delay(1000);
}
