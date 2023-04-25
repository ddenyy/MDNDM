#include <iostream>
#include <cstdio>
class Robot {
public:
    // ��������� �����
    Robot(double startX = 0, double startY = 0, double startZ = 0) : x(startX), y(startY), z(startZ) {}

    // ��⮤� ��६�饭�� ஡��
    void moveX(double distance) { x += distance; }
    void moveY(double distance) { y += distance; }
    void moveZ(double distance) { z += distance; }

    // ��⮤ ����祭�� ⥪�饩 ����樨 ஡��
    void getPosition(double &posX, double &posY, double &posZ) { posX = x; posY = y; posZ = z; }
    // �⠪�
    void attack(Robot& enemy) {
    }
    float getHealthPercent(double health) {
        return (float)health / 100.0f * 100.0f;
    }
    // ��⮤ �믮������ ������
    void executeCommand(std::string command) {
        if (command == "moveUp") {
            moveZ(1);
        }
        else if (command == "moveDown") {
            moveZ(-1);
        }
        else if (command == "moveLeft") {
            moveX(-1);
        }
        else if (command == "moveRight") {
            moveX(1);
        }
        else if (command == "moveForward") {
            moveY(1);
        }
        else if (command == "moveBackward") {
            moveY(-1);
        }
        if (command == "attack_him"){
            //�⠪�
        }
        if (command == "get_health"){
            getHealthPercent(NULL);
        }
        // ���������� ��㣨� ������
        //...
    }
private:
    double x, y, z; // ���न���� ஡�� � ��嬥୮� ����࠭�⢥
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}