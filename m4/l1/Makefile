
# BIKE reference and optimized implementations assume that OpenSSL and NTL libraries are available in the platform.

# To compile this code for NIST KAT routine use: make bike-nist-kat
# To compile this code for demo tests use: make bike-demo-test

# TO EDIT PARAMETERS AND SELECT THE BIKE VARIANT: please edit defs.h file in the indicated sections.

# The file measurements.h controls how the cycles are counted. Note that #define REPEAT is initially set to 100, 
# which means that every keygen, encaps and decaps is repeated 100 times and the number of cycles is averaged.

# Verbose levels: 0, 1, 2 or 3
VERBOSE=0

CC:=gcc
CFLAGS:=-m64 -O3 -std=c11 #-pg -g -fsanitize=address




INCLUDE:= -I./extra_files -I./src -I$(OpenSSL)/include -L$(OpenSSL)/lib

LD	= gcc
LDFLAGS = -lcrypto -lssl -lm -ldl -lpthread -lntl -lgmp  #-lasan


SRC:= $(wildcard src/*.c )
SRCOBJS = $(SRC:.c=.o)

OBJS = $(SRCOBJS:src/%=%)


## OBJ	= rot_right-m4speed.o
## OBJ	= transpose-m4speed.o
## OBJ	= keygen-m4test.o
## OBJ	= encdec-m4test.o
## OBJ	= sampling-m4test.o



all: bike-demo-test




bike-demo-test: $(SRC) tests/test.c
	$(CC) $(CFLAGS) $(INCLUDE) -DVERBOSE=$(VERBOSE) -DNIST_RAND=1 -o $@ $^ $(LDFLAGS)

#bike-demo-test: $(OBJS) tests/test.c
#	$(CC) $(CFLAGS) $(INCLUDE) -DVERBOSE=$(VERBOSE) -DNIST_RAND=1 -o $@ $^ $(LDFLAGS)


%-test: tests/%-test.c $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS)

$(LIBMUL): $(MULOBJS)
	ar -rcs $@ $^

%.o: m4speed/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

%.o: $(MULLIB)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<


%.o: src/%.c
	$(CC) $(CFLAGS) -DVERBOSE=$(VERBOSE) $(INCLUDE) -o $@ -c $<

%.o: %.c
	$(CC) $(CFLAGS) -DVERBOSE=$(VERBOSE) $(INCLUDE) -o $@ -c $<


ARMCC = arm-none-eabi-gcc
ARMARCH = -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARMCFLAG = -O3 -Wall -Wextra -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes -Wundef -Wshadow

%.S: %.c
	$(ARMCC) $(ARMARCH) $(ARMCFLAG) -S -c $< -o $@



clean:
	rm -f PQCkemKAT_*
	rm -f bike-demo-test
	rm *-test *.o
