//
//  righi.c
//  estudando-pthreads
//
//  Created by Rafael Eyng on 5/31/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>

void * helloWorld(void *str) {
  printf("Hello world\n");
  return NULL;
}

int main() {
  pthread_t thid;

  pthread_create(&thid, NULL, helloWorld, NULL);
  printf("Criada thread %d\n", (int) thid);

  pthread_join(thid, NULL);
  printf("A thread %d já terminou\n", (int) thid);

  return 0;
}
