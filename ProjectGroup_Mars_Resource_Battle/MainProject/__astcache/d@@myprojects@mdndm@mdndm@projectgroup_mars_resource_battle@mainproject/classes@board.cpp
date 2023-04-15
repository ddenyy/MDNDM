#include "../Additional_Libraries.h"
#include "Cell.cpp"

class Board
{
public:
	Board(int width, int height) {
		this->width = width;
		this->height = height;
		Pole.resize(width, vector<Cell> (height));
	};

	~Board() {
		for (size_t i = 0; i < Pole.size(); i++)
		{
			Pole[i].clear();
		}

	}

	void PrintBoard() {
		for (size_t i = 0; i < this->width; i++)
		{
			for (size_t j = 0; j < this->height; j++)
			{
				cout << Pole[i][j].getType() << ' ';
			}
			cout << '\n';
		}
	}

private:

    vector<vector<Cell>> Pole;

	int width;
	int height;
};

