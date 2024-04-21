/* Name: Evan Raab
 * Project Name: CSC450-CTA05 - User Input Program
 * Project Purpose: Take user input then append to a .txt file. Then, create a new file and reverse the text
 * Algorithm Used: Ask for user input, then open file. Append user input to the file. Store the file's text into a string. Convert string to char array. Reverse char array. Create new file with reversed text.
 * Program Inputs: String userInputOne
 * Program Outputs: CSC450-mod5-reverse.txt
 * Program Errors: None
*/

#include <iostream>
#include <cstring>
using namespace std;
#include <fstream>
#include <string>
#include <sstream>

// opens and reads a .txt file and buffers to string using stream buffer referenced from https://cplusplus.com/reference/ios/ios/rdbuf/
string AddCharactersToString() {

	ifstream rdToStr;
	// open file
	rdToStr.open("CSC450_CT5_mod5.txt");


	if (!rdToStr)
		cout << "unable to read file";

	stringstream buffer;

	// gets file's streambuffer
	buffer << rdToStr.rdbuf();

	string file_contents;

	// assign stream buffer to empty string
	file_contents = buffer.str();


	rdToStr.close();
	// return string that includes file's text
	return file_contents;

}

// converts string to char array referenced from GeeksForGeeks
char* ConvertStrToChar(const std::string& str) {
    char* char_array = new char[str.length() + 1];
    std::strcpy(char_array, str.c_str());
    return char_array;
}

// manually coded swap algorithm since swap() was not working
void swapChar(char& a, char& b)
{
	char tmp = b;
	b = a;
	a = tmp;

}

// reverses a char array
char* ReverseCharacters(char const* str) {

	int n = strlen(str);
	char* rev = new char[n + 1];
	strcpy(rev, str);

	// loop through all characters in the char array and swap them
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		swapChar(rev[i], rev[j]);
	}

	return rev;
}


// creates a new file using the reversed appended text from the original file
void CreateNewFile(string str)
{
	ofstream reversedFile("CSC450-mod5-reverse.txt");

	if (reversedFile.is_open())
	{
		reversedFile << str;
		reversedFile.close();
	}
	else
		cout << "Unable to open file";
}


int main() {

	fstream originalFile;
	std::string strFromText;
	std::string reversedStr;

	// get user input
	std::string userInputOne;
	std::cout << "Enter in some text: ";
	std::getline(std::cin, userInputOne);

	// open file and append the string from user to the file
	originalFile.open("CSC450_CT5_mod5.txt", ios::app);
	if (!originalFile)
		cout << "File not found";
	else {
		originalFile << userInputOne;
		cout << "Check for appended file and new file\n";
		originalFile.close();
	}

	// open file again and add characters to a single string
	strFromText = AddCharactersToString();

	// convert string from file text to char array
	char* char_array = ConvertStrToChar(strFromText);
	// reverse characters in char array
	char* reversed_chars = ReverseCharacters(char_array);
	// store reversed characters into a string
	reversedStr = reversed_chars;
	// memory management
	delete[] char_array;
    delete[] reversed_chars;

    // create new file with reversed text from original file
    CreateNewFile(reversedStr);

	return 0;

}
