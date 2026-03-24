# DSYA
Reduced Version of Dijkstra's Shunting Yard Algorithm  
  
Program authored by A G Reynolds as part of university coursework [2026]. It uses separate compilation of modular components (such as stacks) to comprise a reduced version of Dijkstra's Shunting Yard Algorithm, converting algebraic expressions to Reverse Polish Notation through a Finite State Machine, then evaluating and displaying the result.
  
## File Descriptions  
 - **boolean.h** - A header file containing boolean typedef used throughout  
 - **cstack (.c / .h)** - A character stack used to manage operators and parentheses during expression conversion  
 - **dsya (.c / .h)** -  Converts standard algebraic expressions to RPN format  
 - **dsya_main.c** - Main program that takes an algebraic expression as user input and prints the result  
 - **dsya_util (.c / .h)** - Contains utility functions  
 - **fstack (.c / .h)** - A float stack used during evaluation of the expression  
 - **rpn (.c / .h)** - The FSM that evaluates the RPN through use of the fstack  
   
## Error Handling
    Error handling in this project uses a numbered system. This emerged from having to debug the code, as the project was a learning experience. After successfully compiling the program, I found logic errors where it was incorrectly triggering error states. I assigned each error a unique code where the leading digit corresponds to a specific file (1 for dsya, 2 for utilities, 3 for rpn), and the remaining digits indicate the line on which the error is written. This change made it clear which error was being triggered and where to look in the code, allowing faster identification of the problem and its correction it.  
      
*Required Makefile Not Provided*
