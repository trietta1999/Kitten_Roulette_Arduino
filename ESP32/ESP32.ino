#include "src/CommonData.h"
#include "src/CommonLibrary.h"
#include "src/CommonService.h"

void WiFiReconnect() {
  // if (WiFi.status() != WL_CONNECTED) {
  //   while (WiFi.status() != WL_CONNECTED) {
  //     delay(10);
  //   }

  //   Serial.println("WiFi re-connected");
  // }
}

void HardwareBeep(uint16_t frequency, uint16_t duration) {
  //tone(BUZZER_PIN, frequency, duration);
}

void HardwareSetup() {
  // // Setup serial
  // Serial.begin(115200);

  // // Setup I/O
  // pinMode(BUZZER_PIN, OUTPUT);
  // pinMode(INPUT_PIN, INPUT_PULLUP);

  // // Wait for activate signal
  // while (digitalRead(INPUT_PIN)) {
  //   delay(10);
  // }

  // //Setup WiFi
  // WiFi.mode(WIFI_STA);
  // WiFi.begin(WIFI_SSID, WIFI_PASS);
  // WiFi.config(
  //   IPAddress(IP_ADD_1, IP_ADD_2, IP_ADD_3, IP_ADD_4),
  //   IPAddress(IP_ADD_1, IP_ADD_2, IP_ADD_3, IP_ADD_4),
  //   IPAddress(NETMASK_1, NETMASK_2, NETMASK_3, NETMASK_4));

  // // Wait for WiFi connect
  // WiFiReconnect();

  // Serial.println("WiFi connected");
  // Serial.print("IP Address: ");
  // Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
}

void IOProcessData() {

}

void loop() {
  CommonServiceProcess();
  IOProcessData();
  UpdateAll();
}
