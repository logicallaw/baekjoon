#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int alphabet[26]{};
	char* word = new char[1000001];
	cin >> word;
	for (int i{ 0 }; i < strlen(word); i++) {
		//소문자를 대문자로
		int toInt = static_cast<int>(word[i]);
		if (toInt >= 97) {
			alphabet[toInt - 97] += 1;
		}
		else {
			alphabet[toInt - 65] += 1;
		}

	}
	bool isMax = true;
	for (int i{ 1 }; i < 26; i++) {
		if (alphabet[i] >= max) {
			max = alphabet[i];
			indexMax = i;
		}
	}
	for (int i{ 0 }; i < 26; i++) {
		if (alphabet[i] == max && i != indexMax) {
			isMax = false;
			break;
		}
	}
	if (isMax)
		cout << static_cast<char>(indexMax + 65);
	else
		cout << "?";
	delete[] word;
	return 0;
}