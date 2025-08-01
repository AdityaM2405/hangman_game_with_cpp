#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class HangMan {
public:
    //Declaring attributes for the word, the guessed part of the word, the number of lives(one for each part of the hangman), and the wrong letters that have already been guessed so far
    string Word;
    string GuessedWord;
    int Lives = 6;
    vector<char> GuessedLetters;

    //Function to display different phases of the game, from full hangman to game over
    void DisplayMan(){
        switch(Lives){
            case 6:
                cout << "______" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "    -----" << endl;
                cout << "   /     \\ " << endl;
                cout << "   \\     /" << endl;
                cout << "    -----" << endl;
                cout << "  ____|____" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "     / \\" << endl;
                cout << "    /   \\" << endl;
                cout << "   /     \\" << endl;
                break;
            case 5:
                cout << "______" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "    -----" << endl;
                cout << "   /     \\ " << endl;
                cout << "   \\     /" << endl;
                cout << "    -----" << endl;
                cout << "  ____|____" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "     / " << endl;
                cout << "    /   " << endl;
                cout << "   /     " << endl;
                break;
            case 4:
                cout << "______" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "    -----" << endl;
                cout << "   /     \\ " << endl;
                cout << "   \\     /" << endl;
                cout << "    -----" << endl;
                cout << "  ____|____" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                break;
            case 3:
                cout << "______" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "    -----" << endl;
                cout << "   /     \\ " << endl;
                cout << "   \\     /" << endl;
                cout << "    -----" << endl;
                cout << "      |____" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                break;
            case 2:
                cout << "______" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "    -----" << endl;
                cout << "   /     \\ " << endl;
                cout << "   \\     /" << endl;
                cout << "    -----" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                break;
            case 1:
                cout << "______" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "    -----" << endl;
                cout << "   /     \\ " << endl;
                cout << "   \\     /" << endl;
                cout << "    -----" << endl;
                break;
           case 0:
                cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀" << endl;
                cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼" << endl;
                cout << "██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀" << endl;
                cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼" << endl;
                cout << "███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼" << endl;
                cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
                cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼" << endl;
                cout << "██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
                cout << "███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼████▄┼┼┼▄▄▄▄▄▄▄┼┼┼▄████┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼▀▀█▄█████████▄█▀▀┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼█████████████┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼██▀▀▀███▀▀▀██┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼██┼┼┼███┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼█████▀▄▀█████┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼┼███████████┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼▄▄▄██┼┼█▀█▀█┼┼██▄▄▄┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼▀▀██┼┼┼┼┼┼┼┼┼┼┼██▀▀┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼" << endl;
                cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
                break;
        }
    }

    void SetWord(){
        int linenumber = 0;
        string word;
        //This ensures that the rand() function generates a new number with each function call
        srand(time(0));
        //Selects a random number between one and 1371
        int random = rand() % 1371;
        //Reads a text file of 1371 common 7-letter words
        ifstream WordFile("insert_filepath_here");
        //Iterates through each line in the file(one word per line), while also incrementing the value of linenumber
        //If the linenumber value matches the random number, the line, i.e., word, in that iteration is selected
        while(getline(WordFile, word)){
            ++linenumber;

            if(linenumber == random){
                Word = word;
            }

        }
        //The GuessedWord string initially starts out as a bunch of blanks
        int len = Word.length();
        char blank = '_';
        GuessedWord = string(len, blank);
    }

    //Function to ask the player for a letter and check if it is in the word or not
    void AskForLetter(){
        char letter;
        cout << "Guess a letter: " << endl;
        cin >> letter;
        
        //If your guess is right, the position(s) of that letter in the word will be revealed
        if(Word.find(letter) != std::string::npos){
            cout << "Good job!" << endl;
            cout << "Word Progress: ";
            //The following loop will iterate through the word and display the guessed letters along with the blanks
            for(int i = 0; i <= Word.length(); i++){
                if(Word[i] == letter){
                    cout << letter;
                    GuessedWord[i] = letter;
                }
                else{
                    cout << GuessedWord[i];
                }
            }
            cout << "" << endl;
            int size = GuessedLetters.size();
            cout << "Guessed Letters: ";
            //The following loop will display all the wrong letters the player has guessed so far
            for(int i = 0; i < size; i++){
                if(i == size - 1){
                    cout << GuessedLetters[i];
                }
                else{
                    cout << GuessedLetters[i] << ",";
                }
            }
            cout << "" << endl;
        }
        //If your guess is wrong, you lose a life
        else{
            cout << "Try again!" << endl;
            GuessedLetters.push_back(letter);
            Lives -= 1;
            cout << "Word Progress: " << GuessedWord << endl;
            cout << "" << endl;
            int size = GuessedLetters.size();
            cout << "Guessed Letters: ";
            for(int i = 0; i < size; i++){
                if(i == size - 1){
                    cout << GuessedLetters[i];
                }
                else{
                    cout << GuessedLetters[i] << ",";
                }
            }
            cout << "" << endl;
        }
    }

    //Function to run the hangman game indefinitely
    void Run(){
        SetWord();
        //This do-while loop will keep taking letters as input and showing the status of the hangman until the player runs out of lives
        do{
            AskForLetter();
            DisplayMan();
            //If the player guesses the entire word before they run out of lives
            if(GuessedWord == Word){

               cout << "░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░" << endl;
               cout << "░░███████░░░░░░░░░░███▒▒▒▒▒▒▒▒███░░░░░░░" << endl;
               cout << "░░█▒▒▒▒▒▒█░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███░░░░" << endl;
               cout << "░░█▒▒▒▒▒▒█░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░░" << endl;
               cout << "░░░░█▒▒▒▒▒█░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒▒███░" << endl;
               cout << "░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██" << endl;
               cout << "░░░█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██" << endl;
               cout << "░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██" << endl;
               cout << "░██▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██" << endl;
               cout << "██▒▒▒███████████▒▒▒▒▒██▒▒▒▒▒▒▒▒██▒▒▒▒▒██" << endl;
               cout << "█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██" << endl;
               cout << "██▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░" << endl;
               cout << "░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░░" << endl;
               cout << "░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░" << endl;
               cout << "░░████████████░░░█████████████████░░░░░░" << endl;

                cout << "░█░█░█▀█░█░█░░░█░█░▀█▀░█▀█░█" << endl;
                cout << "░░█░░█░█░█░█░░░█▄█░░█░░█░█░▀" << endl;
                cout << "░░▀░░▀▀▀░▀▀▀░░░▀░▀░▀▀▀░▀░▀░▀" << endl;
                cout << "" << endl;
                cout << "The word was: " << Word << endl;
                break;
            }
        }while(Lives != 0);
        if(Lives == 0){
            cout << "The word was: " << Word << endl;
        }
    }

    
};


int main(){
   
    //Creating an object for the HangMan class and call the Run() function
    HangMan hangman;
    hangman.Run();

    return 0;
}
