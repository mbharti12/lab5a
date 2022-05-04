CXX=g++
#CXX=clang++
CXXFLAGS=-g
BINARIES=testWordCount WordCount

all: testWordCount
	./testWordCount

testWordCount: testWordCount.o WordCount.o tddFuncs.o
	${CXX} $^ ${CXXFLAGS} -o $@

clean:
	/bin/rm -f ${BINARIES} *.o