#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
int dist = 100;

void drive(int dist,bool bf){
	int backwardForward = (bf) ? (1):(-1);
	while(dist > abs(SensorValue[leftEncoder])){
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{

			motor[rightMotor] = 80*backwardForward;
			motor[leftMotor]  = 80*backwardForward;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{

			motor[rightMotor] = 60*backwardForward;
			motor[leftMotor]  = 80*backwardForward;
		}
		else
		{

			motor[rightMotor] = 80*backwardForward;
			motor[leftMotor]  = 60*backwardForward;
		}
	}
}


task main()
{
	wait1Msec(2000);

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
	for(int i =1;i<5;i++){
		drive(dist *i,true);
		drive(dist *i,false);
	}
}
