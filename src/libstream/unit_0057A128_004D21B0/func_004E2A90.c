/* libio (GNU iostream library, gcc 2000-10-03 snapshot): istream::tellg.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Dev { int fd; char pad[0x16]; unsigned char flags; };
struct File { struct Dev *dev; };
int func_004E7A80(int fd, int off, int whence, int mode);

int func_004E2A90(struct File *f)
{
    int r = func_004E7A80(f->dev->fd, 0, 1, 1);
    if (r == -1)
        f->dev->flags |= 4;
    return r;
}
