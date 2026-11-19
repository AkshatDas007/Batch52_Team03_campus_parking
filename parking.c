#include <stdio.h>
#include <string.h>

#define MAX 5

//Structure to store vehicle details
struct Vehicle
{
    char regNo[20];
    int isParked;

};

// Function to display available parking spaces
void displayAvailability(struct Vehicle v[]){
    int count = 0;

    for (int i = 0; i < MAX; i++){
        if(v[i].isParked == 0){
            count++;
        }
    }

    printf("\nAvailable Parking Spaces: %d", count);
    printf("\nOccupied Parking Spaces: %d\n", MAX - count);

}

//Function for vehicle entry
void vehicleEntry(struct Vehicle v[]){
    char number[20];
    int freeSlot = -1;

    printf("\nEnter Vehicle Registration Number: ");
    scanf("%19s", number);

    for(int i = 0; i < MAX; i++){
        if(v[i].isParked == 1 && strcmp(v[i].regNo, number) == 0){
            printf("\nVehicle is already parked!\n");
            return;
        }

        if(v[i].isParked == 0 && freeSlot == -1){
            freeSlot = i;
        }
    }

    if(freeSlot == -1){
        printf("\nParking Area is FULL!\n");
        return;
    }

    strcpy(v[freeSlot].regNo, number);
    v[freeSlot].isParked = 1;

    printf("\nVehicle Entry successful!\n");
    displayAvailability(v);
}

//Function for vehicle exit
void vehicleExit(struct Vehicle v[]){
    char number[20];
    int duration, fee;

    printf("\nEnter Vehicle Registration Number: ");
    scanf("%19s", number);

    for(int i = 0; i < MAX; i++){
        if(v[i].isParked == 1 && strcmp(v[i].regNo, number) == 0){
            printf("Enter Parking Duration(hours): ");
            scanf("%d", &duration);

            if(duration <= 0){
                printf("\nInvalid parking duration!\n");
                return;
            }

            fee = duration * 20;

            printf("\nVehicle Exit Successful!\n");
            printf("Registration Number: %s\n", v[i].regNo);
            printf("Parking Duration: %d hours\n", duration);
            printf("Parking Fee: Rs. %d\n", fee);

            v[i].isParked = 0;
            v[i].regNo[0] = '\0';

            displayAvailability(v);
            return;
        }
    }

    printf("\nVehicle Not Found!\n");
}

//Main function
int main(){
    struct Vehicle v[MAX] = {0};
    int choice;

    do
    {
        printf("\n=== SMART CAMPUS PARKING SYSTEM ===\n");
        printf("1.Vehicle Entry\n");
        printf("2.Vehicle Exit\n");
        printf("3.Display Parking Availability\n");
        printf("4.Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                vehicleEntry(v);
                break;

            case 2:
                vehicleExit(v);
                break;

            case 3:
                displayAvailability(v);
                break;

            case 4:
                printf("\nThank You for using the system!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
            }
        }while(choice != 4);

        return 0;
}
