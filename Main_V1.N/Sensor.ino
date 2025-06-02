///////////////////////////////////Funcoes de Sensores ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Sensores ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Sensores ////////////////////////////////////////////////////////////////////
void Sensors() {
  /////DETECTA REDE AC
  if (analogRead(A7) >= 800) {
    digitalWrite(RELE2, HIGH);
    ACstate = 1;
  }
  else {
    digitalWrite(RELE2, LOW);
    ACstate = 0;
  }
  //////Battery//////
  //  Voltage Divider 16k/10k
  //  Range 12V-9V
  //  12V = 4.615V = 812 ADC CARREGADA ou maior
  //  10V = 3.85V = 787 ADC Alerta bateria baixa
  //  9.5V - 3.65V = 752 ADC Alerta desligamento
  //  9V = 3.45V 705 ADC DESLIGAMENTO IMEDIATO(Nao passar de 9V)

  //BatDisplay = analogRead(A6);
  BatDisplay = map(analogRead(A6), 600, 970, 0, 100);
  total1 = total1 - readings[readIndex1];
  readings[readIndex1] = BatDisplay;
  total1 = total1 + readings[readIndex1];
  readIndex1 = readIndex1 + 1;
  if (readIndex1 >= 12) {
    readIndex1 = 0;
  }
  BatDisplay = total1 / 12;

  if (BatDisplay >= 100) {
    BatDisplay = 100;
  }

  if (BatDisplay <= 20) {
    if (Lowbat == 0) {
      digitalWrite(13, HIGH);
    }
    Lowbat++;
    if (Lowbat == 15) {
      digitalWrite(13, LOW);
    }
    if (Lowbat == 100) {
      Lowbat = 0;
    }
  }

  if (BatDisplay <= 5) {
    for (int x = 0; x <= 20; x++) {
      display.clearDisplay();
      display.setCursor(10, 0);
      display.print(">>>> WARNING <<<<");
      display.setCursor(16, 10);
      display.print("LOW BATTERY");
      display.setCursor(20, 20);
      display.print("FORCED SHUTDOWN");
      digitalWrite(13, HIGH);
      display.display();
      delay(150);
      display.clearDisplay();
      digitalWrite(13, LOW);
      display.display();
      delay(150);
    }
    digitalWrite(RELE1, LOW);
    resetFunc();
  }

  ////////Determina a maior temperatura, Resistor(Carregador) ou Diodo(USO)
  Temp1 = ((analogRead(A0) * 5.0) - 500) / 10;
  Temp2 = ((analogRead(A1) * 5.0) - 500) / 10;
  if (Temp1 >= Temp2) {
    total2 = total2 - readings2[readIndex2];
    readings2[readIndex2] = Temp1;
    total2 = total2 + readings2[readIndex2];
    readIndex2 = readIndex2 + 1;
    if (readIndex2 >= 12) {
      readIndex2 = 0;
    }
    TempAVG = total2 / 12;
  }
  if (Temp1 <= Temp2) {
    total2 = total2 - readings2[readIndex2];
    readings2[readIndex2] = Temp2;
    total2 = total2 + readings2[readIndex2];
    readIndex2 = readIndex2 + 1;
    if (readIndex2 >= 12) {
      readIndex2 = 0;
    }
    TempAVG = total2 / 12;
  }

  ////FAN VELOCIDADE
  if(TempAVG <=40){
    FANusage = 0;
    analogWrite(FAN, 0);
  }
  if((TempAVG >=45)&& (FANusage == 0)){
    FANusage = 1;
    analogWrite(FAN, 60);
  }
  if((TempAVG >=55)&& (FANusage == 1)){
    FANusage = 2;
    analogWrite(FAN, 160);
  }
  if((TempAVG>=65)&&(FANusage == 2)){
    FANusage = 3;
    analogWrite(FAN, 254);
  }

  if (TempAVG >= 90) {
    for (int x = 0; x <= 20; x++) {
      display.clearDisplay();
      display.setCursor(10, 0);
      display.print(">>>> WARNING <<<<");
      display.setCursor(16, 10);
      display.print("HIGH TEMPERATURE");
      display.setCursor(20, 20);
      display.print("FORCED SHUTDOWN");
      digitalWrite(13, HIGH);
      display.display();
      delay(150);
      display.clearDisplay();
      digitalWrite(13, LOW);
      display.display();
      delay(150);
    }
    digitalWrite(RELE1, LOW);
    resetFunc();
  }

  //CORRENTE
  //Caululo corrente
  //transformar ADC em tensao:
  //((5*ADC)/1023)= Tensao
  //tensao inicial 2.5V
  //Tensao final 3.4V
  //Corrente incremento relacao 0.01V para cada 100mA

  Ampere = map(analogRead(A2), 510, 700, 0, 5000);
  total3 = total3 - readings3[readIndex3];
  readings3[readIndex3] = Ampere;
  total3 = total3 + readings3[readIndex3];
  readIndex3 = readIndex3 + 1;
  if (readIndex3 >= 12) {
    readIndex3 = 0;
  }
  Ampere = total3 / 12;
  if (Ampere <= 0) {
    Ampere = 0;
  }
}
