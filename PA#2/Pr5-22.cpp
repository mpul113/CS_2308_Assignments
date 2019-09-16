// This program reads data from a file.
// The file contains a series of pairs:  a number followed by a string.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    int  num2,
      num3;
    double num;
    string str,
      str2,
      str3;
    
    // Open the file.
    inputFile.open("library.txt");
    
    int count = 0;
    // Read the numbers and strings from the file and
    // display them.
    while (inputFile >> str)  //while the input of the next number succeeds
    {
        inputFile >> ws;
        getline(inputFile, str2);
	inputFile >> ws;
	getline(inputFile, str3);  //input the next string
	inputFile >> ws >> num >> num2 >> num3;
        cout << str << endl
             << str2 << endl
             << str3 << endl
             << num << " "  << num2 << " "  << num3 << endl << endl;
        count++;
    }

    cout << count;    
    // Close the file.
    inputFile.close();
    return 0;
}
