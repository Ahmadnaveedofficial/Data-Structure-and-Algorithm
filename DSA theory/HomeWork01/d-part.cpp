// d) Write a function calculateGrade(int marks) that takes student marks (0–100) and returns
// their grade.
// Example:
// • Marks ≥ 85 → Grade A

// • 70–84 → Grade B
// • 55–69 → Grade C
// • 40–54 → Grade D
// • Below 40 → Grade F

#include <iostream>
using namespace std;
char calculateGrade(int marks) {
    if(marks>=85){
        return 'A';
    }else if(marks>=70){
        return 'B';
    }else if(marks >= 55){
        return 'C';
    }else if(marks>=40){
        return 'D';
    }else{
        return 'F';
    }
}
int main() {
    int marks;
    cout<<"Enter marks (0-100): ";
    cin>>marks;
    if(marks<0||marks>100) {
        cout<<"Invalid marks. Please enter a value between 0 and 100."<<endl;
    }else{
        cout<<"Grade: "<<calculateGrade(marks)<<endl;
    }
    return 0;
}