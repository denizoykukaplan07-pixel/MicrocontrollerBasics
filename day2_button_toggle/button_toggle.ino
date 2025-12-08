const int buttonPin = 2;
const int ledPin    = 13;

bool ledState = false;        
int  lastButtonState = HIGH;  

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);              
  lastButtonState = digitalRead(buttonPin); 

  Serial.begin(9600);
  Serial.println("Start, LED OFF");
}

void loop() {
  int reading = digitalRead(buttonPin);  

  if (reading != lastButtonState) {

    if (reading == LOW) {
      ledState = !ledState;                          
      digitalWrite(ledPin, ledState ? HIGH : LOW);   
      Serial.println(ledState ? "ON" : "OFF"); 
    }      

    delay(50);  
  }
  lastButtonState = reading;
}



