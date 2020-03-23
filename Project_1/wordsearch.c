#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
/*Arguments for Movements
	- Access to the block
	- Access to the list
	- Position of the character
*/
void leftToRight(char** arr, char** list, int x, int y); 
void topToBottom();
void rightDiag();
void leftDiag();
void checkWord(char* word, char** list, int listSize); //Needs the check word with list letter for letter
char** toLower(char** list, int x, int y);



// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));// The block of letters puzzle1.txt
	char **words = (char**)malloc(50 * sizeof(char*)); // This is gonna use states.txt

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i=0; i<50; i++){
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i=0; i<49; i++){
		*(*(words+i) + strlen(*(words+i))-2) = '\0';	
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i=0; i<50; i++){
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}

//Each direction I am checking 
void leftToRight(char** arr, char** list, int x, int y){
	
} 
void topToBottom(){

}
void rightDiag(){

}
void leftDiag(){

}

//Changes letter at current position
char** toLower(char** list, int x, int y){

}

void printPuzzle(char** arr, int n){
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	int i = 0, j = 0;
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			printf("%c ", *(*(arr+i)+j));
		}
		printf("\n");
	}
	printf("\n");

}

void searchPuzzle(char** arr, int n, char** list, int listSize){
	//arr is the scrambled block of letters
	//list is the list of words so all the answers
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here

	int x = 0, y = 0, i = 0, j = 0; //(x,y)The position on the chart. i is the number of iterations to go back if not the word
	char* word;

	While loop will tell you when to stop searching stop at the end of list
	while(i != listSize){
		word = *(list + i);// This will store word so we can check it 
		letter = *(*(list+i)+j);
		max_length = strlen(*(list+i));
	//Double for-loop should go through the block of letters
		for(x = 0; x<n; x++){
			for(y = 0; y<n; y++){
			//Now we should get a word from list and check it 

				if(*(*(arr+x)+y) == letter){
					
				}		
			}
		}

		i++;
	}
	

}

/*Things that might help
	How many directions - 4
	Right to left 
	top to bottom
	Right Diag down
	Left Diag down

	For all these directions check reverse 

*/