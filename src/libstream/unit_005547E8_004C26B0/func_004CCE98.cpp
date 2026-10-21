typedef int s32;
typedef unsigned int u32;

extern "C" u32 func_004CC5A8(int bits);
extern "C" s32 func_004CC568(s32 bits);
extern "C" void func_004CC668(u32 bits);
extern "C" void func_004CCC78(void);
extern "C" void func_004CCFA8(void);
extern "C" void func_004CD080(void);
extern "C" void func_004CD0D8(void);

enum MpegCode { ExtensionStart = 0x1B5, UserDataStart = 0x1B2 };
enum ExtensionId { SequenceExtension = 1, SequenceDisplayExtension = 2,
                   PictureCodingExtension = 8 };

/* Consume extension/user-data units, leaving the following start code unread.
   The returned boundary code also preserves the value forwarded by the header
   readers; its meaning outside this parsing family has not been established. */
extern "C" s32 func_004CCE98(void) {
    u32 startCode;

    func_004CCC78();
    while ((startCode = func_004CC5A8(32)) == ExtensionStart || startCode == UserDataStart) {
        func_004CC668(32);
        if (startCode != ExtensionStart) {
            func_004CCC78();
            continue;
        }
        switch ((u32)func_004CC568(4)) {
        case SequenceExtension:
            func_004CCFA8();
            break;
        case SequenceDisplayExtension:
            func_004CD080();
            break;
        case PictureCodingExtension:
            func_004CD0D8();
            break;
        }
        func_004CCC78();
    }
    return (s32)startCode;
}
