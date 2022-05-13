#ifndef MODULESISACHENKOV_H_INCLUDED
#define MODULESISACHENKOV_H_INCLUDED

void showDatabase(vector<entry> &database);
void searchPersonalCard(vector<entry> &database, string surname);
double s_calculation(int x, int y, int z);
int Task_9_1(int posadOklad, int zarobPlata, int year);
int Task_9_2_1(int one, int two, int three, int four, int five, int six);
int Task_9_2_2(int celsia);
int Task_9_3(int N);
char Task_10_1(char in_path[], char out_path[]);
char Task_10_2(char in_path[]);
void Task_10_3(int x, int y, int z, int b, char out_path[]);

class ClassLab12_Isachenkov {
public:
    ClassLab12_Isachenkov () { a = 5.0, b = 5.0;}
    ClassLab12_Isachenkov (float side_a, float side_b) {a = side_a, b = side_b;}
    float out_a () {return a;}
    float out_b () {return b;}
    double out_S () {return a*b;}
    void in_a (float side_a) {a = side_a;}
    void in_b (float side_b) {b = side_b;}
private:
    float a, b;
};

#endif // MODULESISACHENKOV_H_INCLUDED
