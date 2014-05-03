#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int caseNum)
{
    int row, num;
    set<int> possibilities1;
    cin >> row;
    --row;

    // get all possibilities from the first square
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cin >> num;
            if(i == row)
                possibilities1.insert(num);
        }
    }

    set<int> possibilities2;
    cin >> row;
    --row;

    // get all possibilities from the second square
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cin >> num;
            if(i == row)
                possibilities2.insert(num);
        }
    }

    vector<int> intersection(10);
    vector<int>::iterator it;
    it = set_intersection(possibilities1.begin(), possibilities1.end(),
                          possibilities2.begin(), possibilities2.end(),
                          intersection.begin());
    intersection.resize(it-intersection.begin());

    cout << "Case #" << caseNum << ": ";
    if(intersection.size() == 0)
        cout << "Volunteer cheated!";
    else if(intersection.size() == 1)
        cout << intersection[0];
    else
        cout << "Bad magician!";
    cout << endl;
}

int main()
{
    int numTests;
    cin >> numTests;

    for(int i = 0; i < numTests; ++i)
        solve(i+1);

    return 0;
}
