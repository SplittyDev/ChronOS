#ifndef _ARCH_I386_SERIAL_H
#define _ARCH_I386_SERIAL_H

#include <stdint.h>

#include <kernel/device.h>

#define COM1_PORT  0x3F8
#define COM2_PORT  0x2F8
#define COM3_PORT  0x3E8
#define COM4_PORT  0x2E8

namespace Driver {

class Serial : public Device {
public:
  Serial (const char *name, uint16_t port);
  ~Serial ();

  size_t Read (void *buffer, size_t len, uint32_t address);
  size_t Write (const void *buffer, size_t len, uint32_t address);

  void EnablePort ();
  bool Empty ();
  void PutC (char c);
private:
  uint16_t port;
};

static Serial COM1 ("COM1", COM1_PORT);
static Serial COM2 ("COM2", COM2_PORT);
static Serial COM3 ("COM3", COM3_PORT);
static Serial COM4 ("COM4", COM4_PORT);

}

#endif
