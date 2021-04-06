#pragma once
#ifndef CAGE_H
#define CAGE_H

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
#endif // !CAGE_H

