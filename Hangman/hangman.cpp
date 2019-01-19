#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>
#include "draw.h"
#include "utils.h"
#include "utils.cpp"
#include "draw.cpp"

using namespace std;

int main(void)
{
	srand(time(NULL));
	string hint=chooseWord("library.txt");
	string ans=string(hint.size(),'-');
	int MAX_BAD_GUESS=7;
	int bad_guess=0;
	do
	{
		renderGame(ans,bad_guess);
		char guess=readAGuess();
		if(contains(hint,guess))
		{
			ans=update(ans,hint,guess);
		}
		else
		{
			ans=update(ans,hint,guess);
			bad_guess++;
		}

		system("cls");

	}while(bad_guess<7 && ans != hint);
	displayFinalResult(bad_guess < 7, hint);
	return 0;
}
