﻿#define fi first
#define se second

class LogicRobot {
public:
    int x, y, z; // координаты робота
    int rotation = 0; // текущее направление робота (0-3 соответственно "вперед", "направо", "назад", "налево")
    bool hasArtifact; // есть ли у робота артефакт (да/нет)
    int score; // количество очков игрока
    int numArtifacts;  // количество артефактов на роботе
    int health = 1; // здоровье робота
    int load_capacity = 100; // грузоподъемность робота, по дефолту 100
    int counter_usually_Artifacts = 0;
    int counter_rare_Aritfacts = 0;
    int counter_frequent_Artifacts = 0;
    int base_coordinate_x;
    int base_coordinate_y;
    pair<int, int> enemy_pos;
    Cell now_cell;
    LogicBoard *board_computer_on_robot;
    //Пустой конструктор
     LogicRobot() : x(0), y(0), z(0), rotation(0), hasArtifact(false), score(2), numArtifacts(0), health(100), load_capacity(100),
     counter_frequent_Artifacts(0), counter_rare_Aritfacts(0), counter_usually_Artifacts(0){}
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
            rotate = "forward";
        }
        if (rotation == 1){
            rotate = "right";
        }
        if (rotation == 2){
            rotate = "back";
        }
        if (rotation == 3){
            rotate = "left";
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
        if (s == "right"){
            rotation = (rotation + 1) % 4;
        }
        if (s == "left"){
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
        if (rotation < 0 || rotation > 3) {
            rotation = 0;
        }
        if (get_rotation() == "right"){
            if (get_coordinate_y() + 1 < board_computer_on_robot->field[get_coordinate_x()].size()) {
                now_cell = board_computer_on_robot->field[get_coordinate_x()][get_coordinate_y() + 1];
                walk(0, 1, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_frequents_ok();
                quest_usually_ok();
            }
        }
        if (get_rotation() == "left"){
            if (get_coordinate_y() - 1 >= 0) {
                now_cell = board_computer_on_robot->field[get_coordinate_x()][get_coordinate_y() - 1];
                walk(0, -1, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_frequents_ok();
                quest_usually_ok();
            }
        }
        if (get_rotation() == "back"){
            if (get_coordinate_x() + 1 < board_computer_on_robot->field.size()) {
                now_cell = board_computer_on_robot->field[get_coordinate_x() + 1][get_coordinate_y()];
                walk(1, 0, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_frequents_ok();
                quest_usually_ok();
            }
        }
        if (get_rotation() == "forward"){
            if (get_coordinate_x() - 1 >= 0) {
                now_cell = board_computer_on_robot->field[get_coordinate_x() - 1][get_coordinate_y()];
                walk(-1, 0, 0);
                is_there_an_Artefact();
                quest_ok_rare();
                quest_frequents_ok();
                quest_usually_ok();
            }
        }
    }

    bool correct_move(pair<int, int> pos)
    {
        if (pos.fi < 0 || pos.se < 0 || pos.fi >= board_computer_on_robot->field.size() || pos.se >= board_computer_on_robot->field.size())
            return false;

        if (pos == enemy_pos)
            return false;

        if (board_computer_on_robot->field[pos.fi][pos.se].getTypeOfArtefact() != "no")
            return false;

        if (board_computer_on_robot->field[pos.fi][pos.se].getHeightHill() != now_cell.getHeightHill())
            return false;

        return true;
    }

    void move_until_stop()
    {
        bool we_are_moving = true;

        pair<int, int> next_pos = {x, y};

        while(we_are_moving)
        {
            we_are_moving = false;
            if (get_rotation() == "forward") {
                next_pos = {next_pos.fi - 1, next_pos.se};
                if (correct_move(next_pos)) {
                    we_are_moving = true;
                    make_step_forward();
                }
            }

            if (get_rotation() == "back") {
                next_pos = {next_pos.fi + 1, next_pos.se};
                if (correct_move(next_pos)) {
                    we_are_moving = true;
                    make_step_forward();
                }
            }

            if (get_rotation() == "left") {
                next_pos = {next_pos.fi, next_pos.se - 1};
                if (correct_move(next_pos)) {
                    we_are_moving = true;
                    make_step_forward();
                }
            }

            if (get_rotation() == "right") {
                next_pos = {next_pos.fi, next_pos.se + 1};
                if (correct_move(next_pos)) {
                    we_are_moving = true;
                    make_step_forward();
                }
            }
        }
    }
};