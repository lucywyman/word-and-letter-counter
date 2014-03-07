/****************************************************
  **Filename: wordCounter.cpp
  **Author: Lucy Wyman
  **Date: March 6, 2014
  **Description: Count number of words from user input, and instances of each letter.
  **Input: String/sentence
  **Output: Number of words and instances of each letter
  **************************************************/

#include<string>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

/**************************************************
  **Function: getInput()
  **Description: Read in user input as C-style string
  **Parameters: None
  **Post-conditions: User must input something on the ascii table
  ************************************************/
void getInput();

/************************************************
**Function: countLetters
**Description: Count both the spaces (words) and letters in the input.  This is done using two arrays--one to represent the number of occurences of each letter, and one that correlates to the characters.
**Parameters: C-style string (array) that is the user input.
**Pre-conditions: User must input something on the ascii table
**************************************************/
void countLetters(char *sentence);

int main(){
    getInput();
    return 0;
}

void getInput(){
    char sentence[100];
    cout<<"Please input a string less than 100 characters.  If you enter more than one hundred characters, we will only output data on the first hundred characters:  ";
    cin.getline(sentence, 100);
    countLetters(sentence);
}

void countLetters(char *sentence){
    int ascii [26] = {0};
    char alphabet [26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int wordCount = 1; //Word counter initialized at one since user has entered a word already, but without a space in front.
    for(int i = 0; sentence[i]!='\0'; i++){
	if (sentence[i] == ' ' || sentence[i]=='.' || sentence[i]=='\n')
	    wordCount+=1;
	else if (sentence[i]>='a' && sentence[i]<='z')
	    ascii[(int)(sentence[i])-97]++;
	else if (sentence[i]>='A' && sentence[i]<='Z')
	    ascii[(int)(sentence[i])-65]++;
    }
    cout<<"Word count: "<<wordCount<<endl;
    cout<<"Letter counts: "<<endl;
    for(int i = 0; i<26; i++){
	if(ascii[i]>0)
	    cout<<alphabet[i]<<": "<<ascii[i]<<endl;
    }
}


