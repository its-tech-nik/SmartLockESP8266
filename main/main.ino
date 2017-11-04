#include <Servo.h>

#include <ESP8266WiFi.h>

#include <Key.h>
#include <Keypad.h>

int UNLOCK = 140;
int LOCK = 70;

const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

const char* ssid = "BigDickClub";
const char* passwordWifi = "Megalh_Poutsa";

WiFiServer server(301);

byte rowPins[rows] = {16, 5, 4, 0}; //connect to the row pinouts of the keypad
byte colPins[cols] = {14, 12, 13, 15}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

String password = "4831";
String passwordTyped = "";
int position = 0;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, passwordWifi);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());

  
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  servo.attach(3);
  servo.write(UNLOCK);
  delay(8000);
  servo.write(LOCK);
}

void loop() {

  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  client.flush();

  // Match the request
  if (req.indexOf("") != -10) {  //checks if you're on the main page

    if (req.indexOf("/ON") != -1) { //checks if you clicked ON
        servo.write(UNLOCK);
        delay(8000);
        servo.write(LOCK);
        Serial.println("Door unlocked.");
    }
  }

  else {
    Serial.println("invalid request");
   client.stop();
    return;
  }


  client.flush();
  
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  
  if((int) key) {
    Serial.println(key);
    Serial.println(position);
    
    passwordTyped.concat(key);
    position++;
    if(key == '*') {
      passwordTyped = "";
    }
    if(position > password.length()) {
      if(passwordTyped.equals(password)) {
        Serial.println("Access Granted!");
        
        for(int i = 0; i < 3; i++) {
          delay(250); 
          digitalWrite(2, LOW);
          delay(250);
          digitalWrite(2, HIGH);
        }
        
        servo.write(UNLOCK);
        delay(8000);
        servo.write(LOCK);
      }
      
      position = 0;
      Serial.println(passwordTyped);
      passwordTyped = "";
    }
  }
}
