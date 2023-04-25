#include <iostream>
#include <cstdio>
class Robot {
public:
    // Š®­áâàãªâ®à ª« áá 
    Robot(double startX = 0, double startY = 0, double startZ = 0) : x(startX), y(startY), z(startZ) {}

    // Œ¥â®¤ë ¯¥à¥¬¥é¥­¨ï à®¡®â 
    void moveX(double distance) { x += distance; }
    void moveY(double distance) { y += distance; }
    void moveZ(double distance) { z += distance; }

    // Œ¥â®¤ ¯®«ãç¥­¨ï â¥ªãé¥© ¯®§¨æ¨¨ à®¡®â 
    void getPosition(double &posX, double &posY, double &posZ) { posX = x; posY = y; posZ = z; }
    //  â ª 
    void attack(Robot& enemy) {
    }
    float getHealthPercent(double health) {
        return (float)health / 100.0f * 100.0f;
    }
    // Œ¥â®¤ ¢ë¯®«­¥­¨ï ª®¬ ­¤
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
        if (command == "attackHim"){
            // â ª 
        }
        if (command == "getHealth"){
            getHealthPercent(NULL);
        }
        // „®¡ ¢«¥­¨¥ ¤àã£¨å ª®¬ ­¤
        //...
    }
private:
    double x, y, z; // Š®®à¤¨­ âë à®¡®â  ¢ âà¥å¬¥à­®¬ ¯à®áâà ­áâ¢¥
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}
