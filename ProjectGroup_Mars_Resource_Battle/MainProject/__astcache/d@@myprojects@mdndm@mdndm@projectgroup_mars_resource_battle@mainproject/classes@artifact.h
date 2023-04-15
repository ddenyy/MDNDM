#include "../Additional_Libraries.h"
//#include "MainUnit.h"

// базовый класс для артефакта. Сделал как заглушку пока что
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
