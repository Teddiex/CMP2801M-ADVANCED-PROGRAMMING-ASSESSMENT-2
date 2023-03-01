#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include "getError.h"

#include <iostream>
#include <string>
#include <exception>
#include <vector>



using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands


	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// implement a string tokenizer to populate the parameters vector 
		char* nextToken;
		char* token = strtok_s(cstr, " ", &nextToken);
		while (token != 0)
		{
			parameters.push_back(token);
			token = strtok_s(0, " ", &nextToken);
		}

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		string command = parameters[0];



		try
		{
			if (command.compare("addR") == 0) {
				if (parameters.size() == 5)
				{
				
					int x = stoi(parameters[1].c_str());
					int y = stoi(parameters[2].c_str());
					if (stoi(parameters[3].c_str()) <= 0 || stoi(parameters[4].c_str()) <= 0)
					{
						throw getError("Invalid parameter given");
					}
					int h = stoi(parameters[3].c_str());
					int w = stoi(parameters[4].c_str());


					Rectangle* rectangle = new Rectangle(x, y, h, w);
					shapes.push_back(rectangle);
					cout << rectangle; 
				}
				else
				{
					throw getError("Enter the correct number of parameters");
				}
			}
			else if (command.compare("addS") == 0) {
				if (parameters.size() == 4)
				{
					// get parameters
					int x = stoi(parameters[1].c_str());
					int y = stoi(parameters[2].c_str());
					if (stoi(parameters[3].c_str()) <= 0)
					{
						throw getError("Edge size must be greater than 0");
					}
					int edge = stoi(parameters[3].c_str());
					Square* square = new Square(x, y, edge);
					shapes.push_back(square);
					cout << square;
				}
				else
				{
					throw getError("Enter the correct parameters");
				}
			}

			else if (command.compare("addC") == 0) {
				// get parameters
				if (parameters.size() == 4)
				{
					int x = stoi(parameters[1].c_str()); 
					int y = stoi(parameters[2].c_str());

					if (stoi(parameters[3].c_str()) <= 0)
					{
						throw getError("Radius cannot be less than 0");
					}


					int r = stoi(parameters[3].c_str());
					// ...
					Circle* circle = new Circle(x, y, r);
					shapes.push_back(circle);
					cout << circle;
				}
				else
				{
					throw getError("Enter the correct parameters");
				}
			}
			else if (command.compare("scale") == 0) 
			{
				if (parameters.size() != 4) 
				{
					throw getError("Invalid number of parameters");
				}
				// forgot that stoi is string to int, thus I was losing data when trying to scale by a decimal value, changed to stof
				int position = stoi(parameters[1]) - 1;
				float xScale = stof(parameters[2].c_str());
				float yScale = stof(parameters[3].c_str());

				string value = shapes.at(position)->toString();

				//feel like this is a very weird way of doing it, but I couldn't work out how to get it to work any other way.
				if (position <= shapes.size() && position >= 0)
				{

					if (value.substr(0, 6) == "Circle")
					{
						dynamic_cast<Movable*>(shapes[position])->scale(xScale, yScale);
						cout << shapes[position]->toString();
					}
					else if (value.substr(0, 6) == "Square")
					{
						dynamic_cast<Movable*>(shapes[position])->scale(xScale, yScale);
						cout << shapes[position]->toString();
					}
					else if (value.substr(0, 9) == "Rectangle")
					{
						dynamic_cast<Movable*>(shapes[position])->scale(xScale, yScale);
						cout << shapes[position]->toString();
					}
				}
				else
				{
					throw getError("Invalid Shape position");

				}

			}
			else if (command.compare("move") == 0)
			{
				
				if (parameters.size() != 4) 
				{
					throw getError("Invalid number of parameters");
				}
				
				int shapeNo = stoi(parameters[1].c_str()); // read from parameters
				int x = stoi(parameters[2].c_str());
				int y = stoi(parameters[3].c_str());
				// you may want to check if the index exists or not!

				if (shapeNo <= shapes.size() && shapeNo >= 0 && shapeNo != 0)
				{
					//casting value so I do not get an arithmetic overflow, was using '-' on a 4byte value and then casting to an 8 byte
					Movable* m = dynamic_cast<Movable*>(shapes[static_cast<std::vector<Shape*, std::allocator<Shape*>>::size_type>(shapeNo) - 1]);
					m->move(x, y);
				
					cout << shapes[static_cast<std::vector<Shape*, std::allocator<Shape*>>::size_type>(shapeNo) - 1]->toString();
				}
				else
				{
					throw getError("Invalid Shape Position");
				}
			}

			else if (command.compare("display") == 0)
			{
				if (shapes.size() != 0) 
				{
					for (auto i : shapes)
					{
						cout << i->toString() << endl;
					}
				}
				else 
				{
					throw getError("No shapes to display");
				}
				
				
			}
			else if (command.compare("clear") == 0) 
			{
				for (auto i : shapes) 
				{
					delete i;
					shapes.clear();
				} //deallocating memory for shapes.
			}
			
			cout << endl << endl;
			if (command != "exit")
			{
				//some cleanup
				userCommand.clear();
				command.clear();
				parameters.clear();
			}
		}
		catch (getError e)
		{
			cout << e.getErrorMsg() << std::endl;
			userCommand.clear();
			command.clear();
			parameters.clear();
		}

	}
	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
