# CPP Module 05 – Bureaucrats, Grades & Forms: OOP in Action

## Table of Contents

1. [Project Overview](#project-overview)
2. [Key Concepts Introduced](#key-concepts-introduced)
   - [Exception Handling](#exception-handling)
   - [Class Invariants](#class-invariants)
   - [Operator Overloading](#operator-overloading)
   - [Abstract Interfaces](#abstract-interfaces)
3. [Exercise Breakdown](#exercise-breakdown)
   - [Ex00: Bureaucrat Basics](#ex00-bureaucrat-basics)
   - [Ex01: Introducing Forms](#ex01-introducing-forms)
   - [Ex02: More Responsibilities](#ex02-more-responsibilities)
   - [Ex03: The Intern](#ex03-the-intern)
4. [Compiling and Running](#compiling-and-running)
5. [Conclusion & What’s Next](#conclusion--whats-next)

---

## Project Overview

CPP05 simulates a bureaucratic system with multiple object types:

- A `Bureaucrat` class with strict grade rules
- Abstract `Forms` that need signing and execution
- And finally, an `Intern` that dynamically creates the appropriate form.

This module emphasizes **encapsulation, polymorphism, and exception safety** in a cohesive design.

---

## Key Concepts Introduced

### Exception Handling

We define custom exceptions using `class MyException : public std::exception`, then override `what()` to return a custom message. This allows precise control over error handling:

```cpp
class GradeTooHighException : public std::exception {
public:
    const char* what() const throw();
};
```

### Class Invariants

We enforce **valid object state** through constructor checks and guarded setters. For example:

- Grade must always be between 1 and 150
- Violations trigger exceptions

This is an example of **defensive programming**, ensuring no invalid Bureaucrat or Form can exist.

### Operator Overloading

The `<<` operator is overloaded to allow printing of class instances:

```cpp
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
```

### Abstract Interfaces

The class `AForm` contains pure virtual functions like `execute()`, requiring derived classes to implement specific behaviors.

```cpp
class AForm {
public:
    virtual void execute(Bureaucrat const & executor) const = 0;
};
```

This sets a clear contract for child forms, like `ShrubberyCreationForm`.

---

## Exercise Breakdown

### Ex00: Bureaucrat Basics

**Goal:** Implement a class with a `name` and a `grade`, plus increment/decrement functions.

**We learn:**

- Exception design
- Input validation through constructor checks
- Use of overloaded `<<` for cleaner logging

### Ex01: Introducing Forms

**Goal:** Create an abstract form class that can be signed by a `Bureaucrat`.

**We learn:**

- Object dependencies (a Bureaucrat can interact with a Form)
- Abstract class design: `AForm` can't be instantiated directly
- Encapsulation of access permissions and validation rules

### Ex02: More Responsibilities

**Goal:** Implement actual form types that inherit from `AForm` and perform real actions.

- `ShrubberyCreationForm`: creates a file with ASCII trees
- `RobotomyRequestForm`: random success/failure action
- `PresidentialPardonForm`: prints a pardon message

**We learn:**

- Polymorphism via `execute()`
- Separation of concerns through class specialization

### Ex03: The Intern

**Goal:** The `Intern` class can generate different forms by name.

**We learn:**

- Factory method pattern
- Avoiding `if/else` trees with function pointers or parallel arrays
- Clean abstraction for object creation logic

---

## Compiling and Running

1. Navigate to an exercise folder:

```sh
cd ex03
```

2. Compile:

```sh
make
```

3. Run:

```sh
./bureau
```

4. Clean up:

```sh
make clean
make fclean
make re
```

---

## Conclusion & What’s Next

CPP05 gives us a taste of how to model real-world rules and constraints in code:

- Strong **data validation**
- Effective use of **exceptions**
- **Abstract classes** that define behavior contracts
- Applying the **factory pattern** to create decoupled logic

Up next in **CPP06**, we’ll dive into **casting**, the **standard library**, and more modern C++ idioms.

