#include "defs.h"

inline void srand(unsigned int s) { g_seed = s; }

/**
 * Fast-rand algorigthm
 */
inline int rand()
{
  g_seed = (214013*g_seed+2531011);

  return (g_seed>>16)&0x7FFF;
}
