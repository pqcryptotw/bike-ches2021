



#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stdio.h"
#include "stdint.h"


#include "crypto_kem.h"
#include "api.h"





void print_u8(const unsigned char *data, unsigned len )
{
	for(unsigned i=0;i<len;i++) {
		//if( 0 == (i&7) ) printf("%8d: ",i);
		printf("0x%02x,", data[i] );
		if( 3 == (i&3) ) printf(" ");
		if( 7 == (i&7) ) printf(" ");
		if( 15 == (i&15) ) printf("\n");
	}
}






int main()
{

	unsigned char pk[ CRYPTO_PUBLICKEYBYTES ];
	unsigned char sk[ CRYPTO_SECRETKEYBYTES ];

	//for(int i=0;i<32;i++) seed[i] = 0;
	//key_gen(pk, sk, seed );
	int r = crypto_kem_keypair( pk , sk );
	printf("kem_keypar()->%d.\n\n", r );

	printf("const uint8_t bike_sk[%ld] = {\n", CRYPTO_SECRETKEYBYTES );
	print_u8(sk,CRYPTO_SECRETKEYBYTES);
	printf("};\n\n");

	printf("const uint8_t bike_pk[%ld] = {\n", CRYPTO_PUBLICKEYBYTES );
	print_u8(pk,CRYPTO_PUBLICKEYBYTES);
	printf("};\n\n");

	return 0;
}

