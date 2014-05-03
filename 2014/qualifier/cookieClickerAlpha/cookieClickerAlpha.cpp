#include <iostream>
#include <iomanip>

using namespace std;

double getVal(double cost, double extraProduction, double goal,
        int numProductions)
{
    double time = 0;
    double production = 2;
    for(int i = 0; i < numProductions; ++i)
    {
        time += cost/production;
        production += extraProduction;
    }

    time += goal/production;

    return time;
}

int main()
{
    int numTests;
    double cost, extraProduction, goal;

    cin >> numTests;
    for(int i = 0; i < numTests; ++i)
    {
        cin >> cost >> extraProduction >> goal;

        int numProductions = 0;
        double best = -1;
        double next;
        while(true)
        {
            next = getVal(cost, extraProduction, goal, numProductions);
            if(next < best || best == -1)
                best = next;
            if(next > best)
                break;
            ++numProductions;
        }
        cout << fixed;
        cout << setprecision(7);
        cout << "Case #" << i+1 << ": " << best << endl;
    }
    
    return 0;
}
