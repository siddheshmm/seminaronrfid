**RFID BASED ACCESS CONTROL SYSTEMS**

**How to?**\
  Setup your Arduino IDE\
  Setup Arduino board and RFID reader conenctions as per the pin layout.\
  Scan RFID tags by running the 'DumpInfo' code from the MFRCC522 library (File->Examples)\
  [The library is found here: https://github.com/miguelbalboa/rfid]\
  Then run the code by adding ID of your card in it.\
  Observe output in the serial monitor.\
  And test.

**Troubleshoot**\
  In case of loose connections warning on the serial monitor, try checking the pin connections. And if it persists check your breadboard.\
  In case of lack of a breadboard, use the pins directly into the RFID reader slot(preferably soldered).\
  For other unexpected errors, something that worked for me is patiently following the steps, i.e., Verify->Upload->Serial Monitor\
  Pin layout I referred off the internet to work the Arduino UNO board and RFID reader, avoid connecting the 3.3V from RFID reader to a 5V power supply on the Arduino board. As it made one of my readers stop working.

Reach me at pentosid@gmail.com for report details

A little video of how the code works: https://youtu.be/EMi4iNFbmuU
