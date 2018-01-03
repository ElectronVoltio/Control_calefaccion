#include <DHT.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
#include <TouchScreen.h>

//#define USE_ADAFRUIT_SHIELD_PINOUT
#define DHTTYPE DHT22

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define YP A2 // Pin analogico A1 para ADC
#define XM A3 // Pin analogico A2 para ADC
#define YM 8
#define XP 9

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define TS_MINX 65
#define TS_MINY 140
#define TS_MAXX 905
#define TS_MAXY 915

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ORANGE  0xC360

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

const int DHTPin = 22;
DHT dht(DHTPin, DHTTYPE);

RTC_DS1307 rtc;

float h;                // Variable de humitat directe de DHT
float t_real;           // Variable de temperatura lectura real directe de sensor
int temper;             //
int resto_t;            // Variable resto de una divisió de temperatura
float t;                // Variable de temperatura de salts de 0,5
float t_rudo;
float consigna;         // Variable de la consigna
float val_inicial;      // Variable amb el valor inicial de la consigna
bool error = false;     // Error de lectura del sensor DHT
int xpos;               // Variables que emmagatzenarà les coordenades
int ypos;               // X, Y on presioem i la variable Z
int zpos;               // emmagatzenarà la presió realitzada
int pagina = 1;         // Variable que porta la pàgina de la pantalla TFT
bool s_tempor_B;        // Marca per controlar en temps que permanència a les pantalles manual i automàtic
bool s_tempor_C;        // Marca per controlar en temps que el control està en mode manual
bool marca_M = false;   // Marca per antirepetició del botó del mode manual
bool marca_MC = false;  // Marca per antirepetició del botó on/off calefacció en manual
bool marca_A = false;   // Marca per antirepetició del boto del mode automàtic
bool marca_B = false;   // Marca per evitar el parpadeix del botó de activació del mode manual de la paraula "desactivat"
bool marca_C = false;   // Marca per evitar el parpadeix del botó de activació del mode manual de la paraula "activat"
bool marca_D = false;   // Marca per evitar el parpadeix del botó de activació de la calefacció en mode manual de la paraula "On"
bool marca_E = false;   // Marca per evitar el parpadeix del botó de activació de la calefacció en mode manual de la paraula "Off"
bool marca_F = false;   // Marca per evitar el parpadeix del botó de activació del mode automàtic de la paraula "desactivat"
bool marca_G = false;   // Marca per evitar el parpadeix del botó de activació del mode automàtic de la paraula "activat"
int mode = 0;           // Variable que emmagatzena el mode en que es trobe el control, 0--> desactivat 1--> Automàtic 2--> Manual (no confonfre amb les pantalles)
bool cale_on = false;   // Marca per indicar que la calefacció està en marxa en mode manual

float temperatura[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int i = 0;
float media;
bool inici = true;

char estat;

unsigned long temporiza_A = millis(); // Variable del temps de lectura del sensor DHT
unsigned long temporiza_B = millis(); // Variable del temps de permanència en les pagines manual i automàtic
unsigned long temporiza_C = millis(); // Variable del temps de permanència en mode manual(Per evitar que la calefacció es pogui quedar encesa
//unsigned long temporiza_D = millis();

const int ledMode = 53;   //Sortida per al LED que indica que el mode automàtic està actiu
const int releCale = 52;  //Sortida per activar el relé i en LED de la calefacció
const int ledCale = 51;   // Sortida per al LED que indica que la calefacción està en marxa

int minuts, hores, dies, mesos, anys;
int minuts_inicial, hora_inicial, dies_inicial, mesos_inicial, anys_inicial;
bool canvi_rellotge = false;

static bool primera_vegada = true;

void setup(void) {

  Serial.begin(115200);

  if (! rtc.begin()) {
    Serial.println("No Trobo el DS1307");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC No funciona!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(ledMode, OUTPUT);
  pinMode(releCale, OUTPUT);
  pinMode(ledCale, OUTPUT);

  Serial1.begin(115200);
  dht.begin();

  tft.reset();
  tft.begin(0x9481); // Posar aquí el ILI de la pantalla, Ha de ser en hexadecimal
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  pan_inici();

  //EEPROM.put(100, 17.50);
  EEPROM.get(100, val_inicial);
  delay(5);
  //EEPROM.put(0, 1);
  EEPROM.get(0, mode);
  delay(5);

  if (mode == 1) {
    marca_A = true;
    marca_M = false;
    Serial1.write("a");
    digitalWrite(ledMode, HIGH);
  }
  consigna = val_inicial;
  lectura_DHT();
  pan_principal();
}

void pan_inici() {
  tft.fillScreen(BLUE);
  tft.fillScreen(MAGENTA);
  tft.fillScreen(YELLOW);
  tft.fillScreen(RED);
  tft.fillScreen(BLACK);
  texto("BENVINGUTS!!!", 100, 140, 4, GREEN);
  delay(2000);
  tft.fillScreen(BLACK);
}

void lectura_DHT() {

  h = dht.readHumidity();
  t_real = dht.readTemperature();

  if (inici) {
    media = t_real;
    inici = false;
  }

  temperatura[i] = t_real;
  i++;
  if (i > 19) {
    i = 0;
    media = 0;
    for (int j = 0; j < 20; j++) {
      media = (media + temperatura[j] / 20.0);
    }
  }

  temper = media * 100;
  resto_t = temper % 100;
  temper = temper / 100;
  if (resto_t < 30) {
    t = (temper * 1.00);
  } else if (resto_t >= 30 && resto_t <= 70) {
    t = (temper * 1.00) + 0.50;
  } else if (resto_t > 70) {
    t = (temper * 1.00) + 1.00;
  }

  error = (isnan(h) || isnan(t_real));

  // ********** Enviament de dades al NodeMCU **********
  if (mode == 1 && digitalRead(releCale)) Serial1.write("L");
  if (mode == 1 && !digitalRead(releCale)) Serial1.write("l");
  if (mode != 1) Serial1.write("c");
  Serial1.println(t);
  Serial1.println(h);
  Serial1.println(consigna);
  // ********** Fi del enviament de dades **********

}

void lecturaPanel() {

  TSPoint p = ts.getPoint(); // Realizamos lectura de las coordenadas

  pinMode(XM, OUTPUT); // La llibreria utilitza aquests pines com entrada i sortida
  pinMode(YP, OUTPUT); // és convenient declarar-los com sortida just abans de realitzar una lectura de coordenades.

  xpos = map(p.x, TS_MAXX, TS_MINX, tft.width(), 0); // Mapeam els valors analògics llegits del panel tàctil (0-1023)
  ypos = map(p.y, TS_MAXY, TS_MINY, tft.height(), 0); // i els convertim en valor corresponent a la medida del LCD (3,5" serà de 480x320px)
}

void loop(void) {

  lecturaPanel(); // Realitzem la lectura del panel per detectar les coordenades
  dades_NodeMCU();

  switch (pagina) {
    case 1: // Principal <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

      //tempor_A(3);
      RTC_DS();

      if (botoInstanRectan(1, 270, 50, 50, 2, GREEN, MAGENTA)) {
        pagina = 2; // Pagina Manual
        tft.fillScreen(BLACK);
        s_tempor_B = true;
        marca_B = false;
        marca_C = false;
        marca_D = false;
        marca_E = false;
        temporiza_B = millis();
        primera_vegada = true;
        break;
      }
      if (botoInstanRectan(217, 270, 50, 50, 2, GREEN, MAGENTA)) {
        pagina = 3; // Pagina automàtic
        tft.fillScreen(BLACK);
        s_tempor_B = true;
        marca_F = false;
        marca_G = false;
        temporiza_B = millis();
        primera_vegada = true;
        break;
      }
      if (error) {
        pagina = 4;
        tft.fillScreen(RED);
        break;
      }
      //if (botoInstanRectan(1, 270, 50, 50, 2, WHITE, MAGENTA)) {
      if ((xpos > 318 && xpos < 443) && (ypos > 172 && ypos < 240)) {
        pagina = 5; // Pagina Reloj
        temporiza_B = millis();
        s_tempor_B = true;
        primera_vegada = true;
        DateTime now = rtc.now();
        minuts_inicial = now.minute();
        hora_inicial = now.hour();
        dies_inicial = now.day();
        mesos_inicial = now.month();
        anys_inicial = now.year() - 2000;
        tft.fillScreen(BLACK);
        pan_parametres();
        break;
      }
      if (botoInstanRectan(417, 270, 50, 50, 2, GREEN, MAGENTA)) {
        pagina = 6; // Pagina programació
        tft.fillScreen(BLACK);
        s_tempor_B = true;
        //marca_F = false;
        //marca_G = false;
        temporiza_B = millis();
        primera_vegada = true;
        break;
      }

      tempor_A(3);

      break;
    case 2: // Manual <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

      pan_manual();
      tempor_B();

      // ******** Pulsador de mode manual ************
      if ((xpos > 295 && xpos < 450) && (ypos > 75 && ypos < 121) && !marca_M) {
        mode = 2;
        marca_M = true;
        temporiza_B = millis();
        temporiza_C = millis();
        marca_A = false;
        digitalWrite(ledMode, LOW);
      } else if (((xpos > 295 && xpos < 450) && (ypos > 75 && ypos < 121) && marca_M)) {
        mode = 0;
        Serial1.write("c");
        marca_M = false;
        temporiza_B = millis();
        marca_B = false;
        digitalWrite(ledMode, LOW);
      }

      while ((xpos > 295 && xpos < 450) && (ypos > 75 && ypos < 121)) {
        lecturaPanel();// Anti-repetició
      }
      // ******** Fi Pulsador manual *****************

      // ************** Pulsador calefacció on/off ****************************
      if (mode == 2) {
        if ((xpos > 215 && xpos < 315) && (ypos > 168 && ypos < 209) && !marca_MC) {
          cale_on = true;
          marca_MC = true;
          temporiza_B = millis();
          digitalWrite(releCale, HIGH);
          digitalWrite(ledCale, HIGH);
        } else if ((xpos > 215 && xpos < 315) && (ypos > 168 && ypos < 209) && marca_MC) {
          cale_on = false;
          marca_MC = false;
          temporiza_B = millis();
          digitalWrite(releCale, LOW);
          digitalWrite(ledCale, LOW);
        }

        while ((xpos > 215 && xpos < 315) && (ypos > 168 && ypos < 209)) {
          lecturaPanel();// Anti-repetició
        }

      } else {
        marca_D = false;
        marca_E = false;
        cale_on = false;
      }
      // ************************* Fi pulsador calefacció *************************

      // ******** Pulsador retorn P. Principal ***************
      if (botoInstanRectan(425, 270, 50, 50, 2, WHITE, MAGENTA) or !s_tempor_B) {
        pagina = 1; // Pàgina principal
        tft.fillScreen(BLACK);
        pan_principal();
        break;
      }
      // *********** Fi Pulsador retorn ***************
      // *********** Pulsador pàgina paràmetres reloj ***********
      /*if (botoInstanRectan(1, 270, 50, 50, 2, WHITE, MAGENTA)) {
        pagina = 5; // Pagina Reloj
        temporiza_B = millis();
        DateTime now = rtc.now();
        minuts_inicial = now.minute();
        hora_inicial = now.hour();
        dies_inicial = now.day();
        mesos_inicial = now.month();
        anys_inicial = now.year() - 2000;
        tft.fillScreen(BLACK);
        pan_parametres();
        break;
        }*/
      // *********** Fi pulsador paràmetres reloj **********
      break;
    case 3: // Automàtic<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

      pan_automatic();
      tempor_B();

      // ************* Pulsador de mode automàtic ***********
      if ((xpos > 295 && xpos < 450) && (ypos > 75 && ypos < 121) && !marca_A) {
        marca_A = true;
        mode = 1;
        Serial1.write("a");
        temporiza_B = millis();
        marca_M = false;
        digitalWrite(ledMode, HIGH);
      } else if ((xpos > 295 && xpos < 450) && (ypos > 75 && ypos < 121) && marca_A) {
        marca_A = false;
        mode = 0;
        Serial1.write("c");
        temporiza_B = millis();
        digitalWrite(ledMode, LOW);
      }

      while ((xpos > 295 && xpos < 450) && (ypos > 75 && ypos < 121)) {
        lecturaPanel();// Anti-repetició
      }
      // *********** Fi Pulsador automàtic *********

      if ((xpos > 150 && xpos < 400) && (ypos > 180 && ypos < 220)) {
        temporiza_B = millis();
      }

      // ********** Pulsador de retorn pantalla principal *************
      if (botoInstanRectan(1, 270, 50, 50, 2, WHITE, MAGENTA) or !s_tempor_B) {
        pagina = 1;
        tft.fillScreen(BLACK);
        pan_principal();
      }
      // *********** Fi Pulsador retorn ***************
      break;
    case 4: // Error de lectura DHT <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      pan_error();
      lectura_DHT();
      // ********** Retorn pantalla principal quan ya no hi ha error de DHT *************
      if (!error) {
        pagina = 1;
        tft.fillScreen(BLACK);
        pan_principal();
      }
      // *********** Fi retorn després de error DHT ***************

      break;
    case 5: // Paràmetres reloj

      pan_parametres();
      tempor_B();

      if ((xpos > 200 && xpos < 360) && (ypos > 240 && ypos < 310) || (xpos > 140 && xpos < 400) && (ypos > 110 && ypos < 180)) {
        temporiza_B = millis();
      }

      // ********** Pulsador de retorn pantalla principal *************
      if (botoInstanRectan(425, 270, 50, 50, 2, WHITE, MAGENTA) or !s_tempor_B) {
        //if (botoInstanRectan(425, 270, 50, 50, 2, WHITE, MAGENTA)) {
        pagina = 1; // Pàgina principal
        if (canvi_rellotge) {
          canvi_rellotge = false;
          transmi();
        }
        tft.fillScreen(BLACK);
        pan_principal();
      }
      // *********** Fi Pulsador retorn ***************
      break;
    case 6: // Programació

      programacio();
      tempor_B();

      // ********** Pulsador de retorn pantalla principal *************
      if (botoInstanRectan(1, 270, 50, 50, 2, WHITE, MAGENTA) or !s_tempor_B) {
        pagina = 1;
        tft.fillScreen(BLACK);
        pan_principal();
      }
      // *********** Fi Pulsador retorn ***************
      break;
  } // Fi del Switch

  EEPROM.update(0, mode);

  if (mode == 0) {
    digitalWrite(releCale, LOW);
    digitalWrite(ledCale, LOW);
    digitalWrite(ledMode, LOW);
  }

  // *********** Selecció de valor de consigna temperatura **********
  if (mode == 1 & !error) {
    if (t <= consigna) {
      digitalWrite(releCale, HIGH);
      digitalWrite(ledCale, HIGH);
    } else {
      digitalWrite(releCale, LOW);
      digitalWrite(ledCale, LOW);
    }
    digitalWrite(ledMode, HIGH);
  }
  // ********** Fi de la selección de valor de consigna **********

  if (mode == 2 & !error) {
    tempor_C();
    if (!s_tempor_C) {
      mode = 0;
      Serial1.write("c");
      marca_M = false;
      marca_C = false;
      marca_B = false;
      s_tempor_C = true;
      digitalWrite(ledMode, LOW);
      digitalWrite(releCale, LOW);
      digitalWrite(ledCale, LOW);
      marca_D = false;
      marca_E = false;
      cale_on = false;
    }
    if (cale_on) {
      digitalWrite(releCale, HIGH);
      digitalWrite(ledCale, HIGH);
    }
  }

} // Fi del LOOP

void tempor_A(int temps) {
  if (temporiza_A > millis()) temporiza_A = millis();
  if ((millis() - temporiza_A) >= (temps * 1000)) {
    temporiza_A = millis();
    lectura_DHT();
    pan_principal();
  }
}

void tempor_B() {      // Temps per tornar a la pàgina principal des de pàg. manual i automàtic aprox. 8 segons
  if (temporiza_B > millis()) temporiza_B = millis();
  if ((millis() - temporiza_B) >= 10000) {
    temporiza_B = millis();
    s_tempor_B = false;
  }
}

void tempor_C() {     // Temps de seguretat per desconnectar el mode manual aprox. 10 minuts (600 segons)
  if (temporiza_C > millis()) temporiza_C = millis();
  if ((millis() - temporiza_C) >= 600000) {
    temporiza_C = millis();
    s_tempor_C = false;
  }
}

/*void tempor_D() {
  if (temporiza_D > millis()) temporiza_D = millis();
  if ((millis() - temporiza_D) >= 1000) {
    temporiza_D = millis();
    RTC_DS();
  }
  }*/

