#include <stdio.h>
#include <inttypes.h>

#define MWC_UPPER (mwc_upper=36969*(mwc_upper&65535)+(mwc_upper>>16))
#define MWC_LOWER (mwc_lower=18000*(mwc_lower&65535)+(mwc_lower>>16))
#define MWC ((MWC_UPPER<<16)+MWC_LOWER )
#define SHR3 (shr3^=(shr3<<13), shr3^=(shr3>>17), shr3^=(shr3<<5))
#define CONG (cong=69069u*cong+12345u)
#define FIB ((fib_b=fib_a+fib_b),(fib_a=fib_b-fib_a))
#define KISS ((MWC^CONG)+SHR3)
#define LFIB4 (c++,t[c]=t[c]+t[(uint8_t)(c+58)]+t[(uint8_t)(c+119)]+t[(uint8_t)(c+178)])
#define SWB (c++,swb_bro=(swb_x<swb_y),t[c]=(swb_x=t[(uint8_t)(c+34)])-(swb_y=t[(uint8_t)(c+19)]+swb_bro))

#define MWC64 (mwc64 = UINT64_C(698769069) * (uint32_t)mwc64 + (mwc64 >> 32u), (uint32_t)mwc64)
#define MWC64_SEED(SEED_C, SEED_Z) ((((uint64_t)(SEED_C)) << 32u) | (SEED_Z))
#define KISS2 (MWC64 + CONG + SHR3)

#define UNI (KISS*2.328306e-10)
#define VNI (((long) KISS)*4.656613e-10)

/* Global static variables: */
/* Use random seeds to reset mwc_upper,mwc_lower,shr3,cong,fib_a,fib_b, and the table t[256]*/
static uint32_t mwc_upper = 362436069, mwc_lower = 521288629;
static uint32_t shr3 = 362436000;
static uint32_t cong = 380116160;
static uint32_t fib_a = 224466889, fib_b = 7584631;
static uint32_t t[256];

static uint32_t swb_bro = 0;
static uint8_t c = 0;

static uint64_t mwc64 = MWC64_SEED(7654321, 521288629);

uint32_t swb_x = 0, swb_y = 0;

/* Example procedure to set the table, using KISS: */
void settable(uint32_t i1, uint32_t i2, uint32_t i3, uint32_t i4, uint32_t i5, uint32_t i6)
{
    mwc_upper = i1;
    mwc_lower = i2;
    shr3 = i3;
    cong = i4;
    fib_a = i5;
    fib_b = i6;
}

void init_t(void)
{
    unsigned int    i;

    for (i = 0; i < 256; i++)
    {
        t[i] = KISS;
    }
}

uint32_t MWC64func(void)
{
  static uint32_t z = 521288629;
  static uint32_t c = 7654321;
  uint64_t t;
  uint64_t a = UINT64_C(698769069);

  t = a * z + c;
  c = t >> 32;
  z = t;

  return z;
}

uint32_t KISS2func(void)
{
  static uint64_t mwc64 = MWC64_SEED(7654321, 521288629);
  static uint32_t cong = 123456789;
  static uint32_t shr3 = 362436000;

  return KISS2;
}

/* This is a test main program. It should compile and print 11 0's. */
int main (void)
{
    unsigned int    i;
    uint32_t        k;

    settable(12345, 65435, 34221, 12345, 9983651, 95746118);
    init_t();

/*
    for (i = 0; i < 256; i++)
    {
        printf("%"PRIu32"\n", t[i]);
    }
*/
/*
    for (i = 0; i < 256; i++)
    {
        printf("%"PRIu32"\n", LFIB4);
    }
*/
    for (i = 0; i < 1000000; i++)
    {
        k = LFIB4;
    }
    printf ("%"PRIu32"\n", k - 3673084687U);

    for (i = 0; i < 1000000; i++)
    {
        k = SWB;
    }
    printf ("%"PRIu32"\n", k - 319777393U);

    for (i = 0; i < 1000000; i++)
    {
        k = KISS;
    }
    printf ("%"PRIu32"\n", k - 2100035942U);

    for (i = 0; i < 1000000; i++)
    {
        k = CONG;
    }
    printf ("%"PRIu32"\n", k - 2416584377U);

    for (i = 0; i < 1000000; i++)
    {
        k = SHR3;
    }
    printf ("%"PRIu32"\n", k - 1153302609U);

    for (i = 0; i < 1000000; i++)
    {
        k = MWC;
    }
    printf ("%"PRIu32"\n", k - 904977562U);

    for (i = 0; i < 1000000; i++)
    {
        k = FIB;
    }
    printf ("%"PRIu32"\n", k - 3519793928U);

    for (i = 0; i < 1000000; i++)
    {
        k = MWC64;
    }
    printf ("%"PRIu32"\n", k - 3377343606U);

    mwc64 = MWC64_SEED(7654321, 521288629);
    shr3 = 362436000;
    cong = 123456789;
    for (i = 0; i < 1000000; i++)
    {
        k = KISS2;
    }
    printf ("%"PRIu32"\n", k - 1010846401U);

    return 0;
}