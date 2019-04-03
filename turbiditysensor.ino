const int analogIn=A0;
void setup() {
 Serial.begin(115200); // put your setup code here, to run once:

}

void loop() {
 int sensorvalue=analogRead(analogIn);
 float volt=sensorvalue*(5/1024);
 Serial.println("Sensor value");
 Serial.println(volt);
 Serial.println();
 delay(1000);
 // put your main code here, to run repeatedly:

}
