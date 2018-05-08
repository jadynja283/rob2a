void drive(int dist){
		SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
	while(dist > abs(SensorValue[leftEncoder])){

		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{

			motor[rightMotor] = 80;
			motor[leftMotor]  = 80;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{

			motor[rightMotor] = 60;
			motor[leftMotor]  = 80;
		}
		else
		{

			motor[rightMotor] = 80;
			motor[leftMotor]  = 60;
		}
	}
}
void driveB(int dist){
		SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
	while(dist > abs(SensorValue[leftEncoder])){
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{

			motor[rightMotor] = -80;
			motor[leftMotor]  = -80;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{

			motor[rightMotor] = -60;
			motor[leftMotor]  = -80;
		}
		else
		{

			motor[rightMotor] = -80;
			motor[leftMotor]  = -60;
		}
	}
}
void stopmotor(){
			motor[rightMotor] = 0;
			motor[leftMotor]  = 0;
			wait1Msec(1500);
	}
