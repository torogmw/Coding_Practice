#include "Epic.h"

void Epic::pointArea(int x, int y, int area)
{
  vector<vector<int> > points;
  if (area <= 0)
  {
    cout<<"can't have points with zero or negative area: "<<area<<endl;
    return;  // can't generate points with illegal area
  }
  for (int i = 1; i<=area; i++)
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


