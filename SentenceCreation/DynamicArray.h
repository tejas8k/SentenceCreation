#pragma once
#include <cassert>

class DynamicStringArray {
private:
	size_t size;
	size_t capacity;

	char** strings = nullptr;

	void resize(size_t newCapacity)
	{
		auto newStrings = new char* [newCapacity];
		assert(newCapacity > size);
		for (int i = 0; i < size; i++) {
			newStrings[i] = strings[i];
		}
		delete[] strings;
		strings = newStrings;
		capacity = newCapacity;
	}
public:
	DynamicStringArray(): size(0), capacity(0)
	{
		resize(2);
	}

	void push_back(char* str) 
	{
		if (capacity == size) {
			resize(size + size / 2);
		}
		strings[size++] = str;
	}

	char* pop_back()
	{
		if (size == 0) return nullptr;
		size--;
		return strings[size];
	}

	size_t Size() const 
	{
		return size;
	}

	char*& operator[](size_t index) const
	{
		if (index >= size) {
			assert(false);
		}
		return strings[index];
	}
};