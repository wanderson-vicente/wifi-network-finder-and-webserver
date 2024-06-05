#include <WiFi.h>
#include <WebServer.h>

// WiFi credenciais 
const char* ssid = "net-wirk";
const char* password = "passwd";

// Criação do objeto WebServer na porta 80
WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Definição das rotas
  server.on("/", HTTP_GET, handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<html><body><h1>Redes encontradas</h1><ul>";
  html += getConnectedDevicesHtml();
  html += "</ul></body></html>";
  server.send(200, "text/html", html);
}

String getConnectedDevicesHtml() {
  String html = "";
  // Escaneias as redes disponíveis e armazena
  int n = WiFi.scanNetworks();
  // Itera por todas as redes encontradas e exibe na página
  for (int i = 0; i < n; ++i) {
    html += "<li>SSID: ";
    html += WiFi.SSID(i);
    html += "<br>Signal Strength: ";
    html += WiFi.RSSI(i);
    html += "<br>MAC Address: ";
    html += WiFi.BSSIDstr(i);
    html += "</li><br>";
  }
  return html;
}

