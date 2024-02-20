FROM ubuntu:22.04
# Copy app source code
COPY . .
# RUN CONFIG
RUN echo "*************START*****************"
RUN apt update
RUN apt install g++ -y
RUN echo "*************CHECK_CPP_VERSION*****************"
RUN g++ --version
RUN echo "*************END_CHECK_CPP_VERSION*****************"
RUN g++ app/find.cpp -std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops -unroll-loops -o app/find
RUN app/find < app/in
WORKDIR app/
RUN chmod u+x sample.sh
RUN ["./sample.sh"]