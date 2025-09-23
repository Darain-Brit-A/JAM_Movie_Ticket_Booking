// Movie Ticket Booking System: Implement a system to book movie tickets online

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// declaring global variables 
int available_tickets = 100;    
int total_cost;                
char movie_name[50];
char show_time[50];
int tickets_purchased;                    
int movie_choice = 0;

// function prototypes 
void menu();
int booking();
void cancelation();
void view();
int process_payment(int amount);

// function definition for menu
void menu() 
{
    printf("\n****** Welcome to J A M ******\n\n");  // welcoming and displaying menu
   
    printf("1. Book Ticket\n");
    printf("2. Cancel Ticket\n");
    printf("3. View Ticket\n");
    printf("4. Exit\n\n");
}

// func definition for booking 
int booking()
{
    int no_tickets, m_choice, time;  // local variable declaration 
    
    printf("\nSelect the movie you want to watch : \n"); // displaying movie options
    printf("1. Avengers Endgame\n");
    printf("2. Avengers Infinity War\n");
    printf("3. Avengers: Age of Ultron\n");
    printf("4. The Avengers\n");
    printf("5. Thor: Ragnarok\n");
    printf("\nYour choice : ");
    scanf("%d", &m_choice);    // accepting movie choice
    movie_choice = m_choice;  // assigning the global variable with the choice accepted 
    
    switch(m_choice)      // using switch to assign the global variable with corresponding movie name
	{                     
        case 1:
		 strcpy(movie_name, "Avengers Endgame");   // using string manipulation technique
		 break;
        case 2: 
		 strcpy(movie_name, "Avengers Infinity War"); 
		 break;
        case 3: 
		 strcpy(movie_name, "Avengers: Age of Ultron"); 
		 break;
        case 4: 
		 strcpy(movie_name, "The Avengers"); 
		 break;
        case 5:
		 strcpy(movie_name, "Thor: Ragnarok"); 
		 break;
        default: 
		 printf("Invalid choice! Try again.\n");
		 return 0;
    }
    
    printf("\nSeats available: %d\n", available_tickets);
    printf("Enter number of tickets : ");
    scanf("%d", &no_tickets);                               // accepting num of tickets required 
    if (no_tickets > available_tickets || no_tickets <= 0)
    {
        printf("Invalid number of tickets or not enough tickets available.\n");
        return 0;
    }
    tickets_purchased = no_tickets;  // assigning the global variable with the num of tickets 
    available_tickets = available_tickets - no_tickets; // decrementing the num of total tickets available 
    
	printf("\nSelect Show timings : \n");
    printf("1. Monday 9:00 AM\n");
    printf("2. Wednesday 12:00 PM\n");
    printf("3. Sunday 6:00 PM\n");
    printf("\nYour choice : ");      // accepting show time 
    scanf("%d", &time);
    
    switch(time)  // assigning the show time to global variable 
	{
        case 1:
		  strcpy(show_time, "Monday 9:00 AM");
		  break;
        case 2:
		 strcpy(show_time, "Wednesday 12:00 PM"); 
		 break;
        case 3: 
		 strcpy(show_time, "Sunday 6:00 PM");
		  break;
        default:
		 printf("Invalid choice! Try again....\n"); 
		 return 0;
    }
    
    total_cost = no_tickets * 100;
    printf("\nCost of 1 ticket is Rs 100.\n");
    printf("Total cost = Rs %d\n", total_cost); // printing total cost of tickets 
    
    process_payment(total_cost);               // calling the func of payment with value of total cost 
   
    printf("\nYour Booking is confirmed!\n");
}

int process_payment(int amount)
{
    int pay_choice;             
    printf("\nPayment Methods available :\n");  // displaying payment methods 
    printf("1. UPI\n");
    printf("2. Credit/Debit Card\n");
    printf("3. Net Banking\n");
    printf("\nYour choice : ");
    scanf("%d", &pay_choice);
    
    switch (pay_choice) 
	{
        case 1:
		  printf("Payment of Rs %d was successful via UPI.\n", amount);
		  break;
        case 2: 
		 printf("Payment of Rs %d was successful via Credit/Debit Card.\n", amount);
		  break;
        case 3:
		 printf("Payment of Rs %d was successful via Net Banking.\n", amount);
		  break;
        default:
		  printf("Invalid payment method!\n");
		  return 0;
    }
}

void cancelation()   // function for cancelling tickets 
{
      int cancel_choice , cancel_time;
      printf("\nEnter movie to be canceled : \n");
      printf("\n1. Avengers Endgame\n");
      printf("2. Avengers Infinity War\n");
      printf("3. Avengers: Age of Ultron\n");
      printf("4. The Avengers\n");
      printf("5. Thor: Ragnarok\n");
      printf("\nNumber : ");
      scanf("%d", &cancel_choice);
      
      if(cancel_choice == movie_choice) // checking whether both options are matching
      {
      available_tickets = available_tickets + tickets_purchased; // incrementing the cancelled number
      
	  tickets_purchased = 0;                                     // initialising back to zero
      strcpy(movie_name, "");
      strcpy(show_time, "");
      
	  printf("\nBooking Cancelled.\nRefund of Rs %d was successful.\n", total_cost);
      }
      else
        printf("\nNo tickets booked for this movie\n");
      if(movie_choice == 0)
    {
    	printf("\nNo Tickets booked to cancel\n");
	}
}


void view()  // func to view details of booked tickets 
{
    if (tickets_purchased > 0)
	{
        printf("\nDetails of the movie booked : \n");
		printf("\nMovie Name: %s\n", movie_name);
        printf("Movie Timings: %s\n", show_time);
        printf("Number of Tickets: %d\n", tickets_purchased);
    }
	else 
	{
        printf("No tickets booked.\n");
    }
    
}


int main()
{
    int ch;    // variable to accept choice                        
    while(1)   // looping statement - runs until user exits 
	{
        menu();  // after printing menu control comes back to take the choice 
        
        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        switch(ch) 
		{
            case 1:
			  booking();
			  break;
            case 2:
			 cancelation();
			  break;
            case 3:
			  view();
			  break;
            case 4:
			  printf("\nExiting... Thank you!\n");  // exiting statement 
			  return 0;
            default:
			 printf("Invalid Choice! Try again.\n");
        }
    }
}

