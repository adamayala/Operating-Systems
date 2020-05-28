//Adam Ayala
//Jan 28, 2020
//CST 334, Bruns
//This code converts binary numbers into decimal numbers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

// max length input string
#define MAXSTR 25

// convert input binary string to a number

int main() {

   // user input string
   char s[MAXSTR+3]; 

   // prompt for input if input from terminal
   if (isatty(fileno(stdin))) {
       printf("> ");
   }

   // read input string; at most MAXSTR+1 chars accepted
   // Note: this is tricky. If we accept only MAXSTR chars,
   // we can't see if user entered more chars and they are
   // being dropped by fgets.
   fgets(s, MAXSTR+3, stdin);

   // check input length; n does not include final carriage return
   int n = strlen(s)-1;  
   if (n > MAXSTR) {
     printf("input cannot be more than %d characters\n", MAXSTR);
     exit(1);
   }

   // convert s from a string in binary, to an int, and output
   
   // YOUR CODE HERE

    bool notBinary = false;
    int i;
    //verifying all elements given are either 1's or 0's
    for(i = 0; i < n; i++){
	if(s[i] != '1' && s[i] != '0'){
	    notBinary = true;
	}
    }
    if(notBinary){
	printf("it must contain only zeros and ones\n");
    }
    else if(n == 0){
	printf("0\n");
    }
    else{
	int total = 0;
	int position = 0;
	int k;
	//traversing the string and adding to total as 1's arise
	for(k = n - 1; k >= 0; k--){
	    if(s[k] == '1'){
		int addition = pow (2, position);
		total += addition;
	    }
	    position++;
	}
	printf("%d\n", total);
    }
}

