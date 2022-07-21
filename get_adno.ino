void getbettery(){
    while (NodeSerial.available() > 0) {
                      
                              avgbattery1 = NodeSerial.parseInt();
                              avgbattery2 = NodeSerial.parseInt();
                              avgbattery3 = NodeSerial.parseInt();
    
                                if (NodeSerial.read() == '\n') {
                           
                              }
                              
                                bat1 = avgbattery1;
                                bat2 = avgbattery2;
                                bat3 = avgbattery3;         
                                  
                             Serial.print("bat1");Serial.print("->");Serial.println(bat1);
                             Serial.print("bat2");Serial.print("->");Serial.println(bat2);
                             Serial.print("bat3");Serial.print("->");Serial.println(bat3);
                             
                              if(bat1>0 && bat2>0 && bat3>0){
                          
                       
                               Sendbatterytobase();
                                 
                                 
                                bat1=0;
                                bat2=0;
                                bat3=0;
                               Serial.println("kuy");
                               mdt=33;
                               break;
                                }
                              
                             }
}

void getsoilmoisture(){
 while(NodeSerial.available()>0) {
           po = NodeSerial.parseInt();
           svo = NodeSerial.parseInt();
           
           if (NodeSerial.read() == '\r') {
                                          
           }
           p = po;
           sv = svo;
                              
          Serial.print("จุดที่ -> ");
          Serial.println(p); 
          Serial.println(sv); 
          soiltobase();
          break;
          }
                                      
}

void getsoilmanul(){
   while(NodeSerial.available()>0) {
    rm= NodeSerial.parseInt();
    if (NodeSerial.read() == '\r') {
                                          
           }
    rma=rm;
    soilmantobase();
    break;
   }
}
