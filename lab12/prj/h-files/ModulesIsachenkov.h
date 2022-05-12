#ifndef MODULESISACHENKOV_H_INCLUDED
#define MODULESISACHENKOV_H_INCLUDED

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
