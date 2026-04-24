# LISP Interpreter (C++)

## Overview
This project is a simple LISP interpreter implemented in C++. It supports parsing and evaluating LISP-style expressions using prefix notation.

The interpreter demonstrates core concepts such as tokenization, recursive parsing, and expression evaluation.

---

## Features
- Tokenizes input expressions
- Parses nested LISP expressions
- Evaluates arithmetic operations:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
- Supports nested expressions
- Basic error handling

---

## Example Usage

(+ 2 3)
=> 5

(* 4 5)
=> 20

(+ 2 (* 3 4))
=> 14

(* (+ 1 2) (+ 3 4))
=> 21

(- (* 5 5) (+ 10 5))
=> 10

---

## How to Compile

g++ -std=c++17 main.cpp tokenizer.cpp parser.cpp -o lisp

---

## How to Run

./lisp

---

## Project Structure

lisp-interpreter/
│── main.cpp
│── tokenizer.cpp
│── tokenizer.h
│── parser.cpp
│── parser.h

---

## Milestone 1 Status
- Tokenizer implemented
- Parser implemented
- Arithmetic evaluation working
- Nested expressions supported

---

## Future Improvements
- Variable definitions using define
- User-defined functions
- Enhanced error handling
- Improved REPL interface

---

## Author
Dustin Patton
