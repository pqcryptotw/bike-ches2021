
# BIKE reference and optimized implementations assume that OpenSSL and NTL libraries are available in the platform.

# To compile this code for NIST KAT routine use: make bike-nist-kat
# To compile this code for demo tests use: make bike-demo-test

# TO EDIT PARAMETERS AND SELECT THE BIKE VARIANT: please edit defs.h file in the indicated sections.

# The file measurements.h controls how the cycles are counted. Note that #define REPEAT is initially set to 100, 
# which means that every keygen, encaps and decaps is repeated 100 times and the number of cycles is averaged.

# Verbose levels: 0, 1, 2 or 3
VERBOSE=0

CC:=g++
CFLAGS:=-m64 -O3

SRC:= $(wildcard src/*.c)
INCLUDE:=-I. -I./extra_files -I./src -I$(OpenSSL)/include -L$(OpenSSL)/lib -std=c++11 -lcrypto -lssl -lm -ldl -lpthread -lntl -lgmp

all: bike-demo-test

bike-demo-test: $(SRC) tests/test.c
	$(CC) $(CFLAGS) tests/test.c $(SRC) $(INCLUDE) -DVERBOSE=$(VERBOSE) -DNIST_RAND=1 -o $@

bike-nist-kat: $(SRC) *.h FromNIST/*.h FromNIST/PQCgenKAT_kem.c
	$(CC) $(CFLAGS) FromNIST/PQCgenKAT_kem.c $(SRC) $(INCLUDE) -DVERBOSE=$(VERBOSE) -DNIST_RAND=1 -o $@

clean:
	rm -f PQCkemKAT_*
	rm -f bike-demo-test

