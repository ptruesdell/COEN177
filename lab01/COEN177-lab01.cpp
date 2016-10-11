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

int main() {

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
		
		else if (pid == fork() != 0 && child_num <= 16) { /* Fork off child process */
			/* Parent Code */
			waitpid(-1, &status, 0);
		} else {
			int status;
			//execl(command, parameters, 0); /* Execute command */
			// Exit to avoid memory leak
			exit(0);
		}
	}
}

void parseCommand(command) {
	
	if (command == "exit") {
		exit(0);
	}
	if (command == "") {
		
	}
}