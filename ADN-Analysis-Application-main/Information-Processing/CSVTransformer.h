#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Patient.h"
#include"DiseasesSequences.h"

using namespace std;

template<class T>
class CSVTransformer
{
public:
    virtual vector<string>* toStringVector(T) = 0;
    virtual T fromStringVector(vector<string>*) = 0;
    virtual ~CSVTransformer() = default;
};


class PatientCSVTransformer : public CSVTransformer<Patient*>
{
public:
    vector<string>* toStringVector(Patient* elemento) override
    {
        vector<string>* campos = new vector<string>();
        campos->push_back(elemento->getId());
        campos->push_back(elemento->getName());
        campos->push_back(elemento->getTelephone());
        campos->push_back(elemento->getEmail());
        campos->push_back(elemento->getADNsequence());

        return campos;
    }

    Patient* fromStringVector(vector<string>* vectr) override
    {

        return new Patient(vectr->at(0), vectr->at(1), vectr->at(2), vectr->at(3), vectr->at(4),new vector<DiseasesSequences*>());
    }
};

class DiseaseCSVTransformer : public CSVTransformer<DiseasesSequences*>
{
public:
    vector<string>* toStringVector(DiseasesSequences* disease) override
    {
        vector<string>* fields = new vector<string>();
        fields->push_back(disease->getDisease());
        fields->push_back(disease->getDiseaseSequence());
        return fields;
    }

    DiseasesSequences* fromStringVector(vector<string>* vector) override
    {
        return new DiseasesSequences(vector->at(0), vector->at(1));
    }
};





