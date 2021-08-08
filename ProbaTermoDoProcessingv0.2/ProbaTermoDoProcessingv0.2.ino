#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
char val;

void setup() {
    Serial.begin(115200);
    pinMode(4, INPUT_PULLUP);
    bool status;
    
    // default settings
    status = amg.begin();
    /*if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    
    Serial.println("-- Pixels Test --");

    Serial.println();*/

    delay(100); // let sensor boot up
    while(Serial.availableForWrite()==0){}
    delay(5000);
}


void loop() { 
    //delay(100);
    //while(Serial.available()==0){}
    //val=Serial.read();
    while(Serial.read()!='n'){}
    if (digitalRead(4)==LOW){
    amg.readPixels(pixels);

    /*for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.println(pixels[i-1]);
    }*/
    /*for(int i=0; i<AMG88xx_PIXEL_ARRAY_SIZE;i++){
        
        Serial.println(pixels[i]);
      
    }*/
    String wynik="";
    for(int i=0; i<AMG88xx_PIXEL_ARRAY_SIZE;i++){
        
        wynik+=(String)pixels[i] + ',';
      
    }
    Serial.println(wynik);
    }
}
