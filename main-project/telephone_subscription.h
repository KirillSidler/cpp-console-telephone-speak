#ifndef TELEPHONE_SUBSCRIPTION_H
#define TELEPHONE_SUBSCRIPTION_H

#include "constants.h"

struct telephone
{
    char name[MAX_STRING_SIZE];

};

struct date
{
    int day;
    int month;
    int year;
};

struct times
{
    int hours;
    int min;
    int sec;
};

struct tarif
{
    char name[MAX_STRING_SIZE];

};

struct cena
{
    char money;

};

struct telephone_subscription
{
    char telephone[MAX_STRING_SIZE];
    date call;
    times start;
    times end;
    char tarif[MAX_STRING_SIZE];
    char money[MAX_STRING_SIZE];
};

#endif#pragma once
