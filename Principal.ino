void pan_principal() {

  static float vell_t = t;
  static float vell_h = h;
  static float vell_consigna = consigna;
  static int vell_mode = mode;

  texto("Pantalla Principal", 30, 10, 4, GREEN);
  dibuLinea(30, 42, 455, 42, 3, false, MAGENTA);

  texto("Temperatura:", 135, 65, 3, WHITE);

  dibuRectag(153, 99, 177, 42, 4, true, YELLOW);
  if (vell_t != t || primera_vegada) {
    vell_t = t;
    tft.fillRect(154, 100, 175, 40, BLUE);
  }
  variableF(t, 160, 105, 4, WHITE);
  tft.write(167);
  tft.println("C");

  dibuRectag(357, 116, 95, 22, 2, true, YELLOW);
  if (vell_h != h || primera_vegada) {
    vell_h = h;
    tft.fillRect(358, 117, 93, 20, BLUE);
  }
  texto("Humitat: ", 360, 95, 2, WHITE);
  variableF(h, 370, 120, 2, WHITE);
  tft.println("%");

  dibuRectag(29, 116, 95, 22, 2, true, YELLOW);
  if (vell_mode != mode || primera_vegada) {
    vell_mode = mode;
    tft.fillRect(30, 117, 93, 20, BLUE);
  }
  texto("Mode: ", 50, 95, 2, WHITE);

  switch (mode) {
    case 0:
      texto("OFF", 60, 120, 2, WHITE);
      break;
    case 1:
      texto("Aut.", 55, 120, 2, WHITE);
      break;
    case 2:
      texto("Man.", 55, 120, 2, WHITE);
      break;
    case 3:
      texto("Prog", 55, 120, 2, WHITE);
      break;
  }

  dibuRectag(170, 176, 95, 22, 2, true, RED);
  if (vell_consigna != consigna || primera_vegada) {
    vell_consigna = consigna;
    tft.fillRect(171, 177, 93, 20, BLUE);
  }
  texto("Consigna: ", 60, 180, 2, RED);
  variableF(consigna, 178, 180, 2, WHITE);
  tft.write(167);
  tft.println("C");

  texto("Man", 10, 250, 2, WHITE);
  texto("Aut", 225, 250, 2, WHITE);
  texto("Pro", 425, 250, 2, WHITE);

  primera_vegada = false;
}
