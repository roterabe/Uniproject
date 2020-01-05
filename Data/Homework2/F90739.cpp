#include <iostream>

using namespace std;

int cnt = 0;

struct node
{
    int pos;
    int value;
    node *left;
    node *right;
};

class btree
{
public:
    btree();
    ~btree();

    void add(int key);
    //void search(node *leaf, int &key, int &maxlevel, int level);
    void destroy_tree();
    void root();
    int LEFT(int pos);
    int RIGHT(int key);
    int parent(int key);
    int last();
    bool isRoot(int pos);
    bool hasLeft(int pos);
    bool hasRight(int pos);
    int remove();

private:
    void destroy_tree(node *leaf);
    void add(int key, node *leaf);
    void search(node *leaf, int &key, int level, int &maxlevel);
    void root(node *leaf);
    int LEFT(int pos, node *leaf);
    int RIGHT(int pos, node *leaf);
    int parent(int pos, node *leaf);
    int last(int &key, int &maxlevel, node *leaf);
    bool hasLeft(int pos, node *leaf);
    bool hasRight(int pos, node *leaf);
    int remove(node *leaf);
    void infix(node *leaf, int &key, int &pos);

    node *roote;
};

btree::btree()
{
    roote = NULL;
}

btree::~btree()
{
    destroy_tree();
}

int btree::remove()
{
    return remove(roote);
}

int btree::remove(node *leaf)
{
    int key = -1;
    // int maxlevel = -1;
    int pos = -1;
    infix(leaf, key, pos);
    // search(leaf, key, 0, maxlevel);
    int par = (pos - 1) / 2;
    int element;
    if (hasLeft(par))
    {
        leaf->left->pos = par;
        element = leaf->left->value;
        leaf->left = NULL;
    }
    else
    {
        leaf->right->pos = par;
        element = leaf->right->right->value;
        leaf->right = NULL;
    }

    return pos;
}

bool btree::hasLeft(int pos)
{
    return hasLeft(pos, roote);
}

bool btree::hasLeft(int pos, node *leaf)
{
    int key = -1;
    int maxlevel = -1;
    infix(leaf, key, maxlevel);
    //search(leaf, key, 0, maxlevel);
    if (2 * pos + 1 <= maxlevel)
        return true;
    else
        return false;
}

bool btree::hasRight(int pos)
{
    return hasRight(pos, roote);
}

bool btree::hasRight(int pos, node *leaf)
{
    int key = -1;
    int maxlevel = -1;
    infix(leaf, key, maxlevel);
    //search(leaf, key, 0, maxlevel);
    if (2 * pos + 2 <= maxlevel)
        return true;
    else
        return false;
}

bool btree::isRoot(int pos)
{
    if (pos == 0)
        return true;
    else
        return false;
}

int btree::last()
{
    int key = 0;
    int maxlevel = 0;
    return last(key, maxlevel, roote);
}

int btree::last(int &key, int &maxlevel, node *leaf)
{
    key = -1;
    maxlevel = -1;
    search(leaf, key, 0, maxlevel);
    return key;
}

int btree::parent(int pos)
{
    return parent(pos, roote);
}

int btree::parent(int pos, node *leaf)
{
    return (pos - 1) / 2;
}

int btree::LEFT(int pos)
{
    return LEFT(pos, roote);
}

int btree::LEFT(int pos, node *leaf)
{
    return (2 * pos + 1);
}

int btree::RIGHT(int pos)
{
    return RIGHT(pos, roote);
}

int btree::RIGHT(int pos, node *leaf)
{
    return (2 * pos + 2);
}

void btree::root()
{
    return root(roote);
}

void btree::root(node *leaf)
{
    cout << leaf->value << endl;
}

void btree::destroy_tree(node *leaf)
{
    if (leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::add(int key, node *leaf)
{

    if (key < leaf->value)
    {
        if (leaf->left != NULL)
        {
            add(key, leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->pos = ++cnt;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->value)
    {
        if (leaf->right != NULL)
        {
            add(key, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->pos = ++cnt;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

void btree::add(int key)
{
    if (roote != NULL)
    {
        add(key, roote);
    }
    else
    {
        roote = new node;
        roote->value = key;
        roote->left = NULL;
        roote->right = NULL;
    }
}

void btree::infix(node *leaf, int &key, int &pos)
{
    if (leaf != NULL)
    {
        if (true)
        {
            pos = leaf->pos;
            //pos = (pos - 1) / 2;
            //cout << leaf->pos << " ";
            key = leaf->value;
        }
        infix(leaf->left, key, pos);
        infix(leaf->right, key, pos);
    }
}

void btree::search(node *leaf, int &key, int level, int &maxlevel)
{

    if (leaf != NULL)
    {
        search(leaf->left, key, ++level, maxlevel);

        if (level > maxlevel)
        {
            key = leaf->value;
            maxlevel = level;
            //cout << key;
        }

        search(leaf->right, key, ++level, maxlevel);
    }
}

void btree::destroy_tree()
{
    destroy_tree(roote);
}

int main()
{

    //btree tree;
    btree *tree = new btree();

    tree->add(10);
    tree->add(6);
    tree->add(14);
    tree->add(5);
    tree->add(8);
    tree->add(11);
    //tree->add(18);
    tree->root();
    // cout<<tree->last()<<" ";
    //cout << tree->remove() << "\n";
    //tree->root();
    cout << tree->remove();

    //cout << tree->hasLeft(6) << endl;

    delete tree;
}

/*

    left(p) – връща лявото дете на възела на позиция p; - yes
    right(p) – връща дясното дете на възела на позиция p; - yes
    parent(p) – връща родителя на възела на позиция p; - yes
    root() – връща върха на Хипа; - yes
    last() – връща последният добавен елемент в Хипа; - yes
    isRoot(p) – връща true, ако възела на позиция p е корен и false, в противен случай; - yes
    hasLeft(p) – връща true, ако възела на позиция p има ляв наследник и false, в противен случай;
    hasRight(p) – връща true, ако възела на позиция p има десен наследник и false, в противен случай;
    add(e) – Добавя нов елемент към Хипа и връща нов външен възел v съхраняващ елемента e, така че полученият Хип да бъде пълно двоично дърво с последен възел v.
    remove() – Премахва последния възел на Хипа и връща неговият елемент.

*/