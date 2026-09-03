# Performance Evaluation of a Teleoperated Robotic Arm

> **Experimental evaluation of a teleoperated robotic arm using different communication protocols based on latency and task-efficiency metrics.**

## 📌 Overview

This project presents a teleoperated robotic arm system designed to experimentally evaluate the performance of different communication protocols.

The same robotic system is controlled through multiple communication approaches, and their performance is compared using measurable parameters such as **communication latency, task completion time, task success rate, and positioning error**.

The project was developed as part of the **Mechatronics System Design** course and is also being further developed as a research project.

## 🎯 Objectives

- Develop a functional teleoperated robotic arm.
- Implement multiple communication protocols.
- Measure communication latency.
- Evaluate robotic task performance.
- Compare different protocols under controlled experimental conditions.
- Analyze the relationship between communication performance and robotic task efficiency.

## 🔌 Communication Protocols

The project evaluates the following protocols:

- **TCP** — Reliable, connection-oriented communication
- **UDP** — Lightweight, connectionless communication
- **MQTT** — Lightweight publish/subscribe messaging
- **ESP-NOW** — Direct wireless communication between ESP devices
- **Modbus TCP** — Industrial communication over TCP/IP

## 📊 Performance Metrics

### 1. Communication Latency

The time delay between transmitting a control command and receiving the corresponding response.

**Unit:** milliseconds (ms)

### 2. Task Completion Time

The time required by the robotic arm to complete a predefined task.

**Unit:** seconds (s)

### 3. Task Success Rate

The percentage of successfully completed tasks over the total number of trials.

**Formula:**

`Success Rate (%) = (Successful Trials / Total Trials) × 100`

### 4. Positioning Error

The difference between the desired robotic-arm position and the actual position.

### 5. Error / Correction Count

The number of errors or corrective actions required during task execution.

## ⚙️ System Architecture

```text
                ┌──────────────────┐
                │     Operator     │
                │ Control Interface│
                └────────┬─────────┘
                         │
                         ▼
                ┌──────────────────┐
                │   Transmitter    │
                │   Controller     │
                └────────┬─────────┘
                         │
                         ▼
             ┌────────────────────────┐
             │ Communication Protocol │
             │                        │
             │ TCP / UDP / MQTT       │
             │ ESP-NOW / Modbus TCP   │
             └────────────┬───────────┘
                          │
                          ▼
                ┌──────────────────┐
                │ Receiver / MCU   │
                └────────┬─────────┘
                         │
                         ▼
                ┌──────────────────┐
                │  Servo Motors    │
                └────────┬─────────┘
                         │
                         ▼
                ┌──────────────────┐
                │  Robotic Arm     │
                └────────┬─────────┘
                         │
                         ▼
                ┌──────────────────┐
                │  Task Execution  │
                └──────────────────┘
```

## 🛠️ Hardware Components

- ESP32-S2 development boards
- Robotic arm mechanism
- Servo motors
- Potentiometers / joystick controls
- Sound sensor module
- Power supply / battery
- Breadboard / prototype wiring
- Wi-Fi/network infrastructure
- USB cables

## 💻 Software & Tools

- C/C++
- Arduino Framework
- PlatformIO / Arduino IDE
- Git
- GitHub
- MQTT Broker
- Serial monitoring
- Data logging and analysis tools

## 🔬 Experimental Methodology

The same robotic arm and predefined task are used for each communication protocol to maintain a consistent experimental environment.

### Experimental workflow

```text
Select Communication Protocol
            ↓
Initialize System
            ↓
Send Control Command
            ↓
Record Communication Timestamp
            ↓
Receive Command
            ↓
Execute Robotic Movement
            ↓
Measure Task Performance
            ↓
Record Experimental Data
            ↓
Repeat Multiple Trials
            ↓
Calculate Average Results
            ↓
Compare Protocol Performance
```

Multiple trials are performed for each protocol, and the collected data are used for comparative analysis.

## 📈 Results

The experimental results are used to compare:

- Average communication latency
- Task completion time
- Task success rate
- Positioning error
- Number of corrections/errors

### Example result format

| Protocol   | Avg. Latency (ms) | Task Time (s) | Success Rate (%) | Position Error |
| ---------- | ----------------: | ------------: | ---------------: | -------------: |
| TCP        |                 — |             — |                — |              — |
| UDP        |                 — |             — |                — |              — |
| MQTT       |                 — |             — |                — |              — |
| ESP-NOW    |                 — |             — |                — |              — |
| Modbus TCP |                 — |             — |                — |              — |

> **Note:** Final values will be updated using the measured experimental data.

## 🎥 Project Demonstration

Watch the project demonstration:

**[▶️ Project Demonstration Video](YOUR_VIDEO_LINK_HERE)**

Replace `YOUR_VIDEO_LINK_HERE` with the YouTube, Google Drive, LinkedIn, or other public video link.

## 🔊 Sound Sensor Demonstration

An additional sound-triggered feature is included in the prototype.

A sound sensor detects a sufficiently loud sound, such as a group clap, and triggers the robotic system.

```text
Clap / Sound
     ↓
Sound Sensor
     ↓
Microcontroller
     ↓
Trigger Detection
     ↓
Robotic Arm Activation
```

This feature is included as an interactive demonstration component and is **not part of the primary communication-protocol performance evaluation**.

## 📁 Project Structure

```text
teleoperated-robotic-arm/
│
├── README.md
├── LICENSE
│
├── firmware/
│   ├── tcp/
│   ├── udp/
│   ├── mqtt/
│   ├── esp-now/
│   └── modbus-tcp/
│
├── hardware/
│   ├── schematic/
│   ├── pcb/
│   └── mechanical/
│
├── experiments/
│   ├── raw-data/
│   ├── processed-data/
│   └── results/
│
├── documentation/
│   ├── presentation/
│   └── research/
│
└── media/
    ├── images/
    └── videos/
```

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone YOUR_REPOSITORY_URL
cd teleoperated-robotic-arm
```

### 2. Open the firmware

Open the required protocol folder in **PlatformIO or Arduino IDE**.

### 3. Configure the hardware

Connect the controller, potentiometers/joystick, servo motors, and communication network according to the hardware documentation.

### 4. Configure communication

Set the required:

- Wi-Fi/network credentials
- IP addresses
- Ports
- MQTT broker address/topic
- Modbus TCP configuration

depending on the selected protocol.

### 5. Upload firmware

Upload the transmitter and receiver firmware to the respective ESP32 boards.

### 6. Run the experiment

Select a communication protocol and perform the predefined robotic task.

Record the required performance parameters and repeat the experiment for statistical comparison.

## 👥 Team & Development

This project was developed as a collaborative engineering project.

We followed an **industry-oriented development workflow** using:

- Git/GitHub
- Version control
- Task distribution
- Collaborative coding
- Code contribution
- Testing
- Debugging
- Experimental documentation

## 🔬 Research Direction

The project is being further developed toward research on communication performance in teleoperated robotic systems.

Future work may include:

- Larger experimental datasets
- Different network conditions
- Communication distance analysis
- Packet-loss analysis
- Jitter measurement
- More complex robotic tasks
- Operator performance evaluation
- Statistical analysis
- Additional industrial communication protocols

## 📜 License

This project is open source. See the [`LICENSE`](LICENSE) file for the applicable license terms.

## 🤝 Contributing

Contributions, suggestions, improvements, and experimental extensions are welcome.

If you would like to contribute:

1. Fork the repository.
2. Create a feature branch.
3. Make your changes.
4. Test your changes.
5. Commit your work.
6. Open a Pull Request.

## ⭐ Acknowledgment

This project was developed as part of the **Mechatronics System Design** course.

Special thanks to **Rumana Tasnim** for her guidance, encouragement toward robotics-based projects, and motivation to develop this work further as a research project.

---

Facebook link: facebook.com/reel/1035119629327594/?s=single_unit
Linkedin: https://www.linkedin.com/feed/update/urn:li:activity:7495561157160652800/

### 📚 Project Information

**Project Type:** Robotics / Embedded Systems / Communication / Experimental Research

**Domain:** Mechatronics, Robotics, Embedded Systems, IoT, Industrial Communication

**Primary Focus:** Communication latency and robotic task performance

**Protocols:** TCP, UDP, MQTT, ESP-NOW, Modbus TCP
