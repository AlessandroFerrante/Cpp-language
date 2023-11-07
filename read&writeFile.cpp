/*
* readFile.cpp
*/
/*
 ? reads the numbers from the number.txt file 
 ? and writes them back in order 
 ? to the sorted_numbers.txt file
*/
#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(int * a, int n){
    bool done = true;
    do {
        done = true;
        for (int i = 0; i < n-1; i++){
            if (a[i] > a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                done = false; 
            }
        }
    } while (!done);// ? repeated until done equals false. 
}

int main(int argc, char** argv){
    // ? "input file stream", an input stream to a file, to set a pointer to read from the file. 
    ifstream myfile;// -> FILE * fptr; (in C)
    // ? opens the file with a pointer set to read from the file.
    myfile.open("numbers.txt"); // -> fptr = fopen("numeri.txt"); (in C)
    int n;
    myfile >> n;// ? reads the first line to store n, which indicates the number of elements to read;
    int * dati = new int[n];
    // print in terminal and save to array
    for(int i = 0; i < n; i++){
        myfile >> dati[i];// ? The extract operator >> reads data from the file by positioning the pointer to the next location in the file.
        cout << dati[i] << endl;
    }
    myfile.close(); // -> fclose(myfile); (in C)

    bubbleSort(dati, n); // sort array

    ofstream outfile; // ? ofstream, "output file stream", an output stream to a file, to set a pointer to write to the file.
    outfile.open("sorted_numbers.txt");// ? opens the file with a pointer set to write to the file.
    outfile << n << endl;
    for (int i = 0; i < n; i++){
        outfile << dati[i] << endl;
    }
    outfile.close();// ? closes the output file
    return 0;
}