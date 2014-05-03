#include <iostream>
#include <math.h>

typedef long long ll;

using namespace std;

ll getArea(ll radius)
{
    return pow(radius, 2);
}

ll getNumRings(ll radius, ll remainingPaint)
{
    ll count = 0;
    ll diff = 2*radius + 1;
    while(remainingPaint >= 0)
    {
        remainingPaint -= diff;
        diff += 4;
        ++count;
    }

    if(remainingPaint < 0)
        --count;
    return count;
}

int main()
{
    ll numTests, currentRadius, remainingPaint;
    cin >> numTests;

    for(int i = 0; i < numTests; ++i)
    {
        cin >> currentRadius >> remainingPaint;
        cout << "Case #" << i+1 << ": "<< getNumRings(currentRadius, remainingPaint) << endl;
    }

    return 0;
}
