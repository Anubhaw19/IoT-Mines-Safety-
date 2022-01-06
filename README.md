# IoT-Mines-Safety-
basic model to monitoring:
- Methane Gas using (**MQ4 sensor**).
- Humidity and Temperature measurement using (**DHT11 sensor**).
- Distance measurement using UltraSonic (**HC-SRO4**) sensor.
Using **NodeMCU(esp8266MOD)** as network gateway.


 ## Components
 <p align="left">
  <img  src=circuit.jpeg>
 
- Circuit with different sensors connected.<br>
  </p>
   <p align="left">
 ### Pin Connection:
 **Humidity and Temperature (DHT11) sensor:**
 - positive-Vin
 - data-D5(Node MCU)
 - negative-Ground

 **UltraSonic (HC-SRO4):**
 - echo-D6
 - trig-D7
 - Vcc-Vin(Node MCU)(**5V**)
 - Gnd-Ground(Node MCU)

  **Methane (MQ4) sensor:**
 - Data-A0(Node MCU)
 - Vcc-Vin(Node MCU)(**5V**)
 - Gnd-Ground(Node MCU)

  </p>
  
 ## Data Analysis
 <p align="left">
  <img  src=chart.jpeg>
 
- analyzing data from the chart and serial monitor. <br>
analysing data with the help of [ThingSpeak](https://thingspeak.com/) server.

  </p>



