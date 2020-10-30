#pragma once
#include<iostream>
class DiseasesSequences
{
private:
	std::string disease;
	std::string diseaseSequence;
public:
	DiseasesSequences(std::string disease, std::string sequence);

    std::string getDisease() const;
    void setDisease(std::string disease);

    std::string getDiseaseSequence() const;
    void setDiseaseSequence(std::string diseaseSequence);

};

