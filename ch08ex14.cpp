/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Gabrielle Jackson
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

//Stats function
class Stats{
public:
	 Stats()
		 :  MinLength(""), MaxLength(""), FirstPosition(""), LastPosition("") {
	 
	 }

	 void print() const{
		std::cout <<"Shortest: "<< MinLength <<'\n';
		std::cout <<"Longest: "<< MaxLength <<'\n';
		std::cout <<"Lexicographically First: "<< FirstPosition <<'\n';
		std::cout <<"Lexicographically Last: "<< LastPosition <<'\n';

		std::cout <<"Lengths of elements:\n";
		for (size_t i = 0; i < lengths.size(); ++i){
			std::cout << lengths[i] <<'\n';
		}
	 }

	 std::string MinLength;
	 std::string MaxLength;
	 std::string FirstPosition;
	 std::string LastPosition;
	 std::vector<size_t> lengths;
}

//declaring functions
void Populate(std::vector<std::string>&);
void Find_Stats(const std::vector<std::string>&, Stats&);
std::string Find_Max(const std::vector<std::string>&);
std::string Find_Min(const std::vector<std::string>&);

int main(){
		std::cout << "Find element lengths; Min and Max length and Position First and Last.\n";

		std::vector<std::string> names;
		Populate(names);

		Stats Stats;
		Find_Stats(names, Stats);

		Stats.print();
}//end of main

//Populate function
void Populate(std::vector<std::string>& v){
	 std::cout <<"Populate a vector with Strings. 'exit' to Exit.\n";

	 std::string prompt("Type a string:\n>>");
	 std::string sentinel("exit");

	 while(true){
		std::cout << prompt;
		std::string input;
		getline(std::cin, input);

		if (input == sentinel){
			return;
		}

		v.push_back(input);
	 }
}//end of Populate function

//Find_Stats function
void Find_Stats(const std::vector<std::string>& v, Stats& s){
	for (size_t i = 0; i < v.size(); ++i){
		s.lengths.push_back(v[i].size());	
	}

	s.MinLength = Find_Min(v);
	s.MaxLength = Find_Max(v);

	std::vector<std::string> temp(v);
	sort(temp.begin(), temp.end());

	s.FirstPosition = temp[0];
	s.LastPosition = temp[temp.size() - 1];
}//end of FInd_Stats function

//Find_Min fucntion
std::string Find_Min(const std::vector<std::string>& v){
	std::string shortest;
	size_t length = std::numeric_limits<size_t>::max();
	for (size_t i = 0; i < v.size(); ++i){
		if (length > v[i].size()){
			length = v[i].size();
			shortest = v[i];
		}
	}
	return shortest;
}//end of Find_Min

//Find_Max function
std::string Find_Max(const std::vector<std::string>& v){
	std::string longest;
	size_t length = std::numeric_limits<size_t>::min();
	for (size_t i = 0; i < v.size(); ++i){
		 if (length < v[i].size()){
			length = v[i].size();
			longest = v[i];
		 }
	}
	return longest;
}//end of Find_Max function