//Zaeem Mohamed, Charvi Shah

bool driveDistAndTurn (int motorPower, int distance){
    SensorType[S3] = sensorSONAR;
    SensorType[S2] = sensorTouch;
    
    motor[motorA] = motorPower;
    motor[motorC] = motorPower;

    while (SensorValue[S3] > distance + 15){
        displayString (1, "%d", SensorValue[S3]);
        if (SensorValue[S2]){
            return false;
        }
    }
    displayString (2, "TURNING");
    motor[motorA] = -75;
    motor[motorC] = 75;

    time1[T1] = 0;
    while(time1[T1] < 1250){
        if (SensorValue[S2]){
            return false;
        }
    }

    motor[motorA] = 0;
    motor[motorC] = 0;

    return true;
}

task main(){
    displayString(0, "Fri 09");
    while(nNxtButtonPressed != 3){}
    while(nNxtButtonPressed != -1){}
    while(driveDistAndTurn(50, 15)){}
}
