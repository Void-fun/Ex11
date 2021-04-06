#pragma once
#ifndef CAGE_H
#define CAGE_H

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
#endif // !CAGE_H

