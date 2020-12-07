//
//  main.cpp
//  adventOfCodeDay2
//
//  Created by Zach Howes on 12/6/20.
//

#include <iostream>

bool validPassword(int low, int high, std::string password, char requiredChar);

int main(int argc, const char * argv[]) {
	
	return 0;
}


bool validPassword(int low, int high, std::string password, char requiredChar) {
	int counter = 0;
	for (int i = 0; i < password.size(); ++i) {
		if (password[i] == requiredChar) {
			++counter;
		}
	}
	
	if (low >= counter && counter <= high) {
		return true;
	}
	
	return false;
}
