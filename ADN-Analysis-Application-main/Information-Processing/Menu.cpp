#include"Menu.h"
#include "JSONWriter.h"

void Menu::MenuPrincipal(){

		bool menu = true;

		std::vector<Patient*>* patients = new std::vector<Patient*>();
		std::vector<DiseasesSequences*>* diseases = new std::vector<DiseasesSequences*>();

		while (menu == true) {

		system("CLS");
		std::cout << "Bienvenidos al programa de carga de datos." << std::endl << std::endl;

		std::cout << "1. Cargar datos del archivo de pacientes.csv" << std::endl;
		std::cout << "2. Cargar datos del archivo de enfermedades.csv" << std::endl;
		std::cout << "3. Generar archivo datos_geneticos.json" << std::endl;
		std::cout << "4. Salir.\n" << std::endl;

		int opcion;
		std::cin >> opcion;

		
			switch (opcion) {
				case 1:
				{
					PatientCSVTransformer* converter = new PatientCSVTransformer();
					IReader<Patient*>* reader = new CSVReader<Patient*>("../csv files/pacientes.csv", converter);
					patients = reader->read();
				
					std::cout << "\nDatos cargados.\n";
					std::cout << "1) Visualizar lista de pacientes.\n\n";
					std::cout << "O cualquier otro valor para volver." << std::endl;

					int opcion2;
					std::cin >> opcion2;

			

					system("CLS");
					if (opcion2 == 1) {
						for (auto& data : *patients)
						{
							std::cout << data->getName() << std::endl;
						}
						system("PAUSE");
					}
				}break;
				case 2:
				{
					
					CSVReader<DiseasesSequences*>* reader = new CSVReader<DiseasesSequences*>("../csv files/enfermedades.csv", new  DiseaseCSVTransformer());
					diseases = reader->read();

					std::cout << "Datos cargados.\n";
					std::cout << "1) Visualizar lista de enfermedades.\n\n";
					std::cout << "O cualquier otro valor para volver." << std::endl;

					int opcion3;
					std::cin >> opcion3;

					system("CLS");
					if (opcion3 == 1) {
						for (auto& data : *diseases)
						{
							std::cout << data->getDisease() << std::endl;
						}
						system("PAUSE");
					}
				}break;

				case 3: {
					// En esta parte se agregan las enfermedades a sus respectivos pacientes

					for (auto& pa : *patients)
					{
						for (auto& en : *diseases)
						{
							if (pa->getADNsequence().find(en->getDiseaseSequence()) != std::string::npos) {
								pa->addDisease(en);
							}
						}
					}			
						
					//Ahora se procede a crear el archivo JSON


					
				}break;

				case 4: 
				{
					std::cout << "\nHasta luego! :)" << std::endl << std::endl;							
					menu = false; 
				}break;
				default: {
					std::cerr << "Dato invalido. " << std::endl;
					system("PAUSE");
				}
			}
		}

		delete patients, diseases;
}
