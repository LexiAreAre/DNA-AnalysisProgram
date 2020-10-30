#include "Patient.h"

Patient::Patient(std::string id, std::string name, std::string telephone, std::string email, std::string sequence, std::vector<DiseasesSequences*>* d)
{
	this->id = id;
	this->name = name;
	this->telephone = telephone;
	this->email = email;
	this->ADNsequence = sequence;
    this->diseases = d;
}

std::string Patient::getId() const
{
    return id;
}

void Patient::setId(std::string id)
{
    this->id = id;
}

std::string Patient::getName() const
{
    return name;
}

void Patient::setName(std::string name)
{
    this->name = name;
}

std::string Patient::getTelephone() const
{
    return telephone;
}

void Patient::setTelephone(std::string telephone)
{
    this->telephone = telephone;
}

std::string Patient::getEmail() const
{
    return email;
}

void Patient::setEmail(std::string email)
{
    this->email = email;
}

std::string Patient::getADNsequence() const
{
    return ADNsequence;
}

void Patient::setADNsequence(std::string ADNsequence)
{
    this->ADNsequence = ADNsequence;
}

void Patient::addDisease(DiseasesSequences& disease){
    this->diseases->push_back(&disease);
}

std::string Patient::toString()
{
    std::stringstream ss;
    for (auto& ite : *this->diseases)
    {
        ss << "Disease: " << ite->getDisease() << std::endl;
        ss << "Sequence: " << ite->getDiseaseSequence() << std::endl;
    }
    return ss.str();
}