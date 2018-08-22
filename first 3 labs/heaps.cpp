#include<iostream>
#include<cstdlib>

using namespace std;


void swap(int* a,int* b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}


void max_heapify(int a[],int p,int n)
{
	int left=2*p;
	int right=2*p+1;
	int largest;
	if(left<=n && a[left]>a[p])
		largest=left;
	else
		largest=p;
	if(right<=n && a[right]>largest)
		largest=right;
	if(largest!=p)
	{
		swap(&a[p],&a[largest]);
		max_heapify(a,largest,n);
	}
}


void build_max_heap(int a[],int n)
{
	for(int i=n/2;i>0;i--)
	{
		max_heapify(a,i,n);
	}
}


void min_heapify(int a[],int i,int n)
{
	int left=2*i;
	int right=2*i+1;
	int smallest;
	if(left<=n && a[left]<a[i])
		smallest=left;
	else
		smallest=i;
	if(right<=n && a[right]<smallest)
		smallest=right;
	if(smallest!=i)
	{
		swap(&a[smallest],&a[i]);
		min_heapify(a,smallest,n);
	}
}


void build_min_heap(int a[],int n)
{
	for(int i=n/2;i>0;i--)
	{
		min_heapify(a,i,n);
	}
}

void sorting_heap(int a[],int n)//can use min_heapify but need to pass starting point as well
{
	build_max_heap(a,n);
	//int h=n;
	for(int i=1;i<=n;i++)
	{
		//cout<<a[i]<<"    "<<b[i]<<"   "<<c[i]<<endl;
		cout<<a[i]<<" $ ";
		
	}
	cout<<endl;
	for(int i=n;i>=2;i--)
	{
		swap(&a[1],&a[i]);
		//h=h-1;
		max_heapify(a,1,i-1);
		for(int i=1;i<=n;i++)
	{
		//cout<<a[i]<<"    "<<b[i]<<"   "<<c[i]<<endl;
		cout<<a[i]<<"  ";
		
	}
	cout<<endl;
		//build_max_heap(a,i-1);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	int b[100];
	int c[100];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		c[i]=a[i];
	}
	build_max_heap(a,n);
	build_min_heap(b,n);
	sorting_heap(c,n);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"    "<<b[i]<<"   "<<c[i]<<endl;
		//cout<<c[i]<<"  ";
		
	}

	return 0;
}