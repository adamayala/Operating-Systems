#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

/*
 * A very simple shell that supports only commands 'exit', 'help', and 'today'.
 */

#define MAX_BUF 160
#define MAX_TOKS 100

int main() {
	int ch;
	char *pos;
	char s[MAX_BUF+2];   // 2 extra for the newline and ending '\0'
	static const char prompt[] = "msh> ";
	char *toks[MAX_TOKS];
	char subString[] = "";
	time_t now;
	time(&now);
	bool isFirst = true;

	// 
	// YOUR CODE HERE   (add declarations as needed)
	//

	while (1) {
		// prompt for input if input from terminal
		int i, position = 0;
		isFirst = true;
                memset(subString, 0, strlen(subString));
		if (isatty(fileno(stdin))) {
			printf(prompt);
		}

		// read input
		char *status = fgets(s, MAX_BUF+2, stdin);
		for(i = 0; i < strlen(status) - 1; i++){
                	if(status[i] == ' '){
				if(strcmp(subString, "exit") == 0 && i == 4){
					return 0;
				}
				else if(strcmp(subString, "help") == 0 && i == 4){
					printf("enter 'help', 'today', or 'exit' to quit\n");
					memset(subString, 0, strlen(subString));
					break;
				}
				else if(strcmp(subString, "today") == 0 && i == 5){
					printf("%s", asctime(localtime(&now)));
					memset(subString, 0, strlen(subString));
					break;
				}
				else{
                        		printf("token: '%s'\n", subString);
                               		isFirst = false;
				 	position = 0;
                                	memset(subString, 0, strlen(subString));
				}
                        }
                        else{
                        	subString[position] = status[i];
                                position++;
                        }
                }
		if(strcmp(subString, "exit") == 0 && isFirst){
			return 0;
		}
		else if(strcmp(subString, "help") == 0 && isFirst){
			printf("enter 'help', 'today', or 'exit' to quit\n");
		}
		else if(strcmp(subString, "today") == 0 && isFirst){
			printf("%s", asctime(localtime(&now)));
		}
		else if(strlen(subString) != 0){
			printf("token: '%s'\n", subString);
		}

		// exit if ^d entered
		if (status == NULL) {
			printf("\n");
			break;
		}

		// input is too long if last character is not newline 
		if ((pos = strchr(s, '\n')) == NULL) {
			printf("error: input too long\n");
			// clear the input buffer
			while ((ch = getchar()) != '\n' && ch != EOF) ;
			continue; 
		}

		// remove trailing newline
		*pos = '\0';

		//
		// YOUR CODE HERE
		//
		
	}
	exit(EXIT_SUCCESS);
}
