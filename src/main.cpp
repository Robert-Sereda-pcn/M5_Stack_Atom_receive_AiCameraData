//set the mode and receive data (updated function)
#include <Arduino.h>
#include <ArduinoJson.h>

// Define the UART pins
#define RX_PIN 32
#define TX_PIN 26

// Create a hardware serial object
HardwareSerial uart(1); // Use UART1 (there are multiple UARTs available on ESP32)


// Function to send JSON data
void sendJsonData() {
  // Create a JSON document
  DynamicJsonDocument doc(200);
  // Add data to the document
  doc["function"] = "Object Recognition";
  doc["args"][0] = "Package_scale_model";

  // Serialize the JSON document to a string
  String jsonString;
  serializeJson(doc, jsonString);

  // Send the JSON string over UART
  uart.println(jsonString);
}


void setup() {
    // Initialize the built-in serial monitor
  Serial.begin(115200);

  // Initialize the UART communication with the specified pins and baud rate
  uart.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);

  // Print a message to indicate that the setup is complete
  Serial.println("UART communication started");

  // Send JSON data
  sendJsonData();
}


// Loop function to continuously read data from UART and send it to the serial monitor
void loop() {
  // Check if there is data available to read from UART
  if (uart.available()) {
    // Read the incoming data
    while (uart.available()) {
      // Read one byte from UART
      char incomingByte = uart.read();
      // Write the byte to the serial monitor
      Serial.print(incomingByte);
    }
  }
}


/*
//set the mode and receive data (old function)
#include <Arduino.h>
#include <ArduinoJson.h>

// Define the UART pins
#define RX_PIN 32
#define TX_PIN 26

// Create a hardware serial object
HardwareSerial uart(1); // Use UART1 (there are multiple UARTs available on ESP32)


// Function to send JSON data
void sendJsonData() {
  // Create a JSON document
  StaticJsonDocument<200> doc;
  // Add data to the document
  doc["function"] = "Object Recognition";
  doc["args"][0] = "Package_scale_model";

  // Serialize the JSON document to a string
  String jsonString;
  serializeJson(doc, jsonString);

  // Send the JSON string over UART
  uart.println(jsonString);
}


void setup() {
    // Initialize the built-in serial monitor
  Serial.begin(115200);

  // Initialize the UART communication with the specified pins and baud rate
  uart.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);

  // Print a message to indicate that the setup is complete
  Serial.println("UART communication started");

  // Send JSON data
  sendJsonData();
}


// Loop function to continuously read data from UART and send it to the serial monitor
void loop() {
  // Check if there is data available to read from UART
  if (uart.available()) {
    // Read the incoming data
    while (uart.available()) {
      // Read one byte from UART
      char incomingByte = uart.read();
      // Write the byte to the serial monitor
      Serial.print(incomingByte);
    }
  }
}
*/


/*
//only receive data through TX and TX (first you need to select camera mode)
#include <Arduino.h>

// Define the UART pins
#define RX_PIN 32
#define TX_PIN 26

// Create a hardware serial object
HardwareSerial uart(1); // Use UART1 (there are multiple UARTs available on ESP32)


void setup() {
    // Initialize the built-in serial monitor
  Serial.begin(115200);

  // Initialize the UART communication with the specified pins and baud rate
  uart.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);

  // Print a message to indicate that the setup is complete
  Serial.println("UART communication started");
}


// Loop function to continuously read data from UART and send it to the serial monitor
void loop() {
  // Check if there is data available to read from UART
  if (uart.available()) {
    // Read the incoming data
    while (uart.available()) {
      // Read one byte from UART
      char incomingByte = uart.read();
      // Write the byte to the serial monitor
      Serial.print(incomingByte);
    }
  }
}
*/
