#include "Cell.h"

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
        Pole.clear();
	}

	void CreateBoard(TDummy * RootDummy, float delta_x, float delta_y)
    {
        float x, y;

        delta_x *= -1;

		for (size_t i = 0, y = delta_y; i < this->width; i++, y -= delta_y) {
			for (size_t j = 0, x = delta_x; j < this->height; j++, x -= delta_x) {
                Pole[i][j].ground = new TCube(RootDummy);

                Pole[i][j].ground -> Parent = RootDummy;
            	Pole[i][j].ground -> Height = 0.25;
            	Pole[i][j].ground -> Depth = 1.95;
            	Pole[i][j].ground -> Width = 1.95;

            	Pole[i][j].ground -> Position -> Z = y;
            	Pole[i][j].ground -> Position -> X = x;
			}
		}
	}

    vector<vector<Cell>> Pole;

private:

    //vector<vector<Cell>> Pole;

	int width;
	int height;
};

