/*
#include <iostream>
#include <string>
#include <cctype>  

int main() {
	
	std::string s;
	std::cout << "Unesi jedan redak: ";
	std::getline(std::cin, s); 
	

	
	for (char &c : s) {
		if (std::isalpha(c)) {
		c = toupper(c);

		else if (std::isdigit(c)) {
			c = '*';
		}
		else if (c == ' ' || c == '\t') {
			c = '_';
		}
		
	}

	std::cout << "Obrađeni string: " << s << std::endl;
	return 0;
}
*/
