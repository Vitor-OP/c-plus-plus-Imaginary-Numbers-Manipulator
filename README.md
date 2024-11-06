# Imaginary Numbers Manipulator

This is a very simple project with the pedagogic objective of practicing the basics of C++.  
The project includes two classes, `Complex` and `Phasor`, which represent imaginary numbers in two different formats and are direct correspondents of one another in imaginary numbers math.

- **`Complex`**: Represents imaginary numbers in rectangular form as `a + bj`, where `j` is the square root of `-1`. This form can be understood as a two-dimensional vector, where `a` and `b` are the real and imaginary components, respectively.
- **`Phasor`**: Represents imaginary numbers in polar form as `magnitude ∠ angle` or `r ∠ θ`, where `magnitude` is the length of the vector and `angle` is its orientation in the complex plane. The `Phasor` form allows an alternative view of the imaginary number and is directly convertible to and from the `Complex` form.

## Features

- **Conversion between forms**: Seamless conversion between `Complex` and `Phasor` forms.
- **Basic arithmetic operations**: Addition, subtraction, multiplication, and division operations for both `Complex` and `Phasor` numbers.
- **Display options**: The `Complex` form is displayed as `a + bj`, while the `Phasor` form is displayed as `magnitude ∠ angle` (in degrees or radians).

## Getting Started

To compile and run this project, you need a C++ compiler.

### Compilation
```bash
g++ -o imaginary_numbers main.cpp complex.cpp phasor.cpp
