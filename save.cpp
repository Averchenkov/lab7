#include <iostream>
#include "function.h"

using namespace std;


ostream &operator <<(ostream &os, Graph & graph)
{
	for(auto it = graph.vertex.begin(); it != graph.vertex.end(); it++)
    {
        os << it->name << " ";
    }
    cout << endl;

    for(auto it = graph.arc.begin(); it != graph.arc.end(); it++)
    {
    	os << it->name_start << " " << it->name_finish << endl;
    }
    return os;
}