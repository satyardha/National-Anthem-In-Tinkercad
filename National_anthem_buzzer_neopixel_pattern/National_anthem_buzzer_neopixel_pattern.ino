#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#define PIN        2 //orange
#define PIN1        9  //orange
#define PIN2        3  //white
#define PIN3        7  //white
#define PIN4        4  //green
#define PIN5        10  //green
#define PIN6        5 //blue
#define PIN7        6 //Brown
#define PIN8        8 //multi


#define NUMPIXELS  6
#define NUMPIXELS1  20


Adafruit_NeoPixel pixels1(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(NUMPIXELS, PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels6(7, PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels7(NUMPIXELS1, PIN7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels8(52,PIN8, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int speakerPin = 12;//buzzer is connected to Pin 12 of the Board.
int LED=10;//Led is connected to Pin 10 of the arduino board
int length = 164; // the number of notes
char notes[] = "cdeeeeeeeeeeedef eeedddbdc cgggggfgggfag fffeefdfe eeeeedgggff  eeeddddbdc  cdeeeedef  efgggfedfe  eeddddbdc  gggggfgggfag fffeefdfe cbc bab aga cc dd ee de f _________ "; // a space represents a rest
int beats[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  };//Duration of each note
int tempo = 250; //Change song speed here
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
String message = "Janaganamana Adhinayaka Jaya he Bharata bhagya vidhata Punjab Sindhu Gujarata Maraata Dravida Utkala Banga Vindhya Himachala Yamuna Ganga Uchchala jaladhi taranga Tava Shubha Name Jage,Tava Shubha Ashish Maage,Gahe Tava Jayagatha!Janagana mangaladayaka Jaya he Bharatabhagyavidhata!Jaya He,Jaya He,Jaya He,Jaya Jaya Jaya Jaya He............ ";
int ii = 0;
int strLength;
String toShow;
void playTone(int tone, int duration) {  //creating a square wave for the given duration
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {
    digitalWrite(speakerPin, HIGH);
    digitalWrite(LED, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    digitalWrite(LED,LOW);
    delayMicroseconds(tone);
     
  }
}

void playNote(char note, int duration) { //Assigning high time for the notes
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 956, 851, 758, 716, 638, 568, 1014, 478 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup()
{
  strLength = message.length();
  lcd.begin(16, 2);
  lcd.print("PLEASE STAND FOR");
  lcd.setCursor(0,1);
  lcd.print("NATIONAL ANTHEM  ");
  delay(1000);
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("FLAG HOISTING");
  lcd.setCursor(0,1);
  lcd.print("START");
 
  
  pinMode(speakerPin, OUTPUT);
  pinMode(LED,OUTPUT);
  for(int i=0; i<NUMPIXELS+1; i++) 
  { pixels1.begin();
    pixels1.setPixelColor(i, pixels1.Color(255, 140, 0));//orange
    pixels1.show();
   pixels.begin();
    pixels.setPixelColor(i, pixels.Color(255, 140, 0));//orange
    pixels.show();
   pixels2.begin();
    pixels2.setPixelColor(i, pixels2.Color(255, 255, 255));//white
    pixels2.show(); 
   pixels3.begin();
    pixels3.setPixelColor(i, pixels3.Color(255, 255, 255));//white
    pixels3.show();
   pixels4.begin();
    pixels4.setPixelColor(i, pixels4.Color(0, 150, 0));//green
    pixels4.show();
   pixels5.begin();
    pixels5.setPixelColor(i, pixels5.Color(0, 150, 0));//green
    pixels5.show();
   pixels6.begin();
    pixels6.setPixelColor(i, pixels6.Color(0, 0, 255));//blue
    pixels6.show(); 
    
  }
  for(int i=0; i<NUMPIXELS1; i++) 
  { pixels7.begin();
    pixels7.setPixelColor(i, pixels7.Color(120,0,255));//brown
    pixels7.show();
  }
  
  lcd.clear();
  //lcd.begin(16, 2);
  
  
}

void loop() {  //Main function
  for (int i = 0; i < length; i++) 
  { 
    lcd.home();//For the length of the tune array
    if (notes[i] == ' ') {  //take space as rest
      delay(beats[i] * tempo); // rest
    } 
    else {
      playNote(notes[i], beats[i] * tempo); //play the corresponding note for the corresponding beat
    }
     toShow = message.substring(ii,ii+16);
  lcd.print(toShow);
  ii = ii + 2;
  if(ii>(strLength-16))
  {
    ii = 0;
  }

  delay(100);
  }
    // pause between notes
    delay(tempo / 2);
 
}
