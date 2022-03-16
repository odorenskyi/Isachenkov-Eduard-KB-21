#include <cmath>
#include <iostream>
#include <bitset>

using namespace std;

float s_calculation(int x, int y, int z){
    return (pow((2 * z + 1), x)) - (sqrt(abs(y - 0.5 * z))) + z + 3.141592653589793;
}

int Task_9_1(int posadOklad, int zarobPlata, int year){
    int nadbavka, number1;
    if (year >= 3 && year < 5){
        nadbavka = (posadOklad*10)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    if (year >= 5 && year < 7){
        nadbavka = (posadOklad*15)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    if (year >= 7 && year < 15){
        nadbavka = (posadOklad*20)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    if (year >= 15){
        nadbavka = (posadOklad*25)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    return number1;
}




int Task_9_2_1(int one, int two, int three, int four, int five, int six){
    int celsia;
    celsia = (one+two+three+four+five+six)/6;
    return celsia;
}

int Task_9_2_2(int celsia){
    int farangeit;
    farangeit = (32 + 1.8 * celsia);
    return farangeit;
}

int Task_9_3(int N){
    bitset<32>b_number(N);
    if (N >= 0 && N < 10008000){
        if (b_number[10] == 0){
            return 32-b_number.count();
        }
        else if (b_number[10] == 1){
            return b_number.count();
        }
    }
    else{
        return 0;
    }
}


