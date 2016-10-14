//Zaeem Mohamed, Felix Wu

float stopOnColorEncoder(int colorID, int power){
	SensorType[S1] = sensorColorNxtFULL;
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorC] = 0;
	time1[T1] = 0;
	motor[motorA] = power;
	motor[motorC] = power;
	while(SensorValue(S1) != colorID){}
	motor[motorA] = 0;
	motor[motorC] = 0;
	return 1000.0 * (((nMotorEncoder[motorA]
		   + nMotorEncoder[motorC]) / 2.0)
		   * PI/180.0 * 1.5) / time1[T1];
}

float stopOnColorSonar(int colorID, int power){
	SensorType[S1] = sensorColorNxtFULL;
	SensorType[S2] = sensorSONAR;
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorC] = 0;
	int initDist = SensorValue(S2);
	time1[T1] = 0;
	motor[motorA] = power;
	motor[motorC] = power;
	while(SensorValue(S1) != colorID){}
	motor[motorA] = 0;
	motor[motorC] = 0;

	return 1000.0 * (initDist - SensorValue(S2)) / time1[T1];
}

task main(){
	float errorSum = 0;
	for(int i = 0; i < 3; i++){
		while(nNxtButtonPressed != 3){}
		while(nNxtButtonPressed == 3){}
		eraseDisplay();
		displayString(0, "Fri 00");
		float encSpeed = stopOnColorEncoder(i + 2, 20 * i + 40);
		displayString(1, "Encoder: %f", encSpeed);
		while(nNxtButtonPressed != 3){}
		while(nNxtButtonPressed == 3){}
		float usSpeed = stopOnColorSonar(i + 2, 20 * i + 40);
		displayString(2, "UltraSonic: %f", usSpeed);
		float percError = 100.0 * (usSpeed - encSpeed)/encSpeed;
		errorSum += percError;
		displayString(3, "%%Error: %f%%", percError);
	}
	displayString(4, "Avg %%Error: %f%%", errorSum / 3.0);

	while(nNxtButtonPressed != 3){}
	while(nNxtButtonPressed == 3){}
}
