#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

void fix_spaces(string& text) {
	auto new_end = unique(text.begin(), text.end(),
		[](char a, char b) {
		return a == ' ' && b == ' ';
	});
	text.erase(new_end, text.end());

	for (size_t i = 1; i < text.size(); i++) {
		if ((text[i] == ',' || text[i] == '.') && text[i - 1] == ' ') {
			text.erase(i - 1, 1); 
			i--; 
		}
	}
	for (size_t i = 0; i < text.size(); i++) {
		if (text[i] == ',') {
			if (i + 1 < text.size() && text[i + 1] != ' ') {
				text.insert(i + 1, " "); text.insert
			}
		}
	}
}

int main() {
	string tekst;
	cout << "Unesite tekst: ";
	getline(cin, tekst);

	fix_spaces(tekst);

	cout << "Ispravljeni tekst: " << tekst << endl;

	return 0;
}
