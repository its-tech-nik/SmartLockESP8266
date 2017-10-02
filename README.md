# SmartLockESP8266

The project at this point of its lifetime, it is a simple lock that has been configures
to fit on my door. The components of it is an ESP8266 nodemcu V3, a simple 4X4 keypad,
a servo and a powerbank as a power source. The software, used to program it, is the
Arduino IDE, which I had to configure it, in order to be able to upload code to the ESP.

The capabilities of the ESP8266 are the same as of an Arduino Uno, but it has an
additional build in Wifi module, which saves you a lot of time, space and money.

The vision for this project will be to use it in a Home Automation system. I want my door
to stay unlocked, as soon as I am in my home, and keep it locked and ask for a password,
when I am not at home. Also, I want to use an Amazon Dash button, to be able to unlock the
door, while I have my door locked, which will under my desk, so I don’t need to go to the door to open it.