// Encryption using a Polybius square

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
	char encryptedMessage[256];
	
	// Add code to encipher each letter of the message
	int messlen =  strlen(message);
	int temp1; int row; int column;
	int temp2 = 0;
	
	// printf("Start %s", encryptedMessage);
	
	for(temp1 =  0; temp1 < messlen; temp1 ++){
		for(row = 0; row < 5; row ++){
			for(column = 0; column < 5; column ++){
				if(message[temp1] == square[row][column]){
					encryptedMessage[temp2] = row + '0';
					temp2 ++;
					encryptedMessage[temp2] = column + '0';
					temp2 ++;
					// printf("A %c %c %c %s\n", message[temp1], row + '0', column + '0', encryptedMessage);
				}
				if(message[temp1] == 'j' && square[row][column] == 'i'){
					encryptedMessage[temp2] = row + '0';
					temp2 ++;
					encryptedMessage[temp2] = column + '0';
					temp2 ++;
					// printf("B %c %c %c %s\n", message[temp1], row + '0', column + '0', encryptedMessage);
				}
			}
		}
	}
	
	encryptedMessage[temp2] = '\0';
	
	printf("%s", encryptedMessage);
	
	return 0;
}