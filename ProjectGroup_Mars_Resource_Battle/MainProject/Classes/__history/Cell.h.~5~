#include "Artifact.h"

// класс клетки поля, по которой будет ходить робот
class Cell
{

public:

	// конструктор
	Cell(string type_cell = "earth", int height_hill = 0, Artifact artifact = Artifact(0,0,0)) {
		this->type_cell = type_cell;
		this->height_hill = height_hill;
		this->artifact = artifact;
	};

//	~Cell()
//	{
//		this->type_cell.clear();
//		this->height_hill = 0;
//		delete &this->artifact;
//	}

	// возвращает тип клетки поля
	string getType() {
		return type_cell;
	}

	// возвращает высоту клетки поля (по умолчанию 0, иначе клетка стена с высотой)
	int getHeightHill()
	{
		return height_hill;
	}

	// устанавливает в клетку новый артифакт
	void setArtifact(Artifact new_artifact) {
		this->artifact = new_artifact;
	}

	// устанавливает тип клетки
	void setType(string type_cell)
	{
		this->type_cell = type_cell;
	}

	// если клетка типа холм, можно установить ей высоту
	void setHeight(int height_hill)
	{
		if (this->type_cell == "holm")
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
	Artifact artifact;

};
