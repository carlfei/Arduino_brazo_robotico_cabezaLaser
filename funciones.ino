
void funcionCambiaVelocidad(int veloz){
  if(veloz==0){
    veloz=speedServoUno+2;
    speedServoUno=speedServoDos=speedServoTres=veloz;
    veloz=0;
  }
   if(veloz==1){
    if(speedServoUno>2){
    veloz=speedServoUno-2;
    speedServoUno=speedServoDos=speedServoTres=veloz;
    }
  }
}

void funcionToMyHome(int parameter){

for(int i=servoMotor.read(); i>0; i--){

  servoMotor.write(i);
  delay(30);
  
}
for(int i=servoMotorDos.read(); i>0; i--){

  servoMotorDos.write(i);
  delay(30);
  
}
for(int i=servoMotorTres.read(); i>0; i--){

  servoMotorTres.write(i);
  delay(30);
  
}
if(parameter==1)exit(0);

}



 

  
