/*
	An animal shelter holds only dogs and cats, and operates ona strictly 
	¡°first in, first out¡± basis. People must adopt either the ¡°oldest¡±
	(based on arrival time) of all animals at the shelter, or they can 
	selectwhether they could prefer a dog or a cat (and will receive the 
	oldest animal ofthat type). They cannot select which specific animal 
	they would like. Createthe data structures to maintain this system and 
	implement operations such as enqueue, dequeueAny, dequeueDog and dequeueCat. 
	You may use the built-inLinkedList data structure.
*/
#include <queue>
using namespace std;

enum Animal
{
	Dog,
	Cat,
	Other
};

class Shelter
{
public:
	Shelter() : dogNum(0), catNum(0){}

	void Enqueue(const Animal& animal);
	void DequeueAny();
	void DequeueDog();
	void DequeueCat();

private:
	queue<Animal> q;
	int dogNum;
	int catNum;

};
