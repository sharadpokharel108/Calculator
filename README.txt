Calculator Project - README

Welcome to the Calculator Project!

To compile and run this project, you'll need to set up the MinGW compiler and the raylib library. Follow the steps below to get started:

Step 1: Download and Install MinGW Compiler.
-------------------------------------------
1. Go to the MinGW official website: https://osdn.net/projects/mingw/
2. Download the installer (mingw-get-setup.exe) from the "Downloads" section.
3. Run the installer and follow the on-screen instructions to complete the installation.
4. During installation, make sure to select the necessary components like the C and C++ compilers.

Step 2: Download and Install raylib Library.
--------------------------------------------
1. Go to the raylib official website: https://www.raylib.com/
2. Navigate to the "Download" section.
3. Choose the appropriate version for your platform and download the raylib ZIP file.
4. Extract the contents of the ZIP file to a location on your computer.

Step 3: Compiling and Running the Calculator
--------------------------------------------
1. Open a terminal or command prompt.
2. Navigate to the directory where you've saved the calculator project files.
3. Compile the project using the following command:
   g++ -o calculator.exe calc.cpp -Ipath_to_raylib\include -Lpath_to_raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -std=c++11
   (Replace "path_to_raylib" with the actual path where you extracted raylib.)

		or 
3. Go to C:\raylib\w64devkit then run w64devkit.exe and navigate to the directory where you've saved the calculator project files.
   Now run the command:g++ calc.cpp -lraylib -lopengl32 -lgdi32 -lwinmm -o calculator

4. Run the compiled executable using the command:
   calculator.exe

That's it! You should now have the calculator application up and running.

Feel free to explore the source code, make modifications, and enjoy the functionality of the calculator.

For any questions or issues, refer to the README file or contact us at shrdpokharel@gmail.com.

Happy coding!
