#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    int numTests, numNodes, a, b;
    cin >> numTests;

    for(int i = 0; i < numTests; ++i)
    {
        cin >> numNodes;
        map<int, set<int>> adjList(numNodes);
        for(int j = 0; j < numNodes; ++j)
        {
            cin >> a >> b;
            adjList[a-1].insert(b-1);
            adjList[b-1].insert(a-1);
        }

        // prune nodes with a single leaf
        for(int j = 0; j < numNodes; ++j)
        {
            if(adjList[j].size() == 1)
                adjList.erase(j);
        }

        int maxSize = -1;
        map<int, set<int>>::iterator it = adjList.begin(), end = adjList.end();
        for(; it != end; ++it)
        {
            if(it->second.size() == 2)
            {
            }
        }
    }

    return 0;
}
