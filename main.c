/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"
#include <ctype.h>

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	//Defined all varibales and arrays used
	char tempArray[MAX_INPUT_LEN];
	char fullArray[MAX_INPUT_LEN];
	char vowelArray[MAX_INPUT_LEN];
	char constantArray[MAX_INPUT_LEN];
	int endArray = 0;
	int increment = 0;
	int bool = 0;
	int bool2 = 0;
	int userOption = 0;
	

	// TODO: start by getting strings from users until # is input
	//checks if each toekn is a letter and if so makes a big string of all added values
	printf("Enter strings (# to stop):\n");
	while(bool == 0){
		fgets(tempArray,MAX_INPUT_LEN, stdin);
		for(int i = 0; i < strlen(tempArray); i++){
		if(isalpha(tempArray[i])){
			fullArray[endArray + increment] = tolower(tempArray[i]);
			increment++;
		}	
	}
	//if one of those tokens are by itself and equals # prompt user for menu option to continue looping until 
	// 4 becomes a user input 
	 if(tempArray[0] == '#' && tempArray[1] == '\n'){
		bool2 = 0;
		while(bool2 == 0){
			userOption = getMenuOption();
			if(userOption == 1){
			int vIndex = 0;
			int cIndex = 0;
		for(int i = 0; i < strlen(fullArray); i++){
			//checking if each token is a vowel if so add it to vowel array if not to constant array
			char check = fullArray[i];
			if((check == 'a')|| 
				(check =='e')|| 
				(check =='i')|| 
				(check =='o')|| 
				(check =='u')){
				vowelArray[vIndex] = fullArray[i];
				vIndex++;
			} else {
				constantArray[cIndex] = fullArray[i];
				cIndex++;
			}
		}
		//does the percentage math 
		float vPercent = ((float) strlen(vowelArray) / strlen(fullArray)) * 100;
		float cPercent = ((float) strlen(constantArray) / strlen(fullArray)) *100;
		printf("Amount of Vowels = %lu Percentage of vowels = %.2f \n", strlen(vowelArray), vPercent);
		printf("Amount of Constants = %lu Percentage of constants = %.2f \n", strlen(constantArray), cPercent);
		printf("Total letter count = %lu \n", strlen(fullArray));
		
	}else if (userOption == 2 ){
		//user option 2 creates hisotgram 
		char alphabet[ALPHABET_SIZE] = {0};
		int arrayOfFreq[MAX_INPUT_LEN];
		for(int i = 0; i < strlen(fullArray); i++){
			alphabet[fullArray[i] - 'a'] += 1;
		}
		printf("Frequency of each letter is \n");
		//copy data over to a new array
		for(int i = 0; i < 26; i++){
			arrayOfFreq[i] = (int)alphabet[i];
		}
		//get max value
		int maxFreq = 0;
		for(int i = 0; i < 26; i++){
			if(maxFreq < arrayOfFreq[i]){
				maxFreq = arrayOfFreq[i];
			}
		}
		//Printing the histogram adding astriks and white spaces
		for(int i = maxFreq; i > 0; i--){
			for(int j = 0; j < 26; j++){
				if(arrayOfFreq[j] >= i){
					printf("* ");
				}else{
					printf("  ");
				}
			}
			printf("\n");
		}
		//prints the bottom line of the hisotgram (Alphabet)
		for(int i = 0; i <26; i++){
		printf("%c ", 'a' + i);
		}
		
	}else if(userOption == 3){
		// kills one while loop to let the first one run again
		bool2 = 1;
		printf("Enter strings (# to stop):\n");

	}else if(userOption == 4){
		//kills both while loops allowing program to end
			bool = 1;
			bool2 = 1;
		}else{
			// else case in case user tries to input something other than 1 2 3 or 4
			printf("DID NOT INPUT A NUMBER BETWEEN 1 AND 4");
		}

		}
	 }
	}
	printf("Exiting...\n");
	return 0;
}
