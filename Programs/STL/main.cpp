#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> v {1, 3, 5};
    std::sort(v.begin(), v.end());
    for(auto ele : v)
        cout << ele << endl;
    cout << endl;

    std::reverse(v.begin(), v.end());
    for(auto ele : v)
        cout << ele << endl;
    cout << endl;

    int sum {};
    sum = std::accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    return 0;
}