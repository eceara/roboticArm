#include <Servo.h>




const int pot1=A5;  // Potlar tanımlanıyor.
const int pot2=A4;
const int pot3=A3;
const int pot4=A2;


Servo servo1,servo2,servo3,servo4; // Servolar tanımlanıyor.


int potDurum1,potDurum2,potDurum3,potDurum4 = 0;  // Potun alabileceği değerler tanımlanıyor.
int pos = 0; // Servoların alabileceği pozisyonlar tanımlanıyor.

void setup() {

servo1.attach(5);  // Servo pinleri tanımlanıyor.
servo2.attach(6);
servo3.attach(9);
servo4.attach(10);

pinMode(pot1,INPUT); // Potların giriş portu oldukları tanımlanıyor.
pinMode(pot2,INPUT);
pinMode(pot3,INPUT);
pinMode(pot4,INPUT);



}

void loop() { // Ana fonksiyon.

ServoKontrol1();
ServoKontrol2();
ServoKontrol3();
ServoKontrol4();


}





void ServoKontrol1 () {                  // Yan yana olan 2 servodan biri. 90 Derece açı ile Aşağı/Yukarı hareketi için.

  potDurum1=analogRead(pot1);
  pos=map(potDurum1,0,1023,0,90);

  servo1.write(pos);


}

void ServoKontrol2 (){                  // Yan yana olan 2 servodan diğeri. 90 Derece açı ile Aşağı/Yukarı hareketi için.

potDurum2=analogRead(pot2);
pos=map(potDurum2,0,1023,0,90);

servo2.write(pos);
  
}

void ServoKontrol3 (){                  // Sağ/Sol hareketi için gerekli 180 derece dönmesi beklenen servo.

potDurum3=analogRead(pot3);
pos=map(potDurum3,0,1023,0,180);

servo3.write(pos);
  
}

void ServoKontrol4 (){                    // Tut/Bırak hareketi için gerekli. Derecesi baskı alındığında denenecek.

potDurum4=analogRead(pot4);
pos=map(potDurum4,0,1023,0,90);

servo4.write(pos);
  
}


