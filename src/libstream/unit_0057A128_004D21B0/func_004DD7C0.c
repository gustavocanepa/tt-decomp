/* compiler: ee-gcc2.9-991111 */
/* Decode forty presence bits into packed-field descriptors. Fields 16..31
 * and 35..38 consume a full byte; the remaining present fields consume a bit.
 * An absent descriptor retains its old width, as in the original. */
struct Descriptor { int present, width, byte_offset, bit_offset; };
int func_004DD7C0(const unsigned char *bitmap, struct Descriptor *out) {
    int bitmap_bit=0;
    int byte_offset=0;
    int field;
    int bit_offset;
    bit_offset=0;
    field=0;
    do {
        if((*bitmap>>bitmap_bit)&1) {
            out->present=1;
            out->byte_offset=byte_offset;
            out->bit_offset=bit_offset;
            if((unsigned)(field-16)<16 || (unsigned)(field-35)<4) {
                out->width=8;
                ++byte_offset;
            } else {
                out->width=1;
                ++bit_offset;
                if((bit_offset&7)==0) {++byte_offset;bit_offset=0;}
            }
        } else {
            out->present=0;
            out->byte_offset=0;
            out->bit_offset=0;
        }
        ++bitmap_bit;
        if((bitmap_bit&7)==0) {++bitmap;bitmap_bit=0;}
        ++field;
        ++out;
    } while(field<40);
    return 1;
}
