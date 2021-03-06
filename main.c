#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){

  if(signo == SIGINT){
    printf("\nSIGINT\n");
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("PID:%d\n",getpid());
  }

}


int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("PID is : %d\n", getpid());
    sleep(1);
  }

}
