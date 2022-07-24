#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "student.h"
#include "TreeNode.h"
using namespace std;

void displayTree(student *&tree)
{
if (tree != NULL)
{
    displayTree(tree->left);
    cout << tree->fName() << " " << tree->lName() << endl;
    cout << tree->GPA() << endl;
    cout << tree->creditsTaken() << endl;
    cout << tree->standing() << endl << endl;
    displayTree(tree->right);
}
}
void insertTree(student *&tree, string fName, string lName, float gpa, float credits)
{
    student *n;
    
        if (tree == NULL)
        {
            n = new student;
            n->lName(lName);
            n->fName(fName);
            n->GPA(gpa);
            n->creditsTaken(credits);
            n->standing(credits);
            
            tree = n;
        }
        else if (lName < tree->lName())
            insertTree(tree->left, fName, lName, gpa, credits);
        else
            insertTree(tree->right, fName, lName, gpa, credits);
}
void searchTree(student *tree, string sName)
{
    student *f = NULL;
    
    if (tree == NULL)
    {
        cout << "Search name not found." << endl;
        return;
    }
    else if (tree->lName() > sName)
        searchTree(tree->left, sName);
    
    else if (tree->lName() < sName)
        searchTree(tree->right, sName);
        
    else
    {  f = tree;
    
    cout << "Entry found!" << endl;
    cout << f->fName() << " " << f->lName() << endl;
    cout << "GPA: " << f->GPA() << endl;
    cout << "Credits: " << f->creditsTaken() << endl;
    cout << "Standing: " << f->standing() << endl;
    
    return;
    }
}
void deleteNode(TreeNode *&tree)
{
    TreeNode *DeletingNode = tree;
    TreeNode *AttachPoint;
    
    cout << "Delete node: " << tree->GetLastName() << endl;
    
    if(tree->right == NULL)
        tree = tree->left;
    else if (tree->left == NULL)
        tree = tree->right;
    else
    {
        AttachPoint = tree->right;
        
        while (AttachPoint->left !=NULL)
            AttachPoint = AttachPoint->left;

        AttachPoint->left = tree->left;
        
        tree = tree->right;
    }
    delete DeletingNode;
        }

void removeTree(TreeNode *&tree, string lName)
{
    if (tree == NULL)
        return;
    
    else if (lName < tree->GetLastName())
        removeTree(tree->left, lName);
    else if (lName > tree->GetLastName())
        removeTree(tree->right, lName);
    
    else
        cout << "Remove Tree: " << tree ->GetLastName() << endl;
    deleteNode(tree);
    
}
int displayMenu()
{
    int opt;

    cout << "Enter one of the following options:" << endl;
    cout << "1. Display Tree" << endl;
    cout << "2. Search Tree" << endl;
    cout << "3. Add to Tree" << endl;
    cout << "4. Remove from Tree" << endl;
    cout << "5. Exit" << endl;
    cin >> opt;

    return opt;
}
int main()
{
    int opt;
    ifstream infile;
    student *tree = NULL;
    string sName;
    string lName, fName;
    float gpa, credits;

    infile.open("students.txt");
    
    while (!infile.eof())
    {
    infile >> fName >> lName >> gpa >> credits;
        insertTree(tree, fName, lName, gpa, credits);
        
    }
   
    displayTree(tree);
    
    opt = displayMenu();

    while (opt != 5)
    {
        if (opt == 1)
            displayTree(tree);
        else if (opt == 2)
        {
            cout << endl;
            cout << "Enter search last name: " << endl;
            cin >> sName;
            cout << endl;
            searchTree(tree, sName);
        }
        else if (opt == 3)
        {
            cout << endl;
            cout << "Enter first name: ";
            cin >> fName;
            cout << endl << "Enter last name: ";
            cin >> lName;
            cout << endl << "Enter gpa: ";
            cin >> gpa;
            cout << endl << "Enter credits taken: ";
            cin >> credits;
            
            insertTree(tree, fName, lName, gpa, credits);
        }
        else
            cout << "Enter Last Name of Entry to Delete: ";
            cin >> lName;
            removeTree(tree, lName);
        
        cin.clear();
        opt = displayMenu();
    }
}
