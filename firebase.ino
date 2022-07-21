void Sendbatterytobase(){
   Firebase.setInt(firebaseData,"battery1",bat1);  //อยู่ใน Sendbatterytobase 
   Firebase.setInt(firebaseData,"battery2",bat2);
   Firebase.setInt(firebaseData,"battery3",bat3);
   Firebase.setInt(firebaseData,"mdt",33);
}


void soiltobase(){
           if(p == 0){
            Serial.println("no value");
           }else if(p == 1){
          Firebase.setInt(firebaseData,"Ham/Ham1",sv);
          }else if(p == 2){
           Firebase.setInt(firebaseData,"Ham/Ham2",sv);
           }else if(p == 3){
           Firebase.setInt(firebaseData,"Ham/Ham4",sv);
           }else if(p == 4){
           Firebase.setInt(firebaseData,"Ham/Ham5",sv);
          }else if(p == 5){
           Firebase.setInt(firebaseData,"Ham/Ham7",sv);
          }else if(p == 6){
           Firebase.setInt(firebaseData,"Ham/Ham8",sv);
            }
}

void soilmantobase(){
   Firebase.setInt(firebaseData,"con/rm",rma);
   Firebase.setInt(firebaseData,"con/rms",88);
}
