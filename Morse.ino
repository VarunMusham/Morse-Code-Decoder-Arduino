#include <LiquidCrystal.h>
#include <string.h>
#include<stdlib.h>

const int rs = 0, en = 2, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String state;
char temp;
int d1,d2,d3;

char decodeMorse(String code) {
  // Morse code to English alphabet mapping
  if (code == ".-") return 'A';
  else if (code == "-...") return 'B';
  else if (code == "-.-.") return 'C';
  else if (code == "-..") return 'D';
  else if (code == ".") return 'E';
  else if (code == "..-.") return 'F';
  else if (code == "--.") return 'G';
  else if (code == "....") return 'H';
  else if (code == "..") return 'I';
  else if (code == ".---") return 'J';
  else if (code == "-.-") return 'K';
  else if (code == ".-..") return 'L';
  else if (code == "--") return 'M';
  else if (code == "-.") return 'N';
  else if (code == "---") return 'O';
  else if (code == ".--.") return 'P';
  else if (code == "--.-") return 'Q';
  else if (code == ".-.") return 'R';
  else if (code == "...") return 'S';
  else if (code == "-") return 'T';
  else if (code == "..-") return 'U';
  else if (code == "...-") return 'V';
  else if (code == ".--") return 'W';
  else if (code == "-..-") return 'X';
  else if (code == "-.--") return 'Y';
  else if (code == "--..") return 'Z';
  else if (code=="-----") return '0';
  else if (code==".----") return '1';
  else if (code=="..---") return '2';
  else if (code=="...--") return '3';
  else if (code=="....-") return '4';
  else if (code==".....") return '5';
  else if (code=="-....") return '6';
  else if (code=="--...") return '7';
  else if (code=="---..") return '8';
  else if (code=="----.") return '9';
  else return ' ';  // Space between words
}

void intToCharArray(int num, char charArray[])
{
    // Extract digits
    int d3 = num % 10;
    int d2 = (num % 100) / 10;
    int d1 = num / 100;

    // Convert digits to characters
    charArray[0] = '0' + d1;
    charArray[1] = '0' + d2;
    charArray[2] = '0' + d3;

    // Null-terminate the array
    charArray[3] = '\0';
}


void setup()
{
  lcd.begin(16, 2);
  analogWrite(A5, 135);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

unsigned long int duration;
int index=0;
String str="";
void loop()
{
  duration=pulseIn(8,LOW,2500000)/1000;
  if (duration)
  {
    if (duration<=200)
    {
    state=".";
    str+=".";
    }
    else if (duration<=500)
    {
    state="-";
    str+="-";
    }
    else
    {
      temp=decodeMorse(str);
      Serial.println(temp);
      lcd.print(temp);
      str="";
    }
    Serial.println(str);
  }
  
 }
