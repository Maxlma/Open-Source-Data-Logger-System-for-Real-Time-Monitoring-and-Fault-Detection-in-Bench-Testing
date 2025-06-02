///////////////////////////////////Funcoes de Desligamento ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Desligamento ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Desligamento ////////////////////////////////////////////////////////////////////
void Shutdown() {
  ButtonState = digitalRead(3);
  if (ButtonState == 1) {
    ButtonCount++;
    if (ButtonCount >= 18) {
      analogWrite(13, 254);
      display.clearDisplay();
      display.setCursor(32, 10);
      display.print("SHUTING DOWN");
      display.setCursor(0, 20);
      display.print(".  .  .  .  .  .");
      display.display();
      delay(300);
      analogWrite(13, 0);
      display.clearDisplay();
      display.setCursor(32, 10);
      display.print("SHUTING DOWN");
      display.setCursor(0, 20);
      display.print(".  .  .  .  .");
      display.display();
      delay(300);
      analogWrite(13, 254);
      display.clearDisplay();
      display.setCursor(32, 10);
      display.print("SHUTING DOWN");
      display.setCursor(0, 20);
      display.print(".  .  .  .");
      display.display();
      delay(300);
      analogWrite(13, 0);
      display.clearDisplay();
      display.setCursor(32, 10);
      display.print("SHUTING DOWN");
      display.setCursor(0, 20);
      display.print(".  .  .");
      display.display();
      delay(300);
      analogWrite(13, 2540);
      display.clearDisplay();
      display.setCursor(32, 10);
      display.print("SHUTING DOWN");
      display.setCursor(0, 20);
      display.print(".  .");
      display.display();
      delay(300);
      analogWrite(13, 0);
      display.clearDisplay();
      display.setCursor(32, 10);
      display.print("SHUTING DOWN");
      display.setCursor(0, 20);
      display.print(".");
      display.display();
      delay(300);
     display.setCursor(0, 20);
      display.print(" ");
      display.display();
      analogWrite(13, 0);
      Charger_Check();
    }
  }
}
