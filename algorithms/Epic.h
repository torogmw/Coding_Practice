/*///////////////////////////////////
//                                 //
//  header file for all solutions  //
//  Minwei Gu @ Student Center     // 
//                                 //
//////////////////////*//////////////

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
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

  // max sum for consecutive array
  int maxSum(int arr[], int size);
  
  // determine if it is a well ordered number, well ordered means i-th less than i+1-th
  bool isWellOrdered(int n);

  // determine mango in a random generated array
  bool isMingo(int arr[], int size);  // remain question

  // determine solution from given packet, actually a subset sum problem
  bool hasSolution(int set[],int size,int sum);
  
  // find revised average, remove the three largest element
  int revisedAverage(int arr[], int size);

  // mapping keyboard to different characters, generate all possible string message 
  string keyboardMapping(string& text);
  
  
};
