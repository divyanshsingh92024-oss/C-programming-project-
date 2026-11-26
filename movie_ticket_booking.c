#include <stdio.h>

struct Ticket
{
    char name[20];
    int choice, seats;
};

int main()
{
    struct Ticket t;
    int price, total;
    int available[3] = {50, 30, 20};
    int *p = available;

    do
    {
        printf("\n\n===== MOVIE TICKET BOOKING =====");
        printf("\n1. Silver   - Rs.80");
        printf("\n2. Gold     - Rs.120");
        printf("\n3. Diamond  - Rs.200");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &t.choice);

        if(t.choice >= 1 && t.choice <= 3)
        {
            printf("Enter your name: ");
            scanf("%19s", t.name);

            printf("Enter number of seats: ");
            scanf("%d", &t.seats);

            if(t.seats <= 0 || t.seats > p[t.choice-1])
            {
                printf("\nSeats not available!");
                continue;
            }

            switch(t.choice)
            {
                case 1: price = 80; break;
                case 2: price = 120; break;
                case 3: price = 200; break;
            }

            total = price * t.seats;
            p[t.choice-1] -= t.seats;

            printf("\n\n===== BOOKING DETAILS =====");
            printf("\nName: %s", t.name);
            printf("\nNumber of Seats: %d", t.seats);
            printf("\nTicket Price: Rs.%d", price);
            printf("\nTotal Amount: Rs.%d", total);
            printf("\nRemaining Seats: %d", p[t.choice-1]);
        }
        else if(t.choice != 4)
        {
            printf("\nInvalid choice!");
        }

    } while(t.choice != 4);

    printf("\nThank you for booking!");

    return 0;
}
