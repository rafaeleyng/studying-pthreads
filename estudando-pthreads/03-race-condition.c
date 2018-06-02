//
//  03-race-condition.c
//  estudando-pthreads
//
//  Created by Rafael Eyng on 5/31/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>

int result = 0;

void * func() {
  for (int i = 0; i < 1000000; i++) {
    result += 1;
  }

  printf("thread secundária acabou de somar\n");

  return NULL;
}

int main() {
  pthread_t thid;

  pthread_create(&thid, NULL, func, NULL);

  for (int i = 0; i < 1000000; i++) {
    result += 1;
  }
  printf("thread principal acabou de somar\n");

  pthread_join(thid, NULL);

  printf("result é %d\n", result);
}
