#include "train.h"

int calculate_len(Cage* start) {
	start->off();
	int counter = 0; // счётчик шагов
	int answer = 0;
	while (true) {
		if (start->get())
			break;
		start = start->next; counter++;
		while (!start->get())
		{
			start = start->next;
			counter++;
		}
		start->on();
		come_back(start, counter);
		answer = counter;
		counter = 0;
	}
	return answer;
}

void come_back(Cage* start, int steps) {
	for (int i = 0; i < steps; i++)
	{
		start = start->prev;
	}
}