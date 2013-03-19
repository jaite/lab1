#include <iostream>
#include <fstream>
#include "coding.h"

using namespace std;

int main(int argc, char* argv[]) {
	string inName = argv[1];
	string outName = argv[1];
	outName += ".enc";

	
	ifstream readFile;
	const int n = 1000; // Maximum size
	int size = 0; // Size of input 
	char unEncoded[n], encoded[n];
	
	cout << "Encoder" << endl;
	cout << "File to read from: " << inName << endl;
	cout << "File to write to: " << outName << endl;
	readFile.open(inName.c_str());
	
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			if (size >= n) {
				cout << "File too large! Exiting" << endl;
				return -1;
			}
			readFile.get(unEncoded[size++]);
		}
		--size; // Stressat fulhax för att accounta för den size som läggs på då EOF räknas
		unEncoded[size] = '\0';
		readFile.close();
		
		cout << "The unencoded file " << endl 
			 << "---------------------" << endl 
			 << unEncoded;
		
		for (int i = 0; i <= size; ++i) { // Encode
			// cout << unEncoded[i] << endl;
			encoded[i] = cpp_lab1::Coding::encode(unEncoded[i]);
			
		}
		encoded[size] = '\0';
		
		cout << "The encoded file " << endl 
			 << "---------------------" << endl;
		cout << encoded;
		cout << "---------------------" << endl;
		
		ofstream writeFile;
		writeFile.open(outName.c_str());
		if (writeFile.is_open()) {
			for (int i = 0; i < size; ++i) { // Skriv inte nullbyten till filen
				writeFile.put(encoded[i]);	
			}
			writeFile.close();
		}
		
	}
	
}