 #include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <Ticker.h>
#include <SoftwareSerial.h>

SoftwareSerial NodeSerial(D2, D3); // RX | TX
Ticker ticker;

#define FIREBASE_HOST "projt-7ca6c.firebaseio.com/" //Without http:// or https:// schemes
#define FIREBASE_AUTH "edqemfcC1HnoJF2JBN9FkJOciWU3jcyEKRijPQ5r"

FirebaseData firebaseData;
FirebaseJson json;
void printResult(FirebaseData &data);

int connectwifi = 0;
void setup() {

  pinMode(BUILTIN_LED, OUTPUT);
                                                                                  
  ticker.attach(0.6, tick);
                                                                                                                                                                    
  WiFiManager wifiManager;                                                                                                                                                        
  wifiManager.setAPCallback(configModeCallback);
                                                                    
  if (!wifiManager.autoConnect("TEE_NodeMCU")) {
    Serial.println("failed to connect and hit timeout");
                                                                               
    ESP.reset();
    delay(50000);
  }                                                            
  Serial.println("connected :)");
  connectwifi = 1;
  ticker.detach();                                                                             
  digitalWrite(BUILTIN_LED, LOW);

  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  NodeSerial.begin(19200);
  Serial.begin(115200);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  
}

void printResult(FirebaseData &data){

    if (data.dataType() == "int")
        Serial.println(data.intData());
    else if (data.dataType() == "float")
        Serial.println(data.floatData(), 5);
    else if (data.dataType() == "double")
        printf("%.9lf\n", data.doubleData());
    else if (data.dataType() == "boolean")
        Serial.println(data.boolData() == 1 ? "true" : "false");
    else if (data.dataType() == "string")
        Serial.println(data.stringData());
    else if (data.dataType() == "json")
    {
        Serial.println();
        FirebaseJson &json = data.jsonObject();
        Serial.println("Pretty printed JSON data:");
        String jsonStr;
        json.toString(jsonStr,true);
        Serial.println(jsonStr);
        Serial.println();
        Serial.println("Iterate JSON data:");
        Serial.println();
        size_t len = json.iteratorBegin();
        String key, value = "";
        int type = 0;
        for (size_t i = 0; i < len; i++)
        {
            json.iteratorGet(i, type, key, value);
            Serial.print(i);
            Serial.print(", ");
            Serial.print("Type: ");
            Serial.print(type == FirebaseJson::JSON_OBJECT ? "object" : "array");
            if (type == FirebaseJson::JSON_OBJECT)
            {
                Serial.print(", Key: ");
                Serial.print(key);
            }
            Serial.print(", Value: ");
            Serial.println(value);
        }
        json.iteratorEnd();
    }
    else if (data.dataType() == "array")
    {
        Serial.println();
        FirebaseJsonArray &arr = data.jsonArray();
        Serial.println("Pretty printed Array:");
        String arrStr;
        arr.toString(arrStr,true);
        Serial.println(arrStr);
        Serial.println();
        Serial.println("Iterate array values:");
        Serial.println();
        for (size_t i = 0; i < arr.size(); i++)
        {
            Serial.print(i);
            Serial.print(", Value: ");
            FirebaseJsonData &jsonData = data.jsonData(); 
            arr.get(jsonData, i);
            if (jsonData.typeNum == FirebaseJson::JSON_BOOL)
                Serial.println(jsonData.boolValue ? "true" : "false");
            else if (jsonData.typeNum == FirebaseJson::JSON_INT)
                Serial.println(jsonData.intValue);
            else if (jsonData.typeNum == FirebaseJson::JSON_FLOAT)
              Serial.println(jsonData.floatValue);
            else if (jsonData.typeNum == FirebaseJson::JSON_DOUBLE)
                printf("%.9lf\n", jsonData.doubleValue);
            else if (jsonData.typeNum == FirebaseJson::JSON_STRING ||
                     jsonData.typeNum == FirebaseJson::JSON_NULL ||
                     jsonData.typeNum == FirebaseJson::JSON_OBJECT ||
                     jsonData.typeNum == FirebaseJson::JSON_ARRAY)
                Serial.println(jsonData.stringValue);
        }
    }else{
      Serial.println(data.payload());
    }
}

void tick(){                                                                             
  int state = digitalRead(BUILTIN_LED);                                                
  digitalWrite(BUILTIN_LED, !state);                                                   
}

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());                                                                               
  Serial.println(myWiFiManager->getConfigPortalSSID());                                                   
  ticker.attach(0.2, tick);
}

int connecting=1; //ส่งไปไฟเบสเพื่อเช์คการเชื่อมต่อ
int getHam1,getHam2,getHam3,starthr1,startmin1,starthr2,startmin2,starthr3,startmin3; //รับมาจากไฟเบส
int stp1,stp2,stp3,stp4,stp5,stp6; //statuspoint เปิดปิดจุดที่ต้องการ
int cp ,count;                           //cp chackpoint เช็คจุด
int mode,go=0,back=0,right=0,left=0;
int po,svo,p,sv ,statusa,avgbattery1,avgbattery2,avgbattery3; //,w
int alls,bat1,bat2,bat3,qwe; //,wat;
int cprum , cs ,rms;
int rm,rma;
int modedata,mdt=33;
void loop() {

Firebase.setInt(firebaseData,"connect",connecting);

readModeStatus();

  if(connectwifi==1){
          switch (mode){
            case 0 :
                      
                      alltime();
                      allmoisture();
                      allpoint();
                      sendfor_auto();
                     
                    Serial.print(starthr1);Serial.print(":");Serial.println(startmin1);
                    Serial.print(starthr2);Serial.print(":");Serial.println(startmin2);
                    Serial.print(starthr3);Serial.print(":");Serial.println(startmin3);
                    Serial.print(getHam1);Serial.print(","); Serial.print(getHam2);Serial.print(",");Serial.println(getHam3);
                    Serial.print("sp1");Serial.print("->");Serial.println(stp1);
                    Serial.print("sp2");Serial.print("->");Serial.println(stp2);
                    Serial.print("sp3");Serial.print("->");Serial.println(stp3);
                    Serial.print("sp4");Serial.print("->");Serial.println(stp4);
                    Serial.print("sp5");Serial.print("->");Serial.println(stp5);
                    Serial.print("sp6");Serial.print("->");Serial.println(stp6);
                    Serial.print("mdt");Serial.print("-->");Serial.println(mdt);
                    Serial.print("mode");Serial.print("-->");Serial.println(mode);
                      
                      stp1 =0,stp2=0,stp3=0,stp4=0,stp5=0,stp6=0,count=0;

                      
                      switch (mdt){

                         case 22 :
                         
                         getbettery();
                         
                         break;


                         case 33 :
                         
                         getsoilmoisture();         
                         p = 0;
                         sv=0;
                         
                         break;
                        
                      }
            break;


            case 1 :

                if(count==0){
                      alltime();
                      allmoisture();
                      allpoint();
                      sendfor_auto();
                      count++;
                }
                  control();
                  if(rms==99){
                    getsoilmanul();
                  }
                                       
            break;

            
            }
        
      }
      
}

        
 
