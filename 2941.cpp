#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
    string userInput;
    cin >> userInput;
    int size = userInput.length();
    int word = 0;
    for(int i{ 0 }; i < size; i++) {
        char c = userInput[i];
        if (c == 'c' && (i + 1) < size && ((userInput[i + 1] == '=') || (userInput[i + 1] == '-'))) {
            word++;
            i++;
        } else if (c == 'z' && (i + 1) < size && (userInput[i+1] == '=')) {
            word++;
            i++;
        } else if (c == 's' && (i + 1) < size && (userInput[i+1] == '=')) {
            word++;
            i++;
        } else if (c == 'n' && (i + 1) < size && (userInput[i+1] == 'j')) {
            word++;
            i++;
        } else if (c == 'l' && (i + 1) < size && (userInput[i+1] == 'j')) {
            word++;
            i++;
        } else if (c == 'd' && (i + 1) < size && (userInput[i+1] == '-')) {
            word++;
            i++;
        } else if (c == 'd' && (i + 2) < size && (userInput[i+1] == 'z') && userInput[i+2] == '=') {
            word++;
            i += 2;
        } else {
            word++;
        }
    }
    cout << word;
    return 0;
}