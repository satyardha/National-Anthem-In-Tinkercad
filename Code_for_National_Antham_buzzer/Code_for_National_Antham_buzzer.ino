#include <LiquidCrystal.h>
int speakerPin = 12;//buzzer is connected to Pin 12 of the Board.
int LED=10;//Led is connected to Pin 10 of the arduino board
int length = 164; // the number of notes
char notes[] = "cdeeeeeeeeeeedef eeedddbdc cgggggfgggfag fffeefdfe eeeeedgggff  eeeddddbdc  cdeeeedef  efgggfedfe  eeddddbdc  gggggfgggfag fffeefdfe cbc bab aga cc dd ee de f _________ "; // a space represents a rest
int beats[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  };//Duration of each note
int tempo = 250; //Change song speed here
LiquidCrystal lcd(2,3,4,5,6,7);
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
  delay(3000);
  lcd.clear();
  pinMode(speakerPin, OUTPUT);
  pinMode(LED,OUTPUT);
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
