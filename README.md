# LISP Interpreter (C++)

## Overview
This project is a simple LISP interpreter implemented in C++. It parses and evaluates LISP-style prefix expressions and supports variables and user-defined functions.

The interpreter demonstrates core concepts such as tokenization, recursive parsing, environments, and function evaluation.

---

## Features
- Tokenizes input expressions
- Parses nested LISP expressions
- Evaluates arithmetic operations:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
- Variable support using `define`
- User-defined functions
- Function calls with parameters
- Nested expressions
- Basic error handling
- Interactive REPL

---

## Example Usage

```
(define x 10)
(+ x 5)
=> 15

(define (double n) (* n 2))
(double 6)
=> 12

(define (square n) (* n n))
(square 5)
=> 25

(+ (double 4) (square 3))
=> 17
```

---

## How to Compile

```
g++ -std=c++17 main.cpp tokenizer.cpp parser.cpp -o lisp
```

---

## How to Run

```
./lisp
```

---

## Project Structure

```
lisp-interpreter/
│── main.cpp
│── tokenizer.cpp
│── tokenizer.h
│── parser.cpp
│── parser.h
│── README.md
│── .gitignore
```

---

## Future Improvements
- Improved error handling and messages
- Support for conditionals (if)
- Recursion support for functions
- Additional LISP features

---

## Author
Dustin Patton
