///////////////////////////////////Funcoes de Startup ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Startup ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de Startup ////////////////////////////////////////////////////////////////////
void Startup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //INICIALIZA O DISPLAY COM ENDEREÇO I2C 0x3C
  display.setTextColor(WHITE); //DEFINE A COR DO TEXTO WHITE/BLACK/ INVERSE
  display.setTextSize(1); //DEFINE O TAMANHO DA FONTE DO TEXTO
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  display.setCursor(0, 0);
  display.print("HOLDOWN FOR 2 SECONDS");
  display.setCursor(36, 11);
  display.print("NEXUS GEN1");
  display.setCursor(0, 24);
  display.print("LOADING");
  display.display();
  delay(300);
  display.setCursor(0, 24);
  display.print("LOADING .");
  display.display();
  delay(300);
  display.setCursor(0, 24);
  display.print("LOADING . .");
  display.display();
  delay(300);
  display.setCursor(0, 24);
  display.print("LOADING . . .");
  display.display();
  digitalWrite(RELE1, HIGH);
  delay(300);
  display.setCursor(0, 24);
  display.print("LOADING . . . .");
  display.display();
  delay(300);
  display.setCursor(0, 24);
  display.print("LOADING . . . . .");
  display.display();
  analogWrite(13, 220);
  digitalWrite(FAN, HIGH);
  delay(800);
  display.setCursor(0, 24);
  display.print("LOADING . . . . . .");
  display.display();
  analogWrite(13, 0);
  delay(300);
  display.setCursor(0, 24);
  display.print("LOADING . . . . . . .");
  display.display();
  delay(1200);
  display.clearDisplay();
  digitalWrite(FAN, LOW);
  digitalWrite(ChargeRELE3, LOW);
  ButtonCount = 0;
}
