#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define X 128 // OLED display width, in pixels
#define Y 64 // OLED display height, in pixels
int de=2000;
int i=0,n=0;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(X, Y, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(500);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  for (char c='A';c<='Z';c++){
    display.setCursor(i,n);
    display.print(c);
    display.display();
    delay(100);
    i+=20;
    if(c=='G'){
      i=0;
      n=16;
    }
    if(c=='N'){
      i=0;
      n=32;
    }
    if(c=='U'){
      i=0;
      n=48;
    }
  }
  delay(1000);
  display.clearDisplay();
  display.display();
  i=n=0;
  for (char c='a';c<='z';c++){
    display.setCursor(i,n);
    display.print(c);
    display.display();
    delay(100);
    i+=20;
    if(c=='g'){
      i=0;
      n=16;
    }
    if(c=='n'){
      i=0;
      n=32;
    }
    if(c=='u'){
      i=0;
      n=48;
    }

  }

  
  display.clearDisplay();
  display.setCursor(35,0);
  display.print("Data Type");
  display.setCursor(1,12);
  display.print("4. char");
  display.setCursor(1,25);
  display.print("Ex: char A='a';");
  display.setCursor(17,40);
  display.print(" char name[]='abc';");
  display.display();
  delay(de);
  drawTable();
  display.setCursor(1,1);
  display.print("+Data Type of char");
  display.setCursor(10, (Y / 2) + 12);
  display.print("char");
  display.setCursor(X / 3 + 4, (Y / 2) +5 );
  display.print("1-");
  display.setCursor(X / 3 + 2, (Y / 2) +17 );
  display.print("byt");
  display.setCursor(X / 3 + 26, (Y / 2) +5 );
  display.print("8-");
  display.setCursor(X / 3 + 25, (Y / 2) +17 );
  display.print("bit");
  display.setCursor((X * 2) / 3 + 10, (Y / 2) + 5);
  display.print("-127");
  display.setCursor((X * 2) / 3 + 4, (Y / 2) + 17);
  display.print("to 128");
  display.display();
  delay(de);
}
void drawTable() {
  display.clearDisplay();
  // Draw vertical lines
  display.drawLine(0, 15, 0, Y, SSD1306_WHITE);
  display.drawLine(X / 3, 15, X / 3, Y, X);
  display.drawLine((X * 2) / 3, 15, (X * 2) / 3,Y,X);
  display.drawLine((X/2), (Y/2)+2, (X/2), Y,SSD1306_WHITE);
  display.drawLine(X - 1, 15, X - 1, Y, SSD1306_WHITE);
  // Draw horizontal lines
  display.drawLine(0, 15, X, 15, SSD1306_WHITE);
  display.drawLine(0, (Y / 2)+2 , X, (Y / 2) +2, SSD1306_WHITE);
  display.drawLine(0, Y - 1, X, Y - 1, SSD1306_WHITE);
  //Print headers
  display.setCursor(4, 20);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.print("Data.T");
  display.setCursor(X / 3 + 10, 20);
  display.print("SIZE");
  display.setCursor((X * 2) / 3 + 12, 20);
  display.print("L.M");
  display.display();
}
void loop(){


}