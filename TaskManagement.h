#include <stdio.h>  //Default library
#include <stdlib.h>	//Dynamic memory allocation
#include <string.h> //String manipulation library

//Struct Declaration
struct date{
	int year;
	int month;
	int day;
};

struct taskData{
	struct date dueDate;
	char taskName[20];
	char course[20];
	int status;
};

struct node{
	struct taskData taskLinkedList;
	struct node* next;
};

struct tree{
	float data;  
	struct tree *left;
	struct tree *right;
};

void display_welcomePage();											//Landing page
int leapYear(int *pointerYearFunction);								//Leap Year Detection
void monthErrorDetection(int *pointerYearFunction, int *pointerMonthFunction, int *pointerDayFunction); //Detecting Year and Month Error
struct taskData inputData();										//Input Data to New Node
void InsertNewNode(struct node** head, struct date currentDate);	//Create New Node to The Linked List
void showNodeData(struct taskData temp);							//Print data in each nodes
void showLinkedList(struct node* node);								//Print list of task
void deleteNode(struct node** head);								//Delete node
int statusCheck(struct taskData head, struct date currentDate);		//Check task status
int assignStatus(struct date currentDate, struct taskData head);	//Decide status for data
void swap(struct taskData* a, struct taskData* b);					//Swap data
void sortByDate(struct node** head);								//Sort data by date
void alphasort(struct node** head); 								//Sort data
void markDone(struct node** head);									//Mark done (status) selected data
void sortByStatus(struct node** head);								//Sort data by status
void searchByTaskName(struct node** head);							//Search data by task name
void searchByCourseName(struct node** head);						//Search data by course name
int inputCheck(struct node* head);									//Error handling check input for input more than linked list has
void currentDateChange(struct date* currentDate); 					//Change current date
void writefile(struct node *head);									//File handling to write 
struct node* readFile();                                           	//File handling to read file
void deallocate(struct node** head);								//File handling to deallocate file
struct tree* newNode(float data);									//Insert data for binary tree
struct tree* insert(struct tree* node, float data); 				//Make new node for binary tree
void inorder(struct tree* root);									//Print binary tree
struct tree* smallest(struct tree* root);							//Find smallest number binary tree
struct tree* deleteNodeTree(struct tree* root, float key); 			//Delete node for binary tree
void searchTree(struct tree** current, float search); 				//Search for binary  tree
void binaryTree(struct tree *root); 								//Binary tree menu

void display_welcomePage(){
	system("color 9f");
	printf("\t\t\t\t\t\tTask Management");
	printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
	printf("\n\n\t\t\t\t\t     *                    *");
	printf("\n\n\t\t\t\t\t     *       Welcome      *");
	printf("\n\n\t\t\t\t\t     *                    *");
	printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");

	printf("\n\n\t\t\t\t\t    Press Enter to Continue");
	getchar();			//Detecting enter input
	system("cls");		//Clear screen
	printf("\n\n\t\t\t\t     Task Management\n");
	printf("\n\t\t\t\tProgram to list our  task\n");
	printf("\n\t\t\t\t Press Enter to Continue");
	getchar();			//Detecting enter input
	system("cls");
}

//Leap Year Detection
int leapYear(int *pointerYearFunction){
	 if(( *pointerYearFunction%400 == 0)|| (( *pointerYearFunction%4 == 0 ) &&( *pointerYearFunction%100 != 0))){  
        return 1;
    } else {  
        return 0;
    }  
}

//Detecting Year and Month Error
void monthErrorDetection(int *pointerYearFunction, int *pointerMonthFunction, int *pointerDayFunction){
	//Year input
	printf("Insert year\t\t: ");
    scanf("%d", pointerYearFunction);
    
    //Error detection
    while(*pointerYearFunction<0){
		printf("\nInvalid input, try again. (Year can not be negative)\n\n");
		printf("Insert year\t\t: ");
  		scanf("%d", pointerYearFunction);
	}
	
	//Detect if month more than 12 or less than 1
	do{
		printf("Insert month (1 - 12)\t: ");
		scanf("%d", pointerMonthFunction);
		
		if(*pointerMonthFunction>12 || *pointerMonthFunction<1){
			printf("\nInvalid input, try again. (Month only from 1 - 12)\n\n");
		}
	}while(*pointerMonthFunction>12 || *pointerMonthFunction<1);
	if( (*pointerMonthFunction==1) ||  (*pointerMonthFunction==3) ||  (*pointerMonthFunction==5) ||  (*pointerMonthFunction==7) ||  (*pointerMonthFunction==8) ||  (*pointerMonthFunction==10) ||  (*pointerMonthFunction==12)){
		printf("Insert date (1 - 31)\t: ");
			do{
				if(*pointerDayFunction>31 || *pointerDayFunction<1){
					printf("\nInvalid input, try again. (On month %d only from 1-31)\n\n", *pointerMonthFunction);
					printf("Insert  date (1 - 31)\t: ");
				}
				scanf("%d", pointerDayFunction);	
			}while(*pointerDayFunction>31 || *pointerDayFunction<1);
	}
	
	//If month = 4, 6, 9, 11
	else if((*pointerMonthFunction == 4) ||  (*pointerMonthFunction == 6) ||  (*pointerMonthFunction==9) || (*pointerMonthFunction==11)){
		printf("Insert  date (1 - 30)\t: ");
			do{
				if(*pointerDayFunction>30 || *pointerDayFunction<1){
					printf("\nInvalid input, try again. (On month %d only from 1-30)\n\n", *pointerMonthFunction);
					printf("Insert  date (1 - 30)\t: ");
				}
				scanf("%d", pointerDayFunction);	
			}while(*pointerDayFunction>30 || *pointerDayFunction<1);
	}
	
	//If month = 2 
	else if(*pointerMonthFunction == 2){
		if(leapYear(pointerYearFunction)==1){
			printf("Insert  date (1 - 29)\t: ");
			do{
				if(*pointerDayFunction > 29 || *pointerDayFunction < 1){
					printf("\nInvalid input, try again. (On month %d only from 1-29)\n\n", *pointerMonthFunction);
					printf("Insert date (1 - 29)\t: ");
				}
				scanf("%d", pointerDayFunction);	
			}while(*pointerDayFunction > 29 || *pointerDayFunction < 1);
		}else{
			printf("Insert  date (1 - 28)\t: ");
			do{
				if(*pointerDayFunction > 28 || *pointerDayFunction < 1){
					printf("\nInvalid input, try again. (On month %d only from 1-28)\n\n", *pointerMonthFunction);
					printf("Insert date (1 - 28)\t: ");
				}
				scanf("%d", pointerDayFunction);	
			}while(*pointerDayFunction > 28 || *pointerDayFunction < 1);
		}
	}	
	else{
		printf("ERROR\n");
	}
}

//Input Data to New Node
struct taskData inputData(){
	struct taskData temp;
	
	int hold;
	printf("Insert Course Name (Max 20 chars)\t: ");
	scanf(" %[^\n]s", &temp.course);
	printf("Insert task Name (Max 20 chars): ");
	scanf(" %[^\n]s", &temp.taskName);
	
	//Avoid error handling
	temp.dueDate.month = 1;
	temp.dueDate.day = 1;
	
	//Due date input
	printf("\nInsert Due Date\n");
	monthErrorDetection(&temp.dueDate.year, &temp.dueDate.month, &temp.dueDate.day);
	
	//Status input
	temp.status = 0;
	
	return temp;
}

//Create New Node to The Linked List
void InsertNewNode(struct node** head, struct date currentDate){ 
	//Insert at the end of linked list
	//Create new node
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	
	//Input data
	newNode->taskLinkedList = inputData();
	newNode->taskLinkedList.status = statusCheck(newNode->taskLinkedList, currentDate);
	newNode->next = NULL;
	
	//if it is an empty list, add the newNode to the head of linked list
	if(*head==NULL){
		(*head) = newNode;
	}  
	//Otherwise, find the last node and add the newNode
	else{
		struct node *current = *head;
		while(current->next != NULL){
			current = current->next;
		}
		
		//Add the newNode at the end of the linked list
		current->next = newNode;
	}
}

void showNodeData(struct taskData temp){
	int courseStringLength = strlen(temp.course);
	int taskNameStringLength = strlen(temp.taskName);
	
	//Print
	printf("|%d\t", temp.dueDate.year);
	printf("|%d\t", temp.dueDate.month);
	printf("|%d\t", temp.dueDate.day);
	printf("|%s\t", temp.course);
	printf("%*s", 20 - courseStringLength , "|");
	printf("%s\t", temp.taskName);
	printf("%*s", 20 - taskNameStringLength, "|");
	switch(temp.status){
		case 0:
			printf("Ongoing\n");
			break;
		case 1:
			printf("Done\n");
			break;
		case 2:
			printf("Overdue\n");
			break;
		default :
			printf("ERROR\n");
			break;
	}	
}

//Print list of task
void showLinkedList(struct node* node){
	//If it is an empty list
	if(node == NULL){
	}
	else{
		int i = 1;
		printf("|No\t|Year\t|Month\t|Date\t|Course Name\t\t  |Task\t\t\t  |Status\n");
		while(node != NULL){
			printf("|%d\t",i);
			showNodeData(node->taskLinkedList);
			//To the next node
			node=node->next;
			i++;
		}
		printf("\n");
	}	
}

//Count how many node in the linked list
int nodeCounter(struct node* head){
	int i=1;
	struct node *temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
		i++;
	}
	
	return i;
}

//Delete node
void deleteNode(struct node** head){
	struct node *previous, *temp = *head;
	char searchCourse[20], searchTaskName[20];
	
	//If it is an empty list
	if(*head==NULL){
		printf("list kosong\n");
	}
	else{
		//Input course name which user want to search
		printf("Insert Course Name do you want to delete : ");
		scanf(" %[^\n]s", &searchCourse);
		//Input task name which user want to search
		printf("Insert Task Name do you want to delete : ");
		scanf(" %[^\n]s", &searchTaskName);
		
		//Data in the head of linked list
		if(strcmp(searchCourse, temp->taskLinkedList.course)==0 && strcmp(searchTaskName, temp->taskLinkedList.taskName)==0){
			*head = temp->next;
			free(temp);
		}
		else{
			while(temp!=NULL && (strcmp(searchCourse, temp->taskLinkedList.course)!= 0 && strcmp(searchTaskName, temp->taskLinkedList.taskName)!=0)){
				previous = temp;
				temp = temp->next;
			}
			if(temp == NULL){
				printf("Data not found.\n");
			}
			else{
				previous->next = temp->next;
				free(temp);
			}
		}
	}
	
}

//Check task status
int statusCheck(struct taskData head, struct date currentDate){
	int status;
	if(head.status==1){
		status=1;
	}
	if(head.status != 1){
		if(currentDate.year < head.dueDate.year){
			status = 0;
		}
		else if(currentDate.year == head.dueDate.year){
			if(currentDate.month < head.dueDate.month){
				status = 0;
			}
			else if(currentDate.month == head.dueDate.month){
				if(currentDate.day <= head.dueDate.day){
					status = 0;
				}
				else{
					status = 2;
				}
			}
			else{
				status = 2;
			}
		}
		else{
			status = 2;
		}
	}
	return status;
}

int assignStatus(struct date currentDate, struct taskData head){
	int status;
	if(head.status != 1){
		if(currentDate.year < head.dueDate.year){
			status = 0;
		}
		else if(currentDate.year == head.dueDate.year){
			if(currentDate.month < head.dueDate.month){
				status = 0;
			}
			else if(currentDate.month == head.dueDate.month){
				if(currentDate.day <= head.dueDate.day){
					status = 0;
				}
				else{
					status = 2;
				}
			}
			else{
				status = 2;
			}
		}
		else{
			status = 2;
		}
	}
	return status;
	
}

//Swap data
void swap(struct taskData* a, struct taskData* b){
	struct taskData temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Sort data by date
void sortByDate(struct node** head){
	struct node *current=*head;
	struct node *temp = NULL;
	
	printf("Sort by due date\n");
	if(*head==NULL){
		printf("Linked List Kosong\n");
	}
	else{
		while(current!=NULL){
			temp=current->next;
			while(temp!=NULL){
				if(current->taskLinkedList.dueDate.year>temp->taskLinkedList.dueDate.year){
					swap(&(current->taskLinkedList),&(temp->taskLinkedList));
				}
				if((current->taskLinkedList.dueDate.year==temp->taskLinkedList.dueDate.year)&&(current->taskLinkedList.dueDate.month>temp->taskLinkedList.dueDate.month)){
					swap(&(current->taskLinkedList),&(temp->taskLinkedList));
				}
				if((current->taskLinkedList.dueDate.year==temp->taskLinkedList.dueDate.year)&&(current->taskLinkedList.dueDate.month==temp->taskLinkedList.dueDate.month)&&(current->taskLinkedList.dueDate.day>temp->taskLinkedList.dueDate.day)){
					swap(&(current->taskLinkedList),&(temp->taskLinkedList));
				}
				temp=temp->next;
			}
			current=current->next;
		}	
	}
}

void alphasort(struct node** head){
	struct node *current=*head;
	struct node *temp=NULL;
	printf("Sort by alphabet\n");
	if(*head==NULL){
		printf("Linked List Kosong\n");
	}
	else{
		while(current!=NULL){
			temp=current->next;
			while(temp!=NULL){
				if(strcmp(current->taskLinkedList.taskName,temp->taskLinkedList.taskName)>0){
					swap(&(current->taskLinkedList),&(temp->taskLinkedList));
				}
				temp=temp->next;
			}
			current=current->next;
		}
	}
}

//Mark done (status) selected data
void markDone(struct node** head){
	char searchCourse[20], searchTaskName[20];
	struct node *temp = *head;
	int i;
	//If it is an empty list
	if(*head==NULL){
		printf("List Kosong\n");
	}
	else{
		//Input course name which user want to search
		printf("Insert Course Name do you want to mark as done : ");
		scanf(" %[^\n]s", &searchCourse);
		//Input task name which user want to search
		printf("Insert Task Name do you want to mark as done : ");
		scanf(" %[^\n]s", &searchTaskName);
	
		while(temp != NULL){
		
			if(strcmp(searchCourse, temp->taskLinkedList.course)==0 && strcmp(searchTaskName, temp->taskLinkedList.taskName)==0){
				temp->taskLinkedList.status = 1;
				break;
			}
			temp = temp->next;
		}
	}
	
}

//Sort data by status
void sortByStatus(struct node** head){
	struct node *current = *head;  
	struct node *temp = NULL;  //Next
	
	//If it is an empty list
	if(*head==NULL){
		printf("Data does not exist.\n");
	}
	else{
		while(current!=NULL){
			temp=current->next;
			while(temp!=NULL){
				if(current->taskLinkedList.status>temp->taskLinkedList.status){
					swap(&(current->taskLinkedList),&(temp->taskLinkedList));
				}
				temp=temp->next;
			}
			current=current->next;
		}
	}
}

//Search data by task name
void searchByTaskName(struct node** head){
int result = 0;
	if(*head==NULL){
		printf("Data does not exist.\n");
	}else{
		char searchTaskName[20];
		printf("Insert task name that you want to search : ");
		scanf(" %[^\n]s", &searchTaskName);
		
		struct node* current = *head;
    	struct node* search = NULL;
    	
    	while(current != NULL){
	        if(strcmp( current->taskLinkedList.taskName, searchTaskName) == 0){
	            struct node *temp = malloc(sizeof(struct  node));
	            strcpy(temp->taskLinkedList.course, current->taskLinkedList.course);
	            strcpy(temp->taskLinkedList.taskName, current->taskLinkedList.taskName);
	             temp->taskLinkedList.dueDate.year = current->taskLinkedList.dueDate.year ;
	            temp->taskLinkedList.dueDate.day = current->taskLinkedList.dueDate.day ;
	            temp->taskLinkedList.dueDate.month = current->taskLinkedList.dueDate.month ;
	            temp->taskLinkedList.status = current->taskLinkedList.status;
	            temp->next = NULL;
	            
	            if(result == 0){
	                search = temp;
	                search->next = NULL;
	            }else{
	                search->next = temp;
	            }
	            result++;
	        }
      
        	current = current->next;
    	}
    	
    	if(search == NULL){
	    	getchar();
	    	printf("Data not found. \n");
	    	printf("Press enter to continue.\n");
	    	getchar();
		}else{
			getchar();
	    	showLinkedList(search);
	    	printf("Press enter to continue.\n");
	    	getchar();
		}
		
    	free(search);
	}	
}

//Search data by course name
void searchByCourseName(struct node** head){
	int result = 0;
	if(*head==NULL){
		printf("Data does not exist.\n");
	}else{
		char searchCourse[20];
		printf("Insert course name that you want to search : ");
		scanf(" %[^\n]s", &searchCourse);
		
		struct node* current = *head;
    	struct node* search = NULL;
    	
    	while(current != NULL){
	        if(strcmp( current->taskLinkedList.course, searchCourse) == 0){
	            struct node *temp = malloc(sizeof(struct  node));
	            strcpy(temp->taskLinkedList.course, current->taskLinkedList.course);
	            strcpy(temp->taskLinkedList.taskName, current->taskLinkedList.taskName);
	            temp->taskLinkedList.dueDate.year = current->taskLinkedList.dueDate.year ;
	            temp->taskLinkedList.dueDate.day = current->taskLinkedList.dueDate.day ;
	            temp->taskLinkedList.dueDate.month = current->taskLinkedList.dueDate.month ;
	            temp->taskLinkedList.status = current->taskLinkedList.status;
	            temp->next = NULL;
	            
	            if(result == 0){
	                search = temp;
	                search->next = NULL;
	            }else{
	                search->next = temp;
	            }
	            result++;
	        }
      
        	current = current->next;
    	}
    	
    	if(search == NULL){
	    	getchar();
	    	printf("Data not found. \n");
	    	printf("Press enter to continue.\n");
	    	getchar();
		}else{
			getchar();
	    	showLinkedList(search);
	    	printf("Press enter to continue.\n");
	    	getchar();
		}
		
    	free(search);
	}
}

//Error handling for input more than linked list has
int inputCheck(struct node* head){  
	int ammount;
	do{
		scanf("%d", &ammount);
		if(ammount < 0 ||ammount > nodeCounter(head)){
			printf("Invalid. Try again.\n");
		}
	}while(ammount <0 || ammount >nodeCounter(head));
	return ammount ;
}

void changeStatus(struct node* head, struct date currentDate){
	struct node *temp = head;
	if(temp == NULL){
		printf("Data does not exist.\n");
	}
	else{
		while(temp != NULL){
			temp->taskLinkedList.status = statusCheck(temp->taskLinkedList, currentDate);
			temp = temp->next;
		}
	}
}

void currentDateChange(struct date* currentDate){
	//Input date
    printf("Insert current date\n\n");
    monthErrorDetection(&currentDate->year, &currentDate->month, &currentDate->day);
}

void courseTaskCounter(struct node* head){
	int i=0, j=0, k=0;
	int CourseCounter[20]={0};
	
	struct node *temp = head;
	char ammountCourseCounter[20][20] ={}, ammountCourseCounterReduced[20][20]={};	
	
	//Duplicate all of data course to an array
	while(temp != NULL){
		strcpy(ammountCourseCounter[i], temp->taskLinkedList.course);
		strcpy(ammountCourseCounterReduced[i], temp->taskLinkedList.course);
		temp = temp->next;
		i++;
	}
		
		
	//Check Duplicate betwen array that store course names
	int ammountCourse = nodeCounter(head);
		
	for (i = 0; i < ammountCourse; i++){
		for(j = i + 1; j < ammountCourse; j++){
	    	if(strcmp(ammountCourseCounterReduced[i], ammountCourseCounterReduced[j])==0){
	    		for(k = j; k < ammountCourse; k++){
	    			strcpy(ammountCourseCounterReduced[k], ammountCourseCounterReduced[k + 1]);
				}
				ammountCourse--;
				j--;
			}
		}
	}
		
    //Counter
    for (i = 0; i < ammountCourse; i++){
      		int count=0;
			for (j = 0; j < nodeCounter(head); j++){
				if(strcmp(ammountCourseCounterReduced[i], ammountCourseCounter[j])==0){
	    			count++;
			}
		}
		CourseCounter[i] = count++;
	}
		
	//Display
	printf("\nNumber of tasks in each course \n");
	for(j=0; j<ammountCourse; j++){
		printf("%s = %d\n", ammountCourseCounterReduced[j], CourseCounter[j]);
	}
}

void writefile(struct node *head){
	struct node *temp=head;
	FILE *fptr;
	fptr=fopen("Task manager.bin","wb");
	if(fptr==NULL){
		printf("ERR AJA\n");
		exit(1);
	}
	while(temp!=NULL){
		fwrite(temp,sizeof(struct node),1,fptr);
		temp=temp->next;
	}
	if(fwrite!=0){
		printf("Data saved\n");
	}
	else{
		printf("ERR WRITE\n");
	}
	fclose(fptr);
}

struct node* readFile(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node *head;
	struct node *last;
	last = head = NULL;
	FILE *fptr;
	fptr=fopen("Task Manager.bin","rb");
	if(fptr==NULL){
		printf("Data not found.\n\n");
		return;
	}
	while(fread(temp,sizeof(struct node),1,fptr)){
		if(head==NULL){
			head=last=(struct node*)malloc(sizeof(struct node));
		}
		else{
			last->next=(struct node*)malloc(sizeof(struct node));
			last=last->next;
		}
		last->taskLinkedList=temp->taskLinkedList;
		last->next=NULL;
	}
	fclose(fptr);
	return head;
}

void deallocate(struct node** head){
	struct node* current =*head;
	struct node* next;
	
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	*head=NULL;
}

struct tree* newNode(float data){
	struct tree* newNode;
	newNode =(struct tree*)malloc(sizeof(struct tree));
	newNode->data =data;
	newNode->right =NULL;
	newNode->left = NULL;
	
	return newNode;
}

struct tree* insert(struct tree* node, float data){
	if(node==NULL){
		return newNode(data);
	}
	if(data<node->data){
		node->left = insert(node->left, data);
	}
	else{
		node->right = insert(node->right, data);
	}
	return node;
}

//Print
void inorder(struct tree* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%.2f-->", root->data);
		inorder(root->right);
	}
}

struct tree* smallest(struct tree* root){
	struct tree *current = root;
	
	while(current !=NULL && current ->left != NULL){
		current = current ->left;
	}
	return current;
}

struct tree* deleteNodeTree(struct tree* root, float key){
	if(root==NULL){
		return root;
	}
	
	if(key<root->data){
		root->left = deleteNodeTree(root->left,key);
	}
	else if(key>root->data){
		root->right=deleteNodeTree(root->right,key);
	}
	else{
		if(root->left==NULL&&root->right==NULL){
			root==NULL;
		}
		else if(root->left==NULL){
			root=root->right;
		}
		else if(root->right==NULL){
			root = root->left;
		}
		else{
			struct tree* temp=smallest(root->right);
			root->data = temp->data;
			root->right = deleteNodeTree(root->right, temp->data);
		}
	}
	return root;
}

void searchTree(struct tree** current, float search){
	if((*current)!=NULL){
		if(search<(*current)->data){
			searchTree(&(*current)->left, search);
		}
		else if(search>(*current)->data){
			searchTree(&(*current)->right, search);
		}
		else{
			printf("\nFound %.2f\n",(*current)->data);
		}
	}
	else{
		printf("%.2f Not Found\n", search);
	}
}

void binaryTree(struct tree *root){
	system("cls");	
	int i, optionBinaryTree = -999, inputAmmount;
	float data;
	
	do{
		printf("Binary Tree\n\nChoose option\n1. Insert\n2. Search\n3. Delete\n4. Back to main menu.\n\nInsert option : ");
		scanf("%d", &optionBinaryTree);
	
	switch(optionBinaryTree) {
		case 1:
			printf("Insert tree\n");
			printf("Number of element to insert : ");
			scanf("%d", &inputAmmount);
			
			for(i=0; i<inputAmmount; i++){
				printf("Enter data : ");
				scanf("%f", &data);
				root = insert(root, data);
			}
			
			inorder(root);
			
			getchar();
			printf("\nPress enter to continue.\n");
			getchar();
			system("cls");	
			
			break;
		case 2:
			printf("Search Tree\n");
			inorder(root);
			printf("Number of element to search : ");
			scanf("%d", &inputAmmount);
			
			for(i=0; i<inputAmmount; i++){
				printf("Enter data : ");
				scanf("%f",&data);
				searchTree(&root, data);
			}
			
			getchar();
			printf("\nPress enter to continue.\n");
			getchar();
			system("cls");	
			
			break;		
		case 3:
			printf("Delete Tree\n");
			inorder(root);
			printf("Number of element to insert : ");
			scanf("%d", &inputAmmount);
			for(i=0; i<inputAmmount; i++){
				printf("Enter data : ");
				scanf("%f", &data);
				root = deleteNodeTree(root, data);
			}
			inorder(root);
			getchar();
			printf("\nPress enter to continue.\n");
			getchar();
			system("cls");	
			
			break;
	default:
		printf("Option not availible.\nPress enter to continue.\n");
		getchar();
		optionBinaryTree = 0;
		break;
	}

	}while(optionBinaryTree != 0);
}
