/*
 * C++ Program to Implement Singly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
};//*start;

/*
 * Class Declaration
 */
class single_llist
{
    public:
        node* create_node(int value);
        void insert_begin(int value);
        void insert_pos(int value, int pos);
        void insert_last(int value);
        void delete_pos(int pos);
        void sort();
        void search();
        void update();
        void reverse();
        void display();

        //void store_num(int num);
        void add_two_num(int num1, int num2);

        single_llist()
        {
            start = NULL;
        }
    private:
        struct node *start;
};


/*
 * Creating Node
 */
node *single_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;
        return temp;
    }
}

/*
 * Inserting element in beginning
 */
void single_llist::insert_begin(int value)
{
    //int value;
    //cout<<"Enter the value to be inserted: ";
    //cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }

    cout<<"Element Inserted at beginning"<<endl;
}

/*
 * Inserting Node at l        void store_num(int num);
        void add_two_num(int num1, int num2);ast
 */
void single_llist::insert_last(int value)
{
    //int value;
    //cout<<"Enter the value to be inserted: ";
    //cin>>value;insert_begin
    struct node *temp, *s;
    temp = create_node(value);

    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        s = start;
        while (s->next != NULL)
        {
            s = s->next;
        }
        temp->next = NULL;
        s->next = temp;
    }
    cout<<"Element Inserted at last"<<endl;
}

/*
 * Insertion of node at a given position
 */
void single_llist::insert_pos(int value, int pos)
{
    //int value, pos, counter = 0;
    int counter=0;
    //cout<<"Enter the value to be inserted: ";
    //cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    //cout<<"Enter the postion at which node to be inserted: ";
    //cin>>pos;insert_begin
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        cout<<"Positon out of range"<<endl;
    }
}

/*
 * Sorting Link List
 */
void single_llist::sort()
{
    struct node *ptr, *s;
    int value;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->info > s->info)
            {
                value = ptr->info;
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next;
    }
}

/*
 * Delete element at a given position
 */
void single_llist::delete_pos(int pos)
{
    int i, counter = 0;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    //cout<<"Enter the position of value to be deleted: ";
    //cin>>pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}

/*
 * Update a given Node
 */
void single_llist::update()
{
    int value, pos, i;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    //cout<<"Enter the node postion to be updated: ";
    //cin>>pos;
    //cout<<"Enter the new value: ";
    //cin>>value;
    struct node *s;
    s = start;
    if (pos == 1)
    {
        start->info = value;
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->info = value;
    }
    cout<<"Node Updated"<<endl;
}

/*
 * Searching an element
 */
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    //cout<<"Enter the value to be searched: ";
    //cin>>value;
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->info == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;
}

/*
 * Reverse Link List
 */
void single_llist::reverse()
{
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (start->next == NULL)
    {
        return;
    }
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
    }
    start = ptr2;
}

/*
 * Display Elements of a link list
 */
void single_llist::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void single_llist::add_two_num(int num1, int num2)
{
//    int i,j;
    single_llist s1, s2, s;
    struct node *p1, *p2, *p;
    int result=0;
    int carry = 0;

    while (num1)
    {
        s1.insert_last(num1%10);
        num1/=10;
    }
    s1.display();

    while (num2)
    {
        s2.insert_last(num2%10);
        num2/=10;
    }

    s2.display();
    //
    p1 = s1.start;
    p2 = s2.start;

    while (p1&&p2)
    {
       result = (p1->info + p2->info + carry) % 10;
       carry = (p1->info + p2->info + carry) / 10;

       cout <<"in while, carry="<<carry<<", result="<<result<<endl;
       s.insert_last(result);
       p1 = p1->next;
       p2 = p2->next;

    }

    if (p1||p2)
    {
        p = p1? p1 : p2;
        result = (p->info + carry) % 10;
        carry = (p->info + carry) /10;
        s.insert_last(result);
        if (carry)
        {
            s.insert_last(carry);
        }
        cout <<"after while, carry="<<carry<<", result="<<result<<endl;

    }

    s.display();
//    p = s->start; result = 0;
//    while (p)
//    {
//        result += result
//    }



}

/*
 * Main :contains menu
 */
int main()
{
    //int choice, nodes, element, position, i;
    //single_llist s1, s2;
    single_llist s;

    #if 0
    int num1, num2;
    num1 = 237;
    num2 = 383;
    cout<<"now num1="<<num1<<" ,num2="<<num2<<endl;
    while (num1)
    {
        s1.insert_last(num1%10);
        num1/=10;
    }
    s1.display();

    while (num2)
    {
        s2.insert_last(num2%10);
        num2/=10;
    }
    s2.display();
    #endif

    //s.add_two_num(342, 465);
    s.add_two_num(942, 65);



    return 0;
}
