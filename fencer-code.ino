int previous_state = 0;
int hit_marker = 0;
long int last_hit = 0;
int light = LOW;
const int buzzer = 9;

const int TIME_BETWEEN = 1000;
void setup() {
  
  Serial.begin(9600);

  
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //read the pushbutton value into a variable
  hit_marker = digitalRead(2);
  //print out the value of the pushbutton
  
  if((hit_marker == 0) && (millis() - last_hit > TIME_BETWEEN))
  {
    Serial.println("HIT!");
    last_hit = millis();
    
    
  }
  if(millis() - last_hit < TIME_BETWEEN)
  {
    light = HIGH;
    tone(buzzer, 2000);
  }
  else
  {
    light = LOW;
    noTone(buzzer);
  }
  digitalWrite(8, light);
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  previous_state = hit_marker;
}
