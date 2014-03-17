#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

#define MAXLINE 1000
// split the input line into two lists while keep the index, sort it, then merge


void juggleSort(string oneLine)         // sort one line and output
{
    string output;
    vector<string> splitted;
    vector<int> intList;
    vector<char> charList;
    vector<int> intIndex;
    vector<int> charIndex;
    

    stringstream ss(oneLine);
    string item;
    while(getline(ss,item,' '))
    {
        splitted.push_back(item);
    }
    
//    cout<<endl;

//    
//    if(oneLine.size()<=1)
//    {
//        cout<<oneLine<<endl;
//        return;
//    }
//    
//    int numElements = 0;
//    for (int i = 0; i<oneLine.size(); i++)
//    {
//        if(isalpha(oneLine[i]))
//        {
//            charList.push_back(oneLine[i]);
//            charIndex.push_back(i);
//            //numElements++;
//        }
//        else if(isnumber(oneLine[i]))
//        {
//            intList.push_back(atoi(&oneLine[i]));
//            intIndex.push_back(i);
//            //numElements++;
//        }
//        numElements++;
//    }
    int numElements = 0;
    for (int i =0; i<splitted.size(); i++)
    {
        if(isalpha(splitted[i][0]))
        {
            charList.push_back(splitted[i][0]);
            charIndex.push_back(i);
            numElements++;
        }
        else if(isnumber(splitted[i][0]))
        {
            int temp;
            istringstream(splitted[i])>>temp;
            intList.push_back(temp);
            intIndex.push_back(i);
            numElements++;
        }
    }
    // sort the corresponding lists
    sort(intList.begin(), intList.begin()+intList.size());
    sort(charList.begin(),charList.begin()+charList.size());
    // put them into the final list, first initialization
//    for (int i = 0; i < numElements; i++)
//        output.push_back(' ');
//    
//    // put int
//    for(int i = 0; i<intIndex.size(); i++)
//        output[intIndex[i]] = intList[i]+'0';
//    // put char
//    for (int i = 0; i<charIndex.size(); i++)
//        output[charIndex[i]] = charList[i];
    // merge the two list
    int iCur = 0;
    int cCur = 0;
    for (int i = 0; i<numElements; i++)
    {
        while(iCur<intIndex.size() && cCur<charIndex.size())
        {
            if(intIndex[iCur]<charIndex[cCur])
            {

                stringstream ss;
                ss<<intList[iCur];
                output.append(ss.str());
                iCur++;
            }
            else
            {
                output.push_back(charList[cCur]);
                cCur++;
            }
            output.push_back(' ');
        }
        while(iCur<intIndex.size())
        {
            stringstream ss;
            ss<<intList[iCur];
            output.append(ss.str());
            iCur++;
            output.push_back(' ');
        }
        while(cCur<charIndex.size())
        {
            output.push_back(charList[cCur]);
            cCur++;
            output.push_back(' ');
        }
    }
    
    if (output[output.size()-1]==' ') {
        output = output.substr(0,output.size()-1);
    }
    cout<<" after: "<<output<<endl;
}

//int main()
//{
//    ifstream text;
//    text.open("/Users/Toro/Documents/Spring2014/scv/technical/Coding_Practice/Two/jugg.txt");
//    // replace by cin for coding challenge
//    string input;
//    while(getline(text,input))
//    {
//        cout<<"before: "<<input<<endl;
//        juggleSort(input);
//        
//    }
//    text.close();
//    
//    return 0;
//}
