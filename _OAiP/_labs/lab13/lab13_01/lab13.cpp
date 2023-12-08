#include "Header.h"
#include <iostream>
#include <iomanip>
void AAA::print()
{
	std::cout << x;
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{

			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}

	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void Heap::scan(int i) const
	{
		for (int j = 0; j < size; j++)
		{
			((AAA*)storage[j])->print();
			std::cout << "  ";
		}
		std::cout << std::endl;
		int probel = 20;
		if (size == 0)
			std::cout << "куча пуста" << std::endl;
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}



	void* Heap::extractMin()
	{
		void* rc = nullptr;
		int l;
		int min = 9999999;
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				if (((AAA*)storage[i])->x < min)
				{
					min = ((AAA*)storage[i])->x;
					rc = storage[i];
					l = i;
				}
			}
			storage[l] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	void* Heap::extractI(int i)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[i];
			storage[i] = storage[size - 1];
			size--;
			heapify(i);
		} return rc;
	}
	void Heap::unionHeap(Heap* h2)
	{
		void* rc = nullptr;
		for (int i = 0; i < h2->size; i++)
		{
			rc = h2->storage[i];
			insert(rc);
		}
		heapify(0);
	}
}