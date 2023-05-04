﻿#include "Cell.h"
#include "Classes/Artefact_Classes/artefacts_randomization.h"

class LogicBoard
{
public:
	LogicBoard(int width, int height) {
		this->width = width;
		this->height = height;
		field.resize(width, vector<Cell> (height));
	};

	~LogicBoard() {
		for (size_t i = 0; i < field.size(); i++)
		{            
			field[i].clear();
		}
        field.clear();
	}

    // создает все эти рандомные артефакты и сует их в ячейки поля.
	void initAllRandomArtefacts(int quantity_artefacts)
	{
		int size_Board = min(this->width, this->height);
		vector <artefact*> Vector_Random_Artefacts = get_list_of_artefacts(quantity_artefacts, size_Board);

		for (int i = 0; i < Vector_Random_Artefacts.size(); i++)
		{
			 // координаты х у чтобы на поле поместить объект
			 int x, y;
			 x = Vector_Random_Artefacts[i]->cord_x();
			 y = Vector_Random_Artefacts[i]->cord_y();
			 // редкость артефакта. чтобы понять какой конструктор использовать в cell
			 string ability = Vector_Random_Artefacts[i]->availability();

			 if (ability == "rare")
			 {
				  field[x][y].setRareArtifact(*Vector_Random_Artefacts[i]);
			 }
			 else if (ability == "usually")
			 {
				  field[x][y].setUsuallyArtifact(*Vector_Random_Artefacts[i]);
			 }
			 else if (ability == "frequent")
			 {
				  field[x][y].setFrequentArtifact(*Vector_Random_Artefacts[i]);
			 }
		}
	}

    void generateAllHills() {
		// множество координат х.у которые были уже заняты сгенерированными
        // клетками
		set<pair<int,int>> Busy_cells;

		// количество холмов которые мы сгенерируем
		int count_hills = (min(width,height) / 2) - 1;
        //int count_hills = 2;

		// размер квадрата в котором будем генерировать поле
		int sizeBoardHills = min(width,height);

		int x_rand = 0;
		int y_rand = 0;
        float default_height_hill = 1.95;

		// основной цикл заполнения поля горами
		while(count_hills > 0)
		{
			// генерируем рандомно координаты горы
			x_rand = rand() % sizeBoardHills;
			y_rand = rand() % sizeBoardHills;

			// если горы с такими координатами не было найдено, создаем
			if (Busy_cells.find({x_rand, y_rand}) == Busy_cells.end()) {
			   Busy_cells.insert({x_rand, y_rand});
			   count_hills-=1;
			}
		}

        // заполняем поле горами с высотой 10
		for(auto i: Busy_cells) {
			 field[i.first][i.second].setHeight(default_height_hill);
		}
	}

    vector<vector<Cell>> field;

private:

    //vector<vector<Cell>> field;

	int width;
	int height;
};
