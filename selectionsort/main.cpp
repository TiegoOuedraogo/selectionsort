#include <iostream>

#include <cstdlib>

//to me a void function seems like the best way to do this, since all we're doing is sorting and then printing out the results.
void selectionsort(int n, int A[]);
int createarray(int n, int A[], int x);


int main(int argc, const char * argv[]) {
    
    int n;
    int x;
    std::cout << "Please enter an array length: ";
    std::cin >> n;
    //here, I decided to give the user the chance to give a max for the range of random numbers
    std::cout << "Before I generate some random numbers, please enter in the highest random number you would like to see: ";
    std::cin >> x;
    int A[n];
    createarray(n, A, x);
    selectionsort(n, A);
    return 0;
}

//for me, separating the creation of the array from the sorting of it makes it easier to keep track of what's happening.
int createarray(int n, int A[], int x){
    
    int i;
    for(i=0; i<n; i++){
        //the below statement will create a pseudo random number, and then populate the current location in the array with them.
        int random = (rand() % x) + 1;
        int b = random;
        A[i] = b;
    }
    
    //this will simply print out the results from us populating the array in descending order.
    for(int a = 0; a < (n-1); a++){
        std::cout << A[a] << ", ";
    }
    std::cout << A[n-1] << std::endl;
    return A[n];
}

void selectionsort(int n, int A[]){
    int min;
    int temp;

    /*below is the actual sorting algorithm. it is characterized by two nested for loops, and a nested if condition. */

    for(int i=0; i<(n-1); i++){
        min = i;
        for(int j = (i+1); j<n; j++){
            if(A[j] < A[min]){
                
                //this will simply swap the values.
                temp = A[j];
                A[j] = A[min];
                A[min] = temp;
            }
        }
    }
    std::cout << "Your newly assorted array: " << std::endl;
    for(int a = 0; a < (n-1); a++){
        std::cout << A[a] << ", ";
    }
    std::cout << A[n-1] << std::endl;
}
