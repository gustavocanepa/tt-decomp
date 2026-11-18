/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
struct VoiceSystem;
struct Voice { char unknown00[0xE0]; };
struct VoiceFilter {
    VoiceSystem *system;
    s32 unknown04;
    u64 selectionMask;
    s32 unknown10;
    s32 unknown14;
    s32 unknown18;
    s32 unknown1C;
    s32 unknown20;
    s32 unknown24;
    s32 channelCriterion;
    s32 unknown2C;
    s32 enabledConstraints;
};
struct InterruptSection { s32 depth; s32 previouslyEnabled; };
struct StreamCursor {
    u8 *position;
    u8 get() { return *position++; }
};
// Partial owner and channel views. Named fields reflect observed offsets and use;
// all intervening regions remain unknown.
struct ChannelRecord {
    char unknown00[7];
    u8 channelValue;
    char unknown08[1];
    s8 playbackEnabled;
    char unknown0A[0x0A];
    s32 active;
    char unknown18[4];
};
struct StreamOwner {
    char unknown00[0x28];
    u64 selectionMask;
    s32 unknown30;
    s32 channel;
    char unknown38[0x20];
    StreamCursor stream;
    char unknown5C[0x0C];
    ChannelRecord channels[16];
};
extern InterruptSection D_005A0B88;
extern "C" void func_004A4930(InterruptSection *section);
extern "C" void func_004A4970(InterruptSection *section);
extern "C" void func_004C7A48(VoiceFilter *filter, u64 selectionMask);
extern "C" void func_004C73F8(VoiceSystem *system, VoiceFilter *filter,
                               void (*callback)(Voice *voice, s32 payload), s32 payload,
                               void (*postCallback)(s32 payload));
extern "C" void func_004C7A38(Voice *voice, s32 payload);
extern "C" void func_004C6310(StreamOwner *self) {
    s32 channel = self->channel & 0xF;
    u8 pendingValue = self->stream.get();
    self->channels[channel].channelValue = pendingValue;
    VoiceFilter filter;
    func_004C7A48(&filter, self->selectionMask);
    filter.channelCriterion = channel;
    filter.enabledConstraints |= 0x40;
    func_004A4930(&D_005A0B88);
    func_004C73F8(filter.system, &filter, func_004C7A38, pendingValue, 0);
    func_004A4970(&D_005A0B88);
}
