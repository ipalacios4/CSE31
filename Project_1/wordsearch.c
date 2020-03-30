#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
void upperList(char** list, int listSize);
void leftToRight(char** arr, int x, int y, char** list, int listSize);

// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

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
	//printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	//printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	printf("Printing uppercase list:\n");
	upperList(words, 50);

    return 0;
}

void printPuzzle(char** arr, int n){
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	int i = 0, j = 0;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%c ", *(*(arr+i)+j));
		}
		printf("\n");
	}
	printf("\n");

}

void upperList(char** list, int listSize){
	int i = 0, j = 0;
	for(i = 0; i<listSize; i++){
		for(j = 0; j<=strlen(*(list+i))+1; j++){
			if(*(*(list+i)+j)>='a' && *(*(list+i)+j)<='z'){
				*(*(list+i)+j) = *(*(list+i)+j)-32;
			}
		}
	}
}

void leftToRight(char** arr, int x, int y, char* answer, wordlen){
	int i = 0, j = 0;
	for(i = 1; i<wordlen; i++){

	}

}
//if already lowered just leave alone so have if statements
void makeLower(char** arr, int x, int y, int wordlen){

}

void searchPuzzle(char** arr, int n, char** list, int listSize){
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	int x = 0, y = 0, p = 0, wordlen = 0;
	char* first_Letter;
	char* last_Letter;
	
	//To get words from list and letters for puzzle utilize pointers system
	//Gets first letter of the word. Use this to search through puzzle

	printf("%c\n", *(*(arr + y)+x));
	printf("%c\n", *(*(arr + 0)+1)); //This can move throughout the puzzle

	while(n != listSize+1){
		first_Letter = *(*(list)+p);//first letter of the word we are looking for
		wordlen = *(list+p);// length of the word we are looking for 
		char* answer = (char*)malloc(wordlen*sizeof(char));//create space to put the word in to check

		//double for loop to go through individual letters in block
		for(y = 0; y<n; y++){
			for(x = 0; x<n; x++){
				//We found first letter now we need to find the other ones
				//we can use length to shorten search
				if(*(*(arr+y)+x) == *first_Letter){
					//
					answer = *(*(arr+y)+x);
					switch(){
						case "LR":
						answer = leftToRight(arr, x, y, answer, wordlen);
						if(answer == *(list+p)){
							toLower();
							break;
						}
						case "TB":
						answer = topBottom();
						if(answer == *(list+p)){
							toLower();
							break;
						}
						case "RD":
						answer = rightDiag();
						if(answer == *(list+p)){
							toLower();
							break;
						}
						case "LD":
						answer = leftDiag();
						if(answer == *(list+p)){
							toLower();
							break;
						}
					}
				}
			}
		}
		p++;
	}

}
