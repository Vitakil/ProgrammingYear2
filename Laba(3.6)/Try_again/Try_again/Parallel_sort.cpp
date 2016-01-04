#include "Parallel_sort.h"

template<int size>
Parallel_sort<size>::Parallel_sort(int k)
{
	this->k = k;
	srand(0);
	for (int i(0); i < size; i++)
		mas[i] = rand() % 1000;
}


template<int size>
void Parallel_sort<size>::shift_down(int i, int j)
{
	bool done = false;
	int maxChild;
	while ((i * 2 + 1 < j) && (!done))
	{
		if (i * 2 + 1 == j - 1)
			maxChild = i * 2 + 1;
		else if ( m[i * 2 + 1] > m[i * 2 + 2])
			maxChild = i * 2 + 1;
		else
			maxChild = i * 2 + 2;

		if (mas[i] < mas[maxChild])
		{
			swap(mas[i], mas[maxChild]);
			i = maxChild;
		}
		else
			done = true;
	}
}
template<int size>
void Parallel_sort<size>::dhsort(int begin, int end)
{
	int i;
	for (i = end / 2; i >= begin; i--)
		shift_down(i, end);
	for (i = end; i >= begin; i--)
	{
		std::swap(mas[begin], mas[i]);
		shift_down(begin, i);
	}
}
template<int size>
void Parallel_sort<size>::Parallel_hsort()
{
	std::thread *t = new std::thread[k];
	int l = 0, r = size;
	int size_of_peace_mas = size / k;
	for (int i = 0; i < k - 1; i++)
		t[i] = std::thread(&hsort, (size_of_peace_mas*i, size_of_peace_mas*(i + 1)));
	t[k - 1] = std::thread(&hsort, k - 1 * size_of_peace_mas, size - 1);
	for (int i = 0; i < k; i++)
		t[i].join()
	for (int i(0); i < size; i++)
		cout << mas[i] << " ";
	std::system("pause");
}