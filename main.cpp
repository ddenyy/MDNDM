#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Robot {
private:
    int x, y, z; // текущие координаты робота
    int rotation; // текущее направление робота (0-3 соответственно "вверх", "направо", "вниз", "налево")
    bool hasArtifact; // есть ли у робота артефакт (да/нет)
    int score; // количество очков игрока
    int numArtifacts; // количество артефактов на роботе
    int health; // здоровье робота
    vector<tuple<double, double, double>> artifacts; // артефакты определяются координатами
public:
    // конструктор пустой
    Robot() : x(0), y(0), z(0), rotation(0), hasArtifact(false), score(2), numArtifacts(0), health(100), artifacts(){}
    // конструктор с параметрами
    Robot(double x, double y, double z, int health, int rotation, int numArtifactsh, vector<tuple<double, double, double>> &artifacts) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->health = health;
        this->rotation = rotation;
        this->numArtifacts = numArtifacts;
        this->health = health;
        this->artifacts = artifacts;
    }
    // метод ходьбы робота
    void walk(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
        bool have_we_found_new_artfact = false;
        // здесь надо дописать что если в этой клетки на поле есть артифакт, то его надо добавить
        if (have_we_found_new_artfact){
            artifacts.emplace_back(NULL, NULL, NULL);
        }
    }
    // возвращает текушие координаты робота в виде кортежа(x, y, z)
    tuple<double, double, double> get_coordinates(){
        return make_tuple(x, y, z);
    }
    int get_health() { // метод для получения здоровья робота
        return health;
    }
    // метод для получения количество очков робота
    int get_score(){
        return score;
    }
    // возвращает артефакты, в виде координат
    bool get_artifact(){
        cout << "Координтаы артефактов\n";
        for (auto c: artifacts){
            cout << "x" << " = " << get<0>(c) << "  " << "y" << " = " << get<1>(c) << "  " << "z" << " = " << get<2>(c) << "\n";
        }
    }
    // возвращает текущее направление робота
    string get_rotation(){
        string rotate;
        if (rotation == 0){
            rotate = "вверх\n";
        }

        if (rotation == 1){
            rotate = "направо\n";
        }

        if (rotation == 2){
            rotate = "вниз\n";
        }

        if (rotation == 3){
            rotate = "налево\n";
        }
        return rotate;
    }
    // возвращает количество артефактов на роботе
    int get_numArtifacts(){
        return numArtifacts;
    }
    // сеттер чтобы менять здоровье робота
    void set_health(int health){
        this->health = health;
    }
    // сеттер чтобы менять количество очков у робота
    void set_score(int score){
        this->score = score;
    }
    // сеттер чтобы менять количество артефактов у робота
    void set_numArifacts(int numArifacts){
        this->numArtifacts = numArifacts;
    }
    // сеттер который добавляет артефакт к роботу(артефакт надо добавлять координатами где он находится
    void set_AddArtifact(double x_art, double y_art, double z_art){
        artifacts.emplace_back(x_art, y_art, z_art);
    }
    // сеттер для удаления артефакта, удаление происходит по номеру артефакта
    void set_deleteArifact(int num){
        for (int i = 0; i < artifacts.size(); i++){
            if (i == num){
                artifacts.erase(artifacts.begin() + i);
                break;
            }
        }
    }
    void turn(double angle) {  // метод для поворота робота на угол angle (в градусах)
        double rad = angle * M_PI / 180; // переводим угол в радианы
        double x1 = x * cos(rad) + y * sin(rad); // вычисляем новые координаты
        double y1 = -x * sin(rad) + y * cos(rad);
        x = x1;
        y = y1;
    }
    void jump(double height) { // метод для прыжка робота на высоту height
        z += height;
    }
    // штука которая телепортирует робота в тартарары
    void teleport(double tx, double ty, double tz, double destx, double desty, double destz) {  // метод для телепортации
        if (x == tx && y == ty && z == tz) { // если робот находится на месте телепорта
            x = destx;
            y = desty;
            z = destz;
        } else {
            cout << "Robot is not at the teleport location" << endl;
        }
    }
    void command(string &s){
        if (s == "turnRight"){
            rotation = (rotation + 1) % 4;
        }
        if (s == "turnLeft"){
            rotation = (rotation + 3) % 4;
        }
    }
    // Далее следуют функции которые по полученным командам возвращают новое состояние

};