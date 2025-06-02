///////////////////////////////////Funcoes Charger_Check ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes Charger_Check ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes Charger_Check ////////////////////////////////////////////////////////////////////
void Charger_Check() {

  //Portasd Analogicas:
  //A3 Detector de Carga no modulo da bateria
  //A7 Detecta rede AC
  ButtonCount = 0;

  if (analogRead(A7) <= 500){
    digitalWrite(RELE1, LOW);
    digitalWrite(RELE2, LOW);
    digitalWrite(ChargeRELE3, LOW);
    delay(10000);
    resetFunc();

  }
  else {
    
    digitalWrite(ChargeRELE3, HIGH);
    delay(500);
    digitalWrite(RELE1, LOW);
    digitalWrite(RELE2, LOW);
    delay(500);


    while (analogRead(A3)<= 980) {



      Wakeup = digitalRead(Wake);
      if (Wakeup == 1) {
        ButtonCount++;
      }
      if (ButtonCount >= 3) {
        ButtonCount = 0;
        resetFunc();
      }
      TempAVG = ((((analogRead(A0) * 5.0) - 500)) / 10);
      total2 = total2 - readings2[readIndex2];
      readings2[readIndex2] = TempAVG;
      total2 = total2 + readings2[readIndex2];
      readIndex2 = readIndex2 + 1;
      if (readIndex2 >= 12) {
        readIndex2 = 0;
      }
      TempAVG = total2 / 12;

      if (TempAVG <= 40) {
        analogWrite(FAN, 0);
      }
      if ((TempAVG >= 45) && (FANusage == 0)) {
        analogWrite(FAN, 60);
      }
      if ((TempAVG >= 55) && (FANusage == 1)) {
        analogWrite(FAN, 160);
      }
      if ((TempAVG >= 65) && (FANusage == 2)) {
        analogWrite(FAN, 254);
      }

      for (int i = 44; i <= 84; i++) {
        display.setCursor(42, 24);
        display.print("Temp");
        display.setCursor(75, 24);
        display.print(TempAVG);
        display.setCursor(42, 0);
        display.print("CHARGING");
        display.setCursor(i, 12);
        display.print("|");
        display.display();
        display.clearDisplay();

      }
      for (int i = 84; i >= 44; i--) {
        display.setCursor(42, 24);
        display.print("Temp");
        display.setCursor(75, 24);
        display.print(TempAVG);
        display.setCursor(42, 0);
        display.print("CHARGING");
        display.setCursor(i, 12);
        display.print("|");
        display.display();
        display.clearDisplay();
      }
      if (analogRead(A7) <= 500) {
        display.clearDisplay();
        digitalWrite(ChargeRELE3, LOW);
        delay(10000);
        resetFunc();
      }
    }
  }
  display.clearDisplay();
  digitalWrite(ChargeRELE3, LOW);
  delay(10000);
  resetFunc();

}
