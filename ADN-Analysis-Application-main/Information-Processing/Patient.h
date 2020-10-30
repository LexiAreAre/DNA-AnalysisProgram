#pragma once
#include<vector>
#include<iostream>
#include<sstream>
#include"DiseasesSequences.h"
class Patient
{
private:
	std::string id;
	std::string name;
	std::string telephone;
	std::string email;
	std::string ADNsequence;

    std::vector<DiseasesSequences*>* diseases;
    
public:
	Patient(std::string id, std::string name, std::string telephone, std::string email, std::string sequence, std::vector<DiseasesSequences*>* d);
    Patient() = default;

    std::string getId() const;
    void setId(std::string id);

    std::string getName() const;
    void setName(std::string name);

    std::string getTelephone() const;
    void setTelephone(std::string telephone);

    std::string getEmail() const;
    void setEmail(std::string email);

    std::string getADNsequence() const;
    void setADNsequence(std::string ADNsequence);

    void addDisease(DiseasesSequences* disease);

    std::string toString();
};

