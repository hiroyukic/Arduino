#include <keyboard_jp.h>
#include "Mouse.h"

/*
 * Keyboard_jp_12 for BOSS ME-30
 * Written by HIROYUKI CHIBA @2016/11/08
 * 
 * cf.http://mgt.blog.so-net.ne.jp/2016-01-14
 */

//---------------------------------------------------------------------------
// Bord_2
//   [sw1/Pin8]  [sw2/Pin9]  [sw3/Pin10]  [sw4/Pin11]  [sw5/Pin12] 
//
//   SW1 - 半角／全角
//   sw2 - F6 かな
//   sw3 - F7 全角カナ
//   sw4 - F8 半角カナ
//   sw5 - PageUP
//---------------------------------------------------------------------------
// Bord_1
//   [sw1/Pin1]  [sw2/Pin2]  [sw3/Pin3]  [sw4/Pin4]  [sw5/Pin5] 
//
//   sw1 - 半角／全角
//   sw2 - ←
//   sw3 - →
//   sw4 - ↑
//   sw5 - ↓
//   sw6 -PageDown 
//---------------------------------------------------------------------------

const int buttonON = 0;   // ボタンが押されているとピンの値はLOW
const int buttonOFF = 1;  // ボタンが押されていないとピンの値はHIGH
const int LED = 13;
int responseDelay = 200;
int ButtonState = 0;

const int BUTTON[] = { 0, 1, 2, 3, 4, 5, 6, 7,   8, 9, 10, 11,12 };
 
void setup() {
  int i;
  for( i = 0; i <= 12; i++ ){
    pinMode(BUTTON[i], INPUT_PULLUP);
  }
  Keyboard.begin();
  Mouse.begin();
  
  delay(1000);  // wait for initialization
}
 
void loop() {
  int i;
  digitalWrite(LED, LOW); 

    if( !digitalRead(BUTTON[1]) && !digitalRead(BUTTON[5]) ){
       //Keyboard.write(KEY_LEFT_ARROW);
        //digitalWrite(LED, HIGH); 
        //delay(200);

    }

    if( digitalRead(BUTTON[5]) ){
      //Keyboard.write(KEY_LEFT_ARROW);
        //Keyboard.write(KEY_KANJI);
        //digitalWrite(LED, HIGH); 
        //digitalWrite(LED, 255); 
        //delay(400);
     
    }
    
//---------------------------------------------------------------------------
// Bord_2
//   [sw1/Pin8]  [sw2/Pin9]  [sw3/Pin10]  [sw4/Pin11]  [sw5/Pin12] 
//
//   SW1 - 半角／全角
//   sw2 - F6 かな
//   sw3 - F7 全角カナ
//   sw4 - F8 半角カナ
//   sw5 - PageUP
//---------------------------------------------------------------------------
// Bord_1
//   [sw1/Pin1]  [sw2/Pin2]  [sw3/Pin3]  [sw4/Pin4]  [sw5/Pin5] 
//
//   sw1 - 半角／全角
//   sw2 - ←
//   sw3 - →
//   sw4 - ↑
//   sw5 - ↓
//   sw6 -PageDown 
//---------------------------------------------------------------------------
  for( i = 0; i <= 12; i++ ){
    digitalWrite(LED, LOW); 
    if( !digitalRead(BUTTON[i])) {

      if( i == 0) {  
        // 1-B:sw5 ：Page DOWN ★
        digitalWrite(LED, HIGH);
        Mouse.move(0,0,-1);       
        delay(80);

      } else if( i == 1 ) {  
        // 1-B:sw5 ：→ ★
        digitalWrite(LED, HIGH);
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(2);
        Keyboard.release(KEY_RIGHT_ARROW);
        delay(80);

      } else if( i == 2 ) {  
        // 1-4:sw4 :←　★
        digitalWrite(LED, HIGH);
        Keyboard.press(KEY_LEFT_ARROW);
        delay(2);
        Keyboard.release(KEY_LEFT_ARROW);
        delay(80);

      } else if( i == 3 ) {  
        //  1-3:sw3 ：↑ ★
        digitalWrite(LED, HIGH);
        //Keyboard.write(KEY_RIGHT_ARROW);
        Keyboard.press(KEY_UP_ARROW);
        delay(2);
        Keyboard.release(KEY_UP_ARROW);
        delay(30);

      } else if( i == 4 ) {  
        //  1-4:sw2 ：↓ ★
        digitalWrite(LED, HIGH);
        Keyboard.write(KEY_DOWN_ARROW);
        delay(2);
        Keyboard.release(KEY_DOWN_ARROW);
        delay(30);
         
      } else if( i == 5 ) {  
         //  1-5:sw1 ：全角/半角
        digitalWrite(LED, HIGH); 
        Keyboard.write(KEY_KANJI);
        //delay(250); // '200'以上でないと再変更がかかってしまう。
        delay(300);

      ///////////////////////////////////////////////////////////////////////////////
      //   [sw1/Pin8]  [sw2/Pin9]  [sw3/Pin10]  [sw4/Pin11]  [sw5/Pin12] 
      //
      //   SW1 - 半角／全角
      //   sw2 - F6 かな
      //   sw3 - F7 全角カナ
      //   sw4 - F8 半角カナ
      //   sw5 - PageUP
      ///////////////////////////////////////////////////////////////////////////////
      } else if( i == 8 ) {  
         //  2-1:sw1 ：全角/半角
        digitalWrite(LED, HIGH); 
        Keyboard.write(KEY_KANJI);
        delay(300);

      } else if( i == 9 ) {  
         //  2-6:sw2 ：F6:全角かな
        digitalWrite(LED, HIGH); 
        Keyboard.write(KEY_F6);
        delay(300);

      } else if( i == 10 ) {  
         //  2-7:sw3 ：F7:全角カナ
        digitalWrite(LED, HIGH); 
        Keyboard.write(KEY_F7);
        delay(300);


      } else if( i == 11 ) {  
         //  2-8:sw4 ：F8:半角ｶﾅ
        digitalWrite(LED, HIGH); 
        Keyboard.write(KEY_F8);
        delay(300);


       } else if( i == 12 ) {   
        // 2-G:sw5 ：Page UP ★★
        digitalWrite(LED, HIGH);
        Mouse.move(0,0,1);        // 
        delay(100);

      }
      
      // DeBounce
      //delay(50);                         // button debounce
      //while( !digitalRead(BUTTON[i]) ){}; // wait button release 
      //delay(50);                         // button debounce
    }
  }


  

      // DeBounce
      //delay(50);                         // button debounce
      //while( !digitalRead(BUTTON[i]) ){}; // wait button release
      //delay(50);                         // button debounce
}




//================================================================================
//  Keyboard_jp.h
//================================================================================
/***************************************************** 
        Keyboard.write('A');
        Keyboard.write('_');
        Keyboard.write('\\');
        Keyboard.write(KEY_RETURN);
        
#define KEY_RETURN        0x80  // 0x28
#define KEY_ESC           0x81  // 0x29
#define KEY_BACKSPACE     0x82  // 0x2a
#define KEY_TAB           0x83  // 0x2b
 
#define KEY_KANJI         0x8d  // 0x35 Hankaku/Zenkaku | Kanji
 
#define KEY_CAPS_LOCK     0x91  // 0x39
#define KEY_F1            0x92  // 0x3a
#define KEY_F2            0x93  // 0x3b
#define KEY_F3            0x94  // 0x3c
#define KEY_F4            0x95  // 0x3d
#define KEY_F5            0x96  // 0x3e
#define KEY_F6            0x97  // 0x3f
#define KEY_F7            0x98  // 0x40
#define KEY_F8            0x99  // 0x41
#define KEY_F9            0x9a  // 0x42
#define KEY_F10           0x9b  // 0x43
#define KEY_F11           0x9c  // 0x44
#define KEY_F12           0x9d  // 0x45
#define KEY_PRINT_SCREEN  0x9e  // 0x46
#define KEY_SCROLL_LOCK   0x9f  // 0x47
#define KEY_PAUSE         0xa0  // 0x48
#define KEY_INSERT        0xa1  // 0x49
#define KEY_HOME          0xa2  // 0x4a
#define KEY_PAGE_UP       0xa3  // 0x4b
#define KEY_DELETE        0xa4  // 0x4c
#define KEY_END           0xa5  // 0x4d
#define KEY_PAGE_DOWN     0xa6  // 0x4e
#define KEY_RIGHT_ARROW   0xa7  // 0x4f
#define KEY_LEFT_ARROW    0xa8  // 0x50
#define KEY_DOWN_ARROW    0xa9  // 0x51
#define KEY_UP_ARROW      0xaa  // 0x52
 
#define KEY_KANA          0xe0  // 0x88 Katakana/Hiragana
#define KEY_HENKAN        0xe2  // 0x8a
#define KEY_MUHENKAN      0xe3  // 0x8b
 
#define KEY_LEFT_CTRL     0xf8  // 0xe0
#define KEY_LEFT_SHIFT    0xf9  // 0xe1
#define KEY_LEFT_ALT      0xfa  // 0xe2
#define KEY_LEFT_GUI      0xfb  // 0xe3
#define KEY_RIGHT_CTRL    0xfc  // 0xe4
#define KEY_RIGHT_SHIFT   0xfd  // 0xe5
#define KEY_RIGHT_ALT     0xfe  // 0xe6
#define KEY_RIGHT_GUI     0xff  // 0xe7
************************************************/

