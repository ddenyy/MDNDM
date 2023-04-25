#include <iostream>
#include <cmath>
using namespace std;

class Robot {
private:
    double x, y, z; // координаты робота
    int health; // здоровье робота
    int artifacts;// количество собранных артефактов
    double trap_x, trap_y, trap_z; // координаты ловушки
public:
    Robot(double x0, double y0, double z0, int health0) { // конструктор с параметрами
        x = x0;
        y = y0;
        z = z0;
        health = health0;
        artifacts = 0;
        trap_x = -1;
        trap_y = -1;
        trap_z = -1;
    }

    void walk(double dx, double dy, double dz) { // метод ходьбы робота
        x += dx;
        y += dy;
        z += dz;
    }

    int get_health() { // метод для получения здоровья робота
        return health;
    }

    void turn(double angle) {  // метод для поворота робота на угол angle (в градусах)
        double rad = angle * M_PI / 180; // переводим угол в радианы
        double x1 = x * cos(rad) + y * sin(rad); // вычисляем новые координаты
        double y1 = -x * sin(rad) + y * cos(rad);
        x = x1;
        y = y1;
    }

    void collect_artifact() { // метод для сбора артефакта
        artifacts++;
    }

    void jump(double height) { // метод для прыжка робота на высоту height
        z += height;
    }

    void teleport(double tx, double ty, double tz, double destx, double desty, double destz) {  // метод для телепортации
        if (x == tx && y == ty && z == tz) { // если робот находится на месте телепорта
            x = destx;
            y = desty;
            z = destz;
        } else {
            cout << "Robot is not at the teleport location" << endl;
        }
    }

    void set_trap(double tx, double ty, double tz) { // метод для установки ловушки на координатах (tx, ty, tz)
        trap_x = tx;
        trap_y = ty;
        trap_z = tz;
    }

};
