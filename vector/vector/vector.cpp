#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<algorithm>
#include<assert.h>
#include<stdlib.h>
#include<vector>
#if 0
using namespace std;
template<class T>

class Vector
{
public:
	typedef T*  iterator;
	typedef const T*  const_iterator;
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{

	}
	void PushBack(const T& val)
	{
		if (_finish == _eos)
		{
			size_t newc = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newc);
		}
		*_finish = val;
		_finish++;
	}
	size_t Capacity()
	{
		return _eos - _start;
	}
	void Reserve(size_t n)
	{
		int size = Size();
		if (n > Capacity())
		{
			T * tmp = new T[n];
			memcpy(tmp, _start, sizeof(T)*size);
			for (int i = 0; i < size; i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;
			_start = tmp;
			_finish = _start + size;
			_eos = _start + n;
		}
	}
	size_t Size()
	{
		return _finish - _start;
	}
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}
	iterator begin()
	{
		return _start;
	}
	const_iterator begin() const
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator end()const
	{
		return _finish;
	}
	void InSert(iterator pos, const T& val)
	{
		int len = pos - _start;
		assert(pos >= begin() && pos <= end());
		if (_finish == _eos)
		{
			size_t newc = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newc);
		}
		iterator end = _finsh;
		while (end > pos)
		{
			*end = *(end - 1);
			end--;
		}
		pos = _start + len;
		*pos = val;
		_finish++; 

	}
	void Erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		while (pos < _finish - 1)
		{
			*pos = *(pos + 1);
			pos++;
		}
		_finish--;
	}
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			PushBack(*first);
			++first;


		}
	}
	void Resize(size_t n,const T& val = T())
	{
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
				Reserve(n);
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
			
		}
	}
	void PopBack()
	{
		Erase(end() - 1);

	}
	Vector(const Vector<T>& vec)
		:_start(nullptr);
	    , _finish(nullptr)
		, _eos(nullptr)
	{


	}
private:
	iterator _start;
	iterator _finish;
	iterator _eos;
};
void test1()
{
	Vector<int> v;
	v.PushBack(1);

}
int main()
{
	test1();
	system("pause");
	return 0;
}
#endif