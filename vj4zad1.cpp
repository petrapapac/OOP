#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unosite brojeve (0 na kraju): ";
	while (true) {
		cin >> broj;
		if (broj == 0)  
			break;
		v.push_back(broj); 
	}
}
void print_vector(const vector<int>& v) {
	cout << "Sadrzaj vektora: ";
	for (int x : v) { 
		cout << x << " ";
	}
	cout << endl;
} 
int main() {
	vector<int> brojevi;  
	input_vector(brojevi);  
	print_vector(brojevi);  
	return 0;
}
