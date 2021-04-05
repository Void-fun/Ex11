#pragma once
#ifndef CAGE_H
#define CAGE_H
#include <cstdlib>
#include <ctime>

class Cage
{
    bool light; // Свет (вкл/выкл)
public:
    Cage* next; // следующий вагон
    Cage* prev; // предыдущий вагон
    Cage() : light(false), next(nullptr), prev(nullptr) {}
    void on() { light = true; }
    void off() { light = false; }
    bool get() const { return light; }
};

class Train
{
public:
    int length = rand() % 100;
    Cage* arr = new Cage[this->length];
    Cage* first = arr; // указатель на первый вагон

    Train() {
        for (size_t i = 0; i < this->length; i++)
        {
            arr[i].next = &arr[(i + 1) % this->length];
            arr[i].prev = &arr[(length+ i - 1) % this->length];
        }
    }
    
}
#endif // !CAGE_H

