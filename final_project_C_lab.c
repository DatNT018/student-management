#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//function prototype
void add_emply();
void display_emply();
void edit_emply();
void cal_payment();
void del_emply();

typedef struct {
    char name[50];
    char id[10];
    char designation[50];
    char department[50];
    float salary;
}emply;


int main(){
    unsigned option;
    char choice;
    
    printf("\n-----------------------------------------\n");
    printf("Employee Management System\n");
    printf("-------------------------------------------\n");
    printf("Enter Your Choice:\n");
    printf("1. Add employee\n");
    printf("2. Display all employees\n");
    printf("3. Edit employee\n");
    printf("4. Calculate employee payment\n");
    printf("5. Delete employee\n");
    printf("\n0. Exit\n");
    printf("---------------------------------------------\n");

    do{
        printf("Enter your choice: ");
        scanf("%u", &option);
        getchar();
        switch (option){
            case 1:
                do{
                add_emply();
                printf("Press [Y] to enter more: ");
                scanf(" %c", &choice);
                while (getchar() != '\n');
                }while(choice == 'Y' || choice == 'y');
                break;
        
            case 2:
                printf("Here is the list of employees\n");
                display_emply();
                break;
            case 3:
                do {
                    edit_emply();
                    printf("Press [Y] to enter more: ");
                    scanf(" %c", &choice);
                    while (getchar() != '\n');
                } while (choice == 'Y' || choice == 'y');
                break;
            case 4:
                do{
                    cal_payment();
                    printf("Press [Y] to enter more: ");
                    scanf(" %c", &choice);
                    while (getchar() != '\n');
                }while(choice == 'Y'|| choice == 'y');
                break;
            case 5:
                do{
                    del_emply();
                    printf("Press [Y] to enter more: ");
                    scanf(" %c", &choice);
                    while (getchar() != '\n');
                }while(choice == 'Y' || choice == 'y');
                break;
            case 0:
                printf("Exit program ------------\n");
                
                return 0;
            default:
                printf("Invalid!\n");
                return 0;
        }

    }while (choice != 0);
    
    return 0;
}

//function definition
int num_emply = 0;
emply all_emply[50];
int i; //counter

void add_emply(){
    //int emply_exist = 0; 
    emply new_emply;
    printf("Enter the employeee name: ");
    fgets(new_emply.name, sizeof(new_emply.name), stdin);
    new_emply.name[strcspn(new_emply.name, "\n")] = '\0';
    printf("Enter employee ID: ");
    fgets(new_emply.id, sizeof(new_emply.id), stdin);
    new_emply.id[strcspn(new_emply.id, "\n")] = '\0';
    printf("Enter employee designation: ");
    fgets( new_emply.designation, sizeof( new_emply.designation), stdin);           
    new_emply.designation[strcspn(new_emply.designation, "\n")] = '\0';
    printf("Enter employee department: ");
    fgets( new_emply.department,sizeof( new_emply.department), stdin);   
    new_emply.department[strcspn(new_emply.department, "\n")] = '\0';
    printf("Enter employee salary:$ ");
    scanf("%f", &new_emply.salary);
    getchar();
    //while (getchar() != '\n');

    //check exist
    for (i = 0; i < num_emply; i++) {
            if (strcmp(new_emply.id, all_emply[i].id) == 0) {
                printf("THE EMPLOYEE ID ALREADY EXISTS!!! CANNOT ADD\n");
                return;
            }
        }
    all_emply[num_emply] = new_emply;
    num_emply++;

    printf("\nName\t\t\t\t\t\tDesignation\t\tDepartment\n");
    printf("=================================================================================================================\n");
    printf("%s (%s)\t\t\t\t%s\t\t%s\n", new_emply.name, new_emply.id, new_emply.designation, new_emply.department);

}

void display_emply(){
    int i;
    
    printf("Name\t\t\t\t\t\tDesignation\t\tDepartment\n");
    printf("=====================================================================================================\n");
    for (i=0; i < num_emply; i++){
    printf("%s (%s)\t\t\t\t%s\t\t%s\n", all_emply[i].name, all_emply[i].id, all_emply[i].designation, all_emply[i].department);
    }
    //printf("\n");
}
void edit_emply(){
    char emply_id[10];
    int emply_index = -1;
    int i; //counter
    printf("Enter employee ID for editing: ");
    fgets(emply_id,sizeof(emply_id), stdin);
    emply_id[strcspn(emply_id, "\n")] = '\0';

    for (i = 0; i < num_emply ; i++){
        if (strcmp(emply_id, all_emply[i].id) == 0) {
            emply_index = i;
            break;
        } 
    }
    if (emply_index == -1) {
    printf("Employee not found!\n");
    return;
    }

    printf("\nEnter name: ");
    fgets(all_emply[emply_index].name, sizeof(all_emply[emply_index].name), stdin);
    all_emply[emply_index].name[strcspn(all_emply[emply_index].name, "\n")] = '\0';
    
    printf("Enter employee designation: ");
    fgets(all_emply[emply_index].designation, sizeof(all_emply[emply_index].designation), stdin);
    all_emply[emply_index].designation[strcspn(all_emply[emply_index].designation, "\n")] = '\0';
    
    printf("Enter employee department: ");
    fgets(all_emply[emply_index].department, sizeof(all_emply[emply_index].department), stdin);
    all_emply[emply_index].department[strcspn(all_emply[emply_index].department, "\n")] = '\0';
    
    printf("Enter employee salary: ");
    scanf("%f", &all_emply[emply_index].salary);

    while (getchar() != '\n');


    printf("\nName\t\t\t\t\t\tDesignation\t\tDepartment\n");
    printf("================================================================================================================\n");
    printf("%s (%s)\t\t\t\t\t\t%s\t\t%s\n", all_emply[i].name, all_emply[i].id, all_emply[i].designation, all_emply[i].department);
    
    return;
}


void cal_payment(){
    char emply_id[10];
    int emply_index= -1;
    int i = 0;
    unsigned aftaxpay;
    printf("Enter employee ID for payment: ");
    scanf("%s", emply_id);

    for (i = 0; i < num_emply; i++){
        if(strcmp(emply_id, all_emply[i].id) == 0){
            emply_index = i;
            break;
        }
    }
    if (emply_index == -1) {
        printf("Employee not found!\n");
        return;
    }

    
    unsigned wholeyear_sal = all_emply[emply_index].salary *12;
    
    if(wholeyear_sal > 25000){
        aftaxpay = wholeyear_sal - (wholeyear_sal * 0.05);
    } else if (wholeyear_sal > 15000) {
        aftaxpay = wholeyear_sal - (wholeyear_sal * 0.1);
    } else {
        aftaxpay = wholeyear_sal;
    }

    printf("The after-tax payment is: $%u\n", aftaxpay);

}
void del_emply(){
    char emply_id[10];
    int emply_index = -1;
    int i=0;
    printf("Enter employee ID for deleting: ");
    scanf("%s", emply_id);
    emply_id[strcspn(emply_id, "\n")] = '\0';

    for (i = 0; i < num_emply; i++){
        if(strcmp(emply_id, all_emply[i].id) == 0){
            emply_index = i;
            break;
        }

    } 
    if (emply_index == -1) {
        printf("Employee not found!\n");
        return;
    }

    printf("\nEmployee %s - %s already deleted\n", all_emply[emply_index].name, all_emply[emply_index].id);

    for(i = emply_index; i < num_emply - 1; i++){
        all_emply[i] = all_emply[i+1];
    } 
    num_emply--;
    
}

