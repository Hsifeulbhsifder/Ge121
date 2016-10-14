//Zaeem Mohamed, Charvi Shah

bool driveDistAndTurn (int motorPower, int distance){
    SensorType[S3] = sensorSONAR;
    SensorType[S2] = sensorTouch;
    
    motor[motorA] = motorPower;
    motor[motorC] = motorPower;

    float dist = SensorValue[S3];

    displayString (0, "%d", dist + 15);
    while (SensorValue[S3] > distance + 15){
        displayString (1, "%d", distance + 15);
        if (SensorValue[S2]){
            return false;
        }
    }
    displayString (2, "TURNING");
    motor[motorA] = -75;
    motor[motorC] = 75;

    wait1Msec (1500);

    motor[motorA] = 0;
    motor[motorC] = 0;

    return true;
}

task main(){
    displayString(0, "Wed 01");
    while(nNxtButtonPressed != 3){}
    while(driveDistAndTurn(50, 15)){}
}
