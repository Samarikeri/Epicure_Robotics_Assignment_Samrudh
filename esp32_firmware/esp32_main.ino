#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YourWiFi";
const char* password = "YourPass";

WiFiClient espClient;
PubSubClient client(espClient);

#define STM32_TX 17
#define STM32_RX 16

HardwareSerial STM(2);

void callback(char* topic, byte* payload, unsigned int length) {
  String cmd = "";
  for (int i = 0; i < length; i++) cmd += (char)payload[i];
  STM.println(cmd);  //adds cmd + /n automatically
}

void reconnect() {
  while (!client.connected()) {
    client.connect("ESP32_Client");
    client.subscribe("robot/cmd");
  }
}

void setup() {
  Serial.begin(115200);
  STM.begin(115200, SERIAL_8N1, STM32_RX, STM32_TX);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  client.setServer("broker.hivemq.com", 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected())
    reconnect();

  client.loop();
}
