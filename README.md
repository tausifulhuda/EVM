This is an Embedded Systems project- an Electronic Voting Machine (EVM). I have simulated the circuit in TinkerCad. The link is attached with this repository.

Traditional ballot-based voting system is resource heavy, slow, prone to human error and can be accused of tampering. Electronic voting machine (EVM) is a great solution to all these problems. It removes the need for excessive human resources as this system does not need many people to administer. Also, this machine can publish the result instantly after the voting period ends so it does not need any people count the votes. Human error is nullified as there is no canceled vote or counting error. The result cannot be tampered in EVM as count-tampering is not possible. Moreover, this machine can be integrated with voter database, so each voter much verify their identity before voting and can vote only once.

The main componenets are-

**1. ATmega328P (Arduino Uno):** The MCU used to execute the algorithms, logic and keep records in the system.  
**2. 16×2 Characters LCD with I2C Backpack Interface:** The display to show the UI including vote count and confirmation panel.  
**3. Pushbuttons:** Four pushbuttons are used to take inputs from voters. Two of them are used to denote two different candidates, and other two are used to confirm or cancel a decision.  
**4. Breadboard and Jumper Wires:** Used for connection between MCU and other components.
