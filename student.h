#include<iostream>
#include<string>

using namespace std;

class student
{
public:
    student();

    void fName(string fn);
    string fName();

    void lName(string ln);
    string lName();

    void GPA(float gpa);
    float GPA();

    void creditsTaken(float credits);
    float creditsTaken();

    virtual void standing(float p_cr);
    virtual string standing();
 
    student *left;
    student *right;

protected:
    string p_fn, p_ln, p_st;
    float p_gpa, p_cr;
};

student::student()
{
    p_fn = "Donald";
    p_ln = "Duck";
    p_gpa = 0.00f;
    p_cr = 0.00f;
    p_st = "freshman";
}

void student::fName(string fn)
{
    p_fn = fn;
}
string student::fName()
{
    return p_fn;
}
void student::lName(string ln)
{
    p_ln = ln;
}
string student::lName()
{
    return p_ln;
}
void student::GPA(float gpa)
{
    p_gpa = gpa;
}
float student::GPA()
{
    return p_gpa;
}

void student::creditsTaken(float credits)
{
    p_cr = credits;
}
float student::creditsTaken()
{
    return p_cr;
}
void student::standing(float credits)
{
    if (credits > 120)
        p_st = "Senior";
    else if (credits > 80)
        p_st = "Junior";
    else if (credits > 50)
        p_st = "Sophomore";
    else
        p_st = "Freshman";
}
string student::standing()
{
    return p_st;
}
