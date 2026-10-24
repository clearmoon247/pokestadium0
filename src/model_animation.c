/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/model_animation.c. */

#include "model_animation.h"
#include "util.h"
#include "matrix.h"
#include "model_animation_events.h"
typedef struct unk_func_80016B30_arg0 {
    /* 0x00 */ Vec3s vec;
    /* 0x06 */ s16 unk_06;
} unk_func_80016B30_arg0;
typedef union AnimFixedFrame {
    struct {
        s16 whole;
        s16 fraction; // low 16 bits; signed declaration retained for matching
    };
    s32 raw;
} AnimFixedFrame;
typedef struct TransformAnimRaw {
    /* 0x00 */ s16 animationId;
    /* 0x04 */ TransformAnimData* data;
    /* 0x08 */ AnimFixedFrame frameFixed;
    /* 0x0C */ s32 speedFixed;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 lastRenderFrame;
} TransformAnimRaw;

void ModelAnim_ClearTransformChannel(DisplayObject* display_object);
s32 ModelAnim_BindTransformCurve(DisplayObject* display_object, s16 animation_id, void* address, s32 speed);
s32 ModelAnim_SetSpeed(DisplayObject* display_object, s32 speed);
void ModelAnim_SetFrame(DisplayObject* display_object, s16 animation_timer);
s32 ModelAnim_HasCrossedFrame(DisplayObject* arg0, s16 arg1);
s32 ModelAnim_IsAnimationDone(DisplayObject* display_object);
s32 ModelAnim_IsFinished(DisplayObject* arg0);

void ModelAnim_ClearTransformChannel(DisplayObject* display_object) {
    display_object->transformAnim.animationId = -1;
    display_object->transformAnim.data = NULL;
}

s32 ModelAnim_BindTransformCurve(DisplayObject* display_object, s16 animation_id, void* address, s32 speed) {
    TransformAnimData* transform_addr = Util_ConvertAddrToVirtAddr(address);
    TransformAnimState* transform_anim = &display_object->transformAnim;

    if ((transform_addr != transform_anim->data) || (animation_id != transform_anim->animationId)) {
        transform_anim->animationId = animation_id;
        transform_anim->data = transform_addr;
        transform_anim->frameFixed = (transform_addr->startFrame << 16) - speed;
    }

    transform_anim->speedFixed = speed;
    return transform_anim->frameFixed >> 16;
}

s32 ModelAnim_SetSpeed(DisplayObject* display_object, s32 speed) {
    display_object->transformAnim.speedFixed = speed;
    return display_object->transformAnim.frameFixed >> 0x10;
}

void ModelAnim_SetFrame(DisplayObject* display_object, s16 animation_timer) {
    display_object->transformAnim.frameFixed = (animation_timer << 0x10) - display_object->transformAnim.speedFixed;
}

s32 ModelAnim_HasCrossedFrame(DisplayObject* arg0, s16 arg1) {
    TransformAnimState* ptr = &arg0->transformAnim;
    s32 temp_v0 = ptr->frameFixed + ptr->speedFixed;
    s32 arg = arg1 << 0x10;
    s32 var_a2;
    s32 v = ptr->speedFixed;

    if (v >= 0) {
        var_a2 = ptr->frameFixed < arg;
        if (var_a2 != 0) {
            var_a2 = temp_v0 >= arg;
        }
    } else {
        var_a2 = (arg < ptr->frameFixed);
        if (var_a2 != 0) {
            var_a2 = arg >= temp_v0;
        }
    }

    return var_a2;
}

s32 ModelAnim_IsAnimationDone(DisplayObject* display_object) {
    return ModelAnim_HasCrossedFrame(display_object, display_object->transformAnim.data->endFrame - 1);
}

s32 ModelAnim_IsFinished(DisplayObject* arg0) {
    return arg0->transformAnim.frameFixed >= ((arg0->transformAnim.data->endFrame - 1) << 0x10);
}
