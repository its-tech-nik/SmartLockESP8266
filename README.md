# SmartLockESP8266

The project at this point of its lifetime, it is a simple lock that has been configured
to fit my door. The components of it is an ESP8266 NodeMCU V3, a simple 4X4 keypad,
a servo and an ANKER power bank for its power source. The software, used to program it, is the Arduino IDE, which I had to configure it, in order to be able to upload code to the
ESP.

The capabilities of the ESP8266 are the same as of an Arduino Uno, but it has an
additional build in Wifi module, which saves you a lot of time, space and money.

The vision for this project is to be able to use it in a Home Automation System (HAS). I want my door to stay unlocked, as soon as I am in my home, and keep it locked and ask for a password, while I am not at home. Also, I want to use an Amazon Dash button, to be able to lock and unlock the door, while I have my door unlocked and locked, respectively, which will be under my desk, so I don’t need to stand to open the door.