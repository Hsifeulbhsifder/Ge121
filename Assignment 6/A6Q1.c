//Zaeem Mohamed, Gordon Winch

void buttonHeldTime(int& buttonNum, float& timeHeld){
	while(nNxtButtonPressed == -1 && !SensorValue(S2)){}
	if(SensorValue(S2)) buttonNum = 4;
	else buttonNum = nNxtButtonPressed;
	time1[T1] = 0;
	while(nNxtButtonPressed == buttonNum|| SensorValue(S2)){}
	timeHeld = time1[T1] / 1000.0;
}

void drive(int left, int right){
	motor[motorA] = left;
	motor[motorC] = right;
}

void control(int buttonNum, float timeHeld){
	if(buttonNum == 1){
		drive(75, -75);
	}else if(buttonNum == 2){
		drive(-75, 75);
	}else if(buttonNum == 3){
		drive(75, 75);
	}else if(buttonNum == 4){
		drive(-75, -75);
	}
	time1[T1] = 0;
	while(time1[T1] < timeHeld * 1000){
		if(SensorValue(S3) < 45 && buttonNum == 3){
			drive(30, 30);
		}
	}
	drive(0, 0);
}

task main(){
	SensorType[S2] = sensorTouch;
	SensorType[S3] = sensorSONAR;
	for(int i = 1; i <= 5; i++){
		displayString(0, "Wed 10");
		int buttonNum = 0;
		float timeHeld = 0;
		buttonHeldTime(buttonNum, timeHeld);
		displayString(i, "%d: %fs", buttonNum, timeHeld);
		control(buttonNum, timeHeld);
	}
	while(nNxtButtonPressed == -1 && !SensorValue(S2)){}
}