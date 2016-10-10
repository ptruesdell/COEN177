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
int children = 0;
int procNum = 0;

int forkTwoChildren() {
	for (int i = 0; i < 2; i++) {
		++children;
		pid = fork();

		if (pid < 0) {
			// Error handling
			cout << "Failed to fork, exiting..." << endl;
			return -1;
		}
		else if (pid == 0) {
			// Child code
			cout << "I'm a child process with ID: " << getpid() << " and PARENT: " << getppid() << " - Child num: " << children << endl;
			return children;
		}
		else {
			// Parent code 
			waitpid(-1, NULL, 0);
			// Avoids duplicate print statements from the parent
			if (i == 1) {
				cout << "I'm a PARENT with ID: " << getpid() << endl;
			}
		}
	}
}

int forkThreeChildren() {
	for (int i = 0; i < 3; i++) {
		++children;
		pid = fork();

		if (pid < 0) {
			// Error handling
			cout << "Failed to fork, exiting..." << endl;
			return -1;
		}
		else if (pid == 0) {
			// Child code
			cout << "I'm a child process with ID: " << getpid() << " and PARENT: " << getppid() << " - Child num: " << children << endl;
			return children;
		}
		else {
			// Parent code 
			waitpid(-1, NULL, 0);
			// Avoids duplicate print statements from the parent
			if (i == 2) {
				cout << "I'm a PARENT with ID: " << getpid() << endl;
			}
		}
	}
}

int main(int argc, char **argv) {
	// Fork three children from root
	//forkTwoChildren();
	
	int forkNum = forkThreeChildren();

	if (forkNum == 1) {
		forkNum = forkTwoChildren();
	}
	if (forkNum == 2) {
		forkNum = forkTwoChildren();
	}
	cout << "Total # of children: " << children << endl;
}

