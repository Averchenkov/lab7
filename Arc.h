#ifndef ARC_H
#define ARC_H

#include "Graph.h"
#include <string>

class Graph;

class Arc
{
	friend Graph;
private:
	std::string name_start;
	std::string name_finish;
public:
	Arc(std::string, std::string);
	~Arc();
	std::string get_start();
	std::string get_finish();
	friend std::ostream &operator <<(std::ostream &os, Graph & graph);
};

#endif