// polymorphism.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

//Класс музичні інструменти
class instrument
{
protected:
    string firm, name;
    int cost;
public:
    instrument() : name("NULL"), firm("NULL"), cost(0)
    {}

    virtual ~instrument() = default;

    string GetOrchestra()
    {
        return name;
    }

    void GetInst()
    {
        cout << "\nВведіть назву інструмента: "; cin >> name;
        cout << "Введіть виробника: "; cin >> firm;
        cout << "Введіть ціну: "; cin >> cost;
    }

    void PutInst()
    {
        cout << "\nІнструмент: " << name;
        cout << "\nВиробник: " << firm;
        cout << "\nЦіна: " << cost;
    }

    virtual void GetData() = 0;
    virtual void PutData() = 0;
};

//Духові інструменти
class WindInst : public instrument
{
protected:
    int year, LC; //LC - довжина канала інструмента
    string material, color;
public:
    WindInst() : material("Metal"), color("White"), year(2018), LC(0)
    {}

    void GetData()
    {
        cout << "\nДуховий" << endl;
        instrument::GetInst();
        cout << "Введіть рік: "; cin >> year;
        cout << "Введіть довжину каналу духового інструменту: "; cin >> LC;
        cout << "Введіть матеріал: "; cin >> material;
        cout << "Введіть колір: "; cin >> color;
    }
    void PutData()
    {
        cout << "\nДуховий" << endl;
        instrument::PutInst();
        cout << "\nРік: " << year;
        cout << "\nДовжина духового канала: " << LC;
        cout << "\nМатеріал: " << material;
        cout << "\nКолір: " << color << endl;
    }
};

//Фортепіано
class PianoInst : public instrument
{
protected:
    int year;
    const int NON, key;
    string material;
public:
    PianoInst() : key(85), NON(7), material("Tree"), year(2018)
    {}

    void GetData()
    {
        cout << "\nКлавішний" << endl;
        instrument::GetInst();
        cout << "Введіть рік: "; cin >> year;
        cout << "Введіть матеріал: "; cin >> material;
    }
    void PutData()
    {
        cout << "\nКлавішний" << endl;
        instrument::PutInst();
        cout << "\nРік: " << year;
        cout << "\nКількість нот: " << NON;
        cout << "\nКількість клавіш: " << key;
        cout << "\nМатеріал: " << material << endl;
    }
};

//Струнні інструменти
class StringInst : public instrument
{
protected:
    int year, NOS; //Кількість струн (NOS)
    string material, color;
public:
    StringInst() : material("Steel"), color("Red"), year(2018), NOS(0)
    {}

    void GetData()
    {
        cout << "\nСтрунний" << endl;
        instrument::GetInst();
        cout << "Введіть рік: "; cin >> year;
        cout << "Введіть кількість струн: "; cin >> NOS;
        cout << "Введіть матеріал: "; cin >> material;
        cout << "Введіть колір: "; cin >> color;
    }
    void PutData()
    {
        cout << "\nСтрунний" << endl;
        instrument::PutInst();
        cout << "\nРік: " << year;
        cout << "\nКількість струн: " << NOS;
        cout << "\nМатеріал: " << material;
        cout << "\nКолір: " << color << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 && cls");
    srand(time(NULL));
    int n = 0, s = -1, h = 2;
    bool k = true;
    char choice;
    vector <instrument*> instK;
    vector <string> orchestra;
    WindInst w;
    PianoInst p;
    StringInst st;
    cout << "   MUSIC DREAM!!!" << endl;
    while (true) {
        cout << "     Виберіть подальшу дію: " << endl;
        cout << "1. Додати інструмент" << endl;
        cout << "2. Вивести всі інструменти" << endl;
        cout << "3. Оркестр" << endl;
        cout << "0. Вихід" << endl << endl;
        cout << "music~>";
        cin >> s;
        switch (s) {

            //Ввод инструментов
        case 1: {
            do {
                cout << "Духовий (W), Струнний (S) или Клавішний(P): ";
                cin >> choice;

                if (choice == 'W' || choice == 'w')
                {
                    instK.push_back(new WindInst);
                    n++;
                }

                else if (choice == 'S' || choice == 's')
                {
                    instK.push_back(new StringInst);
                    n++;
                }

                else
                {
                    instK.push_back(new PianoInst);
                    n++;
                }

                instK[n - 1]->GetData();
                cout << "Ще інструмент (y/n)?";
                cin >> choice;
            } while (choice == 'y');
            break;
        }

              //Вивід всіх данних на екран
        case 2: {
            for (int i = 0; i < instK.size(); i++)
            {
                instK[i]->PutData();
            }
            break;
        }

              //Оркестр
        case 3: {
            cout << "Оркестр складається з: " << endl;
            for (int i = 0; i < instK.size(); i++)
            {
                orchestra.push_back(instK[i]->GetOrchestra());
            }
            for (int i = 0; i < orchestra.size(); i++)
            {
                cout << orchestra[i] << endl;
            }
            cout << endl;
            break;
        }

              //Вихід
        case 0: {
            return 0;
            break;
        }
        }
    }
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
