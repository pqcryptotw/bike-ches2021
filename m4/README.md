
# BIKE KEM implenetations on Arm Cortex-M4

This is an ARM Cortex-M4 implementation of BIKE KEM based on the CHES 2021 paper
``Optimizing BIKE for the Intel Haswell and ARM Cortex-M4''.

## Authors

Ming-Shing Chen, Tung Chou, and Markus Krausz

## Licence

The implementations are modified from the ``crypto_kem/bikel1/portable'' implementation in supercop-20200906 (https://bench.cr.yp.to/supercop.html).
The original software are released under Apache-2.0 licence.
The modified files are under the same Apache-2.0 licence.
Additional files excluded from the original implementation are in public domain.



## Contents

There are 4 directories:

- **l1** : BIKE level 1, this work, modified from BIKE team's portable version.
- **l3** : BIKE level 3, this work, modified from BIKE team's portable version.
- **portablel1** : BIKE team's portable implementation for level 1, modified and compatible with PQM4.
- **portablel3** : BIKE team's portable implementation for level 3, modified and compatible with PQM4.


## Instructions for benchmarking on PQM4
1. Download and setup benchmarking environment for PQM4 from https://github.com/mupq/pqm4 .
2. Copy the *imple*/src directory to  *pqm4*/crypto_kem/*your_desired_name*/ . For example,
  'cp -r l1/src  pqm4/crypto_kem/bikel1'  (assuming the PQM4 is installed in the *pqm4* directory.)
3. Use standard tester on PQM4 for the implementation you copied. For example, in the *pqm4* directory, execute
  'python3 test.py'
  or
  'make IMPLEMENTATION_PATH=crypto_kem/bikel1 bin/crypto_kem_bikel1_speed.bin; st-flash write bin/crypto_kem_bikel1_speed.bin 0x8000000' .
  Then collect benchmark results from the UART port of your M4 board with tools from PQM4 .



