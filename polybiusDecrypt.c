// Decryption using a Polybius square

#include <stdio.h>
#include <string.h>

// Global substitution matrix
char square[5][5]  = {{'z', 'e', 'b', 'r', 'a'}, 
	                  {'s', 'c', 'd', 'f', 'g'},
	                  {'h', 'i', 'k', 'l', 'm'},
	                  {'n', 'o', 'p', 'q', 't'},
	                  {'u', 'v', 'w', 'x', 'y'}};
	                  
	   
int main() {
	// Read the plaintext from the terminal
	// You do not need to print a message before reading the input
	char message[128];
	fgets(message, sizeof(message), stdin);
	char decryptedMessage[64];
	
	// Add code to decipher each letter of the message
	int messlen =  strlen(message);
	int temp1; int temp2 = 0;

	for(temp1 =  0; temp1 < messlen - 1; temp1 = temp1 + 2){
		decryptedMessage[temp2] = square[message[temp1] - '0'][message[temp1 + 1] - '0'];
		temp2 ++;
	}
	
	// Add a null-terminator to the string
	decryptedMessage[temp2] = '\0';
	
	printf("%s", decryptedMessage);
	
	return 0;
}