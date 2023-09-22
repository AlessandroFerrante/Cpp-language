/*
 * new_example.cpp
 */
/*
 ? l*allocazione dinamica 
 ? è uguale al C => int * array= malloc(n*sizeof(int))
 ? oppure usando l'operatore new => int *array= new int [n]
 ? invece,
 ? per deallocare possiamo usare
 ? free(array) oppure delete []array
 ? */
#include<iostream>
void calc_max_min(int *a, int n, int *max, int *min){
    *max= a[0];
    *min= a[0];
    for(int i=1; i<n; i++){
        if(a[i] > *max)
            *max= a[i];
        if(a[i] < *min)
            *min= a[i];
    }   
}
int main(int argc, char * argv[]){
    std:: cout<< "Insert array size: ";
    int n;
    std::cin >> n;
    int * array= new int[n];
    for(int i=0; i<n; i++){
        std::cout << "Insert element " << i << ": "; 
        std:: cin >> array[i];
    }
    int MAX, MIN;
    calc_max_min(array, n, &MAX, &MIN);
    std:: cout << "Max is: " << MAX << std:: endl;
    std:: cout << "Min is: " << MIN << std:: endl;
    delete [] array;
    return 0;
}