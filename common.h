///////////////////////////////////////////////////////////////////////////////
// Code that will be useful in different types of kernels.
///////////////////////////////////////////////////////////////////////////////

extern char volatile * const DLC_Configuration;
extern char volatile * const DLC_InterruptConfiguration;
extern char volatile * const DLC_Transmit_Command;
extern char volatile * const DLC_Transmit_FIFO;
extern char volatile * const DLC_Status;
extern char volatile * const DLC_Receive_FIFO;
extern char volatile * const Watchdog1;
extern char volatile * const Watchdog2;

///////////////////////////////////////////////////////////////////////////////
//
// The linker needs to put these buffers after the kernel code, but before the
// system registers that are at the top of the RAM space.
//
// The code that extracts the kernel bin needs to exclude that address range,
// because it will just add 8kb of 0x00 bytes to the kernel bin file.
//
// 4096 == 0x1000
#define MessageBufferSize 1024
#define BreadcrumbBufferSize 6
extern unsigned char __attribute((section(".kerneldata"))) MessageBuffer[];

// Code can add data to this buffer while doing something that doesn't work
// well, and then dump this buffer later to find out what was going on.
extern unsigned char __attribute((section(".kerneldata"))) BreadcrumbBuffer[];

// Uncomment one of these to determine which way to use the breadcrumb buffer.
//#define RECEIVE_BREADCRUMBS
//#define TRANSMIT_BREADCRUMBS
//#define MODEBYTE_BREADCRUMBS

///////////////////////////////////////////////////////////////////////////////
// This needs to be called periodically to prevent the PCM from rebooting.
///////////////////////////////////////////////////////////////////////////////
void ScratchWatchdog();

///////////////////////////////////////////////////////////////////////////////
// Does what it says.
///////////////////////////////////////////////////////////////////////////////
int WasteTime();

///////////////////////////////////////////////////////////////////////////////
// Also does what it says. 10,000 iterations takes a bit less than half a second.
///////////////////////////////////////////////////////////////////////////////
int LongSleepWithWatchdog();

///////////////////////////////////////////////////////////////////////////////
// All outgoing messages must be written into this buffer. The WriteMessage
// function will copy from this buffer to the DLC. Resetting the buffer should
// not really be necessary, but it helps to simplify debugging.
///////////////////////////////////////////////////////////////////////////////
void ClearMessageBuffer();

///////////////////////////////////////////////////////////////////////////////
// The 'breadcrumb' buffer helps give insight into what happened.
///////////////////////////////////////////////////////////////////////////////
void ClearBreadcrumbBuffer();

///////////////////////////////////////////////////////////////////////////////
// Message handlers
///////////////////////////////////////////////////////////////////////////////
void HandleReadMode35();
void HandleWriteRequestMode34();
void HandleWriteMode36();

///////////////////////////////////////////////////////////////////////////////
// Indicates whether the buffer passed to WriteMessage contains the beginning,
// middle, or end of a message. 
///////////////////////////////////////////////////////////////////////////////
typedef enum
{
	Invalid = 0,
	Start = 1,
	Middle = 2,
	End = 4,
	Complete = Start | End,
} Segment;

///////////////////////////////////////////////////////////////////////////////
// Send the given bytes over the VPW bus.
// The DLC will append the checksum byte, so we don't have to.
// The message must be written into MessageBuffer first.
// This function will send 'length' bytes from that buffer onto the wire.
///////////////////////////////////////////////////////////////////////////////
void WriteMessage(char* start, int length, Segment segment);

///////////////////////////////////////////////////////////////////////////////
// Read a VPW message into the 'MessageBuffer' buffer.
///////////////////////////////////////////////////////////////////////////////
int ReadMessage(char *completionCode, char *readState);

///////////////////////////////////////////////////////////////////////////////
// TODO: REMOVE.
// Copy the given buffer into the message buffer.
///////////////////////////////////////////////////////////////////////////////
void CopyToMessageBuffer(char* start, int length, int offset);

///////////////////////////////////////////////////////////////////////////////
// Send a message to explain why we're rebooting, then reboot.
///////////////////////////////////////////////////////////////////////////////
void Reboot(unsigned int value);

///////////////////////////////////////////////////////////////////////////////
// Send a tool-present message with 3 extra data bytes for debugging.
///////////////////////////////////////////////////////////////////////////////
void SendToolPresent(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
void SendToolPresent2(unsigned int value);

///////////////////////////////////////////////////////////////////////////////
// Send the breadcrumb array, then reboot.
// This is useful in figuring out how the kernel got into a bad state.
///////////////////////////////////////////////////////////////////////////////
void SendBreadcrumbsReboot(char code, int breadcrumbs);

///////////////////////////////////////////////////////////////////////////////
// Comput the checksum for the header of an outgoing message.
///////////////////////////////////////////////////////////////////////////////
unsigned short StartChecksum();

///////////////////////////////////////////////////////////////////////////////
// Copy the payload for a read request, while updating the checksum.
///////////////////////////////////////////////////////////////////////////////
unsigned short AddReadPayloadChecksum(char* start, int length);

///////////////////////////////////////////////////////////////////////////////
// Set the checksum for a data block.
///////////////////////////////////////////////////////////////////////////////
void SetBlockChecksum(int length, unsigned short checksum);

///////////////////////////////////////////////////////////////////////////////
// Utility functions to compute CRC for memory ranges.
///////////////////////////////////////////////////////////////////////////////
void crcInit(void);
unsigned int crcFast(unsigned char const message[], int nBytes);