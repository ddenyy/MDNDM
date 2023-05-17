#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Artefact {
protected:
    // координаты
    int _cord_x;
    int _cord_y;
    // вес
    int _weight;
    // стоимость(очки за доставку на базу)
    int _cost;
    // редкость
    string _availability;
    // цвет
    string _colour;
public:
    virtual ~Artefact() = default;

    // сеттеры
    int cord_x() { return _cord_x; }
    int cord_y() { return _cord_y; }
    int weight() { return _weight; }
    int cost() { return _cost; }
    string availability() { return _availability; }
    string colour() { return _colour; }

    // геттеры
    void set_cord_x(int cord_x) { _cord_x = cord_x; }
    void set_cord_y(int cord_y) { _cord_y = cord_y; }
    void set_weight(int weight) { _weight = weight; }
    void set_cost(int cost) { _cost = cost; }
    void set_availability(string availability) { _availability = availability; }
    void set_colour(string colour) { _colour = colour; }

    // печать (для проверки)
    virtual void print() = 0;

    void operator=(Artefact &ar);
};
class frequent : public Artefact {
public:
    frequent();
    frequent(Artefact &ar);
    ~frequent();
    void print();
};
frequent::frequent() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 100;
    _cost = 10;
    _availability = "frequent";
    _colour = "gray";
}

frequent::frequent(Artefact &ar) {
    _cord_x = ar.cord_x();
    _cord_y = ar.cord_y();
    _weight = ar.weight();
    _cost = ar.cost();
    _availability = ar.availability();
    _colour = ar.colour();
}

frequent::~frequent() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 0;
    _cost = 0;
    _availability = "";
    _colour = "";
}
void frequent::print() {
    cout << "Редкость : "<< _availability << "\n";
    cout << "Координаты : " << _cord_x << " ; " << _cord_y << "\n";
}
class rare : public Artefact {
private:
    // время видимости
    int _lifetime = 15;
    // увеличение грузоподъемности робота
    int _buff_lifting = 100;
public:
    rare();
    rare(Artefact &ar);
    ~rare();
    void print();

    int lifetime() { return _lifetime; }
    int buff_lifting() { return _buff_lifting; }

    void set_lifetime(int lifetime) { _lifetime = lifetime; }
    void set_buff_lifting(int buff_lifting) { _buff_lifting = buff_lifting; }
};
// конструктор
rare::rare() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 200;
    _cost = 40;
    _availability = "rare";
    _colour = "orange";
}

// конструктор копирования
rare::rare(Artefact &ar) {
    _cord_x = ar.cord_x();
    _cord_y = ar.cord_y();
    _weight = ar.weight();
    _cost = ar.cost();
    _availability = ar.availability();
    _colour = ar.colour();
}

// деструктор
rare::~rare() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 0;
    _cost = 0;
    _availability = "";
    _colour = "";
    _lifetime = 0;
    _buff_lifting = 0;
}

// вывод для проверки
void rare::print() {
    cout << "Редкость : "<< _availability << "\n";
    cout << "Координаты : " << _cord_x << " ; " << _cord_y << "\n";
}
class usually : public Artefact {
public:
    usually();
    usually(Artefact &ar);
    ~usually();
    void print();
};
usually::usually() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 150;
    _cost = 20;
    _availability = "usually";
    _colour = "blue";
}

usually::usually(Artefact &ar) {
    _cord_x = ar.cord_x();
    _cord_y = ar.cord_y();
    _weight = ar.weight();
    _cost = ar.cost();
    _availability = ar.availability();
    _colour = ar.colour();
}

usually::~usually() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 0;
    _cost = 0;
    _availability = "";
    _colour = "";
}

void usually::print() {
    cout << "Редкость : "<< _availability << "\n";
    cout << "Координаты : " << _cord_x << " ; " << _cord_y << "\n";
}
class Cell
{
public:

    Cell() {
        type_cell = "earth";
        height_hill = 0;
    }


    string getType() {
        return type_cell;
    }

    float getHeightHill()
    {
        return height_hill;
    }

    string getTypeOfArtefact()
    {
        if(is_rare_artefact)
        {
            return "rare";
        }
        if (is_usually_artefact) {
            return "usually";
        }
        if (is_frequent_artefact) {
            return "frequent";
        }

        return "no";
    }

    void setRareArtifact(rare new_artifact) {
        this->rare_artefact = new_artifact;
        is_rare_artefact = true;
        is_usually_artefact = false;
        is_frequent_artefact = false;
    }

    void setUsuallyArtifact(usually new_artifact) {
        this->usually_artefact = new_artifact;
        is_rare_artefact = false;
        is_usually_artefact = true;
        is_frequent_artefact = false;
    }

    void setFrequentArtifact(frequent new_artifact) {
        this->frequent_artefact = new_artifact;
        is_rare_artefact = false;
        is_usually_artefact = false;
        is_frequent_artefact = true;
    }

    void setType(string type_cell)
    {
        this->type_cell = type_cell;
    }

    void setHeight(float height_hill)
    {
//		if (this->type_cell == "hill")
//		{
        this->height_hill = height_hill;
//		}
//		else
//		{
//			this->height_hill = 0;
//		}
    }

private:
    string type_cell;
    float height_hill;

    rare rare_artefact;
    usually usually_artefact;
    frequent frequent_artefact;

    bool is_rare_artefact = false;
    bool is_usually_artefact = false;
    bool is_frequent_artefact = false;

};
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

    void generateAllHills() {
        // количество холмов которые мы сгенерируем
        int count_hills = (min(width,height) / 2) - 1;


        int x_rand = 0;
        int y_rand = 0;
        float default_height_hill = 1.95;

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
class Robot {
private:
    int x, y, z; // координаты робота
    int rotation; // текущее направление робота (0-3 соответственно "вперед", "направо", "назад", "налево")
    bool hasArtifact; // есть ли у робота артефакт (да/нет)
    int score; // количество очков игрока
    int numArtifacts;  // количество артефактов на роботе
    int health; // здоровье робота
    int load_capacity; // грузоподъемность робота, по дефолту 100
    int counter_usually_Artifacts = 0;
    int counter_rare_Aritfacts = 0;
    int counter_frequent_Artifacts = 0;
    int base_coordinate_x;
    int base_coordinate_y;
    Cell now_cell;
    LogicBoard board_computer_on_robot;
public:

    //Пустой конструктор
    Robot() : x(0), y(0), z(0), rotation(0), hasArtifact(false), score(2), numArtifacts(0), health(100), load_capacity(100), counter_frequent_Artifacts(0), counter_rare_Aritfacts(0), counter_usually_Artifacts(0), now_cell(),
              board_computer_on_robot(20, 20){}
    // Функция переносит робота на dx, dy, dz
    void walk(int dx, int dy, int dz) {
        x += dx;
        y += dy;
        z += dz;
        bool have_we_found_new_artfact = false;
    }
    void is_there_an_Artefact(){
        tuple<int, int, int> now_coordinates = get_coordinates();
        if (now_cell.getTypeOfArtefact() == "rare"){
            counter_rare_Aritfacts++;
        }
        if (now_cell.getTypeOfArtefact() == "frequents"){
            counter_frequent_Artifacts++;
        }
        if (now_cell.getTypeOfArtefact() == "usually"){
            counter_usually_Artifacts++;
        }
    }
    tuple<int, int, int> get_coordinates(){
        return make_tuple(x, y, z);
    }
    int get_coordinate_x(){
        return get<0>(get_coordinates());
    }
    int get_coordinate_y(){
        return get<1>(get_coordinates());
    }
    int get_coordinate_z(){
        return get<2>(get_coordinates());
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
            rotate = "forward\n";
        }

        if (rotation == 1){
            rotate = "right\n";
        }

        if (rotation == 2){
            rotate = "back\n";
        }

        if (rotation == 3){
            rotate = "left\n";
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
    void quest_ok_rare(){
        if (counter_rare_Aritfacts > 0 && get_coordinate_x() == base_coordinate_x && get_coordinate_y() == base_coordinate_y){
            load_capacity+=200;
        }
    }
    void quest_frequents_ok(){
        if (counter_frequent_Artifacts > 0){
            set_health(150);
        }
    }
    void quest_usually_ok(){
        if (counter_usually_Artifacts > 0){
            set_score(100);
        }
    }
    void make_step_forward(){
        if (get_rotation() == "forward"){
            if (get_coordinate_y() + 1 <= board_computer_on_robot.field[get_coordinate_x()].size()) {
                now_cell = board_computer_on_robot.field[get_coordinate_x()][get_coordinate_y() + 1];
                walk(0, 1, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_ok_rare();
                quest_usually_ok();
            }
        }
        if (get_rotation() == "back"){
            if (get_coordinate_y() - 1 >= 1) {
                now_cell = board_computer_on_robot.field[get_coordinate_x()][get_coordinate_y() - 1];
                walk(0, -1, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_ok_rare();
                quest_usually_ok();


            }
        }
        if (get_rotation() == "right"){
            if (get_coordinate_x() + 1 < board_computer_on_robot.field.size()) {
                now_cell = board_computer_on_robot.field[get_coordinate_x() + 1][get_coordinate_y()];
                walk(1, 0, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_ok_rare();
                quest_usually_ok();

            }
        }
        if (get_rotation() == "left"){
            if (get_coordinate_x() - 1 >= 1) {
                now_cell = board_computer_on_robot.field[get_coordinate_x() - 1][get_coordinate_y()];
                walk(-1, 0, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_ok_rare();
                quest_usually_ok();

            }
        }
    }

};
class FinalBoss{
    vector<vector<bool>> was()
    void dfs(ll ver){

    }
};