//
// Created by General on 03.08.2020.
//

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt>
FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{
    function<bool(const string&, const string&)> compLB {
            [](const string& element, const string& value){
                return element.length() < value.length() ? true : element.substr(0, value.length()) < value;
            }
    };
    function<bool(const string&, const string&)> compUB {
            [](const string& value, const string& element){
                return value.length() < element.length() ?  value < element.substr(0, value.length()) : false;
            }
    };

    pair<RandomIt, RandomIt> res;
    res.first = lower_bound(range_begin, range_end, string(1, prefix), compLB);
    res.second = upper_bound(range_begin, range_end, string (1,prefix), compUB);
    return res;
}

int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}