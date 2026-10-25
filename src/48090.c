/* Stadium Zero resident code. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_80047490; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80047490.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800474B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800474B8.s")
#endif

M2C_UNK func_800387BC(s32);                         /* extern */
extern s8 D_8007753C;
extern s8 D_8007754C;
extern s32 D_80077588;
extern s32 D_8007758C;
void func_800474E0(s32 arg0)
{
  s32 var_a0;
  if (1)
  {
    var_a0 = arg0;
    D_8007754C = 0;
    D_8007753C = 1;
    D_8007758C = 0;
    D_80077588 = 0;
    if (var_a0 == 0)
    {
      var_a0 = 1;
    }
  }
  func_800387BC(var_a0);
}
