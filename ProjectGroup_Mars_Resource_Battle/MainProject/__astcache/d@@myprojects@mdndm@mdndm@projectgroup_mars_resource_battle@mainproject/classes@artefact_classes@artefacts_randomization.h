#pragma once
#include "artefact.h"
#include "frequent.h"
#include "usually.h"
#include "rare.h"
#include <random>
#include "../../Additional_Libraries.h"
//// ОСНОВНАЯ ФУНКЦИЯ КОТОРУЮ НУЖНО ЗАЮЗАТЬ ДЛЯ ПОЛУЧЕНИЯ ВЕКТОРА АРТЕФАКТОВ
// cnt - количество артефактов. size - размер поля
vector <artefact*> get_list_of_artefacts(int cnt, int size) {

    frequent* frequent_artefact;
    usually* usually_artefact;
    rare* rare_artefact;
    vector <artefact*> Artefacts;
    // 1 = "frequent", 2 = "usually", 3 = "rare"
    vector <int> Data = {1, 2, 3};
    // вектор для рандомизации видов артефактов 1, 2, 3
    vector <int> Random_pos (cnt, 0);

    ////////////////////// Аналогично как сверху
    // 1 = "TCube", 2 = "TSphere", 3 = "TCylinder"
    vector <int> Form = {1, 2, 3};
    vector <int> Random_form (cnt, 0);
    ///////////////////////////////////////////

    // заполняю массив только ширпотребом и обычными
    for (int i = 0; i < cnt; ++i) {
        Random_pos[i] = rand() % 2 + 1;
    }
    // добавляю редкие в рандомные позиции
    for (int i = 0; i < cnt / 10 + 1; ++i) {
        Random_pos[rand() % cnt - 1] = 3;
    }

    ////////////////////// добавляю рандомные чиселки для формы
    for (int i = 0; i < cnt; ++i) {
        Random_form[i] = rand() % 3 + 1;
    }
    /////////////////////////////

    // вектор ставящий каждому артефакту пару координат х и у
    vector <pair<int, pair<int, int>>> Random_cords (cnt);
    // начальная инициализация
    Random_cords[0].first = Random_pos[0];
    Random_cords[0].second = {rand() % size, rand() % size};
    // проверка какого вида данный артефакт
    if (Random_pos[0] == 3) {
        rare_artefact = new rare();
        rare_artefact->set_cord_x(Random_cords[0].second.first);
        rare_artefact->set_cord_y(Random_cords[0].second.second);
        /////////////////////////////
        if (Random_form[0] == 1) {
            rare_artefact->set_form("TCube");
        }
        else if (Random_form[0] == 2) {
            rare_artefact->set_form("TSphere");
        }
        else if (Random_form[0] == 3) {
            rare_artefact->set_form("TCylinder");
        }
        //////////////////////////////
        Artefacts.push_back(rare_artefact);
    }
    else if (Random_pos[0] == 2) {
        usually_artefact = new usually();
        usually_artefact->set_cord_x(Random_cords[0].second.first);
        usually_artefact->set_cord_y(Random_cords[0].second.second);
        /////////////////////////////
        if (Random_form[0] == 1) {
            rare_artefact->set_form("TCube");
        }
        else if (Random_form[0] == 2) {
            rare_artefact->set_form("TSphere");
        }
        else if (Random_form[0] == 3) {
            rare_artefact->set_form("TCylinder");
        }
        //////////////////////////////
        Artefacts.push_back(usually_artefact);
    }
    else {
        frequent_artefact = new frequent();
        frequent_artefact->set_cord_x(Random_cords[0].second.first);
        frequent_artefact->set_cord_y(Random_cords[0].second.second);
        /////////////////////////////
        if (Random_form[0] == 1) {
            rare_artefact->set_form("TCube");
        }
        else if (Random_form[0] == 2) {
            rare_artefact->set_form("TSphere");
        }
        else if (Random_form[0] == 3) {
            rare_artefact->set_form("TCylinder");
        }
        //////////////////////////////
        Artefacts.push_back(frequent_artefact);
    }

    for (int i = 1; i < cnt; ++i) {
        // флаг будет проверять есть ли уже такая пара координат в ранее инициализированных артефактах
        //или если артефакт попал в угол
        bool flag = true;
        Random_cords[i].first = Random_pos[i];
        int rand_x = rand() % size;
        int rand_y = rand() % size;
        pair <int, int> cords = {rand_x, rand_y};
        for (int j = 0; j < i; ++j) {
            if (cords == Random_cords[j].second || cords == make_pair(0, size - 1)
            || cords == make_pair(size - 1, 0)|| cords == make_pair(0, 0) || cords == make_pair(size - 1, size - 1))
                flag = false;
        }
        if (flag) {
            // если флаг, то ставим эту пару координат в зависимости от вида артефакта меняет его координаты
            Random_cords[i].second = cords;
            // проверка какого вида данный артефакт
            if (Random_pos[i] == 3) {
				rare_artefact = new rare();
                rare_artefact->set_cord_x(Random_cords[i].second.first);
                rare_artefact->set_cord_y(Random_cords[i].second.second);
                /////////////////////////////
                if (Random_form[0] == 1) {
                    rare_artefact->set_form("TCube");
                }
                else if (Random_form[0] == 2) {
                    rare_artefact->set_form("TSphere");
                }
                else if (Random_form[0] == 3) {
                    rare_artefact->set_form("TCylinder");
                }
                //////////////////////////////
                Artefacts.push_back(rare_artefact);
            }
            else if (Random_pos[i] == 2) {
                usually_artefact = new usually();
                usually_artefact->set_cord_x(Random_cords[i].second.first);
                usually_artefact->set_cord_y(Random_cords[i].second.second);
                /////////////////////////////
                if (Random_form[0] == 1) {
                    rare_artefact->set_form("TCube");
                }
                else if (Random_form[0] == 2) {
                    rare_artefact->set_form("TSphere");
                }
                else if (Random_form[0] == 3) {
                    rare_artefact->set_form("TCylinder");
                }
                //////////////////////////////
                Artefacts.push_back(usually_artefact);
            }
            else {
                frequent_artefact = new frequent();
                frequent_artefact->set_cord_x(Random_cords[i].second.first);
                frequent_artefact->set_cord_y(Random_cords[i].second.second);
                /////////////////////////////
                if (Random_form[0] == 1) {
                    rare_artefact->set_form("TCube");
                }
                else if (Random_form[0] == 2) {
                    rare_artefact->set_form("TSphere");
                }
                else if (Random_form[0] == 3) {
                    rare_artefact->set_form("TCylinder");
                }
                //////////////////////////////
                Artefacts.push_back(frequent_artefact);
            }
        }
        else
            i--;
	}
    return Artefacts;
}
