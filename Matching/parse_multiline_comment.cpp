#include <iostream>
#include <regex>
#include <sstream>

enum class ScanMode
{
    Default,
    InBlockComment
};

bool Parse(std::string exp, std::vector<std::string>* outRes)
{
    ScanMode scanMode = ScanMode::Default;

    std::regex patternNoBegin{ ".*\\*/" }; // "*/"로 시작하면 안 됨
    std::regex patternYesBegin{ ".*/\\*" };
    std::regex patternEnd{ "/\\*[^]*\\*/" };

    auto iter = exp.begin();

    std::string str = "";

    while (exp.end() != iter)
    {
        switch (scanMode)
        {
            case ScanMode::Default:
            {
                str.push_back(*iter);
                iter++;

                if (true == std::regex_match(str, patternNoBegin))
                {
                    scanMode = ScanMode::InBlockComment;

                    break;
                }
                else if (true == std::regex_match(str, patternYesBegin))
                {
                    str = "/*";

                    scanMode = ScanMode::InBlockComment;
                }

                break;
            }

            case ScanMode::InBlockComment:
            {
                str.push_back(*iter);
                iter++;

                if (true == std::regex_match(str, patternEnd))
                {
                    outRes->push_back(std::move(str));
                    str = "";

                    scanMode = ScanMode::Default;
                }

                break;
            }
        }
    }

    // 아직 다 파싱하지 못한 상태
    if (ScanMode::InBlockComment == scanMode)
    {
        outRes->clear();

        return false;
    }

    return true;
}

int main()
{
    using namespace std;

    // 다중행 주석 체크
    string str = "/*/";
    
    // string str = "/* 43243  */";

    // string str = "/*\na\tbc */";

    // string str =
    //     "423/* 4322rewjoi123 */"
    //     "rewrwerwer"
    //     "/* 42348fdsfdf34 */";
    
    // string str = 
    //     "/* 4322rewjoi123 */"
    //     "/* 42348fdsfdf34 */";

    // string str = 
    //     "/* 4322rewjoi123 */"
    //     "/* 42348fdsfdf34 */*/";

    // TODO : 이거 작동 안 한다.
    string str = 
        "/*/*/* 4322rewjoi123 */"
        "/* 42348fdsfdf34 */";

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
