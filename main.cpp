#include "Graph.h"
#include "function.h"

int main()
{
	Graph *graph = new Graph();

	menu();
	bool f = true;
	while(f)
	{
		input(*graph, f);
	}
}