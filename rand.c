#include "rand.h"

inline void sfastrand(unsigned int s) { g_seed = s; }

/**
 * Fast-rand algorithm
 */
inline int fastrand()
{
  g_seed = (214013 * g_seed + 2531011);

  return (g_seed >> 16) & 0x7FFF;
}

inline static unsigned long rand_xor128()
{
	static unsigned long
    x = 123456789,
    y = 362436069,
    z = 521288629,
    w = 88675123;

	unsigned long t = (x^(x<<11));

  x = y;
  y = z;
  z = w;

  return w = (w^(w>>19))^(t^(t>>8));
}
