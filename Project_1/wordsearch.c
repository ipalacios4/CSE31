#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
void upperList(char** list, int listSize);
void leftToRight(char** arr, int x, int y, char* current_word, int wordlen, char** ans, int num_ans);
void topBottom(char** arr, int x, int y, char* current_word, int wordlen, char** ans, int num_ans);
void toLower(char** arr, int x, int y);
void toUpper(char** arr, int x, int y);

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

//if already lowered just leave alone so have if statements
void toLower(char** arr, int x, int y){
	if(*(*(arr+y)+x)>='A'&& *(*(arr+y)+x)<='Z'){
		*(*(arr+y)+x) = *(*(arr+y)+x) + 32;
	}
}

void toUpper(char** arr, int x, int y){ // Carefull here if there is some overlap we may not need to upper
	if(*(*(arr+y)+x)>='a'&& *(*(arr+y)+x)<='z'){
		*(*(arr+y)+x) = *(*(arr+y)+x) - 32;
	}
		
}


void leftToRight(char** arr, int x, int y, char* current_word, int wordlen, char** answer, int num_ans){
	int i = 0, j = 0;
	printf("%s\n", "func");
	for(i = 0; i<wordlen; i++){
		printf("%c\t", *current_word);
		printf("%c\t", x);
		printf("%c\t", y);
		printf("%c\n", *(*(arr+y)+x));
		if(*(*(arr+y)+(x+1)) == *(current_word+i)){
			*(*(answer+num_ans)+i) = *(*(arr+y)+(x+1)); 
			 x++;
			 toLower(arr, x, y);
		 }
		 else{
			 for(j = i; j>=0; j--){
		 		toUpper(arr,x,y);
		 		x--;
		 	}
		 	
		 }
	}



}

void topBottom(char** arr, int x, int y, char* current_word, int wordlen, char** answer, int num_ans){
	int i = 0, j = 0;
	printf("%s\n", "TB FUNCTION");
	for(i = 0; i<wordlen; i++){
		printf("%c\t", *(*(arr+(y+1))+x));
		printf("%d\t", x);
		printf("%d\n", y+1);
		if(y+1 >= 15 || *(answer+num_ans) == current_word){
			break;
		}
		else if(*(*(arr+(y+1))+x) == *(current_word+i)){
			*(*(answer+num_ans)+i) = *(*(arr+(y+1))+x);
			y++;
			toLower(arr, x, y);
		}
		else{
			for(j = i; j>=0; j--){
				toUpper(arr, x, y);
				y--;
			}
			break;
		}
	}
}


void searchPuzzle(char** arr, int n, char** list, int listSize){
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	int x = 0, y = 0, p = 0, wordlen = 0, num_ans = 0;
	char first_Letter;
	char last_Letter;
	char* current_word = (char*)malloc(20*sizeof(char));

	//create space to put the word that show up
	char** answer = (char**)malloc(10*sizeof(char*));

	for(int i = 0; i<10; i++){
		*(answer+i) = (char*)malloc(20*sizeof(char));
	}

	upperList(list, listSize);
	strcpy(current_word, *list);

	first_Letter = *current_word;
	
	//To get words from list and letters for puzzle utilize pointers system
	//Gets first letter of the word. Use this to search through puzzle
	
	while(p!=listSize){
		strcpy(current_word,*(list+p));
		first_Letter = *(current_word);//first letter of the word we are looking for
		wordlen = strlen(*(list+p));// length of the word we are looking for 

		//double for loop to go through individual letters in block
		  for(y = 0; y<n; y++){
		  	for(x = 0; x<n; x++){
		 		//We found first letter now we need to find the other ones
		 		//we can use length to shorten search
				printf("%s\t", current_word);
		 		if(*(*(arr+y)+x) == first_Letter){
				// 	 printf("%s\t", current_word);
				// printf("%c\n", first_Letter);
					// *(*(answer+num_ans)) = first_Letter;
					// toLower(arr,x,y);
					switch(0){
						case 0://LR
					 	leftToRight(arr, x, y, current_word, wordlen, answer, num_ans);
						if(strcmp(*(answer+num_ans), current_word) == 0){
							break;
						}
						//case 1://TB
						//printf("%c\t", *(*(arr+(y))+x));
						// printf("%d\t", x);
						// printf("%d\n", y);
						// topBottom(arr, x, y, current_word, wordlen, answer, num_ans);
						// if(*(answer+num_ans) == current_word){
						// 	num_ans++;
						// 	break;
						// }
						// case "RD":
						// answer = rightDiag();
						// if(answer == *(list+p)){
						// 	toLower();
						// 	break;
						// }
						// case "LD":
						// answer = leftDiag();
						// if(answer == *(list+p)){
						// 	toLower();
						// 	break;
		 				//}
					}
					if(strcmp(*(answer+num_ans), current_word) == 0){
					break;
					} 
		 		}
				 if(strcmp(*(answer+num_ans), current_word) == 0){
					break;
					} 
		 	}
			 if(strcmp(*(answer+num_ans), current_word) == 0){
					num_ans++;
				} 
		 }
		p++;
	
	}
//This is to print out the answers from the word search

	// printf("%s\n", "Words in the wordsearch: ");
	// for(p = 0; p<listSize; p++){
	// 	printf("%s\n", *(answer+p));
	// }

}
