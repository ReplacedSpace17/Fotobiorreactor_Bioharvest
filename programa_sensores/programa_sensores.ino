//---------------------------------------------- Bibliotecas
#include <OneWire.h>
#include <DallasTemperature.h>

//---------------------------------------------- Pines 
const int LedRojo = 22; // ----> Led Rojo (Wifi)
const int LedBlanco = 23; // ----> Led Blanco (Datos)
const int ldrPin = 13; // -------> LDR Sensor
int relayLuz = 32;// -------------> Relay Luz
int relayBomba = 33;// -------------> Relay Luz

// Pin de datos conectado al sensor DS18B20
#define ONE_WIRE_BUS 14
// Objeto OneWire para la comunicación con el sensor
OneWire oneWire(ONE_WIRE_BUS);
// Objeto DallasTemperature para la gestión del sensor
DallasTemperature sensors(&oneWire);


//---------------------------------------------- Variables
float temperaturaSensor = 0;


//---------------------------------------------- Métodos 
void SubiendoDatos(){
   digitalWrite(LedBlanco, HIGH);
   delay(500);
   digitalWrite(LedBlanco, LOW);
   delay(500);
}

void WifiLed(){
   digitalWrite(LedRojo, HIGH);
   
}

void ObtenerTemperatura(){
  // Se solicita la lectura de la temperatura
  sensors.requestTemperatures();
  temperaturaSensor = sensors.getTempCByIndex(0);
  Serial.print("Temperatura: ");
  Serial.println(temperaturaSensor);
}

void ObtenerLDR(){
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR: ");
  Serial.println(ldrValue);
}

///////////////////// switches
void EncenderLuz(){
  digitalWrite(relayLuz, HIGH);// set relay pin to HIGH
  delay(2000);
}
void ApagarLuz(){
  digitalWrite(relayLuz, LOW);// set relay pin to HIGH
  
}
void EncenderBomba(){
  digitalWrite(relayBomba, HIGH);// set relay pin to HIGH
 
}
void ApagarBomba(){
  digitalWrite(relayBomba, LOW);// set relay pin to HIGH
}

///////////////////////////////////////////////
void Fotobiorreactor(){
  ObtenerTemperatura();
  ObtenerLDR();


  //Leds
  SubiendoDatos();
  WifiLed();
  
  
}

//---------------------------------------------- Main 
void setup() {
  Serial.begin(9600);
  // Configuramos el pin como salida
  pinMode(LedRojo, OUTPUT);
  pinMode(LedBlanco, OUTPUT);
  pinMode(relayLuz, OUTPUT);
  pinMode(relayBomba, OUTPUT);
  // Inicialización del sensor
  sensors.begin();
  
}

void loop() {

  Fotobiorreactor();
  EncenderBomba();
}
