/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/model_animation_events.c. */

#include "model_animation_events.h"
#include "util.h"

void ModelAnim_ClearEventTrack(DisplayObject* arg0);
s16 ModelAnim_BindEventTrack(DisplayObject* arg0, s16 arg1, s32 arg2);
void ModelAnim_SetEventFrame(DisplayObject* display_object, s16 frame_number);
s32 ModelAnim_IsEventFrame(DisplayObject* display_object, s16 frame_number);
s32 ModelAnim_IsEventTrackNearEnd(DisplayObject* display_object);
s32 ModelAnim_IsEventTrackDone(DisplayObject* display_object);

void ModelAnim_ClearEventTrack(DisplayObject* arg0) {
    arg0->eventTrack.trackId = -1;
    arg0->eventTrack.data = 0;
}

s16 ModelAnim_BindEventTrack(DisplayObject* arg0, s16 arg1, s32 arg2) {
    EventTrackData* temp_v0 = Util_ConvertAddrToVirtAddr(arg2);
    EventTrackState* ptr = &arg0->eventTrack;

    if ((temp_v0 != ptr->data) || (arg1 != ptr->trackId)) {
        ptr->trackId = arg1;
        ptr->data = temp_v0;
        ptr->frame = temp_v0->startFrame - 1;
    }

    return ptr->frame;
}

void ModelAnim_SetEventFrame(DisplayObject* display_object, s16 frame_number) {
    display_object->eventTrack.frame = frame_number - 1;
}

s32 ModelAnim_IsEventFrame(DisplayObject* display_object, s16 frame_number) {
    return (display_object->eventTrack.frame + 1) == frame_number;
}

s32 ModelAnim_IsEventTrackNearEnd(DisplayObject* display_object) {
    return (display_object->eventTrack.frame + 2) == display_object->eventTrack.data->endFrame;
}

s32 ModelAnim_IsEventTrackDone(DisplayObject* display_object) {
    return (display_object->eventTrack.frame + 1) == display_object->eventTrack.data->endFrame;
}
