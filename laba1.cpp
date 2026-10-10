#include <iostream>
#include <cstring>
using namespace std;

void printChoice(){
    cout << "\n\n============================\n";
        cout << "       ЛАБОРАТОРНАЯ №1\n";
        cout << "============================\n";
        cout << "2. Размеры типов данных\n";
        cout << "3. Целочисленные типы\n";
        cout << "4. Вещественные типы\n";
        cout << "5. Манипуляции с битами\n";
        cout << "6. Проверка на степень двойки\n";
        cout << "0. Выход\n";
        cout << "============================\n";
        cout << "Выберите этап: ";
}

void dataTypesSizes(){
    cout << "bool: " << sizeof(bool) << " байт \n"; 
    cout << "char: " << sizeof(char) << " байт \n"; 
    cout << "short int: " << sizeof(short int) << " байта \n"; 
    cout << "int: " << sizeof(int) << " байта \n"; 
    cout << "long int: " << sizeof(long int) << " байтов \n"; 
    cout << "float: " << sizeof(float) << " байта \n"; 
    cout << "double: " << sizeof(double) << " байтов \n"; 
    cout << "long double: " << sizeof(long double) << " байтов \n"; 

}

void binaryInt(){
    int x;
    cout << "Введите целое число: ";
    cin >> x;
    bool foundFirstBit = false;
        for (int i = 31; i>=0; i--){
            if (i == 31){
                cout << x << ": " << ((x >> i) & 1) << " | ";
            }
            else if ((i+1)%8 == 0 and (i != 31)){
                cout << " " << ((x >> i) & 1);
            }
            else{
                cout << ((x >> i) & 1);
            }
        }
        if (x > 0){
            cout << " | ";
            for (int i = 31; i>=0; i--){
                if (((x >> i) & 1) == 1){
                    foundFirstBit = true;
                }
                if (foundFirstBit == true){
                    cout << ((x >> i) & 1);
                }
            }

        }
        cout << "\n";
}
void binaryUnsignedInt(){
    unsigned int x;
    cout << "Введите целое число (unsigned): ";
    cin >> x;
    cout << x << ": ";
    for (int i = 31; i>=0; i--){
            if ((i+1)%8 == 0 and (i != 31)){
            cout << " " << ((x >> i) & 1);
        }
        else{
            cout << ((x >> i) & 1);
        }
    }
    cout << "\n";
}
void chooseIntSign() {
    int choice = 67;
    cout << "1. signed \n";
    cout << "2. unsigned \n";
    cout << "Выберите тип int: ";
    cin >> choice;
    switch (choice) {
        case 1:
            binaryInt();
            break;
        case 2:
            binaryUnsignedInt();
            break;
        default:
            cout << "Неверный выбор! Попробуйте еще раз";
            break;
    }
}

void binaryFloat(){
    float x;
    cout << "Введите дробное число: ";
    cin >> x;
    union {
        float number;
        unsigned int bits;
    } data; 
    data.number = x;
    cout << x << ": ";
    for (int i = 31; i >= 0; i--) {
        if (i == 31) {
            cout << ((data.bits >> i) & 1) << " | ";
        }
        else if (i == 23) {
            cout << ((data.bits >> i) & 1) << " | ";
        }
        else {
            cout << ((data.bits >> i) & 1);
        }
    }
    cout << "\n";
}
void binaryDouble() {
    double x;
    cout << "Введите дробное число: ";
    cin >> x;
    union {
        double number;
        unsigned long long bits;
    } data;

    data.number = x;

    cout << x << ": ";

    for (int i = 63; i >= 0; i--) {
        if (i == 63) {
            cout << ((data.bits >> i) & 1) << " | ";
        }
        else if (i == 52) {
            cout << ((data.bits >> i) & 1) << " | ";
        }
        else {
            cout << ((data.bits >> i) & 1);
        }
    }

    cout << "\n";
}
void binarySpecial() {
    union {
        float number;
        unsigned int bits;
    } data;

    unsigned int values[3] = {
        1u,
        0x7F800000u,
        0xFF800000u
    };

    for (int j = 0; j < 3; j++) {
        data.bits = values[j];

        cout << data.number << ": ";

        for (int i = 31; i >= 0; i--) {
            if (i == 31 or i == 23) {
                cout << ((data.bits >> i) & 1) << " | ";
            }
            else {
                cout << ((data.bits >> i) & 1);
            }
        }

        cout << "\n";
    }
}
void chooseFloatSize() {
    int choice = 67;
    cout << "1. float \n";
    cout << "2. double \n";
    cout << "3. Особые случаи \n";
    cout << "Выберите тип числа: ";
    cin >> choice;
    switch (choice) {
        case 1:
            binaryFloat();
            break;
        case 2:
            binaryDouble();
            break;
        case 3:
            binarySpecial();
            break;
        default:
            cout << "Неверный выбор! Попробуйте еще раз";
            break;
    }
}

unsigned int changeBit32(unsigned int x, int bit, int operation) {
    if (operation == 1) {
        x |= (1u << bit);
    }
    else if (operation == 2) {
        x &= ~(1u << bit);
    }
    else if (operation == 3) {
        x ^= (1u << bit);
    }

    return x;
}
unsigned long long changeBit64(unsigned long long x, int bit, int operation) {
    if (operation == 1) {
        x |= (1ULL << bit);
    }
    else if (operation == 2) {
        x &= ~(1ULL << bit);
    }
    else if (operation == 3) {
        x ^= (1ULL << bit);
    }

    return x;
}
void printBits32(unsigned int x) {
    for (int i = 31; i >= 0; i--) {
        if ((i + 1) % 8 == 0 and i != 31) {
            cout << " ";
        }
        cout << ((x >> i) & 1);
    }
}
void printBits64(unsigned long long x) {
    for (int i = 63; i >= 0; i--) {
        if ((i + 1) % 8 == 0 and i != 63) {
            cout << " ";
        }
        cout << ((x >> i) & 1ULL);
    }
}
void bitManipulation() {
    int type;
    int operation;
    int bit;

    cout << "\n===== МАНИПУЛЯЦИИ С БИТАМИ =====\n";
    cout << "1. int\n";
    cout << "2. unsigned int\n";
    cout << "3. float\n";
    cout << "4. double\n";
    cout << "Выберите тип: ";
    cin >> type;

    if (type < 1 or type > 4) {
        cout << "Неверный тип!\n";
        return;
    }

    cout << "\n1. Установить бит\n";
    cout << "2. Сбросить бит\n";
    cout << "3. Инвертировать бит\n";
    cout << "Выберите операцию: ";
    cin >> operation;

    if (operation < 1 or operation > 3) {
        cout << "Неверная операция!\n";
        return;
    }

    cout << "Введите номер бита: ";
    cin >> bit;

    if (type == 4) {
        if (bit < 0 or bit >= 64) {
            cout << "Неверный номер бита!\n";
            return;
        }
    }
    else {
        if (bit < 0 or bit >= 32) {
            cout << "Неверный номер бита!\n";
            return;
        }
    }

    switch (type) {
        case 1: {
            int x;
            cout << "Введите число: ";
            cin >> x;

            unsigned int bits = x;

            cout << "До:    ";
            printBits32(bits);
            cout << " | " << x << "\n";

            bits = changeBit32(bits, bit, operation);

            cout << "После: ";
            printBits32(bits);
            cout << " | " << (int)bits << "\n";

            break;
        }

        case 2: {
            unsigned int x;
            cout << "Введите число: ";
            cin >> x;

            cout << "До:    ";
            printBits32(x);
            cout << " | " << x << "\n";

            x = changeBit32(x, bit, operation);

            cout << "После: ";
            printBits32(x);
            cout << " | " << x << "\n";

            break;
        }

        case 3: {
            union {
                float number;
                unsigned int bits;
            } data;

            cout << "Введите число: ";
            cin >> data.number;

            cout << "До:    ";
            printBits32(data.bits);
            cout << " | " << data.number << "\n";

            data.bits = changeBit32(data.bits, bit, operation);

            cout << "После: ";
            printBits32(data.bits);
            cout << " | " << data.number << "\n";

            break;
        }

        case 4: {
            union {
                double number;
                unsigned long long bits;
            } data;

            cout << "Введите число: ";
            cin >> data.number;

            cout << "До:    ";
            printBits64(data.bits);
            cout << " | " << data.number << "\n";

            data.bits = changeBit64(data.bits, bit, operation);

            cout << "После: ";
            printBits64(data.bits);
            cout << " | " << data.number << "\n";

            break;
        }
    }
}

int checkPowerOfTwo(int x){
    
    if ((x > 0) and (x & (x-1)) == 0){
        cout << x << " является степенью двойки";
    }
    else{
        cout << x << " не является степенью двойки";
        x = 0;
    }
    return x;
}


int main(){
    int choice = -1;

    while (choice != 0) {
        printChoice();
        cin >> choice;
        switch (choice) {
            case 2:
                cout << "\nЭтап 2:\n-----------\n\n";
                dataTypesSizes();
                break;

            case 3:
                cout << "\nЭтап 3:\n-----------\n\n";
                chooseIntSign();
                break;

            case 4:
                cout << "\nЭтап 4:\n-----------\n\n";
                chooseFloatSize();
                break;

            case 5:
                cout << "\nЭтап 5:\n-----------\n\n";
                bitManipulation();
                break;
            
            case 6:
                cout << "\nЭтап 6:\n-----------\n\n";
                int x;
                cout << "Введите целое число: ";
                cin >> x;
                checkPowerOfTwo(x);
                break;

            case 0:
                cout << "\nЗавершение программы...\n";
                break;

            default:
                cout << "\nНеверный выбор!\n";
        }
    }
}
