#pragma once
#include<vector>
#include"Patient.h"
#include"DiseasesSequences.h"
class DiseasesCheckOut {
public:
	static void DNACheckOut(std::vector<Patient*>& patients, std::vector<DiseasesSequences*>& diseases)
	{
		for (auto& pa : patients)
		{
			for (auto& en : diseases)
			{
				if (pa->getADNsequence().find(en->getDiseaseSequence()) != std::string::npos) {
					pa->addDisease(*en);
				}
			}
		}
	}
};