# Repo.: freefem\_class\_examples

## Description
Some examples about adding user-defined C++ classes to FreeFem++.

This repository was made to show and explain how one can embed some C++ code within FreeFem++ (itself being built on C++). The main idea is to code in C++, then to call functions and object code from FreeFem++.

FreeFem++ can be found at the following adress : [http://www.freefem.org](http://www.freefem.org) 

For those using FreeFem++ for scientific work, information is provided on FreeFem++ website for citing the team that created the code.

# Table of Content

* [Introduction](#intro)
* [Adding a class](#class)
* [Adding an array of classes](#array_of_class)

<a name="intro"></a>
## Introduction

The exemples are located in different folders. Description of the working of the code content is a work in progress.

The examples shown in this tutorial are still very basic.

One should be aware that FreeFem++ already offers many possibilities that bypass the need for classes.

Each class is provided with a basch script `.sh` to compile the C++ code into a dynamic library `.dylib` that is read by FreeFem++ to load the class in the main FreeFem++ code (`load.edp` for isntance).

<a name="class"></a>
## Adding a class

Describe how to add a class of simple standard types to FreeFem :

- class_d : for a class with an attribute of type `double`
- class_str : for a class with an attribute of type `str`

## Adding an array of classes

Describe how to add an array of a class called `A`  to FreeFem :

- class_a : defines class a and the array of class a.

Work in progress : use the KN\<T\> FreeFem object to make the array.
 
