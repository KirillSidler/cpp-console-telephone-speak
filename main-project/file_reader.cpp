#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

times convert(char* str)
{
    times result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hours = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.min = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.sec = atoi(str_number);
    return result;
}

date converts(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.year = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.day = atoi(str_number);
    return result;
}

void read(const char* file_name, telephone_subscription* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            telephone_subscription* item = new telephone_subscription;
            file >> item->telephone;
            file >> tmp_buffer;
            item->call = converts(tmp_buffer);
            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->end = convert(tmp_buffer);
            file >> item->money;

            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->tarif, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}