//---------------------------------------IMPORTS PARA FIREBASE REALTIME
#include <FirebaseESP32.h>
#include <WiFi.h>
FirebaseData firebaseData;
const char* ssid = "ERROR404";
const char* password = "AlanTuring117";

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
//--------------------------------------------------------------MÉTODOS DE LECTURA DE SENSORES

//------------------------------------------------------------- obetener datos firebase
boolean GetControlIA() {
  if (Firebase.getBool(firebaseData, "/biorreactor/Control_IA")) {
    boolean dato = firebaseData.boolData();
    Serial.println("Control IA: ");
    Serial.print(dato);
    return dato;
  } else {
    Serial.print("Error al obtener el dato de Firebase: ");
    Serial.println(firebaseData.errorReason());
    return false; // Devuelve un valor por defecto en caso de error
  }
}
boolean GetCicloDiaNoche() {
  if (Firebase.getBool(firebaseData, "/biorreactor/Parameters/CicloDiaNoche")) {
    boolean dato = firebaseData.boolData();
    Serial.println("Control IA: ");
    Serial.print(dato);
    return dato;
  } else {
    Serial.print("Error al obtener el dato de Firebase: ");
    Serial.println(firebaseData.errorReason());
    return false; // Devuelve un valor por defecto en caso de error
  }
}

float GetTemperatureParameter() {
  if (Firebase.getFloat(firebaseData, "/biorreactor/Parameters/Temperature")) {
    float dato = firebaseData.floatData();
    Serial.println("Parametro(Temp: ): ");
    Serial.print(dato);
    return dato;
  } else {
    Serial.print("Error al obtener el dato de Firebase: ");
    Serial.println(firebaseData.errorReason());
    return -1.0; // Devuelve un valor por defecto en caso de error
  }
}

float GetPhParameter() {
  if (Firebase.getFloat(firebaseData, "/biorreactor/Parameters/Ph")) {
    float dato = firebaseData.floatData();
    Serial.println("Parametro(PH: ): ");
    Serial.print(dato);
    return dato;
  } else {
    Serial.print("Error al obtener el dato de Firebase: ");
    Serial.println(firebaseData.errorReason());
    return -1.0; // Devuelve un valor por defecto en caso de error
  }
}

float GetLightIntensityParameter() {
  if (Firebase.getFloat(firebaseData, "/biorreactor/Parameters/LightIntensity")) {
    float dato = firebaseData.floatData();
    Serial.println("Parametro(PH: ): ");
    Serial.print(dato);
    return dato;
  } else {
    Serial.print("Error al obtener el dato de Firebase: ");
    Serial.println(firebaseData.errorReason());
    return -1.0; // Devuelve un valor por defecto en caso de error
  }
}



//..------------------------------------- Función principal
void FotobiorreactorStart(){
  bool IA_Control = GetControlIA(); //----------Validar si se controlará por IA
  bool CicloDiaNoche = GetCicloDiaNoche(); //----------Validar si habrá ciclo dia noche 
  
  float ParametroTemp = GetTemperatureParameter(); //---------- Obtener el valor del parametro de la temperatura
  float ParametroPh = GetPhParameter(); //---------- Obtener el valor del parametro del pH
  float ParametroIntensityLight = GetLightIntensityParameter(); //---------- Obtener el valor del parametro de la intensidad de la luz

  //---------------------------Obtener el valor de los sensores


  
  float temperaturaSensor= 0;

  //obtener datos del sensor
  if(IA_Control==true){
    Serial.println("Control IA activated");
  }
  if(IA_Control==false){
    
    //validar temperatura

    //Validar pH

    //validar Luz

    //ValidarBombade aire
    
  }
  
}



void loop() {

  //obtener
  String datooo="";
  ///obtener valores parametros 
  //UserTemp= Firebase.getInt(firebaseData, "/biorreactor/Parameters/Temperature");
  //UserPh= Firebase.getInt(firebaseData, "/biorreactor/Parameters/Ph");
  //Firebase.setString(firebaseData, "/test", "hola mundo");
  FotobiorreactorStart();
  }
