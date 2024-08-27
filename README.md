# Arduino Nano HID Keyboard Using V-USB

This project demonstrates how to use an Arduino Nano, equipped with an ATmega328P microcontroller, as a USB HID keyboard. By leveraging the V-USB library, this setup allows the Arduino Nano to simulate keyboard input when connected to a computer.

## Overview

The ATmega328P microcontroller on the Arduino Nano does not natively support USB HID functionality. This project circumvents this limitation by utilizing the V-USB library and additional external components to enable HID capabilities. This allows the Arduino Nano to act as a USB keyboard, sending keystrokes to a connected PC.

## Components Required

- **Arduino Nano** (ATmega328P)
- **2x 68Ω Resistors**
- **1x 1.5kΩ Resistor**
- **2x 3.6V Zener Diodes**
- **1x 0.1µF Capacitor**
- **Breadboard and Jumper Wires**

## Hardware Setup

1. **USB Data Lines (D+ and D-)**:
   - Connect 68Ω resistors between the D- and D+ lines and their corresponding pins on the ATmega328P.
   - Place 3.6V Zener diodes between D- and ground, and D+ and ground (cathode to D-, anode to ground; cathode to D+, anode to ground).
   - Connect a 1.5kΩ resistor between D+ and Vcc (5V).

2. **Capacitor**:
   - Place a 0.1µF capacitor between Vcc and ground to stabilize the power supply.

## Software Setup

1. **Install V-USB Library**:
   Download and install the V-USB library from [V-USB GitHub Repository](https://github.com/nerdralph/vusb-for-arduino).

2. **Upload the Code**:
   Use the provided Arduino sketch to simulate HID keyboard actions. This code will:
   - Open the Run dialog with Win+R.
   - Type `cmd` and press Enter to open the Command Prompt.
   - Type `curl parrot.live` and press Enter.

## Notes

- This project requires careful hardware setup to avoid damaging the USB port or the ATmega328P microcontroller.
- The V-USB library and additional components are crucial for enabling HID functionality on the ATmega328P.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

For any questions or issues, please open an issue on the GitHub repository.

---

Feel free to adjust the content to fit your specific needs or add any additional details relevant to your project.
