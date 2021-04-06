#include "Train.h"
#include <iostream>

int calculate_len(Cage *start);
void come_back(Cage *start, size_t steps);

int main() {
	//srand(time(NULL));
	size_t len = 20;
	Train train(len);
	std::cout << calculate_len(train.first) << len << std::endl;

	return 0;
}

int calculate_len(Cage *start) {
	start->off();
	size_t counter = 0; // счётчик шагов
	size_t answer = 0;
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

void come_back(Cage *start, size_t steps) {
	for (size_t i = 0; i < steps; i++)
	{
		start = start->prev;
	}
}