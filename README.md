# 🧠 Smart Power Supply for Data Loggers

**Low-Cost / High-Precision UPS for Reliable Data Acquisition Systems**  
[Published in *Energies*, MDPI - DOI: [10.3390/en16010278](https://doi.org/10.3390/en16010278)]

## 📌 About the Project

This project presents the design and implementation of a **smart, low-cost, and high-precision power supply** system tailored for **data loggers** in experimental setups. It provides **uninterruptible power**, advanced **monitoring features**, and a **DIY-friendly open hardware** approach with robust performance under demanding conditions.

Developed by researchers from the **University of São Paulo (USP)** and the **University of Minho**, this power supply ensures uninterrupted operation even during AC power failures, thanks to an embedded UPS and smart control logic.

## ⚙️ Features

- 🔋 **AC/DC Dual Input** with seamless switching (UPS functionality)
- 📶 **Serial communication (UART)** with external devices
- 📺 **OLED Display** for real-time system status
- 🌡️ **Temperature monitoring** and **smart active cooling**
- 🔄 **Remote firmware update capability**
- 📏 Outputs: ±12V, 5V, 3.3V – bipolar and unipolar DC
- 🛡️ Protection: 3 internal fuses for AC input, DC section, and battery
- 🧠 Controlled by an **ATmega328PB** microcontroller
- 🧩 Fully documented open hardware – easily 3D printable case
- 💸 **Total cost under $150**

## 🧪 Experimental Results

Tests confirmed:

- **Switching time < 10 ms** between power sources  
- No voltage drop affecting operation under 0A, 1A, and 2A loads  
- Stable operation under AC loss scenarios  
- Precise voltage regulation and thermal control

## 📜 License

This project is licensed under the **Creative Commons BY 4.0**  
© 2022 by the authors. Reuse permitted with attribution.  
[License Details](https://creativecommons.org/licenses/by/4.0/)

## 👨‍🔬 Authors

- Márcio L. M. Amorim  
- Gabriel A. Ginja  
- João P. Carmo  
- Melkzedekue M. A. Moreira  
- Adriano A. G. Siqueira  
- José A. Afonso

## 📚 Citation

If you use this work, please cite:

> Amorim, M.L.M.; Ginja, G.A.; Carmo, J.P.; Moreira, M.M.A.; Siqueira, A.A.G.; Afonso, J.A.  
> *Low-Cost/High-Precision Smart Power Supply for Data Loggers.*  
> Energies 2023, 16, 278. DOI: [10.3390/en16010278](https://doi.org/10.3390/en16010278)

---

