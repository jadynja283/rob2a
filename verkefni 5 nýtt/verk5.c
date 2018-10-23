#pragma config(Sensor, in1,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Motor,  port3,           leftMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           rightMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int speed = 63;


task drive()
{

	int threshold =2200;

	while(true)
	{
		if(SensorValue(lineFollowerRIGHT) > threshold)
		{
			motor[leftMotor]  = speed;
			motor[rightMotor] = 0;
		}
		if(SensorValue(lineFollowerCENTER) > threshold)
		{
			motor[leftMotor]  = speed;
			motor[rightMotor] = speed;
		}
		if(SensorValue(lineFollowerLEFT) > threshold)
		{
			motor[leftMotor]  = 0;
			motor[rightMotor] = speed;
		}

		Sleep(20);
	}
 
}
task main()
{

	StartTask(drive);
 	while(vexRT[Btn8U] == 1){}
}
