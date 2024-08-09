#include <iostream>


int main()
{

  int setA = 0, setB = 0;    // a variable to save the bit vector of set A
  int userInput;             // a variable to save the user input

  std::cout << "\n\nWelcome to HW 2: programming!  Given subsets A and B of a universal set with 10 elements \
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, we will use bit strings to find A U B, A ∩ B, and A - B. \
Users will be asked to populate each set. For example, if the user enters 1, 2, 6, the bit \
string will display from left to right and display 0110001000.\n\n";


  std::cout << "Please enter a number for set A (enter -1 to stop): ";
  std::cin >> userInput;

  // Get input for setA
  while(userInput != -1){

    setA |= (1 << userInput);  // | is the bitwise-or; << is the left shift operator       

    std::cout << "Please enter a number for set A (enter -1 to stop): ";
    std::cin >> userInput;

  }


  // Reinitialize userInput so not to fall through loop
  userInput = 0;

  // Padding
  std::cout << '\n';


  // Get input for setB
  std::cout << "Please enter a number for set B (enter -1 to stop): ";
  std::cin >> userInput;

  // Get input for setB
  while(userInput != -1){

    setB |= (1 << userInput);  // | is the bitwise-or; << is the left shift operator   

    std::cout << "Please enter a number for set B (enter -1 to stop): ";
    std::cin >> userInput;    

  }

  
  // Display set 1 (use for loop to 10 as we know we have 10 elements to check in universal)
  int mask = setA;

  std::cout << "\nSet A:           ";

  for (int i = 0; i < 10; i++) {
      
    std::cout << ((mask >> i) & 1);

  }

  std::cout << "\nSet B:           ";

  // Display set 2 (use for loop to 10 as we know we have 10 elements to check in universal)
  mask = setB;

  for (int i = 0; i < 10; i++) {
      
    std::cout << ((mask >> i) & 1);

  }

  std::cout << "\n\n";

  // Get the intersection
  int intersectionR = setA & setB;

  // Get the union
  int unionR = setA | setB;

  // Get the difference from everything in a thats NOT in b ( ~setB )
  int differenceR = setA & ( ~setB );


  std::cout << "Union:           ";

  // Display Union (dont need mask as program wont need value anymore)
  for (int i = 0; i < 10; i++) {
      
    std::cout << ((unionR >> i) & 1);

  }

  std::cout << "\nIntersection:    ";

  // Display Intersection (dont need mask as program wont need value anymore)
  for (int i = 0; i < 10; i++) {
      
    std::cout << ((intersectionR >> i) & 1);

  }

  std::cout << "\nDifference:      ";

  // Display Difference (dont need mask as program wont need value anymore)
  for (int i = 0; i < 10; i++) {
      
    std::cout << ((differenceR >> i) & 1);

  }

  std::cout << "\n\n";
  
}