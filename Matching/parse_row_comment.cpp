#include <iostream>
#include <regex>
#include <sstream>

int main()
{
    using namespace std;

    // regex reg{ "//[^\n\r]*(\n|\r\n|\r)?" };
    // 
    // if (true == regex_match("// first comment", reg))
    // {
    //     cout << "Hello\n";
    // }

    // 단일행 주석 체크
    // 1. //로 시작
    // 2. 줄바꿈 문자를 만날 때까지 파싱
    // 3. 줄바꿈 문자를 만나면 종료
    //    +. 뒤에 ?가 붙은 건 파일의 마지막 줄일 때 줄바꿈이 없을 수 있기 때문

    // [^class] : negated character class
    regex commentReg{ "//[^\n\r]*(\n|\r\n|\r)?" };
    
    string str = 
        "// first comment\n"
        "// second comment\n"
        "lorem ipsum\n"
        "// third comment\n"
        "dolor sit amet\n"
        "// last comment";
    
    // string str = "// first comment";
    
    // 매치하는 부분만 출력
    {
        auto begin = sregex_iterator(str.begin(), str.end(), commentReg);
        auto end   = sregex_iterator();

        for (auto iter = begin; iter != end; iter++)
        {
            smatch match = *iter;

            cout << match.str();
        }

        cout << '\n';
    }

    return 0;
}
