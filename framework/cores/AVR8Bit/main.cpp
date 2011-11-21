#include <Wiring.h>

int main(void) 
{
  // Hardware specific initializations.
  boardInit();

  // USB setup if available
#if defined(USBCON)
  USB.attach();
#endif

  // User defined setup routine
  setup();
  // User defined loop routine
  for (;;)
    loop();
}
