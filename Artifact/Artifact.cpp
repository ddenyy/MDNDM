#include "../main.h"

// ������� ����� ��� ���������. ������ ��� �������� ���� ���
class Artifact
{
public:
	Artifact() 
	{
		this->color = 0;
		this->value = 0;
		this->weight = 0;
	};
	Artifact(int color, int value, int weight) {
		this->color = color;
		this->value = value;
		this->weight = weight;
	};
	

private:
	int color;
	int value;
	int weight;

};