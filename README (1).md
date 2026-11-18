# 💡 Light Up Epoxy Resin Table

A hardware and design project that blends **wood, epoxy resin and smart LED lighting** into a modern decorative table. LED strips glow through the resin, and a sensor-based controller switches them on automatically.

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/Embedded%20C%2FC%2B%2B-00599C?style=flat&logo=cplusplus&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=flat)

<!-- EDIT: add a photo of your finished table. Upload it to this repo in an "images" folder, then use:
![Finished table](images/table.jpg) -->

## ✨ Features

- Wooden table combined with a clear **epoxy resin** section
- **LED strip** lighting placed to give a modern glow through the resin
- **Sensor-based automatic control**: LEDs turn on when the room gets dark
- Smooth fade in and fade out using PWM
- Circuit assembly, wiring and hardware integration done by hand
- Functional testing of LED performance and circuit connections

## 🧰 Components Used

<!-- EDIT: change this list to match exactly what you used -->

| Component | Purpose |
|-----------|---------|
| Wood | Table frame and top |
| Epoxy resin | Clear, glossy resin section |
| LED strip | Lighting effect |
| Arduino / LED controller | Controls the LEDs |
| Sensor (light sensor / LDR) | Detects room brightness |
| Power supply | Powers the LED strip |
| MOSFET, resistors, wires | Switching and circuit connections |

## 🔌 Circuit Overview

<!-- EDIT: update the pins if your wiring is different -->

```
Power supply (+) ──► LED strip (+)
LED strip (−)    ──► MOSFET drain
MOSFET gate      ◄── Arduino pin 9 (via 220 Ω resistor)
MOSFET source    ──► GND (shared by Arduino and power supply)

Light sensor (LDR) ── 5V ── LDR ──┬── A0
                                  └── 10 kΩ ── GND
```

> Important: the Arduino, the MOSFET and the power supply must **share a common ground**.

## 🚀 How to Run

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Open `epoxy_table_led.ino` (the IDE will offer to put it in a folder of the same name, click OK).
3. Select your board and port under **Tools**.
4. Click **Upload**.
5. Open the **Serial Monitor** (9600 baud) to see the light readings, and adjust `TURN_ON_BELOW` and `TURN_OFF_ABOVE` in the code to match your room.

## 🧪 Testing

- Checked that every LED section lights up evenly
- Tested the circuit connections and wiring for loose joints
- Tested the sensor in bright and dark conditions to set the thresholds
- Checked the power supply under full LED load

## 🛠️ Tech Stack

`Wood` `Epoxy Resin` `LED Strip` `Arduino / LED Controller` `Sensors` `Power Supply` `Electrical Wiring` `Basic Embedded Programming`

## 🔮 Future Improvements

- Add a remote or phone app (Bluetooth) to change colors and brightness
- Switch to RGB LED strips for color effects
- Add a manual override button

## 👩‍💻 Author

**Kanipakam Nireesha**: [LinkedIn](https://www.linkedin.com/in/nireesha-k-66474b257) · [GitHub](https://github.com/Nireeshaniree)
