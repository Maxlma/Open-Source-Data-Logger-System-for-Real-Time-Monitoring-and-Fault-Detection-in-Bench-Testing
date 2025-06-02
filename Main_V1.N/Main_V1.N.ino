// PLACA FONTE Power Guard //
// Versão 1 HW V1.K             //
// Marcio Amorim Agosto 2022  //

//Portasd Analogicas:
//A0 Temperatura Resistor Carga
//A1 Temperatura Diodo Saida
//A2 Medidor de Corrente
//A3 Detector de Carga no modulo da bateria
//A4 SDA
//A5 SCL
//A6 NIVEL BATERIA
//A7 Detecta rede AC


// Lista de errors:
// Nao continua carga apos desligar e bateria carregando

#include <Wire.h>
#include <Adafruit_GFX.h>
#define SSD1306_128_32
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306();

#define RELE1 4 //Rele que seleciona antrada bateria ou Carregador
#define RELE2 2 //Rele que seleciona SftwareStart do curcuito
#define ChargeRELE3 7 // Rele de modo sleep para carga AC
#define FAN 9
#define Wake 6
uint8_t Temp1 = 0;
uint8_t Temp2 = 0;
uint8_t Lowbat = 1;


bool ACstate = 0;
bool ButtonState = 0;
bool Wakeup = 0;
bool RemoteShutdown = 0;

uint8_t FANusage = 0;
uint8_t ButtonCount = 0;
uint8_t RScount = 0;


//AVG BAT LEVEL
uint8_t readings[12];
uint8_t readIndex1 = 0;
int total1 = 0;
uint8_t BatDisplay = 0;

// AVG TEMP LEVEL
uint8_t readings2[12];
uint8_t readIndex2 = 0;
uint16_t total2;
uint8_t TempAVG;

// AVG AMP LEVEL
int readings3[12];
uint8_t readIndex3 =0;
int total3 = 0;
uint16_t Ampere = 0; // medidor Ampere


void setup() {
  ///////////////DEFINICAO DE PINOS ////////////////////////////////////////////////////////////////////
  ///////////////DEFINICAO DE PINOS ////////////////////////////////////////////////////////////////////
  ///////////////DEFINICAO DE PINOS ////////////////////////////////////////////////////////////////////
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
  pinMode(ChargeRELE3, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, INPUT);
  pinMode(Wake, INPUT);
  Serial.begin(115200);
  Wire.begin();
  Startup();

  for (int thisReading = 0; thisReading < 12; thisReading++) {
    readings[thisReading] = 0;
  }
  for (int thisReading2 = 0; thisReading2 < 12; thisReading2++) {
    readings2[thisReading2] = 0;
  }
  for (int thisReading3 = 0; thisReading3 < 12; thisReading3++) {
    readings3[thisReading3] = 0;
  }
}
void(* resetFunc) (void) = 0;

void loop() {
  Shutdown();
  Display();
  Sensors();
  PiCom();
}
