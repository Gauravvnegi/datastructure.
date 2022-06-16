#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct re
{
    char pass[50];
    char username[50];
    char q1[30];
    char q2[30];
}data;
struct infoo 
{
    int dataa ;
    struct infoo *link;
}*headd;
struct info
{
    int  data;
    struct info *link;
}*head , *tail;
struct inf
{
    int data_;
    struct inf *pre;
    struct inf *next;
}*start;
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int isFileExists(const char *path);
void updateCredential(void);
void creat(int );
void logout();
void display();
void begg(int);
void  serch(int );
void end(int);
void middle(int , int );
void del(int );
void rev();
void sort();
void creatt(int );
void displayy();
void beggg(int);
int serchh(int );
void endd(int);
void middlee(int , int );
void dell(int );
void revv();
void sortt();
void creat_(int );
void display_();
void begg_(int);
void  serch_(int );
void end_(int);
void middle_(int , int );
void del_(int );
void rev_();
void sort_();
void menu();
void init();
void login();
void quiz();
void sample();
void mainn();
int main()
{
    system("cls");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                WELCOME TO ALL IN ONE              ############");  
    printf("\n\t\t\t############                      PROGRAM                      ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t-------------------------------------------------------------------------\n");
    printf("\n\t\t\t-----------------------------by GAURAV NEGI--------------------------------");
    printf("\n\t\t\t---------------------------------------------------------------------------");
    
    init();
    login();
    return 0;    
}  
void creat(int n)
{
    struct infoo *temp,*newnode,*tempp;
    int i ,data;
    tempp=(struct infoo*)malloc(sizeof(struct infoo));
    if(headd==NULL)
    {
        printf("Enter the data 1 : ");
        scanf("%d" ,&data);
        tempp->dataa=data;
        tempp->link=NULL;
        headd=tempp;
       
    }
   
     temp=headd;
   
    for(i=2;i<=n;i++)
    {
        printf("Enter the %d : " ,i);
        
        scanf("%d" ,&data);
        newnode=(struct infoo*)malloc(sizeof(struct infoo));
        if(newnode==NULL)
        {
            printf("UNABLE\n");
            exit(0);
       
        }
        newnode->dataa=data;
        newnode->link=NULL;
        temp->link=newnode;
        temp=temp->link;
    }
    
}
void display()
{
    struct infoo *temp;
    if(headd==NULL)
    {
        printf("list is empty\n");
    }
    temp=headd;
    while(temp!=NULL)
    {
        printf("%d ", temp->dataa);
        temp=temp->link;
    }
}
void begg(int data)
{
    struct infoo *temp;
    temp=(struct infoo*)malloc(sizeof(struct infoo));
    temp->dataa=data;
    temp->link=headd;
    headd=temp;
}
void serch(int data)
{
    int pos=0,i;
    struct infoo *temp=headd;
    while(temp != NULL)
    {
        pos++;
        if(temp->dataa ==data)
        {
            printf("the data %d  is found at %d \n", data ,pos);
            return ;
        }
        temp=temp->link;
    }
    if(temp==NULL)
    {
        printf("not found \n");
        return ;
    }
  
    
}
void end(int data)
{
    struct infoo *temp ,*q;
    temp=(struct infoo*)malloc(sizeof(struct infoo));
    temp->dataa=data;
    temp->link=NULL;
    if(headd==NULL)
    {
        headd=temp;
        return ;
    }
    q=headd;
    while(q->link!=NULL)
    {
        q=q->link;
    }
    q->link=temp;
}
void middle(int data, int pos){
   struct infoo *temp ,*q1,*q2;
   int i=1;
    temp=(struct infoo*)malloc(sizeof(struct infoo));
    temp->dataa=data;
    temp->link=NULL;
    if(pos==1)
    {
        begg(data);
    }
    else{
    q1=headd;
    q2=q1->link;
    while(i<pos-1)
    {
        q1=q2;
        q2=q2->link;
    }
    temp->link=q2;
    q1->link=temp;
   
    
    
    }
    
}
void del(int data)
{
   struct infoo *temp,*q;
   if(headd==NULL)
   {
       printf("list is empty\n");
       return ;
   }
   if(headd->dataa==data)
   {
       temp=headd;
       headd=temp->link;
       free(temp);
       return;
   }
   q=headd;
   while(q->link->link !=NULL)
   {
       if(q->link->dataa==data)
       {
           temp=q->link;
           q->link=temp->link;
           free(temp);
           return ;
       }
       q=q->link;
   }
   if(q->link->dataa==data)
   {
       temp=q->link;
       q->link=NULL;
       free(temp);
       return ;
   }
   
}
void rev()
{
    struct infoo *q1,*q2,*q3;
    q1=headd;
    q2=q1->link;
    q3=q2->link;
    q2->link=q1;
    q1->link=NULL;
    while(q3!=NULL)
    {
        q1=q2;
        q2=q3;
        q3=q3->link;
        q2->link=q1;
    }
    
    headd=q2;
}
void sort()
{
    struct infoo* temp=headd,*i,*j,*n;
    while(temp!=NULL)
    {
        i=temp->link;
        while(i!=NULL)
        {
            if(temp->dataa > i->dataa){
            int s=temp->dataa;
            temp->dataa=i->dataa;
            i->dataa=s;
            } i=i->link;
        }
        temp=temp->link;
       
    }
    
    temp=headd;
    while(temp!=NULL)
    {
        printf("%d ",temp->dataa);
        temp=temp->link;
    }
}    
void creatt(int data)
{
    struct info *temp,*newnode;
    int i;
   
    if(head==NULL)
    {
      temp=(struct info *)malloc(sizeof(struct info));
    temp->data=data;
    temp->link=NULL;
       
        head=temp;
        tail=temp;
        temp->link=head;
    }
     else
     {
          temp=(struct info *)malloc(sizeof(struct info));
           temp->data=data;
          temp->link=NULL;
          temp->link=tail->link;
            tail->link=temp;
            tail=temp;
     } 
           
}
void displayy()
{
    struct info *temp;
     temp=head;
    if(head==NULL)
    {
        printf("Empty list\n");
        return ;
    }
   
    else
    {
        do
        {
            printf(" %d " , temp->data);
            temp=temp->link;
        } while(temp!=head);
        
    }
}
int serchh(int data)
{
    struct info *temp;
    int pos=0;
    temp=head;
    if(head==NULL)
    {
        printf("list is empty\n");
        exit(0);
    }
    temp=tail->link;
     
        do
        {
            pos++;
            if(temp->data==data){
            printf("%d is found at %d pos" ,data,pos);
            return pos;
            }
            temp=temp->link;
        }while(temp!=head);
    

}
void beggg(int data)
{
    struct info *temp,*q1;
    temp=(struct info *)malloc(sizeof(struct info));
    if(head==NULL)
     {
         temp->data=data;
         temp->link=head;
         head=temp;
         tail=temp;
     }
     temp->data=data;
     temp->link=head;
     q1=head;
     while(q1->link!=head)
     {
         q1=q1->link;
     }
     
    head=temp;
    q1->link=temp;
    
}
void endd(int data)
{
    struct info*temp;
    temp=(struct info *)malloc(sizeof(struct info));
   temp->data=data;
    if(head==NULL)
    {
        beggg(data);
    }
    else{
   
        tail->link=temp;
        temp->link=head;
        tail=temp;
    }
}
void middlee(int data, int pos)
{
    struct info *temp, *q1,*q2,*p;
    int i;
    temp=(struct info *)malloc(sizeof(struct info ));

    if(pos==1 || head==NULL)
    {
        beggg(data);
    }
    else{
    p=tail->link;
    
    for(i=1 ;i<pos-1;i++)
    {
        p=p->link;
        if(p==tail->link)
        {
            printf("hjgsdg %d" ,pos);
            return ;
        }
    }
    temp->data=data;
    temp->link=p->link;
    
    p->link=temp;
    if(p==tail)
    {
        tail=temp;
    }
    }
}
void dell(int data)
{
    struct info *p,*q,*temp;
    if(head==NULL)
    {
        printf("list is empty\n");
        return ;
    }
    if(head->link==head && head->data==data)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    p=tail->link;
    while(p->data==data)
    {
        temp=p;
        tail->link=temp->link;
        head=tail->link;
        free(temp);
        return ;
    }
    while(p->link !=tail)
    {
        if(p->link->data==data){
        temp=p->link;
        p->link=temp->link;
        free(temp);
         }
      p=p->link;
    }
    if(p->link->data==data)
    {
        temp=p->link;
        p->link=temp->link;
        tail=p;
        free(temp);
        return ;
    }
}
void revv()
{
    struct info *q1,*q2,*q3;
    q1=head;
    q2=q1->link;
    q3=q2->link;
    while(q2!=head)
    {
        q2->link=q1;
        q1=q2;
        q2=q3;
        q3=q3->link;
    }
    head=q1;
    q2->link=head;
    tail=q2;
}
void sortt()
{
    struct info* temp=head,*i,*j,*n;
    do
    {
        i=temp->link;
        do
        {
            if(temp->data > i->data)
            {
               int s=temp->data;
               temp->data=i->data;
               i->data=s;
            }
            i=i->link;
        }while(i!=head);
        temp=temp->link;
    }while(temp!=head);

}
void creat_(int n)
{
    struct inf *temp,*q,*t;
    int i,data;
   
    if(start==NULL)
    { 
        temp=(struct inf *)malloc(sizeof(struct inf));
        printf("Enter the data 1 : ");
        scanf("%d" ,&data);
        temp->data_=data;
        temp->next=NULL;
        temp->pre=NULL;
        start=temp;
    }
    q=start;
      for(i=2;i<=n;i++)
      {
         t=(struct inf *)malloc(sizeof(struct inf));
         printf("Enter the data %d : ",i);
        scanf("%d" ,&data);    
       t->data_=data;
       t->next=NULL;
       q->next=t;
       t->pre=q;
       q=q->next;
       
      }
      

}
void display_()
{
    struct inf *temp=start;
    if(temp==NULL)
    {
        printf("sorry\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d " ,temp->data_);
            temp=temp->next;
        }
    }
}

void begg_(int data)
{
   struct inf *temp ,*q;
    temp=(struct inf*)malloc(sizeof(struct inf));
    temp->data_=data;
    temp->next=NULL;
    if(start==NULL)
    {
        temp->data_=data;
        temp->next=NULL;
        temp->pre=NULL;
        start=temp;
    }
    else
    {
        temp->data_=data;
        temp->pre=NULL;
        start->pre=temp;
        temp->next=start;

        start=temp;
    }
}
void serch_(int data)
{
  
  struct inf *temp ,*q;
  int pos=0;
  if(start==NULL)
  {
      printf("Sorry");
      return ;
  }
  q=start;
  while(q!=NULL)
  {
       pos++;
       if(q->data_==data)
       {
           printf("%d is found at %d pos\n",data,pos);
      
       }
       q=q->next;
  }
  if(q==NULL)
  {
      printf("%d is not found ",data);
      return ;
  }
    
}
void end_(int data)
{
    struct inf *temp ,*q=start;
    temp=(struct inf*)malloc(sizeof(struct inf));
    if(start==NULL)
    {
        temp->data_=data;
        temp->next=NULL;
        temp->pre=NULL;
        start=temp;
    }
    else
    {
        while(q->next!=NULL)
        {
            q=q->next;
        }
        temp->data_=data;
        temp->next=NULL;
        q->next=temp;
        temp->pre=q;
    }    
   
}
void middle_(int data, int pos){
   struct inf *temp ,*q=start,*q2;
   int i=1;
   temp=(struct inf*)malloc(sizeof(struct inf));
     if(start==NULL  || pos==1)
    {
       begg(data);
    }
    else
    {
          while(i<pos-1)
          {
              q=q->next;
              i++;
          }
          temp->data_=data;
          temp->next=q->next;
          q->next->pre=temp;
          q->next=temp;
          temp->pre=q;
    }
    
}
void del_(int data)
{
   struct inf *temp ,*q=start,*q2;
   if(start->data_==data)
   {
         temp=start;
         start=start->next;
         free(temp);
   }
   q=start;
   while(q->next->next !=NULL)
   {
       if(q->next->data_==data)
       {
            temp=q->next;
            q->next=temp->next;
            temp->next->pre=q;
            free(temp);
       }
       q=q->next;
   }
   if(q->next->data_==data)
   {
       temp=q->next;
       q->next=temp->next;
       free(temp);
   }
}
void rev_()
{
     struct inf *q1,*q2,*q3;
    q1=start;
    q2=q1->next;
    q3=q2->next;
    q2->next=q1;
    q1->next=NULL;
    while(q3!=NULL)
    {
        q1=q2;
        q2=q3;
        q3=q3->next;
         q2->next=q1;
    }
   
    start=q2;
}
void sort_()
{
   struct inf* temp=start,*i,*j,*n;
    while(temp!=NULL)
    {
        i=temp->next;
        while(i!=NULL)
        {
            if(temp->data_ > i->data_){
            int s=temp->data_;
            temp->data_=i->data_;
            i->data_=s;
            } i=i->next;
        }
        temp=temp->next;
       
    }
}    
void menu()
{
    int i , j , n , data,dataa,ch,choice,c,pos,a,b,option;
    int total;
    float totall;
    do
    { 
        printf("\n1.single linked list\n2.circular\n3.doubly\n4.Quiz\n5.change password\n6.calulator\n7.loggout\n8.exit\n");
        scanf("%d" ,&c);
        switch(c)
        {
       
            case 1:
            {
            do{
                printf("\n1.CRET\n2.transverse\n3.serch\n4.begg\n5.end\n6.del\n7.rev\n8.middle\\n9.sort\n");
                scanf("%d" ,&ch);
                switch(ch)
                {
                    case 1:
                        printf("Enter the number of item\n");
                        scanf("%d" ,&n);
                        creat(n);
                        break;
                    case 2:
                        printf("The list is \n");
                        display();
                        break; 
                    case 3:
                        printf("Enter the number to be serched\n");
                        scanf("%d" ,&dataa);
                        serch(dataa);  
                        break;
                    case 4:
                        printf("Enter the element in begg\n");
                        scanf("%d" ,&dataa);
                        begg(dataa);
                        break;
                    case 5:
                        printf("Dta in last\n");
                        scanf("%d" ,&dataa);
                        end(dataa);
                        break;
                    case 6:
                        printf("Enter trhe data tonbe delete\n");
                        scanf("%d" ,&dataa);
                        del(data);
                        break;  
                    case 7:
                        rev();
                        break;    
                    case 8:
                        printf("E item and pos n : ");
                        scanf("%d%d" ,&dataa,&pos);
                        middle(dataa,pos);
                        break;    
                    case 9:
                        sort();
                        break;              
                }
                printf("\nwant to conitue singly linked list\n");
                choice=getch();
            }while(choice=='y'|| choice=='Y');
            break;
            } 
           
            case 2:
            {
            do{ 
                printf("\n1.CRET\n2.transverse\n3.serch\n4.begg\n5.end\n6.del\n7.rev\n8.middle\n9.sort\n");
                scanf("%d" ,&ch);
                switch(ch)
                {
                    
                    case 1:
                           printf("Enter the number of item\n");
                           scanf("%d" ,&n);
                           for(i=0;i<n;i++)
                            {
                               printf("ENter the data %d : ",i+1);
                               scanf("%d" ,&data);
                               creatt(data);
                            }
                            break;
                    case 2:
                            printf("The list is \n");
                            displayy();
                             break;
                    case 3:
                            printf("Enter the number to be serched\n");
                            scanf("%d" ,&data);
                            serchh(data);
                            break;
                    case 4:
                            printf("Enter the element in begg\n");
                            scanf("%d" ,&data);
                            beggg(data);
                            break;
                    case 5:
                           printf("Dta in last\n");
                           scanf("%d" ,&data);
                           endd(data);
                           break;
                    case 6:
                           printf("Enter trhe data to be delete\n");
                           scanf("%d" ,&data);
                           dell(data);
                           break;
                    case 7:
                           revv();
                           break;
                    case 8:
                           printf("E item and pos n : ");
                           scanf("%d%d" ,&data,&pos);
                           middlee(data,pos);
                           break;
                    case 9:
                           sortt();
                           break;
                }
             printf("want to conitue to circular\n");
             choice=getch();
            }while(choice=='y'|| choice=='Y');
            }
            case 3:
            {
            do
            {
                printf("\n1.CRET\n2.transverse\n3.serch\n4.begg\n5.end\n6.del\n7.rev\n8.middle\n9.sort\n");
                scanf("%d" ,&ch);
                switch (ch)
                {
                     case 1:
                     printf("Enter the number of item\n");
                        scanf("%d" ,&n);
          
                       creat_(n);
            
                      break;
            case 2:
            printf("The list is \n");
            display_();
            break;
            case 3:
            printf("Enter the number to be serched\n");
            scanf("%d" ,&data);
            serch_(data);
            break;
            case 4:
            printf("Enter the element in begg\n");
            scanf("%d" ,&data);
            begg_(data);
            break;
            case 5:
            printf("Dta in last\n");
            scanf("%d" ,&data);
            end_(data);
            break;
            case 6:
            printf("Enter trhe data tonbe delete\n");
            scanf("%d" ,&data);
            del_(data);
            break;
            case 7:
            rev_();
            break;
            case 8:
            printf("E item and pos n : ");
            scanf("%d%d" ,&data,&pos);
            middle_(data,pos);
            break;
            case 9:
            sort_();
            break;
        }
         printf("\nWant to continu doubly\n");
         choice=getch();
        }while (choice=='y' || choice=='Y');
        break;
        }
        case 4:
             quiz();
             menu();
             break;
        case 5:
            printf("Want to change password\n");
            updateCredential();
            break;
        case 6:
            do
            {
            system("cls");
            printf("1.addition\n2.subtraction\n3.multiplication\n4.divide\n");
            printf("Enter the option ....\n");
            scanf("%d" ,&ch);
            switch(ch)
            {
                case 1: 
                printf("Enter First number : ");
                scanf("%d" ,&a);
                printf("Enter second number : ");
                scanf("%d" ,&b);
                printf("%d + %d = %d " ,a,b,a+b);
                break;
                case 2:
                printf("Enter First number : ");
                scanf("%d" ,&a);
                printf("Enter second number : ");
                scanf("%d" ,&b);
                printf("%d - %d = %d " ,a,b,a-b);
                break;
                case 3 : 
                printf("Enter First number : ");
                scanf("%d" ,&a);
                printf("Enter second number : ");
                scanf("%d" ,&b);
                printf("%d * %d = %d " ,a,b,a*b);
                break;
                case 4:
                printf("Enter First number : ");
                scanf("%d" ,&a);
                printf("Enter second number : ");
                scanf("%d" ,&b);
                printf("%d % %d = %d " ,a,b,a%b);
                break;
            }
            printf("\nyou want to continue(y/n):");
            option=getch();
            }while(option=='y' || option=='Y'); 
            
            break;
      
        case 8:             
            {
                exit(0);
                break;
            }  
        
        case 7:
        logout();
        login();
        break;  
        }
        
        printf("You want continue..\n");
        choice=getch();
    }while(choice=='y'|| choice=='Y');
    if(choice=='n'||choice=='N')
    {
        printf("THankyou\n");
    } 
}
void init()
{
    FILE *fp = NULL;
    int s = 0;
    const char defaultUsername[] ="abcd\n";
    const char defaultPassword[] ="abcd\n";
    const char q1[]="gaurav\n";
    const char q2[]="tiger\n";
    s=isFileExists("6.txt");
    if(!s){
     //create the binary file
        fp = fopen("6.txt","wb");
        if(fp != NULL)
        {
            //Copy default password
            strncpy(data.pass,defaultPassword,sizeof(defaultPassword));
            strncpy(data.username,defaultUsername,sizeof(defaultUsername));
            strncpy(data.q1,q1,sizeof(q1));
            strncpy(data.q2,q2,sizeof(q1));
            fwrite(&data,sizeof(data), 1, fp);
            fclose(fp);
        }
    }
}
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
void login()
{
    unsigned char userName[20] ;
    unsigned char password[20] ;
    unsigned char q1[100];
    unsigned char q2[100];
    int L=0,i;
    char ch;
  
    FILE *fp = NULL;
    
    fp = fopen("6.txt","rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&data,sizeof(data), 1, fp);
    fclose(fp);
    do
    {
        
        
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,20,stdin);
        printf("\n\t\t\t\tPassword:");
        for (i = 0; i < 50; i++)
	    {
		ch = getch();
		if (ch != 13) 
		{
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	    }
        if((strcmp(userName,data.username)==0))
        {
        printf("\nFetching account details.....\n");
	        for (i = 0; i < 2000000; i++)
        {
		i++;
		i--;
	}
  
	gotoxy(20, 20);
    for (i = 0; i < 70; i++) {
	for (int j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}
    gotoxy(30, 40);
	printf("\nLOGIN SUCCESSFUL....\n");
    gotoxy(30, 30);
	printf("\nPress enter to continue");
    
	getch();
            system("cls");
            printf("\n\t\t\t###########################################################################");
            printf("\n\t\t\t############                     WELCOME                       ############");
            printf("\n\t\t\t############                       TO                          ############");  
            printf("\n\t\t\t############                    HOME PAGE                      ############");
            printf("\n\t\t\t###########################################################################");
            menu();
            exit(0);
        }
        else 
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }while(L<=3);
    if(L>=4)
    {
        system("cls");
        gotoxy(25, 7);
        printf("****Give the answer of this question****\n");
        gotoxy(25, 9);
        printf("1.WHo is your best freind\n ");
        gotoxy(25, 11);
        fgets(q1,100,stdin);
        gotoxy(25, 13);
        printf("2.Favroite animal\n");
        gotoxy(25, 15);
        fgets(q2,100,stdin);
        if((strcmp(q1,data.q1)==0) &&(strcmp(q2,data.q2)==0))
        {
            updateCredential();
        } 
        else
        {
        printf("\t\t\t\t\nSorry,Unknown User.................");
        getch();
        system("cls");
        }
    }
}
void updateCredential(void)
{
   
    FILE *fp = NULL;
    int i;
    unsigned char userName[20] ;
    unsigned char password[20] ;
    unsigned char q1[10]={0};
    unsigned char q2[10]={0};
    char ch;
    fp = fopen("6.txt","rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&data,sizeof(data), 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    system("cls");
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(userName,20,stdin);
    strncpy(data.username,userName,20);  ///////
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,20,stdin);
    
    strncpy(data.pass,password,20);
    gotoxy(24, 8);
    printf("1.Who is your best freind\n");
    gotoxy(24, 10);
    fgets(q1,100,stdin);
    gotoxy(24, 12);
    printf("Favriote animal\n");
    gotoxy(24, 14);
    fgets(q2,100,stdin);
    strncpy(data.q1,q1,10);
    strncpy(data.q1,q1,10);
    fwrite(&data,sizeof(data), 1, fp);
    fclose(fp);
  for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}
    gotoxy(24,16);
    printf("\n\t\t\t\n-------------------------------------------------------------------------------------------->");
    printf("\n\t\t\t\nYour Password has been changed successfully.....");
    printf("\n\t\t\tLogin Again(y/n) : ");
    fflush(stdin);
    ch=getch();
    if(ch=='y')
    {
       system("cls");
       login();
    }
    else{
        exit(0);
        
    }
}
void logout(void)
{
	int i, j;
    char ch;
	system("cls");
	printf("Please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");
    fflush(stdin);
    getch();
   
}
void quiz()
{
    int i , j,ch;
    char choice;
    printf("1.Want to try Sample quiz\n2.Want to Play main quiz\n");
    scanf("%d" ,&ch);
    do  
    {
         switch(ch)
       {
        case 1:
        system("cls");
        sample();
        break;
        case 2:
        system("cls");
        mainn();
        break;
       }
       printf("\nWant to continue quiz\n");
       choice=getch();
    }while(choice=='y'||choice=='Y');
    if (choice=='Y'==choice=='y')
    {
        quiz();
    }
    else{
        main();
    }
}
void sample()
{
    int j , i,c=0;
    char a,b,cc,d,f,name[10];
    float result;
    printf("Please wait..");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}
    gotoxy(0, 20);
	printf("Press any key to continue..");
    fflush(stdin);
    getch();
    printf("\nENter Your name\n");
    gets(name);
    system("cls");
    gotoxy(30,30);
    printf("\nTHE QUESTION ARE AS FOLLOWS >>>>>>\n");
    for(i=0;i<1;i++)
    {
        system("cls");
        printf("\n1.Why is a macro used in place of a function?\na.It reduces execution time.\nb.It reduces code size.\nc.It increases execution time.\nd.It increases code size.\n");
       
        f=getch();
        fflush(stdin);
        if(f=='b')
        {
            c+=5;
        }
        system("cls");
        printf("\n2.How many times will the following loop execute?\nfor(j = 1; j <= 10; j = j-1)\na.Forever\nb.Never\nc.0\nd.1\n");
       f=getch();
        fflush(stdin);
        if(f=='a')
        {
            c+=5;
        }
        system("cls");
        printf("\n3.Which one of the following is a loop construct that will always be executed once?\na.for\nb.while\nc.switch\nd.do while\n");
        f=getch();
        fflush(stdin);
        if(f=='d')
        {
            c+=5;
        }
        system("cls");
        printf("\n4.Directives are translated by the\na.Pre-processor\nb.Compiler\nc.Linker\nd.Editor\n");
        f=getch();
        fflush(stdin);
        if(f=='a')
        {
            c+=5;
        }
    }
    system("cls");
    printf("Please wait we are calculating your result..");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
    } 
    result=(c/20)*100;
    printf("\n%s your's score is : %.2f\n",name,result);
    if(result>=70 && result<=100)
    {
        printf("\nEXCELLENT\n");
    } 
    else if(result>=50 && result<=69)
    {
        printf("\nGOOD\n");
    } 
    else
    {
        printf("\nPOOR\n");
    }
}
void mainn()
{
      int j , i,c=0;
    char a,b,cc,d,f,name[10],ch;
    float result;
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  WELCOME TO Quiz                  ############");  
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t-------------------------------------------------------------------------\n");
    printf("\n\t\t\t-----------------------------by GAURAV NEGI--------------------------------");
    printf("\n\t\t\t---------------------------------------------------------------------------");
    printf("Please wait..");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}
    gotoxy(0, 20);
	printf("Press any key to continue..");
    fflush(stdin);
    getch();
    printf("\nENter Your name\n");
    gets(name);
    system("cls");
    gotoxy(30,30);
    printf("\nTHE QUESTION ARE AS FOLLOWS >>>>>>\n");
    for(i=0;i<1;i++)
    {
        system("cls");
        printf("\n1.main()\n{\nint x = 5;\nif(x==5)\n{\nif(x==5) break;\nprintf('hello');\n}\nprintf('hi');\n}\na.compiler error\nb.hi\nc.hellohi\nd.hello\n");
        f=getch();
        fflush(stdin);
        if(f=='a')
        {
            c+=5;
        }
        system("cls");
        printf("\n\n2.Linker generates ___ file.\na.Object code\nb.Executable code\nc.Assembly code\nd.None of the above.\n");
       f=getch();
        fflush(stdin);
        if(f=='b')
        {
            c+=5;
        }
        system("cls");
        printf("\n\n3.Similarity between a structure, union and enumeration,\na.All are helpful in defining new variables\nb.All are helpful in defining new data types\nc.All are helpful in defining new pointers\nd.All are helpful in defining new structures\n");
        f=getch();
        fflush(stdin);
        if(f=='b')
        {
            c+=5;
        }
        system("cls");
        printf("\n\n4.Default return type of function defintion\na.void\nb.static\nc.int\nd.float\n");
       f=getch();
        fflush(stdin);
        if(f=='c')
        {
            c+=5;
        }
    }
    system("cls");
    printf("\nPlease wait we are calculating your result..\n");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
    } 
    result=(c/20)*100;
    printf("\n%s your's score is : %.2f\n",name,result);
    if(result>=70 && result<=100)
    {
        printf("\nEXCELLENT\n");
    } 
    else if(result>=50 && result<=69)
    {
        printf("\nGOOD\n");
    } 
    else
    {
        printf("\nPOOR\n");
    }
    printf("\nWant to continue with your menu\n");
    ch=getch();
    if(ch=='Y' ||ch=='y')
    {
        system("cls");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                WELCOME TO ALL IN ONE              ############");  
    printf("\n\t\t\t############                      PROGRAM                      ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t-------------------------------------------------------------------------\n");
    printf("\n\t\t\t-----------------------------by GAURAV NEGI--------------------------------");
    printf("\n\t\t\t---------------------------------------------------------------------------");
    menu();
    }

}
