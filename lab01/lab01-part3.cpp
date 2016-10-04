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

//pid_t pid[19];
/*
void runFork(int n) {
	if (pid[n] == 0) {

	}
	else if (pid[n] > 0) {
		pid[n] = fork();
	}
	else {

	}
}
*/

pid_t pid;

int main(int argc, char **argv) {

	for (int i = 0; i < 2; i++) {
		pid = fork();
		if (pid < 0) {
			/* Error handling */
			cout << "Failed to fork, exiting..." << endl;
			return -1;
		}
		else if (pid == 0) {
			/* Child code runs here */
			cout << "Child PID: " << getpid() << endl;
			for (int j = 0; j < 2; j++) {
				pid = fork();
				if (pid < 0) {
					/* Error handling */
					cout << "Failed to fork, exiting..." << endl;
					return -1;
				}
				else if (pid == 0) {
					/* Child code runs here */
					cout << "Child PID: " << getpid() << endl;
					for (int k = 0; k < 2; k++) {
						pid = fork();
						if (pid < 0) {
							/* Error handling */
							cout << "Failed to fork, exiting..." << endl;
							return -1;
						}
						else if (pid == 0) {
							/* Child code runs here */
							cout << "Child PID: " << getpid() << endl;
							return 0;
						}
						else {
							/* Parent code runs here */
							waitpid(-1, NULL, 0);
							if (j == 1) {
								cout << "Parent PID: " << getpid() << endl;
							}
						}
					}
				}
				else {
					/* Parent code runs here */
					waitpid(-1, NULL, 0);
					if (j == 1) {
						cout << "Parent PID: " << getpid() << endl;
					}
				}
			}	
		else {
			/* Parent code runs here */
			waitpid(-1, NULL, 0);
			if (i == 1) {
				cout << "Parent PID: " << getpid() << endl;
			}
		}
	}
		}
}
}