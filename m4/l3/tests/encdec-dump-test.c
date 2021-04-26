



#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stdio.h"
#include "stdint.h"


#include "crypto_kem.h"
#include "api.h"
#include "debug.h"




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

	unsigned char shared_secret0[ CRYPTO_BYTES ];
	unsigned char shared_secret1[ CRYPTO_BYTES ];
	unsigned char cipher_text[ CRYPTO_CIPHERTEXTBYTES ];

	int r = crypto_kem_enc( cipher_text, shared_secret0,  bike_pk );
	printf("kem_enc()->%d.\n\n", r );

	printf("const uint8_t bike_ss0[%ld] = {\n", CRYPTO_BYTES );
	print_u8(shared_secret0,CRYPTO_BYTES);
	printf("};\n\n");

	printf("const uint8_t bike_ct[%ld] = {\n", CRYPTO_CIPHERTEXTBYTES );
	print_u8(cipher_text,CRYPTO_CIPHERTEXTBYTES);
	printf("};\n\n");

	r = crypto_kem_dec(  shared_secret1 , cipher_text,  bike_sk );
	printf("kem_dec()->%d.\n\n", r );

	printf("const uint8_t bike_ss1[%ld] = {\n", CRYPTO_BYTES );
	print_u8(shared_secret0,CRYPTO_BYTES);
	printf("};\n\n");

	return 0;
}

