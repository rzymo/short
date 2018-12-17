//
// Divisibility by 2-15 for binary numbers
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool divByX(int, string&);
bool verifyBin(string&);
void div(string&);


int main(int argc, char* argv[])
{
    string s;

    if (argc == 2)
    {
        ifstream file;
        file.open(argv[1]);

        if ( file.is_open() )
            getline(file, s);
        else
            s = argv[1];

        file.close();
    }
    else
    {
        cout << "binary number: ";
        cin >> s;
    }

    if (!verifyBin(s)) cout << "Invalid input!" << endl;
    else
    {
        if (s.length() < 3/*4*/)
            cout << "At least 3 characters!" << endl;
        else
            div(s);
    }

    return 0;
}

bool verifyBin(string& s)
{
    bool ok = true;

    for (auto i : s)
        if ( (i != '0') && (i != '1') )
            { ok = false; break; }

    return ok;
}

void div(string &s)
{
    bool out[16] = {}; // fill with zeros

    cout << "\nDivisibility by:\n\n";

    if ( (s.substr(s.length()-1)) == "0" ) out[2] = true;
    if ( (s.substr(s.length()-2)) == "00" ) out[4] = true;
    if ( (s.substr(s.length()-3)) == "000" ) out[8] = true;

    for (int i = 3; i < 14; i += 2)
        out[i] = divByX(i, s); // 3,5,7,9,11,13

    out[6]  = out[2] && out[3];
    out[10] = out[2] && out[5];
    out[12] = out[3] && out[4];
    out[14] = out[2] && out[7];
    out[15] = out[3] && out[5];

    for (int i = 2; i < 16; i++)
    {
        cout << setw(3) << i << " - ";
        if (out[i]) cout << "true\n";
        else cout << "   false\n";
    }
}

bool divByX(int x, string& s)
{
    int tab[x][2];

    switch (x) // DFA
    {
        case 3:
                tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 0; tab[2][0] = 1; tab[2][1] = 2;
                break;
        case 5:
                tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 0; tab[3][0] = 1; tab[3][1] = 2; tab[4][0] = 3; tab[4][1] = 4;
                break;
        case 7:
                tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 0; tab[4][0] = 1; tab[4][1] = 2;
                tab[5][0] = 3; tab[5][1] = 4; tab[6][0] = 5; tab[6][1] = 6;
                break;
        case 9:
                tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 7; tab[4][0] = 8; tab[4][1] = 0;
                tab[5][0] = 1; tab[5][1] = 2; tab[6][0] = 3; tab[6][1] = 4; tab[7][0] = 5; tab[7][1] = 6; tab[8][0] = 7; tab[8][1] = 8;
                break;
        case 11:
                tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 7; tab[4][0] = 8; tab[4][1] = 9;
                tab[5][0] = 10; tab[5][1] = 0; tab[6][0] = 1; tab[6][1] = 2; tab[7][0] = 3; tab[7][1] = 4; tab[8][0] = 5; tab[8][1] = 6; tab[9][0] = 7; tab[9][1] = 8;
                tab[10][0] = 9; tab[10][1] = 10;
                break;
        case 13:
                tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 7; tab[4][0] = 8; tab[4][1] = 9;
                tab[5][0] = 10; tab[5][1] = 11; tab[6][0] = 12; tab[6][1] = 0; tab[7][0] = 1; tab[7][1] = 2; tab[8][0] = 3; tab[8][1] = 4; tab[9][0] = 5; tab[9][1] = 6;
                tab[10][0] = 7; tab[10][1] = 8; tab[11][0] = 9; tab[11][1] = 10; tab[12][0] = 11; tab[12][1] = 12;
                break;
    }

    int pos = 0;
    int jumpTo;

    for (size_t i = 0; i < s.length(); i++)
    {
        istringstream ( s.substr(i,1) ) >> jumpTo;
        pos = tab[pos][jumpTo];
    }

    return (pos ? false : true);
}
