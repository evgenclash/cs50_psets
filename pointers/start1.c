#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                        //Data of the node
    struct node *nextptr;           //Address of the next node
    struct node *prevptr;
}*stnode;

void createNodeList(int n); // function to create the list
void displayList();         // function to display the list
void addNode(int a, int b);             // function to add a new node to the start of the list
void addNodeEnd();
int main()
{
    int n, num;
		printf("\n\n Linked List : To create and display Singly Linked List :\n");
		printf("-------------------------------------------------------------\n");
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList();
    //  printf ("insert the number to check");
    // scanf ("%d", &num);
    // addNode(n, num); 
    // addNodeEnd();
    // displayList();
    return 0;
}
void createNodeList(int n)
{
    struct node *fnNode;
    static struct node *tmp;
    int num;
    stnode =(struct node*) malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    // Creating n nodes and adding to linked list
            if (n > 1)
            {
                createNodeList(n - 1);
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode == NULL)
                {
                    printf(" Memory can not be allocated.");
                    
                }
                else
                {
                    printf(" Input data for node %d : ", n);
                    scanf(" %d", &num);
                    
                    fnNode->num = num;      // links the num field of fnNode with num
                    fnNode->nextptr = NULL; // links the address field of fnNode with NULL
                    fnNode->prevptr = tmp;
                    tmp->nextptr = fnNode;// links previous node i.e. tmp to the fnNode
                    tmp = fnNode;
                }
            }
// reads data for the node through keyboard
    else
    {
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->nextptr = NULL; // links the address field to NULL
        stnode->prevptr = NULL;
        tmp = stnode;
    }
}
void displayList()
{
    int i = 0;
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
         tmp = stnode;
        while(tmp->nextptr !=NULL)
        {
            tmp = tmp->nextptr;
        }
        while(tmp!= NULL)
        {
            printf(" Data = %d\n", tmp->num);       // prints the data of current node
            tmp = tmp->prevptr;                     // advances the position of current node
            i++;
        }
        printf ("Number of nodes you entered %d\n", i);
    }
} 

void addNode(int a, int b)
{
    struct node *tmp;
    tmp = stnode;
    if (a > 0)
    {
        for (int i = 2; i < a; i++)
        {
            tmp = tmp->nextptr;
        }
        if (tmp->num == b)
        {
            printf ("Your number is placed in the node %d \n", a-1);
        }
        else 
        {
            addNode(a-1, b);
        }
    }
    else
    {
        printf ("Node not found\n");
    }
    
}

void addNodeEnd()
{
    int num,n;
    struct node *tmp, *p, *temp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
        temp = stnode;
        // printf ("Add a new node at the end of the list ");
        // scanf ("%d", &num);
        printf ("What to delete? ");
        scanf ("%d", &n);
        for (int i = 1; i < n; i++)
        {
            tmp = temp;
            temp = temp->nextptr;
        }
        
            tmp->nextptr = temp->nextptr;
            // p = (struct node *)malloc(sizeof(struct node));
            // p->num = num;
            // p->nextptr = temp;
            // temp = temp->nextptr;
            
            // tmp->nextptr = p;
        
    
}