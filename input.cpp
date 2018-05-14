#include "function.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void input(Graph &graph, bool &f)
{
	string input;
	std::cin >> input;

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
			fromfile >> graph;
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
			infile << graph;
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