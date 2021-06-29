
# BIKE KEM implenetations for x86 AVX2 instruction set.

This is the x86 implementation of BIKE KEM based on the CHES 2021 paper: 
**Optimizing BIKE for the Intel Haswell and ARM Cortex-M4** (https://eprint.iacr.org/2021/493).

## Authors

Ming-Shing Chen, Tung Chou, and Markus Krausz

## Licence

The implementations are modified from the ``crypto_kem/bikel1/portable'' implementation in supercop-20200906 (https://bench.cr.yp.to/supercop.html).  


The original implementation is licensed under the Apache-2.0 License.  
The modified files are under the same Apache-2.0 licence.  
Additional files excluded from the original implementation are in public domain.


## Contents

There are 4 directories:

- **l1** : BIKE level 1, this work, modified from BIKE team's portable version.  
- **l3** : BIKE level 3, this work, modified from BIKE team's portable version.  
- **portablel1** : BIKE team's portable implementation for level 1, modified and compatible with PQM4. The directory is **NOT** part of
  our implementation but for bencharmking only. Please do not include the directory in the final version.  
- **portablel3** : BIKE team's portable implementation for level 3, modified and compatible with PQM4. The directory is **NOT** part of 
  our implementation but for bencharmking only. Please do not include the directory in the final version.  


## Instructions for benchmarking on PQM4
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
