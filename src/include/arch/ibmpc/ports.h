#ifndef __arch_ports__
#define __arch_ports__

#define PIC0_CMD            0x20    // master 8259 command port
#define PIC0_DATA           0x21    // master 8259 data port
#define PIC1_CMD            0xA0    // slave  8259 command port
#define PIC1_DATA           0xA1    // slave  8259 data port

#define PIT_PORT0           0x40    // timer channel 0 port
#define PIT_PORT2           0x42    // timer channel 2 port
#define PIT_CMD             0x43    // timer command port

#define KBD_DATA            0x60    // keyboard data port
#define KBD_CMD             0x64    // keyboard command port

#define VID_CMD             0x3D4   // video command port
#define VID_DATA            0x3D5   // video data port

#endif
