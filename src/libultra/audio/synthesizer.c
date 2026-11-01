/* Stadium Zero resident code. */
/* Identical to ultralib src/audio/synthesizer.c (2.0I, IDO 5.3); link libultra here once the build exists. */

#include "global.h"
#include "m2c_macros.h"

M2C_UNK func_8004D600(s32);                         /* extern */
M2C_UNK func_8004D630(s32, s32);                    /* extern */
void func_800569B0(s32 arg0, s32 arg1) {
    func_8004D600(arg1);
    func_8004D630(arg1, arg0 + 0x14);
}

M2C_UNK func_8004D600(s32);                         /* extern */
void func_800569E8(s8 *arg0) {
    s32 var_s0;

    var_s0 = M2C_FIELD(arg0, s32 *, 0x14);
    if (var_s0 != 0) {
        do {
            func_8004D600(var_s0);
            func_8004D630(var_s0, arg0 + 4);
            var_s0 = M2C_FIELD(arg0, s32 *, 0x14);
        } while (var_s0 != 0);
    }
}

extern s8 *D_80077BE0;
void func_80056A48(M2C_UNK *arg0)
{
  M2C_UNK **new_var;
  s8 *new_var2;
  new_var2 = D_80077BE0;
  new_var = (M2C_UNK **) (((s8 *) new_var2) + 0x2C);
  *arg0 = *new_var;
  *new_var = arg0;
}

/*
 * func_80056A60
 *
 * Takes one parameter-update node off the synthesizer's free list and
 * returns it (NULL if the list is empty).  D_80077BE0 points at the
 * synthesizer driver, whose word at offset 0x2C heads the singly linked free
 * list; the node's first word is its next pointer, cleared before it is
 * returned.  func_80056A48, just above, is the matching "push a node back".
 * This is the libultra audio __n_allocParam (the symbol table keeps that
 * name; this function is not renamed).
 */
typedef struct SynthParamNode {
    struct SynthParamNode* next;
} SynthParamNode;

typedef struct SynthParamHead {
    /* 0x00 */ char pad00[0x2C];
    /* 0x2C */ SynthParamNode* paramList;
} SynthParamHead;

SynthParamNode* func_80056A60(void) {
    SynthParamNode* update = NULL;

    if (((SynthParamHead*)D_80077BE0)->paramList) {
        update = ((SynthParamHead*)D_80077BE0)->paramList;
        ((SynthParamHead*)D_80077BE0)->paramList = ((SynthParamHead*)D_80077BE0)->paramList->next;
        update->next = NULL;
    }
    return update;
}
