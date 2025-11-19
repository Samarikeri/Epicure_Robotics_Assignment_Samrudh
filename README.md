# Epicure_Robotics_Assignment_Samrudh
This repository contains my solution for the Epicure Robotics Software Engineering task. The project focuses on reading sensor data, moving the simulated robot, and implementing the required control functions. The code is written in Python .

Epicure Robotics – Software Engineering Assignment

This project implements a complete robotic command pipeline using Python → MQTT → ESP32 → STM32 to control a stepper motor and LED through structured commands.

📁 Folder Structure
Epicure_Robotics_Assignment_Samrudh/
├── python_client/
│   └── mqtt_client.py
├── esp32_firmware/
│   └── esp32_main.ino
├── stm32_firmware/
│   └── main.c
└── README.md

🔧 Overview

The system works like this:

Python client publishes commands to an MQTT topic.

ESP32 subscribes to the same topic and receives the commands.

ESP32 forwards the commands via UART to the STM32.

STM32 parses the command and controls:

Stepper Motor

LED ON/OFF

Example commands:

motor:100:1 → move motor 100 steps in direction 1

led:on

led:off

🐍 Python Client (mqtt_client.py)
Requirements

Install the MQTT library:

pip install paho-mqtt

Usage

Run:

python mqtt_client.py


Enter commands like:

motor:200:0
led:on

📡 ESP32 Firmware (esp32_main.ino)

Connects to WiFi

Subscribes to MQTT topic

Receives commands

Writes received command to UART for STM32

Upload using Arduino IDE.

🔧 STM32 Firmware (main.c)

Reads UART input from ESP32

Parses command format

Drives stepper motor through GPIO pins

Controls LED

Only main.c is included — CubeMX project is not required for review

📝 Notes for Reviewer

All firmware is cleanly separated for clarity.

The Python script includes command handling and MQTT integration.

ESP32 sketch and STM32 firmware follow the required command packet format exactly.

✔️ How to Test (High-Level)

Run mqtt_client.py

ESP32 must be connected to same MQTT broker

ESP32 will send commands to STM32 via UART

STM32 will operate motor/LED

✉️ Contact

For any clarifications: Samrudh A
