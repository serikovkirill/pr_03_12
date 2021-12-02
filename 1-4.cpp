#include<iostream>
#include<queue>
using namespace std;
int maxx = -1;
int m_size = 1;
struct node
{
    int info;                           
    node* l, * r;                        
};
node* tree = nullptr;
void push(int a, node** t)
{
    if ((*t) == nullptr)               
    {
        (*t) = new node;               
        (*t)->info = a;                 
        (*t)->l = (*t)->r = nullptr;
        return;                         //
    }

    if (a > (*t)->info) push(a, &(*t)->r); 
    else push(a, &(*t)->l);         
}
void print(node* t, int u)
{
    if (t == nullptr) return;
    else 
    {
        print(t->l, ++u);                   
        for (int i = 0; i < u; ++i) cout << endl;
        cout << t->info << endl;            
        u--;
    }
    print(t->r, ++u);                 
}
void DFS2(node* root) // прямой ход
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->info << " ";
    DFS2(root->l);
    DFS2(root->r);
}
void DFS3(node* root) //обратный ход
{
    if (root == nullptr)   
    {
        return;
    }
    DFS2(root->l);   
    DFS2(root->r);  
    cout << root->info << " ";
}
void DFS1(node* root) // центрированный ход
{
    if (root == nullptr)   
    {
        return;
    }
    DFS2(root->l);
    cout << root->info << " ";
    DFS2(root->r);
}
void BFS(node* root) {
    if (root == NULL)
    {
        return;
    }
    queue<node*> q; 
    q.push(root); 

    while (!q.empty()) 
    {
        node* temp = q.front(); 
        q.pop();  
        cout << temp->info << " "; 

        if (temp->l != nullptr)
            q.push(temp->l);  
        if (temp->r != nullptr)
            q.push(temp->r);  
    }
}
void print_node(node*& t, int lvl) {
    if (t == nullptr) {
        maxx = max(maxx, lvl);
    }
    if (t != nullptr) {
        print_node(t->r, lvl + 1);
        print_node(t->l, lvl + 1);
    }
}
void delete_node(int key) //удаление элемента по значению
{
    node* curr = tree;
    node* parent = nullptr;
    while (curr && curr->info != key)
    {
        parent = curr;
        if (curr->info > key)
        {
            curr = curr->l;
        }
        else
        {
            curr = curr->r;
        }
    }
    if (!curr)
        return;
    if (curr->l == nullptr)
    {
        if (parent && parent->l == curr)
            parent->l = curr->r;
        if (parent && parent->r == curr)
            parent->r = curr->r;
        --m_size;
        delete curr;
        return;
    }
    if (curr->r == nullptr)
    {
        if (parent && parent->l == curr)
            parent->l = curr->l;
        if (parent && parent->r == curr)
            parent->r = curr->l;
        --m_size;
        delete curr;
        return;
    }
    node* replace = curr->r;
    while (replace->l)
        replace = replace->l;
    int replace_value = replace->info;
    delete_node(replace_value);
    curr->info = replace_value;
}
int main(){
    int n;                              
    int s;                              
    cin >> n;                           
    for (int i = 0; i < n; ++i)
    {
        cin >> s;                       

        push(s, &tree);                 
    }
    //print(tree, 0);
    DFS1(tree);
    cout << endl;
    DFS2(tree);
    cout << endl;
    DFS3(tree);
    cout<<endl;
    BFS(tree);
    cout<<endl;
    print_node(tree, 0);
    cout << maxx;
    int a;
    cin >> a;
    delete_node(a);
    print(tree,0);
}