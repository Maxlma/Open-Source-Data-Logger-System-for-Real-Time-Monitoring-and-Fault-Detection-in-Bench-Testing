///////////////////////////////////Funcoes de Display ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Display ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Display ////////////////////////////////////////////////////////////////////
void Display() { // (Cursor COLUNA,LINHA)
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(">");

  if (ACstate == 1) {
    display.setCursor(10, 0);
    display.print("AC - LINE");
    display.setCursor(80, 0);
    display.print(Ampere);
    display.setCursor(110, 0);
    display.print("mA");
    display.setCursor(0, 9);
    display.print("BAT");
    display.setCursor(30, 10);
    display.print("CHARGING:");
    if (analogRead(A3) <= 990)//Detecta charging
    {
      display.setCursor(88, 10);
      display.print("YES");
    }
    else {
      display.setCursor(88, 10);
      display.print("DONE");
    }
  }

  //MODO BAT

  if (ACstate == 0) {
    display.setCursor(10, 0);
    display.print("BATTERY");
    display.setCursor(80, 0);
    display.print(Ampere);
    display.setCursor(110, 0);
    display.print("mA");
    display.setCursor(0, 10);
    display.print("BATTERY LEVEL:");
    display.setCursor(86, 10);
    display.print(BatDisplay);
    display.setCursor(105, 10);
    display.print("%");
  }

  display.setCursor(0, 21);
  display.print("FAN:");
  if ( FANusage == 0) {
    display.setCursor(30, 21);
    display.print("OFF");
  }
  if ( FANusage == 1) {
    display.setCursor(30, 21);
    display.print("20%");
  }
  if ( FANusage == 2) {
    display.setCursor(30, 21);
    display.print("50%");
  }
  if ( FANusage == 3) {
    display.setCursor(30, 21);
    display.print("FULL");
  }
  display.setCursor(60, 21);
  display.print("TEMP:");
  display.setCursor(92, 21);
  display.print(TempAVG);
  display.setCursor(110, 18);
  display.print("c");
  display.display();

}
