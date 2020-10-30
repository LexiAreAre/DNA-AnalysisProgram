#pragma once
#include<vector>
template<class T>
class IWritter
{
public:
	virtual void write(T element) = 0;
	virtual void writeAll(std::vector<T>* elements) = 0;
	virtual ~IWritter() = default;
};

