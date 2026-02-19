# Google-Sheet
  การใช้บอร์ดไมโครคอนโทรลเลอร์ส่งข้อมูลไปยัง Google Sheet

<br/>
  
## <a name="content"></a> สารบัญ
  1.[ไลบรารี่ที่ใช้งาน](#library)
  
  2.[app](#Sp)
  
  3.[การใช้งาน App Script เพื่อส่งข้อมูลไปยัง Google Sheet](#google)
  
  4.[ลิงก์ของ Google Sheet และ App Script](#Link1)


<br/>

## <a name="library"></a> ไลบรารี่ที่ใช้งาน
  1.WiFi ใช้ในการเชื่อมต่อกับ WiFi เพื่อส่งข้อมูลไปยัง Google sheet
  2.HTTPClient ใช้ในการส่งข้อมูลไปยัง Google Sheet


<br/>

## <a name="Sp"></a> app
    1.ทำการเปิด Google Dive แล้วสร้าง Google Sheet
    2.ทำการเปิด Google Dive แล้วสร้าง App Script
    3.ทำการเขียนโค้ดใน App Script เพื่อใช้ในการส่งข้อมูลไปยัง Google Sheet ซึ่งมีวิธีการเขียนโค้ดตามไฟล์ 
    4.ทำการเล์อกที่ การทำให้ใช้งานได้ -> จัดการให้ใช้งานได้ ->


<br/>

## <a name="google"></a> การใช้งาน App Script เพื่อส่งข้อมูลไปยัง Google Sheet
    วิธีการเขียนโค้ดเพื่อส่งข้อมูลไปยัง Google Sheet
    1.ฟังชั้น doGet โดยใช้ function doGet(){} โดยในวงเล็บสามารถสร้างตัวแปรอะไรก็ได้เพื่อใช้ในการเขียนฟังชั้น ในนี้จะใช้เป็น e (ซึ่งจำเป็นต้องเรียกใช้ doGet หากใช้ฟังชั่นอื่นจะไม่สามารถส่งขึ้น Google Sheet
    2.ฟังชั่น var เป็นการสร้างตัวแปรเหมื่อนกับ int หรือ float ในภาษา C
    3.ฟังชั่น  .parameter. เป็นฟังชั่นในการรับข้อมูล วิธีการใช้นำตัวแปรที่สร้างไว้ใน doGet ตามด้วย .parameter. ตามด้วยชื่อของข้อมูลที่ถูกส่งกลับมา (e.parameter.data)
    4.ฟังชั่น new Dete() เป็นฟังชั่นในการดึงเวลามาใช้
    5.ฟังชั่น .getHours()  เป็นฟังชั่นในการดึงค่าชั่วโมงมาจากตัวแปรที่ดึงค่าเวลา ( date.getHours() )
    6.ฟังชั้น .getMinutes() เป็นฟังชั่นในการดึงค่านาทีมาจากตัวแปรที่ดึงค่าเวลา ( date.getMinutes() )
    7.ฟังชั้น .getSeconds() เป็นฟังชั่นในการดึงค่าวินาทีมาจากตัวแปรที่ดึงค่าเวลา ( date.getSeconds() )
    8.ฟังชั้น SpreadsheetApp.openByUrl()  เป็นฟังชั่นในการเลือก Google Sheet ที่ต้องการส่ง ( SpreadsheetApp.openByUrl(url ของ Google Sheet) )
    9.ฟังชั้น .getSheetByName() เป็นฟังชั่นในการเลือกชีตของ Google Sheet ที่ต้องการส่งด้วยใช้กับตัวแปรที่ใช้ฟังชั่นในการเลือก Google Sheet ( ss.getSheetByName("ชีต1") )
    10.ฟังชั้น .appendRow() เป็นฟังชั่นในการเรียงลำดับข้อมูลที่การส่งโดยใช้กับตัวแปรที่ใช้ฟังชั่นในการเลือกชีต (  ws.appendRow([data1,data2])
    
    ตัวอย่างโค้ด
    function doGet(e) {
          var data1 = e.parameter.sensor1;
          var data2 = e.parameter.sensor2;
          var date = new Date();
          var hours = date.getHours();
          var minutes = date.getMinutes();
          var seconds = date.getSeconds(); 
          var time = hours + ":" + minutes + ":" + seconds;
          var urls="url ของ Google Sheet";
          var ss=SpreadsheetApp.openByUrl(urls);
          var ws=ss.getSheetByName("ชีต1");
          ws.appendRow([time,data1,data2]);
    }
    function myFunction() {
      
    }


<br/>
   
## <a name="Link1"></a> ลิงก์ของ Google Sheet และ App Script
ลิงก์ Google Sheet : [ไปที่เว็บไซต์](https://docs.google.com/spreadsheets/d/1WmaNBVfGaR6_M2FEWlNePuxF7KyquoJBrCNNLKxdUzM/edit?gid=0#gid=0)

ลิงก์ App Script ของ Soil Sensor : [ไปที่เว็บไซต์](https://script.google.com/d/1Mdd5yoEIhzhPuhuZc5btQAsZM5MPQrRmxWRQVlMX3e0VDdiDSvA5cKQQ/edit?usp=drive_link)

ลิงก์ App Script ของ อุณหภูมิและควสมชื้นในอากาศ : [ไปที่เว็บไซต์](https://script.google.com/d/1Zrlc-ooEr6B-3yoyaWD6enGBAqd9MEnwu9rqNukZTTX2xZq-4uJAKik3/edit?usp=drive_link)

ลิงก์ App Script ของ เปอเซ็นแบตเตอร์รี่ : [ไปที่เว็บไซต์](https://script.google.com/d/1LMfAsO0ANZI3b9LDrvzPKpmksBPqMbsgNu1F_Pq4gQ-BhTwBVdiDTrZ1/edit?usp=drive_link)


<br/>
