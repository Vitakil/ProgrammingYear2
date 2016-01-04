#include "Betcher_sort.h"


Betcher_sort::Betcher_sort(vector<int> & One,int n,int k)
{
	vector<thread> threads;
	const int MAX_INT = 200009;
	this->k = pow(2, k);
	size = n + (this->k - (n%this->k));
	for (int i(0); i < size - n; i++)
		One.push_back(MAX_INT);
	int cont = size / this->k;
	
	for (int j = (0); j < this->k; j++)
	{
		threads.push_back(thread(&Betcher_sort::heap_sort, this, ref(One), j*cont, (j + 1)*cont));																																																					
		threads[j].join();
	}
	merge_sort(One, 0, this->k - 1, cont);																																											heap_sort(One, 0, size);
}
void Betcher_sort::merge_sort(vector<int> a, int l, int r,int siz)
{
	vector<thread> threads;
	if ((r - l) == 0) return;
	else 
	{
		for (int i(0); i <= (r - l) / 2; i++)
			threads.push_back(thread(&Betcher_sort::merge, this, ref(a), (l + i)*siz, (l + i)*siz, (r - i )*siz, (r - i)*siz));		
		for (int i(0); i <= (r - l) / 2; i++)
			threads[i].join();
		threads.push_back(thread(&Betcher_sort::merge_sort, this, ref(a), l, (r - l) / 2 + l, siz));
		threads.push_back(thread(&Betcher_sort::merge_sort, this, ref(a), (r - l) / 2 + l + 1, r, siz));
		threads[threads.size() - 2].join();
		threads[threads.size() - 1].join();
	}
}
void Betcher_sort::heap_sort(vector<int> &mass,int  begin,int  end) 
{
	int i;
	int temp;
	int count = end - begin;
	for (i = count / 2 - 1; i >= 0; i--)
	{
		shiftDown(mass, i, count,begin);
	}
	for (i = count - 1; i >= 1; i--)
	{
		temp = mass[begin];
		mass[begin] = mass[i+begin];
		mass[i+begin] = temp;
		shiftDown(mass, 0, i,begin);
	}
}

void Betcher_sort::shiftDown(vector<int> &a, int i, int j,int r)
{
	bool done = false;
	int maxChild;
	int temp;
	while ((i* 2 + 1 < j) && (!done))
	{
		if (i * 2 + 1 == j - 1)
			maxChild = i * 2 + 1;
		else if (a[i * 2 + 1+r] > a[i * 2 + 2+r])
			maxChild = i * 2 + 1;
		else
			maxChild = i * 2 + 2;

		if (a[i+r] < a[maxChild+r])
		{
			temp = a[i+r];
			a[i+r] = a[maxChild+r];
			a[maxChild+r] = temp;
			i = maxChild;
		}
		else
		{
			done = true;
		}
	}
}
void Betcher_sort::merge(vector<int> &a, int low1,  int high1,int low2,int high2)
{
	int i, j, k;vector<int> c;
	c.resize(500);
	i = low1;
	k = 0;
	j = low2;
	while (i <= high1 && j <= high2)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= high1)
	{
		c[k] = a[i];
		k++;
		i++;
		if (k == high1)k = low2;
	}
	while (j <= high2)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	int qw = low1;
	for (int l = 0; l < k; l++)
	{
		a[qw] = c[l]; 
		if (qw==high1) qw = low2;
		else qw++;
	}
}

Betcher_sort::~Betcher_sort()
{
}
