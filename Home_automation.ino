#define BLYNK_TEMPLATE_ID "TMPL31sVXZt3z"
#define BLYNK_TEMPLATE_NAME "HOME AUTOMATION"
#define BLYNK_AUTH_TOKEN "rMlwNpc5d8jSvs9gPUHbDnOOm5iDvj2g"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Digicoders2026";
char pass[] = "digicoders";

const uint8_t RELAY_PIN_1 = D1; 
const uint8_t RELAY_PIN_2 = D2; 

const bool relayActiveLow = true;


void setRelay(uint8_t pin, uint8_t value) {
  if (relayActiveLow) {
    digitalWrite(pin, value ? LOW : HIGH);
  } else {
    digitalWrite(pin, value ? HIGH : LOW);
  }
}


BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
}


BLYNK_WRITE(V1) {
  int v = param.asInt(); 
  setRelay(RELAY_PIN_1, v);
  Blynk.virtualWrite(V1, v);
}

BLYNK_WRITE(V2) {
  int v = param.asInt();
  setRelay(RELAY_PIN_2, v);
  Blynk.virtualWrite(V2, v);
}

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);

 
  setRelay(RELAY_PIN_1, 0);
  setRelay(RELAY_PIN_2, 0);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}