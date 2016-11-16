#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
  
  // Check argument cases
  if (argc < 2) {
    printf("No arguments found\n");
    return -1;
  }
  // Simulation takes a max of two arguments from stdin
  else if (argc > 3) {
    printf("Wrong number of arguments\n");
    return -1;
  }
  // Check whether second argument is a number
  else if (isalpha((long)*argv[2])) { 
     printf("Please enter a numerical argument\n");
     return -1;
  }
  else {
    int parameter = atoi(argv[1]);
    continue;
  }

  printf("Enter the reference string: ");
  return 0;

  // LRU Algorithm

}
