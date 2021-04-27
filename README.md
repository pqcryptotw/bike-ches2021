
# BIKE KEM implenetations

This project contains the implementations of BIKE KEM based on the CHES 2021 paper
``Optimizing BIKE for the Intel Haswell and ARM Cortex-M4''.


BIKE is a KEM submission to the
[Post-Quantum Cryptography Standardization project](http://csrc.nist.gov/projects/post-quantum-cryptography).
The (original) official BIKE website is: https://bikesuite.org.

## Authors

Ming-Shing Chen, Tung Chou, and Markus Krausz

## Licence

The implementations are modified from the BIKE team's original implementations(https://github.com/awslabs/bike-kem).  


The original implementation is licensed under the Apache-2.0 License.  
The modified files are under the same Apache-2.0 licence.  
Additional files excluded from the original implementation are in public domain.  



## Contents

There are 2 directories:

- **x86** : implementations for x86 AVX2 instruction set and SUPERCOP(https://bench.cr.yp.to/supercop.html) environment.
- **m4**  : implementations for ARM Cortex M4 and PQM4(https://github.com/mupq/pqm4) environment.


### **x86**

#### Instructions for benchmarking on SUPERCOP
1. Download and setup the SUPERCOP (https://bench.cr.yp.to/supercop.html).
2. Copy the crypto_kem/ to SUPERCOP:  
  'cp -r crypto_kem/  **supercop**/crypto_kem/bikel1'  
3. Benchmarking on SUPERCOP  
  'do-part used'  
  'do-part crypto_kem bikel1'  
  'do-part crypto_kem bikel3'  
4. The results are stored in benchmark/*/data .


### **m4**

#### Contents

There are 4 directories:

- **l1** : BIKE level 1, this work, modified from BIKE team's portable version.
- **l3** : BIKE level 3, this work, modified from BIKE team's portable version.
- **portablel1** : BIKE team's portable implementation for level 1, modified and compatible with PQM4. The directory is **NOT** part of 
  our implementation but for bencharmking only. Please do not include the directory in the final version.  
- **portablel3** : BIKE team's portable implementation for level 3, modified and compatible with PQM4. The directory is **NOT** part of 
  our implementation but for bencharmking only. Please do not include the directory in the final version.  


#### Instructions for benchmarking on PQM4
1. Download and setup benchmarking environment for PQM4 from https://github.com/mupq/pqm4 .
2. Copy the *imple*/src directory to  *pqm4*/crypto_kem/*your_desired_name*/ . For example,  
  'cp -r l1/src  pqm4/crypto_kem/bikel1'  (assuming the PQM4 is installed in the *pqm4* directory.)
3. Use standard tester on PQM4 for the implementation you copied. For example, in the *pqm4* directory, execute  
  'python3 test.py'  
  or  
  'make IMPLEMENTATION_PATH=crypto_kem/bikel1 bin/crypto_kem_bikel1_speed.bin; st-flash write bin/crypto_kem_bikel1_speed.bin 0x8000000' .  
  Then collect benchmark results from the UART port of your M4 board with tools from PQM4 .




