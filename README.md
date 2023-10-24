# IQ-group-pir-wireless-arduino-TX
Spoof a triggering RF signal to switch the mains switch in an IQ Group mains controller (as pictured below)

<img src="images/P1140936.jpg" alt="IQ Group 240V Mains controller"/>

using an ardunio Uno and cheap 433mHz TX module (as pictured below) 

<img src="images/ard.jpg" alt="Ard_tx"/>



# To make this work, do the following 
 - PREPARATION
   - Be safe - Power all things down first!!
   - On the Arduino
     - Wire up the 433 mHZ module - Use dupont male to female wires to link:
       - Arduino 5V  to TX Module +V  
       - Arduino 0V  to TX Module ground  
       - Arduino pin 3 (TX signal) to the TX Module input pin  
   - On the IQ receiver:
     - Wire up mains input power
     - Gently turn the duration pot all the way counter clockwise - It is to be set to "Test"  N.B. This setup means that once the receiver is setup successfully and the Arduino sketch is running, you will hear the IQ receiver relay clicking on every 15 seconds and staying on for about 5 seconds. 10 seconds later, it will click on again and this will repeat while the sketch is running (but only after the code has been learnt - see below on how to do that).  

 - CODE RESET - Do this if you want start from scratch
   - On the IQ Receiver 
     - Power it up
       - If codes have already been stored, the LED will light up solid.
       - If there are no codes (e.g. its the very first time it has ever been powered up), the LED will slowly blink on and off, which indicates that the IQ receiver is already in "Programming mode".
     - Wait for about 10 seconds - for the receiver internals to settle down
     - Press the Receiver's PROGRAM button for 5 seconds to make sure that the IQ receiver is reset empty - The receiver will either do one of the following two things:
       - Pulse very quickly for a bit (indicating it has emptied code) and then slowly blink on and off 
       - it doesn't do anything (indicating no code was previously stored) and just continues blinking slowly on and off. 
                
 - CODE LEARNING
   - On the IQ Receiver 
     - Power it up. If it is for the first time, the LED will slowly blink on and off.
     - If the LED is on solid, press the Receiver's PROGRAM button for 1-2 seconds until the led starts slowly blinking on and off (Do not press for longer otherwise you will trigger a reset of all codes - See previous section)
   - On the Arduino
     - Power it up - it will start transmitting every 15 seconds.
     - Wait until you hear the relay clicking on and off (after about 30 seconds)
   - On the IQ Receiver
     - Check that "programming mode" has completed - This is signified by a repeating LED pattern where the LED becomes solid for about 10 seconds, and then blinks for 5 seconds.  N.B. Note that if the LED ever becomes solid, it is indicating that the code has been stored, and that the IQ Receiver is now in "normal operation" mode where if you now see the LED blinking, it means that the relay is triggered ON with a solid LED meaning that the relay is OFF.
       
N.B. If all is setup and working OK, the relay will click on every 15 seconds, and stay on for about 5 seconds. This will repeat until you stop the Arduino from sending TX signals!

N.B. You will notice that when in "normal operation" and the relay is triggered ON, the LED is flashing slowly. When the relay is off (the untriggered state), The LED is solid on.

N.B. You will notice that you can change the "ON" time on the receiver by turning the receiver pot 

N.B. If you ever power cycle the IQ receiver off and on, wait for about 10 seconds before trying to do things. It seems the Receiver needs some time to settle down and stabilise before it can work OK 

N.B. It is possible for the IQ receiver to recognise separate codes. However, bear in mind that if all devices use the same sketch TX "code" (as seen in the transmit sketch INO file), you do not need to do it!

# Analysis of Pulse train
<img src="images/PIR Pulse train.jpg" alt="Pulse Train 1"/>
