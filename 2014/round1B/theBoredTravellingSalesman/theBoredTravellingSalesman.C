#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

void dfs(map<int, vector<int> > adjList, vector<int> values, set<int> & visited, int current, string & result)
{
    ostringstream ss;
    ss << values[current-1];
    result += ss.str();
    visited.insert(current);

    while(true)
    {
        vector<int> possibleNext;
        for(int i = 0; i < adjList[current].size(); ++i)
        {
            if(visited.find(adjList[current][i]) != visited.end())
                continue;
            possibleNext.push_back(adjList[current][i]);
        }

        if(possibleNext.size() == 0)
            break;

        int best;
        int min = -1;
        for(int i = 0; i < possibleNext.size(); ++i)
        {
            int next = values[possibleNext[i]-1];
            if(min == -1 || next < min)
            {
                min = next;
                best = possibleNext[i];
            }
        }

        dfs(adjList, values, visited, best, result);
    }
}

int main()
{
    int numTests, numNodes, numEdges;
    cin >> numTests;

    for(int t = 0; t < numTests; ++t)
    {
        cin >> numNodes >> numEdges;
        vector<int> values(numNodes);
        map<int, vector<int> > adjList;

        int start;
        int min = -1;
        for(int i = 0; i < numNodes; ++i)
        {
            cin >> values[i];
            if(min == -1 || values[i] < min)
            {
                min = values[i];
                start = i+1;
            }
        }

        int from, to;
        for(int i = 0; i < numEdges; ++i)
        {
            cin >> from >> to;
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        set<int> visited;
        string result = "";
        dfs(adjList, values, visited, start, result);
        cout << result << endl;
    }
    return 0;
}
