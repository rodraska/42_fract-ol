42_fract-ol is a project developed in C for 42 School.

Its objective was to create computer graphics for the Mandelbrot set and the Julia set using the school graphical library: MiniLibX.

The Mandelbrot set is the set of complex numbers c for which the function f(z) = z^2 + c does not diverge to infinity when iterated from z=0.
For each pixel of the graphical window, I calculate its respective coordinates in the complex plane and iterate the mandelbrot function n times. If the absolute function value is below 2 at the end of the n iterations, it belongs to the mandelbrot set and I paint the pixel with the color black. If the absolute function value rises above 2, I paint the pixel accordingly to the number of iterations it took for it happen. 


