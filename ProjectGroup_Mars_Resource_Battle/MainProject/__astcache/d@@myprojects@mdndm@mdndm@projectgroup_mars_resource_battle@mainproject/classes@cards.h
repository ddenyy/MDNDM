//#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class DECK
{
public:
    //1 шаг в текущем направлении СИНИЙ
    const string stepOne = "stepOne";
    //движение до упора в текущем направлении ЖЕЛТЫЙ
    const string stepToStop = "stepToStop";
    //прыжок в текущем направлении ОРАНЖЕВЫЙ
    const string jump = "jump";
    //поворото налево 90' ГОЛУБОЙ
    const string left = "left";
    //поворот направо 90' ГОЛУБОЙ
    const string right = "right";
    //поворот на 180' ГОЛУБОЙ
    const string back = "back";
    //телепорт на любую из клеток с радиусом 1 ЗЕЛЁНЫЙ
    const string teleportForOne = "teleportForOne";
    //телепорт на любую из клеток с радиусом 5 ЗЕЛЁНЫЙ
    const string teleportForFive = "teleportForFive";
    //телепорт на любую из клеток с радиусом 7  ЗЕЛЁНЫЙ
    const string teleportForSeven = "teleportForSeven";
    //установить ловушку КРАСНЫЙ
    const string setTrap = "setTrap";
    //аквтивировать ловушку КРАСНЫЙ
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
    pair<string, int> takeCard();

private:
    vector<string> cards;

    int number = 0;
};


void DECK::formDeck(int id)
{
    cards.clear();
    for (int i = 0; i < 180; ++i)
    {
        cards.push_back(stepOne);
    }
    for (int i = 0; i < 120; ++i)
    {
        cards.push_back(left);
    }
    for (int i = 0; i < 120; ++i)
    {
        cards.push_back(right);
    }
    for (int i = 0; i < 70; ++i)
    {
        cards.push_back(stepToStop);
    }

//    for (int i = 0; i < 45; ++i)
//    {
//        cards.push_back(stepToStop);
//    }
//    for (int i = 0; i < 90; ++i)
//    {
//        cards.push_back(jump);
//    }
//    for (int i = 0; i < 120; ++i)
//    {
//        cards.push_back(left);
//    }
//    for (int i = 0; i < 120; ++i)
//    {
//        cards.push_back(right);
//    }
//    for (int i = 0; i < 60; ++i)
//    {
//        cards.push_back(back);
//    }
//    if (id <= 2)
//        return;
//
//    for (int i = 0; i < 25; ++i)
//    {
//        cards.push_back(teleportForOne);
//    }
//    if (id == 3)
//        return;
//
//    for (int i = 0; i < 35; ++i)
//    {
//        cards.push_back(teleportForFive);
//    }
//    if (id <= 5)
//        return;
//
//    for (int i = 0; i < 35; ++i)
//    {
//        cards.push_back(teleportForSeven);
//    }
//    if (id == 6)
//        return;
//
//    for (int i = 0; i < 15; ++i)
//    {
//        cards.push_back(setTrap);
//    }
//    for (int i = 0; i < 15; ++i)
//    {
//        cards.push_back(activateTrap);
//    }
}

//рандомно мешаем колоду
void DECK::shuffleDeck()
{
    /*
      получаем начальное число на основе времени
      это нужно, чтобы колода каждый раз мешалась по разному
    */
    unsigned seed = chrono::system_clock::now()
                            .time_since_epoch()
                            .count();
    shuffle(begin(cards), end(cards), default_random_engine(seed));
}

//берем карту из конца колода
pair<string, int> DECK::takeCard()
{
    if (cards.size() == 0)
        return make_pair("", 0);

    string currCard;
    currCard = cards[cards.size() - 1];
    cards.pop_back();
    number++;
    return make_pair(currCard, number);
}

