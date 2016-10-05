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
int childCount = 0;

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
							for (int l = 0; l < 3; l++) {
								pid = fork();
								if (pid < 0) {
									/* Error handling */
									cout << "Failed to fork, exiting..." << endl;
									return -1;
								}
								else if (pid == 0) {
									/* Child code runs here */
									cout << "Child PID: " << getpid() << endl;
									while (childCount < 2) {
										if (childCount == 0) {
											// Generate 3 children for the first node on the 3rd level of the tree
											childCount++;
											for (int m = 0; m < 3; m++) {
												pid = fork();

												if (pid < 0) {
													/* Error handling */
													cout << "Failed to fork, exiting" << endl;
													return -1;
												}
												else if (pid == 0) {
													// Child code runs here
													cout << "Child PID: " << getpid() << endl;
													return 0;
												}
												else {
													// Parent code runs here
													waitpid( -1, NULL, 0);
													if (m == 2) {
														cout << "Parent PID: " << getpid() << endl;
													}
												}
											}
										}
										else if (childCount == 1) {
											// Generate 2 children for the second node on the 3rd level
											childCount++;
											for (int n = 0; n < 2; n++) {
												pid = fork();

												if (pid < 0) {
													// Error handling
													cout << "Failed to fork, exiting..." << endl;
													return -1;
												}
												else if (pid == 0) {
													// Child code runs here
													cout << "Child PID: " << getpid() << endl;
													return 0;
												}
												else {
													// Parent code runs here
													waitpid(-1, NULL, 0);
													if (n == 1) {
														cout << "Parent PID: " << getpid() << endl;
													}
												}
											}
										}
										else {
											return 0;
										}

								}
								return 0;
							}
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
			return 0;
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