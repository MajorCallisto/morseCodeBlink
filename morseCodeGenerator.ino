//Morse Code blink sketch
//Blinks message on pin 13
//dotSpeed is in ms
int ledPin = 13;

int dotSpeed = 500;
//Dot Speed is one unit
//Space between same letters is a dot

int dashSpeed = 3*dotSpeed;
//dash is three dots long

int kernSpeed = dotSpeed;
//space between letters is 3 units

int wordSpace = 7*dotSpeed;
//space between words is 7 times one unit

String message;

struct struct_morse {char c; String code;};
struct_morse morse_bytes[] = {
  {'a',"01"},
  {'b',"1000"},
  {'c',"1010"},
  {'d',"100"},
  {'e',"0"},
  {'f',"0010"},
  {'g',"110"},
  {'h',"0000"},
  {'i',"00"},
  {'j',"0111"},
  {'k',"101"},
  {'l',"0100"},
  {'m',"11"},
  {'n',"10"},
  {'o',"111"},
  {'p',"0110"},
  {'q',"1101"},
  {'r',"010"},
  {'s',"000"},
  {'t',"1"},
  {'u',"001"},
  {'v',"0001"},
  {'w',"011"},
  {'x',"1001"},
  {'y',"1011"},
  {'z',"1100"},
  {'1',"01111"},
  {'2',"00111"},
  {'3',"00011"},
  {'4',"00001"},
  {'5',"00000"},
  {'6',"10000"},
  {'7',"11000"},
  {'8',"11100"},
  {'9',"11110"},
  {'0',"11111"},
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
void setup()
{
  pinMode(ledPin, OUTPUT);    
  
  //Serial.begin(9600);
  
  //Serial.println("Begin Morse Code transmission");

  space();
  message = "The quick brown fox jumps over the lazy dog!";

  message.toLowerCase();
  //Serial.println(message);
}

void loop()
{
  transmitMessage((char*)message.c_str());
  delay(2000);
}
void transmitMessage(char *msg){
   while (*msg){
    char currentChar = *msg;
    //Serial.println(currentChar);    
    *msg++;
    if (currentChar == ' '){
      space();
      
      continue; 
    }
    for (int i = 0; i < 54; i ++){
      if (currentChar == morse_bytes[i].c){
        for (int j = 0; j < morse_bytes[i].code.length(); j ++){
          //Serial.print(morse_bytes[i].code.charAt(j));
          if (morse_bytes[i].code.charAt(j) == '1'){
           dash();
          }else{
           dot();
          }
        }
        
        //Serial.println(""); 
        kern();
        continue;
      }
    }
  }
  /* */


}
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
