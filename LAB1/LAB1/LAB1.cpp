#include <iostream>


using namespace std;

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


// Меню программы
int main() {

    int input_index;
    do {
        menu();
        cout << "Выберете команду: ";
        cin >> input_index;
        cout << "Индекс вашей программы: " << input_index << endl;

    } while (input_index != 0);
}

