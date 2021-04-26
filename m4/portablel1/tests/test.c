/******************************************************************************
 * BIKE -- Bit Flipping Key Encapsulation
 *
 * Copyright (c) 2017 Nir Drucker, Shay Gueron, Rafael Misoczki
 * (drucker.nir@gmail.com, shay.gueron@gmail.com, rafael.misoczki@intel.com)
 *
 * Permission to use this code for BIKE is granted.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * The names of the contributors may not be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ""AS IS"" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS CORPORATION OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#include "stdio.h"

#define MSG printf

#include "crypto_kem.h"
#include "utilities.h"
#include "measurements.h"

#include "types.h"



#define NUM_OF_CODE_TESTS 10
#define NUM_OF_ENCRYPTION_TESTS 10
#define SUCCESS 0

////////////////////////////////////////////////////////////////
//                 Main function for testing
////////////////////////////////////////////////////////////////
int main(void)
{
    sk_t sk    = {0}; // private-key: (h0, h1)
    pk_t pk    = {0}; // public-key:  (g0, g1)
    ct_t ct    = {0}; // ciphertext:  (c0, c1)
    ss_t k_enc = {0}; // shared secret after encapsulate
    ss_t k_dec = {0}; // shared secret after decapsulate

    MSG("BIKE Demo Test:\n");

    for (uint32_t i=1; i <= NUM_OF_CODE_TESTS; ++i)
    {
        uint32_t res = SUCCESS;

        MSG("r: %d Code test: %d \n", (int) R_BITS, i);
        //Key generation.
        MEASURE("  keygen", res =  (crypto_kem_keypair(pk.raw, (unsigned char*)&sk)););

        if(res != SUCCESS)
        {
            MSG("Keypair failed with error: %d\n", res);
            continue;
        }

        for (uint32_t j=1; j <= NUM_OF_ENCRYPTION_TESTS; ++j)
        {
            //MSG("Enc/Dec test: %d\n", j);
            uint32_t dec_rc = 0;

            //Encapsulate
            MEASURE("  encaps", res =  (crypto_kem_enc((unsigned char*)&ct, k_enc.raw, pk.raw)););

            if(res != SUCCESS)
            {
                MSG("encapsulate failed with error: %d\n", res);
                continue;
            }

            //Decapsulate
            MEASURE("  decaps", dec_rc = crypto_kem_dec(k_dec.raw, (unsigned char*)&ct, (unsigned char*)&sk););

            if (dec_rc != 0)
            {
                MSG("Decoding failed after %d code tests and %d enc/dec tests!\n", i, j);
            }
            else
            {
                if (secure_cmp(k_enc.raw, k_dec.raw, sizeof(k_dec)/sizeof(uint64_t)))
                {
                    MSG("Success! decapsulated key is the same as encapsulated key!\n");
                } else {
                    MSG("Failure! decapsulated key is NOT the same as encapsulated key!\n");
                }
            }

            print("Initiator's generated key (K) of 256 bits = ",(uint64_t*)k_enc.raw, SS_BYTES*8);
            print("Responder's computed key (K) of 256 bits  = ",(uint64_t*)k_dec.raw, SS_BYTES*8);
        }
    }

    return 0;
}
