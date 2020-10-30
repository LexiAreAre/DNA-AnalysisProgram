#include"JSONTranformer.h"

void to_json(json& j, const Patient& p) {

	j = json{ {"ID", p.getId()},
			{"Name", p.getName()},
			{"Phone", p.getTelephone()},
			{"Email", p.getEmail()},
			{"DNASequence", p.getADNsequence()} };

}

void from_json(json& j, Patient& p) {
	p.setId(j.at("ID").get<std::string>());
	p.setName(j.at("Name").get<std::string>());
	p.setTelephone(j.at("Phone").get<std::string>());
	p.setEmail(j.at("Email").get<std::string>());
	p.setADNsequence(j.at("DNASequence").get<std::string>());
}

void to_json(json& j, const DiseasesSequences& disease) {

	j = json{ {"disease", disease.getDisease()}, {"sequence", disease.getDiseaseSequence()} };

}

void from_json(json& j, DiseasesSequences& disease) {
	disease.setDisease(j.at("disease").get<std::string>());
	disease.setDiseaseSequence(j.at("sequence").get<std::string>());
}