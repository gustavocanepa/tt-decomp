/* compiler: ee-gcc2.9-991111 */
typedef struct {
    unsigned int crc32;
    unsigned int uncompressed_size;
} __attribute__((packed)) GzipTrailer;
extern const unsigned char *func_004D9CF8(const unsigned char *);
extern int func_004D90E8(void *, int, const unsigned char *, const GzipTrailer **);

/* Inflate a gzip member and validate its stored output length. The checksum
 * is returned to the caller when requested; this function does not verify it. */
int func_004D9A50(void *output, int capacity, const unsigned char *gzip,
                  unsigned int *crc32)
{
    GzipTrailer trailer;
    const GzipTrailer *end;
    const unsigned char *compressed = func_004D9CF8(gzip);
    int written;
    if (!compressed)
        return -1;
    if (gzip[2] != 8)
        return -2;
    written = func_004D90E8(output, capacity, compressed, &end);
    if (written < 0)
        return written;
    trailer = *end;
    if (written != trailer.uncompressed_size)
        return -1;
    if (crc32)
        *crc32 = trailer.crc32;
    return written;
}
