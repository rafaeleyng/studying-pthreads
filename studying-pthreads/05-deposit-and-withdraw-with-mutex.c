//
//  05-deposit-and-withdraw-with-mutex.c
//  estudando-pthreads
//
//  Created by Rafael Eyng on 5/31/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 10000

int saldo = 100;
pthread_mutex_t m;

void * deposita( void *str ) {
  int i;
  for(i=0; i<N; i++) {
    pthread_mutex_lock(&m);
    saldo += 1;
    pthread_mutex_unlock(&m);
  }

  return NULL;
}

void * retira( void *str ) {
  int i;
  for (i=0; i<N; i++) {
    pthread_mutex_lock(&m);
    saldo -= 1;
    pthread_mutex_unlock(&m);
  }

  return NULL;
}

int main() {
  pthread_t thid1, thid2;
  pthread_mutex_init(&m, NULL);

  if (
      ( pthread_create (&thid1, NULL, deposita, NULL) != 0) ||
      ( pthread_create (&thid2, NULL, retira, NULL) != 0)
  ) {
    printf("Error\n");
    exit(0);
  }

  pthread_join(thid1, NULL);
  pthread_join(thid2, NULL);
  printf("SALDO ATUAL = %d\n", saldo);
  return 0;
}
