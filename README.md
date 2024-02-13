# cpp-homework
## Table of Contents
- [Task](#task)
- [How to Use](#how_to_use)

## Task
Given an image consisting of MxN pixels. The top-left coordinate of the image is the starting point in space (S). Each pixel is square-shaped with side length a.
From an arbitrary point F, we emit rays towards multiple points D0, D1, D2... Dn.
The task is to determine which (i, j) pixel of the image the ray intersects and the distance traveled in these pixels.

Create a C++ library that calculates the coordinates of the pixels intersected by the ray and the distance traveled in the image. Write the calculated distances and points to a file.
The system's geometry (M, N, a, S) can be entered from the console window, followed by any point F and D.
During the work, only use the C++ STL library.

## How to Use <a name="how_to_use"></a>
1. Start the project.
2. Enter the necessary information for the simulation to be run.
3. (Optional)Add a custom filepath for the output to be written to. The default is the output.txt file in the output folder.
4. The size of a cell can be fractional number, but it can't be negative. Picture width and height represent the number of cells the picture takes up and can only be whole, positive (or zero) numbers.
5. The target points the rays travel to can be both to the "left" or "right" of the point emitting the ray.
6. The visited cells logged in the output file are logged in order, and each cell is only logged once per ray. 
