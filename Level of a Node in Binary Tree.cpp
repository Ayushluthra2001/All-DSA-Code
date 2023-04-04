//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
class Solution{
  public:
    // function should return level of the target node
    void solve(struct Node* node,int target ,int &level,int curr){
        if(node==NULL) return ;
        if(level>0) return ;
        if(node->data==target) {
            level=curr;
            return ;
        } 
        solve(node->left,target,level,curr+1);
        solve(node->right,target,level,curr+1);
    }
    int getLevel(struct Node *node, int target)
    {
    	//code here
    	int level=0;
    	solve(node,target,level,0);
    	return level==0 ? 0 : level+1;
    }
};


//{ Driver Code Starts.
int main() {
//   freopen("input.txt","r", stdin);
//   freopen("output.txt","w", stdout);
//   fflush(stdin);

   int t=0;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
  
   while(t--)
   {
       string s ,ch;
       getline(cin, s);
       Node* root = buildTree(s);

       string key;
   		getline(cin, key);
   		int target=stoi(key);
      // getline(cin, ch);
      Solution obj;
       cout << obj.getLevel(root, target) << "\n";
       //cout<<"~"<<"\n";
   }
   return 0;
}
// } Driver Code Ends
