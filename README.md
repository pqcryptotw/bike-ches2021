
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






