#include <iostream>
#include <string>

using namespace std;

struct pipe {
    string kilometr;
    int length;
    int diametr;
    bool repair;
};

struct ks {
    string name;
    int workshops;
    int workshops_in_work;
    double eff;
};


void check_int(int& x) {
    cin >> x;
    while (!x || x < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите число пожалуйста: ";
        cin >> x;
    }
}
void check_bool(bool& x) {
    cin >> x;
    while (cin.fail() || x < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Выбирете 1 или 0: ";
        cin >> x;
    }
}
void check_double(double& x) {
    cin >> x;
    while (!x || (x < 0)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите правильное значение: ";
        cin >> x;
    }
}

pipe pipe_input() {
    pipe newpipe;
    cout << "Введите название трубы: ";
    cin.ignore();
    getline(cin, newpipe.kilometr);
    cout << "Введите длинну: ";
    check_int(newpipe.length);
    cout << "Введите диаметр: ";
    check_int(newpipe.diametr);
    cout << "Труба в ремонте? (1 - да, 0 - нет): ";
    check_bool(newpipe.repair);
    return newpipe;
}

void pipe_out(const pipe& newpipe) {
    if (newpipe.kilometr.empty()) {
        cout << "Нет данных" << endl;
    }
    else {
        cout << "Имя: " << newpipe.kilometr << endl;
        cout << "Длинна: " << newpipe.length << endl;
        cout << "Диаметр: " << newpipe.diametr << endl;
        if (newpipe.repair == 0) {
            cout << "В ремонте нет" << endl;
        }
        else {
            cout << "В ремонте да" << endl;
        }
    }
}

void menu() {
    setlocale(LC_ALL, "");
    cout << "1. Добавить трубу" << endl;
    cout << "2. Добавить КС" << endl;
    cout << "3. Просмотр всех объектов" << endl;
    cout << "4. Редактировать трубу" << endl;
    cout << "5. Редактировать КС" << endl;
    cout << "6. Сохранить данные в файл" << endl;
    cout << "7. Загрузить данные из файла" << endl;
    cout << "0. Выход" << endl;
}



int main() {
    pipe newpipe;
    int input_index;
    do {
        menu();
        cout << "Выберете команду: ";
        cin >> input_index;

        switch (input_index)
        {
        case 1: {
            newpipe = pipe_input();
            break;
        }
        case 3: {
            cout << "Трубы:" << endl;
            pipe_out(newpipe);
            break;
        }
        }


    } while (input_index != 0);
}

