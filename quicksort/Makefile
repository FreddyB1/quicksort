
GPP = g++
GCC = gcc
QUICKSORT_OUTFILE = "../quicksort.so"

COMPILE_FLAGS = -m32 -fPIC -c -O2 -w -D LINUX -D PROJECT_NAME=\"quicksort\" -I ./SDK/amx/

QUICKSORT = -D QUICKSORT $(COMPILE_FLAGS)

all: QUICKSORT

clean:
	-rm -f *~ *.o *.so

QUICKSORT: clean
	$(GPP) $(QUICKSORT) ./SDK/amx/*.c
	$(GPP) $(QUICKSORT) ./SDK/*.cpp
	$(GPP) $(QUICKSORT) *.cpp
	$(GPP) -m32 -O2 -fshort-wchar -shared -o $(QUICKSORT_OUTFILE) *.o
	rm *.o
