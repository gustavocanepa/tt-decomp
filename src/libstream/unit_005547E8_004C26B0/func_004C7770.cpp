/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VoiceSystem;
extern char D_005A0B88[];
extern "C" void func_004A4930(void *section);
extern "C" void func_004A4970(void *section);
extern "C" void func_004C8970(VoiceSystem *, s32 bankIndex, s32 value0, s32 value1);
extern "C" void func_004C7770(VoiceSystem *voiceSystem, s32 bankIndex, s32 value0, s32 value1) {
    func_004A4930(D_005A0B88);
    if (bankIndex != 2) {
        func_004C8970(voiceSystem, bankIndex, value0, value1);
    } else {
        s32 bankIndex = 0;
        do {
            func_004C8970(voiceSystem, bankIndex, value0, value1);
            bankIndex++;
        } while (bankIndex < 2);
    }
    func_004A4970(D_005A0B88);
}
