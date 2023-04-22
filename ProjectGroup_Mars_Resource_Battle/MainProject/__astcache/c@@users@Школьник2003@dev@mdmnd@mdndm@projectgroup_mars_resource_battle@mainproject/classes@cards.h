#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class DECK
{
public:
    //1 шаг в текущем направлении
    const string stepOne = "stepOne";
    //движение до упора в текущем направлении
    const string stepToStop = "stepToStop";
    //прыжок в текущем направлении
    const string jump = "jump";
    //поворото налево 90'
    const string left = "left";
    //поворот направо 90'
    const string right = "right";
    //поворот на 180'
    const string back = "back";
    //телепорт на любую из клеток с радиусом 1
    const string teleportForOne = "teleportForOne";
    //телепорт на любую из клеток с радиусом 5
    const string teleportForFive = "teleportForFive";
    //телепорт на любую из клеток с радиусом 7
    const string teleportForSeven = "teleportForSeven";
    //установить ловушку
    const string setTrap = "setTrap";
    //аквтивировать ловушку
    const string activateTrap = "activateTrap";

public:
    //конструктор
    DECK() = default;
    //конструктор копирования
    DECK(const DECK& other) = default;
    //деструктор
    ~DECK() = default;

    //формируем колоду для этапа
    void formDeck(int id);

    //рандомно мешаем колоду
    void shuffleDeck();

    //берем карту из конца колода
    string takeCard();

private:
    vector<string> cards;
};
