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
        cout << "\n\n�����i�� �����i�, ��� ������ �����������:"
            << "\n(��� ����������� ����i�� �� ������, ��� ������� �i�� �����i�):"
            << "\nz - ����������� �����i� s_calulation"
            << "\nr - ����������� �����i� Task 9.1"
            << "\ns - ����������� �����i� Task 9.2"
            << "\nt - ����������� �����i� Task 9.3"
            << "\nq - ���i� � �������" << endl << endl;
        cin >> value;
        if (value == 'z'){
            int x, y, z;
            cout << "����i�� x: = ";
            cin >> x;
            cout << "\n����i�� y: = ";
            cin >> y;
            cout << "\n����i�� z: = ";
            cin >> z;
            cout << "S: = " << s_calculation(x, y, z);
        }
        if (value == 'r'){
            double posadOklad, zarobPlata;
            int year;
            cout << "����i�� ����i� ���������� ������(���.): " << endl;
            cin >> posadOklad;
            cout << "����i�� ����i� �����i���� ����� ����i�����(���.): " << endl;
            cin >> zarobPlata;
            cout << "���� ������ �� �i��������i(���i�): " << endl;
            cin >> year;
            cout << "���� �� �������(���.): " << Task_9_1(posadOklad, zarobPlata, year);
        }
        if (value == 's'){
            double one, two, three, four, five, six;
            cout << "\n����i�� ���i������� ����������� ���i��� (�� ������ �����i�) � 00:00 = ";
            cin >> one;
            cout << "����i�� ���i������� ����������� ���i��� (�� ������ �����i�) � 04:00 = ";
            cin >> two;
            cout << "����i�� ���i������� ����������� ���i��� (�� ������ �����i�) � 08:00 = ";
            cin >> three;
            cout << "����i�� ���i������� ����������� ���i��� (�� ������ �����i�) � 12:00 = ";
            cin >> four;
            cout << "����i�� ���i������� ����������� ���i��� (�� ������ �����i�) � 16:00 = ";
            cin >> five;
            cout << "����i�� ���i������� ����������� ���i��� (�� ������ �����i�) � 20:00 = ";
            cin >> six;
            cout << "\n�������������� ����������� �� ������ �����i�: " << Task_9_2_1(one, two, three, four, five, six) << endl;
            cout << "�������������� ����������� �� ������ ����������: " << Task_9_2_2(Task_9_2_1(one, two, three, four, five, six)) << endl;

        }
        if (value == 't'){
            int N, t;
            cout << "\n����i�� ����� N �i� 0 �� 10008000: ";
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
    cout << " __________________________________________________\n| Eduard Isachenkov, isachenkov.eduard26@gmail.com |\n| ������ I��������,  isachenkov.eduard26@gmail.com |\n|_______________________(c)________________________|\n";
}
