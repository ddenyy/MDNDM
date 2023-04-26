#include "Artefact_Classes/rare.h"
#include "Artefact_Classes/usually.h"
#include "Artefact_Classes/frequent.h"
#include "Artefact_Classes/artefact.h"


class Cell
{
public:

	Cell() {
		type_cell = "earth";
	    height_hill = 0;
	}


	string getType() {
		return type_cell;
	}

	int getHeightHill()
	{
		return height_hill;
	}

	string getTypeOfArtefact()
	{
		  if(is_rare_artefact)
		  {
			return "rare";
		  }
		  if (is_usually_artefact) {
			return "usually";
		  }
		  if (is_frequent_artefact) {
				return "frequent";
		  }
	}

	void setRareArtifact(rare new_artifact) {
		this->rare_artefact = new_artifact;
		is_rare_artefact = true;
		is_usually_artefact = false;
		is_frequent_artefact = false;
	}

	void setUsuallyArtifact(usually new_artifact) {
		this->usually_artefact = new_artifact;
		is_rare_artefact = false;
		is_usually_artefact = true;
		is_frequent_artefact = false;
	}

	void setFrequentArtifact(frequent new_artifact) {
		this->frequent_artefact = new_artifact;
		is_rare_artefact = false;
		is_usually_artefact = false;
		is_frequent_artefact = true;
	}

	void setType(string type_cell)
	{
		this->type_cell = type_cell;
	}

	void setHeight(int height_hill)
	{
//		if (this->type_cell == "hill")
//		{
			this->height_hill = height_hill;
//		}
//		else
//		{
//			this->height_hill = 0;
//		}
	}

private:
	string type_cell;
	int height_hill;

	rare rare_artefact;
	usually usually_artefact;
	frequent frequent_artefact;

	bool is_rare_artefact = false;
	bool is_usually_artefact = false;
	bool is_frequent_artefact = false;

};
