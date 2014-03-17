//
//  Amazon.cpp
//  twosigmaTest
//
//  Created by Minwei Gu on 3/14/14.
//  Copyright (c) 2014 twoSigma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
// Amazon online Assesement
// You may use the JDK or the standard template library. The solution will be evaluated on correctness, runtime complexity (big-O), and adherence to coding best practices. A complete answer will include the following:
// 1. Document your assumptions
// 2. Explain your approach and how you intend to solve the problem
// 3. Provide code comments where applicable
// 4. Explain the big-O run time complexity of your solution. Justify your answer.
// 5. Identify any additional data structures you used and justify why you used them.
// 6. Only provide your best answer to each part of the question.
using namespace std;


// k nearest points
class Point{
public:
    double x;
    double y;
    int value;
    Point(double x_, double y_):x(x_),y(y_){}
};

class ListNode{
public:
    ListNode* next;
    int value;
    ListNode(int value_):value(value_),next(0){}
};

vector<Point> findKNearest(int k, vector<Point> points){
    vector<Point> toReturn;
    vector<double> distances;
    
    // first, calculate the distance of the point
    for (int i = 0; i<points.size(); i++)
    {
        double temp = sqrt(points[i].x*points[i].x+points[i].y*points[i].y);
        distances.push_back(temp);
    }
    // then, make a heap
    vector<double> heap(distances.begin(), distances.begin()+k);
    make_heap(heap.begin(), heap.end());
    //for (int i = k; i<distance.size(); i++);
    
    return toReturn;
}
// window sum
// corner case: wSize > size  or wSize < 1
vector<int> windowSum(vector<int> array, int wSize)
{

    vector<int> newArray;
    for (int i = 0; i<=array.size()-wSize; i++)
    {
        int temp = 0;
        for (int j = i; j<i+wSize; j++)
        {
            temp+=array[j];
        }
        newArray.push_back(temp);
    }

    return newArray;
}

// return last k
ListNode* returnLastk(int k, ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    int count = 0;
    
    if(!head) return NULL;
    
    while(count<k)
    {
        fast = fast->next;
        count++;
    }
    
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// test results
class TestResult {
public:
    int studentId;
    string testDate;
    int testScore;
    TestResult(int id, string data, int score){
        studentId = id;
        testDate = data;
        testScore = score;
    }
};

class ResultsbyId
{
    int id;
    vector<int> scores;
};

double calculateFinal(vector<int> results)
{
    // given a vector, return the highest five
    double finalResult = 0;
    double sum = 0;
    sort(results.begin(), results.end());
    for (unsigned i = results.size()-5; i<results.size(); i++)
        sum+=results[i];
    finalResult = sum/5;
    return finalResult;
}

//returning the final score of student with average of his highest five
map <int, double> calculateFinalScores (vector<TestResult> results) {
    map<int, double> finalScores;
    map<int, vector<int> > scoresById;
    // first partition
    for (int i = 0; i<results.size(); i++)
    {
        int tempID = results[i].studentId;
        int tempScore = results[i].testScore;
        if(scoresById.count(tempID)!=0)
        {
            scoresById.find(tempID)->second.push_back(tempScore);   //push the score
        }
        else{
            vector<int> temp;
            temp.push_back(tempScore);
            scoresById.insert(pair<int,vector<int> >(tempID,temp));
        }
    }

//        cout << it->first << " => " << it->second.size()<< '\n';
    // then calculate each scores
    for (map<int,vector<int> >::iterator it=scoresById.begin(); it!=scoresById.end(); ++it)
    {
        double average = calculateFinal(it->second);
        finalScores.insert(pair<int,double>(it->first,average));
        
    }
    for (map<int,double>::iterator itt=finalScores.begin(); itt!=finalScores.end(); ++itt)
    {
        cout << itt->first << " => " << itt->second<< '\n';
    }
    return finalScores;
    
}
int main()
{
    vector<TestResult> results;
    map<int, double> finalScores;
    for (int i = 1; i< 10; i++)
    {
        for (int j = 60; j>=50; j--)
        {
            TestResult temp(i,"sb",j);
            results.push_back(temp);
        }
    }
    finalScores = calculateFinalScores(results);
    
    return 0;
}