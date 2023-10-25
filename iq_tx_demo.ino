/*
sketch : iq_tx.ino 
Author : Peter Matthews (CurlyWurly)

INFORMATION
 - Connect Arduino to TX Module using male to female dupont wires as follows
   - Arduino 5V    to TX module +Vin
   - Arduino 0V    to TX module 0V
   - Arduino pin 3 to TX module input
 - The code structure is contained from code[0] to code[n] and is defined as:
     code[0] - No. of times to repeat the code
     code[1] - No. of pulses (Hi/low combination) - This means it is half the total number of Hi and Low states 
     code[2] - Wait unit time (Hi and Low states are constructed with multiples of this) 
     code[3] - First HIGH state multiplier - multiply with code[2]   
     code[4] - First LOW  state multiplier - multiply with code[2]   
      ....
     code[n] - last LOW   state multiplier
     N.B. The     first  pulse is made up of code[3] and code[4]
          and the second pulse is made up of code[5] and code[6]
*/

#define ldPin      13       //Onboard LED = digital pin 13
#define txPin       3       //Output to RF TX module


// TESTING - Use this for testing - it triggers the relay to pulse on and off slowly  - Notice that the 6 values at the end of the string is "1,5,1,5,1,27"      
int IQcodeT[] = {12,21,730,1,1,1,1,1,1,1,4,1,3,1,6,1,5,1,7,1,5,1,3,1,6,1,3,1,8,1,3,1,5,1,5,1,5,1,5,1,5,1,5,1,27};
// LIVE 1  - Use this to trigger the relay solid on, then go off after timeout - Notice that the 6 values at the end of the string is "1,4,1,5,1,27" instead of "1,5,1,5,1,27"    
int IQcode1[] = {12,21,730,1,1,1,1,1,1,1,4,1,3,1,6,1,5,1,7,1,5,1,3,1,6,1,3,1,8,1,3,1,5,1,5,1,5,1,5,1,4,1,5,1,27};
// LIVE 2  - Use this to trigger the relay solid on, then go off after timeout - Notice that the 6 values at the end of the string is "1,4,1,5,1,27" instead of "1,5,1,5,1,27"    
int IQcode2[]   = {12,21,730,1,1,1,1,1,1,1,4,1,4,1,4,1,6,1,6,1,5,1,6,1,5,1,4,1,6,1,3,1,5,1,5,1,5,1,5,1,4,1,5,1,27};

// Set to LIVE 1
int IQcode[] = IQcode1[]

void tx(int code);  

//************************************************************
void setup() {
//************************************************************
  pinMode(ldPin, OUTPUT);
  pinMode(txPin, OUTPUT);
  Serial.begin(57600);        // Set up Serial baud rate 
}

//************************************************************
void loop() {
//************************************************************
tx(IQcode);
delay(15000);
}

//************************************************************
void tx(int code[]){
//************************************************************
  digitalWrite(ldPin, HIGH);     // LED pin on
  for(int j=0; j<code[0]; j=j+1 ){
    for(int i=3; i<((code[1]*2)+3); i=i+1 ){
      if ( ( ( i ) % 2) == 0 ) {
        digitalWrite(txPin, LOW);
      } else {
        digitalWrite(txPin, HIGH);
      };
      for(int k=0; k<code[i]; k=k+1){
        delayMicroseconds(code[2]); 
      };
    };
  };
  digitalWrite(ldPin, LOW);    // LED pin off
}
