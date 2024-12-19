#include <stdio.h>
#include <stdlib.h>
// function to display the matrix
void DisplayMatrix(char matrix[][100], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("{%s}\n", matrix[i]);
    }
    printf("\n");
}

// display function
void Display (int arr [] , int sizeofArr){
 for (int k = 0; k < sizeofArr; k++) {
    printf("%d ", arr[k]);
}
printf("\n");
}

// selection sorting
void SelectionSorting (int arr [] , int sizeofArr){
    int min ;
    int temp ;
    int nbrComp = 0 ;
    int nbrPerm = 0;

  for( int i = 0 ; i < sizeofArr -1 ;  i++){
    min =  i ;
    for (int j = i+1 ; j < sizeofArr ; j++){
        if ( arr[min] > arr[j]){
            min = j ;
            nbrComp++;
        }
    }
    temp = arr [i];
    arr[i] = arr[min];
    arr[min] = temp ;
    nbrPerm++ ;
    printf("Permutation %d: ", i + 1);
    Display(arr , sizeofArr);
  }
  printf("Number of comparisons : %d \n" , nbrComp);
  printf("Number of permutations : %d \n" , nbrPerm);
}

// bubble sorting
void bubbleSort(int arr[], int sizeofArr) {
    int i;
    int j;
    int temp;
    int nbrComp = 0 ;
    int nbrPerm = 0;
    for (i = 0; i < sizeofArr - 1; i++) {
        for (j = 0; j < sizeofArr - i - 1; j++) {
            nbrComp++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                nbrPerm++;
                printf("Permutation %d: ", nbrPerm);
                Display(arr , sizeofArr);
            }
        }
    }
    printf("\nNumber of comparisons: %d\n", nbrComp);
    printf("Number of permutations: %d\n", nbrPerm);
}
// bubble sort function for a matrix of characters
void BubbleSortMatrix(char matrix[][100], int rows) {
    char temp;
    int nbrComp = 0 ;
    int nbrPerm = 0 ;

    for (int i = 0; i < rows; i++) {
        int sizeofLine = strlen(matrix[i]);
        // Bubble sort for the current row
        for (int j = 0; j < sizeofLine - 1; j++) {
            for (int k = 0; k < sizeofLine - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    // Swap the characters
                    temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                    nbrPerm++;
                printf("swap number %d\n" , nbrPerm);
                DisplayMatrix(matrix, rows);
                }
                nbrComp++;
            }
        }
    }
    printf("nombre de comparaison : %d \n" , nbrComp);
    printf("nombre de permutations : %d\n", nbrPerm);
}


// the function merge
 // global variables fot comp & perm counters
int nbrComp = 0;
int nbrPerm = 0 ;
void Merge ( int arr[] , int low , int mid , int high ){
    int temp [high - low + 1];
    int left = low ;
    int right = mid + 1 ;
    int j = 0;
    while(left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp[j] = arr[left];
            left ++ ;
            j++ ;
            nbrPerm++;
        } else {
        temp[j] = arr[right];
        right ++ ;
        j++;
        nbrPerm++;
        }
        nbrComp++;
    }
    while (left <= mid ){
        temp[j] = arr[left];
        left ++;
        j++;
        nbrPerm++;
    }
    while (right <= high){
        temp[j] = arr[right];
        right ++ ;
        j++;
        nbrPerm++;
    }
    //arr = temp ;
        for (int k = 0; k < high - low +1; k++) {
        arr[low + k] = temp[k];
    }

    printf("merged array in [%d , %d] ", left , right);
    Display(arr, right +1 );
}
//merge sort function
void MergeSort (int arr [] , int low , int high){
    if (low < high){
        int mid = (low + high) / 2 ;
        MergeSort(arr , low , mid );
        MergeSort(arr , mid +1 , high);
        Merge( arr , low , mid , high);
    }
}
// the function insertion sort
void insertionsort(int arr[], int sizeofarr){
    int i, j, temp;
    int nbrComp =0, nbrPerm=0;
    for(i=1;i<sizeofarr-1;i++){
        temp = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            nbrComp++;
            arr[j+1]=arr[j];
            nbrPerm++;
            j= j-1;
        }
        arr[j+1]= temp;
         nbrPerm++ ;
    Display(arr , sizeofarr);
    }
    printf("Number of comparisons : %d \n" , nbrComp);
  printf("number of permutations : %d \n" , nbrPerm);
}
// the function of quick sort
// the function that does the partitioning
int partition(int arr[], int start, int end , int nbrComp , int nbrPerm){
    int pivot, i , j, temp;
    pivot = arr[end];
    i= start;
    for(j=start;j<end-1;j++){
        if(arr[j]<pivot){
           nbrComp++;
           temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
           i++;
        nbrPerm++;
        }
    }
    temp = arr[i];
    arr[i]= arr[end];
    arr[end] = temp;
    nbrPerm++;
    return i;

}
 // the quick sort algorithm using the recursive calls
 void quicksort( int arr, int start, int end){
       int nbrComp =0, nbrPerm =0;
     if (start < end){
        int pivot = partition(arr, start, end, nbrComp, nbrPerm);
        quicksort(arr, start, pivot -1);
        quicksort(arr, pivot +1, end);
     }
       printf("Number of comparisons : %d \n" , nbrComp);
  printf("number of permutations : %d \n" , nbrPerm);
 }
int main()
{
    int array [] = {64 , 34 , 25 , 12 , 22 , 11 , 90};
    int arraySize = sizeof(array) / sizeof(array[0]);

    char matrix[][100] = {"gfr","zvc","qwe", "axd"};
    int rows = sizeof(matrix) / sizeof(matrix[0]);

/*
    printf ("original array \n");
    Display(array , arraySize);

    printf("Selection sorting execution \n");
    SelectionSorting(array , arraySize);
    printf("sorted array using selection sorting \n ");
    Display(array , arraySize);

    printf("Bubble sorting execution \n");
    bubbleSort(array , arraySize);
    printf("sorted array using bubble sorting \n ");
    Display(array , arraySize);

    printf("merge sort execution \n");
    MergeSort(array , 0 , arraySize -1 );
    printf("comparisions %d \n", nbrComp);
    printf("permutations %d \n" , nbrPerm);
    printf("sorted array using merge sorting \n");
    Display(array , arraySize);*/

<<<<<<< HEAD
    printf("Original Matrix:\n");
    DisplayMatrix(matrix, rows);

    BubbleSortMatrix(matrix, rows);
    printf("matrix after bubble sort:\n");
    DisplayMatrix(matrix, rows);
=======
     printf("each step of the insertion sorting process \n");
    insertionsort(array , arraySize);
    printf("sorted array using insertion sorting \n ");
    Display(array , arraySize);
>>>>>>> 0303c55aad76380b5e19e461d48fdf7d01cac40d


    return 0;
}
