#include <iostream>
using namespace std;

string chooseWord(const char* FileName);
char readAGuess();
bool contains(string word, char guess);
string update(string& guessedWord,const string& word, char guess);
string getLowerCaseString(const string s);

