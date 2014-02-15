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

void Epic::inplaceReorder(string s1, string s2)
{
    // O(n^2) brutal force
    if(s1.size()!=s2.size()) return;
    cout<<s1<<"->"<<s2<<endl;
    for (int j = 0; j<s2.size(); j++){
      for (int i = j; i<s1.size(); i++){
        if(s1[j]==s2[j]) break;
        if(s1[i]==s2[j])   // swap s1 with index i and j
        {
          char temp = s1[i];
          s1[i] = s1[j];
          s1[j] = temp;
          cout<<"swap "<<s1[i]<<" and "<<s1[j]<<endl;
          break;
        }
      }
    }   
}

int Epic::maxSum(int arr[], int size){
    // dynamic programming
    int max = 0;
    int temp = 0;
    int index = 0; 
    if(size==0) return 0;
    if(size==1) return arr[0];
    for(int i = 0; i<size; i++)
    {
      temp+=arr[i];
      if(temp>max) 
      {
        max = temp;
        index = i;
      }
      if(temp<0) temp = 0;
    }
    cout<<"max sum: "<<max<<endl;
    return max;
}

bool Epic::isWellOrdered(int n)
{
  int prev=9;
  while(n/10>0)
  {
    int temp = n%10;
    n = n/10;
    if (temp>prev) return false;
    else prev = temp;
  }
  if(n>prev) return false;
  else return true;
}

bool Epic::isMingo(int arr[], int size)
{
  // first, generate the mango
  int mingo[100][100];
  bool winner = false;
  for (int i = 0; i<100; i++)
  {
    int oneLine[100];
    for (int j = 0; j<100; j++)
    {
       oneLine[j] = 100*i+j+1;    
    }
  }
  // find the element, remove it
  for (int i = 0; i<size; i++)
  {
    int row = (arr[i]-1)/100;
    int col = arr[i]-row*100-1; 
    mingo[row][col] = 0;
    // determine mango winner here
   for (int k = 0; k<100; k++)
   {
     if(mingo[row][k]!=0) break;
     if(mingo[row][k]==0 && k==99) winner = true;
   }
   
   for (int k = 0; k<100; k++)
   {
     if(mingo[k][col]!=0) break;
     if(mingo[k][col]==0 && k==99) winner = true;
   }
   if(col>row)
   {  //col < row. start from col
     for (int k = 0; k<100-row+col; k++)
     {
       if(mingo[k][k-row+col]!=0) break;
       if(mingo[k][k-row+col]==0 && k == 99-row+col) winner = true;
     }
   }
   else
   {    // col>row, start from row 0
     for (int k = 0; k<100-col+row; k++)
     {
      if(mingo[k][k+row-col]!=0) break;
      if(mingo[k][k+row-col]==0 && k == 99+row-col) winner = true;
     }
   }
   if (winner)
   {
    cout<<"winner ends up at: "<<arr[i]<<endl; 
    return true;
   }
  }
  return false;
}

bool Epic::hasSolution(int set[], int size, int sum)
{
  // we are doing recursive, but NP-complete
  /*
  if (sum==0) return true;
  if (sum>0 && size == 0) return false;
  if (set[size-1]>sum) //if the last element is larger then sum ,we won't use it.
    return hasSolution(set,size-1,sum);
  return hasSolution(set,size-1,sum-set[size-1])||hasSolution(set,size-1,sum);
  */

  // Let's try some dynamic programming
  bool table[sum+1][size+1]; //create a 2d array
  //base case: sum is 0 true! size is 0 false!
  for (int i = 0; i<=size; i++) table[0][i] = true;
  for (int i = 1; i<=sum; i++) table[i][0] = false;
  
  // fill the table
  for (int i = 1; i<=sum; i++)
  {
    for (int j =1; j<=size; j++)
    {
      table[i][j] = table[i][j-1];
      if(set[j-1]<=i)
        table[i][j] = table[i][j-1] || table[i-set[j-1]][j-1];
    }
  }
  return table[sum][size];
}

int Epic::revisedAverage(int arr[], int size){
  if (size<3) return 0; //not enough elements
  if (size == 3) return (arr[0]+arr[1]+arr[2])/3;
  int buffer[3] = {0,0,0}; 	//the buffer is ordered from big to small, maintain the top 3
  for(int i = 0; i<size; i++)
  {
    if(arr[i]>buffer[0]) // the biggest value
    {
      buffer[2] = buffer[1];
      buffer[1] = buffer[0];
      buffer[0] = arr[i];
    }
    else if(arr[i]>buffer[1] && arr[i]<=buffer[0]) // the 2nd biggest value
    {
      buffer[2] = buffer[1];
      buffer[1] = arr[i];
    }
    else if(arr[i]>buffer[0] && arr[i]<=buffer[1]) // the 3rd biggest value
    {
      buffer[0] = arr[i];
    }
  }
  int sum = 0;
  for (int i = 0; i<size; i++) sum+=arr[i];
  return (sum-buffer[0]-buffer[1]-buffer[2])/(size-3);
}

string Epic::keyboardMapping(string& text)
{
  // first, initialize the mapping
  string map[]={"0",",1","abc2","def3","ghi4","jkl5","mno6","pqrs7","tuv8","wxyz9"};
  string result = ""; //the string we are going to return
  int index; //index to detect how many identical numbers bave been pressed continuously
  int number; //the current number we detected
  cout<<"total size: "<<text.size()<<endl;
  for (int i = 0; i<text.size(); ++i)
  {
    index=number=0;
    if(text[i] == '#') continue; //do nothing
    else if(text[i] == '*') {
      text.push_back(' '); //push a space in to the result
      continue;            //keep moving on to the next character
    }
    else if(text[i]>='0'&& text[i]<='9')
    {
      number = text[i]-'0';
      ++i;   //move forward to check if the next is the same number pressed
      while(i<text.size() && text[i]-'0' == number)
     {
        index++;
        i++;
     }
     index %= map[number].size();     //mod to the current index
     result.push_back(map[number][index]);
      --i; //move back an index
    }
  }
  return result;
}









