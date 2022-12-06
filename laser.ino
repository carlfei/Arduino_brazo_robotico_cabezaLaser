
#include "pitches.h"



byte  numero[10][5] =
{
  //codigo morse numeros
  { 1, 1, 1, 1, 1 }, // 0
  { 0, 1, 1, 1, 1 }, // 1
  { 0, 0, 1, 1, 1 }, // 2
  { 0, 0, 0, 1, 1 }, // 3
  { 0, 0, 0, 0, 1 }, // 4
  { 0, 0, 0, 0, 0 }, // 5
  { 1, 0, 0, 0, 0 }, // 6
  { 1, 1, 0, 0, 0}, // 7
  { 1, 1, 1, 0, 0 }, // 8
  { 1, 1, 1, 1, 4 } // 9
};

char data[] = "";

byte  letras[26][4] =
{
  //codigo morse numeros
  { 0, 1, 4, 4 }, // a
  { 1, 0, 0, 0}, // b
  { 1, 0, 1, 0}, // c
  { 1, 0, 0, 4}, // d
  { 0, 4, 4, 4}, // e
  { 0, 0, 1, 0}, // f
  { 0, 0, 1, 4}, // g
  { 0, 0, 0, 0}, // h
  { 0, 0, 4, 4}, // i
  { 0, 1, 1, 1},// j
   { 0, 1, 0, 4}, // k
  { 0, 1, 0, 0}, // l
  { 0, 0, 4, 4}, // m
  { 0, 1, 4, 4}, // n
  { 0, 0, 0, 4}, // o
  { 0, 1, 1, 0}, // p
  { 1, 1, 0, 1}, // q
  { 0, 1, 0, 4}, // r
  { 0, 0, 0, 0}, // s
  { 1, 4, 4, 4},// t

   { 0, 0, 1, 4}, // u
  { 0, 0, 0, 1}, // v
  { 0,1, 1, 4}, // w
  { 1, 0, 0, 1}, // x
  { 1, 0, 1, 1}, // y
  { 1, 1, 0, 0} // z
  
};

char abc[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int punto=40;
int raya=120;
int pausaEntreLetras=120;
int pausaEntrePalabras=280;

int codificacion[5]={40,120,120,280,0};
 
void funcionInit(){
  Serial.begin(9600);
 
  pinMode(6, OUTPUT);
  pinMode(9, INPUT);
  pinMode(12, OUTPUT);
 
 }

void numeroCuatro(int numer){
  for(int i=0; i<5;i++){
  
      analogWrite(6,1000);
      delay(codificacion[numero[numer][i]]);
      analogWrite(6,0);
      delay(pausaEntrePalabras);
    
  }
 }


void letrasAbc(int numer){
  for(int i2=0; i2<4;i2++){
  
      analogWrite(6,1000);
      tone(12, 800);
      delay(codificacion[letras[numer][i2]]);
      noTone(12);
      analogWrite(6,0);
      delay(pausaEntreLetras);
    
  }
 }

 
void funcionSerial(){

//int index=0;
   while (Serial.available())
   {
      char character = Serial.read();
      if (character != '\n')
      {
        // data[index].concat(character);
      //  Serial.print(character);
        // data[index]=character;
         //letrasAbc(y);
        // index++;

         if(character==' '){
           delay(pausaEntrePalabras);
           Serial.print(" ");
         }else{
         for(int y=0; y<26; y++){
        
        if(abc[y]==character){
          Serial.print(abc[y]);
          letrasAbc(y);
          break;
        
      }
      }
         }
         
      }
      else
      {
//         Serial.println(data[index-1]);
//         data[] = "";
  Serial.println();
      }
   }

   }
  //Serial.print(digitalRead(9));
