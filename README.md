# Cassia_Fistula

## Introduction
First things first, the project is named after a leaf, because of my fond memories of a Herbarium project that I once assisted my elder brother with, back in school.This projects is a collection & implementation of some common design patterns in C++ as I learn them. I am using CMake as my build file generator so I could see how cmake handles library linking and include directory specifications. The project is aimed at exploring various design techniques which means I may be cutting corners to understand an idea... so you may find classes being declared in .cpp files or a "using namespace std" or even a #include <bits/stdc++.h>, as I try to focus on what's important.This readme guides you on..

1. Design pattern classifications, the idea remains same as the ones mentioned in the "Gang of Four".
2. Any project related info (Build or Directory Structure) which the author deems worth mentioning.

## Project Dependencies
- This project requires the following programs for it's functioning.
1. CMake (Version 3.14 and above)
2. GNU C++ Compiler (Version 7.4), This project was built on ubuntu 18.04 using the said compiler version.
3. 3rd Party Libraries ==> boost::DI | boost::program option. 


## Setup step
- This project is structured as a collection of many sub-projects (in their respective directories).
- Create a build directory. cd to it. use 'cmake -DCMAKE_BUILD_TYPE=Debug ..'


## work in progress:
This project is in active development, Contributions and criticisms are welcome.:-)

## Brief:
-Design patterns are common architectural approaches to solving problems, popularized by a book informally known as the "Gang of Four".
-GOF has examples in smalltalk and C++, This project aims to have those ideas and more implemented in modern C++.

## Programming Standard Followed.
-Uses Cpp 11/14
-Uses CMake for build file generation
-Classes are often defined inline (in cpp file)
-Pass by value everywhere
-Liberal namespace usage.

## SOLID Design Principals
## Dependency Injection
## Monads (outside GOF)

## SOLID
SINGLE RESPONSIBILITY -class should have only one reason to change.
OPEN CLOSE -class should be open for extension and close for modifications.
LISKOV'S SUBSTITUTION -
INTERFACE SEGREGATION
DEPENDENCY INVERSION
