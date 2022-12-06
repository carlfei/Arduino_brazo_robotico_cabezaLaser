#include <Servo.h>
 
Servo servoMotor;
Servo servoMotorDos;
Servo servoMotorTres;
const int pinX = A1;
const int pinY = A0;

int pasaTresPasaDos = 0;
int xValue = 0, xValue2 = 0;
int xValueTow = 0, xValueTow2 = 0;
int yValueTow = 0, yValueTow2 = 0;
int yValue = 0, yValue2 = 0;
int laserOn=0;
int topValueTow = 0, topValueTow2 = 0;
int topValue = 0, topValue2 = 0;

int speedServoUno=2, speedServoDos=2, speedServoTres=2;

int velocidad=0;
int toMyHome=0;
int incremetalX=1,incremetalY=1, incremetalXTow=1,incremetalYTow=1, incremetalTop=1, incremetalTopTow=1;
 
void setup() {
  
  Serial.begin(9600);
 pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  servoMotor.attach(2);
  servoMotorDos.attach(3);
  servoMotorTres.attach(4);
  funcionToMyHome(0);
  xValue=analogRead(pinX);  
  yValue=analogRead(pinY);
  topValue=analogRead(pinY);
  
  xValue2=xValue;
  xValueTow2=xValue;

  
  yValue2=yValue;
  yValueTow2=yValue;

  topValue2=topValue;
  topValueTow2=topValue;
  
  funcionInit();
  
  
}




void miServoTres(){
  topValue = analogRead(pinY);
   topValueTow = analogRead(pinY);
  

   if(topValue>topValue2){
    servoMotorTres.write(incremetalTop);
//    incremetalTop=servoMotorTres.read();
    if(incremetalTop+speedServoTres<180){
      incremetalTop=incremetalTop+speedServoTres;
      incremetalTopTow=incremetalTop;
    }
    if(topValue2+speedServoTres<1015){
    topValue2=topValue2+speedServoTres;
    }
 //   topValueTow2=topValue2;
    delay(50);
   }
  
  if(topValueTow<topValueTow2){
    servoMotorTres.write(incremetalTopTow);
    if(incremetalTopTow>0){
      incremetalTopTow=incremetalTopTow-speedServoTres;
      incremetalTop=incremetalTopTow;
    }
    if(topValueTow2>10){
    topValueTow2=topValueTow2-speedServoTres;    
    }
  
    
    delay(50);
   }
  
}





void miServoDos(){
  yValue = analogRead(pinY);
   yValueTow = analogRead(pinY);
 //  Serial.print(yValue);

   if(yValue>yValue2){
    servoMotorDos.write(incremetalY);
  //  incremetalY=servoMotorDos.read();
    if(incremetalY+speedServoDos<180){
      incremetalY=incremetalY+speedServoDos;
      incremetalYTow=incremetalY;
    }
    if(yValue2+speedServoDos<1015){
    yValue2=yValue2+speedServoDos;
    }
 //   yValueTow2=yValue2;
    delay(50);
   }
  
  if(yValueTow<yValueTow2){
    servoMotorDos.write(incremetalYTow);
    if(incremetalYTow>0){
      incremetalYTow=incremetalYTow-speedServoDos;
      incremetalY=incremetalYTow;
    }
    if(yValueTow2>10){
    yValueTow2=yValueTow2-speedServoDos;    
    }
  
    
    delay(50);
   }
  
}





void miServoUno(){
  xValue = analogRead(pinX);
   xValueTow = analogRead(pinX);
 //  Serial.print(xValue);

   if(xValue>xValue2){
    servoMotor.write(incremetalX);
  //  incremetalX=servoMotor.read();
    if(incremetalX+speedServoUno<180){
      incremetalX=incremetalX+speedServoUno;
      incremetalXTow=incremetalX;
    }
    if(xValue2+speedServoUno<1015){
    xValue2=xValue2+speedServoUno;
    }
 
    delay(50);
   }
  
  if(xValueTow<xValueTow2){
    servoMotor.write(incremetalXTow);
    if(incremetalXTow>0){
      incremetalXTow=incremetalXTow-speedServoUno;
      incremetalX=incremetalXTow;
    }
    if(xValueTow2>10){
    xValueTow2=xValueTow2-speedServoUno;    
    }
  
    
    delay(50);
   }
  
}



 
void loop() {





 if (digitalRead(7) == 1) {
    if (pasaTresPasaDos == 0) {
      pasaTresPasaDos = 1;
    } else {
      pasaTresPasaDos = 0;
    }
    delay(2000);
  }

  
  if((analogRead(pinX)>540 || analogRead(pinX)<470) || (analogRead(pinY)>520 || analogRead(pinY)<445)){

    if(analogRead(pinX)>540 || analogRead(pinX)<470){
  miServoUno();
    }
 


  if (pasaTresPasaDos == 0) {
    miServoDos();
  } else {
    miServoTres();
  }
  delay(25);
  }



if (digitalRead(13) == 1){
  if(laserOn==0){
    analogWrite(6,1000);
    laserOn=1;
  }else{
  laserOn=0; 
  analogWrite(6,0); 
  }
  delay(2000);
}

if (digitalRead(11) == 1){
  if(velocidad==0){
  funcionCambiaVelocidad(0);
  velocidad=1;
  }else{
  velocidad=0; 
   funcionCambiaVelocidad(1);
  }
  delay(2000);
}

if (digitalRead(10) == 1){
  if(toMyHome==0){
  funcionToMyHome(1);
  toMyHome=1;
  }
  delay(2000);
}
//Serial.println("servo");
//Serial.println(servoMotor.read());


if(Serial.available()) funcionSerial();



}
