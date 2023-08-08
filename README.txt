# Fire-System
Fire System to control fire
This Project is a fire system that is sensitive to heat and smoke. if temp exceeds a limit,
the system gives a warning, and if the temp exceeds higher limit, it turns the motor on, and the led,
and a buzzer alarm

Application: This folder contains the application and device drivers.

Design: This folder contains proteus design and hex file

AVR_Application.hex: This is the hex file to be burnt on the MCU

Video Demo: The video demo of the project




read temp sensor reading..
1:
if temp < 100:
	print fine
	green led oppened
	the motor is not turned on

if temp > 100 && smoke < 90:
	print Heat
	Yellow led oppened
	Turn the smoke sensor on
	the motor is not turned on
	
	check if the temp goes under 100 again
		if yes
			go to 1;



if temp > 100 && smoke>90:
	print Fire
	turn buzzer on
	red led oppened
	Turn the smoke sensor on
	the motor is  turned on
	
	check the button to stop the fire system\
	if the user hits the button and enters the password right:
		stop the fire system;
