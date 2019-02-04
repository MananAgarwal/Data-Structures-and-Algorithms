#include <stdio.h>
#include <stdlib.h>

void createNewList(int RAM[],int LISTHEADS[], int FREE[], int freeSize, int *freeTop)
{
    //display the list number
    int listNumber = 0;
    while(LISTHEADS[listNumber] != -1){
        listNumber++;
    }

    if(*freeTop<0){  //if(listNumber>freeSize)
        printf("FAILURE: MEMORY NOT AVAILABLE");
        return;
    }
    else{
        printf("\nThe sequence number of the newly created list is: %d", listNumber+1);
        printf("\nEnter key value to be inserted in the newly created list-%d:", listNumber+1);
        
        //Get the input key
        int key;
        scanf(" %d", &key);
        
        //Enter the value in RAM and LISTHEADS. Update freeTop.
        LISTHEADS[listNumber] = FREE[*freeTop];
        RAM[LISTHEADS[listNumber]] = key;
        RAM[LISTHEADS[listNumber]+1] = -1;
        RAM[LISTHEADS[listNumber]+2] = -1;
        *freeTop-=1;
        printf("\nSUCCESS");
    }
}

void insertNewElement(int RAM[],int LISTHEADS[], int FREE[], int freeSize, int *freeTop)
{
    if(*freeTop<0){  //if(listNumber>freeSize)
        printf("FAILURE: MEMORY NOT AVAILABLE");
        return;
    }

    int listNumber, key;
    printf("\nList you want to insert in: ");
    scanf(" %d", &listNumber);
    
    if(listNumber > freeSize || LISTHEADS[listNumber -1] == -1){
        printf("FAILURE: MEMORY NOT AVAILABLE\n");
        return;
    }

    printf("Enter the key value: ");
    scanf(" %d", &key);

    //insertion sort
    int next = LISTHEADS[listNumber-1];
    while(next != -1 && RAM[next]<=key){
        if(RAM[next + 1] == -1){ //i.e. we key is the largest value in the list
            RAM[FREE[*freeTop]] = key;
            RAM[FREE[*freeTop]+1] = -1;
            RAM[FREE[*freeTop]+2] = next;
            RAM[next+1] = FREE[*freeTop];    
            
            FREE[*freeTop] = -1;
            *freeTop-=1;

            printf("SUCCESS");
            return;
        }
        next = RAM[next + 1];
    }

    RAM[FREE[*freeTop]] = key;
    RAM[FREE[*freeTop]+1] = next;
    RAM[FREE[*freeTop]+2] = RAM[next+2];
    if(RAM[next+2] == -1){
        LISTHEADS[listNumber-1] = FREE[*freeTop];
    }
    RAM[next+2] = RAM[FREE[*freeTop]];

    //update freetop
    FREE[*freeTop] = -1;
    *freeTop-=1;
    printf("SUCCESS");
    return;
}

void deleteElement(int RAM[],int LISTHEADS[], int FREE[], int freeSize, int *freeTop)
{
    int listNumber, key;
    printf("\nList you want to delete from: ");
    scanf(" %d", &listNumber);
    
    if(LISTHEADS[listNumber-1] == -1)
    {
        printf("FAILURE: LIST EMPTY");
        return;
    }

    printf("Enter the key value: ");
    scanf(" %d", &key);

    int head = LISTHEADS[listNumber-1];
    while(RAM[head] != key)
    {
        head = RAM[head+1];
        if(head == -1){
            printf("FAILURE: ELEMENT DOES NOT EXIST IN THIS LIST");
            return;
        }
    }

    RAM[head] = -1;
    int next = RAM[head+1];
    int prev = RAM[head+2];
    if(prev != -1)
    {
        RAM[prev+1] = next;
    }
    else{
        LISTHEADS[listNumber-1] = next;
    }

    if(next != -1){
        RAM[next+2] = prev;
    }
    else{
        RAM[prev+1] = next;
    }
    RAM[head+1]=-1;
    RAM[head+2]=-1;

    // update the free list
    *freeTop+=1;
    FREE[*freeTop] = head;
    printf("\nSUCCESS");
    return;
}

void totalElements(int freeTop, int freeSize)
{
    printf("\nTotal number of nodes in all lists are %d", (freeSize - freeTop -1));
}

void totalElementsInList(int RAM[], int LISTHEADS[], int freeSize)
{
    int listNumber;
    printf("\nEnter the list number: ");
    scanf(" %d", &listNumber);

    if(listNumber > freeSize || LISTHEADS[listNumber -1] == -1){
        printf("FAILURE: LIST IS EMPTY\n");
        return;
    }

    int next = LISTHEADS[listNumber-1] + 1;
    int count = 1;
    while(RAM[next] != -1){
        next = RAM[next] + 1;
        count++;
    }

    printf("Total number of nodes in list %d are %d", listNumber, count);
}

void displayLists(int RAM[], int LISTHEADS[])
{
    int i = 0;
    while(LISTHEADS[i] != -1){
        int next = LISTHEADS[i];
        printf("\n\nkey\tnext\tprev");
        do{
            printf("\n%d\t%d\t%d", RAM[next], RAM[next+1], RAM[next+2]);
            next = RAM[next+1];
        }while(next != -1);
        i++;
    }
}

void displayFree(int FREE[], int *freeTop)
{
    if(FREE[0]==-1)
    {
        printf("\nFree list is empty");
        return;
    }
    printf("\nElements of free list are:\n");
    printf("[");
    for(int i = *freeTop; i>0; i--){
        printf("%d , ", FREE[i]);
    }
    printf("%d]", FREE[0]);
}

void defragmentation(int RAM[],int LISTHEADS[], int FREE[], int freeSize, int *freeTop){
    
    int sortedFREE[*freeTop+1];
    //cloning FREE array
    for(int i=0; i<=*freeTop; i++){
        sortedFREE[i] = FREE[i];
    }

    //sorting FREE array
    int temp;
    for(int i = 0; i<*freeTop; i++){
        for(int j = 0; j<*freeTop-i; j++){
            if(sortedFREE[j]>sortedFREE[j+1]){
                temp = sortedFREE[j];
                sortedFREE[j] = sortedFREE[j+1];
                sortedFREE[j+1] = temp;
            }
        }
    }

    //sorted FILLED array
    int countFILL = 0;
    int countFREE = 0;
    int lastFilled[*freeTop + 1];
    for(int i = 0; i<=*freeTop; i++){
        if(sortedFREE[countFREE]==3*i){
            countFREE++;
            continue;
        }
        else if(sortedFREE[countFREE]>3*i){
            lastFilled[countFILL] = 3*i;
            countFILL++;
        }
        if(countFILL == *freeTop+1 || countFREE == *freeTop+1){
            break;
        }
    }

    for(int i = 0; i<countFILL; i++ ){
        int k = sortedFREE[i];
        int l = lastFilled[countFILL-1-i];

        if(k>l){
            printf("\nSUCCESS");
            return;
        }
        RAM[k] = RAM[l];
        RAM[k+1] = RAM[l+1];
        RAM[k+2] = RAM[l+2];
        RAM[l] = -1;
        RAM[l+1] = -1;
        RAM[l+2] = -1;

        if(RAM[k+2] == -1){
            for(int b = 0; b<freeSize; b++){
                if(l==LISTHEADS[b]){
                    LISTHEADS[b] = k;
                    break;
                }
            }
        }
        else
        {
            RAM[RAM[k+2]+1] = k;
        }

        if(RAM[k+1] != -1){
            RAM[RAM[k+1]+2] = k;
        }

        for(int d = 0; d<=*freeTop; d++){
            if(FREE[d]==k){
                FREE[d] = l;
            }
        }
    }    

    printf("\nSUCCESS");
    return;
}

int main()
{
    int ramSize = 12; //51
    int freeSize = ramSize/3;

    int RAM[ramSize];
    int LISTHEADS[freeSize];
    int FREE[freeSize];

    for(int i=0; i<ramSize; i++)
    {
        RAM [i] = -1;
    }

    //initialise the FREE array with all the addresses as RAM is empty
    //also initialise the LISTHEADS array with -1 i.e. NULL
    for(int i=0; i<freeSize; i++)
    {
        FREE[i]=(freeSize-1-i)*3;
        LISTHEADS[i] = -1;
    }
    int freeTop = freeSize-1;

    int option = 1;
    while(option != 0){
        printf("\nSelect an option:\n1. Create a new list\n2. Insert a new element in a given list in sorted order\n3. Delete an element from a given list\n4. Count total elements excluding free list\n5. Count total elements of a list\n6. Display all lists\n7. Display free list\n8. Perform defragmentation\n9. Press 0 to exit\n");
        scanf(" %d", &option);
        switch(option){
            case 0 : option = 0;
                     break;            
            case 1 : createNewList(RAM,LISTHEADS,FREE,freeSize,&freeTop);
                     break;
            case 2 : insertNewElement(RAM,LISTHEADS,FREE,freeSize,&freeTop);
                     break;
            case 3 : deleteElement(RAM,LISTHEADS,FREE,freeSize,&freeTop);
                     break;
            case 4 : totalElements(freeTop, freeSize);
                     break;
            case 5 : totalElementsInList(RAM, LISTHEADS, freeSize);
                     break;
            case 6 : displayLists(RAM, LISTHEADS);
                     break;
            case 7 : displayFree(FREE, &freeTop);
                     break;
            case 8 : defragmentation(RAM,LISTHEADS,FREE,freeSize,&freeTop);
                     break;
            case 9 : option = 0;
                     break;
            default : option = 0;
                     break;
        }        
    }
}