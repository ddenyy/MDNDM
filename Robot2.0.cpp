#include <iostream>
#include <cmath>
using namespace std;

class Robot {
private:
    double x, y, z; // ª®®à¤¨­ âë à®¡®â 
    int health; // §¤®à®¢ì¥ à®¡®â 
    int artifacts; // ª®«¨ç¥áâ¢® á®¡à ­­ëå  àâ¥ä ªâ®¢
    double trap_x, trap_y, trap_z; // ª®®à¤¨­ âë «®¢ãèª¨
public:
    Robot(double x0, double y0, double z0, int health0) { // ª®­áâàãªâ®à á ¯ à ¬¥âà ¬¨
        x = x0;
        y = y0;
        z = z0;
        health = health0;
        artifacts = 0;
        trap_x = -1;
        trap_y = -1;
        trap_z = -1;
    }

    void walk(double dx, double dy, double dz) { // ¬¥â®¤ å®¤ì¡ë à®¡®â 
        x += dx;
        y += dy;
        z += dz;
    }

    int get_health() { // ¬¥â®¤ ¤«ï ¯®«ãç¥­¨ï §¤®à®¢ìï à®¡®â 
        return health;
    }

    void turn(double angle) { // ¬¥â®¤ ¤«ï ¯®¢®à®â  à®¡®â  ­  ã£®« angle (¢ £à ¤ãá å)
        double rad = angle * M_PI / 180; // ¯¥à¥¢®¤¨¬ ã£®« ¢ à ¤¨ ­ë
        double x1 = x * cos(rad) + y * sin(rad); // ¢ëç¨á«ï¥¬ ­®¢ë¥ ª®®à¤¨­ âë
        double y1 = -x * sin(rad) + y * cos(rad);
        x = x1;
        y = y1;
    }

    void collect_artifact() { // ¬¥â®¤ ¤«ï á¡®à   àâ¥ä ªâ 
        artifacts++;
    }

    void jump(double height) { // ¬¥â®¤ ¤«ï ¯àë¦ª  à®¡®â  ­  ¢ëá®âã height
        z += height;
        cout << "Robot jumped to (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void teleport(double tx, double ty, double tz, double destx, double desty, double destz) { // ¬¥â®¤ ¤«ï â¥«¥¯®àâ æ¨¨
        if (x == tx && y == ty && z == tz) { // ¥á«¨ à®¡®â ­ å®¤¨âáï ­  ¬¥áâ¥ â¥«¥¯®àâ 
            x = destx;
            y = desty;
            z = destz;
        } else {
            cout << "Robot is not at the teleport location" << endl;
        }
    }

    void set_trap(double tx, double ty, double tz) { // ¬¥â®¤ ¤«ï ãáâ ­®¢ª¨ «®¢ãèª¨ ­  ª®®à¤¨­ â å (tx, ty, tz)
        trap_x = tx;
        trap_y = ty;
        trap_z = tz;
    }

};
