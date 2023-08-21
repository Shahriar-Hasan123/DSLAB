#include <bits/stdc++.h>
using namespace std;
int visited[100];
int visited2[100];
vector<int>graph[100];
void dfs(int vertex)
{
    visited[vertex]=1;
    cout<<(char)(vertex+64)<<" ";
    for(int i:graph[vertex])
    {
        if(visited[i])
            continue;
        dfs(i);
    }
}
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visited2[source]=1;
    while(!q.empty())
    {
        int cur_v=q.front();
        cout<<(char)(cur_v+64)<<" ";
        q.pop();
        for(int i:graph[cur_v])
        {
            if(!visited2[i]){
              q.push(i);
              visited2[i]=1;
            }
        }
    }


}
int main()
{
	int n,e;
	cout<<"Number of nodes: ";
	cin>>n;
	cout<<"Number of edges: ";
	cin>>e;
    for(int i=0;i<e;i++)
    {
    	char a,b;
    	cin>>a>>b;
        int x=a-64,y=b-64;
    	graph[x].push_back(y);
       // graph[b].push_back(a);
    }
    cout<<endl;
    cout<<"Print Grpah: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" : ";
    	for(auto j:graph[i])
    	cout<<j<<" ";
        cout<<endl;
    }
    cout<<"Traversing using dfs : ";
    dfs(1);
    cout<<endl;
    cout<<"Traversing using bfs: ";
    bfs(1);












   return 0; 
}
 /*
0 0 0 1 
1 0 1 1 
1 0 0 1 
0 0 1 0

 */