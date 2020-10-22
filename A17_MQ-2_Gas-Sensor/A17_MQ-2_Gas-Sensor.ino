/*  Gassensor Test
 *  Board: NANO
 *  Prozessor: ATmega 328P (Old Bootloader)
 *  
 *  V1.0 KHF 10-2020
 */                    

const int gasPin = A0; //GAS sensor output analog A0 pin


void setup()
{
	Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop()
{
	Serial.println(analogRead(gasPin));
	delay(1000); // Print im 1 sec. Takt
}
