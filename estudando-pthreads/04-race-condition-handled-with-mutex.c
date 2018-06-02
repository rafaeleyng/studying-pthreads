//
//  04-race-condition-handled-with-mutex.c
//  estudando-pthreads
//
//  Created by Rafael Eyng on 5/31/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>

int result = 0;
pthread_mutex_t m;

void * func() {
  for (int i = 0; i < 1000000; i++) {
    pthread_mutex_lock(&m);
    result += 1;
    pthread_mutex_unlock(&m);
  }

  printf("thread secundária acabou de somar\n");

  return NULL;
}

int main() {
  pthread_t thid;

  pthread_mutex_init(&m, NULL);
  pthread_create(&thid, NULL, func, NULL);

  for (int i = 0; i < 1000000; i++) {
    pthread_mutex_lock(&m);
    result += 1;
    pthread_mutex_unlock(&m);
  }
  printf("thread principal acabou de somar\n");

  pthread_join(thid, NULL);

  printf("result é %d\n", result);
}
