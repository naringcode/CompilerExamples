#include <iostream>
#include <vector>
#include <regex>

int main()
{
    using namespace std;

    vector<regex> keywordVec;

    // Set Keywords
    {
        keywordVec.push_back(regex{ "int" });
        keywordVec.push_back(regex{ "float" });
    }

    regex variable("[a-zA-Z_]([a-zA-Z0-9_])*");

    string str;

    while (true)
    {
        getline(cin, str);

        bool keyMatched = std::any_of(keywordVec.begin(), keywordVec.end(), [str](const regex& reg) {
            return regex_match(str, reg);
        });

        if (true == keyMatched)
        {
            cout << "Keyword Matched!\n";
        }
        else
        {
            if (true == regex_match(str, variable))
            {
                cout << "Variable Matched!\n";
            }
            else
            {
                cout << "Not Matched!\n";
            }
        }
    }

    return 0;
}
