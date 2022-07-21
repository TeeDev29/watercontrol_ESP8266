void gos(){
        if(Firebase.getInt(firebaseData,"/con/g")){
          if(firebaseData.intData()){
            go = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
         
}

void backs(){
        if(Firebase.getInt(firebaseData,"/con/b")){
          if(firebaseData.intData()){
            back = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
}

void rights(){
        if(Firebase.getInt(firebaseData,"/con/r")){
          if(firebaseData.intData()){
            right = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }  
}

void lefts(){
        if(Firebase.getInt(firebaseData,"/con/l")){
          if(firebaseData.intData()){
            left = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
}



void cprums(){
        if(Firebase.getInt(firebaseData,"/con/cp")){
          if(firebaseData.intData()){
            cprum = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
}

void csg(){
        if(Firebase.getInt(firebaseData,"/con/cs")){
          if(firebaseData.intData()){
            cs = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
}


void rmss(){
        if(Firebase.getInt(firebaseData,"/con/rms")){
          if(firebaseData.intData()){
            rms = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
}
