# SoC Practice: Ascending Timer with Keypad, LCD and TPM0  
Andre - Santi - Jared - Joshua

This project implements an embedded system that allows the user to configure and execute an ascending timer using a keypad interface, displaying real-time information on an LCD and using hardware timer interrupts for precise timing.

---

## Materials Used

To replicate this project, the following hardware is required:

- Microcontroller: KL25Z  
- Display: LCD (16x2) operating in 8-bit mode  
- Input Device: 4x4 Matrix Keypad  
- Output Device: RGB LED (or single LED)  
- Extra Components: Breadboard, jumper wires  

---

## System Features

- User Input via Keypad:  
  The user can enter a time value (in seconds) using multiple digits.

- Dynamic Timer Configuration:  
  The entered value defines the duration of the timer.

- Interrupt-Based Timing:  
  TPM0 is used to generate periodic interrupts, ensuring accurate time counting.

- Real-Time Display:  
  The LCD shows the current timer value in the format `t = current / total`.

- Visual Feedback:  
  An LED turns on when the timer reaches the specified value.

---

## Architecture and Pin Mapping

### Keypad - Port C
- Rows (Outputs): PTC0 – PTC3  
- Columns (Inputs): PTC4 – PTC7  
- Configured using scanning method  

### LCD Screen - Ports A and D (8-Bit Mode)
- Data Bus: PTD0 – PTD7  
- Control Pins:  
  - RS: PTA2  
  - RW: PTA4  
  - EN: PTA5  

### RGB LED
- Red: PTB18  
- Green: PTB19  
- Blue: PTD1  

### Timer Module
- TPM0: Generates periodic interrupts (~0.1 s base)  
- Internal logic accumulates to achieve 1-second timing  

---

## Execution Flow

### Initialization
- Initialize keypad, LCD, LED, and TPM0  
- Display "Hello" for 5 seconds  
- Prompt user with "Cuantos seg:"  

---

### User Input
- User enters digits using keypad  
- Multiple digits are stored in a buffer  
- Input ends when `*` key is pressed  

---

### Timer Start
- Input value is converted to integer  
- Timer variables are reset  
- System enters RUNNING state  
- LCD displays "Counting..."  

---

### Main Loop
- Continuously scans keypad  
- If running:
  - Displays current count vs total time  
  - Updates LCD in real time  

---

### Timer Interrupt (TPM0)
- Executes periodically (~0.1 s)  
- Accumulates ticks  
- Every 1 second:
  - Increments contador  

---

### Timer Completion
- When contador >= segundos:
  - Timer stops  
  - LCD displays "FIN!"  
  - LED turns ON  

---

## System Behavior

- System starts idle after greeting  
- User inputs desired time using keypad  
- Pressing `*` starts the timer  
- LCD shows real-time counting  
- When time is reached:
  - Timer stops  
  - LED turns on as indicator
 
  - ## Diagrama del sistema

![Diagrama](img/diagramaconex_prac3_pt2.jpeg)
![Diagrama](img/diagramflujo_prac3_pt2.jpeg)
