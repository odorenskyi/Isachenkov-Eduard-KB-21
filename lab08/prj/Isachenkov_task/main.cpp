#include <iostream>
#include <windows.h>
#include <clocale>
#include "ModulesIsachenkov.h"

using namespace std;

string Annotations(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    string Annotations = " __________________________________________________\n| Eduard Isachenkov, isachenkov.eduard26@gmail.com |\n| Едуард Ісаченков,  isachenkov.eduard26@gmail.com |\n|_______________________(c)________________________|\n";
    return Annotations;
}

string Equality(double a, double b){
    if (a + 1 >= b){
        string True = "\n(a + 1 >= b) = true";
        return True;
    }
    else{
        string False = "\n(a + 1 >= b) = false";
        return False;
    }
}

float s_calculator(int x, int y, int z){
    double S;
    cout << "\nЗмінна x(" << x << ") в шістнадцятковій системі числення = " << hex << x;
    cout << "\nЗмінна y(" << y << ") в шістнадцятковій системі числення = " << hex << y;
    cout << "\nЗмінна z(" << z << ") в шістнадцятковій системі числення = " << hex << z;
    cout << "\n\nФункція s_calculation: ";
    S = s_calculation(x,y,z);
    return S;
}

int main()
{
    double x, y, z, a, b;
    cout << Annotations();
    cout << "\nВведіть значення x: ";
    cin >> x;
    cout << "Введіть значення y: ";
    cin >> y;
    cout << "Введіть значення z: ";
    cin >> z;
    cout << "Введіть значення a: ";
    cin >> a;
    cout << "Введіть значення b: ";
    cin >> b;
    cout << Equality(a, b);
    cout << endl << s_calculator(x,y,z) << endl;
    system("pause");
    return 0;
}
