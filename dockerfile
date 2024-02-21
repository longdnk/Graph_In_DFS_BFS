# Get the GCC preinstalled image from Docker Hub
FROM gcc:11.4.0

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . .

# Use GCC to compile the Test.cpp source file
RUN g++ app/find.cpp -std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops -unroll-loops -o app/find

# Run the program output from the previous step
CMD ["./app/find"]
