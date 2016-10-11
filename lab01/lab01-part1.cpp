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

		// Take command line input
		std::cin >> command;

		if (command == "exit") {
			exit(0);
		}
		
		if (pid = fork() > 0) { /* Fork off child process */
			/* Parent Code */
			// Wait for child process to exit
			waitpid(-1, NULL, 0);
		} else if (pid = fork() == -1) {
			// Error encountered while trying to fork
			// Exit to avoid memory leak
			exit(-1);
		}
		else {
			// Child code runs here
			if (command == "hello") {
				execl("./helloworld", "helloworld", (char*)0);
				exit(0);
			}
			else {
				cout << "Command not recognized..." << endl;
				exit(0);
			}
		}
	}
}