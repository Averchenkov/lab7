#include "Arc.h"
#include <iostream>
#include <string>

using namespace std;

Arc::Arc(string name_start, string name_finish)
{
	this->name_start = name_start;
	this->name_finish = name_finish;
}
Arc::~Arc()
{
}
string Arc::get_start()
{
	return name_start;
}
string Arc::get_finish()
{
	return name_finish;
}