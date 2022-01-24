#include <iostream>

using namespace std;

#include "telephone_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #1. GIT\n";
    cout << "Variant #9. Telephone speaks\n";
    cout << "Author: Kirill Radzko\n";
    telephone_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << "�������........: ";
            cout << subscriptions[i]->telephone << '\n';

            cout << "���� ������.....: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->call.year << '-';

            cout << setw(2) << setfill('0') << subscriptions[i]->call.month << '-';

            cout << setw(2) << setfill('0') << subscriptions[i]->call.day;
            cout << '\n';

            cout << "����� ������........: ";
            cout << subscriptions[i]->start.hours << ' ';
            cout << subscriptions[i]->start.min << ' ';
            cout << subscriptions[i]->start.sec << '\n';

            cout << "����� �����........: ";
            cout << subscriptions[i]->end.hours << ' ';
            cout << subscriptions[i]->end.min << ' ';
            cout << subscriptions[i]->end.sec << '\n';

            cout << "�����........: ";
            cout << subscriptions[i]->tarif << '\n';

            cout << "C��������........: ";
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
    return 0;
}