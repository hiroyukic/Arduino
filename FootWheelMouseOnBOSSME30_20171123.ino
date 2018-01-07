#include <Keyboard.h>


/*
  ButtonMouseControl

  For Leonardo and Due boards only.

  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

  Hardware:
   5 pushbuttons attached to D2, D3, D4, D5, D6


  The mouse movement is always relative. This sketch reads
  four pushbuttons, and uses them to set the movement of the mouse.

  WARNING:  When you use the Mouse.move() command, the Arduino takes
  over your mouse!  Make sure you have control before you use the mouse commands.

  created 15 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  this code is in the public domain
  
 FootWheelMouseOnBOSS_20161103
 FootWheelMouseOnBOSS_20161203
 FootWheelMouseOnBOSSME30_20171123  ME-30用に修正（ペダル）
*/

//  Foot2(Up)P2
//                              Button2[F6]P8            Button4[F5]P9 
//                  
//                 Button1[Down]P5       Button3[未定]P6             Button5[未定]P7
//                  
//  Foot1(Down)P1
//                  
//     
#include "Keyboard.h"
#include "Mouse.h"
//const int Button1 = 2;  // PWM[2]
//const int Button2 = 4;  // PWM[4]
//const int Button3 = 6;  // →PWM[6]
//const int Button4 = 8;  // →PWM[8]
//const int Button5 = 10; // →PWM[10]


// ペダル
const int Pedal1 = 1;   // →PWM[1] FootDown
const int Pedal2 = 2;   // →PWM[4] FootUp
// 上段
const int Button2 = 9;  // →PWM[9]
const int Button4 = 8;  // →PWM[8]
// 下段
const int Button1 = 5;  // →PWM[5] 
const int Button3 = 6;  // →PWM[6]
const int Button5 = 7;  // →PWM[7]


const int buttonON = 0;   // ボタンが押されているとピンの値はLOW
const int buttonOFF = 1;  // ボタンが押されていないとピンの値はHIGH

const int LED = 13;

int responseDelay = 200;
int ButtonState = 0;

void setup() {
  Serial.begin(9600); //シリアル通信速度（Serial.println 使用時）
  
  // input
  pinMode(Pedal1, INPUT_PULLUP);
  pinMode(Pedal2, INPUT_PULLUP);
  
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP); // Inputモードでプルアップ抵抗を有効に
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Button4, INPUT_PULLUP);
  pinMode(Button5, INPUT_PULLUP);

  // output(LED)
  pinMode(13, OUTPUT);

  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
   if (digitalRead(Pedal1) == buttonOFF 
   && digitalRead(Pedal2) == buttonOFF 
      && digitalRead(Button1) == buttonOFF 
      && digitalRead(Button2) == buttonOFF 
      && digitalRead(Button3) == buttonOFF 
      && digitalRead(Button4) == buttonOFF 
      && digitalRead(Button5) == buttonOFF) {
        delay(10);
        digitalWrite(LED, LOW);
        responseDelay = 200;
        //Serial.println( responseDelay);
        return;
   }


//Serial.println(99999);
//Serial.println(LOW);
//Serial.println(digitalRead(Button3));
//Serial.println(digitalRead(Button5));


  /* ========================================== */
  /* Pedal1（ペダル下）：Page Down */
  /* ========================================== */
  ButtonState = digitalRead(Pedal1);
  if (ButtonState == buttonON) {
      delay(5);
      ButtonState = digitalRead(Pedal1);
      if (ButtonState == buttonON) {
        /* 遅延速度コントロール　*/
        responseDelay = responseDelay - 5;
        if(responseDelay < 60) {
          responseDelay = 60;
        }
        Serial.println( responseDelay);
        /* SW_ON */
        digitalWrite(LED, HIGH);   // LED 点灯 
        Mouse.move(0,0,-1);        // Page DOWN
        delay(responseDelay);  // Mouse動作遅延 
        return;
      }
  }

  
  /* ========================================== */
  /* Pedal2（ペダル上）：Page Up */
  /* ========================================== */
  ButtonState = digitalRead(Pedal2);
  if (ButtonState == buttonON) {
      delay(5);
      ButtonState = digitalRead(Pedal2);
      if (ButtonState == buttonON) {
        /* 遅延速度コントロール　*/
        responseDelay = responseDelay - 5;
        if(responseDelay < 60) {
          responseDelay = 60;
        }
        Serial.println( responseDelay);
        /* SW_ON */
        digitalWrite(LED, HIGH);   // LED 点灯 
        Mouse.move(0,0,1);        // Page DOWN
        delay(responseDelay);  // Mouse動作遅延 
        return;
      }
  }
  
/* ----------------- 上段キー ------------------------ */

  /* ========================================== */
  /* Button4(上段左) : F5　ファンクションキー５　*/
  /* ========================================== */
  ButtonState = digitalRead(Button4);
  if (ButtonState == buttonON) {
      delay(5);
      ButtonState = digitalRead(Button4);
      if (ButtonState == buttonON) {
        //Keyboard.write(KEY_DOWN_ARROW);
        Keyboard.write(KEY_F5);
        /* SW_ON */
        digitalWrite(13, HIGH);   // LED 点灯 
        delay(200);  // Mouse動作遅延 
        return;
      }
  }

  /* ========================================== */
  /* Button2(上段右) : F6　ファンクションキー６ */
  /* ========================================== */
  ButtonState = digitalRead(Button2);
  if (ButtonState == buttonON) {
      delay(5);
      ButtonState = digitalRead(Button2);
      if (ButtonState == buttonON) {
        //Keyboard.write(KEY_DOWN_ARROW);
        Keyboard.write(KEY_F6);
        /* SW_ON */
        digitalWrite(13, HIGH);   // LED 点灯 
        delay(200);  // Mouse動作遅延 
        return;
      }
  }

/* ----------------- 下段キー ------------------------ */


  /* ========================================== */
  /* Button1(下段右) : Page UP　*/
  /* ========================================== */
  ButtonState = digitalRead(Button1);
  if (ButtonState == buttonON) {
      delay(5);
      ButtonState = digitalRead(Button1);
      if (ButtonState == buttonON) {
        /* 遅延速度コントロール　*/
        responseDelay = responseDelay - 5;
        if(responseDelay < 60) {
          responseDelay = 60;
        }
        Serial.println( responseDelay);
        /* SW_ON */
        digitalWrite(13, HIGH);   // LED 点灯 
        Mouse.move(0,0,-1);        // Page UP
        delay(responseDelay);     // Mouse動作遅延 
        return;
      }
  }


  /* ========================================== */
  /* Button5(下段左) : F5　ファンクションキー５　*/
  /* ========================================== */
  ButtonState = digitalRead(Button5);
  if (ButtonState == buttonON) {
      delay(5);
      ButtonState = digitalRead(Button5);
      if (ButtonState == buttonON) {
        //Keyboard.write(KEY_DOWN_ARROW);
        Keyboard.write(KEY_F5);
        /* SW_ON */
        digitalWrite(13, HIGH);   // LED 点灯 
        delay(200);  // 遅延 
        return;
      }
  }

  /* ========================================== */
  /* Button3(下段中) : F6　ファンクションキー６ */
  /* ========================================== */
  ButtonState = digitalRead(Button3);
  if (ButtonState == buttonON) {
      delay(5);
      ButtonState = digitalRead(Button3);
      if (ButtonState == buttonON) {
        //Keyboard.write(KEY_DOWN_ARROW);
        Keyboard.write(KEY_F6);
        /* SW_ON */
        digitalWrite(13, HIGH);   // LED 点灯 
        delay(200);  // 遅延 
        return;
      }
  }


} //END



  
  /*
  if (digitalRead(Button3) == buttonON) {
       //Serial.println(530);
       Keyboard.write(KEY_RIGHT_ARROW);
       digitalWrite(13, HIGH);   // LED 点灯 
       delay(50);  
       return;  
  }
*/



  /* =============================================== */
  /* Button5 && Button3(下段左、下段中) : KEY_LEFT_ARROW　*/
  /* =============================================== */
  /*
  if (digitalRead(Button5) == buttonON && digitalRead(Button3) == buttonON) {
        Serial.println(53);
        Keyboard.write(KEY_LEFT_ARROW);
        digitalWrite(13, HIGH);   // LED 点灯 
        delay(50); 
        return;
  } 
*/

  /* =============================================== */
  /* Button5 && Button4(下段左、上段左) : KEY_UP_ARROW　*/
  /* =============================================== */
  /*
  if (digitalRead(Button4) == buttonON) {
        Serial.println(54);
        Keyboard.write(KEY_UP_ARROW);
        digitalWrite(13, HIGH);   // LED 点灯 
        delay(50); 
        return;
  } 
  */

  /*
  if (digitalRead(Button5) == buttonON) {
       //Serial.println(540);
       Keyboard.write(KEY_LEFT_ARROW);
       digitalWrite(13, HIGH);   // LED 点灯 
       delay(50);  
       return;  
  }
*/

/**********************************************************************
The Leonardo's definitions for modifier keys are listed below:
Key    Hexadecimal value   Decimal value 
KEY_LEFT_CTRL   0x80  128
KEY_LEFT_SHIFT  0x81  129
KEY_LEFT_ALT  0x82  130
KEY_LEFT_GUI  0x83  131
KEY_RIGHT_CTRL  0x84  132
KEY_RIGHT_SHIFT   0x85  133
KEY_RIGHT_ALT   0x86  134
KEY_RIGHT_GUI   0x87  135
KEY_UP_ARROW  0xDA  218
KEY_DOWN_ARROW  0xD9  217
KEY_LEFT_ARROW  0xD8  216
KEY_RIGHT_ARROW   0xD7  215
KEY_BACKSPACE   0xB2  178
KEY_TAB   0xB3  179
KEY_RETURN  0xB0  176
KEY_ESC   0xB1  177
KEY_INSERT  0xD1  209
KEY_DELETE  0xD4  212
KEY_PAGE_UP   0xD3  211
KEY_PAGE_DOWN   0xD6  214
KEY_HOME  0xD2  210
KEY_END   0xD5  213
KEY_CAPS_LOCK   0xC1  193
KEY_F1  0xC2  194
KEY_F2  0xC3  195
KEY_F3  0xC4  196
KEY_F4  0xC5  197
KEY_F5  0xC6  198
KEY_F6  0xC7  199
KEY_F7  0xC8  200
KEY_F8  0xC9  201
KEY_F9  0xCA  202
KEY_F10   0xCB  203
KEY_F11   0xCC  204
KEY_F12   0xCD  205
See Also

    Keyboard.begin()
    Keyboard.end()
    Keyboard.press()
    
    Keyboard.release()
    Keyboard.releaseAll() 

*******************************************************************/




