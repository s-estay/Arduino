
class testClass
{
  public:
    testClass(uint8_t b, uint8_t c){
      value = b;
      factor = c;
    }
    uint8_t getValue(void){
      return value;
    }
    uint8_t getFactor(void){
      return factor;
    }
    uint8_t multiplication(void){
      return value*factor;
    }
    float division(void){
      float d = value;
      float e = factor;
      return d/e;
    }
  private:
    uint8_t value;
    uint8_t factor;
};

int numberDigits(int a){
    uint8_t n = a;
    uint8_t count = 0;

    while(n != 0){
        n /= 10;
        ++count;
    }

    return count;
}

void bitmask(void){
  byte mask = 1;
  
  for (mask = 00000001; mask>0; mask <<= 1){
    Serial.print(mask);
    
    switch (numberDigits(mask)){
      case 1:
        Serial.print("   ");
        break;
      case 2:
        Serial.print("  ");
        break;
      case 3:
        Serial.print(" ");
        break;
    }
    
    Serial.println(mask, BIN);
  }
}

void setup(){
  Serial.begin(9600);
  testClass test(3,4);
  Serial.print("Value is: ");
  Serial.println(test.getValue());
  Serial.print("Factor is: ");
  Serial.println(test.getFactor());
  Serial.print("Multiplication: ");
  Serial.println(test.multiplication());
  Serial.print("Division: ");
  Serial.println(test.division());

  bitmask();
}

void loop(){
  
}
