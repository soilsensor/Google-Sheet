#include<WiFi.h> //ใช้ในการเชื่อมต่อ WiFi
#include <HTTPClient.h> //ใช้ในการส่งข้อมูลขึ้น HTTP

#define WiFi_SSID "ชื่อ WiFi ที่ต้องการทำการเชื่อมต่อ" 
#define WiFi_PASSWORD "รหัสของ WiFi ที่่ต้องการทำการเชื่อมต่อ"

int res; //ตัวแปรในการรีเซตบอร์ด
void setup() {
  Serial.begin(115200); //พอร์ตอนุกรมเพื่อใช้ในการแสดงข้อมูลขึ้น Serail Monitor
  WiFi.begin(WiFi_SSID,WiFi_PASSWORD); //ทำการเชื่อต่อ WiFi
}

//ฟังชั้นในการตรวจสอบ WiFi
void checkWiFi(){
while(WiFi.status() != WL_CONNECTED)//ทำการเข้าเงื่อนไขเมื่อเชื่อมต่อ WiFi ไม่ได้
  {
delay(1000);//ทำการดีเลย์ 1 วิเพื่อเชื่อมต่อ WiFi ใหม่
  Serial.print(".");//ทำการแสดง . เมื่อเข้าเงื่อนไขเชื่อมต่อ WiFi ไม่ได้
  res=res+1;//ทำการเพื่อค่าของตัวแปรเพื่อ้ในการรีเซต
  Serial.println(res);//ทำการแสดงค่าการวนลูปว่าเชื่อต่อ WiFi ไม่ได้กี่ครั้ง

  if(res>=10){//เมือเชื่อต่อ WiFi ไม่ใน 10 ครั้งหรือก็คือ 10 วิจะทำการเข้าเงื่อนไขเพื่อทำการรีเซตบอร์ด (แม้จะทำการเปิด WiFi ไว้แต่ในบางครั้งบอร์ด esp32 ก็ไม่สามารถเชื่อต่อ WiFi ได้จึงต้องทำการรีเซตบอร์ดเพื่อที่จะทำใหเบอร์ด esp32 สามารถเชื่อต่อ WiFi ได้)
    Serial.println("res");//ทำการแสดงข้อความเมื่อจะทำการรีเซตบอร์ดบน Serial Monitor
    ESP.restart(); }//ทำการรีเซ็ตบอร์ด

  Serial.println("WiFi connected");//เมื่อสามารถเชื่อมต่อ WiFi ได้จะทำการแสดงข้อความขึ้น Serial Monitor
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());//แสดงข้อมูล ip ของ WiFi ขึ้น Serial Monitor
}}

//ฟังก์ชันในการส่งข้อมูลขึ้น Google Sheet
void Google_Sheet(){
  HTTPClient http;//สร้างตัวแปรในการส่งข้อมูลไปยัง Google Sheet
        //ทำการสร้างตัวแปรในการเก็บ url ของ App script
        String url = "url ของ App Script ตามด้วย? และชื่อของมูลที่ได้ทำการสร้างไว้ ตามด้วย = และข้อมูล หากมีข้อมากกว่าหนึ่งข้อมูลให้ขั้นข้อมูลด้วย &";
        //ตัวอย่าง
        //"url?data1=1&data2=2";
        Serial.println("Making a request");//ทำการแสดงข้อความเมื่อจะทำการส่งข้อมูลไปยัง google sheet
        http.begin(url.c_str()); //ทำการส่งข้อมูลไปยัง google sheet  
        http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);//ทำการรับสเตต้สของข้อมูลที่ทำการติดตาม
        int httpCode = http.GET();//สร้างตัวแปรเก็บข้อความที่ถูกส่งกลับมา
        String payload;//สร้างตัวแปรเก็บข้อความที่ถูกส่งกลับมา
        if (httpCode > 0) { //ตรวจสอบสเตตัสการส่งข้อมูล
          payload = http.getString();//รับข้อมูลที่ได้ทำการติดตาม
          Serial.println(httpCode);//แสดงเสตัสบน Serial moniter
          Serial.println(payload);//แสดงข้อมูลที่ได้ทำการติดตามบน Serial moniter
        }
        else {//เงื่อนไขเมื่อไม่สามารถส่งข้อมูลไปยัง Google Sheet ได้
          Serial.println("Error on HTTP request");//แสดงข้อความบน Serial moniter เมื่อไม่สามารถส่วข้อมูลไปยัง Google Sheet ได้
        }
        http.end();//สิ้นสุดการใช้งานการส่งข้อมูลขึ้น Google Sheet (ควรจะสิ้นสุดการใช้งานทุกครั้งเมื่อการส่งเสร็จสิ้นเพื่อที่จะสามารถส่งข้อมูลไปยัง Google Sheet ได้ในครั้งถัดไป)
}

void loop() {
  checkWiFi();//ใช้ฟังชั่นในการตรวจสอบ WiFi
  Google_Sheet();//ใช้ฟังชั่นในการส่งข้อมูลไปยัง Google Sheet
  delay(1000);
}
