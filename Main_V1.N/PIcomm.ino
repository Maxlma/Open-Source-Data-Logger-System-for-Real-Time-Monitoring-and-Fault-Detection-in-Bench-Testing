///////////////////////////////////Funcoes de PICom ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de PICom ////////////////////////////////////////////////////////////////////
///////////////////////////////////Funcoes de PICom ////////////////////////////////////////////////////////////////////
void PiCom() {

//  if (ACstate == 1) {
//    Serial.print("SOURCE: ");
//    Serial.print("AC LINE");
//    Serial.print("\t");
//  }
//  if (ACstate == 0) {
//    Serial.print("SOURCE: ");
//    Serial.print("BAT");
//    Serial.print("\t");
//    Serial.print("BAT Level: ");
//    Serial.print( BatDisplay);
//    Serial.print("%");
//    Serial.print("\t");
//    //  Serial.print("BAT Read: ");
//    //  Serial.print(analogRead(A6));
//    Serial.print("\t");
//  }
////  Serial.print("BAT LVL ");
////  Serial.print( analogRead(A3));
////  Serial.print("\t");
//  Serial.print("Current: ");
//  Serial.print( Ampere);
//  Serial.print(" mA");
//  Serial.print("\t");
//  Serial.print("Temp: ");
//  Serial.print( Temp1);
//  Serial.print("C");
//  Serial.print(" Temp2: ");
//  Serial.print( Temp2);
//  Serial.print("C");
//  Serial.print("\t");
//  Serial.print("Fan Usage: ");
//  if ( FANusage == 0) {
//    Serial.println("OFF");
//  }
//  if ( FANusage == 1) {
//    Serial.println("20%");
//  }
//  if ( FANusage == 2) {
//    Serial.println("50%");
//  }
//  if ( FANusage == 3) {
//    Serial.println("FULL");
//  }
//
//
//  //////////////////////////////DEBUG PRINT////////////////////////////////////////
//  //
//  //  Serial.print("total2 ");
//  //  Serial.print(total2);
//  //  Serial.print("\t");
//  //
//  //  Serial.print("TempAVG ");
//  //  Serial.print(TempAVG);
//  //  Serial.println("\t");
//
//
//
//  /////// Remote shutdown
//  RemoteShutdown = digitalRead(11);
//  if (RemoteShutdown == 0) {
//    RScount++;
//    if (RScount >= 50) {
//      ButtonCount = 0;
//      for (int x = 0; x <= 5; x++) {
//        display.clearDisplay();
//        display.setCursor(0, 0);
//        display.print(">> REMOTE SHUTDOWN <<");
//        digitalWrite(13, HIGH);
//        display.display();
//        delay(250);
//        display.clearDisplay();
//        digitalWrite(13, LOW);
//        display.display();
//        delay(250);
//      }
//
//      for (int i = 10; i >= 0; i--) {
//        display.clearDisplay();
//        display.setCursor(0, 0);
//        display.print(">> REMOTE SHUTDOWN <<");
//        display.setCursor(18, 16);
//        display.print("WAIT");
//        display.setCursor(50, 16);
//        display.print(i);
//        display.setCursor(68, 16);
//        display.print("SECONDS");
//        display.display();
//        delay(900);
//        RScount = 0;
//        Wakeup = digitalRead(Wake);
//        if (Wakeup == 1) {
//          ButtonCount++;
//        }
//        if (ButtonCount >= 3) {
//          ButtonCount = 0;
//          resetFunc();
//        }
//      }
//      display.clearDisplay();
//      display.setCursor(48, 10);
//      display.print("GOODBYE");
//      display.display();
//      delay(2000);
//      Charger_Check();
//    }
//  }
}
