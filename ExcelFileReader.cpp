// ExcelFileReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

#define String std::string
#define Vector std::vector
#define Array std::array

void PrintArray(Array<String, 4> inputData) {
    for (String Data : inputData)
        std::cout << Data;
}

bool Sort(Array<String, 4> inputData) {

    if (inputData[2] == " 7")
        return true;
    else
        return false;

}

void Split(String Text,  Vector<std::array <String, 4>> &FileData) {
    std::array<String, 4> LineValue;

    //Look through the string item, and check if it is a comma, if it is, then assign everything before it up to a point as an item in the array.
    //Keep track of the length and index of string as you progress.
    size_t lengthFromComma = 0;
    int index = 0;

    for (size_t I = 0; I < Text.length(); I++) {//loop through string
        if (Text[I] == ',') {//check for comma
            String value = Text.substr(I - lengthFromComma, lengthFromComma);
            LineValue[index] = value; //append to array
            lengthFromComma = 0;
            index++;
        }
        else {
            lengthFromComma++;
        }

    }
    String lastValue = Text.substr(Text.length() - lengthFromComma+1, lengthFromComma-1);
    LineValue[3] = " " + lastValue;

    FileData.push_back(LineValue);

}

int main()
{
    String Text;

    Vector<std::array <String, 4>>  FileData;

    std::ifstream TestFile("TestExcelFile.csv");
    if (TestFile.is_open())
        while (getline(TestFile, Text)) {
            //std::cout << Text << std::endl;
            Split(Text, FileData);
        }

    TestFile.close();

    for (std::array<String, 4> Data : FileData) {
        if (Sort(Data)) {
            PrintArray(Data);
            std::cout << "\n";
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
