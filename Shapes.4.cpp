// Assignment 5, Shapes v.4

// Program will use class variables with public and private access, which declare
// const variables, contructors, assignment operators, and member functions. The
// program will make all pointers read-only or constant read-only to incorporate
// the principle of least privilege. Objects of the same type will now display its
// area, perimeter, volume, and surface area together in console and file output.

// c++ libraries
#include <iostream>
#include <fstream>
#include <algorithm>  // swap
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// c libraries
#include <cstdlib>   // atof
#include <cmath>     // sqrt and M_PI

// class variables with member functions
// square dimensions
class Square
{
  // private const variables
  const double length;

  // public constructor, assignment operator, and member function
  public:
  Square(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
  Square& operator=(const Square&);
  void calculation(ostream&) const;
};

// rectangle dimensions
class Rectangle
{
  // private const variables
  const double length;
  const double width;

  // public constructor, assignment operator, and member function
  public:
  Rectangle(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
                                            width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
  Rectangle& operator=(const Rectangle&);
  void calculation(ostream&) const;
};

// circle dimensions
class Circle
{
  // private const variables
  const double radius;

  // public constructor, assignment operator, and member function
  public:
  Circle(const vector<string>& tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
  Circle& operator=(const Circle&);
  void calculation(ostream&) const;
};

// triangle dimensions
class Triangle
{
  // private const variables
  const double length;
  
  // public constructor, assignment operator, and member function
  public:
  Triangle(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
  Triangle& operator=(const Triangle&);
  void calculation(ostream&) const;
};

// cube dimensions
class Cube
{
  // private const variables
  const double length;
    
  // public constructor, assignment operator, and member function
  public:
  Cube(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
  Cube& operator=(const Cube&);
  void calculation(ostream&) const;
};

// box dimensions
class Box
{
  // private const variables
  const double length;
  const double width;
  const double height;

  // public constructor, assignment operator, and member function
  public:
  Box(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
                                      width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0),
                                      height(tokens.size() > 3 ? atof(tokens[3].c_str()) : 0) {}
  Box& operator=(const Box&);
  void calculation(ostream&) const;
};

// cylinder dimensions
class Cylinder
{
  // private const variables
  const double height;
  const double radius;

  // public constructor, assignment operator, and member function
  public:
  Cylinder(const vector<string>& tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
                                           height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
  Cylinder& operator=(const Cylinder&);
  void calculation(ostream&) const;
};

// prism dimensions
class Prism
{
  // private const variables
  const double length;
  const double height;

  // public constructor, assignment operator, and member function
  public:
  Prism(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
                                        height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
  Prism& operator=(const Prism&);
  void calculation(ostream&) const;
};

// function prototypes
void id();
vector<string> parseString(string);
ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);

int main()
{
  // function call for identification information
  id();

  // declare and initialize variables
  ifstream fin;     
  ofstream fout; 
  string line;
  vector<string> tokens;   
  vector<const void*> myBag;
  vector<int> myBagType;

  // open files
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  // Check if input file is opened successfully
  if (!fin.good())
  {
    cout << "Input file failed to open." << endl;
    return 1;
  }
 
  // Check if output file is opened successfully
  if (!fout.good())
  {
    cout << "Output file failed to open." << endl;
    return 1;
  }

  // keep looping until end of file is reached
  while (!fin.eof())
  {
    // read each line from input file and call function to get tokens
    getline(fin, line);
    tokens = parseString(line);

    // will skip any empty lines from input file
    if (tokens.size() != 0)
    {
      // check if token is square
      if (tokens[0] == "SQUARE")
      {
        // dynamically allocate memory for a new square object using constructor 
        // store const read-only pointer object in bag
        // store 1 into different bag to represent square shape
        const Square* const s = new Square(tokens);
        myBag.push_back(s);
        myBagType.push_back(1);
      }

      // check if token is rectangle
      else if (tokens[0] == "RECTANGLE")
      {
        // dynamically allocate memory for a new rectangle object using constructor 
        // store const read-only pointer object in bag
        // store 2 into different bag to represent rectangle shape
        const Rectangle* const r = new Rectangle(tokens);
        myBag.push_back(r);
        myBagType.push_back(2);
      }

      // check if token is circle
      else if (tokens[0] == "CIRCLE")
      {
        // dynamically allocate memory for a new circle object using constructor 
        // store const read-only pointer object in bag
        // store 3 into different bag to represent circle shape
        const Circle* const c = new Circle(tokens);
        myBag.push_back(c);
        myBagType.push_back(3);
      }

      // check if token is triangle
      else if (tokens[0] == "TRIANGLE")
      {
        // dynamically allocate memory for a new triangle object using constructor 
        // store const read-only pointer object in bag
        // store 4 into different bag to represent triangle shape
        const Triangle* const t = new Triangle(tokens);
        myBag.push_back(t);
        myBagType.push_back(4);
      }

      // check if token is cube
      else if (tokens[0] == "CUBE")
      {
        // dynamically allocate memory for a new cube object using constructor 
        // store const read-only pointer object in bag
        // store 5 into different bag to represent cube shape
        const Cube* const c = new Cube(tokens);
        myBag.push_back(c);
        myBagType.push_back(5);
      }

      // check if token is box           
      else if (tokens[0] == "BOX")
      {
        // dynamically allocate memory for a new box object using constructor 
        // store const read-only pointer object in bag
        // store 6 into different bag to represent box shape
        const Box* const b = new Box(tokens);
        myBag.push_back(b);
        myBagType.push_back(6);
      }

      // check if token is cylinder      
      else if (tokens[0] == "CYLINDER")
      {
        // dynamically allocate memory for a new cylinder object using constructor 
        // store const read-only pointer object in bag
        // store 7 into different bag to represent cylinder shape
        const Cylinder* const c = new Cylinder(tokens);
        myBag.push_back(c);
        myBagType.push_back(7);
      }

      // check if token is prism
      else if (tokens[0] == "PRISM")
      {
        // dynamically allocate memory for a new prism object using constructor 
        // store const read-only pointer object in bag
        // store 8 into different bag to represent prism shape
        const Prism* const p = new Prism(tokens);
        myBag.push_back(p);
        myBagType.push_back(8);
      }

      // check if token is EOF      
      else if (tokens[0] == "EOF")
        break;

      // token does not match one of eight objects
      else
        cout << tokens[0] << " invalid object" << endl;
    }
  }

  // close input file
  fin.close();

  // use insertion sort to sort all objects of the same type together
  // move through all objects in bag
  for (int i = 0; i < myBag.size(); i++)
  {
    // compare current object type with all other object types
    for (int j = i + 1; j < myBag.size(); j++)
    {
      // object type at index j is less than object type at index i
      if (myBagType[j] < myBagType[i])
      {
        // swap both object and object type
        swap(myBag[i], myBag[j]);
        swap(myBagType[i], myBagType[j]);
      }
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert const read-only pointer in vector into pointer to square object
        // dereference the read-only pointer to access square object
        // call function to calculate and display info to console output        
        const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
        const Square& rSquare = *pSquare;
        rSquare.calculation(cout);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert const read-only pointer in vector into pointer to rectangle object
        // dereference the read-only pointer to access rectangle object
        // call function to calculate and display info to console output        
        const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
        const Rectangle& rRectangle = *pRectangle; 
        rRectangle.calculation(cout);
        break;
      }
      // integer 3 represents circle
      case 3:
      {
        // convert const read-only pointer in vector into pointer to circle object
        // dereference the read-only pointer to access circle object
        // call function to calculate and display info to console output     
        const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
        const Circle& rCircle = *pCircle;
        rCircle.calculation(cout);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert const read-only pointer in vector into pointer to triangle object
        // dereference the read-only pointer to access triangle object
        // call function to calculate and display info to console output        
        const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
        const Triangle& rTriangle = *pTriangle;
        rTriangle.calculation(cout);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert const read-only pointer in vector into pointer to cube object
        // dereference the read-only pointer to access cube object
        // call function to calculate and display info to console output         
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        const Cube& rCube = *pCube;
        rCube.calculation(cout);
        break;
      }
      
      // integer 6 represents box
      case 6:
      {
        // convert const read-only pointer in vector into pointer to box object
        // dereference the read-only pointer to access box object
        // call function to calculate and display info to console output       
        const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
        const Box& rBox = *pBox;
        rBox.calculation(cout);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert const read-only pointer in vector into pointer to cylinder object
        // dereference the read-only pointer to access cylinder object
        // call function to calculate and display info to console output    
        const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
        const Cylinder& rCylinder = *pCylinder;
        rCylinder.calculation(cout);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert const read-only pointer in vector into pointer to prism object
        // dereference the read-only pointer to access prism object
        // call function to calculate and display info to console output        
        const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
        const Prism& rPrism = *pPrism;
        rPrism.calculation(cout);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert const read-only pointer in vector into pointer to square object
        // dereference the read-only pointer to access square object
        // call function to calculate and display info to file output        
        const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
        const Square& rSquare = *pSquare;
        rSquare.calculation(fout);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert const read-only pointer in vector into pointer to rectangle object
        // dereference the read-only pointer to access rectangle object
        // call function to calculate and display info to file output        
        const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
        const Rectangle& rRectangle = *pRectangle; 
        rRectangle.calculation(fout);
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert const read-only pointer in vector into pointer to circle object
        // dereference the read-only pointer to access circle object
        // call function to calculate and display info to file output        
        const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
        const Circle& rCircle = *pCircle;
        rCircle.calculation(fout);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert const read-only pointer in vector into pointer to triangle object
        // dereference the read-only pointer to access triangle object
        // call function to calculate and display info to file output    
        const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
        const Triangle& rTriangle = *pTriangle;
        rTriangle.calculation(fout);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert const read-only pointer in vector into pointer to cube object
        // dereference the read-only pointer to access cube object
        // call function to calculate and display info to file output       
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        const Cube& rCube = *pCube;
        rCube.calculation(fout);
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert const read-only pointer in vector into pointer to box object
        // dereference the read-only pointer to access box object
        // call function to calculate and display info to file output      
        const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
        const Box& rBox = *pBox;
        rBox.calculation(fout);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert const read-only pointer in vector into pointer to cylinder object
        // dereference the read-only pointer to access cylinder object
        // call function to calculate and display info to file output       
        const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
        const Cylinder& rCylinder = *pCylinder;
        rCylinder.calculation(fout);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert const read-only pointer in vector into pointer to prism object
        // dereference the read-only pointer to access prism object
        // call function to calculate and display info to file output      
        const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
        const Prism& rPrism = *pPrism;
        rPrism.calculation(fout);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert const read-only pointer in vector into pointer to square object
        // delete dynamically allocated square object      
        const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
        delete pSquare;
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert const read-only pointer in vector into pointer to rectangle object
        // delete dynamically allocated rectangle object   
        const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
        delete pRectangle;
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert const read-only pointer in vector into pointer to circle object
        // delete dynamically allocated circle object   
        const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
        delete pCircle;
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert const read-only pointer in vector into pointer to triangle object
        // delete dynamically allocated triangle object   
        const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
        delete pTriangle;
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert const read-only pointer in vector into pointer to cube object
        // delete dynamically allocated cube object   
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        delete pCube;
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert const read-only pointer in vector into pointer to box object
        // delete dynamically allocated box object   
        const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
        delete pBox;
        break;
      }
     
      // integer 7 represents cylinder
      case 7:
      {
        // convert const read-only pointer in vector into pointer to cylinder object
        // delete dynamically allocated cylinder object   
        const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
        delete pCylinder;
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert const read-only pointer in vector into pointer to prism object
        // delete dynamically allocated prism object   
        const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
        delete pPrism;
        break;
      }

      default:
        break;
    }
  }

  // close output file
  fout.close();

  return 0;
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// function will take a string and create an array of tokens
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

// function will round numbers to two decimal digits
ostream& roundingTwo(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

// function will turn off rounding back to default
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

// member function will perform calculations for square and display results 
void Square::calculation(ostream& out) const
{
  // calculate area and perimeter
  double area = length * length;
  double perimeter = 4 * length;

  // display results to console or file
  out << "SQUARE side=" << length;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for rectangle and display results 
void Rectangle::calculation(ostream& out) const
{ 
  // calculate area and perimeter
  double area = length * width;
  double perimeter = 2 * (length + width);

  // display results to console or file
  out << "RECTANGLE length=" << length << " width=" << width;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for circle and display results 
void Circle::calculation(ostream& out) const
{        
  // calculate area and perimeter
  double area = M_PI * radius * radius;
  double perimeter = 2 * M_PI * radius;

  // display results to console or file
  out << "CIRCLE radius=" << radius;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for triangle and display results 
void Triangle::calculation(ostream& out) const
{        
  // calculate area and perimeter
  double area = (sqrt(3) / 4) * length * length;
  double perimeter = 3 * length;

  // display results to console or file
  out << "TRIANGLE side=" << length;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for cube and display results 
void Cube::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = 6 * length * length;
  double volume = length * length * length;

  // display results to console or file
  out << "CUBE side=" << length;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// member function will perform calculations for box and display results 
void Box::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = 2 * ((length * width) + (width * height) + (length * height));
  double volume = length * width * height;

  // display results to console or file
  out << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// member function will perform calculations for cylinder and display results 
void Cylinder::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = (2 * M_PI * radius * radius) + (2 * M_PI * radius * height);
  double volume = M_PI * radius * radius * height;

  // display results to console or file
  out << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// member function will perform calculations for prism and display results 
void Prism::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = ((sqrt(3) / 2) * length * length) + (3 * length * height);
  double volume = (sqrt(3) / 4) * length * length * height;

  // display results to console or file
  out << "PRISM side=" << length << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// assignment operator for square class
Square& Square::operator=(const Square& copyThis)
{
  // declare reference variable to host object
  Square& host = *this;
  
  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this!= &copyThis)
    const_cast<double&>(host.length) = copyThis.length;

  // return reference variable
  return host;
}

// assignment operator for rectangle class
Rectangle& Rectangle::operator=(const Rectangle& copyThis)
{
  // declare reference variable to host object
  Rectangle& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis)
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  
  // return reference variable
  return host;
}

// assignment operator for triangle class
Triangle& Triangle::operator = (const Triangle& copyThis) 
{
  // declare reference variable to host object
  Triangle& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis)
    const_cast<double&>(host.length) = copyThis.length;  
  
  // return reference variable
  return host;
}

// assignment operator for circle class
Circle& Circle::operator = (const Circle& copyThis) 
{
  // declare reference variable to host object
  Circle& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis) 
    const_cast<double&>(host.radius) = copyThis.radius;
  
  // return reference variable
  return host;
}

// assignment operator for cube class
Cube& Cube::operator = (const Cube& copyThis) 
{
  // declare reference variable to host object
  Cube& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimension
  if (this != &copyThis) 
    const_cast<double&>(host.length) = copyThis.length;

  // return reference variable
  return host;
}

// assignment operator for prism class
Prism& Prism::operator = (const Prism& copyThis) 
{
  // declare reference variable to host object
  Prism& host = *this;
  
  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis) 
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.height) = copyThis.height;
  }

  // return reference variable
  return host;
}

// assignment operator for cylinder class
Cylinder& Cylinder::operator = (const Cylinder& copyThis) 
{
  // declare reference variable to host object
  Cylinder& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis) 
  {
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }

  // return reference variable
  return host;
}

// assignment operator for box class
Box& Box::operator = (const Box& copyThis) 
{
  // declare reference variable to host object
  Box& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimension
  if (this != &copyThis) 
    {
      const_cast<double&>(host.length) = copyThis.length;
      const_cast<double&>(host.width) = copyThis.width;
      const_cast<double&>(host.height) = copyThis.height;
    }

  // return reference variable
  return host;
}
