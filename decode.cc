#include <iostream>
#include <fstream>
#include "coding.h"

using namespace std;

int main(int argc, char* argv[]) {
	string inName = argv[1];
	string outName = argv[1];
	inName += ".enc";

	
	ifstream readFile;
	const int n = 1000; // Maximum size
	int size = 0; // Size of input 
	char unEncoded[n], encoded[n];
	
	cout << "Decoder" << endl;
	cout << "File to read from: " << inName << endl;
	cout << "File to write to: " << outName << endl;
	readFile.open(inName.c_str());
	
	if (readFile.is_open()) {

		while (!readFile.eof()) {
			if (size > n - 1) {
				cout << "File too large! Exiting" << endl;
				return -1;
			}
			readFile.get(encoded[size++]);
		}
		--size;
		encoded[size] = '\0';
		readFile.close();
		
		cout << "The encoded file " << endl 
			 << "---------------------" << endl 
			 << encoded;
		
		for (int i = 0; i <= size; ++i) { // decode
			// cout << unEncoded[i] << endl;
			unEncoded[i] = cpp_lab1::Coding::decode(encoded[i]);
			
		}
		unEncoded[size] = '\0';
		
		cout << "The unEncoded file " << endl 
			 << "---------------------" << endl;
		cout << unEncoded;
		cout << "---------------------" << endl;
		
		ofstream writeFile;
		writeFile.open(outName.c_str());
		if (writeFile.is_open()) {
			for (int i = 0; i < size; ++i) { // Skriv inte nullbyten till filen!
				writeFile.put(unEncoded[i]);
			}
			writeFile.close();
		}
		
	}
	
}