void pan_error() {
  digitalWrite(ledMode, LOW);
  digitalWrite(releCale, LOW);
  texto("Fallo lectura", 50, 120, 5, WHITE);
  texto("sensor DHT!", 80, 160, 5, WHITE);
  inici = true;
  i = 0;
}

