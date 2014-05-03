#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int war(vector<double> naomis, vector<double> kens)
{
    int count = naomis.size();
    for(int i = 0; i < naomis.size(); ++i)
    {
        for(int j = 0; j < kens.size(); ++j)
        {
            if(kens[j] > naomis[i])
            {
                --count;
                kens.erase(kens.begin()+j);
                break;
            }
        }
    }
    return count;
}

int d_war(vector<double> naomis, vector<double> kens)
{
    int count = 0;
    for(int i = 0; i < naomis.size(); ++i)
    {
        int highest = -1;
        for(int j = 0; j < kens.size(); ++j)
        {
            if(naomis[i] > kens[j])
                highest = j;
        }

        if(highest == -1)
        {
            kens.erase(kens.end()-1);
        }
        else
        {
            ++count;
            kens.erase(kens.begin()+highest);
        }
    }
    return count;
}

int main()
{
    int numTests, numBlocks;
    cin >> numTests;

    for(int i = 0; i < numTests; ++i)
    {
        cin >> numBlocks;

        vector<double> naomis(numBlocks);
        vector<double> kens(numBlocks);
        for(int j = 0; j < numBlocks; ++j)
            cin >> naomis[j];
        for(int j = 0; j < numBlocks; ++j)
            cin >> kens[j];
        sort(naomis.begin(), naomis.end());
        sort(kens.begin(), kens.end());
        int normal = war(naomis, kens);
        int decietful = d_war(naomis, kens);
        cout << "Case #" << i+1 << ": " << decietful << " " << normal << endl;
    }

    return 0;
}
