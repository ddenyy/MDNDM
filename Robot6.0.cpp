#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
class Arifact{

};
class Robot {
private:
    int x, y, z; // координаты робота
    int rotation; // текущее направление робота (0-3 соответственно "вперед", "направо", "назад", "налево")
    bool hasArtifact; // есть ли у робота артефакт (да/нет)
    int score; // количество очков игрока
    int numArtifacts;  // количество артефактов на роботе
    int health; // здоровье робота
    // здесь надо допилить чтобы были Данины артефакты
    vector<Arifact> artifacts; // в этом векторе хранятся текущие артефакты, которые есть у робота(в формате где лежали коордианты)
public:
    //Пустой конструктор
    Robot() : x(0), y(0), z(0), rotation(0), hasArtifact(false), score(2), numArtifacts(0), health(100), artifacts(){}
    // Конструктор с параметрами
    Robot(double x, double y, double z, int health, int rotation, int numArtifactsh, vector<Arifact> &artifacts) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->health = health;
        this->rotation = rotation;
        this->numArtifacts = numArtifacts;
        this->health = health;
        this->artifacts = artifacts;
    }
    // Функция переносит робота на dx, dy, dz
    void walk(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
        bool have_we_found_new_artfact = false;
    }
    tuple<double, double, double> get_coordinates(){
        return make_tuple(x, y, z);
    }
    int get_health() {
        return health;
    }
    int get_score(){
        return score;
    }
    string get_rotation(){
        string rotate;
        if (rotation == 0){
            rotate = "вперед\n";
        }

        if (rotation == 1){
            rotate = "направо\n";
        }

        if (rotation == 2){
            rotate = "назад\n";
        }

        if (rotation == 3){
            rotate = "налево\n";
        }
        return rotate;
    }
    int get_numArtifacts(){
        return numArtifacts;
    }
    void set_health(int health){
        this->health = health;
    }
    void diff_health(int something){
        this->health+=something;
    }
    void set_score(int score){
        this->score = score;
    }
    void diff_score(int something){
        this->score+=something;
    }
    void set_numArifacts(int numArifacts){
        this->numArtifacts = numArifacts;
    }
    void jump(double height) {
        z += height;
    }
    void teleport(double tx, double ty, double tz, double destx, double desty, double destz) {
        if (x == tx && y == ty && z == tz) {
            x = destx;
            y = desty;
            z = destz;
        } else {
            cout << "Robot is not at the teleport location" << endl;
        }
    }
    void command_to_turn(string &s){
        if (s == "turnRight"){
            rotation = (rotation + 1) % 4;
        }
        if (s == "turnLeft"){
            rotation = (rotation + 3) % 4;
        }
    }
    void make_step_forward(){
         if (get_rotation() == "вперед"){
             walk(0, 1, 0);
         }
         if (get_rotation() == "назад"){
            walk(0, -1, 0);
        }
         if (get_rotation() == "направо"){
            walk(1, 0, 0);
        }
         if (get_rotation() == "налево"){
            walk(-1, 0, 0);
        }
    }

};
