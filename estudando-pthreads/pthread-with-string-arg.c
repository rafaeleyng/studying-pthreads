//
//  testando.c
//  estudando-pthreads
//
//  Created by Rafael Eyng on 5/31/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#include <pthread.h>
#include <stdio.h>

void * func(void * arg){
  printf("Recebi %s\n", (char *) arg);
  return NULL;
}

int main(int argc, char **argv){
  pthread_t thread[1];
  pthread_create(&thread[0], NULL, func, "oi");
  pthread_join(thread[0], NULL);
}
