#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
 
void printAllPathsUtil(int u, int d, bool vis[],int path[], int& path_index,vector< vector<int> > &edge,vector< vector<int> > &lt, vector< vector<int> > &cap,int &tot,int &mn)
{
    // Mark the current node and store it in path[]
    vis[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print path[]
    if (u == d) {
        for (int i = 0; i < path_index; i++){
            cout << path[i] << " ";
        }
        cout<< tot << " " << mn;
        cout << endl;
    }
    else // If current vertex is not destination recur to next node
    {
        int t=edge[u].size();
        for (int i=0;i<t;i++)
            if (!vis[i]){
                tot=tot+lt[u][i];
                printAllPathsUtil(edge[u][i], d, vis, path,path_index,edge,lt,cap,tot,mn);
            }
    }
    // Remove current vertex from path[] and mark it as unvisited(back traking)
    path_index--;
    vis[u] = false;
}

// Prints all paths from 's' to 'd'
void printAllPaths(int s, int d,int n,vector< vector<int> > &edge,vector< vector<int> > &lt, vector< vector<int> > &cap,int &tot,int &mn)
{
    bool vis[n];
    // Create an array to store paths
    int path[n];
    int path_index = 0;
 
    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++){
        vis[i] = false;
    }
 
    // Call the recursive function
    printAllPathsUtil(s, d, vis, path, path_index,edge,lt,cap,tot,mn);
}



int main()
{
    int n=7;
    vector< vector<int> > edge={{0},{2,3},{3,4,5},{4,5},{6},{4,6}};
    vector< vector<int> > lt={{0},{4,1},{5,3,1},{6,3},{2},{1,4}};
    vector< vector<int> > cap={{0},{3,1},{3,2,2},{2,3},{2},{2,2}};
    int s = 1, d = 6;
    cout << "Following are all different paths from " << s << " to " << d << endl;
    int tot=0;
    int mn=INT_MAX;
    printAllPaths(s, d, n, edge ,lt ,cap,tot,mn);
 
    return 0;
}