/*///////////////////////////////
//
//  header file for all solutions
//  Minwei Gu @ Student Center
//
//////////////////////*//////////

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Epic{
public:
  // given coordinates x,y and area of the rectangele, output all rectangles generated
  void pointArea(int x, int y, int area);
    
  //find all additve Number sequence for a given input
  void additiveNumber(string numSequence);
  
  //remove duplicates for a given string
  void removeDuplicates(string s);
  
  // inlace re-order steps
  void inplaceReorder(string s1, string s2);
};
