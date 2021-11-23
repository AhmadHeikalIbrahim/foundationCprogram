//THIS IS ABOUT A CINEMA TICKETING SYSTEM
//WRITTEN BY AHMAD HEIKAL, AINA FARZANA & DAMIA UZMANA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 60

//1. this function is for customer
void customer ();      //function prototype
void C_M_S ();         //function prototype
void M_R ();           //function prototype
void T_B ();           //function prototype
void R_S ();           //function prototype           
void F_B ();           //function prototype


void cust_member();    //function prototype
void ben_member(void); //function prototype
int cust_valid();      //function prototype
void deals();

//2. this function is for staff
void staff();           
void staff_name();
void staff_identification(int,int,int);

//staff update movie
void U_M ();


void out(void);
void us(void);



//global variables 
float RM;
int nama, id, pass;
char cus_name[100], cuspassword[100], cuscon_password[100], cus_email[100], cusphone_num[20];
//global array
char movie_name[5][50]={"To The Girl I Loved Before (I Hate You)","Deadly Illusions","Just Mercy:Alabama","Coco:Aftermath","Free Guy"};
char time1[3][50]={"6PM - 8PM","10PM - 12AM","1AM - 3AM"};
char time2[3][50]={"2.15PM - 4:15PM","5PM - 7PM","9:30PM - 10:30PM"};
char time3[3][50]={"11AM - 1PM","4PM - 6PM","8:15PM - 10:15PM"};
char time4[3][50]={"10:45AM - 12:45PM","3:45PM - 5:45PM","9PM - 11PM"}; 
char time5[3][50]={"12PM - 2PM","3PM - 5PM","9PM - 11PM"};



int main ()
{
    int code,choice;    //variable declaration
    
    do    // usage of do while loop
    {
    system("cls") ;
    printf("\n\t**********************************");                     
    printf("\n\t WELCOME TO CURTAIN CALL CINEPLEX ");
    printf("\n\t**********************************");
    printf("\n\n\tCode\t Description");
    printf("\n\t-------\t -----------");
    printf("\n\t1.\t Customer");
    printf("\n\t-------\t -----------");
    printf("\n\t2.\t Staff");
    printf("\n\t-------\t -----------");
    printf("\n\t3.\t About Us");
    printf("\n\t-------\t -----------");
    printf("\n\t4.\t Exit");
    printf("\n\t-------\t -----------");
    printf("\n\n\tEnter a number according to the menu above : ");
    scanf("%d",&code);
    }while(code<1||code>4);
    
    if (code==1)
		customer();     //function call
	else if (code==2)
		staff();        //function call
	else if (code==3)
        us();	        //functin call
	else if (code==4)
		out();          //function call
		
	return 0;
}

void customer()      //function header
{
	int choice;      //variable declaration
	system("cls");
	printf("\n\t======================================");
	printf("\n\t|| WELCOME TO CURTAIN CALL CINEPLEX ||");
	printf("\n\t======================================");
    printf("\n\n\t<1> Current Movie Showing\n\t<2> Membership Registration\n\t<3> TicketBooking\n\t<4> Food & Beverages\n\t<5> Main Page");
	printf("\n\n\tEnter code : ");
	scanf("%d", &choice);
	
	if (choice==1)           //usage of nested if else
        {
            C_M_S();         //function call
        }
        else if (choice==2)
        {
            M_R();           //function call
        }
        else if(choice==3)
        {
            T_B ();         //function call   
        }
        else if(choice==4)
        {
            F_B ();         //function call
        }
        else
            main();         //function call
}


void C_M_S ()     //function header
{
    char option;
    system("cls");
    printf("\n\t======================================");
    printf("\n\t||  CURTAIN CALL CINEPLEX'S MOVIES  ||");
	printf("\n\t======================================");
	printf("\n\nDO YOU WANT TO SEE ALL NOW SHOWING MOVIES?(Y/N) -->>");
	scanf(" %c", &option);
	
		if(option=='y'||option=='Y')    // usage of if else
		{
		    
			printf("\n\tCATEGORY                   MOVIES ");
			printf("\n\t------------\t----------------------------------------");
			printf("\n\tROMANCE     \t%s",movie_name[0]);
			printf("\n\t------------\t----------------------------------------");
			printf("\n\tTHRILLER    \t%s",movie_name[1]);
			printf("\n\t------------\t----------------------------------------");
			printf("\n\tBIOGRAPHY   \t%s",movie_name[2]);
			printf("\n\t------------\t----------------------------------------");
			printf("\n\tANIMATION   \t%s",movie_name[3]);
			printf("\n\t------------\t----------------------------------------");
			printf("\n\tCOMEDY      \t%s",movie_name[4]);
			printf("\n\t------------\t----------------------------------------");
			printf("\n\nPress Any Key To Go Back To Customers' Site");
		    if(getch())
		    customer();
		}
		
		else
		customer();     //function call	
}

//membership registration for customer
void M_R ()         //function header
{
    int z, gift;    //variable declaration
    char ship;      //variable declaration
    system("cls");
    printf("\n\t========================================");
    printf("\n\t|| CURTAIN CALL CINEPLEX'S MEMBERSHIP ||");
	printf("\n\t========================================");
    printf("\n\n\t<1> Apply Membership");
    printf("\n\n\t<2> Benefits of Membership");
    printf("\n\n\t<3> Back");
    printf("\n\n\tEnter your choice : ");
    scanf("%d",&z);
    
    if (z==1)
		cust_member();    //function call
	else if (z==2)
		ben_member();     //function call
	else 
		customer();       //function call
    
}
 
    
void cust_member()      //function header
{	
    int age;
    
	system("cls");
	printf("\n\t|\t***Sign Up As a New Member***\t|");
	printf("\nPlease enter your age:");
	scanf ("%d", &age);
	
	if(age>=18)     //usage of nested if else
	{
    
	printf("\nEnter your name : ");
	scanf("%s", cus_name);
	printf("Enter email : ");
	scanf("%s", cus_email);
	printf("Enter password (8-12 characters) : ");
	scanf("%s", cuspassword);
	printf("Confirm password : ");
	scanf("%s", cuscon_password);
	printf("Enter phone number : ");
	scanf("%s", cusphone_num);
	
	cust_valid();    //function call
	
	}
    else
	printf("\nThank you !\nMEMBERSHIP IS NOT ALLOWED,CUSTOMER MUST BE 18 YEARS OLD OR OLDER");
}


//this function is to validate customer's details
int cust_valid()    //function header

{
	int i, flag = 1, opt;
	
	//validate the name
	for (i = 0; cus_name[i] != '\0'; i++)   //for loop
	{
	 	if (!((cus_name[i] >= 'a' && cus_name[i] <= 'z') || (cus_name[i] >= 'A' && cus_name[i] <= 'Z'))) 
	 	{
	 	printf("Please enter the valid name, your name MUST NOT have any special characters");	
		flag = 0;
		break;
		}
	}
	
	if (flag == 1)
	{
		int count = 0, success;
		
		//validate email id 
		for (i = 0; cus_email[i] != '\0'; i++) 
		{
			if (cus_email[i] == '@' || cus_email[i] == '.') 
                count++; 
		}
		
		if (count >= 2 && strlen(cus_email) >= 5) 
		{
			//validate password and confirm it
			if (!strcmp(cuspassword, cuscon_password))
			{
				if (strlen(cuspassword) >= 8 && strlen(cuscon_password) <= 12) 
				{
					//validating customers' mobile numbers
					if (strlen(cusphone_num) >=9 && strlen(cusphone_num)<=12) 
					{
						for (i = 0; i < 10; i++)
						{ 
        	     		   	if (cusphone_num[i] >= '0' && cusphone_num[i] <= '9') 
							{ 
                    			success = 1;
                                printf("\nThank you for the registeration as a CNN member ! ");
		                        printf("\nCongratulations! You get a chance to choose your monthly gift! ");
		                        deals();
		                        
		                    
                                break; 
                            } 
                            
							else 
							{ 
                                printf("\n\nPlease Enter Valid Mobile Number\n\n"); 
                                        	
								return 0; 
                                break; 
                        	} 
                        } 
  
                        // Success is assigned with value 1, Once every inputs are correct. 
                        if (success == 1) 
                            return 1; 
					}
				}	
				else
					printf("\nYour password is too short, it must be in length 8 to 12");
			}
			else
				printf("\nPassword doesn't match");
		}
		else
			printf("\nPlease enter a valid e-mail");
			
	}	
}

//for display benefits of membership
void ben_member(void)  //function header
{   
    int opt;
    system("cls");
    printf("\nHere are the privileeges provided for CNN member >> ");
    printf("\n1. You will be provided with regular update movies and promotions.");
    printf("\n2. Every purchase will get a 25 points = RM2");
    printf("\n3. Many gifts and coupons waiting you every month. ");
    printf("\n\nPress Any Key To Go Back.");
	if(getch())
	customer();    
}


//customer's monthly deals 
void deals()
{
	int gift;

    printf ("\n\n\t 10 \t20 \t30\n");
    printf ("\nPlease enter any(one) code above as your gift : ", gift);
    scanf ("%d", &gift);
    
    do //usage of do while loop
    {
        if (gift==10)
        {
        printf ("\nYour chosen gift is code 10.\n");
        printf ("You get one free tickets for adults.\n");
        printf ("The gift are valid until end of this month.\n");
        printf ("You can make a redemption at the counter. \n");
        printf("\n\nPress Any Key To Go Back To Customers' Site");
		if(getch())
		customer();
        break;
        }
        else if (gift==20)
        {
        printf ("\nYour chosen gift is code 20.\n");
        printf ("You get one free small popcorn.\n");
        printf ("Gift is valid until end of this month.\n");
        printf ("You can make a redemption at the counter.\n");
        printf("\n\nPress Any Key To Go Back To Customers' Site");
		if(getch())
		customer();
        break;
        }
        else if (gift==30)
        {
        printf ("\nYour chosen gift is code 30.\n");
        printf ("You get RM3 discount voucher per person.\n");
        printf ("Voucher is valid until end of this month.\n");
        printf ("You can make a redemption at the counter. \n");
        printf("\n\nPress Any Key To Go Back To Customers' Site");
		if(getch())
		customer();
        break;
        }
         else
        {
        printf ("\nInvalid gift code");
        printf ("\nRe-enter a code: ");
        scanf ("%d", &gift);
        }
    
    }while (gift!=10 || gift!=20 || gift!=30);
}

   
 
//customer's ticket booking  
void T_B ()                //function header
{	 
    char choice;           //variable declaration
	int movie, showtime;   //variable declaration
	
    
    system("cls");   //clear screen
    printf("\n\t||===================================||");
    printf("\n\t||  CURTAIN CALL CINEPLEX'S BOOKING  ||");
	printf("\n\t||===================================||");
    printf("\n\n\t\t\tTicket Price\n");
    printf("\t||=============================================||\n");
    printf("\t||        Adult (13/o and above) : RM20        ||\n");
    printf("\t||                Kids :RM15                   ||\n");
    printf("\t||=============================================||\n\n");

   do      //usage of do while loop
   {
   printf("\n\t\t<<<<< MOVIE LIST >>>>>");
   printf("\n\t===================================================");
   printf("\n\t MOVIE 1 : %s", movie_name[0]);
   printf("\n\t MOVIE 2 : %s", movie_name[1]);
   printf("\n\t MOVIE 3 : %s", movie_name[2]);
   printf("\n\t MOVIE 4 : %s", movie_name[3]);
   printf("\n\t MOVIE 5 : %s", movie_name[4]);
   printf("\n\t===================================================");
   printf("\n\n\t Enter Your Movie Code : ");
   scanf("%d", &movie);
   
   if(movie!=1 && movie!=2 && movie!=3 && movie!=4 && movie !=5)
   {
       printf("\n\t--INVALID--\n\tPlease re-enter your choice :");
       scanf("%d", &movie);
   }
   }while (movie!=1 && movie!=2 && movie!=3 && movie!=4 && movie !=5);  //loop will stop if 1,2,3,4 or 5
   
    if(movie==1)   //usage of nested if else 
    {
    printf("\n\t==== HALL 1 ====");
    printf("\n\t--- SHOWTIME ---");
    printf("\n\t [1] %s",time1[0]);
    printf("\n\t [2] %s",time1[1]);
    printf("\n\t [3] %s",time1[2]);
    printf("\n\t Please choose showtime : ");
    scanf("%d", &showtime);
    do
    {
        if(showtime!=1 && showtime!=2 && showtime!=3)
        {
            printf("\n\tPlease re-enter valid code for showtime : ");
            scanf("%d",&showtime);
            
        }
    }while(showtime!=1 && showtime!=2 && showtime!=3);
    R_S(); 
    }
    
    else if(movie==2)
    {
    printf("\n\t==== HALL 2 ====");
    printf("\n\t--- SHOWTIME ---");
    printf("\n\t [1] %s",time2[0]);
    printf("\n\t [2] %s",time2[1]);
    printf("\n\t [3] %s",time2[2]); 
    printf("\n\t Please choose showtime : ");
    scanf("%d", &showtime);
    do
    {
        if(showtime!=1 && showtime!=2 && showtime!=3)
        {
            printf("\n\tPlease re-enter valid code for showtime : ");
            scanf("%d",&showtime);
            
        }
    }while(showtime!=1 && showtime!=2 && showtime!=3);
    R_S();  
    
    }
          
    else if(movie==3)
    {
    printf("\n\t==== HALL 3 ====");
    printf("\n\t--- SHOWTIME ---");
    printf("\n\t [1] %s",time3[0]);
    printf("\n\t [2] %s",time3[1]);
    printf("\n\t [3] %s",time3[2]);
    printf("\n\t Please choose showtime : ");
    scanf("%d", &showtime);
    do
    {
        if(showtime!=1 && showtime!=2 && showtime!=3)
        {
            printf("\n\tPlease re-enter valid code for showtime : ");
            scanf("%d",&showtime);
            
        }
    }while(showtime!=1 && showtime!=2 && showtime!=3);
    R_S(); 
    }
          
    else if(movie==4)
    {
    printf("\n\t==== HALL 4 ====");
    printf("\n\t--- SHOWTIME ---");
    printf("\n\t [1] %s",time4[0]);
    printf("\n\t [2] %s",time4[1]);
    printf("\n\t [3] %s",time4[2]);
    printf("\n\t Please choose showtime : ");
    scanf("%d", &showtime);
    do
    {
        if(showtime!=1 && showtime!=2 && showtime!=3)
        {
            printf("\n\tPlease re-enter valid code for showtime : ");
            scanf("%d",&showtime);
            
        }
    }while(showtime!=1 && showtime!=2 && showtime!=3);
    R_S(); 
    }
      
    else
    {
    printf("\n\t==== HALL 5 ====");
    printf("\n\t--- SHOWTIME ---");
    printf("\n\t [1] %s",time5[0]);
    printf("\n\t [2] %s",time5[1]);
    printf("\n\t [3] %s",time5[2]);
    printf("\n\t Please choose showtime : ");
    scanf("%d", &showtime);
    do
    {
        if(showtime!=1 && showtime!=2 && showtime!=3)
        {
            printf("\n\tPlease re-enter valid code for showtime : ");
            scanf("%d",&showtime);
            
        }
    }while(showtime!=1 && showtime!=2 && showtime!=3);
    R_S(); 
    }  

          //function call
}

//customer's reservation seat 
void R_S()  //function header
{
    int i, A, K, seat_quantity, seat_reserved[60]={0};  //variable declaration
    int seat_num, valid;    //variable declaration
    float totalringgit;     //variable declaration
    
    do        //usage of do while loop
    {
        printf("\n\n");
        printf("\t\t||\t\tSCREEN\t\t||");
        for(i=1; i<=60; i++)    //array application
        {
            if( i==1 )
            printf("\n");

            if(seat_reserved[i]==0)
            printf("%d\t", i);
            else if (seat_reserved[i]==1)
            printf("XX\t");

            if( i%10==0 )
            printf("\n");
        }
        printf("\nEnter seat quantity >> ");
        printf("\nAdult : ");
        scanf("%d",&A);
        printf("\nKids :");
        scanf("%d",&K);

        totalringgit=(A*20)+(K*15);    //calculation for total ticket
        seat_quantity=(A+K);

        for(i=1;i<=seat_quantity;i++)
        {
            printf("\nEnter seat : ");
            scanf("%d",&seat_num);
            seat_reserved[seat_num] = 1;
        }
        printf("\n\n");
        printf("\t\t||\t\tSCREEN\t\t||");
        for(i=1; i<=60; i++)
        {
           if( i==1 )
               printf("\n");

             if(seat_reserved[i]==0)
                printf("%d\t", i);
            else if (seat_reserved[i]==1)
                printf("XX\t");

           if( i%10==0 )
               printf("\n");
        }
        printf("\nTotal Ticket Price is RM%.2f\n",totalringgit);

        printf("\nThank you for buy ticket");
        break;
        valid = 0;
    }while(valid==0);

}


//food and beverages
void F_B () //function header
{

    char decision, z;         //variable declaration
    int set, i;               //variable declaration
    float  totalprice;  //variable declaration
    
    system("cls");
    printf("Do You Want To Add Some Foods (Y/N) : ");
    scanf("%s", &decision);

    if (decision=='Y' || decision=='y')  //usage of if else
    {
       printf("\n\t=============================");
	   printf("\n\t|| CURTAIN CALL CINEPLEX MENU ||");
	   printf("\n\t=============================");
       printf("\nCode\t\t  Combo\t\t\t\t Price");
       printf("\n=========================================================");
       printf("\n A\t|| CreamCheese Pie+Popcorn(L)+Soft Drink||RM17.00 ");
       printf("\n B\t|| Mac & Cheese+Popcorn(L)+Soft Drink  \t||RM20.00 ");
       printf("\n C\t|| Cheese Hotdog+Popcorn(M)+Soft Drink \t||RM15.00");
       printf("\n K\t|| Popcorn(S)+Fruit Snacks+Soft Drink  \t||RM10.00 ");
       printf("\n=========================================================");
       printf("\n\n\tHow many set do you want >> ");
       scanf("%d", &set);
       totalprice=0.0;
     

       for(i=1;i<=set;i++)  //array application
       {
        printf("\n\tEnter code set : ");
        scanf("%s", &z); 
        
        if (z=='A'|| z=='a')  //usage of nested if else
        {RM=17;}
        else if (z=='B' || z=='b')
        {RM=20;}
        else if (z=='C' || z=='c')
        {RM=15;}
        else if (z=='K' || z=='k')
        {RM=10;}
        else
        {RM=0;}
        totalprice+=RM;

        }
        printf("\n\t=================================");
        printf("\n\n\t Your total is : RM%.2f\n", totalprice);
        printf("\n\t=================================");
        printf("\n\nPress Any Key To Go Back.");
     	if(getch())
	    customer();
    }
    else
    customer();    //function call
}



void staff()      //function header
{   
    int u;        //variable declaration
    system("cls");           
    printf("\nHello Beloved Staff");
    
    staff_name ();      //function call
    
       
       printf(" \n\n================================================================================\n");
       printf("\n\n");
       printf("Do you want to make a movie update?\n");
       printf(" ||=============================================||\n");
       printf(" ||             1- YES                          ||\n");
       printf(" ||             2- NO                           ||\n");
       printf(" ||=============================================||\n\n");
       printf("Enter your choice : ");
       scanf("%d",&u);
       
       if (u==1)
       {
        U_M ();  //function call
       }
       else if(u==2)
       {
        out();   //function call 
       }
       
}

void staff_name ()  //function header
{
    
    printf(" \n\n================================================================================\n");
    printf("\n\n");
    printf(" =============================================\n");
    printf(" ||             1- ALIYAH                   ||\n");
    printf(" ||             2- ANAS                     ||\n");
    printf(" ||             3- CHARLIE                  ||\n");
    printf(" ||             4- DANNY                    ||\n");
    printf(" ||             5- KHALISH                  ||\n");
    printf(" ||             6- MUNIR                    ||\n");
    printf(" ||             7- NUSHA                    ||\n");
    printf(" ||             8- QAISAH                   ||\n");
    printf(" ||             9- RYAN                     ||\n");
    printf(" ||             10- ZAMRI                   ||\n");
    printf(" ||=========================================||\n\n");

        do   //usage of do while loop
        {
        printf("Enter a number according to your name: ");
        scanf("%d",&nama);
            if (nama==1)
            {
            printf("\n\n SELAMAT SEJAHTERA ALIYAH\n");
                break;
            }
            else if (nama==2)
            {
            printf("\n\n SELAMAT SEJAHTERA ANAS\n");
                break;
            }
            else if (nama==3)
            {
            printf("\n\n SELAMAT SEJAHTERA CHARLIE\n");
                break;
            }
            else if (nama==4)
            {
            printf("\n\n SELAMAT SEJAHTERA DANNY\n");
                break;
            }
            else if (nama==5)
            {
            printf("\n\n SELAMAT SEJAHTERA KHALISH\n");
                break;
            }
            else if (nama==6)
            {
            printf("\n\n SELAMAT SEJAHTERA MUNIR\n");
                break;
            }
            else if (nama==7)
            {
            printf("\n\n SELAMAT SEJAHTERA NUSHA\n");
                break;
            }
            else if (nama==8)
            {
            printf("\n\n SELAMAT SEJAHTERA QAISAH\n");
                break;
            }
            else if (nama==9)
            {
            printf("\n\n SELAMAT SEJAHTERA RYAN\n");
                break;
            }
            else if (nama==10)
                
            {
            printf("\n\n SELAMAT SEJAHTERA ZAMRI\n");
                break;
            }
            
        }while(nama>=1||nama<=10);
        
    }
        
  void staff_identification (int nama, int x,int j)  //function header
        {
            if(nama==1)
            {
          if (x!=2000||j!=12345)
          {
                  do{
                printf ("\n\t####Invalid Username or Password#####\n\n");
                  printf("\tRe-enter User ID : ");
                  scanf("%d",&x);
                  printf("\n\tRe-enter Password: ");
                  scanf("%d",&j);
              }while (x!=2000||j!=12345);
              printf ("\n\t####Valid Data####\n\n");
          }
              else
              printf ("\n\t####Valid Data####\n\n");
          }
            else if(nama==2)
              {
            if (x!=2001||j!=54321)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2001||j!=54321);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            
            else if(nama==3)
              {
            if (x!=2002||j!=98765)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2002||j!=98765);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            
            else if(nama==4)
              {
            if (x!=2003||j!=87654)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-entter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2003||j!=87654);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            else if(nama==5)
              {
            if (x!=2004||j!=2468)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2004||j!=2468);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            else if(nama==6)
              {
            if (x!=2005||j!=89765)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2005||j!=89765);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            else if(nama==7)
              {
            if (x!=2006||j!=45678)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2006||j!=45678);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            else if(nama==8)
              {
            if (x!=2007||j!=65784)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2007||j!=65784);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            else if(nama==9)
              {
            if (x!=2008||j!=5793)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2008||j!=5793);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
            else if(nama==10)
              {
            if (x!=2009||j!=888888)
            {
                    do{
                    printf ("\n\t####Invalid Username or Password#####\n\n");
                    printf("\tRe-enter User ID : ");
                    scanf("%d",&x);
                    printf("\n\tRe-enter Password: ");
                    scanf("%d",&j);
                }while (x!=2009||j!=888888);
                printf ("\n\t####Valid Data####\n\n");
            }
                else
                printf ("\n\t####Valid Data####\n\n");
            }
        }
        
//for staff update movie       
void U_M()  //function header
{
    int o, f, i=0, dec ;
    
    system("cls");
    printf("\n\t||===================================||");
    printf("\n\t||       UPDATE MOVIES FOR STAFF     ||");
	printf("\n\t||===================================||");
    printf("\n\n\tTHIS MENU REQUIRES YOUR USER ID AND PASSWORD\n");
    printf("\n\tUser ID : ");
    scanf("%d",&id);
    printf("\n\tPassword: ");
    scanf("%d",&pass);
    staff_identification(nama ,id , pass);   //function call 
    
    printf("\n\t===================================================");
    printf("\n\t\t<<<<< MOVIE LIST >>>>>");
    printf("\n\t MOVIE 1 : %s", movie_name[0]);
    printf("\n\t MOVIE 2 : %s", movie_name[1]);
    printf("\n\t MOVIE 3 : %s", movie_name[2]);
    printf("\n\t MOVIE 4 : %s", movie_name[3]);
    printf("\n\t MOVIE 5 : %s", movie_name[4]);
    printf("\n\t===================================================");
    
    printf("\n\tHow many movie want to change? : ");
    scanf("%d",&f);
        do
    {
        if(f!=1 && f!=2 && f!=3 &&f!=4 &&f!=5)
        {
            printf("\n\tInvalid. Please re-enter valid code  : ");
            scanf("%d",&f);
            
        }
    }while(f!=1 && f!=2 && f!=3 &&f!=4 &&f!=5);
    
    do      //usage of do while loop
    {
    getchar();
    printf("\n\tChoose movie to change: ");
    scanf("%d",&o);
    switch (o)     //usage of switch
    {
        case 1 :
            printf("\tMovie Title : ");
            scanf ("%s",&movie_name[0]);
            printf("\n\tMovie Showtime For New Movie ->>");
            printf("\n\t [1] : ");
            scanf (" %s",time1[0]);
            printf("\n\t [2] : ");
            scanf (" %s",time1[1]);
            printf("\n\t [3] : ");
            scanf (" %s",time1[2]);
        break;
        case 2 :
            printf("\tMovie Title: ");
            scanf("%s",&movie_name[1]);
            printf("\n\tMovie Showtime For New Movie ->>");
            printf("\n\t [1] : ");
            scanf (" %s",time2[0]);
            printf("\n\t [2] : ");
            scanf (" %s",time2[1]);
            printf("\n\t [3] : ");
            scanf (" %s",time2[2]);
        break;
        case 3 :
            printf("\tMovie Title: ");
            scanf("%s",&movie_name[2]);
            printf("\n\tMovie Showtime For New Movie ->>");
            printf("\n\t [1] : ");
            scanf (" %s",time3[0]);
            printf("\n\t [2] : ");
            scanf (" %s",time3[1]);
            printf("\n\t [3] : ");
            scanf (" %s",time3[2]);
        break;
        case 4 :
            printf("\tMovie Title: ");
            scanf("%s",&movie_name[3]);
            printf("\n\tMovie Showtime For New Movie ->>");
            printf("\n\t [1] : ");
            scanf (" %s",time4[0]);
            printf("\n\t [2] : ");
            scanf (" %s",time4[1]);
            printf("\n\t [3] : ");
            scanf (" %s",time4[2]);
        break;
        case 5 :
            printf("\tMovie Title: ");
            scanf("%s",&movie_name[4]);
            printf("\n\tMovie Showtime For New Movie ->>");
            printf("\n\t [1] : ");
            scanf (" %s",time5[0]);
            printf("\n\t [2] : ");
            scanf (" %s",time5[1]);
            printf("\n\t [3] : ");
            scanf (" %s",time5[2]);
        break;
        default :
            break;
            
    }
    getchar();
    i++;
    }while (i<f);
    {
    printf("\n\t\t<<<<< MOVIE LIST >>>>>");
    printf("\n\t MOVIE 1 : %s", movie_name[0]);
    printf("\n\t MOVIE 2 : %s", movie_name[1]);
    printf("\n\t MOVIE 3 : %s", movie_name[2]);
    printf("\n\t MOVIE 4 : %s", movie_name[3]);
    printf("\n\t MOVIE 5 : %s", movie_name[4]);
    } 
    printf("\n\nPress Any Key To Go Back.");
    if(getch())
	customer();
    
}
    
//exit 
void out(void)   //function header
{
	
	system("cls");       //clear screen
	printf("\n\t==============================================");
	printf("\n\t  Thank you for visiting Curtain Call Cineplex  ");
	printf("\n\t\t    Please come again later\t     ");
	printf("\n\t==============================================");
}        

//About us
void us(void)    //function header
{
    system("cls");
    printf("\nThis system was made by 3 students : \n\n");
	printf("1. AHMAD HEIKAL BIN IBRAHIM \t\t2020464196\n");
	printf("2. AINA FARZANA BINTI ZULKIFLI \t\t2020846492\n");
	printf("3. DAMIA UZMANA BINTI SAMSUL \t\t2020882868");
	printf("\n\nPress Any Key To Go Back.");
	if(getch())
	main();
}
