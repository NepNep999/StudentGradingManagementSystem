#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Student {
private:
    char names[50][50];
    int roll[50];
    float grade[50][5]; // Store grades for 5 subjects
    float avg[50];
    char remarks[50][20]; // Store remarks for each student
    int s; // Current student index

    void average(int index) {
        float combined=0;
        for(int l=0;l<5;l++) {
            combined+=grade[index][l];
        }
        avg[index]=combined/5;
    }

    void assign(int index) {
        if(avg[index]>=90) {
            strcpy(remarks[index],"Excellent");
        } else if(avg[index]>=75) {
            strcpy(remarks[index],"Very Good");
        } else if(avg[index]>=50) {
            strcpy(remarks[index],"Passed");
        } else {
            strcpy(remarks[index],"Failed");
        }
    }

public:
    void setIndex(int index) {
        s=index;
    }

    void input() {
    	system("CLS");
        cout<<"-Entering Data for Student "<<(s+1)<<"---"<<endl;
        cin.ignore();
        cout<<"Enter student name: ";
        cin.getline(names[s],50);
        cout<<"Enter roll number: ";
        cin>>roll[s];

        for(int i=0;i<5;++i) {
            do {
                cout<<"Enter marks for subject "<<(i+1)<<"(0-100): ";
                cin>>grade[s][i];
                if(grade[s][i]<0||grade[s][i]>100) {
                    cout<<"Invalid input. Please enter marks between 0 and 100."<<endl;
                }
            } while(grade[s][i]<0||grade[s][i]>100);
        }
        average(s);
        assign(s);
    }

    void display() {
    	system("CLS");
        cout<<"Name: "<<names[s]<<endl;
        cout<<"Roll Number: "<<roll[s]<<endl;
        cout<<"Marks: ";
        for(int i=0;i<5;i++) {
            cout<<grade[s][i]<<" ";
        }
        cout<<endl;
        cout<<"Average: "<<fixed<<setprecision(2)<<avg[s]<<endl;
        cout<<"Remarks: "<<remarks[s]<<endl;
        cout<<"---------------------------"<<endl;
    }
};

int main() {
    Student s[50];
    int count=0;
    int choice;
        cout<<setw(50)<<"Student Grades Management System"<<endl;
        cout<<"1. Add Student Record"<<endl;
        cout<<"2. View All Student Records"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1) {
            if(count<50) {
                s[count].setIndex(count);
                s[count].input();
                count++;
                main();
            } else {
                cout<<"Maximum number of student records reached (50)."<<endl;
            }
        } else if(choice==2) {
            if(count==0) {
                cout<<"No records to display."<<endl;
            } else {
                for(int i=0;i<count;++i) {
                    s[i].setIndex(i);
                    cout<<endl<<"Student "<<(i+1)<<":"<<endl;
                    s[i].display();
                }
            }
        } else if(choice==3) {
            cout<<"Thank you and Goodbye!"<<endl;
            exit(0);
        } else {
            cout<<"Invalid choice. Try again."<<endl;
        }
}


