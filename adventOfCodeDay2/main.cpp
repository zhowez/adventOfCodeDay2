//
//  main.cpp
//  adventOfCodeDay2
//
//  Created by Zach Howes on 12/6/20.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <fstream>


bool validPasswordPart1(std::tuple<int,int,std::string,char>);

int numberOfValidPasswords(std::vector<std::tuple<int,int,std::string,char>>&,bool (*validPass)(std::tuple<int,int,std::string,char>));

void createVectorOfPasscodes(std::vector<std::tuple<int,int,std::string,char>>&,std::ifstream &);

void openFile(std::string, std::ifstream&);

bool validPasswordPart2(std::tuple<int,int,std::string,char>);

int main(int argc, const char * argv[]) {
	std::vector<std::tuple<int,int,std::string,char>> passwords;
	std::ifstream file;
	openFile(argv[1],file);
	createVectorOfPasscodes(passwords,file);
	
	int numOfCodes = numberOfValidPasswords(passwords,validPasswordPart1);
	
	std::cout << "The total number of valid passcodes is " << numOfCodes << "\n";
	
	numOfCodes = numberOfValidPasswords(passwords,validPasswordPart2);
	
	std::cout << "The total number of valid passcodes is " << numOfCodes << "\n";
	
	return 0;
}


bool validPasswordPart1(std::tuple<int,int,std::string,char> password) {
	int low = std::get<0>(password);
	int high = std::get<1>(password);
	std::string pW = std::get<2>(password);
	char neededChar = std::get<3>(password);
	
	int counter = 0;
	for (int i = 0; i < pW.size(); ++i) {
		if (pW[i] == neededChar) {
			++counter;
		}
	}
	
	if (counter >= low && counter <= high) {
		return true;
	}
	
	return false;
}

void createVectorOfPasscodes(std::vector<std::tuple<int,int,std::string,char>>& passwords,std::ifstream & file) {
	int low;
	char throwAway;
	int high;
	char letter;
	std::string code;
	while (file >> low) {
		file >> throwAway >> high >> letter >>throwAway >> code;
		passwords.push_back(std::make_tuple(low,high,code,letter));
	}
	
}

void openFile(std::string fileName,std::ifstream &file) {
		file.open(fileName);
	
	if (!file.is_open()) {
		std::cout << "The file could not open" << std::endl;
		exit(-1);
	}
	
}

int numberOfValidPasswords(std::vector<std::tuple<int,int,std::string,char>>& passwords,bool (*validPass)(std::tuple<int,int,std::string,char>)) {
	int count = 0;
	for (int i = 0; i < passwords.size(); ++i) {
		if (validPass(passwords[i])) {
			++count;
		}
	}
	return count;
}


bool validPasswordPart2(std::tuple<int,int,std::string,char> password) {
	bool isCorrect = false;
	int low = std::get<0>(password);
	int high = std::get<1>(password);
	std::string pW = std::get<2>(password);
	char neededChar = std::get<3>(password);
	
	if (pW[low-1] == neededChar) {
		isCorrect = !isCorrect;
	}
	
	if (pW[high-1] == neededChar) {
		isCorrect = !isCorrect;
	}
	
	return isCorrect;
}
