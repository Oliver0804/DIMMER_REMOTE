
//40 00 00 00 00 72 AA 67 30 62 30 77 30 23
int brightness = 128;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
byte Color_R[4];
byte Color_G[4];
byte Color_B[4];
byte Color_W[4];
byte Color_SR[4];
byte Color_SG[4];
byte Color_SB[4];
byte Color_SW[4];
byte buffer_RX[70];
int flag_RX = 0;
// the setup routine runs once when you press reset:
void setup() {

  // declare pin 9 to be an output:
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  for (int color = 0; color < 20; color++) {
    analogWrite(2, color);
    analogWrite(3, color);
    analogWrite(4, color);
    analogWrite(5, color);
    delay(70);
  }
  for (int color = 0; color < 20; color++) {
    analogWrite(6, color);
    analogWrite(7, color);
    analogWrite(8, color);
    analogWrite(9, color);
    delay(70);
  }
  for (int color = 0; color < 20; color++) {
    analogWrite(10, color);
    analogWrite(11, color);
    analogWrite(12, color);
    analogWrite(13, color);
    delay(70);
  }
  for (int color = 50; color > -1; color--) {
    analogWrite(10, color);
    analogWrite(11, color);
    analogWrite(12, color);
    analogWrite(13, color);
    analogWrite(6, color);
    analogWrite(7, color);
    analogWrite(8, color);
    analogWrite(9, color);
    analogWrite(2, color);
    analogWrite(3, color);
    analogWrite(4, color);
    analogWrite(5, color);
    delay(1);
  }
  //Serial.println("HI!!!");
}

// the loop routine runs over and over again forever:
void loop() {
  flag_RX = 0;
  while (Serial.available()) {
    buffer_RX[flag_RX++] = (char)Serial.read();
    //Serial.print(".");
  }
  while (Serial1.available()) {
    buffer_RX[flag_RX++] = (char)Serial1.read();
    //Serial.print(".");
  }
  for (int x = 0; x < 50; x++) {
    //Serial.print(buffer_RX[x]);
    if (buffer_RX[x] == '@' && buffer_RX[x + 10 + 3] == '#') {
      //Serial.println("OK!");
      buffer_RX[x] = 0;
      flag_RX = 0;
      switch (buffer_RX[x + 1]) {
        case 0x00:

          Serial.println("A1");
          Serial.println(buffer_RX[x + 3 + 3]);
          Serial.println(buffer_RX[x + 5 + 3]);
          Serial.println(buffer_RX[x + 7 + 3]);
          Serial.println(buffer_RX[x + 9 + 3]);

          Color_SR[1] = (int)buffer_RX[x + 3 + 3];
          Color_SG[1] = buffer_RX[x + 5 + 3];
          Color_SB[1] = buffer_RX[x + 7 + 3];
          Color_SW[1] = buffer_RX[x + 9 + 3];
          //analogWrite(2, Color_R[1]);
          //analogWrite(3, Color_G[1]);
          //analogWrite(4, Color_B[1]);
          //analogWrite(5, Color_W[1]);

          break;
        case 0x01:

          Serial.println("A2");
          Serial.println(buffer_RX[x + 3 + 3]);
          Serial.println(buffer_RX[x + 5 + 3]);
          Serial.println(buffer_RX[x + 7 + 3]);
          Serial.println(buffer_RX[x + 9 + 3]);

          Color_SR[2] = buffer_RX[x + 3 + 3];
          Color_SG[2] = buffer_RX[x + 5 + 3];
          Color_SB[2] = buffer_RX[x + 7 + 3];
          Color_SW[2] = buffer_RX[x + 9 + 3];
          //analogWrite(6, Color_R[2]);
          //analogWrite(7, Color_G[2]);
          //analogWrite(8, Color_B[2]);
          //analogWrite(9, Color_W[2]);

          break;
        case 0x02:

          Serial.println("A3");
          Serial.println(buffer_RX[x + 3 + 3]);
          Serial.println(buffer_RX[x + 5 + 3]);
          Serial.println(buffer_RX[x + 7 + 3]);
          Serial.println(buffer_RX[x + 9 + 3]);

          Color_SR[3] = buffer_RX[x + 3 + 3];
          Color_SG[3] = buffer_RX[x + 5 + 3];
          Color_SB[3] = buffer_RX[x + 7 + 3];
          Color_SW[3] = buffer_RX[x + 9 + 3];
          //analogWrite(10, Color_R[3]);
          // analogWrite(11, Color_G[3]);
          //analogWrite(12, Color_B[3]);
          //analogWrite(13, Color_W[3]);

          break;
        case '4':
          Serial.println("A4");
          Serial.println(buffer_RX[x + 3]);
          Serial.println(buffer_RX[x + 5]);
          Serial.println(buffer_RX[x + 7]);
          Serial.println(buffer_RX[x + 9]);
          break;
        case '5':
          break;
      }
    }
  }
  // Serial.print(Color_R[1]);
  // Serial.print("\t");
  // Serial.print(Color_SR[1]);
  // Serial.println("\t");
  if (Color_SR[1] > Color_R[1]) {
    Color_R[1] = Color_R[1] + 1;
    analogWrite(2, Color_R[1]);
    //Serial.print("+");
  } else if (Color_SR[1] < Color_R[1]) {
    Color_R[1] =  Color_R[1] - 1;
    analogWrite(2, Color_R[1]);
    //Serial.print("-");
  }
  if (Color_SB[1] > Color_B[1]) {
    Color_B[1] = Color_B[1] + 1;
    analogWrite(3, Color_B[1]);
  } else if (Color_SB[1] < Color_B[1]) {
    Color_B[1] = Color_B[1] - 1;
    analogWrite(3, Color_B[1]);
  }
  if (Color_SG[1] > Color_G[1]) {
    Color_G[1] = Color_G[1] + 1;
    analogWrite(4, Color_G[1]);
  } else if (Color_SG[1] < Color_G[1]) {
    Color_G[1] = Color_G[1] - 1;
    analogWrite(4, Color_G[1]);
  }
  if (Color_SW[1] > Color_W[1]) {
    Color_W[1] = Color_W[1] + 1;
    analogWrite(5, Color_W[1]);
  } else if (Color_SW[1] < Color_W[1]) {
    Color_W[1] = Color_W[1] - 1;
    analogWrite(5, Color_W[1]);
  }

  if (Color_SR[2] > Color_R[2]) {
    Color_R[2] = Color_R[2] + 1;
    analogWrite(6, Color_R[2]);
  } else if (Color_SR[2] < Color_R[2]) {
    Color_R[2] =  Color_R[2] - 1;
    analogWrite(6, Color_R[2]);
  }
  if (Color_SB[2] > Color_B[2]) {
    Color_B[2] = Color_B[2] + 1;
    analogWrite(7, Color_B[2]);
  } else if (Color_SB[2] < Color_B[2]) {
    Color_B[2] = Color_B[2] - 1;
    analogWrite(7, Color_B[2]);
  }
  if (Color_SG[2] > Color_G[2]) {
    Color_G[2] = Color_G[2] + 1;
    analogWrite(8, Color_G[2]);
  } else if (Color_SG[2] < Color_G[2]) {
    Color_G[2] = Color_G[2] - 1;
    analogWrite(8, Color_G[2]);
  }
  if (Color_SW[2] > Color_W[2]) {
    Color_W[2] = Color_W[2] + 1;
    analogWrite(9, Color_W[2]);
  } else if (Color_SW[2] < Color_W[2]) {
    Color_W[2] = Color_W[2] - 1;
    analogWrite(9, Color_W[2]);
  }


  if (Color_SR[3] > Color_R[3]) {
    Color_R[3] = Color_R[3] + 1;
    analogWrite(10, Color_R[3]);
  } else if (Color_SR[3] < Color_R[3]) {
    Color_R[3] =  Color_R[3] - 1;
    analogWrite(10, Color_R[3]);
  }
  if (Color_SB[3] > Color_B[3]) {
    Color_B[3] = Color_B[3] + 1;
    analogWrite(11, Color_B[3]);
  } else if (Color_SB[3] < Color_B[3]) {
    Color_B[3] = Color_B[3] - 1;
    analogWrite(11, Color_B[3]);
  }
  if (Color_SG[3] > Color_G[3]) {
    Color_G[3] = Color_G[3] + 1;
    analogWrite(12, Color_G[3]);
  } else if (Color_SG[3] < Color_G[3]) {
    Color_G[3] = Color_G[3] - 1;
    analogWrite(12, Color_G[3]);
  }
  if (Color_SW[3] > Color_W[3]) {
    Color_W[3] = Color_W[3] + 1;
    analogWrite(13, Color_W[3]);
  } else if (Color_SW[3] < Color_W[3]) {
    Color_W[3] = Color_W[3] - 1;
    analogWrite(13, Color_W[3]);
  }
  delay(10);

}
