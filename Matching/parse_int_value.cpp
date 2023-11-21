#include <iostream>
#include <regex>

int main()
{
    using namespace std;

    // 10진수
    regex intDec{ "[1-9]([0-9])*[uU]?[lL]?[lL]?" };

    // 8진수
    regex intOct{ "0([0-7])+[uU]?[lL]?[lL]?" };

    // 16진수
    regex intHex{ "0[xX]([0-9a-fA-F])+[uU]?[lL]?[lL]?" };

    // 2진수
    regex intBin{ "0[bB]([01])+[uU]?[lL]?[lL]?" };

    // 숫자 0
    regex intZero{ "0[uU]?[lL]?[lL]?" };

    // 합친 형태(8진수에서 숫자 0도 함께 다룸 / intOct와 살짝 다름)
    regex combinedReg{ 
        "([1-9]([0-9])*[uU]?[lL]?[lL]?)|"\
        "(0([0-7])*[uU]?[lL]?[lL]?)|"\
        "(0[xX]([0-9a-fA-F])+[uU]?[lL]?[lL]?)|"\
        "(0[bB]([01])+[uU]?[lL]?[lL]?)" };

    int val = 00557ull;

    string str;

    while (true)
    {
        getline(cin, str);

        if (true == regex_match(str, intDec))
        {
            cout << "Int Decimal\n";
        }
        else if (true == regex_match(str, intOct))
        {
            cout << "Int Oct\n";
        }
        else if (true == regex_match(str, intHex))
        {
            cout << "Int Hex\n";
        }
        else if (true == regex_match(str, intBin))
        {
            cout << "Int Binary\n";
        }
        else if (true == regex_match(str, intZero))
        {
            cout << "Int Zero\n";
        }
        else
        {
            cout << "Not Matched!\n";
        }

        // if (true == regex_match(str, combinedReg))
        // {
        //     cout << "Matched!\n";
        // }
        // else
        // {
        //     cout << "Not Matched!\n";
        // }
    }

    return 0;
}
