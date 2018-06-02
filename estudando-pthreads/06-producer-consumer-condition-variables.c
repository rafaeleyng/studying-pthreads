//
//  06-condition-variables.c
//  estudando-pthreads
//
//  Created by Rafael Eyng on 5/31/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int buffer = 0;
pthread_mutex_t m;
pthread_cond_t c;

void *produtor(void *str) {
  printf("started producing and buffer is now: %d\n", buffer);

  int i;
  for(i=0; i<100; i++) {
    pthread_mutex_lock(&m);
    buffer++;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
  }

  printf("finished producing and buffer is now: %d\n", buffer);

  return NULL;
}

void *consumidor(void *str) {
  printf("started consuming and buffer is now: %d\n", buffer);

  int i;
  for (i=0; i<100; i++) {
    pthread_mutex_lock(&m);
    while(buffer <= 0)
      pthread_cond_wait(&c, &m);
    buffer--;
    pthread_mutex_unlock(&m);
  }

  printf("finished consuming and buffer is now: %d\n", buffer);

  return NULL;
}

int main() {
  pthread_t thid1, thid2;
  pthread_mutex_init(&m, NULL);
  pthread_cond_init(&c, NULL);

  pthread_create (&thid1, NULL, produtor, NULL);
  pthread_create (&thid2, NULL, consumidor, NULL);

  pthread_join(thid1, NULL);
  pthread_join(thid2, NULL);

  return 0;
}
