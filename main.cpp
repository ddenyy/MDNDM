#include <iostream>
#include <cmath>
using namespace std;

class Robot {
private:
    double x, y, z; // ���न���� ஡��
    int health; // ���஢� ஡��
    int artifacts; // ������⢮ ᮡ࠭��� ���䠪⮢
    double trap_x, trap_y, trap_z; // ���न���� ����誨
public:
    Robot(double x0, double y0, double z0, int health0) { // ��������� � ��ࠬ��ࠬ�
        x = x0;
        y = y0;
        z = z0;
        health = health0;
        artifacts = 0;
        trap_x = -1;
        trap_y = -1;
        trap_z = -1;
    }

    void walk(double dx, double dy, double dz) { // ��⮤ 室�� ஡��
        x += dx;
        y += dy;
        z += dz;
    }

    int get_health() { // ��⮤ ��� ����祭�� ���஢�� ஡��
        return health;
    }

    void turn(double angle) { // ��⮤ ��� ������ ஡�� �� 㣮� angle (� �ࠤ���)
        double rad = angle * M_PI / 180; // ��ॢ���� 㣮� � ࠤ����
        double x1 = x * cos(rad) + y * sin(rad); // ����塞 ���� ���न����
        double y1 = -x * sin(rad) + y * cos(rad);
        x = x1;
        y = y1;
    }

    void collect_artifact() { // ��⮤ ��� ᡮ� ���䠪�
        artifacts++;
    }

    void jump(double height) { // ��⮤ ��� ��릪� ஡�� �� ����� height
        z += height;
        cout << "Robot jumped to (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void teleport(double tx, double ty, double tz, double destx, double desty, double destz) { // ��⮤ ��� ⥫�����樨
        if (x == tx && y == ty && z == tz) { // �᫨ ஡�� ��室���� �� ���� ⥫�����
            x = destx;
            y = desty;
            z = destz;
        } else {
            cout << "Robot is not at the teleport location" << endl;
        }
    }

    void set_trap(double tx, double ty, double tz) { // ��⮤ ��� ��⠭���� ����誨 �� ���न���� (tx, ty, tz)
        trap_x = tx;
        trap_y = ty;
        trap_z = tz;
    }

};