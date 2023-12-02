The program adds 2 and up to 13 very large numbers accurately. It multiplies the first and last and shows the intermediate steps of the product. The numbers must be positive whole numbers or ‘0’. 

Procedural/Functional Decomposition
•	Problem is broken down into subtasks handled by different functions
•	Data and data structures passed around via parameters
•	No objects are included in the program

String library functions are included in the program.

Key Data Structures
•	String variables to store the integer values
•	String variables for input validation, all user inputs are initially stored in a string and then manipulated to check for correct format and characters
•	Arrays of strings to group the integers to be operated on and to store the intermediate steps of the multiplication process

Algorithm Design
•	Required Tasks
o	Storage of very large integers
o	Addition of strings (2 numbers at a time) by using standard addition alignment
o	Multiplication of strings (2 numbers at a time) by using standard indexing of alignment process
•	Solution
o	Store integers in string variables backwards and add leading zeros to handle varying integer sizes
o	Add integers one character at a time from lowest to highest index while keeping track of the carry value
o	Multiply every character together and index after each pass to provide accurate intermediate steps and ultimately a final product

Time complexity of operations
•	Add Function: O(n)
•	Multiply Function: O(n^2)

Space complexity of operations
•	Add Function: O(1)
•	Multiply Function: O(1)
