#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const string LOAD = "0";
const string STORE = "1";
const string ADD = "2";
const string SUB = "3";
const string MUL = "4";
const string SHIFTR = "5";
const string DIV = "6";
const string SHIFTL = "7";
const string NOT = "8";
const string AND = "9";
const string OR = "a";
const string XOR = "b";
const string JUMP = "c";
const string LI = "d";
const string BRNE = "e";
const string BREQ = "f";

string decimalToHex(string decimal){
    int n = stoi(decimal);
    string ans = "";
    char hexaDeciNum[100];

    // Counter for hexadecimal number array 
    int i = 0;
    while (n != 0) {
        // Temporary variable to store remainder 
        int temp = 0;

        // Storing remainder in temp variable. 
        temp = n % 16;

        // Check if temp < 10 
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n / 16;
    }

    // Printing hexadecimal number 
    // array in reverse order 
    for (int j = i - 1; j >= 0; j--)
        ans += hexaDeciNum[j];

    if (ans == "")
        ans = "0";

    return ans;
}

int main() {
    // Input and output file names
    string inputFileName = "timer _ assembly.txt";
    string outputFileName = "timer.txt";

    // Open the input file
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cout << "Error opening input file: " << inputFileName << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cout << "Error opening output file: " << outputFileName << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        iss >> word;
        if (word == "LOAD") {
            string from;
            string to;
            iss >> from;
            iss >> to;
            outputFile << LOAD << " ";
            outputFile << decimalToHex(from) << " ";
            outputFile << "0" << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "STORE") {
            string from;
            string to;
            iss >> from;
            iss >> to;
            outputFile << STORE << " ";
            outputFile << decimalToHex(from) << " ";
            outputFile << decimalToHex(to) << " ";
            outputFile << "0" << endl;
        }
        else if (word == "ADD") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << ADD << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "SUB") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << SUB << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "MUL") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << MUL << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "SHIFTR") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << SHIFTR << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "DIV") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << DIV << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "SHIFTL") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << SHIFTL << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "NOT") {
            string a;
            string to;
            iss >> a;
            iss >> to;
            outputFile << NOT << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << "0" << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "AND") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << AND << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "OR") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << OR << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "NAND") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << AND << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << " ";
            outputFile << NOT << " ";
            outputFile << decimalToHex(to) << " ";
            outputFile << "0" << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "XOR") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << XOR << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "NOR") {
            string a;
            string b;
            string to;
            iss >> a;
            iss >> b;
            iss >> to;
            outputFile << OR << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(to) << " ";
            outputFile << NOT << " ";
            outputFile << decimalToHex(to) << " ";
            outputFile << "0" << " ";
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "LI") {
            string intermediate;
            string to;
            iss >> to;
            iss >> intermediate;
            intermediate = decimalToHex(intermediate);
            outputFile << LI << " ";
            if (intermediate.size() > 1) {
                outputFile << intermediate[0] << " ";
                outputFile << intermediate[1] << " ";
            }
            else if (intermediate == "") {
                outputFile << "0" << " ";
                outputFile << "0" << " ";
            }
            else {
                outputFile << "0" << " ";
                outputFile << intermediate[0] << " ";
            }
            outputFile << decimalToHex(to) << endl;
        }
        else if (word == "JUMP") {
            string to;
            iss >> to;
            outputFile << JUMP << " ";
            outputFile << decimalToHex(to) << " ";
            outputFile << "0" << " ";
            outputFile << "0" << endl;
        }
        else if (word == "BRNE") {
            string a;
            string b;
            string branch;
            iss >> a;
            iss >> b;
            iss >> branch;
            outputFile << BRNE << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(branch) << endl;
        }
        else if (word == "BREQ") {
            string a;
            string b;
            string branch;
            iss >> a;
            iss >> b;
            iss >> branch;
            outputFile << BREQ << " ";
            outputFile << decimalToHex(a) << " ";
            outputFile << decimalToHex(b) << " ";
            outputFile << decimalToHex(branch) << endl;
        }
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "File processing complete." << endl;

    return 0;
}
