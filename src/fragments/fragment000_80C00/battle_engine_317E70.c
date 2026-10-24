/* Stadium Zero fragment000_80C00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_317E70.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "geo_render.h"
#include "model_renderer.h"
#include "matrix.h"
#include "fragments/particle_math/particle_math.h"
#include "memory.h"

void BattleAnim_ClearEffectStateFlag(void);
void BattleAnim_EffectStartNop(void);
void BattleAnim_DisableEffectSpawningAlias(void);

void BattleAnim_DisableEffectSpawning(void);

void BattleAnim_ClearEffectStateFlag(void) {
    D_811842A0 = 0;
}

void BattleAnim_EffectStartNop(void) {
}

void BattleAnim_DisableEffectSpawningAlias(void) {
    BattleAnim_DisableEffectSpawning();
}
