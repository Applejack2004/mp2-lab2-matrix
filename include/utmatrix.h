// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class T>
class TVector
{
protected:
	T* pVector;
	int Size;       // размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	
	TVector(int s = 10, int si = 0);
	TVector(const TVector& v);                // конструктор копирования
	~TVector();
	T* Get_pVector()
	{
		return pVector;
	}
	int GetSize() { return Size; } // размер вектора
	int GetStartIndex() { return StartIndex; } // индекс первого элемента
	T& operator[](int pos);             // доступ
	bool operator==(const TVector& v) const;  // сравнение
	bool operator!=(const TVector& v) const;  // сравнение
	TVector& operator=(const TVector& v);     // присваивание

	// скалярные операции
	TVector  operator+(const T& val);   // прибавить скаляр
	TVector  operator-(const T& val);   // вычесть скаляр
	TVector  operator*(const T& val);   // умножить на скаляр

	// векторные операции
	TVector  operator+(const TVector& v);     // сложение
	TVector  operator-(const TVector& v);     // вычитание
	T  operator*(const TVector& v);     // скалярное произведение

	// ввод-вывод
	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i] << ' ';
		return out;
	}
};

template <class T>
TVector<T>::TVector(int s, int si)
{

	if (s < 0 || s) > MAX_VECTOR_SIZE)
	throw s;
	Size = s;
	StartIndex = si;
	pVector = new T[Size];
	for (int i; i < Size; i++)
	{
		pVector[i] = 0;

	}

}

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T>& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new T[Size];
	std::copy(v.pVector, v.pVector + (Size), pVector);
}

template <class T>
TVector<T>::~TVector()
{
	delete[] pVector;
}

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{

	if (pos - StartIndex) < 0 || (pos - StartIndex) > MAX_VECTOR_SIZE)
	throw s;
	return pVector[pos - StartIndex];
}

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
	if ((Size) != (v.Size))
	{
		return false;
	}
	for (int i = 0; i < Size; i++)
	{
		if (v[i] != this[i])
		{
			return false;

		}

	}
	return true;
}

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector& v) const
{
	return !(this == v);
}

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector& v)
{
	if (pVector != v.pVector)
	{
		if ((v.Size) != (Size))
		{
			delete[] pVector;
			pVector = new T[v.Size];
			Size = v.Size;
			StartIndex = v.StartIndex;
		}
		for (int i; i < Size; i++)
		{
			pVector[i] = v.pVector[i];

		}
	}
	return *this;
}

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T& val)
{

	TVector<T> res(Size);
	for (int i = 0; i < Size; i++)
	{
		Res[i] = val + this[i];
	}
	return res;
}


template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T& val)
{
	TVector<T> res(Size);
	for (int i = 0; i < Size; i++)
	{
		Res[i] = val - this[i];
	}
	return res;
}

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T& val)
{
	TVector<T> res(Size);
	for (int i = 0; i < Size; i++)
	{
		Res[i] = val * this[i];
	}
	return res;
}

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
	if (Size != v.Size)
	{
		throw "not equal size";
	}
	TVector<T> res(Size);
	for (int i = 0; i < Size; i++)
	{
		Res[i] = v[i] + this[i];
	}
	return res;
}

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
	if (Size != v.Size)
	{
		throw "not equal size";
	}
	TVector<T> res(Size);
	for (int i = 0; i < Size; i++)
	{
		Res[i] = v[i] - this[i];
	}
	return res;
}

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T>& v)
{
	if (Size != v.Size)
	{
		throw "not equal size";
	}
	T res;
	for (int i = 0; i < Size; i++)
	{
		res = v[i] * this[i];
	}
	return res;
}

// Верхнетреугольная матрица
template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt);                    // копирование
	TMatrix(const TVector<TVector<T> >& mt); // преобразование типа
	bool operator==(const TMatrix& mt) const;      // сравнение
	bool operator!=(const TMatrix& mt) const;      // сравнение
	TMatrix& operator= (const TMatrix& mt);        // присваивание
	TMatrix  operator+ (const TMatrix& mt);        // сложение
	TMatrix  operator- (const TMatrix& mt);        // вычитание

	// ввод / вывод
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};

template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T> >(s)
{
} /*-------------------------------------------------------------------------*/

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T>& mt) :
	TVector<TVector<T> >(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) :
	TVector<TVector<T> >(mt) {}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T>& mt) const
{
	return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T>& mt) const
{
	return true;
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& mt)
{
	return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
	return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
	return *this;

} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
