#include <stdio.h>
#include <stdlib.h>
//might have to include string library

int Find_in_file(char *20000words, char *text);

int main(){
    //initialising variables
    FILE *20000words;
	char text[1000], element;
	int i, rotationkey, count=0;

	20000words = fopen("20000_words.txt", "r");
	
	printf("Enter message to be decrypted: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array 'text'
	
	for(rotationkey=0; rotationkey<26; rotationkey++){
	    for (i=0; text[i]!='\0'; i++){
	        text[i] = text[i] + rotationkey;
	    }
	    
	    Find_in_file(20000words, text);
	    
	    if(count>=3){
	        break;
	    }
	    
	}
	
	printf("Decrypted message: %s", text); //prints the correctly rotated message to the screen
	
	return 0;
}


int Find_in_file(char *20000words, char *text){
    char lineoffile[];
    int results;
    
    /* loop runs through every line of the file pointed to by "*20000words" and stores the word in the array 
    "lineoffile[]" until the end of file is reached  */
    while(fgets(lineoffile, 1000, *20000words) != '\0') {
        
        //The command "fgets(lineoffile, 1000, *20000words)" is executed within the condition so it is not required here  
        
        /*If statement checks if the word on a given line of the file is present in the string "text". If condition is 
        true, the results value is incremente by 1 */
		if(strstr(text, ptrtofile) != '\0') {
			results++;
		}
	}
	
	return results;
}	
