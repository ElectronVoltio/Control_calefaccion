void pan_parametres() {
  //DateTime now = rtc.now();

  //static int minuts_inicial = now.minute();
  //static int hora_inicial = now.hour();
  //static int dies_inicial = now.day();
  //static int mesos_inicial = now.month();
  //static int anys_inicial = now.year() - 2000;

  static int vell_hores = hora_inicial, vell_minuts = minuts_inicial;
  static int vell_dies = dies_inicial, vell_mesos = mesos_inicial, vell_anys = anys_inicial;

  texto("Parametres Rel.", 60, 30, 4, CYAN);
  dibuLinea(60, 62, 412, 62, 3, true, BLUE);

  texto("Hora", 168, 220, 2, BLUE);
  hores = num_inputI(hora_inicial, 145, 270, 2, WHITE, BLUE, 0, 23, 1);
  hora_inicial = hores;

  if (vell_hores != hores) {
    canvi_rellotge = true;
    vell_hores = hores;
  }

  texto("Minuts", 267, 220, 2, BLUE);
  minuts = num_inputI(minuts_inicial, 255, 270, 2, WHITE, BLUE, 0, 59, 1);
  minuts_inicial = minuts;

  if (vell_minuts != minuts) {
    canvi_rellotge = true;
    vell_minuts = minuts;
  }

  texto("Dia", 110, 90, 2, RED);
  dies = num_inputI(dies_inicial, 85, 140, 2, WHITE, RED, 1, 31, 1);
  dies_inicial = dies;

  if (vell_dies != dies) {
    canvi_rellotge = true;
    vell_dies = dies;
  }

  texto("Mes", 220, 90, 2, RED);
  mesos = num_inputI(mesos_inicial, 195, 140, 2, WHITE, RED, 1, 12, 1);
  mesos_inicial = mesos;

  if (vell_mesos != mesos) {
    canvi_rellotge = true;
    vell_mesos = mesos;
  }

  texto("Any", 330, 90, 2, RED);
  anys = num_inputI(anys_inicial, 305, 140, 2, WHITE, RED, 17, 99, 1);
  anys_inicial = anys;

  if (vell_anys != anys) {
    canvi_rellotge = true;
    vell_anys = anys;
  }

}

