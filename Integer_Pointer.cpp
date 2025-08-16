/* Program that ask user to enter three integer values as input, however we will let user decide how many they will input for demenstration of the program I will input 3. Store the values into three different variables. For each varibale, create an integer pointer to dynamic memory. Display the contents of the variables and points. In your program, be sure to use the new operator and delete operators to management memory.*/

#include <iostream>
#include <limits> // For input validation

//only allow up to 26 values for simplicity, as we will use A-Z for display
constexpr int MAX_VALUES = 26;

// Safe integer input function (avoids undefined behavior from invalid input)
bool safeInput(int& input) {
    std::cin >> input;
    if (!std::cin) {
        std::cin.clear(); // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    return true;
}

int main() {
    // Ask user how many values they want to input
   int count = 0;

   std::cout << "How many integers do you want to enter?| Limit is 26: ";
   while (!safeInput(count) || count <= 0 || count > MAX_VALUES) {
        std::cin.clear(); // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    std::cout << "Please enter a valid positive integer|cannot be more than 26 and can not be negative: ";
    }

    int* values = new int[count]; // Dynamic memory allocation for integers

    for (int i = 0; i < count; ++i){
        std::cout << "Enter value " << static_cast<char>('A' + i) << ": ";
        while (!safeInput(values[i])){
            std::cout << "Invalid input. Enter value " << static_cast<char>('A' + i) << " again:";
        }
    }

    std::cout << "\nStored values and memory addresses:\n";
    for (int i = 0; i < count; ++i) {
        //Only valid for i < 26, Since we chose to use only A-Z for display
        char label = (i < 26) ? static_cast<char>('A' + i) : '?';
        std::cout << "Value " << label << ": " << values[i]
                  << " at address: " << &values[i] << "\n"; 
    }

    std::cout << values[0] << "\n"; // Display the first value for demonstration 

   
    // Clean up dynamic memory
    delete[] values;
    values = nullptr; // Avoid dangling pointer

    if (values == nullptr) {
        std::cout << "Values pointer is null. Memory cleaned up successfully.\n";
    } else {
        std::cout << "values[0]: " << values[0] << "\n";
        delete[] values; // This should not be accessed after delete
    }
    

    return 0; 
   

}