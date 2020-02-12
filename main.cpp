#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int ndig(int n){
    int ans=0;
    while(n){
        n/=10;
        ans++;
    }
    return ans;
}

class node{                              // Data type of a Binary Tree's node.
    
    int data;
    node* left;
    node* right;
    
public:
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
    
    friend class bTree;
};

class bTree{                             // Binary Tree's architecture.
    
    node *root;
    
public:
    
    bTree(){
        root=NULL;
    }
    ~bTree(){
        delete root;
    }
    
    void lvlip(){                        // Function to take level order input.
        
        cout<<"Enter root data : ";
        int a; cin>>a;
        root= new node(a);
        
        queue<node*> q;                  // A queue which will help to take inputs in correct order.
        q.push(root);
        
        while(!q.empty()){
            
            node* temp= q.front();
            q.pop();
            
            cout<<"Enter left child's data of "<<temp->data<<" : ";
            
            int al; cin>>al;
            
            if(al!= -1){                 // '-1' denotes absence of child.
                
                temp->left= new node(al);
                q.push(temp->left);
            }
            
            cout<<"Enter right child's data of "<<temp->data<<" : ";
            
            cin>>al;
            
            if(al!= -1){                 // '-1' denotes absence of child.
                
                temp->right= new node(al);
                q.push(temp->right);
            }
        }
    }
    
    int height(){                        // Function to find height of the Binary Tree.
        
        if (root==NULL) return -1;
        
        int ht=-1;
        
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        
        while (!q.empty()){
            node* f=q.front();
            q.pop();
            
            if (f==NULL){
                ht++;
                if (!q.empty()) q.push(NULL);
            }
            else{
                if (f->left!=NULL) q.push(f->left);
                if (f->right!=NULL) q.push(f->right);
            }
        }
        return ht;
    }
    
    void showTree(){                     // Function which displays the Binary Tree with CORRECT INDENTATION.
        int H=height();
        
        int ht=2+height();               // ht is given a larger value than actual height for neatness.
        
        node* spc= new node(-1);         // A node which represents empty nodes of the tree. ( Basically to print spaces. )
        
        queue<node*> q,q1;               // Queues which ensure proper order.
        
        q.push(root);
        q.push(NULL);
        
        bool rn=true;                    // Variable which stops the following 'while' loop when all nodes have been displayed.
        
        int h=0;
        for(h=1; h<= pow(2, ht)-1;h++) cout<<" ";      // Printing the spaces before the root node.
        
        while (rn && !q.empty()){
            
            q1=q;
            bool brk=true;
            
            while(!q1.empty()){
                if(q1.front()!=spc && q1.front()!=NULL) brk=false;
                q1.pop();
            }
            
            if(brk) rn=false;            // If no node remains, variable 'rn' will break the 'while' loop.
            
            node* f=q.front();           // Node on which processes will be applied.
            q.pop();
            
            if (f==NULL){                // New line when a level ends.
                cout<<endl;
                
                if(ht-2 >0){
                    
                    // Printing " | " ...
                    
                    int non=pow(2,H-(ht-2)) -1;
                    
                    queue<node*> q2=q;
                    int narr[100]={};
                    
                    for(int nn=0; nn<= 2*(non)+1 ; nn++){
                        if(q2.front()!=spc && q2.front()!=NULL){
                            narr[nn]=1;
                        }
                        q2.pop();
                    }
                    for(h=1; h<= pow(2, ht)-1;h++) cout<<" ";
                    for(int nn=0; nn< 2*(non)+1 ; nn+=2){
                        if(narr[nn]==1 || narr[nn+1]==1) cout<<"!";
                        else cout<<" ";
                        for(h=1; h<= 2*(pow(2, ht)-1) +1 ;h++) cout<<" ";
                    }
                    cout<<endl;
                    
                    // Printing " _____ " ...
                    
                    queue<node*> q4=q;
                    int narr2[100]={};
                    
                    for(int nn=0; nn<= 2*(non)+1 ; nn++){
                        if(q4.front()!=spc && q4.front()!=NULL){
                            narr2[nn]=1;
                        }
                        q4.pop();
                    }
                    
                    for(h=0; h<= pow(2, ht-1)-1;h++) cout<<" ";
                    
                    for(int nn=0; nn< 2*(non)+1 ; nn+=2){
                        
                        if(narr2[nn]==1 && narr2[nn+1]==1){
                            for(h=1; h<= 2*(pow(2, ht-1)-1) +1 ;h++) cout<<"_";
                            cout<<"  ";
                        }
                        
                        else if(narr2[nn]==0 && narr2[nn+1]==1){
                            
                            for(h=1; h<= (2*(pow(2, ht-1)-1) +1)/2 ;h++) cout<<" ";
                            
                            for(h=0; h<= (2*(pow(2, ht-1)-1) +1)/2 ;h++) cout<<"_";
                            cout<<"  ";
                            
                        }
                        else if(narr2[nn]==1 && narr2[nn+1]==0){
                            
                            for(h=0; h<= (2*(pow(2, ht-1)-1) +1)/2 ;h++) cout<<"_";
                            
                            for(h=1; h<= (2*(pow(2, ht-1)-1) +1)/2 ;h++) cout<<" ";
                            cout<<"  ";
                        }
                        else for(h=1; h<= 2*(pow(2, ht-1)-1) +3 ;h++) cout<<" ";
                        
                        for(h=1; h<= 2*(pow(2, ht-1)-1) +1 ;h++) cout<<" ";
                    }
                    cout<<endl;
                    
                    
                    // Printing  " / \ " ...
                    
                    
                    queue<node*> q3=q;
                    int narr1[100]={};
                    
                    for(int nn=0; nn<= 2*(non)+1 ; nn++){
                        if(q3.front()!=spc && q3.front()!=NULL){
                            narr1[nn]=1;
                        }
                        q3.pop();
                    }
                    for(h=1; h<= pow(2, ht-1)-1;h++) cout<<" ";
                    int br=0;
                    for(int nn=0; nn<= 2*(non)+1 ; nn++){
                        if(narr1[nn]==1){
                            if(br%2==0) cout<<"/";
                            else cout<<"\\";
                        }
                        else cout<<" ";
                        for(h=1; h<= 2*(pow(2, ht-1)-1) +1 ;h++) cout<<" ";
                        br++;
                    }
                    cout<<endl;
                    
                }
                
                ht--;
                int ndg= ndig(q.front()->data)-1;
                for(h=1; h<= pow(2, ht)-1-ndg ;h++) cout<<" ";              // Printing spaces after a node.
                if (!q.empty()) q.push(NULL);
            }
            
            else{
                if(f!=spc) cout<<f->data;
                else cout<<" ";                                        // If node is not present, a space will be printed.
                
                int ndg= ndig(f->data)-1;
                
                for(h=1; h<= 2*(pow(2, ht)-1) +1 -ndg;h++) cout<<" ";      // Printing spaces after a node.
                
                
                
                if (f->left!=NULL) q.push(f->left);
                else q.push(spc);                       // This will represent a blank node. ( To print spaces. )
                
                if (f->right!=NULL) q.push(f->right);
                else q.push(spc);                       // This will represent a blank node. ( To print spaces. )
                
            }
        }
        cout<<endl<<endl<<endl;
    }
    
    void dleaf(node *n){
        node *c1=n->left, *c2=n->right;
        if(c1!=NULL){
            if(c1->left==NULL && c1->right==NULL){
                n->left=NULL;
            }
        }
        if(c2!=NULL){
            if(c2->left==NULL && c2->right==NULL){
                n->right=NULL;
            }
        }
        if(c1!=NULL){
            dleaf(c1);
        }
        if(c2!=NULL){
            dleaf(c2);
        }
    }
    void dleaf(){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            root=NULL;
            return;
        }
        dleaf(root);
    }
    node* par(node*fp, node* n){
        if(n==root) return NULL;
        
        if(fp->left==n || fp->right==n) return fp;
        
        if(fp->data > n->data) return par(fp->left, n);
        return par(fp->right, n);
    }
    node* par(node*n){
        return par(root, n);
    }
    
};

int main(){                                        // The main function.
    
    bTree t;
    
    t.lvlip();                                     // Function call to take input (level order).
    
    cout<<endl<<endl;
    cout<<"The Tree is : "<<endl<<endl;
    
    t.showTree();                                  // Function call to display the Binary Tree with CORRECT INDENTATION.
    
    //t.dleaf();
    //t.showTree();
    //t.par(47);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1

// 1 2 3 4 -1 -1 5 6 -1 7 8 -1 -1 -1 -1 -1

// 2 3 4 5 6 7 8 9 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1


