// code for your Photon Redboard goes here

int boardLed = D0;
void setup(){ 
	Particle.subscribe("Upcoming_Event10_4", flickerled); 
	Particle.subscribe("physical_computing_shreya", flash);
	Particle.publish("physical_computing_will", "test"); 
	Particle.subscribe("physical_computing_switch_status", flash);
	// ^^ this line above assumes that you have setup IFTTT listen for publish events that start with the characters "event"
	// A subscription works like a prefix filter. If you subscribe to “foo”, you will receive any event whose 
	// name begins with “foo”, including “foo”, “fool”, “foobar”, and “food/indian/sweet-curry-beans”.  So if 
	// in this case, if the event sent by IFTTT is "event" or "event_atrlkjdf" or "event/SPACE/generic/light", flickerled()
	// will trigger
	

	pinMode(boardLed,OUTPUT);
}
void loop(){

}
void flickerled (const char *event, const char *data){
	
	// this will only blink the light if the data sent with msg "event..." is, **exactly** this: "Upcoming_Event10_4"
	// this may not be useful to only blink with that specific data
	if(strcmp(data, "homework")==0){
		digitalWrite(boardLed, HIGH);
	}
	else {
	    digitalWrite(boardLed, LOW);
	}
}

void flash (const char *event, const char *data){
    Particle.publish("flashed!");
    for (int i=0; i<5, i++){
    digitalWrite(boardLed, HIGH);
    delay(300);
    digitalWrite(boardLed, LOW);
    delay(100);
    }
}


