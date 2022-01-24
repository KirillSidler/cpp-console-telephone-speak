#include <iostream>

using namespace std;

#include "telephone_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #1. GIT\n";
    cout << "Variant #9. Telephone Speaks\n";
    cout << "Author: Kirill Radzko\n";

    telephone_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    float sizes;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << "Телефон........: ";
            cout << subscriptions[i]->telephone << '\n';

            cout << "Дата звонка.....: ";
            cout <<  subscriptions[i]->call.year << '-';

            cout <<  subscriptions[i]->call.month << '-';

            cout <<  subscriptions[i]->call.day;

            cout << '\n';

            cout << "Время начала........: ";
            cout << subscriptions[i]->start.hours << ' ';
            cout << subscriptions[i]->start.min << ' ';
            cout << subscriptions[i]->start.sec << '\n';

            cout << "Время конца........: ";
            cout << subscriptions[i]->end.hours << ' ';
            cout << subscriptions[i]->end.min << ' ';
            cout << subscriptions[i]->end.sec << '\n';

            cout << "Стоимость........: ";
            cout << subscriptions[i]->tarif << '\n';

            cout << "Тариф........: ";
            cout << subscriptions[i]->money << '\n';

            cout << '\n';
        }



        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    cout << "Group: 14\n";

    return 0;
}