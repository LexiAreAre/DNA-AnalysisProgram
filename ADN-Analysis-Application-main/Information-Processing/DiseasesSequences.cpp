#include "DiseasesSequences.h"
DiseasesSequences::DiseasesSequences(std::string disease, std::string sequence)
{
	this->disease = disease;
	this->diseaseSequence = sequence;
}
std::string DiseasesSequences::getDisease() const{
    return disease;
}

void DiseasesSequences::setDisease(std::string disease){
    this->disease = disease;
}

std::string DiseasesSequences::getDiseaseSequence() const{
    return diseaseSequence;
}

void DiseasesSequences::setDiseaseSequence(std::string diseaseSequence){
    this->diseaseSequence = diseaseSequence;
}

