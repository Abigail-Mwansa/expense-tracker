#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

//Structure for storing expense information
struct Expense{
    
    int id;
    string description;
    double amount ;
    string category;
    string date;
};

//Function to add an expense
void addExpense(vector<Expense>&expenses){
    Expense e;
    cout<<"Enter expense ID:";
    cin>>e.id;
    cin.ignore();
    cout<<"Enter Description:";
    getline(cin, e.description);
    cout<<"Enter amount: ";
    cin>>e.amount;

    cin.ignore();
    cout<<"Enter category (Food, Transport, Education, other): ";
    getline(cin, e.category);
    cout<<" Enter date: ";
    getline(cin, e.date);

    expenses.push_back(e);
    
    cout<<"Expense added successfully!"<<endl;
}

//Function to display expenses

void viewExpenses(vector<Expense>&expenses){
    if(expenses.size() == 0){
        cout<<"No expenses recorded."<<endl;
    }
    else{
        for(int i = 0; i < expenses.size(); i++){
            cout<<"\nExpenses ID: "<<expenses[i].id<<endl;
            cout<<"Description: "<<expenses[i].description<<endl;
            cout<<"Amount: K"<<expenses[i].amount<<endl;
            cout<<"Category: "<<expenses[i].category<<endl;
            cout<<"Date: "<<expenses[i].date<<endl;
        }
    }
}

//Function to calculate total expenses
void calculateTotal(vector<Expense>&expenses){
    double total = 0;
    for (int i = 0; i <expenses.size();i++){
        total = total + expenses[i].amount;
    }
    cout<<"Total expenses: K"<<total<<endl;
}

//Functions to edit an expense
void editExpense(vector<Expense>&expenses){
    int searchID;
    int found = 0;
    cout<<"Enter the ID of the expense to edit: ";
    cin>> searchID;

    for(int i = 0;i<=expenses.size(); i++){
        if(expenses[i].id == searchID){
            cout<<"Enter new description: ";
            cin.ignore();
            getline(cin,expenses[i].description);
            cout<<"Enter new amount: ";
            cin>>expenses[i].amount;

            cin.ignore();
            cout<<"Enter new category: ";
            getline(cin, expenses[i].category);
            cout<<"Enter new date: ";
            getline(cin,expenses[i].date);

            cout<<"Expense updated successfully!"<<endl;

            found = 1;
            break;
        }
    }
    if(found == 0) {
        cout<<"Expense ID not found!"<<endl;
    }
}

//Function to delete an expense

void deleteExpense(vector<Expense>&expenses){
    int searchID;
    int found = 0;

    cout<<"Enter the ID of the expense to delete: ";
    cin>>searchID;

    for(int i = 0; i< expenses.size();i++){
        if(expenses[i].id == searchID){
            for(int j = i;j<expenses.size() - 1; j++){
                expenses[j] = expenses[j + 1];

            }

            expenses.pop_back();
            cout<<"Expense deleted successfully!" <<endl;

            found = 1;
            break;
        }
    }
   if (found == 0){
    cout<<"Expense ID not found!"<<endl;
   } 
}

//NEW FEATURE : Expense category summary

void categorySummary(vector<Expense>&expenses){
    double foodTotal = 0;
    double transportTotal = 0;
    double educationTotal = 0;
    double otherTotal = 0;
    double overallTotal = 0;

    if(expenses.size() == 0 ){
        cout<<"\n No Expenses available for the report."<<endl;
    }
    else {
        for(int i = 0;i<expenses.size();i++){
            if(expenses[i].category == "Food"){
                foodTotal = foodTotal + expenses[i].amount;
            }
            else if(expenses[i].category == "Transport"){
                transportTotal =  transportTotal + expenses[i].amount ;
            }  else if(expenses[i].category == "Education"){
                educationTotal = educationTotal + expenses[i].amount;

            }
            else{
                otherTotal = otherTotal + expenses[i].amount;
            }
            overallTotal = overallTotal + expenses[i].amount;
        }

        cout<<" \n=========EXPENSE REPORT=============="<<endl;

        cout<<"\nFood expenses: K"<<foodTotal <<endl;
        cout<<"\nTransport expenses: K"<<transportTotal <<endl;
        cout<<"\nEducation expenses: K"<<educationTotal <<endl;
        cout<<"\nOther expenses: K"<<otherTotal <<endl;

        cout<<"-----------------------------------------------"<<endl;
        cout<<"====================================================="<<endl;
    }
}

//FUNCTION THAT SAVES EXPENSES
void saveExpenses(vector<Expense>&expenses){
    ofstream file("expenses.txt");
    for(int i = 0;i<expenses.size();i++){
        file<<expenses[i].id<<endl;
        file<<expenses[i].description<<endl;
        file<<expenses[i].amount<<endl;
        file<<expenses[i].category<<endl;
        file<<expenses[i].date<<endl;
    }
    file.close();
    cout<<"Expenses saved successfully!"<<endl;
}

//FUNCTIONS TO LOAD EXPENSES
void loadExpenses(vector<Expense>&expenses){
    ifstream file("expenses.txt");
    Expense e;
    while(file >>e.id){
        file.ignore();
        getline(file, e.description);
        file >> e.amount;
        file.ignore();
        getline(file, e.category);
        getline(file, e.date);
        expenses.push_back(e);
    }
    file.close();
}
//function for searching expense by id
void searchExpense(vector<Expense>&expenses){
    int searchID;
    int found = 0;

    cout<<"Enter expense to search: ";
    cin>>searchID;

    for(int i = 0;i< expenses.size(); i++){
        if(expenses[i].id == searchID){
            cout<<"\n Expense Found!"<<endl;
            cout<<"ID: "<<expenses[i].id<<endl;
            cout<<"Description: "<<expenses[i].description<<endl;
            cout<<"Amount: "<<expenses[i].amount<<endl;
            cout<<"Category: "<<expenses[i].category<<endl;
            cout<<"Date: "<<expenses[i].date<<endl;

            found = 1;
            break;
        }
    }
    if(found == 0){
        cout<<"\n Expense not found."<<endl;
    }
}
//function for finding an expense by category
void searchByCategory(vector<Expense>&expenses){
    string searchCategory;
    int found = 0;

    cin.ignore();
    cout<<"\nEnter Category: ";
    cin>>searchCategory;

    for(int i = 0;i< expenses.size();i++){
        if(expenses[i].category == searchCategory){
            cout<<"\nDescription: "<<expenses[i].description<<endl;
            cout<<"Amount: "<<expenses[i].amount<<endl;
            cout<<"Date: "<<expenses[i].date<<endl;

            found = 1;
        }
    }
    if(found == 0){
        cout<<"\nNo expenses found in this category!"<<endl;
    }

}
//function for searching by date
void searchByDate(vector<Expense>&expenses){
    string searchDate;
    int found = 0;
    cout<<"\nEnter the date: ";
    cin>>searchDate;
    for(int i = 0;i<expenses.size();i++){
        if(expenses[i].date == searchDate){
            cout<<"\nDescription: "<<expenses[i].description<<endl;
            cout<<"Amount: "<<expenses[i].amount<<endl;
            cout<<"Category: "<<expenses[i].category<<endl;

            found = 1;
        }
    }
    if(found == 0){
        cout<<"No expense found for this date!"<<endl;
    }
}

//MAIN FUNCTION
int main(){
   // vector<Expense> expenses;
    cout<<"=====EXPENSE TRACKER===== "<<endl;
    vector<Expense> expenses;
    int choice;
     do{
        cout<<"\n====EXPENSE TRACKER===="<<endl;
        cout<<"1. Add Expense"<<endl;
        cout<<"2. View Expense"<<endl;
        cout<<"3. Calculate Total"<<endl;
        cout<<"4. Edit Expense"<<endl;
        cout<<"5. Delete Expense"<<endl;
        cout<<"6. Expense Reports"<<endl;
        cout<<"7. Load Expenses"<<endl; 
        cout<<"8. Search Expense By ID"<<endl;
        cout<<"9. Search Expense By Category"<<endl;
        cout<<"10. Search Expense By Date"<<endl;
        cout<<"11. Exit"<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1: addExpense(expenses);
            break;
            case 2: viewExpenses(expenses);
            break;   
            case 3: calculateTotal(expenses);
            break;
            case 4: editExpense(expenses);
            break;
            case 5: deleteExpense(expenses);
            break;
            case 6: categorySummary(expenses);
            break;
            case 7: searchExpense(expenses);
            break;
            case 8: searchByCategory(expenses);
            break;
            case 9: searchByDate(expenses);
            break;
            case 10: saveExpenses(expenses);
            break;
            case 11: cout<<"Exiting Expense Tracker..."<<endl;
            break;
            default:cout<<"Invalid choice!"<<endl; 
            

        }
     }while(choice !=11);
    
    return 0;
}
