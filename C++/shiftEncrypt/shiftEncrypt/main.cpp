///////////////////////////////////////////////////////////////////
//																 //
//	ShiftEncrypt												 //
//																 //
//	Author: Juice												 //
//																 //
//	Description: Encryption algorithm for shift ciphers			 //
//																 //					
//	Created 6/11/17 for iD Tech Camps							 //
//																 //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


int main() {

	//Get plaintext
	std::cout << "Enter text to be encrypted (in lowercase, please): ";
	std::string text;
	getline(std::cin, text);

	//Get key
	std::cout << "Enter shift key [int]: ";
	int shift;
	std::cin >> shift;

	//Encrypt
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') continue; //Ignore spaces

		//If you overflow, loop back around to beginning
		if (text[i] + shift > 122) {
			int diff = 122 - text[i];
			text[i] = 96 + shift - diff;
		}
		//Otherwise just shift the text
		else text[i] += shift;
	}

	//Print out the ciphertext
	std::cout << "\nCiphertext: " << text << std::endl;

	system("pause");

	return 0;
}