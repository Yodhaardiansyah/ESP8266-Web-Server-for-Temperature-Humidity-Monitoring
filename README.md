### **📌 README - ESP8266 Temperature & Humidity Monitoring System**  

---

## **📖 Project Overview**  
This project uses an **ESP8266** microcontroller to monitor **temperature and humidity** from two **DHT22 sensors** and display the data on a simple **web server**. The web page refreshes automatically every 2 seconds to provide real-time updates.

---

## **🔧 Hardware Requirements**  
- **ESP8266 (NodeMCU, Wemos D1 Mini, etc.)**  
- **DHT22 Temperature & Humidity Sensors (x2)**  
- **Resistors (4.7kΩ pull-up for each DHT22 data pin)**  
- **Jumper Wires**  
- **Micro USB Cable**  

---

## **📜 Software Requirements**  
- **Arduino IDE**  
- **ESP8266 Board Package**  
- **DHT Sensor Library**  
- **ESP8266WiFi Library**  

---

## **🛠️ Circuit Diagram**  
| **ESP8266 (NodeMCU)** | **DHT22 Sensor 1** | **DHT22 Sensor 2** |
|----------------------|-----------------|-----------------|
| 3.3V               | VCC             | VCC             |
| GND               | GND             | GND             |
| D5 (GPIO14)       | DATA            | -               |
| D7 (GPIO13)       | -               | DATA            |
| **4.7kΩ Pull-up** | Between VCC & DATA | Between VCC & DATA |

---

## **💻 Installation & Setup**  
### **1️⃣ Install Required Libraries**  
Open **Arduino IDE**, go to **Sketch → Include Library → Manage Libraries**, and install:  
- `DHT sensor library by Adafruit`
- `ESP8266WiFi library (already included with ESP8266 board package)`

### **2️⃣ Configure ESP8266 Board**  
Go to **Tools → Board → ESP8266** and select your **ESP8266 model**.

### **3️⃣ Upload the Code**  
1. Open the Arduino **Serial Monitor** at **115200 baud rate**.  
2. Enter your **WiFi SSID and Password** in the code.  
3. Click **Upload** and wait for the ESP8266 to flash.  

---

## **🌐 How to Access the Web Server?**  
1. Open the **Serial Monitor** after flashing the ESP8266.  
2. Find the **IP Address** printed in the Serial Monitor (e.g., `192.168.1.100`).  
3. Open a web browser and enter `http://192.168.1.100/` to view the temperature & humidity data.

---

## **📷 Screenshot of Web Interface**  
The web page displays real-time **temperature and humidity** data from both sensors with a **refresh rate of 2 seconds**.

---

## **🚀 Features**  
✅ Real-time **temperature & humidity monitoring**  
✅ Auto-refresh web page every **2 seconds**  
✅ Lightweight **HTML interface**  
✅ **WiFi connectivity** for remote access  
✅ Supports **multiple sensors**  

---

## **⚠️ Troubleshooting**  
### **Problem 1: No WiFi Connection?**  
- Double-check your **WiFi SSID & password**.  
- Ensure your WiFi **router is online**.  

### **Problem 2: Web Page Not Loading?**  
- Confirm the **ESP8266 IP Address** from the **Serial Monitor**.  
- Restart ESP8266 and try again.  

### **Problem 3: Sensor Data Not Displaying?**  
- Check **wiring connections** (VCC, GND, DATA).  
- Add **4.7kΩ pull-up resistors** for DHT22.  

---

## **📜 License**  
This project is licensed under the **MIT License**.  

**Author:** Yodha Ardiansyah  
🌐 **Website:** [arunovasi.my.id](https://arunovasi.my.id)  

---
