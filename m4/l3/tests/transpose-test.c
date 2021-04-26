
//#include "randombytes.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>


#include "stdio.h"
#include "stdint.h"


void print_u8(const unsigned char *data, unsigned len )
{
	for(unsigned i=0;i<len;i++) {
		if( 0 == (i&15) ) printf("%3d: ",i);
		printf("%02x,", data[i] );
		if( 3 == (i&3) ) printf(".");
		if( 7 == (i&7) ) printf(" ");
		if( 15 == (i&15) ) printf("\n");
	}
}


void print_u16(const uint16_t *data, unsigned len )
{
	for(unsigned i=0;i<len;i++) {
		if( 0 == (i&7) ) printf("%3d: ",i);
		printf("0x%04x,", data[i] );
		if( 3 == (i&3) ) printf(" ");
		if( 7 == (i&7) ) printf("\n");
	}
}



void print_u32(const uint32_t *data, unsigned len )
{
	for(unsigned i=0;i<len;i++) {
		if( 0 == (i&7) ) printf("%3d: ",i);
		printf("0x%08x,", data[i] );
		if( 3 == (i&3) ) printf(" ");
		if( 7 == (i&7) ) printf("\n");
	}
}



uint8_t check_eq( const uint8_t *vec0, const uint8_t *vec1, unsigned len)
{
	uint8_t diff = 0;
	for(unsigned i=0;i<len;i++){
		diff |= vec0[i]^vec1[i];
//		if(diff) {
//			printf("neq: %dbyte: %x:%x\n",i, vec0[i], vec1[i] );
//			return diff == 0;
//		}
	}
	return diff==0;
}



#include "btfy.h"
#include "transpose.h"
#include "randombytes.h"


#define TEST_RUN 1000


//#define TESTSPEED

#ifdef TESTSPEED
#include "benchmark.h"
#endif





int main()
{

	uint32_t vec0[32];
	uint32_t vec1[32];
	uint32_t vec2[32];
	uint32_t vec3[32];
	//uint32_t vec4[32];
	//uint32_t vec5[32];

	uint8_t eq = 1;

#ifdef TESTSPEED
struct benchmark bm0;
bm_init(&bm0);
#endif


	printf("transpose 32x32 test:\n");
	for(int i=1;i<=TEST_RUN;i++) {
		randombytes( vec0 , sizeof(vec0) );
		if(0==i) for(int j=0;j<sizeof(vec0)/sizeof(uint32_t);j++) vec0[j]=0xff;

		memcpy( (void*)vec1 , (void*)vec0 , sizeof(vec0) );
#ifdef TESTSPEED
BENCHMARK( bm0, {
#endif
		transpose_32x32_in( vec1 );
#ifdef TESTSPEED
} );
#endif
		memcpy( (void*)vec2 , (void*)vec0 , sizeof(vec0) );
		transpose_32x32_in2( vec2 );

		if(0==i) {
			print_u32( vec0, 32 );
			printf("->\n");
			print_u32( vec1 , 32 );
		}

		if( !check_eq( (uint8_t*)vec2 , (uint8_t*)vec1 , sizeof(vec0) ) ) {
			print_u32( vec0, 32 );
			printf("->\n");
			print_u32( vec1 , 32 );
			printf("<-\n");
			print_u32( vec2 , 32 );
			eq = 0;
			break;
		}
	}
	printf("\ntest %s.\n\n", (eq)?"PASS":"FAIL");




#ifdef TESTSPEED
char bmmsg[256];
bm_dump(bmmsg,sizeof(bmmsg),&bm0);
printf("benchmark:\n%s\n", bmmsg );
#endif


	return 0;
}

