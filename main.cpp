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
