# ATmega32 Drivers and Applications 🚀

This repository contains a collection of **bare-metal drivers** and example **applications** developed for the **ATmega32 microcontroller**. It demonstrates core embedded systems concepts using **C language**, including low-level register manipulation, peripheral interfacing, and modular driver development.

---

## 📂 Repository Structure

# Atmega32-Drivers-and-Applications
Atmega32-Drivers-and-Applications/
│
├── MCAL/ # Microcontroller Abstraction Layer
│ ├── DIO/ # Digital I/O driver
│ ├── ADC/ # Analog-to-Digital Converter driver
│ ├── TIMER/ # Timer0/1/2 drivers
│ ├── UART/ # UART communication driver
│ ├── SPI/ # SPI protocol driver
│ ├── I2C/ # I2C protocol driver
│ └── ... # Other core MCAL modules
│
├── HAL/ # Hardware Abstraction Layer
│ ├── LCD/ # Character LCD driver
│ ├── KEYPAD/ # Matrix keypad driver
│ ├── SEVEN_SEG/ # 7-segment display driver
│ ├── STEPPER/ # Stepper motor control
│ └── ... # Additional components
│
├── APP/ # Application examples
│ ├── Calculator/
│ ├── LCD_Keypad_Demo/
│ └── ...
│
├── LIB/ # Shared utility macros and typedefs
│ ├── BIT_MATH.h
│ └── STD_TYPES.h
│
└── README.md # This file


---

## ⚙️ Features

- 🧠 Modular MCAL & HAL drivers
- ⌨️ Keypad & LCD interface demo
- ⏲️ Timer, PWM, and delay handling
- 📡 UART, SPI, and I2C communication
- 🔢 ADC reading and 7-segment output
- 🚦 Mini projects like calculator, traffic light, and stepper control

---

## 🔧 Tools Used

- **AVR-GCC** (WinAVR or avr-gcc)
- **AVRDUDE** for flashing
- **Proteus** or **real hardware** for testing
- **Eclipse** or **VS Code** with Makefile/CMake

---

## 📚 How to Use

1. Clone the repo:
   ```bash
   git clone https://github.com/Albakatoshy/Atmega32-Drivers-and-Applications.git
