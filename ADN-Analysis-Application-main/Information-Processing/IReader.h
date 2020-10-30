#pragma once
#include<vector>
template<class T>
class IReader
{
public:
	virtual std::vector<T>* read() = 0;
	virtual ~IReader() = default;
};

