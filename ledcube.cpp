// Creating function pointer type
typedef void (*EffectFunction)();

// Functions prototypes
void regressiveCounting();
void sequencial();
void turnOffLayersLed();


// Setting all pins to output mode
void setup(){
  for(int i=0; i<20 ;i++){
    pinMode(i,OUTPUT); 
  }
}


// Loop satement
void loop()
{
  
  EffectFunction func[5];
  func[0] = &regressiveCounting;
  func[1] = &sequencial;
  
  
  for(int i=0; i<2; i++){
  	func[i]();
    delay(1000);
  }
}


//=============EFFECT FUNCTIONS==============//

// Reressive counting
void regressiveCounting(){
  
  //5
  for(int i=3;i>0;i--){
    digitalWrite(i,HIGH);
  }
  for(int i=5;i<8;i++){
  	digitalWrite(i, HIGH);
  }
  digitalWrite(11,HIGH);
  for(int i=15;i>12;i--){
  	digitalWrite(i,HIGH);
  }
  delay(1000);
  turnOffLayersLed();
  
  //4
  for(int i=0;i<9;i+=4){
    digitalWrite(i,HIGH);
  }
  digitalWrite(9,HIGH);
  for(int i=2;i<15;i+=4){
    digitalWrite(i,HIGH);
  }
  delay(1000);
  turnOffLayersLed();
}


// sequencial
void sequencial(){ 
  for(int i=0; i<20; i++){
    digitalWrite(i, HIGH);
    delay(100);
  	digitalWrite(i, LOW);
  }
}


//=============AUXILIAR FUNCTIONS=============//

//turnoff all leds from a layer
void turnOffLayersLed(){
  for(int i=0;i<=16;i++){
    digitalWrite(i,LOW);
  }
}