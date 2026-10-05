#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Expense{
    
    int id;
    string description;
    double amount ;
    string category;
    string date;
};
int main(){
    vector<Expense> expenses;
    cout<<"=====EXPENSE TRACKER===== "<<endl;

    return 0;
}
