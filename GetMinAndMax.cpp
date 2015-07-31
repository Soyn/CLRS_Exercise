#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

//!
//! @Brief:get the minmum and maxmum in an array (size is n) , by using 3 * (n // 2) comparisons.
//! Create by Soyn. 31/7/15.
//! Refactor by @Mooopy
//!


std :: pair<int, int> max_min( int lhs, int rhs)
{

    return lhs > rhs ? std :: make_pair(lhs,rhs) : std :: make_pair( rhs, lhs);
}

// at least 2 items in vector
std :: pair<int, int> find_max_min( std:: vector<int> const & sequence)
{
        int max, min;
        std :: tie( max, min) = max_min( sequence[0], sequence[1]);
        for( auto it = sequence.cbegin(); it < sequence.cend() - 1; it += 1)
        {
            auto curr_pair = max_min(*(it), *( it + 1));
            max = std ::max( max, curr_pair.first), min = std :: min( min, curr_pair.second);
        }
        if( sequence.size() & 0x1)  // for odd size
                max = std :: max( max,sequence.back()), min = std :: min( min, sequence.back());

        return std :: make_pair(max, min);
}

int main(void)
{
        std :: vector<int> sample = {11,52,-3,-4,75,60,-199};
        auto pair = find_max_min(sample);
        std :: cout << "max : " << pair.first << " min : " << pair.second << std :: endl;
        return 0;
}
