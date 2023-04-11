﻿#include "Cell.h"

class LogicBoard
{
public:
	LogicBoard(int width, int height) {
		this->width = width;
		this->height = height;
		field.resize(width, vector<LogicCell> (height));
	};

	~LogicBoard() {
		for (size_t i = 0; i < field.size(); i++)
		{            
			field[i].clear();
		}
        field.clear();
	}

//	void CreateField()
//    {
//        float x, y;
//
//        delta_x *= -1;
//
//		for (size_t i = 0, y = delta_y; i < this->width; i++, y -= delta_y) {
//			for (size_t j = 0, x = delta_x; j < this->height; j++, x -= delta_x) {
//                Field[i][j].ground = new TCube(RootDummy);
//
//                Field[i][j].ground -> Parent = RootDummy;
//            	Field[i][j].ground -> Height = 0.25;
//            	Field[i][j].ground -> Depth = 1.95;
//            	Field[i][j].ground -> Width = 1.95;
//
//            	Field[i][j].ground -> Position -> Z = y;
//            	Field[i][j].ground -> Position -> X = x;
//			}
//		}
//	}

private:

    vector<vector<LogicCell>> field;

	int width;
	int height;
};

