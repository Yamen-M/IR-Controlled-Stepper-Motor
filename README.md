# IR-Controlled-Stepper-Motor

Stepper Motor Control with IR Remote

Control a NEMA 17 Stepper Motor using an IR remote control!

This project demonstrates how to control a NEMA 17 Stepper Motor (or other) using an IR remote control. The project uses Arduino Uno to read IR signals from an IR remote control using IRremote library and translate them into motor control commands using the AccelStepper library.

# Features:

- Control a NEMA 17 Stepper Motor using an IR remote control
- Adjustable speed
- Direction control
- ReturnHome function, allows the motor to return to initial position at the beginning of the code execution
  
<b>Details:</b> When the UP or DOWN button on the IR remote is pressed, the motor keeps moving infinitely until the STOP button is pressed.

<b>Usage example:</b> Curtain control. By designing extra parts (3D printing) this project allows for fully wireless control of the curtain using the IR remote.

# Hardware Requirements:

- NEMA 17 Stepper Motor (or other)
- A4988 Driver
- IR receiver module
- IR remote
- Arduino Uno
- Jumper wires
- Power Supply for the Arduino (Minimum 5V)
- Power supply for the motor (Minimum 12VDC)
- 100uf capacitor
  
# Software Requirements:

- Arduino IDE

# How to Use:
<b>Full Simulation of the project using wokwi.com including wiring diagram: https://wokwi.com/projects/406950093561627649</b>


![IRreceiver Diagram](https://github.com/user-attachments/assets/cd1220ac-9341-439c-ba80-b3cd6a22c397)



<b>Step 1: Decode IR Remote Commands</b>

- Plug the Arduino Uno into your PC or laptop.
- Open the Arduino IDE and navigate to File > Open > IRDecode.ino (located in this repository).
- Upload the IRDecode.ino code to the Arduino Uno.
- Open the Serial Monitor by navigating to Tools > Serial Monitor or by pressing Ctrl + Shift + M (Windows) or Cmd + Shift + M (Mac).
- Point the IR remote at the IR receiver module and press a button. The Serial Monitor will display the decoded IR command.
- Take note of the IR commands for each button press (e.g. UP, DOWN, STOP).

<b>Step 2: Configure the Main Code</b>

- Open the Main.ino file (located in this repository) in the Arduino IDE.
- Edit the switch statements in the loop function to match the IR commands you decoded in Step 1.
- Save the changes to the Main.ino file.

<b>Step 3: Connect the Hardware</b>

![image](https://github.com/user-attachments/assets/30299db1-4f40-42d2-b5b5-ad22748f94a7)


<h1>WARNING!: IT IS IMPORTANT TO SET THE CURRENT LIMIT THAT ALIGNS WITH YOUR STEPPER MOTOR. FOLLOW THE LINK BELOW TO FIND DIFFERENT METHODS TO DO SO. </h1>

- <b>Link: https://lastminuteengineers.com/a4988-stepper-motor-driver-arduino-tutorial/</b>
- Connect the A4988 Driver to the Arduino Uno.
- Connect the NEMA 17 Stepper Motor to the A4988 Driver.
- <b>(WARNING: Do not unplug the motor while the A4988 driver is on as it could damage the driver. Unplug all power sources then unplug the motor if needed!)</b>
- Plug in the 12VDC power supply to the A4988.
- Connect the IR receiver module to the Arduino Uno.

<b>Step 4: Upload the Main Code</b>

- Upload the modified Main.ino code to the Arduino Uno.
- Open the Serial Monitor to verify that the code is working correctly.

<b>Step 5: Control the Stepper Motor</b>

- Use the IR remote control to control the Stepper Motor.
- Press the UP or DOWN button to move the motor infinitely.
- Press the STOP button to stop the motor.

# <b>License:</b>

This project is licensed under <b>MIT License</b>.

# <b>Contributing:</b>

Contributions are welcome! If you'd like to contribute to this project, please fork the repository and submit a pull request.
