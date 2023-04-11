#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
#define debug(x) std::cerr << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;
// Класс игрока
class Player{
private:
    //Структура Borders определяет переменные задающие границы перемещения игрового объекта типа Player в графическом окне.
    // По умолчанию границы задаются согласно размеру графического окна, которые передаются по ссылки window.
    struct Borders{
        // Начальные координаты
        double x;
        double y;
        double maxx;
        double maxy;
    };
    // Здесь надо сделать два объекта, которые создадут анимированное отображение
    // Изначально границы не заданы
    Borders borders{0};
    // Начальное положение робота
    pair<double, double> pos = {0, 0};
    // ЗtimeUpdate ? свойство подсчёта интервала времени, по окончанию которого периодически будет обновляться игровая логика.
    double life_x_start, life_y_start;
    // Флаг проверки робота на живность
    bool dead = false;
public:
    enum class direction{up, down, left, right};
    // Сюда в параметрах конструктора передаём: ссылку на графическое окно
    Player()
};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    return 0;
}