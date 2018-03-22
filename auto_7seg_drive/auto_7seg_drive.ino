int bcdPin[4] = {7,6,5,4};
byte seq[10][4] = {
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

void setup() {
  for(int i = 0; i < 4; i++){
  pinMode(bcdPin[i], OUTPUT);
  }
}

void loop(){
  for(int i = 0; i < 10; i++){
    display(i);
    delay(500);
  }
}

void display(int number){
  for(int i = 0; i < 4; i++){
    digitalWrite(bcdPin[i], seq[number][i]);
  }
}
