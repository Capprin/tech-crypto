///////////////////////////////////////////////////////////////////
//																 //
//	ShiftDecrypt												 //
//																 //
//	Author: Juice												 //
//																 //
//	Description: Decryption algorithm for shift ciphers			 //
//																 //					
//	Created 6/11/17 for iD Tech Camps							 //
//																 //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


int main() {

	//Get ciphertext
	std::cout << "Enter the ciphertext (in lowercase, please): ";
	std::string text;
	getline(std::cin, text);

	//Get key
	std::cout << "Enter shift key [int]: ";
	int shift;
	std::cin >> shift;

	//Decrypt
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') continue; //Ignore whitespace

		//Handle overflow
		if (text[i] - shift < 97) {
			int diff = text[i] - 97;
			text[i] = 123 - shift + diff;;
		}
		//Otherwise just shift
		else text[i] -= shift;
	}

	//Output plaintext
	std::cout << "\nPlaintext: " << text << std::endl;

	system("pause");


	return 0;
}