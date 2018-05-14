#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;

Graph::Graph()
{
}
Graph::~Graph()
{
}
Graph::Graph(const Graph &graph)
{
	vertex.clear();
	vertex = graph.vertex;
}
Graph &Graph::operator =(const Graph & graph)
{
	vertex.clear();
	vertex = graph.vertex;
	return *this;
}

ostream &operator <<(ostream &os, Graph & graph)
{
	os << graph.vertex.size() << endl;
	for(auto it = graph.vertex.begin(); it != graph.vertex.end(); it++)
    {
        os << it->name << " ";
    }
    os << endl;


    os << graph.arc.size() << endl;
    for(auto it = graph.arc.begin(); it != graph.arc.end(); it++)
    {
    	os << it->name_start << " " << it->name_finish << endl;
    }
    return os;
}

istream & operator>>(istream &is, Graph &graph)
{
  graph.vertex.clear();
  graph.arc.clear();
  unsigned int sizeVertex;
  is >> sizeVertex;
  for(unsigned int i = 0; i < sizeVertex; i++)
  {
    string name;
    is >> name;
    graph.vertex.push_back(Vertex(name));
  }
  unsigned int sizeArc;
  is >> sizeArc;
  for(unsigned int i = 0; i < sizeArc; i++)
  {
    string name_start, name_finish;
    is >> name_start >> name_finish;
    graph.arc.push_back(Arc(name_start,name_finish));
  }
  return is;
}

bool Graph::check_vertex_name(string name)
{
	bool f = false;
	for(auto it = vertex.begin(); it != vertex.end(); it++)
    {
        if (it->name == name) 
    	{
    		f = true;
    		break;
    	}
    }
    return f;
}
bool Graph::check_arc_name(string name_start, string name_finish)
{
	bool f = false;
	for(auto it = arc.begin(); it != arc.end(); it++)
    {
        if ((it->name_start == name_start) && (it->name_finish == name_finish)) 
    	{
    		f = true;
    		break;
    	}
    }
    return f;
}
void Graph::new_vetex(string name)
{	
	if (!check_vertex_name(name)) vertex.push_back(Vertex(name));
	else cout << "This vertex already exist" << endl;
}
void Graph::connected(string name_start, string name_finish)
{
	if(!check_arc_name(name_start, name_finish) && !check_arc_name(name_finish, name_start))
	{
		if(check_vertex_name(name_start))
		{
			if(check_vertex_name(name_finish))
			{
				arc.push_back(Arc(name_start, name_finish));
			}
			else cout << "There is no vertex with name " << name_finish << endl;
		}
		else cout << "There is no vertex with name " << name_start << endl;
	}
	else cout << "This arc already exist" << endl;
}
void Graph::delete_vertex(string name)
{
	bool f = false;
	for(auto it = vertex.begin(); it != vertex.end(); it++)
    {
        if (it->name == name) 
    	{
    		vertex.erase(it);
    		f = true;
    		break;
    	}
    }
    if(f) 
	{
		for(auto it = arc.begin(); it != arc.end(); it++)
	    {
	        if ((it->name_start == name) || (it->name_finish == name)) 
        	{
        		arc.erase(it);
        		break;
        	}
	    }
	}
	else cout << "There is no this vertex" << endl;
}
void Graph::delete_arc(string name_start, string name_finish)
{
	bool f = false;
	for(auto it = arc.begin(); it != arc.end(); it++)
    {
        if ((it->name_start == name_start) && (it->name_finish == name_finish)) 
    	{
    		arc.erase(it);
    		f = true;
    		break;
    	}
    }
    if (!f) cout << "There is no this arc" << endl;
}
void Graph::rename_vertex(string old_name, string new_name)
{
	if(!check_vertex_name(new_name))
	{
		bool f = false;
		for(auto it = vertex.begin(); it != vertex.end(); it++)
	    {
	        if (it->name == old_name) 
        	{
        		it->name = new_name;
        		f = true;
        		break;
        	}
	    }
	    if (f)
	    {
	    	for(auto it = arc.begin(); it != arc.end(); it++)
		    {
		        if (it->name_start == old_name)
	        	{
	        		it->name_start = new_name;
	        		break;
	        	}
	        	else if (it->name_finish == old_name)
	        	{
	        		it->name_finish = new_name;
	        		break;
	        	}
		    }
	    }
	    else cout << "There is no vertex with name " << old_name << endl;
	}
	else cout << "Vertex with name " << new_name << " already exist" << endl;
}
void Graph::output_vertex()
{
	for(auto it = vertex.begin(); it != vertex.end(); it++)
    {
        cout << it->name << " ";
    }
    cout << endl;
}
void Graph::output_arc_start(string name_start)
{
	for(auto it = arc.begin(); it != arc.end(); it++)
    {
        if (it->name_start == name_start)
    	{
    		cout << it->name_start << " " << it->name_finish << endl;
    	}
    }
}
void Graph::output_arc_finish(string name_finish)
{
	for(auto it = arc.begin(); it != arc.end(); it++)
    {
        if (it->name_finish == name_finish)
    	{
    		cout << it->name_start << " " << it->name_finish << endl;
    	}
    }
}
void Graph::output_arc()
{
	for(auto it = arc.begin(); it != arc.end(); it++)
    {
    	cout << it->name_start << " " << it->name_finish << endl;
    }
}