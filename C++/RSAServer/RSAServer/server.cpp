///////////////////////////////////////////////////////////////////
//																 //
//	RSAServer													 //
//																 //
//	Author: Juice												 //
//																 //
//	Description: An implementation of RSA on the server side	 //
//																 //					
//	Created 6/11/17 for iD Tech Camps							 //
//																 //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <math.h>


int main() {
	int n, k, j;

	std::cout << "Generate keys? [y/n]: ";
	char in;
	std::cin >> in;
	std::cout << std::endl;

	if (in == 'y') {
		//Generate public and private keys
		std::cout << "----------------------------------" << std::endl;
		std::cout << "Generating public and private keys" << std::endl;
		std::cout << "----------------------------------" << std::endl;

		std::cout << "\nEnter a prime number: ";
		int p1;
		std::cin >> p1;

		std::cout << "Enter another prime number: ";
		int p2;
		std::cin >> p2;

		n = p1 * p2; //First part of public key
		int z = (p1 - 1)*(p2 - 1);

		k; //Will become second part of public key

		//Get k (must be prime, cannot divide evenly into z)
		bool exit = false;
		while (!exit) {
			std::cout << "\nEnter a prime number less than " << z << ": ";
			std::cin >> k;

			if (z % k != 0) exit = true;
			else std::cout << "Prime can't divide evenly into " << z << "!" << std::endl;
		}


		std::cout << "\nGenerating private key..." << std::endl;

		j = 1; //Will become private key

		bool generated = false;
		while (!generated) {
			if ((k * j) % z == 1) generated = true;
			else j++;
		}

		//All keys are now generated


		//Write keys to file
		std::ofstream out_file("public.txt");
		out_file << n << std::endl << k;
		out_file.close();

		out_file.open("private.txt");
		out_file << j;
		out_file.close();
	}
	else {
		//Get public key;
		std::ifstream in_file("public.txt");
		if (!in_file.is_open()) {
			std::cout << "Could not open 'public.txt', make sure you generate keys first!" << std::endl;
			system("pause");
			return -1;
		}

		in_file >> n;
		in_file >> k;
		in_file.close();
		

		//Get private key;
		in_file.open("private.txt");
		if (!in_file.is_open()) {
			std::cout << "Could not open 'private.txt', make sure you generate keys first!" << std::endl;
			system("pause");
			return -1;
		}

		in_file >> j;
		in_file.close();


		//Doing decryption
		std::cout << "----------" << std::endl;
		std::cout << "Decryption" << std::endl;
		std::cout << "----------" << std::endl;

		std::ifstream internet("internet.txt");
		if (!internet.is_open()) {
			std::cout << "Could not find 'internet.txt', make sure you've sent a message from the client!" << std::endl;
			system("pause");
			return -1;
		}

		//Actual decryption of file
		while (!internet.eof()) {
			char c = internet.get();

			char p = ((long)pow(c, j)) % n; //Decryption: (c^j)%n. It's simple!

			p += 96; //Readjust to actual character

			std::cout << p;
		}

	}

	std::cout << std::endl;
	system("pause");

	return 0;
}