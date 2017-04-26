//============================================================================
// Name        : 22B_Lab1.cpp
// Author      : Nancy Zhou
// Version     : 2.5
// Copyright   : 4/25/17
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
int calcMode(vector<int>testScores,vector<int> &mod);//reference b/c a vector is created and needed in the print function
void print(vector<int>testScores, int avg, int med, vector<int> mod);

/**==============================================================
                    Main
==============================================================**/
int main()
{
    char runagain;
    vector<int> testScores;
    vector<int> mod;
    int avg, med;
    //cout << "hello" << endl;
    do
    {

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
        }//info of scores is calculated and printed
        else
        {
            cout << "Error getting test scores" << endl;
        }//getscores failed
        cout << "Press any key to input another file or # to exit. " << endl;
        cin >> runagain;
    }//the program is replayed if the user wants to calculate another vector.
    while (runagain!= '#');

    cout << "Thank you for using this program." << endl;

    return 0;
}
/**=============================================================
Gets the file name from the user and adds the elements of the
file to a vector.
 ==============================================================*/
int getScores(vector <int> &testScores )
{
    ifstream finput;
    int score;
    string input;//="lab1.txt";//use this until test the cin
    cout << "Please input file name:" << endl;
    cin>>input;
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
/**=============================================================
Sorts the elements of the vector.
 ==============================================================*/

int sortScores(vector<int>&testScores)//sorts the vector with sort function
{
    sort (testScores.begin(), testScores.end());
    /* cout<< "This is the sorted vector:"<<endl;
    for (int val:testScores)
         // {
         //for (int r=0; r <5&&testScores.size; r++ )
     {
         cout << val << " ";
     }
     cout<< endl;*/
    //}
}
/**=============================================================
Calculates the average.
 ==============================================================*/
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
/**=============================================================
Calculates the middle element. If vector is even, averages the middle.
 ==============================================================*/

int calcMedian(vector<int>testScores, int med)// uses the amount of elements and counts to the half of that number, if even it averages that number and the next, if odd takes the number
{
    int mid;
    mid= testScores.size()/2;
    if (testScores.size()%2==1)//%- modulus operator used to find the remainder.
    {
      med= testScores[mid];
    }
    else
        med=(testScores[mid]+testScores[mid-1])/2;// paranthesis
    return med;

}
/**=============================================================
Creates a vector that finds and stores the most occurring
elements.
 ==============================================================*/
int calcMode(vector<int> scores,vector<int> &mod)//reads the vector and stores the most occurring element
//count and compare
{
    int occurs=1;
    int mode=0;
    int mostfrq;
    vector<int> freq;
    vector<int> scr;
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

    for (int i=0; i<freq.size()-1; i++)//comparing with next element, so the last element is compared -1 than the size
    {
        if (freq[i]>freq[i+1])
        {
            mostfrq= freq[i];

        }
    }
    //cout<<"hi this is most frequent"<<mostfrq<<endl;
    for (int i=0; i<freq.size(); i++)
    {
        if (freq[i]==mostfrq)
        {
            mod.push_back(scr[i]);
        }
    }//find the highest frequency and use the index to correspond to the scores vector and save the modes into a modes vector.
//cout << "these are the modes: ";
    /*for (int val:modes)
    {

        cout<< val<<" ";
    }
    cout<< endl;

    //this displays the unique score and frequency vectors and the most frequent #
      for (int i=0; i<scr.size(); i++)
        {
            cout<< "scr: ";
            cout << scr[i] << " ";//<< endl;
            cout << "freq: "<< freq[i] << " "<<endl;
           // cout<< "most frequent: "<<mostfrq<<endl;
        }*/


}
/**=============================================================
Prints the sorted vector, average, median and the mode vector.
 ==============================================================*/
void print(vector<int> testScores, int avg, int med, vector<int> mod)
{
    // print the sorted vector, average, median, and mode
    cout<< "These are the sorted scores: "<<endl;
    for (int val:testScores)
    {
        cout << val << " ";
    }
    cout<< endl<<"--------------------------------------"<<endl;
    cout<< "The average of the scores is:"<<endl<<avg<<endl;
    cout<< "The median of the scores is:"<<endl<<med<<endl;
    cout<< "The mode(s) of the scores is/are:"<<endl;
    for (int val:mod)
    {
        cout << val << " ";
    }
    cout<< endl;

}
/***********************************************************
 ver 2.5 Output:
____________________________________________________________

 Please input file name:
lab1.txt
These are the sorted scores:
61 61 66 68 71 72 73 73 74 74 77 79 80 80 85 87 87 87 87 88 89 90 91 92 92 92 92 97 99 100
--------------------------------------
The average of the scores is:
82
The median of the scores is:
87
The mode(s) of the scores is:
87 92
Press any key to input another file or # to exit.
#
Thank you for using this program.

Process returned 0 (0x0)   execution time : 9.992 s
Press any key to continue.
=============================================================

ver 2.5 output if a user input is not found/ incorrect:
_____________________________________________________________

Please input file name:
lab
File failed to open
Error getting test scores
Press any key to input another file or # to exit.
l
Please input file name:
lab1.txt
These are the sorted scores:
61 61 66 68 71 72 73 73 74 74 77 79 80 80 85 87 87 87 87 88 89 90 91 92 92 92 92 97 99 100
--------------------------------------
The average of the scores is:
82
The median of the scores is:
87
The mode(s) of the scores is/are:
87 92
Press any key to input another file or # to exit.

=============================================================

ver 2.0 output:
______________________________________________________________

Please input file name:
lab1.txt
These are the sorted scores:
61 61 66 68 71 72 73 73 74 74 77 79 80 80 85 87 87 87 87 88 89 90 91 92 92 92 92 97 99 100
--------------------------------------
The average of the scores is:
82
The median of the scores is:
87
The mode(s) of the scores is:
87 92

Process returned 0 (0x0)   execution time : 4.218 s
Press any key to continue.
____________________________________________________________

If I could/were to keep working on this program, I would implement a
way to create the most square-shaped cout of the vector by
creating a nested for loop to make rows and columns.

 **********************************************************/



