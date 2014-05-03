#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int minSet;

int getNumSet(ll num)
{
    int numSet = 0;
    for(int i = 0; i < 50; ++i)
    {
        numSet += num & 1 ? 1 : 0;
        num >>= 1;
    }
    return numSet;
}

ll getDiff(ll a, ll b)
{
    return a^b;
}

void solve(const vector<ll>& devices, int currentDevice, vector<ll> outlets, ll diff)
{
    if(currentDevice == devices.size())
    {
        minSet = getNumSet(diff);
        return;
    }

    for(int i = 0; i < outlets.size(); ++i)
    {
        ll newDiff = getDiff(devices[currentDevice], outlets[i]);
        if(diff == -1 && getNumSet(newDiff) >= minSet)
            continue;

        if(newDiff == diff || diff == -1)
        {
            vector<ll> newOutlets(outlets);
            newOutlets.erase(newOutlets.begin()+i);
            solve(devices, currentDevice+1, newOutlets, newDiff);
        }
    }
}

void readCurrents(vector<ll> & currents, int numCurrents, int length)
{
    for(int i = 0; i < numCurrents; ++i)
    {
        ll num = 0;
        char ch;
        for(int k = 0; k < length; ++k)
        {
            cin.get(ch);
            if(ch != '0' && ch != '1')
            {
                --k;
                continue;
            }
            num <<= 1;
            num += ch == '0' ? 0 : 1;
        }
        currents[i] = num;
    }
}

int main()
{
    int numTests, numDevices, length;
    cin >> numTests;

    for(int i = 0; i < numTests; ++i)
    {
        minSet = 1000;

        cin >> numDevices >> length;

        vector<ll> outlets(numDevices);
        readCurrents(outlets, numDevices, length);

        vector<ll> devices(numDevices);
        readCurrents(devices, numDevices, length);

        solve(devices, 0, outlets, -1);
        cout << "Case #" << i+1 << ": ";
        if(minSet == 1000)
            cout << "NOT POSSIBLE";
        else
            cout << minSet;
        cout << endl;
    }

    return 0;
}
