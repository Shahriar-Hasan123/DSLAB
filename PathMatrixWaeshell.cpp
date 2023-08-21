#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
    cout<<"Number of nodes: ";
    cin>>n;
    int matrix[n][n];
    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    		cin>>matrix[i][j];

    cout<<"Print W0 matrix: "<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int k=0;k<n;k++)
    {
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		   matrix[i][j]=matrix[i][j]|(matrix[i][k]&matrix[k][j]);
    	}
    }
    cout<<"Path matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
             cout<<matrix[i][j]<<" ";
    	}
    	cout<<endl;
    }



return 0;
}