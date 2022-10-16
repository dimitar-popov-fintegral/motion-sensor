#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

int main(){
  setbuf(stdout, NULL);
  time_t rawtime;
  struct tm * timeinfo;

  wiringPiSetup();
  char val;
  {
    pinMode(1, INPUT);
    pinMode(2, OUTPUT);
  }
  
  while(1){
    val = digitalRead(1);
    if(val == 1){
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      printf ( "detected on: %s", asctime (timeinfo) );
      digitalWrite(2, HIGH);
      delay(100);
      continue;
    }
    //printf("No Detection\n");
    digitalWrite(2, LOW);
    delay(100);
  }
}
