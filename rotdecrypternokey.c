#include <stdio.h>
#include <stdlib.h>
//might have to include string library

int Find_in_file(char *words, char *text);

int main(){
    
    //initialising variables
    FILE *words;
    char text[1000], element;
	int i, rotationkey, count=0;

	words = fopen("20000_words.txt", "r");
	
	printf("Enter message to be decrypted: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array 'text'
	
	if(element >= 'a' && element <= 'z'){
			element = element + rotationkey - 32;
			
	for(rotationkey=0; rotationkey<26; rotationkey++){
	    
	    /* This for loop executes the rotation for every letter in the array "text" */
	    for (i=0; text[i]!='\0'; i++){
	        
	        /* Each lowercase letter is rotated by the "rotationkey" */
	        if(text[i] >= 'a' && text[i] <= 'z'){
	            text[i] = text[i] + rotationkey;
            }
            
            /* Each UPPERCASE letter of the string is turned into lowercase by subtracting 32 
            (according to the ASCII standard) and then rotated by the "rotationkey". This is done
            because every word in the text file is in lowercase. */
            if(text[i] >= 'A' && text[i] <= 'Z'){
	            text[i] = text[i] + rotationkey + 32;
            }
            
            /* If the rotation causes the element to have a value outside 'a'....'z' (according 
            to the ASCII standard), 26 is subtracted to give the rotated letter*/
            if(element > 'Z' || element < 'A'){
				element = element - 26;
		    }
	    }
	    
	    /* Returns the number of matches found by the function as an integer and assigns this value to 
	    the variable "count" */
	    count = Find_in_file(words, text);
	    
	    if(count>=3){
	        break;
	    }
	    
	}
	
	printf("Decrypted message: %s", text); //prints the correctly rotated message to the screen
	
	return 0;
}

/* This function compares every word in the file to every word in the string and returns the number of 
matches found */
int Find_in_file(char *words, char *text){
    
    char fileline[];
    int results = 0;
    
    /* Loop runs through every line of the file pointed to by "*words" and stores the word in the array 
    "lineoffile[]" until the end of file is reached */
    while(fgets(fileline, 1000, words) != '\0') {
        
        /* The command "fgets(lineoffile, 1000, *words)" is executed within the condition so it is 
        not required here */
        
        /* If statement checks if the word on a given line of the file is present in the string "text". If 
        condition is true, the results value is incremented by 1 */
		if(strstr(text, fileline) != '\0') {
			results++;
		}
	}
	
	return results;
}
