//
//  09-void-pointer.c
//  studying-pthreads
//
//  Created by Rafael Eyng on 6/3/18.
//  Copyright © 2018 Rafael Eyng. All rights reserved.
//

#import <stdlib.h>
#import <stdio.h>

int main(void) {
  int a[3] = {1,2,3};
  int *b = malloc(3 * sizeof(int));
  b[0] = 1;
  b[1] = 2;
  b[2] = 3;
  void *pointer1 = (int *)a;
  void *pointer2 = b;
  int *c = (int *)pointer1;
  int *d = (int *)pointer2;

  printf("%d\n", a[1]);
  printf("%d\n", b[1]);
  printf("%d\n", c[1]);
  printf("%d\n", d[1]);

  return 0;
}
