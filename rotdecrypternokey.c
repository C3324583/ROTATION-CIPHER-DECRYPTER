#include <stdio.h>
#include <stdlib.h>
void Find_in_file(*10000words);
int main(){
    //initialising variables
    FILE *
	char text[126], element;
	int i, rotationkey;
	
	printf("Enter message to be decrypted: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array 'text'
	for(rotationkey=0; rotationkey<26; rotationkey++){
	    for (i=0; text[i]!='\0'; i++){
	        text[i] = text[i] + rotationkey;
	    }
	    if (the words are found in a library){
	        break;
	    }
	    
	}
	
	printf("Decrypted message: %s", text); //prints the correctly rotated message to the screen
	
	return 0;
}


void Find_in_file(*10000words){

    while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			printf("A match found on line: %d\n", line_num);
			printf("\n%s\n", temp);
			find_result++;
		}
		line_num++;
	}
}	