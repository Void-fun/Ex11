#pragma once
#ifndef TRAIN_H
#define TRAIN_H

class Train
{
public:
    int length;
    Cage* arr;
    Cage* first = arr; // ��������� �� ������ �����

    void setlen(int len) {
        this->length = len;
        delete[] arr;
        arr = new Cage[this->length];
    }
    Train(int len) {
        this->setlen(len);
        for (int i = 0; i < this->length; i++)
        {
            arr[i].next = &arr[(i + 1) % this->length];
            arr[i].prev = &arr[(length + i - 1) % this->length];
        }
    }

};

class Cage
{
    bool light; // ���� (���/����)
public:
    Cage* next; // ��������� �����
    Cage* prev; // ���������� �����
    Cage() : light(false), next(nullptr), prev(nullptr) {}
    void on() { light = true; }
    void off() { light = false; }
    bool get() const { return light; }
};

int calculate_len(Cage* start);
void come_back(Cage* start, int steps);
#endif // !TRAIN_H

