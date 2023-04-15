#include "./DanyaArtefact/artefact.h"
#include "./DanyaArtefact/frequent.h"
#include "./DanyaArtefact/rare.h"
#include "./DanyaArtefact/usually.h"

// класс клетки поля, по которой будет ходить робот
class Cell
{

public:
	// стандартный конструктор, типо пустая клетка
	// Все инициализируется стандартным образом.
	// потом при помощи ф-ции рандома Лысого мы будем
	// полностью инициализировать клетку
	Cell()
	{
		type_cell = "earth";
		is_empty_cell = true;
		height_hill = 0;
    }

	// возвращает тип клетки поля земля || холм
	string getType() {
		return type_cell;
	}

	// возвращает высоту клетки поля (по умолчанию 0, иначе клетка стена с высотой)
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

	// устанавливает в клетку новый артифакт типа rare
	void setRareArtifact(rare new_artifact) {
		this->rare_artefact = new_artifact;
		is_rare_artefact = true;
		is_usually_artefact = false;
		is_frequent_artefact = false;
		is_empty_cell = false;

	}

	// устанавливает в клетку новый артифакт типа usually
	void setUsuallyArtifact(usually new_artifact) {
		this->usually_artefact = new_artifact;
		is_rare_artefact = false;
		is_usually_artefact = true;
		is_frequent_artefact = false;
		is_empty_cell = false;
	}
	// устанавливает в клетку новый артифакт типа frequents
	void setFrequentArtifact(frequent new_artifact) {
		this->frequent_artefact = new_artifact;
		is_rare_artefact = false;
		is_usually_artefact = false;
		is_frequent_artefact = true;
		is_empty_cell = false;
	}

	// устанавливает тип клетки
	void setType(string type_cell)
	{
		this->type_cell = type_cell;
	}

	// если клетка типа холм, можно установить ей высоту
	void setHeight(int height_hill)
	{
		if (this->type_cell == "hill")
		{
			this->height_hill = height_hill;
		}
		else
		{
			this->height_hill = 0;
		}
	}

    TCube *ground;

private:
	string type_cell;
	int height_hill;
	// лысый писал классы с маленькой буквы rare usually frequent
	rare rare_artefact;
	usually usually_artefact;
	frequent frequent_artefact;

	// костыль чтобы определять какой артефакт лежит в клетке
	bool is_rare_artefact = false;
	bool is_usually_artefact = false;
	bool is_frequent_artefact = false;
	bool is_empty_cell = false;



};
