// Copyright 2021 asma
#pragma once
#ifndef TRAIN_H
#define TRAIN_H
#include <cstdlib>
#include <ctime>
class Cage
{
    bool light; // Ñâåò (âêë/âûêë)
public:
    Cage* next; // ñëåäóþùèé âàãîí
    Cage* prev; // ïðåäûäóùèé âàãîí
    Cage() : light(false), next(nullptr), prev(nullptr) {}
    void on() { light = true; }
    void off() { light = false; }
    bool get() const { return light; }
};
class Train
{
public:
    int length;
    Cage* arr;
    Cage* first; // óêàçàòåëü íà ïåðâûé âàãîí
    void setlen(int len) {
        this->length = len;
        arr = new Cage[this->length];
        first = arr;
    }
    Train(int len) {
        this->setlen(len);
        arr[0].next = &arr[1];
        arr[0].prev = &arr[this->length - 1];
        arr[this->length - 1].next = &arr[0];
        arr[this->length - 1].prev = &arr[this->length - 2];

        for (int i = 1; i < this->length - 1; i++)
        {
            bool light = rand() % 2;
            if (light)
                arr[i].on();
            else
                arr[i].off();

            arr[i].next = &arr[(i + 1) % this->length];
            arr[i].prev = &arr[(this->length + i - 1) % this->length];
        }
    }
};
int calculate_len(Cage* start);
Cage* come_back(Cage* start, int steps);
#endif // !TRAIN_H
