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

	pair <int, int> get_field_size()
	{
		return make_pair(width, height);
	}//поле если че квадратное


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

             field[x][y].set_form(Vector_Random_Artefacts[i]->get_form());
		}
	}

    void generateAllHills() {
		// количество холмов которые мы сгенерируем
		int count_hills = (min(width,height) / 2) - 1;


		int x_rand = 0;
		int y_rand = 0;
        float default_height_hill = 1.95;

        srand(time(NULL));

		// основной цикл заполнения поля горами
		while(count_hills > 0)
		{
			bool flag_create_hill = false;
			// генерируем рандомно координаты горы
			x_rand = rand() * rand() % width;
			y_rand = rand() * rand() % height;

			// генерируем случайную ширину горы
			int width_hill = (rand() * rand() % width);
			// генерируем случайную высоту горы (по у)
			int height_hill = (rand()*rand() % height);

			for (int i = x_rand; i <= width_hill; i++)
			{
				for (int j = y_rand; j <= height_hill; j++)
				{
					int cur_height = field[i][j].getHeightHill();
					field[i][j].setHeight(cur_height + 1);
					flag_create_hill = true;
				}
			}

			if (flag_create_hill == true)
			{
				count_hills -= 1;
			}
		}

	}

    vector<vector<Cell>> field;

private:

    //vector<vector<Cell>> field;

	int width;
	int height;
};

