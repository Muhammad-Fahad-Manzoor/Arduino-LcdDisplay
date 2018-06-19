
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>

//Include the Process class in your sketch. #include <Process.h>
// Bridge library feature: access to the shared storage, run and manage linux processes, open a remote console, access to the linux file system, including the sd card, enstablish http clients or server
#include <Process.h>

// setup Adafruit display
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  Serial.println("Embedded Regression tool is initiating...");

  //Initialize  display
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3c (for the 128x64)
  // init done

  // Clear the buffer.
  display.clearDisplay();

   // draw a single pixel
  display.drawPixel(10, 10, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  display.display();
  delay(2000);
  display.clearDisplay();


  // draw rectangles
  testdrawrect();
  display.display();
  delay(2000);
  display.clearDisplay();
    
}
   
// the loop function runs over and over again forever
void loop() {

//display on OLED
  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Embedded Regression tool is initiating...");
  //display.setTextColor(BLACK, WHITE); // 'inverted' text
  //display.println(3.141592);
  //display.setTextSize(2);
  //display.setTextColor(WHITE);
  //display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();
  delay(2000);
  display.clearDisplay();

  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(2,0);
  display.println("Connecting Arduino");
  display.display();
  delay(2000);
  display.clearDisplay();
  
Serial.println(" Connecting arduino ");

//Create a named Process with which you'll use to run the WiFi status script and grep.
Process p;
p.runShellCommand("ls");


// exit(0);
}

// Functions Definition outside the main loop
void testdrawrect(void) {
  for (int16_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
    display.display();
    delay(1);
  }
}
