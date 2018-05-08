
task project2(){
	int dist = 0;
wait1Msec(1000);

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
	for(int i = 1;i<10;i++){

	if(i%2){
  dist += 700;
	drive(dist);

	}
	else{
	driveB(dist);

	}
	stopmotor();

	}
}
