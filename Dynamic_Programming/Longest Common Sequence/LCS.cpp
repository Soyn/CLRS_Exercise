/********************************
* @Author: Soyn
* @Brief:The longest common sequence
* @CreatedTime:24/1/16.
********************************/
#include <iostream>
#include <memory>
#include <string>

//
// @Brief: longest common sequence
class LCS{
public:
    LCS() = default;
    LCS(const std :: string sequence_x, const std :: string sequence_y) :
        sequence_x_(sequence_x), sequence_y_(sequence_y),
        sequence_x_length_(sequence_x_.length()), sequence_y_length_(
        sequence_y_.length()), record_length_table_(
        new int[(sequence_x_length_ + 1) * (sequence_y_length_ + 1)])
        {

        }
    void GetLength();
    LCS(const LCS &) = delete;
    LCS& operator=(const LCS&) = delete;

    void PrintLCS(int, int);
    void LCSLength();
    void PrintTable();
    ~LCS(){}
private:
    std :: string sequence_x_, sequence_y_;
    size_t sequence_x_length_, sequence_y_length_;
    std :: unique_ptr<int[]> record_length_table_;
};

void LCS :: GetLength()
{
    std :: cout << "Sequence_x_length: " << sequence_x_length_ << " ";
    std :: cout << "Sequence_y_length: " << sequence_y_length_ << " ";
}
void LCS :: LCSLength()
{
    char char_table_x[sequence_x_length_ + 1],
         char_table_y[sequence_y_length_ + 1];

    for(auto i = 1; i < sequence_x_length_; ++i)
        char_table_x[i] = sequence_x_[i - 1];

    for(auto i = 1; i < sequence_y_length_; ++i)
        char_table_y[i] = sequence_y_[i - 1];

    for(auto i = 0; i < sequence_x_length_ * sequence_y_length_ + 2; ++i)
        record_length_table_[i] = 0;

    //the procedure to get the length table of subsequence
    for(auto row = 1; row < sequence_x_length_ + 1 ; ++row){
        for(auto col = 1; col < sequence_y_length_ + 1; ++col){
            if(char_table_x[row] == char_table_y[col]){
                record_length_table_[(row * sequence_y_length_ + col)] =
                 record_length_table_[((row - 1) *
                                sequence_y_length_ + (col - 1))] + 1;
            }else{
                if(record_length_table_[((row - 1) * sequence_y_length_ + col)]
            >= record_length_table_[(row * sequence_y_length_ + (col - 1))]){

                    record_length_table_[(row * sequence_y_length_ + col)] =
                record_length_table_[((row - 1) * sequence_y_length_  + col)];

                }else{

                    record_length_table_[(row * sequence_y_length_ + col)] =
                record_length_table_[(row * sequence_y_length_ + (col - 1))];

                }
            }
        }
    }
}

void LCS :: PrintLCS(int row, int col)
{
    std :: cout << sequence_x_;
    if(row ==0 || col == 0)
        return;
    if(sequence_x_[row - 1] == sequence_y_[col - 1]){
        PrintLCS(row - 1, col - 1);
        std :: cout <<  "Row: " << row << ' ' << sequence_x_[row] << '\n';
    }else{
        if(record_length_table_[(row - 1) * sequence_y_length_ + col] >=
           record_length_table_[row * sequence_y_length_ +(col - 1)])
            PrintLCS(row - 1, col);
        else
            PrintLCS(row, col - 1);
    }
}

void LCS :: PrintTable()
{
    int _count = 0;
    for(int i = 0; i < (sequence_x_length_ + 1) * (sequence_y_length_ + 1);
        ++i){
        ++_count;
        std :: cout << record_length_table_[i] << ' ';
        if( _count % sequence_y_length_ == 0)
            std :: cout << '\n';
    }
}

int main(int argc, char **argv)
{
    std :: string S1("ABCBDAB"), S2("BDCABA");
    LCS L1(S1,S2);
    L1.LCSLength();
    //L1.PrintLCS(7,6);
    //L1.PrintTable();
    L1.GetLength();
    return 0;
}
