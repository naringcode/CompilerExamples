#include <iostream>
#include <regex>
#include <sstream>

int main()
{
    using namespace std;

    // 다중행 주석 체크
    regex commentReg{ "/\\*[^]*\\*/" };

    // TEMP
    // regex commentReg{ ".*/\\*.*" };
    // regex commentReg{ ".*\\*/" };

    // string str = "/* 43243  */";

    string str =
        // "423/* 4322rewjoi123 */"
        // "/* 42348fdsfdf34 */";
        "/* 4322rewjoi123 */"
        "/* 42348fdsfdf34 */";

    if (true == regex_match("/* 43243  */", commentReg))
    {
        // 매치하는 부분만 출력
        auto begin = sregex_iterator(str.begin(), str.end(), commentReg);
        auto end = sregex_iterator();

        for (auto iter = begin; iter != end; iter++)
        {
            smatch match = *iter;

            cout << ": " << match.str();
        }
    }

    return 0;
}
