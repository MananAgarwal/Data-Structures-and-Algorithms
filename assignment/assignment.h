void createNewList(int RAM[], int LISTHEADS[], int FREE[], int freeSize, int *freeTop);
void insertNewElement(int RAM[], int LISTHEADS[], int FREE[], int freeSize, int *freeTop);
void deleteElement(int RAM[], int LISTHEADS[], int FREE[], int freeSize, int *freeTop);
void totalElements(int freeTop, int freeSize);
void totalElementsInList(int RAM[], int LISTHEADS[], int freeSize);
void displayLists(int RAM[], int LISTHEADS[], int freeSize);
void displayFree(int FREE[], int *freeTop);
void defragmentation(int RAM[], int LISTHEADS[], int FREE[], int freeSize, int *freeTop);
