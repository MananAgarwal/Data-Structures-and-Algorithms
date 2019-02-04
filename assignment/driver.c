#include <stdio.h>
#include <stdlib.h>
#include "assignment.h"

int main()
{
    int ramSize = 12; //51
    int freeSize = ramSize / 3;

    int RAM[ramSize];
    int LISTHEADS[freeSize];
    int FREE[freeSize];

    for (int i = 0; i < ramSize; i++)
    {
        RAM[i] = -1;
    }

    //initialise the FREE array with all the addresses as RAM is empty
    //also initialise the LISTHEADS array with -1 i.e. NULL
    for (int i = 0; i < freeSize; i++)
    {
        FREE[i] = (freeSize - 1 - i) * 3;
        LISTHEADS[i] = -1;
    }
    int freeTop = freeSize - 1;

    int option = 1;
    while (option != 0)
    {
        printf("\nSelect an option:\n1. Create a new list\n2. Insert a new element in a given list in sorted order\n3. Delete an element from a given list\n4. Count total elements excluding free list\n5. Count total elements of a list\n6. Display all lists\n7. Display free list\n8. Perform defragmentation\n9. Press 0 to exit\n");
        scanf(" %d", &option);
        switch (option)
        {
        case 0:
            option = 0;
            break;
        case 1:
            createNewList(RAM, LISTHEADS, FREE, freeSize, &freeTop);
            break;
        case 2:
            insertNewElement(RAM, LISTHEADS, FREE, freeSize, &freeTop);
            break;
        case 3:
            deleteElement(RAM, LISTHEADS, FREE, freeSize, &freeTop);
            break;
        case 4:
            totalElements(freeTop, freeSize);
            break;
        case 5:
            totalElementsInList(RAM, LISTHEADS, freeSize);
            break;
        case 6:
            displayLists(RAM, LISTHEADS, freeSize);
            break;
        case 7:
            displayFree(FREE, &freeTop);
            break;
        case 8:
            defragmentation(RAM, LISTHEADS, FREE, freeSize, &freeTop);
            break;
        case 9:
            option = 0;
            break;
        default:
            option = 0;
            break;
        }
    }
}