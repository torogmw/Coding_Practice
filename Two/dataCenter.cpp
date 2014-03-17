#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

void jumbleSort(string oneLine)
{
    string output;
    vector<string> splitted;
    vector<int> intList;
    vector<int> intIndex;
    vector<string> wordList;
    vector<int> wordIndex;
    
    // first, split the oneline into vector of strings 
    stringstream s(oneLine);
    string item;
    while(getline(s,item,' '))
    {
        splitted.push_back(item);
    }
    
    // partition into different lists
    int numElements = splitted.size();
    for (int i = 0; i<numElements; i++)
    {
        if(isalpha(splitted[i][0]))
        {
            wordList.push_back(splitted[i]);
            wordIndex.push_back(i);
        }
        else
        {
            int temp;
            istringstream(splitted[i])>>temp;
            intList.push_back(temp);
            intIndex.push_back(i);
        }
    }
    
    // sort them using std::sort
    sort(intList.begin(),intList.begin()+intList.size());
    sort(wordList.begin(),wordList.begin()+wordList.size());

    
    // merge them into the final output
    int iCur = 0;        // cursor for tracking index
    int wCur = 0;
    for (int i=0; i<numElements; i++)
    {
        while(iCur<intIndex.size() && wCur<wordIndex.size())
        {
            if(intIndex[iCur]<wordIndex[wCur])
            {
                stringstream s;
                s<<intList[iCur];
                output.append(s.str());
                iCur++;
            }
            else
            {
                output.append(wordList[wCur]);
                wCur++;
            }
            output.push_back(' ');
        }
        while(iCur<intIndex.size())
        {
            stringstream s;
            s<<intList[iCur];
            output.append(s.str());
            iCur++;
            output.push_back(' ');
        }
        while(wCur<wordIndex.size())
        {
            output.append(wordList[wCur]);
            wCur++;
            output.push_back(' ');
        }
    }
    // remove the last space in the output
    if(output[output.size()-1]==' ')
    {
        output = output.substr(0,output.size()-1);
    }
    cout<<output<<endl;

    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    while(getline(cin,input))
    {
        //cout<<"before: "<<input<<endl;
        jumbleSort(input);
    }
    return 0;
}