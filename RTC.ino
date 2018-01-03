void RTC_DS () {
  DateTime now = rtc.now();
  int s = 0;
  int m = 0;
  int h = 0;
  int D = 0;
  int M = 0;
  static int vell_segond = now.second();
  static int vell_minut = now.minute();
  static int vell_hora = now.hour();
  static int vell_dia = now.day();
  static int vell_diaSetmana = now.dayOfTheWeek();
  char diaSetmana[7][10] = {"Diumenge", "Dilluns", "Dimarts", "Dimecres", "Dijous", "Divendres", "Dissabte"};

  const int posX_hora = 342;
  const int posY_hora = 182;
  const int posX_data = 320;
  const int posY_data = 210;

  if (vell_diaSetmana != now.dayOfTheWeek()) {
    vell_diaSetmana = now.dayOfTheWeek();
    tft.fillRect(335, 157, 120, 20, BLACK);
  }
  texto(diaSetmana[now.dayOfTheWeek()], 340, 160, 2, YELLOW);

  //if (vell_segond != now.second()) {
  //vell_segond = now.second();
  //tft.fillRect((posX_hora - 3 + 50 + 50), posY_hora - 5, 40, 33, BLACK);
  //}

  if (vell_minut != now.minute()) {
    vell_minut = now.minute();
    tft.fillRect((posX_hora - 3 + 50), posY_hora - 5, 40, 33, BLACK);
  }

  if (vell_hora != now.hour()) {
    vell_hora = now.hour();
    tft.fillRect(posX_hora - 3, posY_hora - 5, 40, 33, BLACK);
  }

  if (vell_dia != now.day()) {
    vell_dia = now.day();
    tft.fillRect(posX_data - 3, posY_data - 5, 140, 33, BLACK);
  }
  //**********************************************************************
  if (now.day() < 10) {
    texto("0", posX_data, posY_data, 3, WHITE);
    D = 18;
  }
  variableI(now.day(), posX_data + D, posY_data, 3, WHITE);

  texto("/", posX_data + 35, posY_data, 3, WHITE);
  if (now.month() < 10) {
    texto("0", posX_data + 50, posY_data, 3, WHITE);
    M = 18;
  }
  variableI(now.month(), (posX_data + 50) + M, posY_data, 3, WHITE);

  texto("/", (posX_data + 35 + 50), posY_data, 3, WHITE);
  variableI(now.year() - 2000, (posX_data + 50 + 50), posY_data, 3, WHITE);
  //*******************************************************************

  if (now.hour() < 10) {
    texto("0", posX_hora, posY_hora, 3, WHITE);
    h = 18;
  }
  variableI(now.hour(), (posX_hora) + h, posY_hora, 3, WHITE);

  texto(":", posX_hora + 35, posY_hora, 3, WHITE);
  if (now.minute() < 10) {
    texto("0", posX_hora + 50, posY_hora, 3, WHITE);
    m = 18;
  }
  variableI(now.minute(), (posX_hora + 50) + m, posY_hora, 3, WHITE);

  //texto(":", posX_hora + 35 + 50, posY_hora, 3, WHITE);
  //if (now.second() < 10) {
  //texto("0", posX_hora + 50 + 50, posY_hora, 3, WHITE);
  //s = 18;
  //}
  //variableI(now.second(), (posX_hora + 50 + 50) + s, posY_hora, 3, WHITE);

}
