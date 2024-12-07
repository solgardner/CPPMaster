#include <iostream>
#include <fstream>  // For file I/O
#include <string>
#include <cstdlib>
#include "MatCalc.h"

// Function to split a string by a delimiter and return a dynamically allocated array of integers
int* split(const std::string& text, char delimiter, int& count) {
	// First, determine the number of elements (tokens) in the result
	count = 1; // Start with one token, assuming there's no delimiter at the ends
	for (char ch : text) {
    	if (ch == delimiter) {
        	++count; // Count delimiters to determine the number of tokens
    	}
	}

	int* splitArray = new int[count]; // Dynamically allocate an array of integers
	int currItem = 0;
	size_t startingIndex = 0;

	// Iterate through the string to split based on the delimiter
	for (size_t i = 0; i <= text.size(); ++i) {
    	if (i == text.size() || text[i] == delimiter) {
        	// Extract substring and convert it to integer
        	std::string token = text.substr(startingIndex, i - startingIndex);
        	splitArray[currItem++] = std::stoi(token); // Convert and store in array
        	startingIndex = i + 1; // Update starting index to the character after the delimiter
    	}
	}

	return splitArray; // Return the dynamically allocated array
}

// Function to read file and return the final array
int** readFiles(int& totalRows, int& totalColumns, const std::string& fileName) {
	std::ifstream inputFile(fileName);

	if (!inputFile) {
    	std::cerr << "Error opening file: " << fileName << std::endl;
    	totalRows = 0;
    	totalColumns = 0;
    	return nullptr;
	}

	std::string line;
	std::getline(inputFile, line);
	totalRows = std::stoi(line); // First line: number of rows
	std::getline(inputFile, line);
	totalColumns = std::stoi(line); // Second line: number of columns

	int** finalArray = new int*[totalRows];

	for (int i = 0; i < totalRows; ++i) {
    	if (std::getline(inputFile, line)) {
        	int tmpCount;
        	finalArray[i] = split(line, ' ', tmpCount);

        	// Debug: Print the parsed row
        	std::cout << "Row " << i << ": ";
        	for (int j = 0; j < totalColumns; ++j) {
            	std::cout << finalArray[i][j] << " ";
        	}
        	std::cout << std::endl;

        	// Ensure the parsed columns match the expected count
        	if (tmpCount != totalColumns) {
            	std::cerr << "Error: Row " << i << " has incorrect number of columns." << std::endl;
        	}
    	} else {
        	std::cerr << "Error: Not enough rows in file." << std::endl;
        	totalRows = i; // Update total rows read
        	break;
    	}
	}

	inputFile.close();
	return finalArray;
}




/*
void removeCoreFiles(const std::string& directory) { // Define the regex pattern 
for core.% files std::regex pattern("^core\\.\\d+$"); // Iterate through the directory 
for (const auto& entry : fs::directory_iterator(directory)) { // Check if the current entry is a regular file 
if (fs::is_regular_file(entry)) { // Get the filename as a string 
std::string filename = entry.path().filename().string(); // Check if the filename matches the regex 
if (std::regex_match(filename, pattern)) { // Remove the file
std::cout << "Removing file: " << entry.path() << std::endl; fs::remove(entry); // Deletes the file } } } }
*/

int main() {
  std::remove("core.136");
  return 0;
	int totalRows1;
	int totalColumns1;
	int totalRows2;
	int totalColumns2;
	int** array1 = readFiles(totalRows1,totalColumns1,"m1.txt");
	int** array2 = readFiles(totalRows2,totalColumns2,"m2.txt");// Get the final array and count from readFiles

	if (array1 && array2) { // Check if array is not null
    	MatCalc add = MatCalc(array1,totalRows1,totalColumns1,array2, totalRows2,totalColumns2,'*');
	} else {
    	std::cerr << "No data was read from the file." << std::endl;
	}

	return 0;
}