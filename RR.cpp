#include<iostream>
#include<queue>
using namespace std;

/*
Submitted by :Muhammad Ahsan Ali
REG #  200901072
BSCS-01-B
Submitted t0: Maam Reeda Saeed
*/




int Input_DIFF_AT(int* burstTime, int *rem_burstTime ,int * arivalTime,int totalProcess, int sumOfBt)
{

	for (int i = 0; i < (2 * totalProcess); i++)
	{
		if (i < totalProcess)
		{
			cout << "Enter AT-" << i + 1 << " : ";
			cin >> arivalTime[i];
		}
		else
		{
			int holdit;
			cout << "Enter BT-" << i % totalProcess + 1 << " : ";
			cin >> holdit;
			rem_burstTime[i % totalProcess] = holdit;
			burstTime[i % totalProcess] = holdit;;
			sumOfBt += burstTime[i % totalProcess];

		}
	}
	return sumOfBt;
}


void CAL_CT_DIFF_AT(int* burstTime, int* rem_burstTime, int* arivalTime, int totalProcess, int sumOfBt,int Time
,int timeQuatum ,queue<int> readyQueue, int * CT)
{

	int i = 0, x = 0;
	while (Time < sumOfBt)
	{
		if (rem_burstTime[x] > timeQuatum && arivalTime[x] <= i && i < totalProcess)
		{
			readyQueue.push(x);
			rem_burstTime[x] -= timeQuatum;
			Time += timeQuatum;
			//cout << "\nA\n";
			//cout << "\nTime" << Time<<endl;


		}
		else if (rem_burstTime[x] <= timeQuatum && arivalTime[x] <= i && rem_burstTime[x] != 0 && i < totalProcess)
		{
			//readyQueue.push(x);
			Time += rem_burstTime[x];
			rem_burstTime[x] -= rem_burstTime[x];
			CT[x] = Time;
			//cout << "\nB\n";

			//cout << "\nP" << x + 1 << " Time " << Time<<endl;

		}

		if (arivalTime[x] > i && rem_burstTime[x] != 0 && i < totalProcess)
		{

			//cout << "\nC\n";
			int seq = arivalTime[x] - x;//i not in bracket rightside
			int j = 0;
			while (j < seq)
			{
				int tempHold = readyQueue.front();
				readyQueue.pop();
				if (rem_burstTime[tempHold] > timeQuatum)//&& arivalTime[tempHold] < j)
				{
					readyQueue.push(tempHold);
					rem_burstTime[tempHold] -= timeQuatum;
					Time += timeQuatum;
					//cout << "\nE\n";
					//cout << "\nTime" << Time << endl;


				}
				else if (rem_burstTime[tempHold] <= timeQuatum && rem_burstTime[tempHold] != 0)
				{
					//readyQueue.push(tempHold);
					Time += rem_burstTime[tempHold];
					rem_burstTime[tempHold] -= rem_burstTime[tempHold];// i  leftside
					CT[tempHold] = Time;
					//cout << "\nF\n";
					//cout << "\nP" << x + 1 << " Time " << Time << endl;

				}
				j++;

			}
			//i -= 1;

			//test

			if (rem_burstTime[x] > timeQuatum)//&& arivalTime[tempHold] < j)
			{
				readyQueue.push(x);
				rem_burstTime[x] -= timeQuatum;
				Time += timeQuatum;
				//cout << "\nG\n";


			}
			else if (rem_burstTime[x] <= timeQuatum && rem_burstTime[x] != 0)
			{
				//readyQueue.push(tempHold);
				Time += rem_burstTime[x];
				rem_burstTime[x] -= rem_burstTime[x];
				CT[x] = Time;
				//cout << "\nBb\n";
				//cout << "\nP" << x << " Time " << Time << endl;

			}

		}

		if (i > totalProcess)
		{
			int tempHold = readyQueue.front();
			readyQueue.pop();
			//cout << "\nD\n";
			if (rem_burstTime[tempHold] > timeQuatum)//&& arivalTime[tempHold] < j)
			{
				readyQueue.push(tempHold);
				rem_burstTime[tempHold] -= timeQuatum;
				Time += timeQuatum;


			}
			else if (rem_burstTime[tempHold] <= timeQuatum && rem_burstTime[tempHold] != 0)
			{
				//readyQueue.push(tempHold);
				Time += rem_burstTime[tempHold];
				rem_burstTime[tempHold] -= rem_burstTime[tempHold];
				CT[tempHold] = Time;
				//cout << "\nP" << tempHold + 1 << " Time " << Time << endl;

			}

		}

		i++;
		x++;
		if (i == totalProcess)
		{
			x = 0;
		}

	}

}
void Print_DIFF_AT(int* BT, int* TAT, int* WT,int * AT, int totalProcess,int*CT)
{
	int i = 0;
	cout << "\n\nPno\t" << "AT\t"<<"BT\t"<<"CT\t" << "WT\t" << "TAT" << endl;
	while (i < totalProcess)
	{
		cout << i + 1 << "\t" <<AT[i] << "\t" << BT[i] << "\t"<<CT[i]<<"\t" << TAT[i] << "\t" << WT[i] << endl;
		i++;
	}

}
void TurnARoundTime_AND_WaitingTimeCal(int * ARR1, int *ARR2,int*ARR3, int totalProcess) 
{
	for (int i = 0; i < totalProcess; i++)
	{
		ARR1[i] = ARR2[i] - ARR3[i];

	}

}

double averageFinder(int* ARR1, int n)
{
	int i = 0;
	double AVG = 0.0;
	while (i < n)
	{
		AVG += ARR1[i];
		i++;
	}
	return AVG / n;
}


int Input(int* rem_burstTime, int* burstTime, int totalProcess)
{
	int sumOfBT = 0;

	for (int i = 0; i < totalProcess; i++)
	{
		cout << "\nEnter BT-" << i + 1 << " :";
		cin >> burstTime[i];
		rem_burstTime[i] = burstTime[i];
		sumOfBT += burstTime[i];
	}

	return sumOfBT;
}

void TurnAroundTime(int* rem_burstTime, int* waitingTime
	, int TimeQuatum, int time, int sumOfBT, int totalProcess)
{

	int j = 0;
	while (time < sumOfBT)
	{
		if (rem_burstTime[j] > TimeQuatum)
		{
			rem_burstTime[j] -= TimeQuatum;
			time += TimeQuatum;

		}
		else if (rem_burstTime[j] <= TimeQuatum && rem_burstTime[j] - TimeQuatum == 0)
		{
			time += rem_burstTime[j];
			rem_burstTime[j] -= rem_burstTime[j];
			waitingTime[j] = time;

		}
		else if (rem_burstTime[j] < TimeQuatum && rem_burstTime[j] != 0)
		{
			time += rem_burstTime[j];
			rem_burstTime[j] -= rem_burstTime[j];
			waitingTime[j] = time;

		}

		if (j + 1 == totalProcess)
		{
			j = -1;
		}
		j++;



	}
}
void Print(int* BT, int* TAT, int* WT, int totalProcess)
{
	int i = 0;
	cout << "Pno\t" << "BT\t" << "WT\t" << "TAT" << endl;
	while (i < totalProcess)
	{
		cout << i + 1 << "\t" << BT[i] << "\t" << WT[i] << "\t" << TAT[i] << endl;
		i++;
	}




}

void  WaitingTime(int* burstTime, int* waitingTime, int totalProcess, int* TAT)
{
	int i = 0;

	while (i < totalProcess)
	{
		TAT[i] = waitingTime[i] - burstTime[i];
		i++;
	}



}
int main()
{
	int option;
	cout << "1) Round Robin with Same Arival Time\n2)Round Robin with different Arival Time\nENTER : ";
	cin >> option;
	if (option == 2)
	{

		int* burstTime, * rem_burstTime, * TAT, * CT,
			* arivalTime, * WT, totalProcess, timeQuatum
			, Time = 0, sumOfBt = 0;
		double AverageWT, AverageTAT;
		queue<int> readyQueue;
		cout << "Enter Total Number of processes:";
		cin >> totalProcess;




		cout << "Enter Time Quatum:";
		cin >> timeQuatum;

		burstTime = new int[totalProcess];
		rem_burstTime = new int[totalProcess];
		arivalTime = new int[totalProcess];
		TAT = new int[totalProcess];
		CT = new int[totalProcess];
		WT = new int[totalProcess];
		sumOfBt = Input_DIFF_AT(burstTime, rem_burstTime, arivalTime, totalProcess, sumOfBt);

		CAL_CT_DIFF_AT(burstTime, rem_burstTime, arivalTime, totalProcess, sumOfBt, Time
			, timeQuatum, readyQueue, CT);

		TurnARoundTime_AND_WaitingTimeCal(TAT, CT, arivalTime, totalProcess);

		TurnARoundTime_AND_WaitingTimeCal(WT, TAT, burstTime, totalProcess);
		

		AverageTAT = averageFinder(TAT, totalProcess);

		AverageWT = averageFinder(WT, totalProcess);

		Print_DIFF_AT(burstTime,TAT,WT,arivalTime,totalProcess,CT);

		cout << "\n\nAverage Waiting Time: " << AverageWT << "\nAverage Turn Around Time : " << AverageTAT << endl;


	}
	else 
	{
		int* rem_burstTime, * burstTime,
			* waitingTime, * TAT, totalProcess,
			TimeQuatum, time = 0, sumOfBT = 0;
		double AverageWT, AverageTAT;

		cout << "Enter Total Number of Process:";
		cin >> totalProcess;
		cout << "Enter Time Quantum:";
		cin >> TimeQuatum;

		rem_burstTime = new int[totalProcess];
		burstTime = new int[totalProcess];
		waitingTime = new int[totalProcess];
		TAT = new int[totalProcess];

		sumOfBT = Input(rem_burstTime, burstTime, totalProcess);

		TurnAroundTime(rem_burstTime, TAT
			, TimeQuatum, time, sumOfBT, totalProcess);

		WaitingTime(burstTime, TAT, totalProcess, waitingTime);


		AverageWT = averageFinder(waitingTime, totalProcess);
		AverageTAT = averageFinder(TAT, totalProcess);
		cout << endl << endl;
		Print(burstTime, TAT, waitingTime, totalProcess);


		cout << "\n\nAverage Waiting Time: " << AverageWT << "\nAverage Turn Around Time : " << AverageTAT;

	
	
	}


}



