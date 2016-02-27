#include <iostream>
/*
********************************
* The longest common sequence
* Created by Soyn.
* Created Time: 24/1/16.
********************************
*/

class LCS{
public:
    LCS() = default;
    LCS(const std :: string str1, const std :: string str2) : S1(str1), S2(str2)
    {
        S1Len = S1.length() + 1;
        S2Len = S2.length() + 1;
        C = new int(S1Len * S2Len);
    }
    void PrintLCS(int, int);
    void LCSLength();
    void PrintTable();
    ~LCS()
    {
        delete C;
    }
private:
    std :: string S1, S2;
    int S1Len, S2Len;
    int *C;
};

int main(int argc, char **argv)
{
    std :: string S1("ABCBDAB"), S2("BDCABA");
    LCS L1(S1,S2);
    L1.LCSLength();
    //L1.PrintLCS(7,6);
    L1.PrintTable();
    return 0;
}

void LCS :: LCSLength()
{
    char Chr1[S1Len], Chr2[S2Len];
    for(int i = 1; i < S1Len; ++i)
        Chr1[i] = S1[i - 1];
    for(int i = 1; i < S2Len; ++i)
        Chr2[i] = S2[i - 1];

    // assgin 0 to C[i][0]
    for(int i = 0; i < S1Len; ++i){
        C[i * S2Len] = 0;
    }
    // assgin 0 to C[0][i]
    for(int i = 0; i < S2Len; ++i){
        C[i] = 0;
    }

    //the procedure to get the length table of subsequence
    int row, col;
    for( row = 1; row < S1Len; ++row){
        for( col = 1; col < S2Len; ++col){
            if(Chr1[row] == Chr2[col]){
                C[(row *S2Len + col)] = C[((row - 1) * S2Len + (col - 1))] + 1;
            }else{
                if(C[((row - 1) * S2Len + col)] >= C[(row * S2Len + (col - 1))]){
                    C[(row * S2Len + col)] = C[((row - 1) * S2Len  + col)];
                }else{
                    C[(row * S2Len + col)] = C[(row * S2Len + (col - 1))];
                }
            }
        }
    }
}

void LCS :: PrintLCS(int row, int col )
{
    std :: cout << S1;
    if(row ==0 || col == 0)
        return;
    if(S1[row - 1] == S2[col - 1]){
        PrintLCS(row - 1, col - 1);
        std :: cout <<  "Row: " << row << ' ' << S1[row] << '\n';
    }else{
        if(C[(row - 1) * S2Len + col] >= C[row * S2Len +(col - 1)])
            PrintLCS(row - 1, col);
        else
            PrintLCS(row, col - 1);
    }
}

void LCS :: PrintTable()
{
    int Count = 0;
    for(int i = 0; i < S1Len * S2Len; ++i){
        ++Count;
        std :: cout << C[i] << ' ';
        if( Count % S2Len == 0)
            std :: cout << '\n';
    }
}
