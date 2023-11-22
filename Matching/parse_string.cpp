#include <iostream>
#include <regex>
#include <sstream>

enum class ScanMode
{
    Default,
    InString
};

bool Parse(std::string exp, std::vector<std::string>* outRes)
{
    ScanMode scanMode = ScanMode::Default;

    std::regex pattern{ ".*\"" };

    auto iter = exp.begin();
    
    std::string res  = "";
    std::string temp = "";

    while (exp.end() != iter)
    {
        switch (scanMode)
        {
            case ScanMode::Default:
            {
                temp.push_back(*iter);
                iter++;

                if (true == std::regex_match(temp, pattern))
                {
                    res += "\"";
                    temp = "";

                    scanMode = ScanMode::InString;
                }

                break;
            }

            case ScanMode::InString:
            {
                temp.push_back(*iter);
                iter++;

                if (true == std::regex_match(temp, pattern))
                {
                    res += temp;

                    outRes->push_back(std::move(res));

                    res  = "";
                    temp = "";

                    scanMode = ScanMode::Default;
                }

                break;
            }
        }
    }

    // 아직 다 파싱하지 못한 상태
    if (ScanMode::InString == scanMode)
    {
        outRes->clear();

        return false;
    }

    return true;
}

int main()
{
    // TODO
    // parse_multiline_comment.cpp와 같은 문제가 있음
    // 일단 원하는 기능 다 만들고 나중에 수종
    using namespace std;

    regex reg{ "\"[^]*\"" };

    // 문자열 파싱
    string str = "";

    // str.push_back('"');
    // str.push_back('A');
    // str.push_back('B');
    // str.push_back('C');
    // str.push_back('"');

    str = "\"abcd\"123\"efgh\"";

    vector<string> vec;

    if (true == Parse(str, &vec))
    {
        for (auto elem : vec)
        {
            std::cout << elem << '\n';
        }
    }
    else
    {
        std::cout << "Parsing Failed\n";
    }

    return 0;
}
