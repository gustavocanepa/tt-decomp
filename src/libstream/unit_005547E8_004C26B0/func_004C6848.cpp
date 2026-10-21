/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;
// Partial playback-record views inferred from this routine; padding offsets remain provisional.
struct SequenceInputView {
    char pad00[4];
    u32 limit;
};
struct PlaybackState {
    s32 active;
    void *context;
    SequenceInputView *input;
    f32 savedValue;
    s32 unknown10;
    s32 boundedIndex;
};
struct PlaybackOwner {
    char pad00[0x234];
    PlaybackState playback;
};
struct InterruptState {
    s32 nestedInterruptDepth;
    s32 priorInterruptState;
};
extern InterruptState D_005A0B88;
extern "C" void func_004C6970(PlaybackOwner *self, s32 mode);
extern "C" void func_004C6560(PlaybackOwner *self, void *context, SequenceInputView *input, s32 index);
extern "C" void func_004A4930(InterruptState *state);
extern "C" void func_004A4970(InterruptState *state);
extern "C" void func_004C6848(PlaybackOwner *self, void *context, SequenceInputView *input, s32 index, f32 value) {
    PlaybackState *state = &self->playback;
    if (state->active != 0) {
        func_004C6970(self, 1);
    }
    func_004A4930(&D_005A0B88);
    if (input->limit < (u32)index) {
        index = 0;
    }
    func_004C6560(self, context, input, index);
    state->context = context;
    state->input = input;
    state->active = 1;
    state->boundedIndex = index;
    state->savedValue = value;
    state->unknown10 = 0;
    func_004A4970(&D_005A0B88);
}
