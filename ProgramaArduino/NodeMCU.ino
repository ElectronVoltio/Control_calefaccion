void dades_NodeMCU() {
  if (Serial1.available() > 0) {
    estat = Serial1.read();
    if (estat == 99) {               //Espera resposta del NodeMCU per passar a mode desactivat amb la lletra "c"
      mode = 0;
    }
    if (estat == 97) {                //Espera resposta del NodeMCU per passar a mode automàtic amb la lletra "a"
      mode = 1;
    }
    //}
    //if (Serial1.available() > 4) {
    val_inicial = Serial1.parseFloat();
    if (val_inicial == 0) EEPROM.get(100, val_inicial);
    consigna = val_inicial;
    EEPROM.put(100, consigna);
    EEPROM.update(0, mode);
  } else {
    return;
  }
}

