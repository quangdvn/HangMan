#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;

const static string FIGURE[] = 
{
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
};

const string& YouWin()
{
    const static string figure[] = 
	{
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
	};
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
   	return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}  
  
const string& YouLose() 
{
    const static string figure[] = 
	{
    "   ------------+    \n"
    "   |    /           \n"
    "   |    O      	 \n"
    "   |   /|\\    	 \n"
    "   |   / \\   		 \n"
    "   |        		 \n"
    " -----      		 \n" ,
    "   ------------+    \n"
    "   |     |          \n"
    "   |     O          \n"
    "   |    /|\\        \n"
    "   |    / \\        \n"
    "   |        		 \n"
    " -----      		 \n" ,
    "   ------------+    \n"
    "   |      \\        \n"
    "   |      O         \n"
    "   |     /|\\       \n"
    "   |     / \\       \n"
    "   |      			 \n"
    " -----   			 \n" ,
    "   ------------+    \n"
    "   |     |          \n"
    "   |     O          \n"
    "   |    /|\\        \n"
    "   |    / \\        \n"
    "   |        		 \n"
    " -----      		 \n"
    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

void renderGame(string guessedWord, int badGuessCount)
{
	cout<<FIGURE[badGuessCount]<<endl;
    cout<<"Current guess = "<<guessedWord<<endl;
    cout<<"You have made "<<badGuessCount<<" bad guess(es)\n";
    if(badGuessCount == 6)
	{	   	
		cout<<"				====================================="			<<endl;
		cout<<"				|				    |"			<<endl;
		cout<<"				|				    |"			<<endl;
		cout<<"				| WARNING !! ITS YOUR LAST CHANCE !!|"			<<endl;
		cout<<"				|				    |"			<<endl;
		cout<<"				|				    |"			<<endl;
		cout<<"				====================================="			<<endl;
	} 
}

void displayFinalResult(bool won, const string& word) 
{
    while (true) 
	{
		system("cls");
		
        if (won) cout << "Congratulations! You win!" << endl;
        else cout << "You lost. The correct word is " << word << endl;
        
        if (won) cout << YouWin()<< endl;
        else cout << YouLose()<< endl;
        this_thread::sleep_for(chrono::milliseconds(200));
		
	}
}
