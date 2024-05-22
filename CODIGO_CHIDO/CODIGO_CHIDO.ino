#include <ESP32Firebase.h>

// Definir las credenciales de la red WiFi
#define WIFI_SSID "ERROR404"
#define WIFI_PASSWORD "AlanTuring117"

// Definir la URL de referencia de tu proyecto Firebase
#define REFERENCE_URL "https://bioharvest-bc783-default-rtdb.firebaseio.com/"

int bombaPin = 2;
int luzPin = 4;
Firebase firebase(REFERENCE_URL);

void setup() {
  pinMode(bombaPin, OUTPUT);
   pinMode(luzPin, OUTPUT);
  Serial.begin(115200);

  // Configurar el modo WiFi y desconectar cualquier conexión previa
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Conectar a la red WiFi
  Serial.println();
  Serial.println();
  Serial.print("Conectando a: ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Conectado");

  // Imprimir la dirección IP
  Serial.print("Dirección IP: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  // Leer valor entero de la ruta especificada en Firebase
  int bombaStatus = firebase.getInt("BioharvestApp/Usuarios/67f8f9be-25cb-4655-9549-a14288cb0ae5/Fotobiorreactores/663b531b-7b3d-43bd-8cce-7a4eedbcaf76/ControlBiorreactor/Bomba");
   int lamparaStatus = firebase.getInt("BioharvestApp/Usuarios/67f8f9be-25cb-4655-9549-a14288cb0ae5/Fotobiorreactores/663b531b-7b3d-43bd-8cce-7a4eedbcaf76/ControlBiorreactor/Lampara");
  Serial.println("Lampara:");
  Serial.println(lamparaStatus);
   Serial.println("Bomba:");
  Serial.println(bombaStatus);
  
digitalWrite(bombaPin, bombaStatus == 1 ? HIGH : LOW);
digitalWrite(luzPin, lamparaStatus == 1 ? HIGH : LOW);

  

  delay(500); // Esperar 5 segundos antes de la próxima solicitud
}
