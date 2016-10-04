#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// The basic programming task - A simple shell
int main(int argc, char *argv[]) {

	string command;

	// Main loop
	while (true) {

		pid_t pid = 0;

		// Print prompt
		cout << "$> ";
		std::cin >> command;

		if (command == "exit") {
			exit(0);
		}
		
		else if (pid = fork() != 0) { /* Fork off child process */
			/* Parent Code */
			waitpid(-1, NULL, 0); /* Wait for child to exit */
		} else {
			execl("/home/ptruesdell/a.out", (char*) NULL);
			// Exit to avoid memory leak
			exit(1);
		}
	}
}

