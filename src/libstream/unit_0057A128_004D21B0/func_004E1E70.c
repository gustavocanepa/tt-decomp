/* compiler: ee-gcc2.9-991111 */

/* Shared CD streaming RPC request. Field roles are inferred from its callers;
 * the trailing byte belongs to the 20-byte wire layout and is left unchanged. */
typedef struct {
    unsigned char retry_count;
    unsigned char spindle_control;
    unsigned char data_pattern;
    unsigned char reserved;
} ReadMode;

typedef struct {
    unsigned int sector;
    unsigned int sector_count;
    void *buffer;
    int command;
    ReadMode mode;
} StreamRequest;

extern int D_005A0D90;
extern int D_005A0DA8;
extern int D_005A0E00;
extern StreamRequest D_005A0E80;
extern char D_005A1F50[];
extern const char D_00614F38[], D_00614F50[], D_00614F68[];

extern int func_004DF590(int);
extern void func_004FA840(int);
extern void func_004FD2D0(const char *, ...);
extern void func_004FDAF8(void *, int);
extern int func_004FE530(void *, int, int, void *, int, void *, int,
                       void *, void *);

int func_004E1E70(unsigned int sector, unsigned int sector_count,
                  void *buffer, int command, const ReadMode *mode)
{
    int result;
    StreamRequest *request = &D_005A0E80;
    if (!func_004DF590(15))
        return 0;
    if (D_005A0D90 > 0)
        func_004FD2D0(D_00614F38);

    D_005A0E80.sector = sector;
    request->sector_count = sector_count;
    request->buffer = buffer;
    request->command = command;
    if (mode) {
        request->mode.retry_count = mode->retry_count;
        request->mode.spindle_control = mode->spindle_control;
        request->mode.data_pattern = mode->data_pattern;
    }
    if (D_005A0D90 > 0)
        func_004FD2D0(D_00614F50);
    func_004FDAF8(request, 20);
    if (func_004FE530(D_005A1F50, 9, 0, request, 20,
                      &D_005A0E00, 4, 0, 0) < 0) {
        func_004FA840(D_005A0DA8);
        return 0;
    }
    if (D_005A0D90 > 0)
        func_004FD2D0(D_00614F68);

    /* RPC writes the result through DMA: func_005AE2E8 the uncached EE alias. */
    result = *(int *)((unsigned int)&D_005A0E00 | 0x20000000);
    func_004FA840(D_005A0DA8);
    return result;
}
