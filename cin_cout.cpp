/*
 * cin_cout.cpp
 */
#include<iostream>

int main(int argc, char * argv[]){
    //std -> name space, hierarchical names
	//:: separators, cout -> console out , endl-> end line
    std::cout <<"Insert a number : ";
    //scanf("%d", &a);
    int a;
    std::cin>>a; //cin -> console input, write in address of the integer a, the number writed in console
    int b = a*2;
    std::cout<< "The value is : " << b << std::endl;
    return 0;
}