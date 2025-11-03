#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool je_samoglasnik(char c) {
	c = tolower(c);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
string word_to_pig_latin(const string& word) {
	if (word.empty()) return "";

	if (je_samoglasnik(word[0])) {
		return word + "hay";
	}
}
	else {
		return word.substr(1) + word[0] + "ay";
	}
}

int main() {
	string rijec;
	cout << "Unesite rijec: ";
	cin >> rijec;

	string rezultat = word_to_pig_latin(rijec);
	cout << "Pig Latin: " << rezultat << endl;

	return 0;
}
