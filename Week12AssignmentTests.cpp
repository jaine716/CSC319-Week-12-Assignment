/* GitHub requirement: you must commit/push 
                       (private repository-free with the student pack)
                       your project to your GitHub Account
   insert your name: Jaine E. Perotti
   insert your github user: jaine716
   insert your project name in github: https://github.com/jaine716/CSC319-Week-12-Assignment
   invite as a collaborator: mmail002

   once completed, you must upload it to GitHub

	you may have to modify the .h, .cpp and Week12AssignmentTest.cpp for this assignment
*/

#include <cassert>
#include <algorithm>  //sort

#include "Week12Assignment.h"

using std::string;
using std::istringstream;
using std::cout;
using std::endl;
using std::max;

void myFunction1() {
	Square s(11, 22, "small square", 4);
	Rectangle r(11, 22, "small rectangle", 2, 3);

	vector<Shape *>  shapes;

	int sumSurface = 0;

	//you must insert both s and r in shapes
	//then do the sum of their surface using
	//an iterator to access the 'Shape' in shapes
	//use sumSurface as an accumulator

	//add the address of the shapes to the vector
	shapes.push_back(&s);
	shapes.push_back(&r);

	//add the surface areas of the shapes
	for(auto it = shapes.begin(); it!= shapes.end(); it++)
		sumSurface += (*it)->getSurface();
	
	cout << sumSurface << endl;

	//check if sumSurface is correct
	assert( sumSurface == 22);
}

void myFunction2() {
	Square s(11, 22, "small square", 2);
	Rectangle r(11, 22, "small rectangle", 4, 5);

	vector<Shape *>  shapes;

	//you must insert both s and r in shapes
	//then sort the collection in descending order of surface
	//using the sort <algorithm>

	//insert your code here

	shapes.push_back(&s);
	shapes.push_back(&r);

	//sort the shapes
	stable_sort(shapes.begin(), shapes.end(),
			[]( Shape * shape1, Shape * shape2) 
			{return shape1->getSurface() >= shape2->getSurface();});

	//check if the collection is sorting correctly
	Shape * sresult = shapes.at( 0 );

	assert( sresult->getSurface() == 20);
}

void myFunction3() {
	Square s(11, 22, "small square", 2);
	Rectangle r(11, 22, "small rectangle", 4, 5);

	vector<Shape *>  shapes;

	shapes.push_back(&s);
	shapes.push_back(&r);

	//you must insert both s and r in shapes
	//then find the Shape with the biggest surface
	//you must used a function in <algorithm>
	//store the result in biggest
	Shape * biggest = nullptr;
	
	//insert your code here

	//find the shape with the larger surface area
	auto temp = max_element(shapes.begin(), shapes.end(),
				[](Shape* s1, Shape* s2) 
				{return s1->getSurface() <= s2->getSurface();});

	biggest = *temp;

	//check if the result is correct
	assert( biggest->getSurface() == 20);
}

const string SMALL_RECTANGLE = "small rectangle";

void myFunction4() {
	Square * s = new Square(11, 22, "small square", 2);
	Rectangle * r = new Rectangle(11, 22, SMALL_RECTANGLE, 2, 3);

	map<string, Shape *> shapes;

	//you must insert both s and r in shapes
	//then find the Shape with the name SMALL_RECTANGLE
	//you must used a function in map, to find it
	Shape * smallRectangle = nullptr;

	//map the names to the shapes
	shapes.insert(pair<string,Shape*>(s->getName(),s));
	shapes.insert(pair<string,Shape*>(r->getName(),r));

	//search for small rectangle
	auto result = shapes.find("small rectangle");

	//smallRectangle points to the second element in the pair
	smallRectangle = result->second;

	//check if the result is correct
	assert( smallRectangle->getName().compare(SMALL_RECTANGLE) == 0);
}

void myFunction5() {
	Square * s = new Square (11, 22, "small square", 3);
	Rectangle * r = new Rectangle (11, 22, SMALL_RECTANGLE, 4, 5);

	map<string, Shape *> shapes;

	int sumSurface = 0;

	//you must insert both s and r in shapes
	//then do the sum of their surface using
	//an iterator to access the 'Shape' in shapes
	//use sumSurface as an accumulator

	//map the names to the shapes
	shapes.insert(pair<string,Shape*>(s->getName(),s));
	shapes.insert(pair<string,Shape*>(r->getName(),r));

	//get sum of the surface areas
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
		sumSurface += it->second->getSurface();
	
	//check if sumSurface is correct
	cout << sumSurface << endl;
	assert( sumSurface == 29);
}

int main() 
{
	myFunction1();

	myFunction2();

	myFunction3();

	myFunction4();

	myFunction5();	
}	