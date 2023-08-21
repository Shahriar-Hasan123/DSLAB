#include <bits/stdc++.h>
using namespace std;
int heap[100],size=0;
void insert(int value)
{
    size++;
    int index=size;
    heap[index]=value;
    while(index>1)
    {
    	int parent=index/2;
    	if(heap[parent]<heap[index])
    	{
    		swap(heap[parent],heap[index]);
    		index=parent;
    	}
    	else
    	return;
    }

}
void deleteRoot()
{
  if(size==0)
  {
    cout<<"Heap is empty!"<<endl;
    return;
  }
  heap[1]=heap[size];
  size--;
  int i=1;
  while(i<size)
  {
    int left=2*i,right=2*i+1;
    if(left<=size && heap[left]>heap[i])
    {
      swap(heap[left],heap[i]);
      i=left;
    }
    else if(right<=size && heap[right]>heap[i])
    {
      swap(heap[right],heap[i]);
      i=right;
    }
    else return;

  }
}
void printHeap()
{
	for(int i=1;i<=size;i++)
	cout<<heap[i]<<" ";
	cout<<endl;
}
int main()
{
   heap[0]=-1;
   insert(8);
   insert(7);
   insert(3);
   insert(6);
   insert(5);
   insert(4);
   insert(2);
   
   printHeap();

   //Delation...........
   deleteRoot();
   printHeap();


}