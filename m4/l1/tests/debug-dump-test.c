



#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stdio.h"
#include "stdint.h"


#include "sampling.h"
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
  uint8_t seeds[ sizeof(seeds_t) ];
  uint8_t error[ sizeof(pad_e_t) ];
  int r = 0;

  get_seeds( (seeds_t *)seeds  );
  printf("get_seeds()->%d.\n\n", r );
  printf("const uint8_t bike_seeds[%ld] = {\n", sizeof(seeds) );
  print_u8( seeds , sizeof(seeds) );
  printf("};\n\n");

  r = generate_error_vector((pad_e_t *)error, (const seed_t *)seeds );
  printf("generate_error_vector()->%d.\n\n", r );
  printf("const uint8_t bike_error[%ld] = {\n", sizeof(error) );
  print_u8( error , sizeof(error) );
  printf("};\n\n");

	return 0;
}

