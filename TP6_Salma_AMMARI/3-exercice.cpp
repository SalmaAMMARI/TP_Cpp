#include <iostream>
using namespace std ;
struct Node{
    //Attributs
    int data ;
    Node* right ;// pointer to the right node
    Node* left ; // pointer to a object of type node , left node
    //COnstructeur
    Node(int value){
        data = value;
        right = nullptr;
        left =nullptr ;
    }
    //methods :
    Node* insert(Node* node , int value){
        // a fct that returns a pointer to a tree( Node*) after inserting a node in it
        if (node== nullptr){
            //if the tree is empty
            return new Node(value);// the new tree is the node made from value

        }
        if (value<node->data){
            node->left=insert(node->left , value);
        }else if (value>node->data){
           node->right= insert(node->right , value );

        }
        // otheriwse value == node.data : return the tree itself
        return node;
    }

    bool recherch(Node* node , int value){
        if (node== nullptr){
            return false;

        }
        if (value==node->data){
            return true ;
        }
        if (value>node->data){
            return recherch(node->right , value);
        }else{
            return recherch(node->left , value);
        }
    }
    Node* minNode(Node* node){
        Node* current = node ;
        while (current &&current->left!=nullptr){
            current = current->left ;
        }
        return current ;

    };
    Node* remove(Node* node , int value){
        // the fct returns the tree after deletion
        if (node== nullptr){
            return node ;
            // if the tree is empty we do nothing

        }
        if (value<node->data){
            node->left = remove(node->left , value);
            // we delete the value from the left subtree
        }else if (value>node->data){
            node->right = remove(node->right , value);
        }else{
            //if node->data==value
            // we check if the tree doesnt have a child : left or right then we remove only the node and we return the child
            //if the tree has both children then we have to take the node with min value from the right subtree
            // store it in the root and then remove the node from the right child that has the min value
            if (node->left== nullptr){
                Node* temp=node->right ;
                delete node;
                return temp;
            } else if (node->right== nullptr){
                Node* temp= node->left ;
                delete node ;
                return temp ;
            }
            //if it has both children then we need tif find the node with the min value in the right subtree
            Node* minnode=minNode(node->right);
            node->data=minnode->data;
            node->right=remove(node->right,minnode->data);

        }
        return node;
    }
    //inorder: left + node + right
void inorder(Node* node){
        if (node!=nullptr){
            inorder(node->left);
            cout<<node->data<<" ";
            inorder(node->right);


        }
    }

};

int main() {
    Node* root = nullptr;  // L'arbre commence vide

    // Insérer les éléments dans l'arbre
    cout << "Insertion des elements : 5 3 7 2 4 6 8" << endl;
    root = root->insert(root, 5);
    root = root->insert(root, 3);
    root = root->insert(root, 7);
    root = root->insert(root, 2);
    root = root->insert(root, 4);
    root = root->insert(root, 6);
    root = root->insert(root, 8);
    cout<<"Parcours infixe:"<<endl;
    root->inorder(root);
    cout<<"\nRecherche de 4 :";
    if (root->recherch(root,5)){
        cout<<"Trouve";
    }else{
        cout<<"Non trouve";
    }
    cout<<"\nSupression de 4:\n";
    root->remove(root,4);
    cout<<"Parcours infixe apres supprssion :\n";
    root->inorder(root);



}
