//============================================================================
// Name        : 22B_Lab1.cpp
// Author      : Nancy Zhou
// Version     : 01
// Copyright   : Your copyright notice
// Description : a program that reads a text file that is entered by the user containing a set of test scores, calculates the average, median and mode.
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


// prototypes go here
int getScores(vector<int>&testScores);//reference b/c the vector is being initialized and is needed by main.
int sortScores(vector<int>&testScores);//reference b/c the sorted vector needs to return to main
int calcAverage(vector<int>testScores, int);
int calcMedian(vector<int>testScores,int);
int calcMode(vector<int>testScores,vector<int> mod);
void print(vector<int>testScores, int avg, int med, vector<int> mod);

int main()
{

    vector<int> testScores;
    vector<int> mod;
    int avg, med;
    //cout << "hello" << endl;

    if (getScores(testScores))
    {
        sortScores(testScores); //Call sorting function here
        avg = calcAverage(testScores, avg);
        //cout<<"This is the average:"<<endl<< avg<<endl;
        med = calcMedian(testScores, med);
        //cout<<"This is the median:"<<endl<< med<<endl;
        calcMode(testScores, mod);
        print(testScores, avg, med, mod);
    }
    else
    {
        cout << "Error getting test scores" << endl;
    }

    return 0;
}
int getScores(vector <int> &testScores )
{
    ifstream finput;
    int score;
    string input="lab1.txt";//use this until test the cin
    //cout << "Please input file name:" << endl;
    //cin>>input;
    finput.open(input.c_str());//open file, ifstream reads as char*, so I needed to use .c_str
    if (finput.fail())
    {
        cout<<"File failed to open"<<endl;
        return 0;
    }

    while (finput >> score)//reads file into the vector?
    {
        testScores.push_back(score);
    };
    /*cout<< "This is the unsorted vector:"<<endl;

    for (int val:testScores)
    {
        cout << val << " ";
    }
    cout<< endl;*/
    finput.close();
    return 1;
}

int sortScores(vector<int>&testScores)//sorts the vector
{
    sort (testScores.begin(), testScores.end());
    cout<< "This is the sorted vector:"<<endl;
    for (int val:testScores)
        // {
        //for (int r=0; r <5&&testScores.size; r++ )
    {
        cout << val << " ";
    }
    cout<< endl;
    //}
}
int calcAverage(vector <int>scores, int avg)// sums the elements in the vector then divides it by the amount of elements
{
    int size;
    size= scores.size();// finds the size of the array
    //cout<<"This is the size: "<<size<<endl;
    int sum=0;
    for (int i=0; i<size; i++)
    {
        sum+=scores[i];
        //cout<< scores[i]<<" at "<< i<< endl;// check index
        //cout<< sum<<" at "<< i<< endl;// check sum
    }
    avg= sum/size;

    return avg;
}


int calcMedian(vector<int>testScores, int med)// uses the amount of elements and counts to the half of that number, if even it averages that number and the next, if odd takes the number
{
    int mid;
    mid= testScores.size()/2;
    med= testScores[mid];
    return med;

}

int calcMode(vector<int> scores,vector<int> mod)//reads the vector and stores the most occurring element
//count and compare
{
    int occurs=1;
    int mode=0;
    int mostfrq;
    vector<int> freq;
    vector<int> scr;
    vector<int> modes;
    for (int i=0; i<scores.size(); i++)
    {
        //cout<< scores[i]

        if (scores[i]!=scores[i+1])// increase index
        {
            scr.push_back(scores[i]);//do not change
            freq.push_back(occurs);
            occurs=1;


        }//this if statement locates the change in unique elements and creates and assigns them to the corresponding vector.
        if(scores[i]==scores[i+1])
        {
            occurs+=1;
            //freq.push_back(occurs);// not included because the vector was making a new element when I just wanted to increment
        }//this if statement counts the frequency.
    }// this for loop adds the unique elements into a vector and counts and adds the unique element's frequency into a frequency vector
    for (int i=0; i<freq.size()-1; i++)
    {
        if (freq[i]>freq[i+1])
        {
            mostfrq= freq[i];
            if (mostfrq>mode)
            {
                mode=mostfrq;
            }
            //cout<<"hi "<<mostfrq<<endl;
        }
        if (freq[i]==mode)
        {
            mode= scr[i];
            modes.push_back(mode);
        }
        for (int val:modes)
        {
            cout << val << " ";
        }
        cout<< endl;
    }//find the highest frequency and use the index to correspond to the scores vector and save the modes into a modes vector.


    /*this displays the unique score and frequency vectors and the most frequent #

        for (int i=0; i<scr.size(); i++)
        {
            cout<< "scr: ";
            cout << scr[i] << " "<< endl;
            cout << "freq: "<< freq[i] << " "<<endl;
            cout<< "most frequent: "<<mostfrq<<endl;
        }*/

}

void print(vector<int> testScores, int avg, int med, vector<int> mod)
{
    // print the sorted vector, average, median, and mode
    cout<< "These are the scores"<<endl;
    for (int val:testScores)
    {
        cout << val << " ";
    }
    cout<< endl<<"--------------------------------------"<<endl;
    cout<< "The average of the scores is:"<<endl<<avg<<endl;
    cout<< "The median of the scores is:"<<endl<<med<<endl;
    cout<< "The mode(s) of the scores is:"<<endl;
    for (int val:mod)
    {
        cout << val << " ";
    }
    cout<< endl;

}


