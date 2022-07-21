void allpoint(){
  point1();
  point2();
  point3();
  point4();
  point5();
  point6();
}

void point1(){
        if(Firebase.getInt(firebaseData,"point1")){
          if(firebaseData.intData()){
            stp1 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());          
          }
}

void point2(){
        if(Firebase.getInt(firebaseData,"point2")){
          if(firebaseData.intData()){
            stp2 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
          
}
}

void point3(){
        if(Firebase.getInt(firebaseData,"point3")){
          if(firebaseData.intData()){
            stp3 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
           
}
}

void point4(){
        if(Firebase.getInt(firebaseData,"point4")){
          if(firebaseData.intData()){
            stp4 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
           
}
}

void point5(){
        if(Firebase.getInt(firebaseData,"point5")){
          if(firebaseData.intData()){
            stp5 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
           
}
}

void point6(){
        if(Firebase.getInt(firebaseData,"point6")){
          if(firebaseData.intData()){
            stp6 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
          
}
}
