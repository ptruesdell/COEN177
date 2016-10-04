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

// The basic programming task - A simple shell
/*int main(int argc, char *argv[]) {
	pid_t pid = 0;

	if (pid = fork() == -1) {
		cout << "Error creating child process, exiting..." << endl;
	}
	else if (pid = fork() == 0) {
		
	}
}*/

int main(int argc, char **argv)
{
    printf("--beginning of program\n");

    int counter = 0;
    pid_t pids[16];

    for (int i = 0; i < 16; ++i) {
    	if (pids[i] = fork() == 0) {
        // child process
        	for (int n = 0; n < 5; ++n) {
            	printf("child process: counter=%d\n", ++counter);
        	}
    	}
    	else if (pids[i] = fork() > 0) {
        	// parent process
        	for (int m = 0; m < 5; ++m) {
            	printf("parent process: counter=%d\n", ++counter);
        	}
    	}
    	else {
        	// fork failed
        	printf("fork() failed!\n");
        	return 1;
    	}
    }

    printf("--end of program--\n");

    return 0;
}