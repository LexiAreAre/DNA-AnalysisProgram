#pragma once

#include"lib/json.hpp"
#include"Patient.h"
#include"DiseasesSequences.h"

using nlohmann::json;


void to_json(json& j, const Patient& p);

void from_json(json& j, Patient& p);

void to_json(json& j, const DiseasesSequences& disease);

void from_json(json& j, DiseasesSequences& disease);


