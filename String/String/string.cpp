#define  _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<algorithm>
#include<assert.h>
#include<stdlib.h>
using namespace std;
#if 0
class String
{
public:
	typedef char*  iterator;
	//typedef const char*  (constiterator);
	String(char* str = "")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}
	void Swap(String &str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);

	}
	String(const String& str)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}
	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

	}
	char& operator[](size_t pos)
	{
		if (pos < _size)
		{
			return _str[pos];
		}
		return _str[_size - 1];
	}
	const char& operator[](size_t pos)const
	{
		assert(pos < _size);
		return _str[pos];
	}
	iterator begin()
	{
		return _str;
	}
	const iterator begin()const
	{
		return _str;
	}
	const iterator cbegin() const
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
	const iterator end()const
	{
		return _str + _size;
	}
	const iterator cend()const
	{
		return _str + _size;
	}
	void push_back(char c)
	{
		if (_capacity == _size)
		{
			size_t newc = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newc);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}
	void Append(const char * str)
	{
		int size = strlen(str);
		if (size + _size > _capacity)
		{
			reserve(_size + size);
		}
		strcpy(_str + _size, str);
		_size = _size + size;
	}
	String& operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	String& operator+=(const String& str)
	{
		Append(str._str);
		return *this;
	}
	void insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newc = _capacity == 0 ? 15 : _capacity * 2;
			reserve(newc);
		}
		size_t end = _size;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		++_size;


	}
	void insert(size_t pos, const char *str)
	{
		int sz = strlen(str);
		if (_size + sz > _size)
		{
			reserve(sz + _size);
		}
		size_t end = _size + sz;
		while (end > pos + sz - 1)
		{
			_str[end] = _str[end - sz];
			--end;
		}
		int i = 0;
		while (*str)
		{
			_str[pos + i] = *str++;
			i++;
		}
		_size += sz;
		_str[_size] = '\0';


	}
	size_t size()const
	{
		return _size;
	}
	size_t capacity()
	{
		return _capacity;
	}
	void resize(size_t sz, char c = '\0')
	{
		if (sz > _capacity)
		{
			reserve(sz);
		}
		if (sz > _size)
		{
			memset(_str + _size, c, sz - _size);
		}
		_size = sz;
		_str[_size] = '\0';
	}
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char * tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void erase(size_t pos, int len)
	{
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
			return;
		}
		else
		{
			while (pos + len <= _size)
			{
				_str[pos] = _str[pos + len];
				pos++;
			}
			_size -= len;
		}

	}
	size_t find(const char * str, size_t pos = 0)
	{
		char *start = strstr(_str + pos, str);
		if (start == nullptr) return npos;
		else return start - _str;
	}
	size_t find(char ch, size_t pos = 0)
	{
		for (int i = pos; i < _size; i++)
		{
			if (ch == _str[i])
				return i;
		}
		return npos;
	}
private:
	static const size_t npos;
	char* _str;
	size_t _size;
	size_t _capacity;
};
const size_t String::npos = -1;


int main()
{
	String s("45690");
	s.insert(3, "78");
	s.erase(0, 3);
	system("pause");
	return 0;
}
#endif