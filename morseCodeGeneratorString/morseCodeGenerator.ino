//Morse Code blink sketch
//Blinks message on pin 13
//dotSpeed is in ms
#define ledPin 0
#define dotSpeed 500

//Dot Speed is one unit
//Space between same letters is a dot

#define dashSpeed (3*dotSpeed)
//dash is three dots long

#define kernSpeed dotSpeed
//space between letters is 3 units

#define wordSpace (7*dotSpeed)
//space between words is 7 times one unit

String message;

struct struct_morse {char c; String code; int len;};

const struct_morse morse_alpha[] = {
  {'a',"01", 2},
  {'b',"1000", 4},
  {'c',"1010", 4},
  {'d',"100", 3},
  {'e',"0", 1},
  {'f',"0010", 4},
  {'g',"110", 3},
  {'h',"0000", 4},
  {'i',"00", 2},
  {'j',"0111", 4},
  {'k',"101", 3},
  {'l',"0100", 4},
  {'m',"11", 2},
  {'n',"10", 2},
  {'o',"111", 3},
  {'p',"0110", 4},
  {'q',"1101", 4},
  {'r',"010", 3},
  {'s',"000", 3},
  {'t',"1", 1},
  {'u',"001", 3},
  {'v',"0001", 4},
  {'w',"011", 3},
  {'x',"1001", 4},
  {'y',"1011", 4},
  {'z',"1100", 4},
  {'1',"01111"},
  {'2',"00111"},
  {'3',"00011"},
  {'4',"00001"},
  {'5',"00000"},
  {'6',"10000"},
  {'7',"11000"},
  {'8',"11100"},
  {'9',"11110"},
  {'0',"11111"}};/*,
  {'.',"010101"},
  {',',"110011"},
  {'?',"001100"},
  {'\'',"011110"},
  {'!',"101011"},
  {'/',"10010"},
  {'(',"10110"},
  {')',"101101"},
  {'&',"01000"},
  {':',"111000"},
  {';',"101010"},
  {'=',"10001"},
  {'+',"01010"},
  {'-',"100001"},
  {'_',"001101"},
  {'"',"010010"},
  {'$',"0001001"},
  {'@',"011010"}
};

*/
void setup()
{
  pinMode(ledPin, OUTPUT);
  space();
  message = "THIS IS MY MESSAGE AND ITS LONG - OH WELL DEAL WITH IT - CHRISTOPHER LEWIS";

  message.toLowerCase();
}

void loop()
{
  //testCharacter();
  transmitMessage((char*)message.c_str());
  delay(2000);
}
void testCharacter(){
  /*dash();
  dot();
  dash();
  dash();
  dash();
  */
  for (int j = 0; j < morse_alpha[1].len; j ++){
    
    if (morse_alpha[1].code.charAt(j) == '1'){
      blip();
      blip();
      blip();
      //dash();
    }else{
      dot();
    }
    /**/
  }
  
  kern();
}
void transmitMessage(char *msg){
  
   while (*msg){
    char currentChar = *msg;
    *msg++;
    if (currentChar == ' '){
      space();
      
      continue; 
    }
    for (int i = 0; i < 54; i ++){
      if (currentChar == morse_alpha[i].c){
        for (int j = 0; j < morse_alpha[i].code.length(); j ++){
          if (morse_alpha[i].code.charAt(j) == '1'){
           dash();
          }else{
           dot();
          }
        }
        kern();
        continue;
      }
    }
  }

}
 /* */
void dot(){
  digitalWrite(ledPin, HIGH);
  delay(dotSpeed);
  signalPause();
}
void dash(){
  digitalWrite(ledPin, HIGH);
  delay(dashSpeed);
  signalPause();
}
void signalPause(){
  digitalWrite(ledPin, LOW);
  delay(dotSpeed); 
}
void kern(){
  digitalWrite(ledPin, LOW);
  delay(kernSpeed);
}
void space(){
  digitalWrite(ledPin, LOW);
  delay(wordSpace);
}
void blip(){
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);               // wait for a second 
}

