#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

//const string words[] = {"hello", "cat", "dog", "human" }; 

string getLowerCaseString(const string s)
{
	string res = s;
	for (int i = 0; i < s.size(); i++) res[i] = tolower(s[i]);
	return res;
}

string chooseWord(const char* FileName)
{
	string word;
	vector <string> List;
	ifstream file(FileName);
	if(file.is_open())
	{
		while(file >> word) List.push_back(word);
		if(List.size() > 0)
		{
			int randomIndex = rand() % List.size();
    		return getLowerCaseString(List[randomIndex]); 
		}
    }
}

char readAGuess()
{
    char a;
    cout<<"Please enter your next guess: ";
    cin>>a;
    cout<<"\n";
    return a;
}

bool contains(string word, char guess)
{
    for(int i=0;i<word.size();i++)
    {
        if(guess==word[i]) return 1;
    }
    return 0;
}

string update(string& guessedWord,const string& word, char guess)
{
    for(int i=0;i<word.size();i++)
    {
        if(guess==word[i]) guessedWord[i]=word[i];
    }
    return guessedWord;
}


