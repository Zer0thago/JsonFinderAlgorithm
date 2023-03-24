# JSON Extractor
This C++ program reads an input file, searches for a JSON object
(enclosed by curly braces {}), and writes the JSON object to an output file after removing any forward slashes /.
## Requirements
C++ compiler (e.g., g++, clang)
## Compilation
To compile the program, run the following command in your terminal:
```bash
g++ -o JsonFinderAlgo main.cpp
```
This will generate an executable file named json_extractor.
## Usage
Prepare an input file named input.txt containing the text from which you want to extract the JSON object.
Run the compiled program:
```bash
./JsonFinderAlgo
```
If a JSON object is found in the input file, the program will
create an output.json file containing the extracted JSON object with any forward slashes / removed.
## Code Overview
```c++
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    using namespace std;
    ifstream input_file("input.txt");
    std::string input_str(std::istreambuf_iterator<char>(input_file), {});

    size_t start_pos = input_str.find("{");
    if (start_pos != string::npos) {
        regex pattern("\\{.*?\\}");
        smatch match;

        if (std::regex_search(input_str, match, pattern)) {
            cout << "Match found: " << match.str() << endl;
            if (!match.str().empty()) {
                ofstream outfile("output.json");
                outfile << std::regex_replace(match.str(), std::regex("/"), "");
                outfile.close();
            }
            else
            {
                cout << "No Match found!";
            }
        }
    }

    return 0;
}
```
The program includes necessary header files for input/output and regex operations.
The main function reads the contents of input.txt into a string.
The program checks for the presence of an opening curly brace { in the input string.
If found, it searches for a JSON object using a regex pattern and extracts it.
If the JSON object is not empty, the program writes it to an output.json file after removing any forward slashes /.
