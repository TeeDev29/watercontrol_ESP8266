void allmoisture(){
  moisture1();
  moisture2();
  moisture3();
}
void moisture1(){
        if(Firebase.getInt(firebaseData,"setHam1")){
          if(firebaseData.intData()){
            getHam1 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
           
}
}

void moisture2(){ 
       if(Firebase.getInt(firebaseData,"setHam2")){
          if(firebaseData.intData()){
            getHam2 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
           
      }
}

void moisture3(){
        if(Firebase.getInt(firebaseData,"setHam3")){
          if(firebaseData.intData()){         
            getHam3 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         
      }  
}
