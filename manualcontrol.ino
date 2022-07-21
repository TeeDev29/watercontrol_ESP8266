void control(){
                     gos();
                     backs();
                     rights();
                     lefts();
                   
                     cprums();
                     csg();
                     rmss();
                    
                     readModeStatus();
                     
                     NodeSerial.print(go);
                     NodeSerial.print("\n");
                     NodeSerial.print(back);
                     NodeSerial.print("\n");
                     NodeSerial.print(right);
                     NodeSerial.print("\n");
                     NodeSerial.print(left);
                     NodeSerial.print("\n");

                     NodeSerial.print(cprum);
                     NodeSerial.print("\n");

                     NodeSerial.print(cs);
                     NodeSerial.print("\n");

                     NodeSerial.print(rms);
                     NodeSerial.print("\n");
                     
                     NodeSerial.print(mode);
                     NodeSerial.print("\n");

                     
                    
                     Serial.print("go-> ");Serial.println(go);
                     Serial.print("back-> ");Serial.println(back);
                     Serial.print("right-> ");Serial.println(right);
                     Serial.print("left-> ");Serial.println(left);
                     Serial.print("mode-> ");Serial.println(mode);
                    
                    go=0;back=0;right=0;left=0; cs=0; cprum=0; mode=0;
                   
}
