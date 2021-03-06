#pragma config(Sensor, in4,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  pushBtn,        sensorTouch)
#pragma config(Sensor, dgtl8,  rangeFinder,    sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void stopAllMotors(){
  motor[rightMotor] = 0;
  motor[leftMotor] = 0;
}
void turn(){
	motor[rightMotor] = 80;
	motor[leftMotor]  = -80;
}


task main(){
//SensorValue[pushBtn] == 0
//SensorValue[rangeFinder] > 55
//SensorValue[lightSensor] < 500
    while(SensorValue[pushBtn] == 0 && SensorValue[rangeFinder] > 55 && SensorValue[lightSensor] < 500){

	  	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]){
				motor[rightMotor] = 80;
				motor[leftMotor]  = 80;
			}
			else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder])){
				motor[rightMotor] = 60;
				motor[leftMotor]  = 80;
			}
			else{
				motor[rightMotor] = 80;
				motor[leftMotor]  = 60;
			}
		
		}
	  turn();

	stopAllMotors();
}
