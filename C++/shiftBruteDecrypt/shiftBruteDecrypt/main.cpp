///////////////////////////////////////////////////////////////////
//																 //
//	ShiftBruteDecrypt											 //
//																 //
//	Author: Juice												 //
//																 //
//	Description: A brute-force decryption of shift ciphers		 //
//																 //					
//	Created 6/11/17 for iD Tech Camps							 //
//																 //
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>


int main() {

	//Get ciphertext
	std::cout << "Enter the ciphertext: ";
	std::string cipher_text;
	getline(std::cin, cipher_text);

	//Note: Don't need a key!

	//For every possible key:
	for (int shift = 1; shift < 26; shift++) {

		//Try decryption
		std::string text = cipher_text;
		for (int i = 0; i < text.length(); i++) {
			if (text[i] == ' ') continue;

			if (text[i] - shift < 97) {
				int diff = text[i] - 97;
				text[i] = 123 - shift + diff;;
			}
			else text[i] -= shift;
		}

		//Output this version so the user can review (and see if it is human-readable)
		std::cout << "\nShift of " << shift << ": " << std::endl;
		std::cout << text << std::endl;
	}

	system("pause");

	return 0;
}