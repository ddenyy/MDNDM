#include "cards.h"

void DECK::formDeck(int id)
{
    cards.clear();
    for (int i = 0; i < 225; ++i)
    {
        cards.push_back(stepOne);
    }
    for (int i = 0; i < 45; ++i)
    {
        cards.push_back(stepToStop);
    }
    for (int i = 0; i < 90; ++i)
    {
        cards.push_back(jump);
    }
    for (int i = 0; i < 120; ++i)
    {
        cards.push_back(left);
    }
    for (int i = 0; i < 120; ++i)
    {
        cards.push_back(right);
    }
    for (int i = 0; i < 60; ++i)
    {
        cards.push_back(back);
    }
    if (id <= 2)
        return;

    for (int i = 0; i < 25; ++i)
    {
        cards.push_back(teleportForOne);
    }
    if (id == 3)
        return;

    for (int i = 0; i < 35; ++i)
    {
        cards.push_back(teleportForFive);
    }
    if (id <= 5)
        return;

    for (int i = 0; i < 35; ++i)
    {
        cards.push_back(teleportForSeven);
    }
    if (id == 6)
        return;

    for (int i = 0; i < 15; ++i)
    {
        cards.push_back(setTrap);
    }
    for (int i = 0; i < 15; ++i)
    {
        cards.push_back(activateTrap);
    }
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
string DECK::takeCard()
{
    string currCard;
    currCard = cards[cards.size() - 1];
    cards.pop_back();
    return currCard;
}

