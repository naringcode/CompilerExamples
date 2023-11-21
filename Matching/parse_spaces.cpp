#include <iostream>
#include <regex>
#include <sstream>

int main()
{
    using namespace std;

    // 공백 체크
    regex spaceReg{ "[ \t\n\r\f]+" };

    string str = "apple \t  banana\n \n\r mango melon";
    string repStr = regex_replace(str, spaceReg, " ");

    vector<string> vec;

    // Split
    {
        stringstream ss{ repStr };

        string temp;

        while (getline(ss, temp, ' '))
        {
            vec.push_back(temp);
        }
    }

    std::cout << repStr << '\n';

    for (const string& str : vec)
    {
        std::cout << str << '\n';
    }

    return 0;
}
