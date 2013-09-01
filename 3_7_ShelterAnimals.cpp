#include <iostream>

#include "3_7_ShelterAnimals.h"

using namespace std;

void Shelter::Enqueue(const Animal& animal)
{
	if (animal == Animal::Cat)
	{
		++catNum;
	}
	if (animal == Animal::Dog)
	{
		++dogNum;
	}
	q.push(animal);
}

void Shelter::DequeueAny()
{
	if (q.empty())
	{
		throw new exception("Empty");
	}
	q.pop();
}

void Shelter::DequeueDog()
{
	if (dogNum == 0)
	{
		throw new exception("There is no dog");
	}
	while (!q.empty() && (q.front() != Animal::Dog))
	{
		q.pop();
	}
	q.pop();
	dogNum--;
}

void Shelter::DequeueCat()
{
	if (catNum == 0)
	{
		throw new exception("There is no cat");
	}
	while (!q.empty() && (q.front() != Animal::Cat))
	{
		q.pop();
	}
	q.pop();
	catNum--;
}
