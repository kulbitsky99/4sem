#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool compare(const string& lhs, const string& rhs)
{

    return (lhs.size() == rhs.size()) ? (lhs < rhs) : (lhs.size() < rhs.size());
    /*for(int i = 0; i < (int)min(lhs.size(), rhs.size()); i++)
    {
        if(lhs[i] < rhs[i])
            return true;
        if(lhs[i] > rhs[i])
            return false;
    }*/
}


int main()
{
    std :: vector<string> base;
    int n;
    cin >> n;
    base.resize(n);
    string data;
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        base[i] = data;
    }
    std :: sort(base.begin(), base.end(), compare);
    for(int i = 0; i < n; i++)
    {
        cout << base[i] << endl;
    }
    return 0;
}
