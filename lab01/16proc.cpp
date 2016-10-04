#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>

using namespace std;

pid_t pid;
/*int childNum == 0;

void forkChildren(int nChildren) {

  pid = fork();

  if (nChildren > 0) {
    if (pid == 0) {
      // Child code runs here
      cout << "Child PID: " << getpid() << endl; 
      exit(0);
    }
    else if (pid > 0) {
      // Parent code runs here
      cout << "Parent PID: " << getpid() << endl;
      forkChildren(nChildren - 1);
      waitpid(); /* Wait for child process to terminate */
  //  }
    //else {
      // Error handling
      //cout << "Failed to fork, exiting..." << getpid() << endl;
      //exit(1);
   // }
 // }
//}

int main(int argc, char **argv) 
{
  pid = fork();
  int childNum = 0;

  for (int i = 0; i < 16; i++) {

    if (pid == 0) {
      // Child code runs here
      cout << "Child PID " << ++childNum << ": " << getpid() << endl;
      pid = fork();
    }
    else if (pid > 0) {
      // Parent code runs here
      waitpid(-1, NULL, 0);
    }
    else {
      exit(1);
    }
  }

  return 0;
}