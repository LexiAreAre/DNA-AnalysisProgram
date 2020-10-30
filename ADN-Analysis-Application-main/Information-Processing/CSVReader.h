#pragma once
#include<fstream>
#include<string>
#include<sstream>
#include"IReader.h"
#include"CSVTransformer.h"
template <class T>
class CSVReader:
	public IReader<T>
{
private:
	fstream in;
	CSVTransformer<T>* converter;
	std::vector<std::string>* makeFields(std::string registry)
	{
		std::vector<std::string>* fields = new std::vector<std::string>();
		std::string value;
		std::istringstream iss(registry);
		while (std::getline(iss, value, ','))
		{
			fields->push_back(value);
		}
		return fields;
	}
public:
	template<class T>
	CSVReader(std::string path, CSVTransformer<T>* converter)
	{
		this->converter = converter;
		this->in.open(path, std::ios::in);
		if (!this->in.good())
		{
			throw invalid_argument("Error: File could not be open");
		}
	}
	
	std::vector<T>* read() override
	{
		std::string registry;
		std::vector<T>* elements = new std::vector<T>();
		while (getline(this->in, registry))
		{
			std::vector<string>* fields = this->makeFields(registry);
			elements->push_back(this->converter->fromStringVector(fields));
			delete fields;
		}
		return elements;
	}
	~CSVReader()
	{
		this->in.close();
		delete this->converter;
	}
};

