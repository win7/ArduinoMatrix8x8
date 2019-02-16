/*
   
   Based on the following library:
   https://github.com/riyas-org/max7219/tree/master/MaxMatrix
   
*/

#include <MaxMatrix.h>
#include <avr/pgmspace.h>

int DIN = 4;   // DIN pin of MAX7219 module
int CS = 3;    // CS pin of MAX7219 module
int CLK = 2;   // CLK pin of MAX7219 module
int TOTAL_DISPLAY = 1;

PROGMEM const unsigned char CH[] = {
  3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
  1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
  3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
  5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
  4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
  5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
  5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
  1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
  3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
  3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
  5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
  5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
  2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
  4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
  2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
  4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
  4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
  3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
  4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
  4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
  4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
  4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
  4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
  4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
  4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
  4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
  2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
  2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
  3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
  3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
  3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
  4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
  5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
  4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
  4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
  4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
  4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
  4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
  4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
  4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
  4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
  3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
  4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
  4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
  4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
  5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
  5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
  4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
  4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
  4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
  4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
  4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
  5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
  4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
  5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
  5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
  5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
  5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
  4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
  2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
  4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
  2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
  3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
  4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
  2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
  4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
  4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
  4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
  4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
  4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
  3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
  4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
  4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
  3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
  4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
  4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
  3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
  5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
  4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
  4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
  4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
  4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
  4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
  4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
  3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
  4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
  5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
  5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
  5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
  4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
  3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
  3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
  1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
  3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
  4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};

char smile1[] = {
  8, 8,
  B00111100,
  B01000010,
  B10010101,
  B10100001,
  B10100001,
  B10010101,
  B01000010,
  B00111100
};

char smile2[] = {
  8, 8,
  B00111100,
  B01000010,
  B10010101,
  B10100001,
  B10100001,
  B10010001,
  B01000010,
  B00111100
};

char smile03[] = {
  8, 8,
  B00111100,
  B01000010,
  B10100101,
  B10010001,
  B10010001,
  B10100101,
  B01000010,
  B00111100
};

byte heart1[] = {
  8, 8,
  B00001100,
  B00011110,
  B00111110,
  B01111100,
  B01111100,
  B00111110,
  B00011110,
  B00001100
};

byte heart2[] = {
  8, 8,
  B00001110,
  B00111111,
  B01111111,
  B11111110,
  B11111110,
  B01111111,
  B00111111,
  B00001110
};

byte flower1[] = {
  8, 8,
  B11011011,
  B10100101,
  B01100110,
  B10011001,
  B10011001,
  B01100110,
  B10100101,
  B11011011
};

byte flower2[] = {
  8, 8, 
  B11100111,
  B10100101,
  B11011011,
  B00100100,
  B00100100,
  B11011011,
  B10100101,
  B11100111
};

byte flower3[] = {
  8, 8, 
  B11011011,
  B10100101,
  B01000010,
  B10011001,
  B10011001,
  B01000010,
  B10100101,
  B11011011
};

byte flower4[] = {
  8, 8, 
  B11100111,
  B10100101,
  B11100111,
  B00011000,
  B00011000,
  B11100111,
  B10100101,
  B11100111
};

byte flower5[] = {
  8, 8, 
  B10111101,
  B01011010,
  B10011001,
  B11100111,
  B11100111,
  B10011001,
  B01011010,
  B10111101
};

byte flower6[] = {
  8, 8, 
  B00011000,
  B00111100,
  B01011010,
  B11100111,
  B11100111,
  B01011010,
  B00111100,
  B00011000
};

byte human1[] = { 
  8, 8,
  B00000000,
  B10010000,
  B11001011,
  B00111111,
  B11001011,
  B10000100,
  B00000000,
  B10101010
};

byte human2[] = {
  8, 8,
  B00000000,
  B10000100,
  B11001011,
  B00111111,
  B11001011,
  B10010000,
  B00000000,
  B01010101
};

char text1[]= "TE LLEVARE EN MI CORAZON         ";
char text2[]= "NUNCA TE OLVIDARE         ";
char text3[]= "I LOVE YOU         ";

MaxMatrix m(DIN, CS, CLK, TOTAL_DISPLAY);
int rand_view;
int rand_effect;
int rand_delay;
int count_special = 0;
byte buffer[10];

void setup() {
  Serial.begin(9600);
  Serial.println("Run...");
  m.init();                                 // module initialize
  m.setIntensity(7);                        // dot matix intensity 0-15
  randomSeed(analogRead(0));
}
void loop() {
  rand_view = random(0, 23);              // random number from 0 to 13
  rand_effect = random(0, 4);
  rand_delay = random(1, 6);
  switch (rand_view) {
    case 0:
      PrintStringWithShift(text1, rand_delay * 50);      // (text, scrolling speed)
      break;
    case 1:
      PrintStringWithShift(text2, rand_delay * 50);
      break;
    case 2:
      ImagePWM(heart1, rand_delay * 20);
      break;
    case 3:
      ImageDinamic(heart1, heart2, rand_delay * 50);
      break;
    case 4:
      ImageDinamic(smile1, smile2, rand_delay * 50);
      break;
    case 5:
      ImageDinamic(human1, human2, rand_delay * 50);
      break;
    case 6:
      ImageBlink(smile1, rand_delay * 5);  
      break;
    case 7:
      ImageBlink(heart1, rand_delay * 5);
      break;
    case 8:
      Ajedrex(rand_delay * 5);
      break;
    case 9:
      Spiral1(rand_delay * 5);
      break;
    case 10:
      Spiral2(rand_delay * 5);
      break;
    case 11:
      TransHorizontal(rand_delay * 10);      
      break;
    case 12:
      TransVertical(rand_delay * 10);
      break;
    case 13:
      RandomPoint(rand_delay * 50);
      break;
    case 14:
      ImageBlink(flower1, rand_delay * 5);  
      break;
    case 15:
      ImageBlink(flower2, rand_delay * 5);
      break;
    case 16:
      ImageBlink(flower3, rand_delay * 5);
      break;
    case 17:
      ImageBlink(flower4, rand_delay * 5);
      break;
    case 18:
      ImageBlink(flower5, rand_delay * 5);
      break;
    case 19:
      ImageBlink(flower6, rand_delay * 5);
      break;
    case 20:
      Fire(rand_delay);
      break;
    default:
      count_special++;
      if (count_special == 21) {
        PrintStringWithShift(text3, rand_delay * 50);
        count_special = 0;
      }
      Serial.println(count_special);
      break;
  }
  delay(500);
  m.clear();
}

// Display=the extracted characters with scrolling
void PrintCharWithShift(char c, int shift_speed) {
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7 * c, 7);
  m.writeSprite(32, 0, buffer);
  m.setColumn(32 + buffer[0], 0);
  for (int i = 0; i < buffer[0] + 1; i++) {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}
// Extract the characters from the text string
void PrintStringWithShift(char* s, int shift_speed) {
  while (*s != 0) {
    PrintCharWithShift(*s, shift_speed);
    s++;
  }
}

void TransHorizontal(int delay_) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      m.setDot(col, row, true);
      delay(delay_);
    }
  }

  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      m.setDot(col, row, false);
      delay(delay_);
    }
  }
}

void TransVertical(int delay_) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      m.setDot(row, col, true);
      delay(delay_);
    }
  }

  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      m.setDot(row, col, false);
      delay(delay_);
    }
  }
}

void Fire(int delay_) {
  int rand_size; 
  for(int k = 0; k < 20; k++) {
    for (int row = 0; row < 8; row++) {
      rand_size = random(3, 8); 
      for (int col = 0; col < rand_size; col++) {
        m.setDot(row, 7 - col, true);
        delay(delay_);
      }
    }
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        m.setDot(row, 7 - col, false);
      }
    }
  }
}

void Ajedrex(int delay_) {
  int status = 0;
  int sign = -1;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      sign = sign * - 1;
      status = status + sign;
      m.setDot(col, row, status);
      delay(delay_);
    }
    sign = sign * - 1;
    status = status + sign;
  }
}

void BrightnessUp (int delay_) {
  for (int k = 0; k < 16; k+=1) {
      m.setIntensity(k);
      delay(delay_);
  
  }
}

void BrightnessDown (int delay_) {
  for (int k = 0; k < 16; k+=1) {
      m.setIntensity(15 - k);
      delay(delay_);
    
  }
}

void Spiral1 (int delay_) {
  for (int i = 0; i < 4; i++){
      for (int k = i; k < 8 - i; k++) {
        m.setDot(i, k, true);
        delay(delay_);
      }
      for (int k = i + 1; k < 8 - i; k++) {
        m.setDot(k, 7 - i, true);
        delay(delay_);
      }
      for (int k = i + 1; k < 8 - i; k++) {
        m.setDot(7 - i, 7 - k, true);
        delay(delay_);
      }
      for (int k = i + 1; k < 8 - i; k++) {
        m.setDot(7 - k, i, true);
        delay(delay_);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int k = i; k < 8 - i; k++) {
        m.setDot(i, k, false);
        delay(delay_);
      }
      for (int k = i + 1; k < 8 - i; k++) {
        m.setDot(k, 7 - i, false);
        delay(delay_);
      }
      for (int k = i + 1; k < 8 - i; k++) {
        m.setDot(7 - i, 7 - k, false);
        delay(delay_);
      }
      for (int k = i + 1; k < 8 - i; k++) {
        m.setDot(7 - k, i, false);
        delay(delay_);
      }
    }
}

void Spiral2 (int delay_) {
  for (int i = 0; i < 4; i++){
    for (int k = i + 1; k < 8 - i; k++) {
      m.setDot(7 - k, i, true);
      delay(delay_);
    }
    for (int k = i + 1; k < 8 - i; k++) {
      m.setDot(7 - i, 7 - k, true);
      delay(delay_);
    }
    for (int k = i + 1; k < 8 - i; k++) {
      m.setDot(k, 7 - i, true);
      delay(delay_);
    }
    for (int k = i; k < 8 - i; k++) {
      m.setDot(i, k, true);
      delay(delay_);
    }
  }
  for (int i = 0; i < 4; i++){
    for (int k = i + 1; k < 8 - i; k++) {
      m.setDot(k, 7 - i, false);
      delay(delay_);
    }
    for (int k = i + 1; k < 8 - i; k++) {
      m.setDot(7 - k, i, false);
      delay(delay_);
    }
    for (int k = i + 1; k < 8 - i; k++) {
      m.setDot(7 - i, 7 - k, false);
      delay(delay_);
    }
    for (int k = i; k < 8 - i; k++) {
      m.setDot(i, k, false);
      delay(delay_);
    }  
  }
}


void ImageDinamic(byte *data1, byte *data2, int delay_){
  for (int k = 0; k < 10; k++) {
    m.writeSprite(0, 0, data1);
    delay(delay_);
    m.writeSprite(0, 0, data2);
    delay(delay_);
  }
}

void ImagePWM(byte *data, int delay_) {
  for (int k = 0; k < 10; k++) {
    m.setIntensity(0);
    m.writeSprite(0, 0, data);
    BrightnessDown(delay_);
    delay(500);
    BrightnessUp(delay_);
  }
  m.setIntensity(7);  
}

void ImageBlink (byte *data, int delay_) {
  for (int k = 20; k > 1; k--) {
    m.writeSprite(0, 0, data);
    delay(rand_delay * k);
    m.clear();
    delay(rand_delay * k);
  }
}

void RandomPoint (int delay_) {
  int row_;
  int col_;
  for (int i = 0; i < 32 * (delay_ / 50); i++) {
    row_ = random(0, 8);
    col_ = random(0, 8);
    m.setDot(row_, col_, true);
    delay(delay_);
  }
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      m.setDot(row, col, false);
    }
  }
}
