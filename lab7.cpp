#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Vertex;
class Arc;
class Graph;

class Vertex
{
	friend Graph;
private:
	string name;
public:
	Vertex(string name)
	{
		this->name = name;
	}
	~Vertex()
	{
	}
	string get()
	{
		return name;
	}
	void set(string name)
	{
		this->name = name;
	}
	Vertex(const Vertex &other)
	{
		name = other.name;
	}

};

class Arc
{
	friend Graph;
private:
	string name_start;
	string name_finish;
public:
	Arc(string name_start, string name_finish)
	{
		this->name_start = name_start;
		this->name_finish = name_finish;
	}
	~Arc()
	{
	}
	string get_start()
	{
		return name_start;
	}
	string get_finish()
	{
		return name_finish;
	}
};

class Graph
{

private:
	std::vector<Vertex> vertex;
	std::vector<Arc> arc;
public:
	Graph()
	{
	}
	~Graph()
	{
	}
	Graph(const Graph &graph)
	{
		vertex.clear();
		vertex = graph.vertex;
	}
	Graph &operator =(const Graph & graph)
	{
		vertex.clear();
		vertex = graph.vertex;
		return *this;
	}
	bool check_vertex_name(string name)
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
	bool check_arc_name(string name_start, string name_finish)
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
	void new_vetex(string name)
	{	
		if (!check_vertex_name(name)) vertex.push_back(Vertex(name));
		else cout << "This vertex already exist" << endl;
	}
	void connected(string name_start, string name_finish)
	{
		if(!check_arc_name(name_start, name_finish))
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
	void delete_vertex(string name)
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
	void delete_arc(string name_start, string name_finish)
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
	void rename_vertex(string old_name, string new_name)
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
	void output_vertex()
	{
		for(auto it = vertex.begin(); it != vertex.end(); it++)
	    {
	        cout << it->name << " ";
	    }
	    cout << endl;
	}
	void output_arc_start(string name_start)
	{
		for(auto it = arc.begin(); it != arc.end(); it++)
	    {
	        if (it->name_start == name_start)
        	{
        		cout << it->name_start << " " << it->name_finish << endl;
        	}
	    }
	}
	void output_arc_finish(string name_finish)
	{
		for(auto it = arc.begin(); it != arc.end(); it++)
	    {
	        if (it->name_finish == name_finish)
        	{
        		cout << it->name_start << " " << it->name_finish << endl;
        	}
	    }
	}
	void output_arc()
	{
		for(auto it = arc.begin(); it != arc.end(); it++)
	    {
        	cout << it->name_start << " " << it->name_finish << endl;
	    }
	}
};

void output()
{
	cout << "Menu:" << endl;
	cout << "add(vertex)" << endl;
	cout << "connected" << endl;
	cout << "delete vertex" << endl;
	cout << "delete arc" << endl;
	cout << "rename(vertex)" << endl;
	cout << "save" << endl;
	cout << "open" << endl;
	cout << "print vertex" << endl;
	cout << "print start" << endl;
	cout << "print finish" << endl;
	cout << "print arc" << endl;
	cout << "exit" << endl;
	cout << endl;
}

void input(Graph &graph, bool &f)
{
	string input;
	cin >> input;

	if(input == "add")
	{
		string name;
		cin >> name;
		graph.new_vetex(name);
		f = true;
	}
	else if(input == "connected")
	{
		string name_start;
		string name_finish;
		cin >> name_start;
		cin >> name_finish;
		graph.connected(name_start, name_finish);
		f = true;
	}
	else if(input == "delete")
	{
		cin >> input;
		if(input == "vertex")
		{
			string name;
			cin >> name;
			graph.delete_vertex(name);
			f = true;
		}
		else if(input == "arc")
		{
			string name_start;
			string name_finish;
			cin >> name_start;
			cin >> name_finish;
			graph.delete_arc(name_start, name_finish);
			f = true;
		}
	}
	else if(input == "rename")
	{
		string old_name;
		string new_name;
		cin >> old_name;
		cin >> new_name;
		graph.rename_vertex(old_name, new_name);
		f = true;
	}
	else if(input == "print")
	{
		cin >> input;
		if(input == "vertex")
		{
			graph.output_vertex();
			f = true;
		}
		else if(input == "start")
		{
			string name_start;
			cin >> name_start;
			graph.output_arc_start(name_start);
			f = true;
		}
		else if(input == "finish")
		{
			string name_finish;
			cin >> name_finish;
			graph.output_arc_finish(name_finish);
			f = true;
		}
		else if(input == "arc")
		{
			graph.output_arc();
			f = true;
		}
	}
	else if(input == "open")
	{
		string name_file;
		cin >> name_file;
		ifstream fromfile;
		fromfile.open(name_file);
		if(fromfile.is_open())
		{
			fromfile.read((char*)&graph, sizeof(graph));
		}
		fromfile.close();
		f = true;
	}
	else if(input == "save")
	{
		string name_file;
		cin >> name_file;
		ofstream infile;
		infile.open(name_file);
        if(infile.is_open())
        {
			infile.write((char*)&graph, sizeof(graph));
		}
		infile.close();
		f = true;
	}
	else if(input == "exit")
	{	
		f = false;
	}
	else
	{
		cout << "There is no this instruction" << endl;
		f = true; 
	}
}

int main()
{
	Graph *graph = new Graph();

	output();
	bool f = true;
	while(f)
	{
		input(*graph, f);
	}
}