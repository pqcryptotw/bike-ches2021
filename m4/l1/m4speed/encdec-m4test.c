

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"

#include "crypto_kem.h"
#include "debug.h"
#include "api.h"


#define SIZE_DATA1  ( CRYPTO_CIPHERTEXTBYTES )
#define SIZE_DATA2  ( CRYPTO_BYTES )




unsigned char data1[SIZE_DATA1] = {0};
unsigned char data2[SIZE_DATA2] = {0};


void init_data()
{
  for(int i=0;i<sizeof(data1);i++) data1[i] = i;
  for(int i=0;i<sizeof(data2);i++) data2[i] = i;
}



///////////////////////////////////////////////


const char * speed1_name = "crypto_kem_encap()";

const char * speed2_name = "crypto_key_decap()";



int speed1()
{
  crypto_kem_enc(data1,data2,bike_pk);

  return 0;
}


int speed2()
{
  crypto_kem_dec(data2,bike_ct,bike_sk);

  return 0;
}


///////////////////////////////////////////////////////

#define _DEC_

#if defined(_DEC_)
const char * test1_name = "crypto_kem_dec()";
const char * test2_name = "ss==x86-ss";
#else
const char * test1_name = "crypto_kem_enc()";
const char * test2_name = "ss==x86-ss, ct==x86-ct";
#endif



int test1()
{
#if defined(_DEC_)
  int r = crypto_kem_dec(data2,bike_ct,bike_sk);
#else
  int r = crypto_kem_enc(data1,data2,bike_pk);
#endif
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
#if defined(_DEC_)
  uint8_t r_ss = cmp_eq( data2 , bike_ss1 , sizeof(bike_ss1) );
#else
  uint8_t r_ss = cmp_eq( data2 , bike_ss0 , sizeof(bike_ss0) );
  uint8_t r_ct = cmp_eq( bike_ct , data1 , sizeof(bike_ct) );
#endif
  return r_ss;
}

