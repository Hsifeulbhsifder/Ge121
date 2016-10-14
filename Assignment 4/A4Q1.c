task main()
{
	displayString(0, "Thurs 01");
	SensorType[S3] = sensorSONAR;
	int delay = 750;

	while(SensorValue[S3]>10)
	{
		if(nNxtButtonPressed == 1)
		{
			motor[motorA] = 75;
			motor[motorC] = -75;

			wait1Msec(delay);


			motor[motorA]=0;
			motor[motorC]=0;
		}

		else if (nNxtButtonPressed == 2)
		{
			motor[motorA]=-75;
			motor[motorC]=75;

			wait1Msec(delay);


			motor[motorA]=0;
			motor[motorC]=0;

		}
		else if (nNxtButtonPressed == 3)
		{
			displayString(1,"Allons-y!");

			motor[motorA] = 100;
			motor[motorC] = 100;

			wait1Msec(2000);

			motor[motorA]=0;
			motor[motorC]=0;

			eraseDisplay();

			displayString(0, "Thurs 01");


		}

	}
}
