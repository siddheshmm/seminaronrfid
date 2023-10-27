//Scan your RFID tags using the 'DumpInfo' code from MFRC522 RFID library
//Following code is for an rduino UNO board and uses a MFRC522 RFID tag and reader

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>


#define SS_PIN 10
#define RST_PIN 9

#define SERVO_PIN 3
Servo myservo;

#define ACCESS_DELAY 1000
#define DENIED_DELAY 1000
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  myservo.attach(SERVO_PIN);
  myservo.write( 70 );
  delay(7500);
  myservo.write( 0 );
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag: ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase();
  if (content.substring(1) == "83 E7 FE F6") //UID of the card to which access is allowed goes here
  {
    Serial.println("AUTHORIZED ACCESS GRANTED.");
    Serial.println();
    myservo.write( 70 );
    delay(ACCESS_DELAY);
  myservo.write( 0 );
  }

 else   {
    Serial.println("ACCESS DENIED");
    Serial.println();
    delay(DENIED_DELAY);
  }
}
