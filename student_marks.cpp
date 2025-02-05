#include <iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
#define loop(i, b) for (int i = 0; i < b; i++)



class students{
    public:
    
    int rno;
    string name;
    int marks[2];
    
    void total_marks(){
        int sum=0;
        for(int i=0; i< 2; i++){
            sum += marks[i];
        }
        cout<< "total marks are "<< sum<< endl;
    }
}student[4];

int main(){
    loop(i,4){
        // string n;
        student[i].rno = i+1;
        cout<< "enter the name "<< endl;
        cin >> student[i].name;
        
        for(int j = 0; j<2; j++){
            cout<< "enter your marks" << endl;
            cin >> student[i].marks[j] ;
        }
    }
    
    student[1].total_marks();
}
