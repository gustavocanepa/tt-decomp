/* compiler: ee-gcc2.9-991111 */
/* Byte ring buffer header (data follows at +0x10): advance the func_005AE2E8 cursor, wrapping at the end. */
struct RingBuffer {
	int capacity;
	int count;
	char *readPos;
	char *writePos;
	char data[1];
};

extern "C" void func_004FBB68(RingBuffer *rb)
{
	rb->count--;
	rb->readPos++;
	if (rb->readPos == (char *)rb + (rb->capacity + 0x10))
		rb->readPos = rb->data;
}
