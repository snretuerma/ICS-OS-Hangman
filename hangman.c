#include "../../sdk/dexsdk.h"

#define MaxMistakes 5

// function prototypes
void DrawScenes(int i);
void DrawScene0();
void DrawScene1();
void DrawScene2();
void DrawScene3();
void DrawScene4();
void DrawScene5();
void DrawScene6();

main(){
	int mistakes = 0, wordIndex, i, guesses, wordCount, wordLength, cleared, wins=0, loses=0, flag, inputStatus, trigger;
	char word[20], characterGuesses[20] = "", input, guessWord[20];
	const char *gameWords[] = {"MISTAKES", "ANDROID", "OPERATING", "SYSTEMS", "PASSION", "ELECTRIC", "MAGNET", "CUSTOM", "COLD", "RAIN"}; 
	wordCount = (sizeof(gameWords)/sizeof(const char *));
	clrscr();													// clear console contents
	for(wordIndex = 0; wordIndex < wordCount; wordIndex++){		// depending on string array given, repeat the game until all words have been tried
		strcpy(word,gameWords[wordIndex]);
		wordLength = strlen(word);
		mistakes = 0;
		guesses = 0;
		cleared = 0;
		trigger = 0;
		for(i = 0; i < wordLength; i++){						// make a string of '?' to represent word to be guessed
			guessWord[i] = '?';
		}
		while(1){
			if(mistakes>MaxMistakes || cleared == wordLength){	// stopping conditions for the loop
				if(mistakes>MaxMistakes){
					trigger = 1;								// if the trigger is mistake, set the trigger variable to 1
				}
				break;
			}

			flag = 0;
			inputStatus = 0;
			printf("Game %d\n", wordIndex+1);					
			DrawScenes(mistakes);								// call draw scene function to draw the figure for the hangman depending on mistake value
			printf("Guesses: %s Mistakes: %d Cleared: %d Word Lenght: %d\n", characterGuesses, mistakes, cleared, wordLength );
			printf("%s\n", guessWord);							// show the current value of the word to be guessed
			printf("Guess: ");
			input = toupper(fgetc(stdin));						// get input and convert it to uppercase letters
			fgetc(stdin); 										// chomp input to remove trailing whitespace
			clrscr();											// clear the screen
			for(i = 0; i < wordLength; i++){					// check if the input has already been used
				if(characterGuesses[i] == input){
					printf("\nInput already used! \ninput: %c Guesses: %c\n\n", input, characterGuesses[i]);
					flag = 1;
					break;
				}
			}
			
			if(flag == 0){										// if the input is still available, check for the result in the current word to be guessed
				characterGuesses[strlen(characterGuesses)] = input;
				for(i = 0; i < wordLength; i++){
					if(input == word[i]){						// check if input is in the word
						inputStatus = 1;
						break;
					}
				}

				if(inputStatus == 1){							// if it is in the word, replace all '?' in the guess string shown to the user and increment cleared variable for each character instance that matched
					for(i = 0; i < wordLength; i++){
						if(input == word[i]){
							guessWord[i] = input;
							cleared++;
						}
					}
				}
				else{											// increment the mistakes variable if word is not present
					mistakes++;
				}
			}
			
		}// end of while
		if(trigger == 1){										// print status at the end of each game depending on trigger
			clrscr();
			printf("Game %d\n", wordIndex+1);
			DrawScenes(mistakes);
			printf("Guesses: %s Mistakes: %d Cleared: %d Word Lenght: %d\n", characterGuesses, mistakes, cleared, wordLength );
			printf("%s\n", guessWord);
			printf("\nGame %d Failed!\n", wordIndex+1);
			loses++;
		}
		else{
			clrscr();
			printf("Game %d\n", wordIndex+1);
			DrawScenes(mistakes);
			printf("Guesses: %s Mistakes: %d Cleared: %d Word Lenght: %d\n", characterGuesses, mistakes, cleared, wordLength );
			printf("%s\n", guessWord);
			printf("\nGame %d Cleared!\n", wordIndex+1);
			wins++;
		}
		strncpy(characterGuesses, "", sizeof(characterGuesses));// clear the guesses string		
		strncpy(guessWord, "", sizeof(guessWord));				// clear the guess word shown
	
	}// end of for

	printf("\nFinal Score: %d\n", wins);						// at the end of the games, show final score

}// end of program


// Draws scenes by calling function depending on the mistakes
void DrawScenes(int i){
	switch(i){
		case 0:
			DrawScene0();
		break;
		
		case 1:
			DrawScene1();
		break;

		case 2:
			DrawScene2();
		break;

		case 3:
			DrawScene3();
		break;

		case 4:
			DrawScene4();
		break;

		case 5:
			DrawScene5();
		break;

		case 6:
			DrawScene6();
		break;
	}
}


void DrawScene0(){
	textcolor(9);
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	
	printf("|");//starter
	textcolor(6);
	printf("    ||============");
	textcolor(14);
	printf("|"); //rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    || //         ");
	textcolor(14);
	printf("|");// rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||//");
	textcolor(9);
	printf("                                                         |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(15);
	printf("____");					// ground
	textcolor(6);
	printf("||");
	textcolor(15);
	printf("___________________");	// ground
	textcolor(9);
	printf("                                        |\n");//closer
	
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
}


void DrawScene1(){
	textcolor(9);
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	
	printf("|");//starter
	textcolor(6);
	printf("    ||============");
	textcolor(14);
	printf("|"); //rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    || //         ");
	textcolor(14);
	printf("|");// rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||//");
	textcolor(10);
	printf("          0");
	textcolor(9);
	printf("                                              |\n");//closer

	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(15);
	printf("____");					// ground
	textcolor(6);
	printf("||");
	textcolor(15);
	printf("___________________");	// ground
	textcolor(9);
	printf("                                        |\n");//closer
	
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
}

void DrawScene2(){
	textcolor(9);
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	
	printf("|");//starter
	textcolor(6);
	printf("    ||============");
	textcolor(14);
	printf("|"); //rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    || //         ");
	textcolor(14);
	printf("|");// rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||//");
	textcolor(10);
	printf("          0");
	textcolor(9);
	printf("                                              |\n");//closer

	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(10);
	printf("            |");
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(15);
	printf("____");					// ground
	textcolor(6);
	printf("||");
	textcolor(15);
	printf("___________________");	// ground
	textcolor(9);
	printf("                                        |\n");//closer
	
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
}


void DrawScene3(){
	textcolor(9);
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	
	printf("|");//starter
	textcolor(6);
	printf("    ||============");
	textcolor(14);
	printf("|"); //rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    || //         ");
	textcolor(14);
	printf("|");// rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||//");
	textcolor(10);
	printf("          0");
	textcolor(9);
	printf("                                              |\n");//closer

	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(10);
	printf("           /");
	printf("|");
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(15);
	printf("____");					// ground
	textcolor(6);
	printf("||");
	textcolor(15);
	printf("___________________");	// ground
	textcolor(9);
	printf("                                        |\n");//closer
	
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
}

void DrawScene4(){
	textcolor(9);
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	
	printf("|");//starter
	textcolor(6);
	printf("    ||============");
	textcolor(14);
	printf("|"); //rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    || //         ");
	textcolor(14);
	printf("|");// rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||//");
	textcolor(10);
	printf("          0");
	textcolor(9);
	printf("                                              |\n");//closer

	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(10);
	printf("           /");
	printf("|");
	printf("\\");
	textcolor(9);
	printf("                                             |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(15);
	printf("____");					// ground
	textcolor(6);
	printf("||");
	textcolor(15);
	printf("___________________");	// ground
	textcolor(9);
	printf("                                        |\n");//closer
	
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
}

void DrawScene5(){
	textcolor(9);
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	
	printf("|");//starter
	textcolor(6);
	printf("    ||============");
	textcolor(14);
	printf("|"); //rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    || //         ");
	textcolor(14);
	printf("|");// rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||//");
	textcolor(10);
	printf("          0");
	textcolor(9);
	printf("                                              |\n");//closer

	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(10);
	printf("           /");
	printf("|");
	printf("\\");
	textcolor(9);
	printf("                                             |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(10);
	printf("           /");
	textcolor(9);
	printf("                                               |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(15);
	printf("____");					// ground
	textcolor(6);
	printf("||");
	textcolor(15);
	printf("___________________");	// ground
	textcolor(9);
	printf("                                        |\n");//closer
	
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
}

void DrawScene6(){
	textcolor(9);
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	
	printf("|");//starter
	textcolor(6);
	printf("    ||============");
	textcolor(14);
	printf("|"); //rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    || //         ");
	textcolor(14);
	printf("|");// rope color yellow
	textcolor(9);
	printf("                                              |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||//");
	textcolor(10);
	printf("          0");
	textcolor(9);
	printf("                                              |\n");//closer

	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(10);
	printf("           /");
	printf("|");
	printf("\\");
	textcolor(9);
	printf("                                             |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(10);
	printf("           /");
	printf(" \\");
	textcolor(9);
	printf("                                             |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(6);
	printf("    ||");
	textcolor(9);
	printf("                                                           |\n");//closer
	
	printf("|");//starter
	textcolor(15);
	printf("____");					// ground
	textcolor(6);
	printf("||");
	textcolor(15);
	printf("___________________");	// ground
	textcolor(9);
	printf("                                        |\n");//closer
	
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
}