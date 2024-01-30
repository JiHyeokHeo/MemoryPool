#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
#include <basetsd.h>
#include <map>
using namespace std;

map<int, int> mp;
int main()
{
    vector<int> v{ 1,1,2,2,3,3 };
    for (int i : v)
    {
        if (mp[i])
            continue;
        else
            mp[i] = 1;
    }

    vector<int> ret;
    map<int, int>::iterator it
        = mp.begin();
    for (; it != mp.end(); it++)
        ret.push_back(it->first);

    for (int i : ret)
        cout << i << '\n';

    return 0;
}

