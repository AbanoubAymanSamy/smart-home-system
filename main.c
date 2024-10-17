/* * 
THE 
Graduation_Project_AMIT
SMART HIME SYSTEM
 * */

#include "../LIB/STD_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/TIMER_1/TIM1_interface.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_config.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_interface.h"
#include "../HAL/BUZZER/BUZZER_interface.h"
#include "../HAL/servoMotor/ServoMotor_ingerface.h"
#include "../HAL/ServoMotor/ServoMotor_config.h"
#include "../HAL/TEMP_SENSOR/TEMP_interface.h"
#include "../MCAL/UART/UART_interface.h"

#define F_CPU 16000000
#include <util/delay.h>

#define MAX_PASSWORD_LENGTH 4 // The length (size of) password

int main(void) {
	/* LCD INIT */
	DIO_voidSetPortDir(LCD_DPORT, 0xFF); //Implement the direction of LCD
	DIO_voidSetPortDir(LCD_CPORT, 0xFF); //Implement the direction of LCD
	LCD_voidInit();
	
	LCD_voidSendCommand(1); //Clear LCD
	LCD_voidGotoxy(0,0); // place of Enter Password
	LCD_voidSendString("Enter Password:");
	
	/* Keypad INIT */
	KEYPAD_voidInit();
	
	/* ADC INIT */
	ADC_voidInit();
	
	/* UART INIT */
	UART_voidInit();
	
	/* APPLICATION VARIABLES */
	u32 enteredPass = 0;
	u32 correctPass = 1234;
	u8 count = 3;
	u8 login_success = 0;
	u8 key=0xff;
	/* Buzzer */
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN2, OUTPUT);
	
	/* LEDS */
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN5, OUTPUT);
	
	/* AC, Dimmer, Temp Sensor, Servo Motor */
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN3, OUTPUT); // AC Control
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN4, OUTPUT); // Light Control
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN2, INPUT);  // Temp Sensor
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN3, INPUT);  // Dimmer
	
	while (1) {
		/* UART Interfacing */
		if (UART_u8Available()) //check if the data is available or not 
		 { 
			u8 receivedChar = UART_u8Rx(); //received the character and use it to choice the case of switch statement  
			
			switch (receivedChar) {
				case 'L': // LEDS
				{
					static u8 lightState = 0;
					lightState = !lightState;
					if (lightState) {
						DIO_voidSetPinVal(DIO_PORTD, DIO_PIN5, HIGH); // turn on the LEDS
						LCD_voidSendCommand(1); 
						LCD_voidGotoxy(0,0);
						LCD_voidSendString("Light ON     ");
						UART_voidTransmitString("Light ON\r\n");
						} else {
						DIO_voidSetPinVal(DIO_PORTD, DIO_PIN5, LOW); // turn off the LEDS 
						LCD_voidSendCommand(1);
						LCD_voidGotoxy(0,0);
						LCD_voidSendString("Light OFF    ");
						UART_voidTransmitString("Light OFF\r\n");
					}
					_delay_ms(500); // delay to install  
				}
				break;
				case 'A': // AC
				{
					static u8 acState = 0;
					acState = !acState;
					if (acState) {
						
						DCMOTOR_voidCW(100); // turn on the AC 
						_delay_ms(1000);
						LCD_voidSendCommand(1); 
						LCD_voidGotoxy(0,0);
						LCD_voidSendString("AC ON        ");
						UART_voidTransmitString("AC ON\r\n");
						} else {
						DCMOTOR_voidCW(0); // turn off the AC 
						LCD_voidSendCommand(1);  
						LCD_voidGotoxy(0,0);
						LCD_voidSendString("AC OFF       ");
						UART_voidTransmitString("AC OFF\r\n");
					}
					_delay_ms(500); // delay to install  
				}
				break;
				case 'P': // enter password
				{
					enteredPass = 0;
					LCD_voidSendCommand(1);
					LCD_voidGotoxy(0, 0);
					LCD_voidSendString("Enter Password:");
					UART_voidTransmitString("Enter Password:\r\n");
					u8 password[MAX_PASSWORD_LENGTH];
					for (u8 i = 0; i < MAX_PASSWORD_LENGTH; i++) {
						while (!UART_u8Available()); 
						password[i] = UART_u8Rx();
						UART_voidTx('*'); //display star
						enteredPass = enteredPass * 10 + (password[i] - '0');
						for(u8 j = 0; j < 4; j++){
						LCD_voidGotoxy(j, 1);
						LCD_voidSendData('*');  // Display '*' for each digit
						}
					}
					UART_voidTransmitString("\r\n");
					
					// check the password
					if (enteredPass == correctPass) {
						login_success = 1;
						LCD_voidSendCommand(1);
						LCD_voidGotoxy(0,0);
						LCD_voidSendString("Password OK   ");
						UART_voidTransmitString("Password OK\r\n");
						_delay_ms(150);
						LCD_voidSendCommand(1);
						LCD_voidGotoxy(0,0);
						LCD_voidSendString("WELCOME HOME   ");
						UART_voidTransmitString("WELCOME HOME\r\n");
						_delay_ms(300);
						LCD_voidSendCommand(1);
						SERVO_voidSendDegree(90);
						_delay_ms(150);
						SERVO_voidSendDegree(0);
						} else {
						count--;
						if (count > 0) {
							LCD_voidSendCommand(1);
							LCD_voidGotoxy(0,0);
							LCD_voidSendString("Wrong Pass, Try");
							UART_voidTransmitString("Wrong Password, Try Again\r\n");
							BUZZER_voidOnVal();
							_delay_ms(100);
							BUZZER_voidOffVal();
							_delay_ms(100);
							} else {
							LCD_voidSendCommand(1);
							LCD_voidGotoxy(0,0);
							LCD_voidSendString("SYSTEM CLOSED  ");
							UART_voidTransmitString("SYSTEM CLOSED\r\n");
							BUZZER_voidOnVal();
							_delay_ms(500);
							BUZZER_voidOffVal();
							_delay_ms(500);
							
						}
					}
				}
				break;
				default:
				{
					LCD_voidSendCommand(1); 
					LCD_voidGotoxy(0,0);
					LCD_voidSendString("Invalid Cmd    ");
					UART_voidTransmitString("Invalid Command\r\n");
					_delay_ms(500);
				}
				break;
			}
		}

		if (login_success == 1) {
			/* read the value of temperature degree */
			LCD_voidGotoxy(0, 0);
			LCD_voidSendString("Temp:");
			u16 temp_degree = (u16)LM35_f32GetTemperature(ADC_3);
			LCD_voidGotoxy(5, 0);
			LCD_voidSendNumber(temp_degree);
			LCD_voidSendString("C ");
			UART_voidTransmitString("Temperature: ");
			// covert the number to serial then send it
			char tempStr[5];
			itoa(temp_degree, tempStr, 10);
			UART_voidTransmitString(tempStr);
			UART_voidTransmitString("C\r\n");

			/* read the value of brightness */
			LCD_voidGotoxy(0, 1); // the place on LCD
			LCD_voidSendString("Brightness:");
			u16 level_brt = (u16)LM35_f32GetTemperature(ADC_2); // to save the value of level of brightness
			LCD_voidGotoxy(12, 1);
			LCD_voidSendNumber(level_brt); // to display the number of brightness
			LCD_voidSendString(" ");
			UART_voidTransmitString("Brightness Level: ");
			// covert the number to serial then send it
			u8 brtStr[5];
			itoa(level_brt, brtStr, 10);
			UART_voidTransmitString(brtStr);
			UART_voidTransmitString("\r\n");

			// (Dimmer) to control the level of Brightness
			if (level_brt <= 100) {
				TIMER1_voidFastPWM10BitRes(OC1A_PIN, level_brt);
			}

			// if the degree of the room get greater than or equal 28 the AC turned on
			if (temp_degree >= 28) {
				DCMOTOR_voidCW(100); 
				UART_voidTransmitString("AC turned ON due to high temperature\r\n");// to send the action to user's device
				_delay_ms(40);
				UART_voidTransmitString("============================================\r\n");
			}
			// if the degree of the room get less than or equal 21 the AC turned on
			if (temp_degree <= 21) {
				DCMOTOR_voidCW(0); 
				UART_voidTransmitString("AC turned OFF due to low temperature\r\n"); // to send the action to user's device
				_delay_ms(40);
				UART_voidTransmitString("============================================\r\n");
			}
		}
	}
}
