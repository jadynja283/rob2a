#pragma config(Sensor, dgtl7,  limitSwitch,    sensorTouch)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                    - Dual Joystick Control -                                      *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses both the Left and the Right joysticks to run the robot using "tank control".    *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task stopAllMotors()
{
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	motor[armMotor] = 0;
	motor[clawMotor] = 0;
}


task main ()
{

  while (SensorValue[limitSwitch] == 0/* && vexRT[Btn7U] == 0*/){//stop takki virkur til ad stoppa allt, takki ovirkur 7U ovirkur.
		motor[leftMotor] = vexRT[Ch3] / 2;
		motor[rightMotor] = vexRT[Ch2] / 2;

		if(vexRT[Btn5D] == 1)
		{
			if(SensorValue[limitSwitch] == 0){
				motor[armMotor] = 60;
			}
		}
		else if(vexRT[Btn5U] == 1)
		{
				motor[armMotor] = -60;
		}
		else
		{
			motor[armMotor] = 0;
		}

		if(vexRT[Btn6U] == 1)
		{
			motor[clawMotor] = 60;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[clawMotor] = -60;
		}
		else
		{
			motor[clawMotor] = 0;
		}
	}
	StartTask(stopAllMotors);

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
