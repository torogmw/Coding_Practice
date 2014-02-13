#include "Epic.h"

void Epic::pointArea(int x, int y, int area)
{
  vector<vector<int> > points;
  if (area <= 0)
  {
    cout<<"can't have points with zero or negative area: "<<area<<endl;
    return;  // can't generate points with illegal area
  }
  for (int i = 1; i<=area; i++)	// i start from 1 !!!
  {
    if((area%i)==0)  // find a pair, will have four types for each pair
    { 
      vector<int> pairs(8,0);
      int height = i;
      int width = area/i;    // height for x, width for y
      pairs[0]=x+height;
      pairs[1]=y+width;
      pairs[2]=x-height;
      pairs[3]=y-width;
      points.push_back(pairs);
    }
  }
  cout<<"all points list here for: ("<<x<<","<<y<<")"<<endl; //print out all generated points
  for (int i = 0; i<points.size(); i++)
  {
    // generating the other two points on the fly 
    cout<<"-- ("<<points[i][0]<<","<<points[i][1]<<"),("<<points[i][0]<<","<<y<<"),("<<x<<","<<points[i][1]<<")"<<endl;
    cout<<"-- ("<<points[i][0]<<","<<points[i][3]<<"),("<<points[i][0]<<","<<y<<"),("<<x<<","<<points[i][3]<<")"<<endl;
    cout<<"-- ("<<points[i][2]<<","<<points[i][1]<<"),("<<points[i][2]<<","<<y<<"),("<<x<<","<<points[i][1]<<")"<<endl;
    cout<<"-- ("<<points[i][2]<<","<<points[i][3]<<"),("<<points[i][2]<<","<<y<<"),("<<x<<","<<points[i][3]<<")"<<endl;
  }
  cout<<"totally: "<<points.size()*4<<" points!"<<endl;
}

void Epic::additiveNumber(string numSeq)
{
    vector<string> additive;
    if(numSeq.size()<3) {
      cout<<"illegal size! "<<endl; 
      return;
    }
    for (int i=0; i<numSeq.size(); i++){
        if(numSeq[i]>'9' || numSeq[i]<'0'){
          cout<<"illegal character!"<<endl;	//ignore the alphabet
          return;
      }
    }
    for (int i=0; i<numSeq.size()-2; i++)
    {
      int first = numSeq[i]-'0';
      int second = numSeq[i+1]-'0';
      if (first+second<10 && first+second==(numSeq[i+2]-'0'))
        additive.push_back(numSeq.substr(i,3));
      if (first+second>10 && i<numSeq.size()-3 && first+second == (numSeq[i+2]-'0')*10+numSeq[i+3]-'0')
        additive.push_back(numSeq.substr(i,4)); 
    }
    cout<<"total numbers: "<<additive.size()<<endl;
    for (int i =0; i<additive.size(); i++)
      cout<<"-"<<additive[i]<<endl;
}

void Epic::removeDuplicates(string s)
{
   if (s.size()== 0)
   {
     cout<<"ni ta ma chi zai duo wo?"<<endl;
     return;
   }
   cout<<"input: "<<s<<endl;
   string out;
   for (int i = 0; i<s.size()-1; i++)
   {
     if(s[i]!=s[i+1]) out.append(s.substr(i,1));
   }
   out.append(s.substr(s.size()-1,1));  //final output
   cout<<"output: "<<out<<endl;
}

