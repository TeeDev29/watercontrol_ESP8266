void alltime(){
  time1();
  time2();
  time3();
}

void time1(){
  
       if(Firebase.getInt(firebaseData,"/Timer1/Start/hr")){
        if(firebaseData.intData()){
          starthr1 = firebaseData.intData();
          
          }
        }
       else{
        connectwifi=0;
         Serial.println(firebaseData.errorReason());
         
}
        if(Firebase.getInt(firebaseData,"/Timer1/Start/min")){
          if(firebaseData.intData()){
            startmin1 = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
          
      }
}

void time2(){
           if(Firebase.getInt(firebaseData,"/Timer2/Start/hr")){
            if(firebaseData.intData()){
              starthr2 = firebaseData.intData();
              }
            }
           else{
            connectwifi=0;
             Serial.println(firebaseData.errorReason());
             
        }
            if(Firebase.getInt(firebaseData,"/Timer2/Start/min")){
              if(firebaseData.intData()){
                startmin2 = firebaseData.intData();
                }
              }
             else{
              connectwifi=0;
               Serial.println(firebaseData.errorReason());
               
          }
}

void time3(){
               if(Firebase.getInt(firebaseData,"/Timer3/Start/hr")){
                if(firebaseData.intData()){
                  starthr3 = firebaseData.intData();
                  }
                }
               else{
                connectwifi=0;
                 Serial.println(firebaseData.errorReason());
                 
            }
                if(Firebase.getInt(firebaseData,"/Timer3/Start/min")){
                  if(firebaseData.intData()){
                    startmin3 = firebaseData.intData();
                    }
                  }
                 else{
                  connectwifi=0;
                   Serial.println(firebaseData.errorReason());
                   
              }
}
