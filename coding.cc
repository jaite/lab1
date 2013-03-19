/*
 * coding.cc
 */

#include "coding.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

namespace cpp_lab1 {
	
	const string encoding = "bcdefghijklmnopqrstuvwxyza";
	const string alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	unsigned char Coding::encode(unsigned char c) {
		int index = alphabet.find(c);
		if (index >= 0 && index < alphabet.length()) {
			return encoding[index];
		}
		return c;
	}
	
	unsigned char Coding::decode(unsigned char c) {
		int index = encoding.find(c);
		
		if (index >= 0 && index < encoding.length()) {	
			return alphabet[index];
		}
		return c;
	}
}