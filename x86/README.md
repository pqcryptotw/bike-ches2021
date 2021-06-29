
# BIKE KEM implenetations for x86 AVX2 instruction set.

This is the x86 implementation of BIKE KEM based on the CHES 2021 paper: 
**Optimizing BIKE for the Intel Haswell and ARM Cortex-M4** (https://eprint.iacr.org/2021/493).

## Authors

Ming-Shing Chen, Tung Chou, and Markus Krausz

## Licence

The implementations are modified from the BIKE team's original implementations(https://github.com/awslabs/bike-kem).


The original implementation is licensed under the Apache-2.0 License.  
The modified files are under the same Apache-2.0 licence.  
Additional files excluded from the original implementation are in public domain.


## Instructions for benchmarking on SUPERCOP
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
