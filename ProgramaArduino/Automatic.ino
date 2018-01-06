void pan_automatic() {
  texto("Automatic", 130, 30, 4, RED);
  dibuLinea(130, 62, 343, 62, 3, true, BLUE);

  texto("Mode Automatic", 130, 92, 2, WHITE);
  dibuRectag(309, 79, 152, 42, 2, true, WHITE);
  if (!digitalRead(ledMode)) {
    while (!marca_F) {
      tft.fillRect(310, 80, 150, 40, RED);
      marca_F = true;
    }
    texto("Desactivat", 326, 92, 2, WHITE);
    marca_G = false;
    FillRectagRudo(140, 155, 205, 80, 5, 3, true, BLACK);
  } else {
    while (!marca_G) {
      tft.fillRect(310, 80, 150, 40, GREEN);
      marca_G = true;
    }
    texto("Activat", 343, 92, 2, BLACK);
    marca_F = false;
    
    consigna = num_inputF(val_inicial, 150, 180, 5, WHITE, RED, 15.0, 30.0, 0.5);
    val_inicial = consigna;
    EEPROM.put(100, consigna);
  }
  
  

}
