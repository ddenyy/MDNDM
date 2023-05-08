#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Robot {
private:
    int x, y, z; // ⥪�騥 ���न���� ஡��
    int rotation; // ⥪�饥 ���ࠢ����� ஡�� (0-3 ᮮ⢥��⢥��� "�����", "���ࠢ�", "����", "������")
    bool hasArtifact; // ���� �� � ஡�� ���䠪� (��/���)
    int score; // ������⢮ �窮� ��ப�
    int numArtifacts; // ������⢮ ���䠪⮢ �� ஡��
    int health; // ���஢� ஡��
    vector<tuple<double, double, double>> artifacts; // ���䠪�� ��।������� ���न��⠬�
public:
    // ��������� ���⮩
    Robot() : x(0), y(0), z(0), rotation(0), hasArtifact(false), score(2), numArtifacts(0), health(100), artifacts(){}
    // ��������� � ��ࠬ��ࠬ�
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
    // ��⮤ 室�� ஡��
    void walk(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
        bool have_we_found_new_artfact = false;
        // ����� ���� ������� �� �᫨ � �⮩ ���⪨ �� ���� ���� ���䠪�, � ��� ���� ��������
        if (have_we_found_new_artfact){
            artifacts.emplace_back(NULL, NULL, NULL);
        }
    }
    // �����頥� ⥪�訥 ���न���� ஡�� � ���� ���⥦�(x, y, z)
    tuple<double, double, double> get_coordinates(){
        return make_tuple(x, y, z);
    }
    int get_health() { // ��⮤ ��� ����祭�� ���஢�� ஡��
        return health;
    }
    // ��⮤ ��� ����祭�� ������⢮ �窮� ஡��
    int get_score(){
        return score;
    }
    // �����頥� ���䠪��, � ���� ���न���
    bool get_artifact(){
        cout << "���न��� ���䠪⮢\n";
        for (auto c: artifacts){
            cout << "x" << " = " << get<0>(c) << "  " << "y" << " = " << get<1>(c) << "  " << "z" << " = " << get<2>(c) << "\n";
        }
    }
    // �����頥� ⥪�饥 ���ࠢ����� ஡��
    string get_rotation(){
        string rotate;
        if (rotation == 0){
            rotate = "�����\n";
        }

        if (rotation == 1){
            rotate = "���ࠢ�\n";
        }

        if (rotation == 2){
            rotate = "����\n";
        }

        if (rotation == 3){
            rotate = "������\n";
        }
        return rotate;
    }
    // �����頥� ������⢮ ���䠪⮢ �� ஡��
    int get_numArtifacts(){
        return numArtifacts;
    }
    // ���� �⮡� ������ ���஢� ஡��
    void set_health(int health){
        this->health = health;
    }
    // ���� �⮡� ������ ������⢮ �窮� � ஡��
    void set_score(int score){
        this->score = score;
    }
    // ���� �⮡� ������ ������⢮ ���䠪⮢ � ஡��
    void set_numArifacts(int numArifacts){
        this->numArtifacts = numArifacts;
    }
    // ���� ����� �������� ���䠪� � ஡���(���䠪� ���� ��������� ���न��⠬� ��� �� ��室����
    void set_AddArtifact(double x_art, double y_art, double z_art){
        artifacts.emplace_back(x_art, y_art, z_art);
    }
    // ���� ��� 㤠����� ���䠪�, 㤠����� �ந�室�� �� ������ ���䠪�
    void set_deleteArifact(int num){
        for (int i = 0; i < artifacts.size(); i++){
            if (i == num){
                artifacts.erase(artifacts.begin() + i);
                break;
            }
        }
    }
    void turn(double angle) {  // ��⮤ ��� ������ ஡�� �� 㣮� angle (� �ࠤ���)
        double rad = angle * M_PI / 180; // ��ॢ���� 㣮� � ࠤ����
        double x1 = x * cos(rad) + y * sin(rad); // ����塞 ���� ���न����
        double y1 = -x * sin(rad) + y * cos(rad);
        x = x1;
        y = y1;
    }
    void jump(double height) { // ��⮤ ��� ��릪� ஡�� �� ����� height
        z += height;
    }
    // ��㪠 ����� ⥫�������� ஡�� � ������
    void teleport(double tx, double ty, double tz, double destx, double desty, double destz) {  // ��⮤ ��� ⥫�����樨
        if (x == tx && y == ty && z == tz) { // �᫨ ஡�� ��室���� �� ���� ⥫�����
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
    // ����� ᫥���� �㭪樨 ����� �� ����祭�� �������� �������� ����� ���ﭨ�

};