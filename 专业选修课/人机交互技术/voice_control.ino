#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET     4

const int NUM_SLIDERS = 3;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2};
int analogSliderValues[NUM_SLIDERS];

Adafruit_SSD1306 display(128, 64, &Wire,OLED_RESET);
void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }

  Serial.begin(9600);
  OLED_init(); 
}

void loop() {
  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)
  delay(10);
  OLED_refresh();
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}

void OLED_refresh() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(25, 5);
  display.println("-Ao Volume-");
  display.setCursor(0, 20);
  display.println("master:");
  display.setCursor(0, 30);
  display.println("chat:");
  display.setCursor(0, 40);
  display.println("game:");
  display.setTextSize(1); 
  display.setCursor(40, 20);
  display.println((int)(analogSliderValues[0] / 10.23));
  display.setCursor(30, 30);
  display.println((int)(analogSliderValues[1] / 10.23));
  display.setCursor(30, 40);
  display.println((int)(analogSliderValues[2] / 10.23));
  display.display();
}

void OLED_init(){
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setTextSize(1);  
  display.setCursor(17, 5);
  display.println("-Ao Volume-");
  display.setCursor(0, 20);
  display.println("master:");
  display.setCursor(0, 30);
  display.println("chat:");
  display.setCursor(0, 40);
  display.println("game:");

  display.display();
}