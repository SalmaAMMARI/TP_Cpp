README - TP3

 The exercises include memory analysis, cleaning service estimation, compile-time factorial computation, global vs. local variable usage, constants, and overflow detection in multiplication.

Table of Contents

Requirements

Compilation and Execution

Exercises

Notes


To compile and run these exercises, ensure you have:

A C++ compiler (e.g., g++, clang++) supporting C++11 or later

A terminal or an IDE like VS Code, Code::Blocks, or CLion

Compilation and Execution

Each exercise is controlled by the EXO macro. To compile and run a specific exercise, define the macro accordingly.

Example using g++:

# Compile with EXO=1 (for Exercise 1)
g++ -o tp_exercises tp.cpp -DEXO=1

# Run the executable
./tp_exercises

Replace 1 with the desired exercise number (1 to 6).

Exercises

1. Memory Analysis of an Array

Calculates the total memory occupied by an array.

Determines the size of an individual element.

Computes the number of elements in the array.

2. Carpet Cleaning Service Estimation

Asks the user for the number of small and large carpets.

Computes the cost, tax, and total estimate.

Displays an estimate valid for 30 days.

3. Compile-Time Factorial Calculation

Uses constexpr recursion to compute the factorial of a number at compile time.

Uses static_assert to verify correctness.

4. Global vs. Local Variables (Shadowing)

Demonstrates variable shadowing with a global variable.

Uses the scope resolution operator :: to access the global value.

5. Advanced Constant Usage

Demonstrates const and constexpr constants.

Calculates the area of a circle using a predefined pi value.

6. Overflow Detection in Multiplication

Implements safeMultiply() to detect overflow before multiplication.

Demonstrates different cases of overflow scenarios.

Notes

If EXO is not defined correctly, a preprocessor error message will be displayed.

Ensure valid inputs where required (e.g., integers for multiplication tests).