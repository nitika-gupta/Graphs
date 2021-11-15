#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int> adj[]){
    vector<int> bfs;
    vector<int> visited(n+1,0);

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i]=1;

            while(!q.empty()){
                int x=q.front();
                q.pop();
                bfs.push_back(x);

                for( auto it: adj[x]){
                   if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                   }
                }

            }

        }
    }
    for(int i=0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
    }

}

int main(){


    int n,m;
    cin>>n>>m;
    

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

   /* for(int i=0;i<n+1;i++){
        cout<<"vertex "<<i<<" has the edges : ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }*/

   bfs(n,adj);
  


    return 0;
}