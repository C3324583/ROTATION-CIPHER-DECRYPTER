#include <stdio.h>
#include <string.h>

int main(){
    
    //initialising variables
    FILE *words;
    char text[1000], fileline[100];
	int i, rotationkey, count=0;

	words = fopen("20000_words.txt", "r");
	if(words=='\0'){
	    printf("error opening file");
	}
	
	printf("Enter message to be decrypted: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array 'text'
	
	
	
	for(rotationkey=1; rotationkey<27; ++rotationkey){
	   
	    //This for loop executes the rotation for all letters in the array "text" until the text[i] occupying index i is empty
	    for(i = 0; text[i] != '\0'; ++i){
		
		    //Each lowercase letter of the string is turned into UPPERCASE by subtracting 32 (according to the ASCII standard) and then rotated backwards by the "rotationkey"
     		if(text[i] >= 'A' && text[i] <= 'Z'){
	    		text[i] = text[i] + 32 + 1;
		    	//If the rotation causes the text[i] to have a value outside 'a'....'z' (according to the ASCII standard), 26 is added to give the rotated letter
    			if(text[i] > 'z' || text[i] < 'a'){
	    			text[i] = text[i] - 26;
    			}
    		}
		
	    	//Each UPPERCASE letter is rotated backwards by the "rotationkey"
		    else if(text[i] >= 'a' && text[i] <= 'z'){
			    text[i] = text[i] + 1;
			    //If the rotation causes the text[i] to have a value outside 'a'....'z' (according to the ASCII standard), 26 is added to give the rotated letter
			    if(text[i] > 'z' || text[i] < 'a'){
				    text[i] = text[i] - 26;
			    }
		    }
	    }

	    
	    while(fgets(fileline, 100, words) != '\0') {
        
            if(strstr(text, fileline) != '\0') {
			    count++;
	        }
	    }
	    
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
