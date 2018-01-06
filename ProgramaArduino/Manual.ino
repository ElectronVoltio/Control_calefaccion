void pan_manual() {

  texto("Pantalla Manual", 60, 30, 4, CYAN);
  dibuLinea(60, 62, 412, 62, 3, true, BLUE);

  texto("Mode Manual", 130, 92, 2, WHITE);

  dibuRectag(309, 79, 152, 42, 2, true, WHITE);
  if (mode == 2) {
    while (!marca_C) {
      tft.fillRect(310, 80, 150, 40, GREEN);
      marca_C = true;
    }

    texto("Activat", 343, 92, 2, BLACK);
    marca_B = false;

    texto("Calefaccio: ", 60, 180, 2, WHITE);

    tft.drawRect(219, 167, 102, 42, WHITE);
    if (cale_on) {
      while (!marca_D) {
        tft.fillRect(220, 168, 100, 40, GREEN);
        marca_D = true;
      }

      texto("On", 250, 177, 3, BLACK);
      marca_E = false;
    } else {
      while (!marca_E) {
        tft.fillRect(220, 168, 100, 40, RED);
        marca_E = true;
      }

      texto("Off", 245, 177, 3, WHITE);
      marca_D = false;
    }

  } else {
    while (!marca_B) {
      tft.fillRect(310, 80, 150, 40, RED);
      marca_B = true;
    }

    texto("Desactivat", 326, 92, 2, WHITE);
    tft.fillRect(58, 164, 265, 50, BLACK);

    marca_C = false;
  }
}
