#pragma once
#include<fstream>
#include<sstream>
#include"CSVTransformer.h"
#include "IWritter.h"
template<class T>
class CSVWriter :
    public IWritter<T> 
{
private:
    fstream out;
    ICSVTransformer<T>* converter;
    std::string makeRegistry(std::vector<std::string>* fields)
    {
        auto begin = fields->begin();
        auto end = fields->end();
        std::stringstream s;
        if (begin != end)
        {
            s << *begin++;
        }
        while (begin != end)
        {
            s << ",";
            s << *begin++;
        }
        s << std::endl;
        return s.str();
    }
public:
    template<class T>
    CSVWriter(std::string path, ICSVTransformer<T>* converter)
    {
        this->converter = converter;
        this->out.open(path, std::ios::out);
        if (!this->out.good())
        {
            throw std::invalid_argument("Error finding file path");
        }
    }

    void write(T element) override
    {
        std::vector<std::string>* fields = this->converter->toStringVector(element);
        this->out << this->makeRegistry(fields);
        delete fields;
    }

    void writeAll(std::vector<T>* elements) override
    {
        for (auto& current : *elements)
        {
            this->write(current);
        }
    }
    ~CSVWriter()
    {
        this->out.close();
        delete this->converter;
    }
};

