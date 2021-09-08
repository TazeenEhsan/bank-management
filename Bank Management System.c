
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct st
{
    char name[20];
    int account_no;

    char password[15];
    int balance;

    char contact[15];
    char address[40];

    struct st *next;
}node;
struct st2
{
    char name[20];
    int serial;
    struct st2 *next;
}*head2;

node *head;


void st()
{

    char s[20];
    int a;

    char p[15];
    int b;

    char c[15];
    char ad[40];

     node *temp=(node*)malloc(sizeof(node));

     printf("\nEnter name:");
     gets(s);
     gets(s);
     strcpy(temp->name,s);

     printf("Enter account no.:");
     scanf("%d",&a);
     temp->account_no=a;

     printf("Enter password: ");
     gets(p);
     gets(p);
     strcpy(temp->password,p);

     printf("Enter balance: ");
     scanf("%d",&b);
     temp->balance=b;

     printf("Enter contact: ");
     gets(c);
     gets(c);
     strcpy(temp->contact,c);

     printf("Enter address: ");
     gets(ad);
     strcpy(temp->address,ad);
     temp->next=NULL;
    if(head==NULL)
    {
        head=temp;

    }
    else
    {
        node *temp2=head;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}
void deposit()
{
    int a,b;
    char s[20];
    node *temp=head;
    printf("Enter your account no.");
    scanf("%d",&a);
    printf("Enter your password:");
    gets(s);
    gets(s);
    while(temp->account_no!=a && temp->password!=s)
    {
        temp=temp->next;

    }
     if(temp->account_no!=a && temp->password!=s)
        {
            printf("\nAccount does not match\n");

        }
      else

    printf("Enter the amount to deposit:");
    scanf("%d",&b);
    temp->balance+=b;
    printf("\nDeposit successfully\n");

}
void withdrw()
{
    int a,b;
    char s[20];
    node *temp=head;
    printf("Enter your account no.");
    scanf("%d",&a);
    printf("Enter your password:");
    gets(s);
    gets(s);
    while(temp->account_no!=a && temp->password!=s)

    {
        temp=temp->next;

    }
     if(temp->account_no!=a && temp->password!=s)
        {
            printf("\nAccount does not match!\n");

        }
     else


    printf("Enter the amount to withdrw:");
    scanf("%d",&b);
    if(b>temp->balance)
    {
        printf("\nYou cannot withdraw money!\n");
    }
    else
    {


    temp->balance-=b;
    printf("\nwithdrw successfully\n");
    }
}
void infrmtn()
{
    int a;
    char s[20];
    node *temp=head;
    printf("Enter your account no.");
    scanf("%d",&a);

    printf("Enter your password:");
    gets(s);
    gets(s);
    while(temp->account_no!=a && temp->password!=s)
    {
        temp=temp->next;

    }
    if(temp->account_no!=a && temp->password!=s)
        {
            printf("\nAccount does not match\n");

        }
        else

      printf("\t\t********Account Information*******");

     printf("Name:");
     puts(temp->name);
     printf("Account no.%d\n",temp->account_no);
     printf("Balance is: %d\n",temp->balance);
     printf("Contact no:");
     puts(temp->contact);
     printf("Address:");
     puts(temp->address);
}
int insrt(int b)
{
       char s[20];
      struct st2 *temp2;
      struct st2 *temp=(struct st2*)malloc(sizeof(struct st2));

      printf("\n\nPlease sir enter your name and collect your serial number:");
      gets(s);
      b++;
      strcpy(temp->name,s);
      temp->serial=b;

     temp->next=NULL;
     if(head2==NULL)
     {
        head2=temp;
     }
     else
     {
        struct st2 *temp2=head2;
        while(temp2->next!=NULL)
        {

            temp2=temp2->next;

        }


        temp2->next=temp;

     }

      printf("\nYour serial number is A%d\t\tThank you. Wait for the call.\n\n\nNext person\n",temp->serial);
     return b;
}
void call()
{

    printf("\n\nSerial number A%d , Mr.%s ",head2->serial,head2->name);
      // puts(head2->name);
       printf("please come in\n\n");
       head2=head2->next;

}

int main()
{
    int n,ac,sc,i,j,c=2,a=3,b=100;
    char s[20];
    printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-Welcome to ST Bank Limited-**-**-**-**-**-**-**-**-**-**-**\n\t\t**-**-**-**-**-**-**-**-**-**-**-\t\t\t    **-**-**-**-**-**-**-**-**-**-**\t\t\t\t**-**-**-**-**-**-**-**-**-**-**-\t\t\t    **-**-**-**-**-**-**-**-**-**-**\n\n");

   while(1)
   {


    for(i=0;i<a;i++)
    {
        b=insrt(b);
    }




    for(j=0;j<a;j++)

     {


       call();


        printf("\n\nIf you dont have an account in our bank,then kindly call for Admin\n\n");
        while(1)
        {



         printf("\nOptions are:    \n1.Admin    \n2.Recipient    \n3.Exit\nEnter choice:");
         scanf("%d",&n);
          if(n==1)
        {
            printf("\n\n*********************Admin Tasks***********************\n");
            printf("\n\nChoose task:  \n1.Add user.  \n2.Exit.\n\nEnter choice:");
            scanf("%d",&ac);
            if(ac==1)
            {
                st();
            }
            else if(ac==2)
            {
                break;
            }

        }
         else if(n==2)
        {
            printf("           **Recipient Tasks**\n");
            printf("Choose task:  \n1.Cash Deposit  \n2.Cash Withdraw  \n3.Account Information  \n4.Exit\nEnter choice:");
            scanf("%d",&sc);

            if(sc==1)
            {
                deposit();
            }
            else if(sc==2)
            {
                withdrw();
            }
             else if(sc==3)
             {
                 infrmtn();
             }
             else if(sc==4)
             {
                 break;
             }

        }
        else if(n==3)
        {
            printf("\n\tTHANK YOU SIR.PLEASE COME AGAIN\n\n");
            break;
        }


        }
    }
   }
 return 0;

  }

