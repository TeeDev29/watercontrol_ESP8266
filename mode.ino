
void readModeStatus(){
  
    if(Firebase.getInt(firebaseData,"mode")){
          if(firebaseData.intData()){
            mode = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
    

        if(Firebase.getInt(firebaseData,"mdt")){
          if(firebaseData.intData()){
            mdt = firebaseData.intData();
            }
          }
         else{
          connectwifi=0;
           Serial.println(firebaseData.errorReason());
         }
}
