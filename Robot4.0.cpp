#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Robot {
private:
    int x, y, z; // â¥ªãé¨¥ ª®®à¤¨­ âë à®¡®â 
    int rotation; // â¥ªãé¥¥ ­ ¯à ¢«¥­¨¥ à®¡®â  (0-3 á®®â¢¥âáâ¢¥­­® "¢¢¥àå", "­ ¯à ¢®", "¢­¨§", "­ «¥¢®")
    bool hasArtifact; // ¥áâì «¨ ã à®¡®â   àâ¥ä ªâ (¤ /­¥â)
    int score; // ª®«¨ç¥áâ¢® ®çª®¢ ¨£à®ª 
    int numArtifacts; // ª®«¨ç¥áâ¢®  àâ¥ä ªâ®¢ ­  à®¡®â¥
    int health; // §¤®à®¢ì¥ à®¡®â 
    vector<tuple<double, double, double>> artifacts; //  àâ¥ä ªâë ®¯à¥¤¥«ïîâáï ª®®à¤¨­ â ¬¨
public:
    // ª®­áâàãªâ®à ¯ãáâ®©
    Robot() : x(0), y(0), z(0), rotation(0), hasArtifact(false), score(2), numArtifacts(0), health(100), artifacts(){}
    // ª®­áâàãªâ®à á ¯ à ¬¥âà ¬¨
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
    // ¬¥â®¤ å®¤ì¡ë à®¡®â 
    void walk(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
        bool have_we_found_new_artfact = false;
        // §¤¥áì ­ ¤® ¤®¯¨á âì çâ® ¥á«¨ ¢ íâ®© ª«¥âª¨ ­  ¯®«¥ ¥áâì  àâ¨ä ªâ, â® ¥£® ­ ¤® ¤®¡ ¢¨âì
        if (have_we_found_new_artfact){
            artifacts.emplace_back(NULL, NULL, NULL);
        }
    }
    // ¢®§¢à é ¥â â¥ªãè¨¥ ª®®à¤¨­ âë à®¡®â  ¢ ¢¨¤¥ ª®àâ¥¦ (x, y, z)
    tuple<double, double, double> get_coordinates(){
        return make_tuple(x, y, z);
    }
    int get_health() { // ¬¥â®¤ ¤«ï ¯®«ãç¥­¨ï §¤®à®¢ìï à®¡®â 
        return health;
    }
    // ¬¥â®¤ ¤«ï ¯®«ãç¥­¨ï ª®«¨ç¥áâ¢® ®çª®¢ à®¡®â 
    int get_score(){
        return score;
    }
    // ¢®§¢à é ¥â  àâ¥ä ªâë, ¢ ¢¨¤¥ ª®®à¤¨­ â
    bool get_artifact(){
        cout << "Š®®à¤¨­â ë  àâ¥ä ªâ®¢\n";
        for (auto c: artifacts){
            cout << "x" << " = " << get<0>(c) << "  " << "y" << " = " << get<1>(c) << "  " << "z" << " = " << get<2>(c) << "\n";
        }
    }
    // ¢®§¢à é ¥â â¥ªãé¥¥ ­ ¯à ¢«¥­¨¥ à®¡®â 
    string get_rotation(){
        string rotate;
        if (rotation == 0){
            rotate = "¢¢¥àå\n";
        }

        if (rotation == 1){
            rotate = "­ ¯à ¢®\n";
        }

        if (rotation == 2){
            rotate = "¢­¨§\n";
        }

        if (rotation == 3){
            rotate = "­ «¥¢®\n";
        }
        return rotate;
    }
    // ¢®§¢à é ¥â ª®«¨ç¥áâ¢®  àâ¥ä ªâ®¢ ­  à®¡®â¥
    int get_numArtifacts(){
        return numArtifacts;
    }
    // á¥ââ¥à çâ®¡ë ¬¥­ïâì §¤®à®¢ì¥ à®¡®â 
    void set_health(int health){
        this->health = health;
    }
    // á¥ââ¥à çâ®¡ë ¬¥­ïâì ª®«¨ç¥áâ¢® ®çª®¢ ã à®¡®â 
    void set_score(int score){
        this->score = score;
    }
    // á¥ââ¥à çâ®¡ë ¬¥­ïâì ª®«¨ç¥áâ¢®  àâ¥ä ªâ®¢ ã à®¡®â 
    void set_numArifacts(int numArifacts){
        this->numArtifacts = numArifacts;
    }
    // á¥ââ¥à ª®â®àë© ¤®¡ ¢«ï¥â  àâ¥ä ªâ ª à®¡®âã( àâ¥ä ªâ ­ ¤® ¤®¡ ¢«ïâì ª®®à¤¨­ â ¬¨ £¤¥ ®­ ­ å®¤¨âáï
    void set_AddArtifact(double x_art, double y_art, double z_art){
        artifacts.emplace_back(x_art, y_art, z_art);
    }
    // á¥ââ¥à ¤«ï ã¤ «¥­¨ï  àâ¥ä ªâ , ã¤ «¥­¨¥ ¯à®¨áå®¤¨â ¯® ­®¬¥àã  àâ¥ä ªâ 
    void set_deleteArifact(int num){
        for (int i = 0; i < artifacts.size(); i++){
            if (i == num){
                artifacts.erase(artifacts.begin() + i);
                break;
            }
        }
    }
    void turn(double angle) {  // ¬¥â®¤ ¤«ï ¯®¢®à®â  à®¡®â  ­  ã£®« angle (¢ £à ¤ãá å)
        double rad = angle * M_PI / 180; // ¯¥à¥¢®¤¨¬ ã£®« ¢ à ¤¨ ­ë
        double x1 = x * cos(rad) + y * sin(rad); // ¢ëç¨á«ï¥¬ ­®¢ë¥ ª®®à¤¨­ âë
        double y1 = -x * sin(rad) + y * cos(rad);
        x = x1;
        y = y1;
    }
    void jump(double height) { // ¬¥â®¤ ¤«ï ¯àë¦ª  à®¡®â  ­  ¢ëá®âã height
        z += height;
    }
    // èâãª  ª®â®à ï â¥«¥¯®àâ¨àã¥â à®¡®â  ¢ â àâ à àë
    void teleport(double tx, double ty, double tz, double destx, double desty, double destz) {  // ¬¥â®¤ ¤«ï â¥«¥¯®àâ æ¨¨
        if (x == tx && y == ty && z == tz) { // ¥á«¨ à®¡®â ­ å®¤¨âáï ­  ¬¥áâ¥ â¥«¥¯®àâ 
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
    // „ «¥¥ á«¥¤ãîâ äã­ªæ¨¨ ª®â®àë¥ ¯® ¯®«ãç¥­­ë¬ ª®¬ ­¤ ¬ ¢®§¢à é îâ ­®¢®¥ á®áâ®ï­¨¥

};
