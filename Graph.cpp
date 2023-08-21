#include<bits/stdc++.h>
using namespace std;
int e,n;
#define N 100
void power(int m[][N],int m1[][N],int g[][N])
{
	for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
   	    g[i][j]=0;
   	    for(int k=0;k<n;k++)
   	     g[i][j]+=m[i][k]*m1[k][j];
     }
   }
   
}
void printMatrix(int a[][N])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
void enterZero(int a[][N])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=0;
}
int strongly_Connected(int m[][N],int m2[][N],int m3[][N],int m4[][N])
{
	int flag=0;
    for(int i=0;i<n;i++){
 	  for(int j=0;j<n;j++){
       int ch=m[i][j]+m2[i][j]+m3[i][j]+m4[i][j];
       cout<<ch<<" ";
       if(!ch)flag=1;
      }
      cout<<endl;
   }
    
  return flag;
}
int main()
{
 cout<<"Number of Nodes: ";
 cin>>n;
 cout<<"Number of edges: ";
 cin>>e;

  int m[N][N];
  enterZero(m);
 cout<<"Enter edges: "<<endl;
 for(int i=0;i<e;i++)       
 {
 	int a,b;
 	cin>>a>>b;
    m[a][b]=1;
 }
 printMatrix(m);

 //No of length 2
 int m2[N][N];
 enterZero(m2);
 power(m,m,m2);
 cout<<"Number of path of length 2"<<endl;
 printMatrix(m2);

 //No of length 3
 int m3[N][N];
 enterZero(m3);
 power(m2,m,m3);
 cout<<"Number of Path of length 3"<<endl;
 printMatrix(m3);


//No of length 4
 int m4[N][N];
 enterZero(m4);
 power(m3,m,m4);
 cout<<"Number of Path of length 4"<<endl;
 printMatrix(m4);

//Checking Strongly connected on not
 cout<<"Check Strongly connected:"<<endl;
 if(strongly_Connected(m,m2,m3,m4))
 	cout<<"\nThe Graph is not strongly connected"<<endl;
 else
 	cout<<"The Graph is strongly connected"<<endl;









}
/*
0 1
0 4
1 4
1 3
1 2
2 3
3 4


0 1
1 2
1 3
3 0
3 2
3 3
	*/