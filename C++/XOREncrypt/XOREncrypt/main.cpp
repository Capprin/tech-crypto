///////////////////////////////////////////////////////////////////
//																 //
//	XOREncrypt													 //
//																 //
//	Author: Juice												 //
//																 //
//	Description: An implementation of XOR encryption			 //
//																 //					
//	Created 6/11/17 for iD Tech Camps							 //
//																 //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>

int main() {

	//Choosing between writing (encryption) or reading (decryption)
	std::cout << "File read or write [r/w]? ";
	char in;
	std::cin >> in;

	std::string tmp;
	getline(std::cin, tmp);

	std::cout << std::endl;

	//Get input text
	std::string in_text;
	if (in == 'w') {
		std::cout << "Enter plaintext to encrypt: ";
		getline(std::cin, in_text);
	}
	else{
		//Open file, quit if error
		std::ifstream inFile("encryptedText.txt");
		if (!inFile.is_open()) {
			std::cout << "Failed to open encryptedText.txt. Make sure it exists!" << std::endl;
			system("pause");
			return -1;
		}

		//Get all contents of file for in_text
		while (!inFile.eof()) {
			in_text += inFile.get();
		}

		inFile.close();
	}

	//Get key
	std::cout << "Enter key: ";
	std::string key;
	getline(std::cin, key);

	//Modify key if it's longer or shorter than in_text
	if (key.length() > in_text.length()) key = key.substr(0, in_text.length());
	else if (key.length() < in_text.length()) {
		while (key.length() < in_text.length()) {
			key += '-';
		}
	}

	//Create output text
	std::string out_text(in_text.length(), ' ');

	//Do actual encryption/decryption (bitwise XOR)
	for (int i = 0; i < in_text.length(); i++) {
		out_text[i] = in_text[i] ^ key[i];
	}

	//Output to file or to stdout
	if (in == 'w') {
		std::cout << "\nCiphertext:" << std::endl;
		std::cout << out_text << std::endl;
		std::ofstream outFile("encryptedText.txt");
		
		outFile << out_text;
		outFile.close();
	}
	else {
		std::cout << "Plaintext:\n" << out_text.substr(0,out_text.length()-1) << std::endl;
	}



	system("pause");

	return 0;
}