
using namespace std;

class TreeNode
{
public:
    void GetLastName(string lName);
    string GetLastName();
    TreeNode *left;
    TreeNode *right;
    
protected:
    string m_lName;
};
void TreeNode::GetLastName(string lName)
{
    m_lName = lName;
}
string TreeNode::GetLastName()
{
    return m_lName;
}
