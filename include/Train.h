#pragma once
#ifndef TRAIN_H
#define TRAIN_H
#include "Cage.h"

class Train
{
public:
    int length = rand() % 100;
    Cage* arr = new Cage[this->length];
    Cage* first = arr; // указатель на первый вагон

    void setlen(size_t len) {
        this->length = len;
    }
    Train(size_t len) {
        this->setlen(len);
        for (size_t i = 0; i < this->length; i++)
        {
            arr[i].next = &arr[(i + 1) % this->length];
            arr[i].prev = &arr[(length + i - 1) % this->length];
        }
    }

}
#endif // !TRAIN_H

