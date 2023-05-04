#include "../Additional_Libraries.h"

// базовый класс для артефакта. Сделал как заглушку пока что
class LogicArtifact
{
public:
	LogicArtifact()
	{
		this->color = 0;
		this->value = 0;
		this->weight = 0;
	};
	LogicArtifact(int color, int value, int weight) {
		this->color = color;
		this->value = value;
		this->weight = weight;
	};


private:
	int color;
	int value;
	int weight;

};
