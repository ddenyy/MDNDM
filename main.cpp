#include <iostream>
#include <cstdio>
class Robot {
public:
    // Конструктор класса
    Robot(double startX = 0, double startY = 0, double startZ = 0) : x(startX), y(startY), z(startZ) {}

    // Методы перемещения робота
    void moveX(double distance) { x += distance; }
    void moveY(double distance) { y += distance; }
    void moveZ(double distance) { z += distance; }

    // Метод получения текущей позиции робота
    void getPosition(double &posX, double &posY, double &posZ) { posX = x; posY = y; posZ = z; }
    // атака
    void attack(Robot& enemy) {
    }
    float getHealthPercent(double health) {
        return (float)health / 100.0f * 100.0f;
    }
    // Метод выполнения команд
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
            //атака
        }
        if (command == "get_health"){
            getHealthPercent(NULL);
        }
        // Добавление других команд
        //...
    }
private:
    double x, y, z; // Координаты робота в трехмерном пространстве
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}