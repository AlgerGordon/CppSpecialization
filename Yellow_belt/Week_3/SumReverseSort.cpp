//
// Created by General on 14.07.2020.
//

#include <algorithm>
#include "SumReverseSort.h"
//#include "sum_reverse_sort.h"

int Sum(int x, int y)
{
    return x + y;
}

string Reverse(string s)
{
    string rs;
    rs.assign(s.rbegin(), s.rend());
    return rs;
}
void Sort(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
}
