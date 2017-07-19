int pump=6;
int mist=11;
int red=9;
int blue=10;
int fanpin=2;

int yellowA=8;
int yellowB=4;

int ENA=3;
int ENB=5;
int ENA1=12;
int ENB2=13;

enum vel{
	low=0,    // so as to start from 0
	medium,
	fast
}speedy;


void reset(){
	digitalWrite(ENA,LOW);
	digitalWrite(ENB,LOW);
  	digitalWrite(ENA1,LOW);
  	digitalWrite(ENB2,LOW);
	digitalWrite(red,LOW);
	digitalWrite(fanpin,LOW);
	digitalWrite(blue,LOW);
	analogWrite(yellowA,0); 
	analogWrite(yellowB,0);
	analogWrite(pump,0); 
	analogWrite(mist,0);
	speedy=low;
}

void fan(){
  	digitalWrite(fanpin,HIGH);
  	delay(5000);
}

void rain(){
	reset();
	analogWrite(pump,255); // change according to input supply
	digitalWrite(ENA,HIGH);
	digitalWrite(ENB,HIGH);
	digitalWrite(ENA1,HIGH);
	digitalWrite(ENB2,HIGH);
	delay(5000);
}

void fog(){
	reset();
	analogWrite(mist,240); // change according to input supply
	digitalWrite(ENA,HIGH);
	digitalWrite(ENB,HIGH);
	digitalWrite(ENA1,HIGH);
	digitalWrite(ENB2,HIGH);
	delay(5000);
}

void lightening(){
	reset();
	for(int i=0;i<5;i++){
		digitalWrite(blue,HIGH);
		delay(200);
		digitalWrite(blue,LOW);
		delay(20);
	digitalWrite(blue,HIGH);
	delay(200);
	digitalWrite(blue,LOW);
	delay(2000);
	}
}

void normal(){
	reset();
	analogWrite(yellowA,120);
	analogWrite(yellowB,160);
	analogWrite(blue,100);
	analogWrite(red,40);
	delay(5000);
}

void setup(){
	Serial.begin(9600);
	pinMode(pump,OUTPUT);
	pinMode(mist,OUTPUT);
	pinMode(red,OUTPUT);
	pinMode(blue,OUTPUT);
	pinMode(fanpin,OUTPUT);
	pinMode(yellowA,OUTPUT);
	pinMode(yellowB,OUTPUT);
	pinMode(ENA,OUTPUT);
	pinMode(ENB,OUTPUT);
	pinMode(ENA1,OUTPUT);
    pinMode(ENB2,OUTPUT);
	Serial.print("start");
	Serial.print("\n");
	reset();	

	// Flash red green led 10 times to show starting of system
	for(int i=0;i<10;i++){
		digitalWrite(red,HIGH);
		delay(50);
		digitalWrite(red,LOW);
		delay(50);
	}

}

void loop(){
	char getstr=Serial.read();
  
  	if(getstr=='M'){
		Serial.print("Mist\n");
		fog();
	}

  	else if(getstr=='F'){
		Serial.print("Fan\n");
		fan();
  	}

	else if(getstr=='R'){
		Serial.print("Rain\n");
		rain();
	}

	else if(getstr=='L'){
		Serial.print("Lightening\n");
		lightening();
	}

	else if(getstr=='N'){
		Serial.print("Normal\n");
		normal();
	}

  	else if(getstr=='r'){
		Serial.print("Reset\n");
		reset();
  	}

}
