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


//class Mingo;
class Mingo{
public:
  Mingo()
  {
    //matrix = new int[100][100];
    for (int i = 0; i<100; i++)
    {
      for(int j =0; j<100; j++)
        matrix[i][j]=i*100+j;
    }
    count = 0;
    diagChecked = false;
  }
  ~Mingo(){}
  void init(){
    cout<<"generate a mingo!"<<endl;
  }
  bool isMingo(int row, int col)
  {
    int index = 0;
    matrix[row][col] = 10000; // give it a constant value;
    // check row
    while(index<100 && matrix[100][col]==10000) index++;
    if(index == 100) {
      cout<<"Mingo No."<<count++<<" at "<<row<<","<<col<<endl;
      return true;
    }
    // check column
    index = 0;
    while(index<100 && matrix[row][index]==10000) index++;
    if(index == 100) {
      cout<<"Mingo No."<<count++<<" at "<<row<<","<<col<<endl;
      return true;
    }
    // check diag, which is tricky part of this program! // do we need to consider?
    if (row == col)  
    {
      index = 0;
      while(index<100&&matrix[index][index]==10000) index++;
      if(index == 100)
      {
        cout<<"Mingo No."<<count++<<" at "<<row<<","<<col<<endl;
        return true;
      }
    }
    if(row+col==99)
    { 
      index = 0;
      while(index<100&&matrix[index][99-index]==10000) index++;
      if(index == 100)
      {
        cout<<"Mingo No."<<count++<<" at "<<row<<","<<col<<endl;
        return true;
      }
    }
   return false;    
  }

private:
  int matrix[100][100];
  int count;
  bool diagChecked; 
  
};
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

  // print well-ordered number for given digits
  void printNum(int numRemaining, int num);
  
  // finger mapping and sequence
  void typist(string text);
  
  Mingo mg;

};
