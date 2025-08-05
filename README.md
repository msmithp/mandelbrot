# mandelbrot


## How to Build

The following instructions detail how to build the project on a 64-bit Windows system using MinGW32.

1. Make a build directory:

    ```
    mkdir build
    cd build
    ```

2. Run `cmake`:

    ```
    cmake .. -G"MinGW Makefiles" -B .
    ```

3. Run `make` using MinGW32:

    ```
    mingw32-make
    ```

4. Run the executable:

    ```
    mandelbrot
    ```