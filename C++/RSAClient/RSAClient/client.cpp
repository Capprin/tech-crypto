///////////////////////////////////////////////////////////////////
//																 //
//	RSAClient													 //
//																 //
//	Author: Juice												 //
//																 //
//	Description: An implementation of RSA on the client side	 //
//																 //					
//	Created 6/11/17 for iD Tech Camps							 //
//																 //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>


int main() {
	int n, k;

	std::cout << "----------" << std::endl;
	std::cout << "Encryption" << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << std::endl;

	//Get public keys
	std::ifstream in_file("public.txt");
	if (!in_file.is_open()) {
		std::cout << "Could not open 'public.txt', make sure you generate keys first!" << std::endl;
		system("pause");
		return -1;
	}

	in_file >> n;
	in_file >> k;
	in_file.close();


	//Get plaintext
	std::cout << "Enter plaintext to encrypt: ";
	std::string plain_text;
	getline(std::cin, plain_text);


	//Set up outfile
	std::ofstream out_file("internet.txt");

	//Do encryption and write to file
	for (char p : plain_text) {
		p -= 96; //Adjust so numbers aren't astronomically large
		char c = ((long)pow(p, k)) % n; //Actual encryption! (p^k)%n

		out_file << c;
	}

	out_file.close();

	system("pause");

	return 0;
}