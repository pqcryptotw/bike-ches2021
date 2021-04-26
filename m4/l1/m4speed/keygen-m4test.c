

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"

#include "crypto_kem.h"
#include "debug.h"
#include "api.h"


#define SIZE_DATA1  ( CRYPTO_PUBLICKEYBYTES )
#define SIZE_DATA2  ( CRYPTO_SECRETKEYBYTES )




unsigned char data1[SIZE_DATA1] = {0};
unsigned char data2[SIZE_DATA2] = {0};


void init_data()
{
  for(int i=0;i<sizeof(data1);i++) data1[i] = i;
  for(int i=0;i<sizeof(data2);i++) data2[i] = i;
}



///////////////////////////////////////////////


const char * speed1_name = "crypto_kem_keypair()";

const char * speed2_name = "dummy";



int speed1()
{
  crypto_kem_keypair(data1,data2);

  return 0;
}


int speed2()
{

  return 0;
}


///////////////////////////////////////////////////////

const char * test1_name = "crypto_kem_keypair(pk,sk)";

const char * test2_name = "pk==x86-pk, sk==x86-sk";




int test1()
{
  int r = crypto_kem_keypair(data1,data2);
  return r;
}


static
uint8_t cmp_eq( const uint8_t *v1, const uint8_t *v2, unsigned len )
{
  uint8_t r = 0;
  for(unsigned i=0;i<len;i++) r |= v1[i]^v2[i];
  return 0==r;
}


int test2()
{
  uint8_t r_pk = cmp_eq( bike_pk , data1 , sizeof(bike_pk) );
  uint8_t r_sk = cmp_eq( bike_sk , data2 , sizeof(bike_sk) );

  return r_pk&&r_sk;
}

