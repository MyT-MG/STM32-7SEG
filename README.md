# STM32-7SEG  
Interfacing a 7-Segment LED Display with STM32F103

## 📋 Overview  
This project demonstrates how to drive a single‐digit common-anode (or common-cathode) 7-segment LED display using an STM32F103 microcontroller.  
The included files contain a complete demo: schematic (Proteus), source code (`main.c`), and compiled firmware (`main.hex`).

## 🧩 Features  
- Direct GPIO control of each of the 7 segments (A–G) plus the decimal point (DP)  
- Simple incremental count from 0 to 9 (or custom pattern)  
- Easy to expand to multiplexing multiple digits  
- Example using the STM32 Standard Peripheral Library / HAL (as per your code style)  
- Proteus simulation and practical hardware reference included  
  - `Proteus-sim.pdsprj` — Proteus project file  
  - `STM32-7segLED.pdf` — Design & wiring notes  

## 🛠️ Hardware Requirements  
- STM32F103 board (e.g., “Blue Pill” or equivalent)  
- 7-Segment LED module (single digit)  
- Current-limiting resistors for each segment (e.g., 330 Ω)  
- Wires, breadboard or PCB  
- Optional: Proteus simulation software for testing  

## 📌 Pinout / Wiring  
| Segment | STM32 GPIO | Description           |
|---------|------------|------------------------|
| A       | PA0        | Segment A              |
| B       | PA1        | Segment B              |
| C       | PA2        | Segment C              |
| D       | PA3        | Segment D              |
| E       | PA4        | Segment E              |
| F       | PA5        | Segment F              |
| G       | PA6        | Segment G              |
| DP      | PA7        | Decimal Point (optional) |

> **Note:** Adjust the pin mapping to match your wiring and board layout.


## 🚀 How to Build & Run  
1. Open `main.c` in your STM32 IDE (e.g., STM32CubeIDE, Keil, or whichever you use).  
2. Ensure the GPIO pins match the wiring in your hardware layout.  
3. Compile the project and generate the `.hex` or `.bin`.  
4. Flash the firmware (`main.hex`) onto your STM32F103 board (via ST-Link, USB, or other programmer).  
5. Power the board: the 7-segment display should begin counting from 0 to 9 repeatedly (or display your configured pattern).

## 📐 Customize / Expand  
- **Change count sequence:** Modify the array of segment bit-patterns in `main.c` to show custom characters (A–F, dash, etc.).  
- **Multiplex multiple digits:** Add additional digit enable lines and time‐multiplex segment outputs for multi‐digit displays.  
- **Use driver chips:** For larger displays or higher current, interface via shift-registers (e.g., 74HC595) or LED driver ICs.  
- **Interrupt / Timer usage:** Replace the simple delay loop with a hardware timer interrupt for smoother display and better CPU usage.

## ⚠️ Troubleshooting  
- Display is blank? → Check that the segment resistors are connected, common anode/cathode orientation is correct, and your power and ground are aligned.  
- Some segments flicker or don’t light? → Verify GPIO pin configuration (Push‐Pull vs Open‐Drain), check for shorts, or increase resistor value if current limiting.  
- Display count not correct? → Double‐check segment mapping and ensure the bit‐patterns in the lookup array map correctly to your wiring.

## 📄 Documentation  
For a detailed schematic, wiring guide, and simulation setup, see `STM32-7segLED.pdf`.

## 🤝 Contribution  
Contributions are welcome! Feel free to:  
- Add support for multiple digits  
- Use SPI/I²C LED driver ICs  
- Provide KiCad/Altium board layouts  
- Write a detailed guide for multiplexing or 7-segment fonts  

Please open an issue or pull request.
