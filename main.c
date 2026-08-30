/*
 Program Name: Ferry System
 Author: Maya Soparkar
 Date: 3/21/2025
 Time Spent: 4 hrs
 Purpose: Create a program that will identify how many
        times the ferry has to cross the river to serve all waiting cars.
 */
#include <stdio.h>
#include <stdlib.h>
#include "ferry_loading.h"

int main(int argc, char* argv[]) {
 int c; //number of test cases
 scanf("%d\n", &c);

 //loop over each test
 while (c--) {
  int l, m;
  scanf("%d %d", &l, &m);
  //convert meters to centimeters
  l *= 100;

  //make queues for both sides
  Queue leftQueue = {NULL, NULL};
  Queue rightQueue = {NULL, NULL};

 //read incoming cars
  int i;
  for ( i = 0; i < m; i++) {
   int length;
   char side[6];
   scanf("%d %s", &length, side);

   //Add the car to the corresponding queue based on its side
   if (side[0] == 'l') {
    enQueue(&leftQueue, length);
   } else {
    enQueue(&rightQueue, length);
   }
  }

  int crossings = 0;
  int ferryPosition = 0; //0 = left bank, 1 = right bank

  while (!isEmpty(&leftQueue) || !isEmpty(&rightQueue)) {
   int load = 0;

   //load cars from the current side
   if (ferryPosition == 0) {
    while (!isEmpty(&leftQueue) && load + leftQueue.front->length <= l) {
     load += deQueue(&leftQueue);
    }
   } else {
    while (!isEmpty(&rightQueue) && load + rightQueue.front->length <= l) {
     load += deQueue(&rightQueue);
    }
   }
   //cross to other side
   ferryPosition = 1 - ferryPosition;
   crossings++;
  }

  printf("%d\n", crossings);
 }
 return 0;

}
