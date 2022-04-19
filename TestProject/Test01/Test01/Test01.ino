/*
 Name:		Test01.ino
 Created:	4/19/2022 8:08:25 AM
 Author:	umar.hassan
*/

// the setup function runs once when you press reset or power the board

USBSerial Serials;
void setup() {
	pinMode(PC13, WiringPinMode::OUTPUT);
	digitalWrite(PC13, LOW);
	Serial1.begin(115200);
	Serials.begin(115200);
	Serial
}

// the loop function runs over and over again until power down or reset
void loop() {
	delay(500);
	digitalWrite(PC13, LOW);
	delay(500);
	digitalWrite(PC13, HIGH);
	Serial1.println("Hello Serial1!");
	Serials.println("Hello USBSerial");
}
