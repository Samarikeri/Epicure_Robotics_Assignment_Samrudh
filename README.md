# Epicure_Robotics_Assignment_Samrudh
This repository contains my solution for the Epicure Robotics Software Engineering task. The project focuses on reading sensor data, moving the simulated robot, and implementing the required control functions. The code is written in Python .
📌 Epicure Robotics – Software Engineering Task

Author: Samrudh
Submission Date: 19-Nov

🚀 Project Summary

This project implements a command pipeline between:

A Python script (MQTT client)

An ESP32 (MQTT → UART bridge)

An STM32 microcontroller (final motor + LED control)

Commands are typed in the Python script → published to MQTT → received by ESP32 → forwarded via UART to STM32 → STM32 interprets commands and controls the hardware.

Supported Commands
motor:<steps>:<direction>
led:on
led:off


Examples:

motor:100:1 → Move motor 100 steps in direction 1

led:on → Turn LED ON

led:off → Turn LED OFF

📂 Folder Structure
epicure-robotic-task/
├── python_client/
│   └── mqtt_client.py
├── esp32_firmware/
│   └── esp32_main.ino
├── stm32_firmware/
│   └── main.c
└── README.md


You should create these folders manually on GitHub and upload the files inside each folder.

🧠 How the System Works (Simple Explanation)
🟦 1. Python Script → MQTT

Reads user input

Publishes the command to an MQTT topic

Uses paho-mqtt library

🟩 2. ESP32 → MQTT Subscriber

Connects to Wi-Fi

Subscribes to MQTT topic

Any received message is forwarded through UART to STM32

🟧 3. STM32 → Hardware Control

Reads UART commands

Parses strings

If command is motor → move stepper

If command is LED → turn LED ON/OFF
