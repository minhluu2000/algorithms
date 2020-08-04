#pragma once
#include <iostream>
#include <list>
#include <utility>

using namespace std;

template <typename T>
class HashTable
{
private:
	int size;
	list<pair<int, T>> *table;

	int hash(const int _key)
	{
		return _key % size;
	}

public:
	HashTable(const int _size)
	{
		size = _size;
		table = new list<pair<int, T>>[size];
	}

	~HashTable()
	{
		size = 0;
		for (int i = 0; i < size; ++i)
		{
			table[i].clear();
		}
		delete[] table;
	}

	void insert(const int _key, T _value)
	{
		table[hash(_key)].push_back(pair<int, T>(_key, _value));
	}

	int minChainLen()
	{
		if (size == 0)
			return 0;

		int min = table[0].size();
		for (int i = 1; i < size; ++i)
		{
			if (min > table[i].size())
				min = table[i].size();
		}

		return min;
	}

	int maxChainLen()
	{
		if (size == 0)
			return 0;

		int max = table[0].size();
		for (int i = 1; i < size; ++i)
		{
			if (max < table[i].size())
				max = table[i].size();
		}

		return max;
	}

	double averageChainLen()
	{
		if (size == 0)
			return 0;

		double total = 0;
		for (int i = 0; i < size; ++i)
			total += table[i].size();

		return total / size;
	}

	T *search(int _key)
	{
		int index = hash(_key);
		auto iterator = table[index].begin();
		for (; iterator != table[index].end(); ++iterator)
		{
			if (iterator->first == _key)
				return &(iterator->second);
		}
		return nullptr;
	}

	// Additional functions
	void showHash()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i;
			for (auto x : table[i])
				cout << " --> " << x.first << ", " << x.second << " ";
			cout << endl;
		}
	}
};
