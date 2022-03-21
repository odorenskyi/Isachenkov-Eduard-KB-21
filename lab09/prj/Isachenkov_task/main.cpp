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
        cout << "\n\nSelect the function you want to use:"
            << "\n(to use, enter the button next to the function):"
            << "\nz - the function is called s_calculation"
            << "\nr - the function is called Task 9.1"
            << "\ns - the function is called Task 9.2"
            << "\nt - the function is called Task 9.3"
            << "\nq - exit the application" << endl << endl;
        cin >> value;
        if (value == 'z'){
            int x, y, z;
            cout << "Enter x: = ";
            cin >> x;
            cout << "\nEnter y: = ";
            cin >> y;
            cout << "\nEnter z: = ";
            cin >> z;
            cout << "S: = " << s_calculation(x, y, z);
        }
        if (value == 'r'){
            double posadOklad, zarobPlata;
            int year;
            cout << "Enter the amount of salary (UAH): " << endl;
            cin >> posadOklad;
            cout << "Enter the amount of the employee's salary (UAH): " << endl;
            cin >> zarobPlata;
            cout << "Work experience at the enterprise (years): " << endl;
            cin >> year;
            cout << "Amount to be paid (UAH): " << Task_9_1(posadOklad, zarobPlata, year);
        }
        if (value == 's'){
            double one, two, three, four, five, six;
            cout << "\nEnter the fixed air temperature (Celsius) î 00:00 = ";
            cin >> one;
            cout << "Enter the fixed air temperature (Celsius) î 04:00 = ";
            cin >> two;
            cout << "Enter the fixed air temperature (Celsius) î 08:00 = ";
            cin >> three;
            cout << "Enter the fixed air temperature (Celsius) î 12:00 = ";
            cin >> four;
            cout << "Enter the fixed air temperature (Celsius) î 16:00 = ";
            cin >> five;
            cout << "Enter the fixed air temperature (Celsius) î 20:00 = ";
            cin >> six;
            cout << "\nAverage daily temperature on the Celsius scale: " << Task_9_2_1(one, two, three, four, five, six) << endl;
            cout << "The average daily temperature on the Fahrenheit scale: " << Task_9_2_2(Task_9_2_1(one, two, three, four, five, six)) << endl;

        }
        if (value == 't'){
            int N, t;
            cout << "\nEnter the number N from 0 to 10008000: ";
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
    cout << " __________________________________________________\n| Eduard Isachenkov, isachenkov.eduard26@gmail.com |\n|_______________________(c)________________________|\n";
}
