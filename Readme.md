# 🚗 Automated Parking LOT System



-----------------------------------------------------------------------------------------------------------------------------------

## 📖 Introduction

The ** Automated Parking LOT System** is an embedded application designed to automate parking lot management using the **ATmega32 AVR Microcontroller**. The system controls vehicle entry and exit, monitors parking occupancy, manages gate operation using servo motors, and provides real-time information through an LCD display and UART communication.

The project follows a **Layered Architecture (MCAL / HAL / APP)** to ensure modularity, reusability, and maintainability while applying embedded systems concepts such as GPIO, External Interrupts, Timers, PWM, UART communication, and finite state machine design.

-----------------------------------------------------------------------------------------------------------------------------------

## 🎯 Project Goals

- Automate parking lot access.
- Improve parking management efficiency.
- Monitor available parking spaces in real time.
- Prevent vehicle entry when the parking lot is full.
- Provide administrator control through password authentication.
- Log important system events using UART.
- Demonstrate modular embedded software development.

-----------------------------------------------------------------------------------------------------------------------------------

## 🚀 Key Features

- Automatic vehicle entry and exit control.
- Servo motor gate operation using PWM.
- Real-time parking occupancy management.
- LCD user interface.
- Password-protected administrator mode.
- Manual gate control.
- Parking full detection.
- Event logging through UART.
- LED status indicators.
- Modular layered software architecture.

-----------------------------------------------------------------------------------------------------------------------------------

## 🏗️ System Architecture

```
                +----------------------+
                |        APP           |
                | Parking Controller   |
                +----------+-----------+
                           |
          +----------------+----------------+
          |                                 |
     +----+-----+                     +-----+-----+
     |   HAL    |                     |    MCAL   |
     | LCD      |                     | DIO       |
     | Keypad   |                     | EXTI      |
     | Servo    |                     | TIMER1    |
     | LED      |                     | UART      |
     +----------+                     +-----------+
```

-----------------------------------------------------------------------------------------------------------------------------------
## 🚗 System Flow

```text
                        +----------------------+
                        |      Power ON        |
                        +----------+-----------+
                                   |
                                   ▼
                     Initialize All Peripherals
        (DIO, EXTI, TIMER1, UART, LCD, Keypad, Servo, LED)
                                   |
                                   ▼
                      Display Parking Information
                                   |
                                   ▼
                           Wait for Request
                                   |
                 +-----------------+-----------------+
                 |                                   |
                 ▼                                   ▼
          Vehicle Entry                      Vehicle Exit
                 |                                   |
                 ▼                                   ▼
      Check Available Spaces               Detect Exit Event
                 |
         +-------+-------+
         |               |
        YES             NO
         |               |
         ▼               ▼
 Display "Parking   Open Entry Gate
      Full"               |
         |                ▼
 Reject Entry      Update Parking Counter
         |                |
         ▼                ▼
 Turn ON Red LED    Update LCD Display
         |                |
         ▼                ▼
 Send UART Log      Send UART Log
         |                |
         +--------+-------+
                  |
                  ▼
            Close Gate
                  |
                  ▼
             Return to IDLE
```
------------------------------------------------------------------------------------------------------------------------------
## 🧠 System State Machine

                        +------------------+
                        |      INIT        |
                        | Hardware Setup   |
                        +--------+---------+
                                 |
                                 ▼
                        +------------------+
                        |      IDLE        |
                        | Waiting Request  |
                        +---+----------+---+
                            |          |
          Entry Request     |          | Exit Request
                            |          |
                            ▼          ▼
                    +-----------+   +-----------+
                    |   ENTRY   |   |   EXIT    |
                    +-----+-----+   +-----+-----+
                          |                 |
                          ▼                 ▼
                Update Parking      Update Parking
                    Counter             Counter
                          |                 |
                          ▼                 ▼
                     Close Gate        Close Gate
                          |                 |
                          └───────┬─────────┘
                                  │
                                  ▼
                               +------+
                               | IDLE |
                               +------+

                     Parking Full Detected
                                  │
                                  ▼
                        +------------------+
                        |      FULL        |
                        | Entry Rejected   |
                        | Exit Allowed     |
                        +--------+---------+
                                 │
                                 ▼
                               IDLE

                      Administrator Login
                                 │
                                 ▼
                        +------------------+
                        |      ADMIN       |
                        | Manual Control   |
                        | Reset Counter    |
                        | Change Capacity  |
                        +--------+---------+
                                 │
                                 ▼
                               IDLE

                         System Fault
                                 │
                                 ▼
                        +------------------+
                        |      ERROR       |
                        | Fault Handling   |
                        +--------+---------+
                                 │
                                 ▼
                               INIT

-----------------------------------------------------------------------------------------------------------------------------------

## 📊 Software Modules

Main --> ParkingManager

ParkingManager --> GateController

ParkingManager --> SpotCounter

ParkingManager --> LCD

ParkingManager --> Keypad

ParkingManager --> UART

ParkingManager --> EXTI

GateController --> Servo

SpotCounter --> VehicleSensor

-----------------------------------------------------------------------------------------------------------------------------------
## ⚙️ Hardware Components

| Component | Purpose |
|-----------|---------|
| ATmega32 | Main Controller |
| LCD 16x2 | User Interface |
| 4×4 Keypad | Password Entry |
| Servo Motors | Gate Control |
| Push Buttons | Vehicle Detection |
| LEDs | Status Indicators |
| Virtual Terminal | UART Monitoring |

-----------------------------------------------------------------------------------------------------------------------------------

## 💻 Software Stack

| Layer | Drivers |
|-------|---------|
| APP | Parking Logic |
| HAL | LCD, Keypad, Servo, LED |
| MCAL| DIO, EXTI, TIMER1, UART |
| Common| STD_TYPES, BIT_MATH |

-----------------------------------------------------------------------------------------------------------------------------------

## 🔄 System Workflow

1. Initialize all peripherals.
2. Display parking information on LCD.
3. Wait for vehicle entry or exit request.
4. Verify parking availability.
5. Open gate using Servo Motor.
6. Update parking counters.
7. Display updated status.
8. Send UART log.
9. Return to idle state.

-----------------------------------------------------------------------------------------------------------------------------------
## 📂 Project Structure

```text
Automated_Parking_System/
│
├── APP
│   ├── APP.c
│   ├── APP.h
│   └── main.c
│
├── HAL
│   ├── LCD
│   │   ├── LCD_Interface.h
│   │   ├── LCD_Config.h
│   │   ├── LCD_Private.h
│   │   └── LCD_Program.c
│   │
│   ├── KEYPAD
│   │   ├── KPD_Interface.h
│   │   ├── KPD_Config.h
│   │   ├── KPD_Private.h
│   │   └── KPD_Program.c
│   │
│   ├── SERVO
│   │   ├── SERVO_Interface.h
│   │   ├── SERVO_Config.h
│   │   ├── SERVO_Private.h
│   │   └── SERVO_Program.c
│   │
│   └── LED
│       ├── LED_Interface.h
│       ├── LED_Config.h
│       ├── LED_Private.h
│       └── LED_Program.c
│
├── MCAL
│   ├── DIO
│   ├── EXTI
│   ├── TIMER1
│   └── UART
│
├── LIB
│   ├── STD_TYPES.h
│   ├── BIT_MATH.h
│   └── Common_Macros.h
│
├── Proteus
│   ├── Parking_System.pdsprj
│   └── HEX_File
│
└── README.md
```

-----------------------------------------------------------------------------------------------------------------------------------
## 📌 Pin Configuration

| Peripheral | ATmega32 Pin | Port | Description |
|------------|--------------|------|-------------|
| LCD Data (D0–D7) | PA0–PA7 | PORTA | LCD 8-bit Data Bus |
| LCD RS | PB0 | PORTB | Register Select |
| LCD RW | PB1 | PORTB | Read / Write |
| LCD EN | PB2 | PORTB | Enable Signal |
| Keypad Row 0 | PC0 | PORTC | Row 0 |
| Keypad Row 1 | PC1 | PORTC | Row 1 |
| Keypad Row 2 | PC2 | PORTC | Row 2 |
| Keypad Row 3 | PC3 | PORTC | Row 3 |
| Keypad Column 0 | PC4 | PORTC | Column 0 |
| Keypad Column 1 | PC5 | PORTC | Column 1 |
| Keypad Column 2 | PC6 | PORTC | Column 2 |
| Keypad Column 3 | PC7 | PORTC | Column 3 |
| Entry Button | PD2 (INT0) | PORTD | Vehicle Entry Detection |
| Exit Button | PD3 (INT1) | PORTD | Vehicle Exit Detection |
| Entry Servo | PD5 (OC1A) | PORTD | Entry Gate PWM |
| Exit Servo | PD4 (OC1B) | PORTD | Exit Gate PWM |
| Green LED | PB3 | PORTB | Parking Available Indicator |
| Red LED | PB4 | PORTB | Parking Full Indicator |
| UART TX | PD1 (TXD) | PORTD | UART Transmission |
| UART RX | PD0 (RXD) | PORTD | UART Reception |
```

-----------------------------------------------------------------------------------------------------------------------------------
## 📡 UART Log Example

->text<-
SYSTEM READY
ENTRY GATE OPENED
VEHICLE ENTERED
AVAILABLE SPACES : 18
VEHICLE EXITED
PARKING FULL
ADMIN LOGIN
SYSTEM RESET


-----------------------------------------------------------------------------------------------------------------------------------

## 🛠️ Development Tools

- Microchip Studio
- Proteus Professional
- AVR-GCC
- Git
- GitHub

-----------------------------------------------------------------------------------------------------------------------------------

👥 Team 4 -----=> Embedded_Elite <=-----

| Team Member | Role | Responsibilities |
|-------------|------|------------------|
| *Abdulrahman Ali Abdelaziz Ali* | *Team Leader & MCAL/HAL Developer* | Project Architecture, APP Layer Development, DIO Driver, Keypad Driver, System Integration, GitHub Management, Documentation (README), Code Review, Final Testing & Debugging |
| *Yousef Mohamed Al-Sayed Abohashem Hassan* | *MCAL/HAL Developer* | EXTI Driver, LED Driver |
| *Omar Hamdy Hamed Abdelrahman* | *HAL & Communication Developer* | LCD Driver, UART Driver |
| *Omar Alaa Eldin Abdelrady* | *MCAL Developer* | Timer1 Driver, PWM Generation |
| *Mina Ramy Rizk Youssef* | *HAL Developer & Simulation Engineer* | Servo Motor Driver, Proteus Simulation, Hardware Integration |

-----------------------------------------------------------------------------------------------------------------------------------

👨‍🏫 Supervisor

**Eng. Hesham Ahmed**

-----------------------------------------------------------------------------------------------------------------------------------

📜 License

Developed as part of the **NTI Embedded Systems Training Program** for educational purposes.

-----------------------------------------------------------------------------------------------------------------------------------

⭐ Acknowledgment

Special thanks to **National Telecommunication Institute (NTI)** and **Eng. Hesham Ahmed** and **Gestell Team** for their guidance and support throughout the project.

-----------------------------------------------------------------------------------------------------------------------------------