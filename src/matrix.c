/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/gfx_rect.c, src/matrix.c. */

#include "matrix.h"
#include "game_state.h"
#include "math_util.h"
extern Mtx gIdentityMtx;
extern Vec3f D_80060450;
extern Vec3s D_8006045C;
extern Vec3f D_80060464;
#define GET_HIGH_S16_OF_32(var) (((s16*)&(var))[0])
#define GET_LOW_S16_OF_32(var) (((s16*)&(var))[1])

#include "global.h"
#include "gfx_rect.h"
#include "memory.h"
extern DepthBuffer* D_8005F670;

Color_RGBA8* Color_SetRGB(Color_RGBA8* dest, u8 r, u8 g, u8 b);
Color_RGBA8* Color_SetRGBA(Color_RGBA8* dest, u8 r, u8 g, u8 b, u8 alpha);
Vec3f* Vec3f_SetComponents(Vec3f* dest, f32 x, f32 y, f32 z);
unk_D_800A7440* GfxRect_SetBounds(unk_D_800A7440* arg0, s16 x1, s16 y1, s16 x2, s16 y2);
Vec3f* Vec3f_SetComponentsDuplicate(Vec3f* dest, f32 x, f32 y, f32 z);
Vec3f* Vec3f_AddInPlace(Vec3f* dest, Vec3f* summand);
Vec3f* Vec3f_Add(Vec3f* dest, Vec3f* a, Vec3f* b);
Vec3f* Vec3f_SubtractInPlace(Vec3f* dest, Vec3f* subtrahend);
Vec3f* Vec3f_Subtract(Vec3f* out, Vec3f* a, Vec3f* subtrahend);
Vec3f* Vec3f_FromVec3s(Vec3f* float_vector, Vec3s* int_vector);
Vec3f* Vec3f_TriangleNormal(Vec3f* dest, Vec3f* a, Vec3f* b, Vec3f* c);
Vec3f* Vec3f_CrossProduct(Vec3f* dest, Vec3f* a, Vec3f* b);
Vec3f* Vec3f_Normalize(Vec3f* vector);
Vec3s* Vec3s_SetComponents(Vec3s* dest, s16 a, s16 b, s16 c);
Vec3s* Vec3s_AddInPlace(Vec3s* dest, Vec3s* summand);
Vec3s* Vec3s_Add(Vec3s* dest, Vec3s* a, Vec3s* b);
Vec3s* Vec3s_SubtractInPlace(Vec3s* dest, Vec3s* subtrahend);
Vec3s* Vec3s_Subtract(Vec3s* dest, Vec3s* a, Vec3s* subtrahend);
Vec3s* Vec3s_FromVec3f(Vec3s* dest, Vec3f* float_vector);
void MtxF_Copy(MtxF* dest, MtxF* src);
void MtxF_Identity(MtxF* dest);
void MtxF_SetTranslation(MtxF* identity, Vec3f* translate);
void MtxF_SetLookAt(MtxF* mtx, Vec3f* from, Vec3f* to, u16 roll);
void MtxF_SetRotationTranslation(MtxF* out, Vec3s* translate, Vec3s* rotate);
void MtxF_SetRotationTranslationF(MtxF* out, Vec3f* translate, Vec3s* rotate);
void MtxF_SetRotationAndTransformTranslation(MtxF* out, Vec3f* translate, Vec3s* rotate);
void MtxF_SetRotationScaleTranslation(MtxF* dest, Vec3f* translate, Vec3s* rotate, Vec3f* scale);
void MtxF_SetRotationAndScaledTranslation(MtxF* dest, Vec3f* translate, Vec3s* rotate, Vec3f* scale);
void MtxF_SetOrthonormalBasis(MtxF* dest, Vec3f* up_direction, Vec3f* pos, s16 yaw);
void MtxF_Multiply(MtxF* dest, MtxF* A, MtxF* B);
void MtxF_ScaleRows(MtxF* dest, MtxF* matrix, Vec3f* scale);
void MtxF_GetScale(MtxF* matrix, Vec3f* dest);
void MtxF_TransformVec3s(MtxF* matrix, Vec3s* dest);
void MtxF_ToFixed(MtxF* dest, MtxF* src);
void Vec3f_CalculateDistanceAngles(Vec3f* to, Vec3f* from, f32* euclidean, s16* angle_x, s16* angle_y);
void Camera_ComputeEyeFromAngles(Vec3f* from, Vec3f* to, f32 dist, s16 rotation_x, s16 rotation_y);

Color_RGBA8* Color_SetRGB(Color_RGBA8* dest, u8 r, u8 g, u8 b) {
    dest->r = r;
    dest->g = g;
    dest->b = b;

    return dest;
}

Color_RGBA8* Color_SetRGBA(Color_RGBA8* dest, u8 r, u8 g, u8 b, u8 alpha) {
    dest->r = r;
    dest->g = g;
    dest->b = b;
    dest->a = alpha;

    return dest;
}

Vec3f* Vec3f_SetComponents(Vec3f* dest, f32 x, f32 y, f32 z) {
    dest->x = x;
    dest->y = y;
    dest->z = z;

    return dest;
}

unk_D_800A7440* GfxRect_SetBounds(unk_D_800A7440* arg0, s16 x1, s16 y1, s16 x2, s16 y2) {
    if (x2 >= x1) {
        arg0->x1 = x1;
        arg0->y1 = x2;
    } else {
        arg0->x1 = x2;
        arg0->y1 = x1;
    }

    if (y2 >= y1) {
        arg0->x2 = y2;
        arg0->y2 = y1;
    } else {
        arg0->y2 = y2;
        arg0->x2 = y1;
    }

    return arg0;
}

Vec3f* Vec3f_SetComponentsDuplicate(Vec3f* dest, f32 x, f32 y, f32 z) {
    dest->x = x;
    dest->y = y;
    dest->z = z;

    return dest;
}

Vec3f* Vec3f_AddInPlace(Vec3f* dest, Vec3f* summand) {
    dest->x += summand->x;
    dest->y += summand->y;
    dest->z += summand->z;

    return dest;
}

Vec3f* Vec3f_Add(Vec3f* dest, Vec3f* a, Vec3f* b) {
    dest->x = a->x + b->x;
    dest->y = a->y + b->y;
    dest->z = a->z + b->z;

    return dest;
}

Vec3f* Vec3f_SubtractInPlace(Vec3f* dest, Vec3f* subtrahend) {
    dest->x -= subtrahend->x;
    dest->y -= subtrahend->y;
    dest->z -= subtrahend->z;

    return dest;
}

Vec3f* Vec3f_Subtract(Vec3f* out, Vec3f* a, Vec3f* subtrahend) {
    out->x = a->x - subtrahend->x;
    out->y = a->y - subtrahend->y;
    out->z = a->z - subtrahend->z;

    return out;
}

Vec3f* Vec3f_FromVec3s(Vec3f* float_vector, Vec3s* int_vector) {
    float_vector->x = int_vector->x;
    float_vector->y = int_vector->y;
    float_vector->z = int_vector->z;

    return float_vector;
}

Vec3f* Vec3f_TriangleNormal(Vec3f* dest, Vec3f* a, Vec3f* b, Vec3f* c) {
    dest->x = ((b->y - a->y) * (c->z - b->z)) - ((c->y - b->y) * (b->z - a->z));
    dest->y = ((b->z - a->z) * (c->x - b->x)) - ((c->z - b->z) * (b->x - a->x));
    dest->z = ((b->x - a->x) * (c->y - b->y)) - ((c->x - b->x) * (b->y - a->y));

    return dest;
}

Vec3f* Vec3f_CrossProduct(Vec3f* dest, Vec3f* a, Vec3f* b) {
    dest->x = (a->y * b->z) - (b->y * a->z);
    dest->y = (a->z * b->x) - (b->z * a->x);
    dest->z = (a->x * b->y) - (b->x * a->y);

    return dest;
}

Vec3f* Vec3f_Normalize(Vec3f* vector) {
    f32 temp_fv1_2 = 1.0f / sqrtf(SQ(vector->x) + SQ(vector->y) + SQ(vector->z));

    vector->x *= temp_fv1_2;
    vector->y *= temp_fv1_2;
    vector->z *= temp_fv1_2;

    return vector;
}

Vec3s* Vec3s_SetComponents(Vec3s* dest, s16 a, s16 b, s16 c) {
    dest->x = a;
    dest->y = b;
    dest->z = c;

    return dest;
}

Vec3s* Vec3s_AddInPlace(Vec3s* dest, Vec3s* summand) {
    dest->x += summand->x;
    dest->y += summand->y;
    dest->z += summand->z;

    return dest;
}

Vec3s* Vec3s_Add(Vec3s* dest, Vec3s* a, Vec3s* b) {
    dest->x = a->x + b->x;
    dest->y = a->y + b->y;
    dest->z = a->z + b->z;

    return dest;
}

Vec3s* Vec3s_SubtractInPlace(Vec3s* dest, Vec3s* subtrahend) {
    dest->x -= subtrahend->x;
    dest->y -= subtrahend->y;
    dest->z -= subtrahend->z;

    return dest;
}

Vec3s* Vec3s_Subtract(Vec3s* dest, Vec3s* a, Vec3s* subtrahend) {
    dest->x = a->x - subtrahend->x;
    dest->y = a->y - subtrahend->y;
    dest->z = a->z - subtrahend->z;

    return dest;
}

Vec3s* Vec3s_FromVec3f(Vec3s* dest, Vec3f* float_vector) {
    dest->x = ROUND_MAX(float_vector->x);
    dest->y = ROUND_MAX(float_vector->y);
    dest->z = ROUND_MAX(float_vector->z);

    return dest;
}

void MtxF_Copy(MtxF* dest, MtxF* src) {
    if (dest != src) {
        s32 i;
        u32* d = (u32*)dest;
        u32* s = (u32*)src;

        for (i = 0; i < 16; i++) {
            *d++ = *s++;
        }
    }
}

void MtxF_Identity(MtxF* dest) {
    s32 i;
    f32* j;
    // These loops must be one line to match on -O2
    // clang-format off
    
    // initialize everything except the first and last cells to 0
    for (j = (f32*)dest + 1, i = 0; i < 14; j++, i++) { *j = 0.0f; }

    // initialize the diagonal cells to 1
    for (j = (f32*)dest, i = 0; i < 4; j += 5, i++) { *j = 1.0f; }
    // clang-format on
}

void MtxF_SetTranslation(MtxF* identity, Vec3f* translate) {
    MtxF_Identity(identity);

    identity->mf[3][0] = translate->x;
    identity->mf[3][1] = translate->y;
    identity->mf[3][2] = translate->z;
}

void MtxF_SetLookAt(MtxF* mtx, Vec3f* from, Vec3f* to, u16 roll) {
    f32 invLength;
    f32 dx;
    f32 dz;
    f32 xColY;
    f32 yColY;
    f32 zColY;
    f32 xColZ;
    f32 yColZ;
    f32 zColZ;
    f32 xColX;
    f32 yColX;
    f32 zColX;

    dx = to->x - from->x;
    dz = to->z - from->z;

    invLength = -1.0 / sqrtf(dx * dx + dz * dz);
    dx *= invLength;
    dz *= invLength;

    yColY = COSS(roll);
    xColY = SINS(roll) * dz;
    zColY = -SINS(roll) * dx;

    xColZ = to->x - from->x;
    yColZ = to->y - from->y;
    zColZ = to->z - from->z;

    invLength = -1.0 / sqrtf(xColZ * xColZ + yColZ * yColZ + zColZ * zColZ);
    xColZ *= invLength;
    yColZ *= invLength;
    zColZ *= invLength;

    xColX = yColY * zColZ - zColY * yColZ;
    yColX = zColY * xColZ - xColY * zColZ;
    zColX = xColY * yColZ - yColY * xColZ;

    invLength = 1.0 / sqrtf(xColX * xColX + yColX * yColX + zColX * zColX);

    xColX *= invLength;
    yColX *= invLength;
    zColX *= invLength;

    xColY = yColZ * zColX - zColZ * yColX;
    yColY = zColZ * xColX - xColZ * zColX;
    zColY = xColZ * yColX - yColZ * xColX;

    invLength = 1.0 / sqrtf(xColY * xColY + yColY * yColY + zColY * zColY);
    xColY *= invLength;
    yColY *= invLength;
    zColY *= invLength;

    mtx->mf[0][0] = xColX;
    mtx->mf[1][0] = yColX;
    mtx->mf[2][0] = zColX;
    mtx->mf[3][0] = -(from->x * xColX + from->y * yColX + from->z * zColX);

    mtx->mf[0][1] = xColY;
    mtx->mf[1][1] = yColY;
    mtx->mf[2][1] = zColY;
    mtx->mf[3][1] = -(from->x * xColY + from->y * yColY + from->z * zColY);

    mtx->mf[0][2] = xColZ;
    mtx->mf[1][2] = yColZ;
    mtx->mf[2][2] = zColZ;
    mtx->mf[3][2] = -(from->x * xColZ + from->y * yColZ + from->z * zColZ);

    mtx->mf[0][3] = 0.0f;
    mtx->mf[1][3] = 0.0f;
    mtx->mf[2][3] = 0.0f;
    mtx->mf[3][3] = 1.0f;
}

void MtxF_SetRotationTranslation(MtxF* out, Vec3s* translate, Vec3s* rotate) {
    f32 sx = SINS(rotate->x);
    f32 cx = COSS(rotate->x);

    f32 sy = SINS(rotate->y);
    f32 cy = COSS(rotate->y);

    f32 sz = SINS(rotate->z);
    f32 cz = COSS(rotate->z);

    out->mf[0][0] = cy * cz + (sx * sy) * sz;
    out->mf[0][1] = -cy * sz + (sx * sy) * cz;
    out->mf[0][2] = cx * sy;
    out->mf[0][3] = translate->x;

    out->mf[1][0] = cx * sz;
    out->mf[1][1] = cx * cz;
    out->mf[1][2] = -sx;
    out->mf[1][3] = translate->y;

    out->mf[2][0] = -sy * cz + (sx * cy) * sz;
    out->mf[2][1] = sy * sz + (sx * cy) * cz;
    out->mf[2][2] = cx * cy;
    out->mf[2][3] = translate->z;

    out->mf[3][0] = 0.0f;
    out->mf[3][1] = 0.0f;
    out->mf[3][2] = 0.0f;
    out->mf[3][3] = 1.0f;
}

void MtxF_SetRotationTranslationF(MtxF* out, Vec3f* translate, Vec3s* rotate) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp0;

    temp_fv0 = SINS(rotate->x);
    temp_fv1 = COSS(rotate->x);

    temp_fa0 = SINS(rotate->y);
    temp_fa1 = COSS(rotate->y);

    temp_ft4 = SINS(rotate->z);
    temp_ft5 = COSS(rotate->z);

    sp0 = temp_fv0 * temp_fa0;
    out->mf[0][0] = (temp_fa1 * temp_ft5) + (sp0 * temp_ft4);
    out->mf[1][0] = (-temp_fa1 * temp_ft4) + (sp0 * temp_ft5);
    out->mf[2][0] = temp_fv1 * temp_fa0;
    out->mf[3][0] = translate->x;

    out->mf[0][1] = temp_fv1 * temp_ft4;
    out->mf[1][1] = temp_fv1 * temp_ft5;
    out->mf[2][1] = -temp_fv0;
    out->mf[3][1] = translate->y;

    sp0 = temp_fv0 * temp_fa1;
    out->mf[0][2] = (-temp_fa0 * temp_ft5) + (sp0 * temp_ft4);
    out->mf[1][2] = (temp_fa0 * temp_ft4) + (sp0 * temp_ft5);
    out->mf[2][2] = temp_fv1 * temp_fa1;
    out->mf[3][2] = translate->z;

    out->mf[0][3] = 0.0f;
    out->mf[1][3] = 0.0f;
    out->mf[2][3] = 0.0f;
    out->mf[3][3] = 1.0f;
}

void MtxF_SetRotationAndTransformTranslation(MtxF* out, Vec3f* translate, Vec3s* rotate) {
    f32 sx = SINS(rotate->x);
    f32 cx = COSS(rotate->x);
    f32 sy = SINS(rotate->y);
    f32 cy = COSS(rotate->y);
    f32 sz = SINS(rotate->z);
    f32 cz = COSS(rotate->z);

    out->mf[0][0] = (cy * cz) + ((sx * sy) * sz);
    out->mf[0][1] = (-cy * sz) + ((sx * sy) * cz);
    out->mf[0][2] = cx * sy;

    out->mf[1][0] = cx * sz;
    out->mf[1][1] = cx * cz;
    out->mf[1][2] = -sx;

    out->mf[2][0] = (-sy * cz) + ((sx * cy) * sz);
    out->mf[2][1] = (sy * sz) + ((sx * cy) * cz);
    out->mf[2][2] = cx * cy;

    out->mf[3][0] = (out->mf[0][0] * translate->x) + (out->mf[1][0] * translate->y) + (out->mf[2][0] * translate->z);
    out->mf[3][1] = (out->mf[0][1] * translate->x) + (out->mf[1][1] * translate->y) + (out->mf[2][1] * translate->z);
    out->mf[3][2] = (out->mf[0][2] * translate->x) + (out->mf[1][2] * translate->y) + (out->mf[2][2] * translate->z);

    out->mf[0][3] = out->mf[1][3] = out->mf[2][3] = 0.0f;
    out->mf[3][3] = 1.0f;
}

void MtxF_SetRotationScaleTranslation(MtxF* dest, Vec3f* translate, Vec3s* rotate, Vec3f* scale) {
    f32 sx = SINS(rotate->x);
    f32 cx = COSS(rotate->x);

    f32 sy = SINS(rotate->y);
    f32 cy = COSS(rotate->y);

    f32 sz = SINS(rotate->z);
    f32 cz = COSS(rotate->z);

    dest->mf[0][0] = (cy * cz) * scale->x;
    dest->mf[0][1] = (cy * sz) * scale->x;
    dest->mf[0][2] = (-sy) * scale->x;
    dest->mf[0][3] = 0.0f;

    dest->mf[1][0] = (sx * sy * cz - cx * sz) * scale->y;
    dest->mf[1][1] = (sx * sy * sz + cx * cz) * scale->y;
    dest->mf[1][2] = (sx * cy) * scale->y;
    dest->mf[1][3] = 0.0f;

    dest->mf[2][0] = (cx * sy * cz + sx * sz) * scale->z;
    dest->mf[2][1] = (cx * sy * sz - sx * cz) * scale->z;
    dest->mf[2][2] = (cx * cy) * scale->z;
    dest->mf[2][3] = 0.0f;

    dest->mf[3][0] = translate->x;
    dest->mf[3][1] = translate->y;
    dest->mf[3][2] = translate->z;
    dest->mf[3][3] = 1.0f;
}

void MtxF_SetRotationAndScaledTranslation(MtxF* dest, Vec3f* translate, Vec3s* rotate, Vec3f* scale) {
    f32 sx = SINS(rotate->x);
    f32 cx = COSS(rotate->x);

    f32 sy = SINS(rotate->y);
    f32 cy = COSS(rotate->y);

    f32 sz = SINS(rotate->z);
    f32 cz = COSS(rotate->z);

    dest->mf[0][0] = cy * cz;
    dest->mf[0][1] = cy * sz;
    dest->mf[0][2] = -sy;
    dest->mf[0][3] = 0.0f;

    dest->mf[1][0] = sx * sy * cz - cx * sz;
    dest->mf[1][1] = sx * sy * sz + cx * cz;
    dest->mf[1][2] = sx * cy;
    dest->mf[1][3] = 0.0f;

    dest->mf[2][0] = cx * sy * cz + sx * sz;
    dest->mf[2][1] = cx * sy * sz - sx * cz;
    dest->mf[2][2] = cx * cy;
    dest->mf[2][3] = 0.0f;

    dest->mf[3][0] = translate->x * scale->x;
    dest->mf[3][1] = translate->y * scale->y;
    dest->mf[3][2] = translate->z * scale->z;
    dest->mf[3][3] = 1.0f;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000E41C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000E41C.s")
#endif

void MtxF_SetOrthonormalBasis(MtxF* dest, Vec3f* up_direction, Vec3f* pos, s16 yaw) {
    Vec3f lateral_direction;
    Vec3f left_direction;
    Vec3f forward_direction;

    Vec3f_SetComponentsDuplicate(&lateral_direction, SINS(yaw), 0, COSS(yaw));
    Vec3f_Normalize(up_direction);

    Vec3f_CrossProduct(&left_direction, up_direction, &lateral_direction);
    Vec3f_Normalize(&left_direction);

    Vec3f_CrossProduct(&forward_direction, &left_direction, up_direction);
    Vec3f_Normalize(&forward_direction);

    dest->mf[0][0] = left_direction.x;
    dest->mf[0][1] = left_direction.y;
    dest->mf[0][2] = left_direction.z;
    dest->mf[3][0] = pos->x;

    dest->mf[1][0] = up_direction->x;
    dest->mf[1][1] = up_direction->y;
    dest->mf[1][2] = up_direction->z;
    dest->mf[3][1] = pos->y;

    dest->mf[2][0] = forward_direction.x;
    dest->mf[2][1] = forward_direction.y;
    dest->mf[2][2] = forward_direction.z;
    dest->mf[3][2] = pos->z;

    dest->mf[0][3] = 0.0f;
    dest->mf[1][3] = 0.0f;
    dest->mf[2][3] = 0.0f;
    dest->mf[3][3] = 1.0f;
}

void MtxF_Multiply(MtxF* dest, MtxF* A, MtxF* B) {
    f32 entry0;
    f32 entry1;
    f32 entry2;

    entry0 = A->mf[0][0];
    entry1 = A->mf[0][1];
    entry2 = A->mf[0][2];

    dest->mf[0][0] = (entry0 * B->mf[0][0]) + (entry1 * B->mf[1][0]) + (entry2 * B->mf[2][0]);
    dest->mf[0][1] = (entry0 * B->mf[0][1]) + (entry1 * B->mf[1][1]) + (entry2 * B->mf[2][1]);
    dest->mf[0][2] = (entry0 * B->mf[0][2]) + (entry1 * B->mf[1][2]) + (entry2 * B->mf[2][2]);

    entry0 = A->mf[1][0];
    entry1 = A->mf[1][1];
    entry2 = A->mf[1][2];

    dest->mf[1][0] = (entry0 * B->mf[0][0]) + (entry1 * B->mf[1][0]) + (entry2 * B->mf[2][0]);
    dest->mf[1][1] = (entry0 * B->mf[0][1]) + (entry1 * B->mf[1][1]) + (entry2 * B->mf[2][1]);
    dest->mf[1][2] = (entry0 * B->mf[0][2]) + (entry1 * B->mf[1][2]) + (entry2 * B->mf[2][2]);

    entry0 = A->mf[2][0];
    entry1 = A->mf[2][1];
    entry2 = A->mf[2][2];

    dest->mf[2][0] = (entry0 * B->mf[0][0]) + (entry1 * B->mf[1][0]) + (entry2 * B->mf[2][0]);
    dest->mf[2][1] = (entry0 * B->mf[0][1]) + (entry1 * B->mf[1][1]) + (entry2 * B->mf[2][1]);
    dest->mf[2][2] = (entry0 * B->mf[0][2]) + (entry1 * B->mf[1][2]) + (entry2 * B->mf[2][2]);

    entry0 = A->mf[3][0];
    entry1 = A->mf[3][1];
    entry2 = A->mf[3][2];

    dest->mf[3][0] = (entry0 * B->mf[0][0]) + (entry1 * B->mf[1][0]) + (entry2 * B->mf[2][0]) + B->mf[3][0];
    dest->mf[3][1] = (entry0 * B->mf[0][1]) + (entry1 * B->mf[1][1]) + (entry2 * B->mf[2][1]) + B->mf[3][1];
    dest->mf[3][2] = (entry0 * B->mf[0][2]) + (entry1 * B->mf[1][2]) + (entry2 * B->mf[2][2]) + B->mf[3][2];

    dest->mf[0][3] = dest->mf[1][3] = dest->mf[2][3] = 0.0f;
    dest->mf[3][3] = 1.0f;
}

void MtxF_ScaleRows(MtxF* dest, MtxF* matrix, Vec3f* scale) {
    s32 i;

    for (i = 0; i < 4; i++) {
        dest->mf[0][i] = matrix->mf[0][i] * scale->x;
        dest->mf[1][i] = matrix->mf[1][i] * scale->y;
        dest->mf[2][i] = matrix->mf[2][i] * scale->z;
        dest->mf[3][i] = matrix->mf[3][i];
    }
}

void MtxF_GetScale(MtxF* matrix, Vec3f* dest) {
    dest->x = sqrtf(SQ(matrix->mf[0][0]) + SQ(matrix->mf[0][1]) + SQ(matrix->mf[0][2]));
    dest->y = sqrtf(SQ(matrix->mf[1][0]) + SQ(matrix->mf[1][1]) + SQ(matrix->mf[1][2]));
    dest->z = sqrtf(SQ(matrix->mf[2][0]) + SQ(matrix->mf[2][1]) + SQ(matrix->mf[2][2]));
}

void MtxF_TransformVec3s(MtxF* matrix, Vec3s* dest) {
    f32 entry0 = dest->x;
    f32 entry1 = dest->y;
    f32 entry2 = dest->z;

    dest->x = ((entry0 * matrix->mf[0][0]) + (entry1 * matrix->mf[1][0]) + (entry2 * matrix->mf[2][0])) + matrix->mf[3][0];
    dest->y = ((entry0 * matrix->mf[0][1]) + (entry1 * matrix->mf[1][1]) + (entry2 * matrix->mf[2][1])) + matrix->mf[3][1];
    dest->z = ((entry0 * matrix->mf[0][2]) + (entry1 * matrix->mf[1][2]) + (entry2 * matrix->mf[2][2])) + matrix->mf[3][2];
}

void MtxF_ToFixed(MtxF* dest, MtxF* src) {
    s32 asFixedPoint;
    s32 i;
    s16* a3 = (s16*)dest;      // all integer parts stored in first 16 bytes
    s16* t0 = (s16*)dest + 16; // all fraction parts stored in last 16 bytes
    f32* t1 = (f32*)src;

    for (i = 0; i < 16; i++) {
        asFixedPoint = *t1++ * (1 << 16);         //! float-to-integer conversion responsible for PU crashes
        *a3++ = GET_HIGH_S16_OF_32(asFixedPoint); // integer part
        *t0++ = GET_LOW_S16_OF_32(asFixedPoint);  // fraction part
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000ED9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000ED9C.s")
#endif

void Vec3f_CalculateDistanceAngles(Vec3f* to, Vec3f* from, f32* euclidean, s16* angle_x, s16* angle_y) {
    f32 x_dist = from->x - to->x;
    f32 y_dist = from->y - to->y;
    f32 z_dist = from->z - to->z;

    *euclidean = sqrtf(SQ(x_dist) + SQ(y_dist) + SQ(z_dist));
    *angle_x = MathUtil_Atan2s(sqrtf(SQ(x_dist) + SQ(z_dist)), y_dist);
    *angle_y = MathUtil_Atan2s(z_dist, x_dist);
}

void Camera_ComputeEyeFromAngles(Vec3f* from, Vec3f* to, f32 dist, s16 rotation_x, s16 rotation_y) {
    to->x = from->x + (dist * COSS(rotation_x) * SINS(rotation_y));
    to->y = from->y + (dist * SINS(rotation_x));
    to->z = from->z + (dist * COSS(rotation_x) * COSS(rotation_y));
}
