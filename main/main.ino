#include <Servo.h>

#include <Key.h>
#include <Keypad.h>

const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[rows] = {16, 5, 4, 0}; //connect to the row pinouts of the keypad
byte colPins[cols] = {14, 12, 13, 15}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

String password = "12345";
String passwordTyped = "";
int position = 0;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.begin(115200,SERIAL_8N1,SERIAL_TX_ONLY);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  servo.attach(3);
  servo.write(140);
  delay(5000);
  servo.write(60);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  
  if((int) key) {
    Serial.println(key);
    Serial.println(position);

    
    passwordTyped.concat(key);
    position++;
    
    if(position > 4) {
      if(passwordTyped.equals(password)) {
        Serial.println("Access Granted!");
        
        for(int i = 0; i < 3; i++) {
          delay(250); 
          digitalWrite(2, LOW);
          delay(250);
          digitalWrite(2, HIGH);
        }
        
        servo.write(140);
        delay(8000);
        servo.write(60);
      }
      
      position = 0;
      Serial.println(passwordTyped);
      passwordTyped = "";
    }
  }
}
