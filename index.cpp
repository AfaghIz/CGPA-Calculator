#include <iostream>
#include <strings.h>
#include <string>
#include <new>  
using namespace std;

//Constraints: MAX 100 courses as input

string* createarray(int size)
{
  string* ca = new string[size]; // ca = course amount
  return ca;
};


void deletearr(string* ptr)
{
  if (ptr != nullptr)
  {
    delete[] ptr;
    ptr = nullptr;
  }
  cout << "successfully deleted" << endl;
};

int gradesum(int size, int totalgrade, int grade[]) //totalgrade variable is passed by reference (original is edited)
{
    for (int x = 0; x < size; x++) //calculates total grade recieved
        {
            totalgrade = totalgrade + grade[x];
        }
    return totalgrade;    
}

double CGPA(double totalgrade, int sumcoursegrade)
{
    double cGPA;
    cGPA = (totalgrade/sumcoursegrade) * 100;
    cGPA = cGPA/ 9.5;
    return cGPA;
}

int main(){

    int ans;
    int size;
    double cgpa;
    double totalgrade = 0; //grade recived by student
    int sumcoursegrade = 0; //total grade of all courses combined 
    cout << "Please insert the number of courses: ";
    cin >> size;
    string* array = createarray(size);
    int grade[100]; //max 100 classes
    int credits[100]; 

    for (int i = 0; i < size; i++) //takes name of each class
    {
        cout << "Please insert the name of each class: ";
        cin >> array[i];
    }
    
    
    for (int j = 0; j < size; j++) //takes grade for each course
    {
        cout << "Please insert the grade recieved for course '" << array[j] << "' : ";
        cin >> grade[j];
    }
    
   totalgrade = gradesum(size, totalgrade, grade);
   cout << totalgrade << endl;
   sumcoursegrade = size * 100; //Sum of max grade of all courses 
   cout << sumcoursegrade << endl;

    for (int k = 0; k < size; k++) //takes credits of each course
    {
        cout <<"Please insert the credits recieved for course '" << array[k] << "' : ";
        cin >> credits[k];
    }

  cgpa = CGPA(totalgrade, sumcoursegrade);
  cout << cgpa << endl;

    cout << "Please select:" << endl;
    cout << "1) GRADES" << endl;
    cout << "2) CGPA" << endl;
    cout << "3) Exit" << endl;
    cin >> ans;

  switch (ans)
    {
    case 1:
    cout << "COURSE     CREDITS     GRADES" << endl;
    for (int i = 0; i < size; i++)//shows classes 
    {
        cout << array[i] << "    \t" << credits[i] << "     \t" << grade[i] << endl;
    }
        break;
    case 2:
        cout << "CGPA: " << cgpa << endl;
    case 3:
        break;
    default:
        cout << "Invalid Value";
        break;
    }

    deletearr(array);
}


