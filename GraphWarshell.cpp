#include <bits/stdc++.h>
using namespace std;
#define N 4
#define INF 10000
void ShortestPath_warshell(int matrix[][N])
{
    int graph[N][N];
    for(int i=0;i<N;i++)
    	for(int j=0;j<N;j++)
    		graph[i][j]=matrix[i][j];

    for(int k=0;k<N;k++)
    {
    	for(int i=0;i<N;i++)
    	{
    		for(int j=0;j<N;j++)
    		{
    			if(graph[i][j]>graph[i][k]+graph[k][j])
    				graph[i][j]=graph[i][k]+graph[k][j];
    		}
    	}
    }

    //Print shortest path matrix
    for(int i=0;i<N;i++)
    {
    	for(int j=0;j<N;j++)
    	{
            if(graph[i][j]==INF)
                cout<<"INF";
            else
                cout<<graph[i][j];
            cout<<" ";
        }
    	cout<<endl;
    }
}
int n,e;
int main()
{
   int matrix[N][N]={{7,5,INF,INF},{7,INF,INF,2},
                     {INF,3,INF,INF},{4,INF,1,INF}};
     ShortestPath_warshell(matrix);


}
