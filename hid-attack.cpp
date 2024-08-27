#include <VUSB.h>

// Define the keyboard report structure
typedef struct {
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
} keyboard_report_t;

keyboard_report_t report = {0, 0, {0, 0, 0, 0, 0, 0}};

void setup() {
  // Initialize V-USB
  VUSB.begin();
  
  // Simulate keyboard actions after a short delay
  delay(5000);

  // Press Win+R to open Run dialog
  pressKey(KEY_LEFT_GUI);
  pressKey('r');
  releaseAllKeys();
  
  delay(500);

  // Type 'cmd' and press Enter
  typeString("cmd");
  pressKey(KEY_RETURN);
  releaseAllKeys();
  
  delay(500);

  // Type 'curl parrot.live' and press Enter
  typeString("curl parrot.live");
  pressKey(KEY_RETURN);
  releaseAllKeys();
}

void loop() {
  // Nothing to do here
}

void pressKey(uint8_t key) {
  report.keys[0] = key;
  VUSB.sendReport(&report, sizeof(report));
}

void releaseAllKeys() {
  report.keys[0] = 0;
  VUSB.sendReport(&report, sizeof(report));
}

void typeString(const char* str) {
  while (*str) {
    pressKey(*str++);
    releaseAllKeys();
    delay(50);
  }
}
