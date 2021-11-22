#ifndef TVECTOR_H
#define TVECTOR_H

#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"

template <class T>
class TVector
{
public:
	TVector();
	TVector(T);
	int real_size, size_of_memory;
	T* arr = nullptr;
	void AppendElement(T);
	//int BinarySearch(T);
	void Delete();
	void DeleteElement(int);
	int LowerBound(T);
	void Move(int, bool, int, bool, T = T());
	void Realloc(bool);
	void Update(T, int);
	void operator= (const TVector<T>&);
	template <typename A>
	friend std::ostream& operator<<(std::ostream&, const TVector<A>&);
	~TVector();
};
#endif
