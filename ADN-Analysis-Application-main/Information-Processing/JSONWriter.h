#pragma once
#include <fstream>
#include "JSONTranformer.h"
#include "IWritter.h"
#include "lib/json.hpp"

using nlohmann::json;

template <class T>
class JSONWriter : public IWritter<T>{

private:
	std::string rutaArchivo;
	json modeloJson;

public:
	JSONWriter(std::string rutaArchivo) : modeloJson(json::array()){
		this->rutaArchivo = rutaArchivo;
	}


	void write(T elemento) override{
		json elementoJson = elemento;
		this->modeloJson.pushBack(elementoJson);
	}


	void writeAll(std::vector<T>* elements){
		for(auto& actual : *elements){
			this->write(actual);

		}
	}
	~JSONWriter(){
		std::ofstream out;
		out.open(this->rutaArchivo, std::ios::out);
		if (!out.good())
		{
			throw std::invalid_argument("Ruta del archivo no es valida o no hay permisos.");
		}
		out << modeloJson;
	}
};

