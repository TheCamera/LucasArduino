//Drawing Machines: Combination Lock
//Lucas Lacamara

//TODO:
////Separate brightness among r, g, and b pins.

int potPin = 0;
int potVal = 0;

int rPin = 9;
int gPin = 10;
int bPin = 11;
int rVal = 0;
int gVal = 0;
int bVal = 0;

int DEBUG = 1;

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
  if (DEBUG) {
    Serial.begin(9600);
  }
}

void loop() {
  potVal = analogRead(potPin);
  
  if (potVal < 682) { //0-682
    potVal = (potVal * 3) / 4; //Normalize to 0-255
    
    rVal = 256 - potVal; //Red from full to off
    gVal = potVal; //Green from off to full
    bVal = 1; //Blue off
    
  } else if (potVal < 1364) { //682-1364
    potVal = ((potVal - 682) * 3) / 4; //Normalize to 0-255
    
    rVal = 1; //Red off
    gVal = 256 - potVal; //Green from full to off
    bVal = potVal; //Blue from off to full
    
  } else { //1364-2046
    potVal = ((potVal - 1365) * 3) / 4; //Normalize to 0-255
    
    rVal = potVal; //Red from off to full
    gVal = 1; //Green off
    bVal = 256 - potVal; //Blue from full to off
  }
  
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
  
  if (DEBUG) {
    DEBUG += 1;
    
    if (DEBUG > 100) { //print every hundred loops
      DEBUG = 1; //Reset the counter
      
      Serial.print("R:");
      Serial.print(rVal);
      Serial.print("\t");
      
      Serial.print("G:");
      Serial.print(gVal);
      Serial.print("\t");
      
      Serial.print("B:");
      Serial.println(bVal);
    }
  }
}
