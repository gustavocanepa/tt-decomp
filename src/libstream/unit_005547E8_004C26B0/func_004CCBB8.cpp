typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_004CC568(s32 bits);
extern "C" void func_004CCC78(void);
extern "C" s32 func_004CCCC0(void);
extern "C" void func_004CCD70(void);
extern "C" s32 func_004CCDC8(void);

enum MpegStartCode {
    PictureStart = 0x100,
    SequenceHeader = 0x1B3,
    SequenceEnd = 0x1B7,
    GroupOfPictures = 0x1B8
};

/* Scan headers until a picture is ready or the sequence ends. Unknown codes
   are consumed and the next start code is sought by the alignment helper. */
extern "C" s32 func_004CCBB8(void) {
    for (;;) {
        u32 startCode;

        func_004CCC78();
        startCode = func_004CC568(32);
        switch (startCode) {
        case SequenceHeader:
            func_004CCCC0();
            break;
        case GroupOfPictures:
            func_004CCD70();
            break;
        case SequenceEnd:
            return 0;
        case PictureStart:
            func_004CCDC8();
            return 1;
        }
    }
}
