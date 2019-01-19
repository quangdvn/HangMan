#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>
#include<fstream>
using namespace std;

void renderGame(string guessedWord, int badGuessCount);
void displayFinalResult(bool won, const string& word);
