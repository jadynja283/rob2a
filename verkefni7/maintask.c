#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)

#include "mydrivefunction.c"
#include "mytasks.c"
task main()
{
StartTask(project1);
StartTask(project2);
StartTask(project3);
StartTask(project4);
while(true){
		int number = rand()%4;
		if(number ==1){
			StartTask(project1);
			StopTask(project2);
			StopTask(project3);
			StopTask(project4);
		}
		if(number ==2){
			StartTask(project2);
			StartTask(project3);
			StopTask(project4);
		}
		if(number ==3){
			StartTask(project3);
			StopTask(project4);
			StopTask(project2);
			StopTask(project1);

		}
		else{
			StopTask(project4);
			StopTask(project3);
			StopTask(project2);
			StopTask(project1);
			wait1Msec(1000);
		}
	}
}



}

}
