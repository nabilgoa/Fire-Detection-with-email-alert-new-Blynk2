// Chage These Credentials with your Blynk Template credentials
#define BLYNK_TEMPLATE_ID "TMPLoQJZ3ekM"
#define BLYNK_DEVICE_NAME "Fire Detection"
#define BLYNK_AUTH_TOKEN "y_X508aLE-ARQ7DcId7LMFE_P5_KzGhv"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "1 Step RnD"; // Change your Wifi/ Hotspot Name
char pass[] = "abcd@54321@"; // Change your Wifi/ Hotspot Password

BlynkTimer timer;

#define fire 23
#define GREEN 12
#define RED 14`
#define buzzer  13
int fire_Val = 0;

WidgetLED led(V1);

void setup() //Setup function - only function that is run in deep sleep mode
{
  Serial.begin(9600); //Start the serial output at 9600 baud
  pinMode(GREEN, OUTPUT);
  pinMode(fire, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000);
  timer.setInterval(500L, mySensor);
}

void loop() //Loop function
{
  Blynk.run();
  timer.run();
}

void mySensor()
{
  fire_Val = digitalRead(fire);
   
  if (fire_Val == LOW)
  {
    Blynk.logEvent("fire_alert");
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(buzzer, HIGH);
    Blynk.virtualWrite(V0, 1);
    Serial.print("fIRE Level: ");
    Serial.println(fire_Val);
    led.on();
  }

  else
  {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
    digitalWrite(buzzer, LOW);
    Blynk.virtualWrite(V0, 0);
    Serial.print("fIRE Level: ");
    Serial.println(fire_Val);
    led.off();
  }  

  
}
