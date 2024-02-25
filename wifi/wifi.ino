//---------------------------------------IMPORTS PARA FIREBASE REALTIME
#include <FirebaseESP32.h>
#include <WiFi.h>
FirebaseData firebaseData;
const char* ssid = "ERROR404";
const char* password = "AlanTuring117";

//---------------------------------------> IMPORTS PARA SENSOR bmp



//--------------------------------------------------------------MÉTODOS DE LECTURA DE SENSORES


//Parametros
int UserTemp =0, UserPh=0;
String luz="", aire="";

//Sensors
int ldrValue=0, temperatureValue=0, phValue=0;

void setup() {
  //---------------------------FIREBASE WIFI
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.print("Connecting with ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("WiFi conected. IP: ");
  Serial.println(WiFi.localIP());
  Firebase.begin("https://bioharvest-bc783-default-rtdb.firebaseio.com/", "jbvslc7CKYCpk9T13joPzCHMi7lZQhd47GlHlRiT");

}


void loop() {
  String datooo="";
  ///obtener valores parametros 
  //UserTemp= Firebase.getInt(firebaseData, "/biorreactor/Parameters/Temperature");
  //UserPh= Firebase.getInt(firebaseData, "/biorreactor/Parameters/Ph");
  Firebase.setString(firebaseData, "/test", "hola mundo");
  if (Firebase.getString(firebaseData, "/test")) {
    String dato = firebaseData.stringData();
    Serial.print("Dato obtenido de Firebase: ");
    Serial.println(dato);
  } else {
    Serial.println("Error al obtener el dato de Firebase");
    Serial.println(firebaseData.errorReason());
  }

  delay(2000);
Serial.println(datooo);

  

  //obeteer lecturas sensor
  
  //Guardar datos en firebase
  //Firebase.setInt(firebaseData, "/biorreactor/Sensors/ldr", ldrValue);
  delay(2000);
  
  }
