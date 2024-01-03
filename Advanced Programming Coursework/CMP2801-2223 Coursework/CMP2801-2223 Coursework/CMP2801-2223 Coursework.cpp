/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

//all header files needed for this file to run
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

//all pre-defined header files needed for this file to run
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;

//function that checks every input other than the command to ensure all inputted characters are digits
//exceptions made for '-' and '.' characters so negatives and decimals can be excepted
bool checkForInts(vector<string> parameters, int n)
{
	bool check = true;
	for (int i = 0; i < n; i++) //loop through parameters
	{
		char* str = new char[parameters[i + 1].length() + 1]; //change parameter to characyer array
		strcpy_s(str, parameters[i + 1].length() + 1, parameters[i + 1].c_str());
		for (int j = 0; j < strlen(str); j++) //loop through characters of parameter
		{
			if (not isdigit(str[j]) and str[j]!='-' and str[j]!='.') //check if character isnt a digit or a '.' or '-'
			{
				check = false;
				break;
			}
			else if (str[j] == '-') //if character '-'
			{
				if (strlen(str) > 1 and j == 0) //'-' must be first symbol in parameter and parameter size must be grater than 1
				{
					if (not isdigit(str[j + 1])) //charatcer following '-' must be a digit
					{
						check = false;
						break;
					}
				}
				else
				{
					check = false;
					break;
				}
			}
			else if (str[j] == '.') //if character '.'
			{
				if (j != 0 and j != strlen(str) - 1) //'.' must not be first or last character in parameter
				{
					if (not isdigit(str[j - 1]) or not isdigit(str[j + 1])) //cannot be precede or be preceded by a non digit
					{
						check = false;
						break;
					}
				}
				else
				{
					check = false;
					break;
				}
			}
		}
	}
	return check; //returns true if all characters are digits, else false
}

int main()
{
	int a = -5;
	int b = 3;
	string userCommand;			// holds parameter[0] (the command addR, move etc...)
	vector <Shape*> shapes;     // holds pointers to shapes
	vector <string> parameters; // holds inputed parameters

	//token pointers
	char* token; 
	char* nextToken;

	//variables where appropriate parameters are storred
	string command;
	int x;
	int y;
	int h;
	int w;
	int e;
	int r;
	int shapeNo;
	float xScalar;
	float yScalar;

	//will continue to loop until the user type 'exit' 
	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand); //user input saved to userCommand
		char* cstr = new char[userCommand.length() + 1]; //create an array of characters 
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str()); //populate the character array using the user input

		//turns the inputted string into tokens, using a blank space as an identifier for where a token ends
		//tokens are storred in the parameters vector
		token = strtok_s(cstr, " ", &nextToken);
		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok_s(NULL, " ", &nextToken);
		}

		if (parameters.size() == 0)
		{
			command = "error";
		}
		else
		{
			command = parameters[0]; //get the command
		}
		

		//if command is 'addR' create a rectangle using the given parameters, if they are acceptable
		if (command.compare("addR") == 0) 
		{
			try
			{
				if (parameters.size() == 5) //rectangle command must have 5 parameters
				{
					bool check = checkForInts(parameters,4); //check all appropriate parameters contain only digits
					if (check)
					{
						//assign parameters
						x = stoi(parameters[1].c_str());
						y = stoi(parameters[2].c_str());
						h = stof(parameters[3].c_str());
						w = stof(parameters[4].c_str());
						if (h > 0 and w > 0) //cannot have 0 or negative length to sides of shape
						{
							Rectangle* r = new Rectangle(x, y, h, w); //instansiate rectangle using given parameters
							shapes.push_back(r); //push rectngle pointer into vector
							cout << *r; //display rectsngle information
						}
						else //error message for w and h parameters being <=0
						{
							string s = "Cannot have rectange with sides of length 0";
							throw(s);
						}
					}
					else //error message for parameters containing non digits
					{
						string s = "Incorrect parameters inputted";
						throw (s);
					}
				}
				else if (parameters.size() < 5) //when too few parameters are inputted
				{
					string s = "Too few parameters inputted";
					throw (s);
				}
				else //if parameters not equal to 5 or <5, must be greater than 
				{
					string s = "Too many parameters inputted";
					throw (s);
				}
			}
			catch(string s) //where error messages are thrown to, and outputted
			{
				cout << s << endl;
			}
		}

		//if command is 'addS' create a square using the given parameters, if they are acceptable
		else if (command.compare("addS") == 0) 
		{

			try
			{
				if (parameters.size() == 4) //square command must have 4 parameters
				{
					bool check = checkForInts(parameters,3); //check all appropriate parameters contain only digits
					if (check)
					{
						//assign appropriate parameters to variables
						x = stoi(parameters[1].c_str());
						y = stoi(parameters[2].c_str());
						e = stof(parameters[3].c_str());
						if (e > 0) //side length of a square cannot be 0 or negative
						{
							Square* s = new Square(x, y, e); //instantiate square using given parameters
							shapes.push_back(s); //push sqy=uare pointer into vector
							cout << *s; //output square values to console
						}
						else //error message if square side lengths are innappropriate
						{
							string s = "Cannot have square with sides of length 0";
							throw(s);
						}
					}
					else //error message if inputs are not digits
					{
						string s = "Incorrect parameters inputted";
						throw (s);
					}
				}
				else if (parameters.size() < 4) //error message if too few parameters
				{
					string s = "Too few parameters inputted";
					throw (s);
				}
				else //error message if too many parameters are inputted
				{
					string s = "Too many parameters inputted";
					throw (s);
				}
			}
			catch (string s) //where error messages are thrown to, and outputted
			{
				cout << s << endl;
			}
		}

		//if command is 'addC' create a circle using the given parameters, if they are acceptable
		else if (command.compare("addC") == 0) 
		{

			try
			{
				if (parameters.size() == 4) //circle command must have 4 parameters
				{
					bool check = checkForInts(parameters,3); //check all appropriate parameters contain only digits
					if (check) //all appropriate parameters must be digits
					{
						//assign appropriate parameters to variables
						x = stoi(parameters[1].c_str());
						y = stoi(parameters[2].c_str());
						r = stof(parameters[3].c_str());
						if (r > 0) //radius of a circe cannot be zero or negative
						{
							Circle* c = new Circle(x, y, r); //instansiate circle using parameters
							shapes.push_back(c); //push circle pointer into vector
							cout << *c; //display circle information
						}
						else //error message if circle radius innappropriate
						{
							string s = "Cannot have circle with radius 0";
							throw(s);
						}
					}
					else //error message if parameters contain non digits
					{
						string s = "Incorrect parameters inputted";
						throw (s);
					}
				}
				else if (parameters.size() < 4) //error message if too few parameters
				{
					string s = "Too few parameters inputted";
					throw (s);
				}
				else //error message if too many parameters
				{
					string s = "Too many parameters inputted";
					throw (s);
				}
			}
			catch (string s) //where error messages are thrown to, and outputted
			{
				cout << s << endl;
			}

		}

		//if command is 'sclae' change the dimensions of the chosen shape, if the parameters are acceptable
		else if (command.compare("scale") == 0) 
		{

			try
			{
				if (parameters.size() == 4) //size command must have 4 parameters
				{
					bool check = checkForInts(parameters, 3); //check all appropriate parameters contain only digits
					if (check) 
					{
						//assign appropriate parameters to variables
						shapeNo = stoi(parameters[1].c_str());
						xScalar = stof(parameters[2].c_str());
						yScalar = stof(parameters[3].c_str());

						//shapeNo must be in a specific range, so the index isnt out of range
						//x and y cannot be 0 or negative or scale wont work properly
						if (shapeNo > 0 and shapeNo <= shapes.size() and xScalar > 0 and yScalar > 0) 
						{
							Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]); //cast pointer to moveable base class
							m->scale(xScalar, yScalar); //scale shape
							cout << *shapes[shapeNo - 1]; //output shape to the console
						}
						else //error message when index out of range or 0, negative x/y coords
						{
							string s = "Invalid input";
							throw(s);
						}
					}
					else //error message when parameters contain non digits
					{
						string s = "Incorrect parameters inputted";
						throw (s);
					}
				}
				else if (parameters.size() < 4) //error message if there are too few parameters
				{
					string s = "Too few parameters inputted";
					throw (s);
				}
				else //error message if there are too many parameters
				{
					string s = "Too many parameters inputted";
					throw (s);
				}
			}
			catch (string s) //where error messages are thrown to, and outputted
			{
				cout << s << endl;
			}
		}

		//if command is 'move' create move the chosen shape to the new coordinates, if the parameters are acceptable
		else if (command.compare("move") == 0) 
		{ 

			try
			{
				if (parameters.size() == 4) //move command must have 4 parameters
				{
					bool check = checkForInts(parameters, 3); //check all appropriate parameters contain only digits
					if (check)
					{
						//assign appropriate parameters to variables
						shapeNo = stoi(parameters[1].c_str());
						x = stoi(parameters[2].c_str());
						y = stof(parameters[3].c_str());

						if (shapeNo > 0 and shapeNo <= shapes.size()) //check index is valid
						{
							Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]); //cast shape to moveable
							m->move(x, y); //move shape
							cout << *shapes[shapeNo - 1]; //out result of move to console
						}
						else //error message if an invalid index is given
						{
							string s = "Invalid Index";
							throw(s);
						}
					}
					else //error message if parameter contains non digits
					{
						string s = "Incorrect parameters inputted";
						throw (s);
					}
				}
				else if (parameters.size() < 4) //error message when too few parameters are inputted
				{
					string s = "Too few parameters inputted";
					throw (s);
				}
				else //error message if too many parameters are inputted
				{
					string s = "Too many parameters inputted";
					throw (s);
				}
			}
			catch (string s) //where error messages are thrown to, and outputted
			{
				cout << s << endl;
			}
		}

		//display all shapes that have been created, or a message if there are none
		else if (command.compare("display") == 0) 
		{

			if (shapes.size() > 0) //if the vector contains any shapes
			{
				for (int i = 0; i < shapes.size(); i++) //loop through all existing shapes
				{
					cout << *shapes[i] << endl; //output shape to console
				}
			}
			else //message if there are no shapes to display
			{
				cout << "No shapes to display" << endl;
			}
		}

		//destroy all current shapes, then clear the shapes vector, give an appropriate message if there are no shapes
		else if (command.compare("clear") == 0)
		{
			if (shapes.size() > 0) //if the vector contains any shapes
			{
				for (int i = 0; i < shapes.size(); i++) //loop through all existing shapes
				{
					shapes[i]->~Shape(); //destroy shape
				}
				shapes.clear(); //clear addresses from vector
				cout << "Shapes cleared" << endl; //message so user knows command did something
			}
			else //message if there were no shapes to destroy
			{
				cout << "No shapes to destroy" << endl;
			}
			
		}

		//give approprite message to the user if their command is not an accepted one
		else
		{
			cout << "Please enter a correct command" << endl;
		}

		parameters.clear(); //clear parameters vector after each itteration of the while loop
		cout << endl << endl; //leave to lines gap between user commands
	}

	//destory all shapes, clear memory before ending program
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->~Shape();
	}
	shapes.clear();

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
