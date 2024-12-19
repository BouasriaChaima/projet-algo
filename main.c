#include <stdio.h>
#include <stdlib.h>

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
    Display(arr , sizeofArr);
  }
  printf("Number of comparisons : %d \n" , nbrComp);
  printf("numver of permutations : %d \n" , nbrPerm);
}

// bubble sorting
void BubbleSorting (int arr [] , int sizeofArr){
    int swap;
for (int i = 0 ; i < sizeofArr - 1 ; i++ ){
  for (int j = 0 ; j < sizeofArr - 1 -i ; j++){
    if(arr[j] > arr[j+1]){
     swap = arr[j];
     arr[j] = arr [j+1];
     arr[j+1] = swap ;
    //dispaly every progress
    printf("After swapping %d and %d: ", arr[j + 1], arr[j]);
    Display(arr , sizeofArr);

}}}}

// the function merge
void Merge ( int arr[] , int low , int mid , int high){
    int temp [high - low + 1];
    int left = low ;
    int right = mid + 1 ;
    int j = 0;

    while(left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp[j] = arr[left];
            left ++ ;
            j++ ;
        } else {
        temp[j] = arr[right];
        right ++ ;
        j++;
        }
    }
    while (left <= mid ){
        temp[j] = arr[left];
        left ++;
        j++;
    }
    while (right <= high){
        temp[j] = arr[right];
        right ++ ;
        j++;
    }
    //arr = temp ;
        for (int k = 0; k < high - low +1; k++) {
        arr[low + k] = temp[k];
    }
    printf("Merging range [%d-%d]: ", low, high);
    for (int k = low; k <= high; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

void MergeSort (int arr [] , int low , int high){
    if (low < high){
        int mid = (low + high) / 2 ;
        MergeSort(arr , low , mid );
        MergeSort(arr , mid +1 , high);
        Merge( arr , low , mid , high);
    }

}

int main()
{
    int array [] = {64 , 34 , 25 , 12 , 22 , 11 , 90};
    int arraySize = sizeof(array) / sizeof(array[0]);

   printf ("original array \n");
   Display(array , arraySize);

    printf("each step of the slection sorting process \n");
    SelectionSorting(array , arraySize);
    printf("sorted array using selection sorting \n ");
    Display(array , arraySize);

    BubbleSorting(array , arraySize);
    printf("sorted array using bubble sorting \n ");
    Display(array , arraySize);

    MergeSort(array , 0 , arraySize -1);
    printf("sorted array using merge sorting \n");
    Display(array , arraySize);




    return 0;
}
