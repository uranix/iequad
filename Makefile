CXX=g++
CXXFLAGS= -std=c++11 -O3

TARGETS=main main2 main3 quad

all: ${TARGETS}

clean:
	rm -f ${TARGETS}
