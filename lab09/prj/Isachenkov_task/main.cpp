#include <iostream>
#include "ModulesIsachenkov.h"

using namespace std;

void Annotations();

int main()
{
    char *locale = setlocale(LC_ALL, "");
    Annotations();
    char value;
    do{
        cout << "\n\nВиберiть функцiю, яку хочете використати:"
            << "\n(щоб використати впишiть ту кнопку, яка вказана бiля функцiї):"
            << "\nz - викликається функцiя s_calulation"
            << "\nr - викликається функцiя Task 9.1"
            << "\ns - викликається функцiя Task 9.2"
            << "\nt - викликається функцiя Task 9.3"
            << "\nq - вихiд з додатку" << endl << endl;
        cin >> value;
        if (value == 'z'){
            int x, y, z;
            cout << "Введiть x: = ";
            cin >> x;
            cout << "\nВведiть y: = ";
            cin >> y;
            cout << "\nВведiть z: = ";
            cin >> z;
            cout << "S: = " << s_calculation(x, y, z);
        }
        if (value == 'r'){
            double posadOklad, zarobPlata;
            int year;
            cout << "Введiть розмiр посадового окладу(грн.): " << endl;
            cin >> posadOklad;
            cout << "Введiть розмiр заробiтньої плати працiвника(грн.): " << endl;
            cin >> zarobPlata;
            cout << "Стаж роботи на пiдприємствi(рокiв): " << endl;
            cin >> year;
            cout << "Сума до виплати(грн.): " << Task_9_1(posadOklad, zarobPlata, year);
        }
        if (value == 's'){
            double one, two, three, four, five, six;
            cout << "\nВведiть зафiксовану температуру повiтря (за шкалою Цельсiя) о 00:00 = ";
            cin >> one;
            cout << "Введiть зафiксовану температуру повiтря (за шкалою Цельсiя) о 04:00 = ";
            cin >> two;
            cout << "Введiть зафiксовану температуру повiтря (за шкалою Цельсiя) о 08:00 = ";
            cin >> three;
            cout << "Введiть зафiксовану температуру повiтря (за шкалою Цельсiя) о 12:00 = ";
            cin >> four;
            cout << "Введiть зафiксовану температуру повiтря (за шкалою Цельсiя) о 16:00 = ";
            cin >> five;
            cout << "Введiть зафiксовану температуру повiтря (за шкалою Цельсiя) о 20:00 = ";
            cin >> six;
            cout << "\nСередньодобова температура за шкалою Цельсiя: " << Task_9_2_1(one, two, three, four, five, six) << endl;
            cout << "Середньодобова температура за шкалою Фарангейта: " << Task_9_2_2(Task_9_2_1(one, two, three, four, five, six)) << endl;

        }
        if (value == 't'){
            int N, t;
            cout << "\nВведiть число N вiд 0 до 10008000: ";
            cin >> N;
            cout << "N: = " << Task_9_3(N);
        }
    }while(value == 'a'||value == 'A'||value == 'b'||value == 'B'||value == 'c'||value == 'C'||
           value == 'd'||value == 'D'||value == 'e'||value == 'E'||value == 'g'||value == 'G'||
           value == 'h'||value == 'H'||value == 'i'||value == 'I'||value == 'j'||value == 'J'||
           value == 'k'||value == 'K'||value == 'l'||value == 'L'||value == 'm'||value == 'M'||
           value == 'n'||value == 'N'||value == 'o'||value == 'O'||value == 'p'||value == 'P'||
           value == 'r'||value == 'R'||value == 'u'||value == 'U'||value == 'v'||value == 'V'||
           value == 'w'||value == 'W'||value == 'x'||value == 'X'||value == 'y'||value == 'Y'||
           value == 'z'||value == 'Z'||value == 's'||value == 'S'||value == 't'||value == 'T');
    return 0;
}

void Annotations(){
    cout << " __________________________________________________\n| Eduard Isachenkov, isachenkov.eduard26@gmail.com |\n| Едуард Iсаченков,  isachenkov.eduard26@gmail.com |\n|_______________________(c)________________________|\n";
}
