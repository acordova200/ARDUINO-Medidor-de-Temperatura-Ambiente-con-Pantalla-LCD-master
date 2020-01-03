
#include <LiquidCrystal.h>


LiquidCrystal LCD(12,11,5,4,3,2);


int SensorTempPino=0;
int AlertaTempBaja=8;
int AlertaTempAlta=13;
int TempBaja=0;
int TempAlta=40;

void setup() {
	
  	pinMode(AlertaTempBaja, OUTPUT);
	pinMode(AlertaTempAlta, OUTPUT);

	
	LCD.begin(16,2);
	
	LCD.print("Temperatura:");
	
	LCD.setCursor(0,1);
	
	LCD.print("      C        F");
}

void loop() {

	int SensorTemp=analogRead(SensorTempPino);


	float T=SensorTemp*5;
	T/=1024;

  	
	float TemperaturaC=(T-0.5)*100;

 
	float TemperaturaF=(TemperaturaC*9/5)+32;

  	
  	LCD.setCursor(0,1);

	LCD.print(TemperaturaC);

  	
	LCD.setCursor(9,1);

  	
  	LCD.print(TemperaturaF);

	
  	if (TemperaturaC>=TempAlta) {
  		digitalWrite(AlertaTempBaja, LOW);
  		digitalWrite(AlertaTempAlta, HIGH);
    }
  	else if (TemperaturaC<=TempBaja){
  		digitalWrite(AlertaTempBaja, HIGH);
  		digitalWrite(AlertaTempAlta, LOW);
  	}
  	else {
  		digitalWrite(AlertaTempBaja, LOW);
  		digitalWrite(AlertaTempAlta, LOW);
    }


  	delay(1000);
}