//
//  02-pthread-with-arg.c
//  estudando-pthreads
//
//  Created by Rafael Eyng on 5/31/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#include <pthread.h>
#include <stdio.h>

void* func_str(void* arg){
  char *str = (char *) arg;
  printf("Recebi %s\n", str);
  return NULL;
}

void* func_int(void* arg){
  int num = *((int *) arg);
  printf("Recebi %d\n", num);
  return NULL;
}


int main(int argc, char **argv){
  pthread_t thread[2];

  char *str = "oi";
  pthread_create(&thread[0], NULL, func_str, str);

  int num = 2;
  pthread_create(&thread[1], NULL, func_int, &num);

  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);
}
