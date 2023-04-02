#include "Artifact.h"

// ����� ������ ����, �� ������� ����� ������ �����
class Cell
{

public:

	// �����������
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

	// ���������� ��� ������ ����
	string getType() {
		return type_cell;
	}

	// ���������� ������ ������ ���� (�� ��������� 0, ����� ������ ����� � �������)
	int getHeightHill()
	{
		return height_hill;
	}

	// ������������� � ������ ����� ��������
	void setArtifact(Artifact new_artifact) {
		this->artifact = new_artifact;
	}

	// ������������� ��� ������
	void setType(string type_cell)
	{
		this->type_cell = type_cell;
	}

	// ���� ������ ���� ����, ����� ���������� �� ������
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
