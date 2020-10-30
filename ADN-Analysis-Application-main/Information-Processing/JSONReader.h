#pragma once
#include<fstream>
#include<vector>
#include"lib/json.hpp"
#include "IReader.h"
#include"JSONTranformer.h"

using nlohmann::json;
template <class T>
class JSONReader : public IReader<T>{
private:
	std::fstream in;
public:
	JSONReader(std::string path)
	{
		this->in.open(path, std::ios::in);
		if (!in.good())
		{
			throw std::invalid_argument("Error: File could not be open");
		}
	}

	std::vector<T>* read() override
	{
		json jsonFile;
		this->in >> jsonFile;
		std::vector<T>* data = new std::vector<T>();
		*data = jsonFile.get<std::vector<T>>();
		return data;
	}

	~JSONReader()
	{
		this->in.close();
	}
};

