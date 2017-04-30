//
// Created by steven on 30/04/17.
//

// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <string.h>
#include "EdmondsKarp.h"
using namespace std;

// M is number of nodes next to the source and N is the number of nodes next to the sink

// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool** bpGraph, int u, bool seen[], int matchR[], int N, int M)
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited

            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in the above line, matchR[v]
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR, N, M))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number of matching from M to N
int maxBPM(bool** bpGraph, int N, int M)
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];

    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));

    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR, N, M))
            result++;
    }
    return result;
}

// Driver program to test above functions
int find_max_flow(bool** edm, int N, int M)
{
    return maxBPM(edm, N, M);
}