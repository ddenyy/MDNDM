#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
#define debug(x) std::cerr << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;
// ����� ��ப�
class Player{
private:
    //������� Borders ��।���� ��६���� �����騥 �࠭��� ��६�饭�� ��஢��� ��ꥪ� ⨯� Player � ����᪮� ����.
    // �� 㬮�砭�� �࠭��� �������� ᮣ��᭮ ࠧ���� ����᪮�� ����, ����� ��।����� �� ��뫪� window.
    struct Borders{
        // ��砫�� ���न����
        double x;
        double y;
        double maxx;
        double maxy;
    };
    // ����� ���� ᤥ���� ��� ��ꥪ�, ����� ᮧ����� �����஢����� �⮡ࠦ����
    // ����砫쭮 �࠭��� �� ������
    Borders borders{0};
    // ��砫쭮� ��������� ஡��
    pair<double, double> pos = {0, 0};
    // �timeUpdate ? ᢮��⢮ ������� ���ࢠ�� �६���, �� ����砭�� ���ண� ��ਮ���᪨ �㤥� ����������� ��஢�� ������.
    double life_x_start, life_y_start;
    // ���� �஢�ન ஡�� �� ��������
    bool dead = false;
public:
    enum class direction{up, down, left, right};
    // � � ��ࠬ���� ��������� ��।��: ��뫪� �� ����᪮� ����
    Player()
};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    return 0;
}