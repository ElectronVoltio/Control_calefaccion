#include <ESP8266WiFi.h>

// Connexió a xarxa privada
const char* ssid = "*****************"; // Nombre de la red WIFI
const char* password = "*************"; // Contraseña

WiFiServer server(80);

// Variables temporals
static char celsiusTemp[7];         // Variable
static char humitat_percent[7];
static char consignaString[7];

IPAddress ip_xarxa;

char estat;                 // Variable de lectura dels valor enviat pel Arduino c--> Desactivat a--> Automàtic L--> Calefacció encesa l--> calefacció apagada
float t;                    // Valor de temperatura enviat per l'Arduino
float h;                    // Valor de humitat enviat per l'Arduino
float consigna;             // Valor de consigna de la temperatura en graus Celsius
bool cale;                  // Marca que indica l'estat de la calefacció false--> apagada true--> encesa
int modo = 0;               // Variable que indica el mode del control 0--> Desactivat 1--> Automàtic 2--> Manual(Aquest no es fa servir aquí
bool man = false;           // Variable sense utilitat
String getV;                // Variable que conte la resposta provenient de la pàgina web

// secuència d'arrancada
void setup() {
  // Inicialitzem port sèrie
  Serial.begin(115200);
  delay(10);

  // Connectant a la xarxa WiFi
  //Serial.println();
  //Serial.print("Connectant a ");
  //Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    //Serial.print(".");
  }
  //Serial.println("");
  //Serial.println("WiFi connectat");

  // Inicialitzant servidor WEB
  server.begin();
  //Serial.println("Servidor Web en marxa. Espereu per IP del ESP...");
  delay(10);

  // Visualitza adreça IP del ESP
  ip_xarxa = WiFi.localIP();
  Serial.println(ip_xarxa);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

}

void Dades_arduino() {

  if (Serial.available() > 0) {
    estat = Serial.read();
    delay(10);
    //Serial.println(estat);
    if (estat == 99) {
      modo = 0;
    }
    if (estat == 97) {
      modo = 1;
    }
    if (estat == 76) {
      modo = 1;
      cale = true;
    }
    if (estat == 108) {
      modo = 1;
      cale = false;
    }
  }

  if (Serial.available() > 4) {
    t = Serial.parseFloat();
    delay(10);
    h = Serial.parseFloat();
    delay(10);
    consigna = Serial.parseFloat();
    delay(10);
  } else {
    return;
  }

  //Serial.println(modo);
  //Serial.println(t);
  //Serial.println("\t");
  //Serial.println(h);
  //Serial.println("\t");
  //Serial.println(consigna);
  //Serial.print("\t");
  //Serial.println(modo);
}

// Secuència principal
void loop() {

  Dades_arduino();

  // comprova nou client
  WiFiClient client = server.available();

  String req = client.readStringUntil('H');   //Lectura de la primera línia de la resposta
  if (req.indexOf("cons=") != -1) {
    getV = req.substring(req.indexOf("=") + 1, req.length());
    consigna = 1.0 * (getV.toFloat());
    Serial.println(" ");
    Serial.println(consigna);
  }
  if (req.indexOf("incr=1") != -1) {          //Incrementa consigna en 0.5 graus
    consigna = consigna + 0.5;
    if (consigna > 30.0) {                    // límit màxim de 30ºC
      consigna = 30.0;
    }
    Serial.println(" ");
    Serial.println(consigna);
  }
  if (req.indexOf("incr=0") != -1) {          //Disminueix la consigna en 0.5 graus
    consigna = consigna - 0.5;
    if (consigna < 16.0) {                    // Límit mínim de 16ºC
      consigna = 16.0;
    }
    Serial.println(" ");
    Serial.println(consigna);
  }

  if (req.indexOf("mato=0") != -1) {          //Posa la consigna a 16ºC
    consigna = 16.0;
    Serial.println(" ");
    Serial.println(consigna);
  }
  if (req.indexOf("mato=1") != -1) {          //Posa la consigna a 20ºC
    consigna = 20.0;
    Serial.println(" ");
    Serial.println(consigna);
  }
  if (req.indexOf("mato=2") != -1) {          //Posa la consigna a 21ºC
    consigna = 21.0;
    Serial.println(" ");
    Serial.println(consigna);
  }
  if (req.indexOf("mato=3") != -1) {          //Posa la consigna a 22ºC
    consigna = 22.0;
    Serial.println(" ");
    Serial.println(consigna);
  }

  if (req.indexOf("auto=1") != -1) {           //Lectura pàgina web per passar a mode automàtic i connectar la calefacció
    modo = 1;
    Serial.write("a");
  }
  if (req.indexOf("auto=0") != -1) {           //lectura pàgina web per passar a mode desactivat i desconnectar la calefacció
    modo = 0;
    Serial.write("c");
  }

  client.flush();

  dtostrf(t, 4, 1, celsiusTemp);
  dtostrf(h, 4, 1, humitat_percent);
  dtostrf(consigna, 4, 1, consignaString);

  //PÀGINA WEB

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();

  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head> <style type='text/css'>body{width:100%;height:100%}</style><meta http-equiv='refresh' ");
  client.println("content='30;URL=/' charset='utf-8'><title>Control de temperatura casa</title>");
  client.println("</head><body bgcolor='#3daee9'><font color='white'><h1 align='center'>Control de temperatura calefacció</h1></font>");

  client.println("<table width='80%' align='center' border='2px'><tr>");
  client.println("<td width='50%' align='center' bgcolor='#9fa89d'><a style='font-size:25pt' href='/?auto=1'>Mode<br>Automàtic</a></td>");
  client.println("<td>   </td>");
  client.println("<td width='50%' align='center' bgcolor='#a89d9e'><a style='font-size:25pt' href='/?auto=0'>Mode<br>Desactivat</a></td>");
  client.println("</tr></table><br>");

  switch (modo) {
    case 0:
      //Buit
      break;
    case 1:
      client.println("<table width='80%' align='center' border='2px'><tr><td bgcolor='green' align='center' colspan='4'><h1>Control Activat</h1></td</tr>");
      client.println("<tr><td width='25%' align='center'><a style='font-size:25pt' href='/?incr=1'>Augmentar(+)</a><br></td>");
      client.println("<td width='25%' align='center' rowspan='2'><font color='white'><h2>Consigna:<br>(graus ºC)</h2></font></td> ");
      client.println("<form action='/' method='get'>");
      client.println("<td width='25%' align='center' rowspan='2'><input style='text-align: center;width: 120px;height:50px;font-size:20pt' type='text' size=3 name='cons' value='");
      //client.println(consignaString);
      client.println(consigna);
      client.println("'>");

      if (cale) {
        client.println("<td width='25%' bgcolor='#00ff00' align='center' rowspan='2'><font color='black'><h2>Encesa</h2></td></tr>");
      }
      else {
        client.println("<td width='25%' bgcolor='red' align='center' rowspan='2'><font color='white'><h2>Apagada</h2></font></td></tr>");
      }
      client.println("<tr><td align='center'><a style='font-size:25pt' href='/?incr=0'>Disminuir(-)</a></td></tr>");
      client.println("<tr><td align='center' colspan='4'><input style='width:140px;height:50px;font-size:20pt' type='submit' value='Actualitzar'>");
      client.println("</td></form></tr>");
      client.println("<tr><td align='center'><a style='font-size:25pt' href='/?mato=0'>15ºC</a></td>");
      client.println("<td align='center'><a style='font-size:25pt' href='/?mato=1'>20ºC</a></td>");
      client.println("<td align='center'><a style='font-size:25pt' href='/?mato=2'>21ºC</a></td>");
      client.println("<td align='center'><a style='font-size:25pt' href='/?mato=3'>22ºC</a></td></tr>");
      client.println("</table><br><br>");
      break;
    case 2:
      client.println("<table width='80%' align='center' border='2px'><tr>");
      client.println("<td bgcolor='red' align='center' colspan='2'><h1>Control Desactivat</h1></td>");
      client.println("</tr><tr>");
      client.println("<td align='center' colspan='2'><font color='white'><h2>Control Manual de la calefacció</h2></font></td>");
      client.println("</tr><tr>");
      client.println("<td width='50%' align='center'><a style='font-size:25pt' href='/?leds=1'>Encendre</a></td>");
      client.println("<td width='50%' align='center'><a style='font-size:25pt' href='/?leds=0'>Apagar</a></td>");
      client.println("</tr><tr>");
      if (man) {
        client.println("<td colspan='2' bgcolor='#00ff00' style='height: 10px'></td>");
      }
      else {
        client.println("<td colspan='2' bgcolor='red' style='height: 10px'></td>");
      }
      client.println("</tr></table><br><br>");
      break;
  }

  client.println("<table align='center' border='2px'><caption style='font-size:18pt'>Paràmetres actuals</caption><tr>");
  client.println("<td><input style='text-align: center;width: 160px;height:60px;font-size:40pt' type='text' size=4 name='t' value='");
  //client.println(celsiusTemp);
  client.println(t);
  client.println("'></td><td><h2> ºC de Temperatura</h2></td>");
  client.println("</tr><tr>");

  client.println("<td align='center'><input style='text-align: center;width: 80px;height:30px;font-size:20pt' type='text' size=4 name='s' value='");
  //client.println(t);
  client.println("'></td><td><h2>---</h2></td>");
  client.println("</tr><br><tr>");

  client.println("<td align='center'><input style='text-align: center;width: 80px;height:30px;font-size:20pt' type='text' size=4 name='h' value='");
  //client.println(humitat_percent);
  client.println(h);
  client.println("'></td><td><h2> % humitat</h2></td>");
  client.println("</tr></table>");
  client.println("</body></html>");

  client.stop();

}
