
# BIKE KEM implenetations

This project contains the implementations of BIKE KEM based on the CHES 2021 paper:
**Optimizing BIKE for the Intel Haswell and ARM Cortex-M4** (https://eprint.iacr.org/2021/493).


BIKE is a KEM submission to the
[Post-Quantum Cryptography Standardization project](http://csrc.nist.gov/projects/post-quantum-cryptography).  
The (original) official BIKE website is: https://bikesuite.org.

## Authors

Ming-Shing Chen, Tung Chou, and Markus Krausz

## Licence

The implementations are modified from the BIKE team's original implementations(https://github.com/awslabs/bike-kem).  


The original implementation is licensed under the Apache-2.0 License.  
The modified files are under the same Apache-2.0 licence.  
Additional files excluded from the original implementation are in the public domain.  



## Contents

There are 2 directories:

- **x86** : implementations for x86 AVX2 instruction set and SUPERCOP(https://bench.cr.yp.to/supercop.html) environment.
- **m4**  : implementations for ARM Cortex M4 and PQM4(https://github.com/mupq/pqm4) environment.


## Instructions for benchmarks

### **x86**
1. Download and setup the SUPERCOP (https://bench.cr.yp.to/supercop.html).
2. Copy the crypto_kem/ to SUPERCOP:
```
cp -r crypto_kem  **SUPERCOP_DIR**/crypto_kem
```
3. Benchmarking on SUPERCOP:
   Please note that it would take about **10 hours** to initialize (i.e., `do-part used`) the SUPERCOP.
```
do-part used
do-part crypto_kem bikel1
do-part crypto_kem bikel3
```
4. Read results in `benchmark/*/data`.
  The line starting with `keypair_cycles`, `enc_cycles`, and `dec_cycles` reports the cycles counts for 3x32 measurements
  of key generation, encapsulation, and decapsulation respectively.
  The first number is the **median** of the measurements.
```
grep "keypair_cycles" ./data
grep "enc_cycles" ./data
grep "dec_cycles" ./data
```



+ The implementations are included in SUPERCOP with the path crypto_kem/bikel[1,3]/ches2021 since `supercop-20210424`.
+ We tested the implementations with `gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0`.





### **m4**
1. Download and setup benchmarking environment of PQM4 (https://github.com/mupq/pqm4) .
2. Copy the source code directory *l[1,3]*/src to PQM4 *pqm4*/crypto_kem/*bikel[1,3]*/ .
   Assuming the PQM4 is installed in the *~/pqm4* directory:
```
cp -r l1/src  ~/pqm4/crypto_kem/bikel1
```
3. Use standard tester on PQM4 for all implementations in PQM4:
   In the *~/pqm4* directory, execute
```
python3 test.py
```
  or benchmark **only** the *bikel1* KEM:
```
make IMPLEMENTATION_PATH=crypto_kem/bikel1 bin/crypto_kem_bikel1_speed.bin
st-flash write bin/crypto_kem_bikel1_speed.bin 0x8000000
```
4. Collect benchmark results from the *UART* port from your M4 development board.



+ The implementations are included in PQM4 with the path crypto_kem/bikel[1,3]/m4f since `commit 65f12c6c66f`.
+ We tested the implementations with
  1) `arm-none-eabi-gcc (GNU Arm Embedded Toolchain 10-2020-q4-major) 10.2.1 20201103 (release)`,
  2) `python3 --version: Python 3.8.5`, and
  3) `st-flash --version:  v1.5.1-47-g2901826`.





## Running as a standalone application
1. Add required/missing `.h` files in the implementation directory for compilers:
```
touch crypto_kem.h
touch randombytes.h
echo "#include <openssl/rand.h>" >> randombytes.h
echo "static inline void randombytes(unsigned char *out,unsigned l) {RAND_bytes(out,l);}" >> randombytes.h
```
2. Compile all `.c` files in the implementation directory for object files.
3. The key-generation, encapsulation, and decapsulation can be accessed with the function signatures:
```
int crypto_kem_keypair( unsigned char *pk, unsigned char *sk );
int crypto_kem_enc( unsigned char *c, unsigned char *k, const unsigned char *pk );
int crypto_kem_dec( unsigned char *k, const unsigned char *c, const unsigned char *sk );
```
4. Sizes of key-pairs, shared key, and ciphertext can be readed in `api.h`.



