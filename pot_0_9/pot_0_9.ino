const int bcdPin[4] = {7,6,5,4};
const int potPin = 0;
const byte seq[10][4] = {
{0,0,0,0},
{0,0,0,1},
{0,0,1,0},
{0,0,1,1},
{0,1,0,0},
{0,1,0,1},
{0,1,1,0},
{0,1,1,1},
{1,0,0,0},
{1,0,0,1},
};

void setup(){
  for(int i = 0; i < 4; i++){
    pinMode(bcdPin[i], OUTPUT);
  }
}

void loop(){
  int voltage = analogRead(potPin);
  int mapVoltage = map(voltage, 0, 1023, 0, 1000);
      
  if(mapVoltage < 100){
    display(0);
  }
  else if(mapVoltage >= 100 && voltage < 200){
    display(1);
  }
  else if(mapVoltage >= 200 && voltage < 300){
    display(2);
  }
  else if(mapVoltage >= 300 && voltage < 400){
    display(3);
  }
  else if(mapVoltage >= 400 && voltage < 500){
    display(4);
  }
  else if(mapVoltage >= 500 && voltage < 600){
    display(5);
  }
  else if(mapVoltage >= 600 && voltage < 700){
    display(6);
  }
  else if(mapVoltage >= 700 && voltage < 800){
    display(7);
  }
  else if(mapVoltage >= 800 && voltage < 900){
    display(8);
  }
  else if(mapVoltage >= 900){
    display(9);
  }
}

void display(int number){
  for(int i = 0; i < 4; i++){
    digitalWrite(bcdPin[i], seq[number][i]);
  }
}



