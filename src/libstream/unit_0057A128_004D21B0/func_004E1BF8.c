/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
extern int D_005A0D90;
extern int D_005A2934;
extern u8 D_0078B110[];
extern unsigned int func_004E1E70(unsigned int, unsigned int, void *, int, const u8 *);
extern void func_004FB898(int);
extern void func_004FD2D0(const char *, ...);
extern void func_004FDAF8(void *, int);

/* sceCdStRead: drain 2048-byte sectors from the active streaming request.
 * RPC results pack the sector count into the low half and the drive error into
 * the high half. Blocking reads retain the last error and sleep when a poll
 * makes no progress; nonblocking reads perform one poll. */
int func_004E1BF8(unsigned int sector_count, unsigned int *buffer, unsigned int blocking, unsigned int *error_out)
{
    int *const debug_level = &D_005A0D90;
    unsigned int result, sectors_returned, error_code, last_error;
    int sectors_read;

    if (*debug_level > 0)
        func_004FD2D0("sceCdStRead call read size= %d mode= %d\n", sector_count, blocking);
    if (D_005A2934 == 0)
        return 0;
    last_error = 0;
    sectors_read = 0;
    /* Write back the destination cache lines before the IOP transfers data. */
    func_004FDAF8(buffer, sector_count << 11);
    if (blocking != 0) {
        do {
            result = func_004E1E70(0, sector_count - sectors_read, (char *)buffer + (sectors_read << 11), 2, D_0078B110);
            sectors_returned = result & 0xFFFF;
            error_code = result >> 16;
            sectors_read += sectors_returned;
            if (error_code != 0) {
                last_error = error_code;
                if (*debug_level > 0)
                    func_004FD2D0("sceCdStRead BLK Read cur_size= %d read_size= %d req_size= %d err 0x%x\n",
                                  sectors_read, sectors_returned, sector_count, error_code);
            } else if (sectors_returned == 0) {
                func_004FB898(600);
            }
        } while (sectors_read != sector_count && (error_code == 0 || sectors_returned != 0));
        if (*debug_level > 0)
            func_004FD2D0("sceCdStRead BLK Read Ended\n");
        *error_out = last_error;
    } else {
        result = func_004E1E70(0, sector_count, buffer, 2, D_0078B110);
        error_code = result >> 16;
        sectors_read = result & 0xFFFF;
        *error_out = error_code;
    }
    return sectors_read;
}
