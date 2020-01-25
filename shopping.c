#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct StackNode{
    int id;
    char pname[100];
    int price;
    struct StackNode *next;
};
void push(struct StackNode **root,int id,char str2[],int cost)
{
    int i=0;
    struct StackNode* stackNode=(struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->id=id;
    strcpy(stackNode->pname,str2);
    stackNode->price=cost;
    stackNode->next=*root;
    *root=stackNode;
}
void poplast(struct Stacknode **root){
    int itemid;
    char itemname[100];
    int itemprice;
    struct StackNode *temp;
    temp=*root;
    itemid=temp->id;
    strcpy(itemname,temp->pname);
    itemprice=temp->price;
    *root=temp->next;
    free(temp);
}
void pop(struct StackNode **root,int idt)
{
    struct StackNode *temp,*old;
    temp=*root;
    //isEmpty
    while(temp!=NULL){
        if(temp->id==idt){
            if(temp==*root){
                *root=temp->next;
                free(temp);
                return;
            }else{
            old->next=temp->next;
            free(temp);
            return;
            }
           }
            else{
            old=temp;
            temp=temp->next;
           }
        }
        printf("\nProduct not found");
}
void display(struct StackNode *root){
    int i;
  printf("\n");
  while(root!=NULL){
     printf("\t%d\t%s\t\t %d\n", root->id,root->pname,root->price);
        root = root->next;
    }
  }

int count(struct StackNode *root){
  int c=0,i;
  for(i=0;i<5;i++){
  while(root!=NULL){
    root=root->next;
    c++;
   }
  }
  return c;
}
//main() function
void main()
{
 static int totalCost;
 int i,j,choice,c=1/*inserting elements*/,cost[100];
 struct StackNode *top=NULL,*node,*old;
 char str[100];
 char items[100][100]={"HP LCD Monitor",
 "Logitech Mouse",
 "Sandisk 16GB Pendrive",
 "Lee",
 "clothVilla",
 "Manyavar",
 "iPhone XS",
 "Pixel 3",
 "Lenovo K9"
 };
 printf("Please Enter Your good Name\n");
 gets(str);
 printf("Hello %s, Welcome to our Online Shopping.\n",str);
 do{
  //C is 1 to set 'insert' as first choice
  if(c==1){
  printf("Enter\n1 - Computer Accessories\n2 - Cloths\n3 - Mobiles\nAny other number to exit\n");
  printf("(You can add only 5 Products)\n");
  scanf("%d",&choice);
  //all choice 1st group
  switch(choice)
  {
   case 1:  //computer accessories
   {
    int accessoriesChoice;
    printf("Enter\n1 - HP LCD Monitor - Rs.28389\n2 - Logitech Mouse- Rs.500\n3 - Sandisk 16GB Pendrive - Rs.550\nAny other number to exit\n");
    scanf("%d",&accessoriesChoice);
    cost[0]=28389;
    cost[1]=500;
    cost[2]=550;
    //subgroup under computer a. choice
    switch(accessoriesChoice)
    {
     case 1:
     {
      int num;
      char product[100]="HP LCD Monitor";
      printf("You chose HP LCD Monitor with Rs.28389.Are you sure to buy.If 'Yes' Enter 1 else enter any other number\n");
      scanf("%d",&num);
      if(num==1)
      {
       push(&top,0,product,28389);
       totalCost+=28389;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     case 2:
     {
      int num;
      char product[50]="Logitec Mouse";
      printf("You chose Logitech Mouse with Rs.500.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,1,product,500);
       totalCost+=500;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     case 3:
     {
      int num;
      char product[50]="Sandisk 16GB Pendrive";
      printf("You chose Sandisk 16GB Pendrive with Rs.550.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,2,product,550);
       totalCost+=550;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     default:{
      printf("Exit from Computer Accessories\n");
      break;
     }
    }
    break;
   }
   case 2:   //cloths
   {
    int clothsChoice;
    char product[50]="Lee";
    printf("Enter\n1 - Lee - Rs.1250\n2 - clothVilla - Rs.5000\n3 - Manyavar - Rs.2800\nAny other number to exit\n");
    scanf("%d",&clothsChoice);
    cost[3]=1250;
    cost[4]=5000;
    cost[5]=2800;
    switch(clothsChoice)
    {
     case 1:
     {
      int num;
      char product[50]="Lee";
      printf("You chose Lee for Rs.1250.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,3,product,1250);
       totalCost+=1250;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     case 2:
     {
      int num;
      char product[50]="clothVilla";
      printf("You chose clothVilla for Rs.5000.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,4,product,5000);
       totalCost+=5000;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     case 3:
     {
      int num;
      char product[50]="Manyavar";
      printf("You chose Manyavar for Rs.2800.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,5,product,2800);
       totalCost+=2800;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     default:{
      printf("Exit from Cloths Category\n");
      break;
     }
    }
    break;
   }
   case 3:  //mobile
   {
    int mobileChoice;
    printf("Enter\n1 - iPhone XS - Rs.99000\n2 - Pixel 3 - Rs.71000\n3 - Samsung Galaxy - Rs.67000\nAny other number to exit\n");
    scanf("%d",&mobileChoice);
    cost[6]=99000;
    cost[7]=71000;
    cost[8]=67000;
    switch(mobileChoice)
    {
     case 1:
     {
      int num;
      char product[50]="iPhone XS";
      printf("You chose to buy iPhone XS for Rs.999000.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,6,product,99000);
       totalCost+=99000;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     case 2:
     {
      int num;
      char product[50]="PIXEL 3";
      printf("You chose to buy Pixel 3 for Rs.71000.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,7,product,71000);
       totalCost+=71000;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     case 3:
     {
      int num;
      char product[50]="Samsung Galaxy";
      printf("You chose to buy Samsung Galaxy for Rs.67000.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
          push(&top,8,product,67000);
       totalCost+=67000;
      }
      printf("Your Cost in Cart is %d\n",totalCost);
      break;
     }
     default:{
      printf("Exit from Mobile Category\n");
      break;
     }
    }
    break;
   }
   default:
   {
    printf("Enter Valid Categories Choice\n");
    break;
   }
  }
//displaying
  printf("\t\n\n***%s's cart***\n\n\n",str);
  printf("\tId\t Items\t\t\tCost\n");
  printf("------------------------------------------------------");
  //displaying
  if(count(top)>6){
       printf("\nYou can add only 5 products.\n");
    }
  else if(count(top)==6){
    poplast(&top);
  display(top);
   printf("\nLast added item removed.(Five products only)");
  printf("\n\nTotal Cost:\t%d",totalCost);
  printf("\n");
  }else{
  display(top);
  printf("\n\nTotal Cost:\t%d",totalCost);
  printf("\n");
  }
  if(count(top)<5)
 printf("Total no. of item:%d.\n\n\n",count(top));
 else
     printf("\nYou can add only 5 products into cart.\n\n\n");
 }
// c=2 -> delete products
  if(c==2)
  {
   int id;
   printf("Enter id to delete item\n");
   scanf("%d",&id);
   if(id<9&&id>=0){
   totalCost=totalCost-cost[id];
    pop(&top,id);
    printf("\nProduct Removed.\n");
   }
   else{
    printf("Enter Valid id\n");
   }
     printf("\t\n\n***%s's cart***\n\n\n",str);
       printf("\tRevised Items \n");
   printf("\tId\t Items\t\t\tCost\n");
  printf("------------------------------------------------------");
  //displaying
if(count(top)>6){
       printf("\nYou can add only 5 products.\n");
    }
  else if(count(top)==6){
  poplast(&top);
  display(top);
  printf("\nLast added item removed.(Five products only)");
  printf("\n\nTotal Cost:\t%d",totalCost);
  printf("\n");
  }else{
  display(top);
  printf("\n\nTotal Cost:\t%d",totalCost);
  printf("\n");
  }
 if(count(top)<5)
     printf("Total no. of item:%d.\n\n\n",count(top));
  else
     printf("\nYou can add only 5 products into cart.\n\n\n");  }
  printf("If you wish to buy anything more Enter\n1 to Add Item\n2 to Delete Items\nAny other number to Exit\n");
  scanf("%d",&c);
 }
  while(c==1 || c==2 );
 printf("Your Final Cost is %d\n",totalCost);
 printf("Thanks %s for Choosing Us and Visit us again.\n",str);
 }
