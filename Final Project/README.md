# Robotic Arm Controller

This project is a microcontroller-based system to control a **robotic arm** using a keypad, LCD display, servo motor, and three stepper motors. It allows manual movement control and visual feedback using a 4x4 keypad and an LCD screen.

---

## 🛠 Features

- Control **three stepper motors** (base, shoulder, elbow)
- Adjust **servo motor angle** (gripper or wrist)
- LCD displays action/status in real-time
- Keypad interface for selecting direction or movement
- Modular HAL and MCAL architecture for scalability

---

## 📦 Hardware Connections

| Port   | Pins        | Component           |
|--------|-------------|---------------------|
| PORTB  | All         | 4x4 Keypad          |
| PORTC  | All         | LCD (4-bit mode)    |
| PORTA  | 0–3         | Stepper Motor 1     |
| PORTA  | 4–7         | Stepper Motor 2     |
| PORTD  | 0–3         | Stepper Motor 3     |
| PORTD  | Pin 5       | Servo Motor (PWM)   |

---

## 🎮 Keypad Controls

| Key | Function             |
|-----|----------------------|
| 1   | Stepper 1 CW         |
| 2   | Stepper 1 CCW        |
| 4   | Stepper 3 CW         |
| 5   | Stepper 3 CCW        |
| 7   | Servo +Angle         |
| 8   | Servo -Angle         |

---

## 🔧 Dependencies

This project uses a layered architecture:

- **MCAL**: DIO, TIMER1, I2C, ADC, SPI, External Interrupts, Global Interrupts
- **HAL**: LCD, Keypad, Stepper Motor

Make sure all modules are implemented and configured correctly.

---

## 🚀 Getting Started

1. Clone the repository.
2. Compile using AVR-GCC or load into AVR IDE (e.g., Atmel Studio, PlatformIO).
3. Flash the firmware to an ATmega32 or similar microcontroller.
4. Connect hardware as per the pin mapping.
5. Power the circuit and start controlling the robotic arm!

---

## 📄 License

This project is open-source and available under the Abdalrahman License.

---

## 🙋‍♂️ Author

Developed by **[Abdalrahman]** – feel free to fork, modify, or contribute.
