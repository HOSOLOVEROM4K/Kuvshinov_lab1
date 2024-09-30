#include <iostream>
#include <string>

using namespace std;

struct pipe {
    string name;
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
    getline(cin, newpipe.name);
    cout << "Введите длинну: ";
    check_int(newpipe.length);
    cout << "Введите диаметр: ";
    check_int(newpipe.diametr);
    cout << "Труба в ремонте? (1 - да, 0 - нет): ";
    check_bool(newpipe.repair);
    return newpipe;
}

void pipe_out(const pipe& newpipe) {  

    if (newpipe.name.empty()) {
        cout << "Нет данных." << endl;
    }
    else {
        cout << "-------------" << endl;
        cout << "Имя: " << newpipe.name << endl;
        cout << "Длинна: " << newpipe.length << endl;
        cout << "Диаметр: " << newpipe.diametr << endl;
        
        if (newpipe.repair == 0) {
            cout << "В ремонте нет." << endl;
            cout << "-------------" << endl;
        }
        else {
            cout << "В ремонте да." << endl;
            cout << "-------------" << endl;
        }
    }
}

ks ks_input() {
    
    ks newks;
    cout << "Введите название КС: ";
    cin.ignore();
    getline(cin, newks.name);
    cout << "Введите количество цехов: ";
    check_int(newks.workshops);
    cout << "Введите количество цехов в работе: ";
    check_int(newks.workshops_in_work);
    while (newks.workshops < newks.workshops_in_work) {
        cout << "Колличество работающих станций должно быть меньше количества станций!!!" << endl;
        cout << "Введите количество цехов в работе: ";
        check_int(newks.workshops_in_work);
    }
    cout << "Эффективность КС: ";
    check_double(newks.eff);
    return newks;
}

void ks_out(const ks& newks) { 

    if (newks.name.empty()) {
        cout << "-------------" << endl;
        cout << "Нет данных." << endl;
        cout << "-------------" << endl;
    }
    else {
        cout << "-------------" << endl;
        cout << "Имя: " << newks.name << endl;
        cout << "Количество цехов: " << newks.workshops << endl;
        cout << "Количество цехов в работе: " << newks.workshops_in_work << endl;
        cout << "Эффективность: " << newks.eff << endl;
        cout << "-------------" << endl;
    }
}

pipe pipe_change(pipe& newpipe) {
    newpipe.repair = !newpipe.repair;
    cout << "Статус изменен на: " << newpipe.repair << endl;
    return newpipe;
}
ks ks_change(ks& newks) {
    cout << "Количество цехов в работе: " << endl;
    check_int(newks.workshops_in_work);
    while (newks.workshops < newks.workshops_in_work) {
        cout << "Колличество работающих станций должно быть меньше количества станций" << endl;
        check_int(newks.workshops_in_work);
    }
    cout << "Эффективность: " << endl;
    check_double(newks.eff);

    return newks;
}

void menu() {
    
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
    setlocale(LC_ALL, "RU");
    pipe newpipe;
    ks newks;
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
        case 2: {
            newks = ks_input();
            break;
        }
        case 3: {
            cout << "Труба:" << endl;
            pipe_out(newpipe);
            cout << "КС" << endl;
            ks_out(newks);
            break;
        }
        case 4: {
            if (newpipe.name.empty()) {
                cout << "Нет трубы" << endl;
            }
            else {
                pipe_change(newpipe);
            }
            break;
        }
        case 5: {
            if (newks.name.empty()) {
                cout << "Нет КС" << endl;
            }
            else {
                ks_change(newks);
            }
            break;
        }
        }


    } while (input_index != 0);
}

