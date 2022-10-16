#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <wiringPi.h>
#include <unistd.h>

struct thread_args{
  int tid;
  time_t time;
};

void* report_distance(void* args){
  struct thread_args* payload;
  payload = (struct thread_args*) args;

  struct tm * timeinfo;
  time(&(payload->time));
  timeinfo = localtime(&(payload->time));

  printf ( "detected on: %s", asctime (timeinfo) );
  sleep(1);
  printf("exit thread\n");
  //printf("got detection alert, begin measuring distance\n");
  //todo code which measures distance
  pthread_exit(NULL);
}

int main(){
  setbuf(stdout, NULL);
  wiringPiSetup();
  char val;
  {
    pinMode(1, INPUT);
    pinMode(2, OUTPUT);
  }

  while(1){
    val = digitalRead(1);
    if(val == 1){
      pthread_t tid;
      time_t now;
      struct thread_args args;
      args.tid = tid;
      args.time = now;
      pthread_create(&tid, NULL, report_distance, &args);
      digitalWrite(2, HIGH);
      delay(100);
      printf("exit loop\n");
      continue;
    }
    //printf("No Detection\n");
    digitalWrite(2, LOW);
    delay(100);
  }

  return 0;
}
