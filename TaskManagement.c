#include <stdio.h>  //Default library
#include <stdlib.h>	//Dynamic memory allocation
#include <string.h> //String manipulation library
#include "TaskManagement.h" //Function list

int main(){
	system("cls");	//Clear screen
    
    //Variable Declaration
    struct node* head = NULL;
	struct date currentDate;
	struct tree *root = NULL;
	
	//To avoid error handling
	currentDate.month = 1;
	currentDate.day = 1;
	
    int option, inputAmmount, errorMessage, detectDisplayError, detectError, i, j, k;
    
    //Landing page
    display_welcomePage();
    system("color 03");
    
    //Current date input
    printf("Input current date\n\n");
	monthErrorDetection(&currentDate.year, &currentDate.month, &currentDate.day);
    
    system("cls");	
    head = readFile();
	showLinkedList(head);
	
	//Program running loop
    do{
    	//Error detection loop
		do{ 
			detectDisplayError = 0;
			//Error Message
			if(errorMessage == 1){
				printf("Option not availible\n");
			}
			printf("Task Management\nCurrent date : %d/%d/%d\n\n", currentDate.day, currentDate.month, currentDate.year);
			printf("\nChoose option :\n1. Input new task \n2. Mark done task\n3. Remove task\n4. Search task by task name\n5. Search  task by course name\n6. Sort by nearest due date\n7. Sort by course name\n8. Categorize by status\n9. Change Current Date\n10. Binary Tree\n11. End Program\n\nOption : ");
			
			//Error Detection
			do{
				scanf("%d", &option);
				if(option< 1 || option>13){
					printf("Invalid options. Option is not availible. Try again!\n");
				}
			
			}while(option<1||option>13);
			
			switch(option){
				//Input data
				case 1:
					printf("\nInput Data\n");
					head = readFile();
					printf("How many taks do you want to input : ");
					scanf("%d", &inputAmmount);
					
					for(i=0; i<inputAmmount; i++){
				 		InsertNewNode(&head, currentDate); //ngisi status nya disini 
					}
					writefile(head);
					detectError = -999;
					errorMessage = 0;
					break;
				//Mark as Done Assignment
				case 2:
					head = readFile();
					showLinkedList(head);
					printf("\nHow many taks do you want to mark as done : ");
					inputAmmount = inputCheck(head);
					for(i=0;i<inputAmmount;i++){
						markDone(&head);
					}
					showLinkedList(head);
					writefile(head);
					detectError = -999;
					errorMessage = 0;
					break;
				//Remove Data
				case 3: {
					printf("\nHow many taks do you want to remove : ");
					head = readFile();
					inputAmmount = inputCheck(head);
					for(i=0;i<inputAmmount;i++){
						deleteNode(&head);
					}
					writefile(head);
			    	detectError = -999;
			    	errorMessage = 0;
			    	break;}
			    //Search data by task name
				case 4:
					printf("\nSearch by Task Name\n ");
					head = readFile();
					printf("How many taks do you want to search  : ");
					inputAmmount = inputCheck(head);
					showLinkedList(head);
					for(i=0;i<inputAmmount;i++){
						searchByTaskName(&head);
					}		
					
					detectError = -999;
					errorMessage = 0;
					break;
				//Search data by course name
				case 5:
					printf("\nSearch by Course Name\n ");
					head = readFile();
					printf("Number of Task to search: ");
					inputAmmount  = inputCheck(head);
					for(i=0; i<inputAmmount; i++){
						searchByCourseName(&head);
					}	
					
					detectError = -999;
					errorMessage = 0;
					break;
				//Sort by Date
				case 6:
					head = readFile();
					sortByDate(&head);
					writefile(head);
					
					detectError = -999;
					errorMessage = 0;
					break;
				//Sort by course name
				case 7:
					head = readFile();
					alphasort(&head);
					writefile(head);
					
					detectError = -999;
					errorMessage = 0;
					break;
				//Sort by Status
				case 8:
					head = readFile();
					sortByStatus(&head);
					writefile(head);
					
					detectError = -999;
					errorMessage = 0;
					break;
				//Update current date
				case 9:
					currentDateChange(&currentDate);
					
					detectError = -999;
					errorMessage = 0;
					break;
				case 10:
					binaryTree(root);
					
					detectError = -999;
					errorMessage = 0;
					
					break;
				//Error detection
				case 11:
					writefile(head);
					deallocate(&head);
					
					detectError = -999;
				//Default option
				default:
					errorMessage = 1;
					break;
			}	
		}while(detectError != -999);
		
		system("cls");	
		changeStatus(head, currentDate);
		
		//Display data
		showLinkedList(head);
		
		
		//Task counter for each course
		if(head != NULL){
			courseTaskCounter(head);
		}
			
	}while(option != 11);
	
    return 0;
} 




