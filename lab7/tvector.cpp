#include "tvector.h"

template TVector<Rectangle>;
template TVector<Rhombus>;
template TVector<Trapezoid>;

template <class T> TVector<T>::TVector()
{
	real_size = 0;
	size_of_memory = 1;
	arr = new T[size_of_memory];
}

template<class T> TVector<T>::TVector(T t)
{
	real_size = size_of_memory = 1;
	arr = new T[size_of_memory];
	arr[0] = t;
}

template <class T> void TVector<T>::Realloc(bool increase)
{
	double value;
	if (increase)
	{
		value = 2;
	}
	else
	{
		value = 0.5;
	}
	T* aux_arr = new T[int(size_of_memory * value)];
	for (int i = 0; i < real_size; i++)
	{
		aux_arr[i] = this->arr[i];
	}
	delete[] arr;
	this->arr = new T[int(size_of_memory * value)];
	for (int i = 0; i < real_size; i++)
	{
		this->arr[i] = aux_arr[i];
	}
	size_of_memory = int(size_of_memory * value);
	delete[] aux_arr;
}

template <class T> void TVector<T>::Move(int index, bool forward, int stop, bool updating, T t)
{
	if (forward)
	{
		if (real_size == size_of_memory)
		{
			Realloc(forward);
		}
		for (int i = stop; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		if (!updating)
		{
			++real_size;
		}
		arr[index] = t;
	}
	else
	{
		for (int i = index; i < stop - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		if (!updating)
		{
			--real_size;
		}
		if ((real_size * 2) == size_of_memory)
		{
			Realloc(forward);
		}
	}
}

template <class T> int TVector<T>::LowerBound(T t)
{
	int l = 0, r = real_size, m;
	while (l < r)
	{
		m = l + (r - l) / 2;
		if (!(arr[m] < t))
		{
			r = m;
		}
		else
		{
			l = m + 1;
		}
	}
	return l;
}

template <class T> void TVector<T>::AppendElement(T t)
{
	if (!real_size)
	{
		if (!size_of_memory)
		{
			arr = new T[++size_of_memory];
		}
		arr[0] = t;
		++real_size;
	}
	else
	{
		//double square = t.Square();
		int index = LowerBound(t);
		Move(index, true, real_size, false, t);
	}
}

/*
template <class T> int TVector<T>::BinarySearch(T t)
{
	int l = -1, r = real_size, m
	while (l < r - 1)
	{
		m = (l + r) / 2;
		if (arr[m] < t)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	return ((r < real_size) && (arr[r] == t)) ? r : -1;
}
*/
template <class T> void TVector<T>::DeleteElement(int index)
{
	if (index >= real_size)
	{
		std::cout << "There's no such element in vector\n";
		return;
	}
	if (real_size == 1)
	{
		real_size = size_of_memory = 0;
		delete[] arr;
		arr = nullptr;
		return;
	}
	Move(index, false, real_size, false);
}

template <class T> void TVector<T>::Delete()
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
	real_size = size_of_memory = 0;
}

template <class T> void TVector<T>::Update(T t, int index)
{
	if ((!index) && (!real_size))
	{
		++real_size;
		arr[index] = t;
		return;
	}
	if (index >= real_size)
	{
		std::cout << "There's no such element in vector\n";
		return;
	}
	else
	{
		int new_index = LowerBound(t);
		if ((new_index >= index) && (index + 1 >= new_index))
		{
			arr[index] = t;
			return;
		}
		else if (new_index < index)
		{
			Move(new_index, true, index, true, t);
		}
		else
		{
			Move(index, false, new_index, true);
			arr[new_index - 1] = t;
		}
	}
}


template <typename T> void TVector<T>::operator= (const TVector<T>& tvector)
{
	if (arr)
	{
		delete[] arr;
	}
	real_size = tvector.real_size;
	size_of_memory = tvector.size_of_memory;
	arr = new T[size_of_memory];
	for (int i = 0; i < real_size; i++)
	{
		arr[i] = tvector.arr[i];
	}
}

template std::ostream& operator<<(std::ostream& os, const TVector<Rectangle>& tvector);
template std::ostream& operator<<(std::ostream& os, const TVector<Rhombus>& tvector);
template std::ostream& operator<<(std::ostream& os, const TVector<Trapezoid>& tvector);

template <typename T> std::ostream& operator<< (std::ostream& os, const TVector<T>& tvector)
{
	os << "{";
	for (int i = 0; i < tvector.real_size - 1; i++)
	{
		os << tvector.arr[i] << "; ";
	}
	if (tvector.real_size)
	{
		os << tvector.arr[tvector.real_size - 1];
	}
	os << "}";
	return os;
}

template <class T> TVector<T>::~TVector()
{
	
}

/*
   TVector<Rectangle> v;
   v.AppendElement(Rectangle(std::cin));
   v.DeleteElement(2);
   v.AppendElement(Rectangle(std::cin));
   v.AppendElement(Rectangle(std::cin));
   std::cout << v << "\n";
   v.AppendElement(Rectangle(std::cin));
   v.AppendElement(Rectangle(std::cin));
   v.AppendElement(Rectangle(std::cin));
   std::cout << v << "\n";
   v.DeleteElement(1);
   std::cout << v << "\n";
   v.AppendElement(Rectangle(std::cin));
   TVector<Rectangle> v2;
   v2 = v;
   std::cout << "v2 : " << v2 << "\n";
   std::cout << v << "\n";

   v.Update(Rectangle(std::cin), 0);
   std::cout << v << "\n";
   v.Update(Rectangle(std::cin), 4);
   std::cout << v << "\n";
   v.Update(Rectangle(std::cin), 3);
   std::cout << v << "\n";




   v.DeleteElement(4);
   std::cout << v << "\n";
   v.DeleteElement(1);
   std::cout << v << "\n";
   v.DeleteElement(1);
   std::cout << v << "\n";
   v.DeleteElement(1);
   std::cout << v << "\n";
   v.DeleteElement(1);
   std::cout << v << "\n";
   v.DeleteElement(0);
   std::cout << v << "\n";
   v.AppendElement(Rectangle(std::cin));
   std::cout << v << "\n";

   v2.Delete();
   std::cout  << "v2 : " << v2 << "\n";*/