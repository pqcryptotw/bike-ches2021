
# BIKE KEM implenetations for x86 AVX2 instruction set.

This is the x86 implementation of BIKE KEM based on the CHES 2021 paper
``Optimizing BIKE for the Intel Haswell and ARM Cortex-M4''.

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
  'cp -r crypto_kem  **SUPERCOP_DIR**/crypto_kem'  
3. Benchmarking on SUPERCOP  
  'do-part used'  
  'do-part crypto_kem bikel1'  
  'do-part crypto_kem bikel3'  
4. The results are stored in benchmark/*/data .


