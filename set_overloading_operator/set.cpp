/*
 author Alessandro Ferrante
 * set.cpp
*/
/*
 | The file contains only the method implementations of the SetDuplicates and Set classes.
 *
 ? The example implements the redemption of the set, union and difference operators,
 ? the addition and subtraction operators and the element access operator via index.
 * 
*/

using namespace std;

// Default constructor
SetDuplicates::SetDuplicates() : size(0){
    
} 

// Copy constructor
SetDuplicates::SetDuplicates(SetDuplicates& s){
    size = s.size;
    data = new int[size];
    for(int i = 0; i < size; i++){
        data[i] = s.data[i];
    }
}

// Destructor
SetDuplicates::~SetDuplicates(){
    if(size < 0)
        delete []data;
}

//* Implementation of the add method
void SetDuplicates::add(int elem){
    //  New larger array
    int * new_data = new int [size + 1];
    // Copy of elements already existing in the set
    for (int i = 0; i < size; i++){
        new_data[i]= data[i];
    }

    // ? Adding the element to the new array
    new_data[size] = elem; 

    // ? Deallocates memory of the existing array if it already contained elements
    if(size > 0)
        delete []data;

    data = new_data; // ? Update the pointer to the new array
    size++; // ? Increments the size of the set object
}

//* Implementation of the remove method
bool SetDuplicates::remove(int elem){
    int i;
    for(i = 0; i < size; i++){
        if (data[i] == elem)
            break;
    }
    
    // ? if the element does not exist, return false
    if(i == size)
        return false;

    size--;

    // If the set is not empty
    if (size > 0){
        // ? Move the elements following the element to be removed to cover the hole, 
        // ? in fact it starts from the position where the control stops 
        // ? and sets j = i (i -> position of the element found)
        for(int j = i ; j < size; j++){
            data[j] = data[j+1];
        }

        int * new_data = new int[size];
        for (int i = 0; i < size; i++){
            new_data[i]  = data[i];
        }
        // deallocate the memory pointed to the previous array; 
        delete []data;
        // update the pointer to the new array
        data = new_data;
    }
    else
        delete []data;
    return true;
}

// ? Implementation of the find method
bool SetDuplicates::find(int elem){
    for (int i = 0; i < size; i++){
        if (data[i] == elem)
            return true;
    }
    return false;
}

// ? Implementation of the + operator, for joining two sets
SetDuplicates SetDuplicates::operator+(SetDuplicates & rhs){
    SetDuplicates result(*this);           // ? Create a copy of the current (this) set (the left-hand side of the operator)
    for(int i = 0; i < rhs.size; i++){     // ? Iterate through the elements of the right-hand side set (rhs)
        result.add(rhs.data[i]);           // ? Add each element of rhs to the result set
    }
    // ? Return the resulting set after the union operation
    return result;
}

// ? Implementation of the - operator, for the difference between two sets
SetDuplicates SetDuplicates::operator-(SetDuplicates & rhs){
    SetDuplicates result(*this);            // ? Create a copy of the current (this) set (the left-hand side of the operator)
    for(int i = 0; i < rhs.size; i++){      // ? Iterate through the elements of the right-hand side set (rhs)
        result.remove(rhs.data[i]);         // ? Remove each element of rhs to the result set
    }
    // ? Return the resulting set after the difference operation
	return result;
}

//? Implementation of the output operator to print the elements of the set to the screen
ostream& operator<<(ostream& output_stream, SetDuplicates & s){
    // Output a separator line
	output_stream << "-------------------------" << endl;
    // ? Iterate through the elements of the set, to print them to the screen
	for (int i = 0;i < s.size;i++) {
		output_stream << i << ":" << s.data[i] << endl;
	}
    // Return the output stream 
	return output_stream;
}

// | Methods of the Set class
// ? Adds an element to the set avoiding duplicates,
// ? uses the method of the parent class
void Set::add(int elem){
    // ? if it already exists, it returns and does not add it to the set
	if (SetDuplicates::find(elem)) 
		return;
		
	SetDuplicates::add(elem); // ? call parent class method
}

// ? Implementation of the + operator, for the union of two sets (of the Set class)
Set Set::operator+(Set& rhs){
	Set result(rhs);                    // ? Create a copy of the set, where to add the element
	for (int i = 0; i < size;i++) {     // ? Iterate through the elements of the left-hand side set (this)
		result.add(data[i]);            // ? Add each element of rhs to the result set
	}
	return result;
}