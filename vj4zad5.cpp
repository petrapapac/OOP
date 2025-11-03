#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

void print_vector(const vector<string>& words) {
	cout << "[ ";
	for (size_t i = 0; i < words.size(); i++) {
		cout << "\"" << words[i] << "\"";
		if (i != words.size() - 1)
			cout << ", ";
	}
	cout << " ]" << endl;
}
void reverse_strings(vector<string>& words) {
	for (string& w : words) {
		reverse(w.begin(), w.end()); 
}

int main() {
	
	vector<string> rijeci = { "hello", "world", "c++" };

	cout << "Prije okretanja: ";
	print_vector(rijeci);


	reverse_strings(rijeci);

	cout << "Nakon okretanja: ";
	print_vector(rijeci);

	return 0;
}
