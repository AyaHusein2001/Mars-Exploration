#include<iostream>
#include"mission.h"
#include"MarsStation.h"
#include"Events.h"
#include"Cancellation.h"
#include"Formulation.h"
#include"PriorityNode.h"
#include"rover.h"
#include"Queue.h"
#include"PriorityQueue.h"
#include<Windows.h>
using namespace std;

class interacmode :private MarsStation
{
public:

	void display()
	{
		int a, b, c, i, j;
		rover *Erover=new rover;
		rover *Mrover= new rover;
		rover *Prover= new rover;                   //pointers to objects
		rover *incheck= new rover;
		rover *inexec= new rover;
		mission *Emis=new mission;
		mission *Pmis= new mission;
		mission *Mmis= new mission;
		mission *Emis= new mission;
		rover *pcheck= new rover;
		rover *Mcheck= new rover;
		rover *Echeck= new rover;


		int* arrA = new int[100];
		int* arrB = new int[100];
		int* arrC = new int[100];
		int day = 1;
		while(day)
		{
			cout << "current day:" << day << endl;
			cout << "Press ENTER to continue......." << endl;                // this for interactive mode
			cin.get();
			while (!Mountmissions.isEmpty())
			{
				if (Mountmissions.dequeue(Mmis)&&Mmis->getformulationday()<day)
				{
					c++;

					arrC[i] = Mmis->getid();
					i++;
					
				}
			}
			i = 0;
			while (!polarmissions.isEmpty())
			{
				if (polarmissions.dequeue(Pmis)&&Pmis->getformulationday() < day)
				{
					b++;
					arrB[i] = Pmis->getid();
					i++;
				}

			}
			i = 0;
			while (!Emergmissions.isEmpty())
			{
				if (Emergmissions.dequeue(Emis) && Emis->getformulationday() < day)
				{
					a++;
					arrA[i] = Emis->getid();
					i++;
				}

			}
			
			cout << a + b + c << "waiting Missions:";
			cout << "  " << '[';
			while(!Emergmissions.isEmpty()&& Emis->getformulationday() < day)
			{
				cout << arrA[j] << ',';
				j++;
			}
			cout << ']' << "  " << '(';
			j = 0;
			while (!polarmissions.isEmpty() &&Pmis->getformulationday() < day)
			{
				cout << arrB[j] << ',';
				j++;
			}
			cout << ')' << ' ' << '{';
			j = 0;
			while(!Mountmissions.isEmpty() && Mmis->getformulationday() < day)
			{
				cout << arrC[j] << ',';
				j++ ;
			}
			cout << '}' << endl;


		
			
			
			a = b = c = 0;
			while (!InExecrovers.isEmpty())
			{
				a++;                                            //Here we use the function to get the mission of the passed rover

			}

			cout << a << "In-Execution Missions/Rovers:" << ' ';
			cout << '[';
			while (!InExecrovers.isEmpty())
			{
				if (InExecrovers.dequeue(inexec))
				{ if ( inexec->getrovertype()=='E')
					cout << inexec->getnomissions() << '/' << inexec << ',';
				}
			}
			cout << ']' << ' ' << '(';
			while (!InExecrovers.isEmpty())
			{
				if (InExecrovers.dequeue(inexec)
				{
					if (inexec->getrovertype() == 'P')
					cout << inexec->getnomissions() << '/' << inexec << ',';
				}
			}
			cout << ')' << ' ' << '{';
			while (!InExecrovers.isEmpty())
			{
				if (InExecrovers.dequeue(inexec)
				{  
					if(inexec->getrovertype()=='M')
					cout << inexec->getnomissions()<< '/' << inexec << ',';
				}
			}
			cout << '}' << endl;


			a = b = c = i = j = 0;
			int c1, c2;
			while (!Erovers.isEmpty())                                          //AVAILABLE ROVERS
			{
				a++;

			}
			while (!EInCheckUp.isEmpty())
			{
				b++;
			}
			
			while (InExecrovers.dequeue(Erover) || !InExecrovers.isEmpty() &&Erover->getrovertype()=='E')
			
			{
				c++;
			}
			c1 = a - b - c;
			c2 = c1;
			a = b = c = c1 = 0;
			while (!Provers.isEmpty())                                          //AVAILABLE ROVERS
			{
				a++;

			}
			while (!PInCheckUp.isEmpty())
			{
				b++;
			}

			while (InExecrovers.dequeue(Prover) || !InExecrovers.isEmpty() && Prover->getrovertype() == 'P')

			{
				c++;
			}
			c1 = a - b - c;
			c2 += c1;
			a = b = c = c1 = 0;
			while (!Mrovers.isEmpty())                                          //AVAILABLE ROVERS
			{
				a++;

			}
			while (!MInCheckUp.isEmpty())
			{
				b++;
			}

			while (InExecrovers.dequeue(Mrover) || !InExecrovers.isEmpty() && Mrover->getrovertype() == 'M')
			{
				c++;
			}
			c1 = a - b - c;
			c2 += c1;
			cout << c2 << "Available rovers" << endl;





			a = b = c = 0;               //incheckup rovers
			while (!PInCheckUp.isEmpty())
			{
				a++;

			}
			while (!MInCheckUp.isEmpty())
			{
				b++;

			}
			while (!EInCheckUp.isEmpty())
			{
				c++;


			}

			cout << a + b + c << "In-checkup Rovers:";
			cout << '[';
			while (!EInCheckUp.isEmpty())
			{        
				if (EInCheckUp.dequeue(Echeck))
				{
					cout << Echeck->getnomissions() << ',';
				}
			}
			cout << ' ' << ']' << '(' << ;
			while (!PInCheckUp.isEmpty())
			{
				if (PInCheckUp.dequeue(Pcheck))
				{
					cout << pcheck->getnomissions() << ',';
				}
			}
			cout << ')' << ' ' << '{';
			while (!MInCheckUp.isEmpty())
			{
				if (MInCheckUp.dequeue(Mcheck))
				{
					cout << Mcheck->getnomissions() << ',';
				}
			}
			cout << '}' << endl;
			

			a = b = c = i = 0;                       //IMPLEMENTAION FOR COMPLETED MISSIONS
			int k, m, d;
			while (!Compmissions.isEmpty())
			{
				a++;
				if (compmissions.dequeue(Mmis)&&Mmis->getmissiontype()=='M')
				{
					arrA[i] = Mmis->getid();
					i++;
				}
				else if (compmissions.dequeue(Emis)&&Emis->getmissiontype()== 'E')
				{
					arrB[k] = Emis->getid();
					k++;
				}
				else if (compmissions.dequeue(Pmis)&&Pmis->getmissiontype() == 'P')
				{
					arrC[m] = Pmis->getid();
					m++;
				}
				else
				{
					rerurn;
				}
			}

			cout << a << "completed missions:";
			cout << ' ' << '{';
			i = 0;
			while (!Compmissions.isEmpty() && compmissions.dequeue(Mmis)&&Mmis->getmissiontype() == 'M')
			{
				cout << arrA[i] << ',';
				i++;
			}
			i = 0;
			cout << '}' << ' ' << '[';
			while (!Compmissions.isEmpty() && compmissions.dequeue(Emis)&&Emis->getmissiontype() == 'E')
			{
				cout << arrB[i] << ',';
				i++;
			}
			cout << ']' << ' ' << '(';
			while (!Compmissions.isEmpty() && compmissions.dequeue(Pmis)&&Pmis->getmissiontype()== 'P')
			{
				cout << arrB[i] << ',';
				i++;
			}
			cout << ')' << endl;
			
			day++;
		}
	}
};
class stepbystepmode :public interacmode
{
public:
	void display()
	{
		int a, b, c, i, j;
		rover* Erover = new rover;
		rover* Mrover = new rover;
		rover* Prover = new rover;                   //pointers to objects
		rover* incheck = new rover;
		rover* inexec = new rover;
		mission* Emis = new mission;
		mission* Pmis = new mission;
		mission* Mmis = new mission;
		mission* Emis = new mission;
		rover* pcheck = new rover;
		rover* Mcheck = new rover;
		rover* Echeck = new rover;


		int* arrA = new int[100];
		int* arrB = new int[100];
		int* arrC = new int[100];
		int day = 1;
		while (day)
		{
			cout << "current day:" << day << endl;
			cout << "Press ENTER to continue......." << endl;                // this for interactive mode
			cin.get();
			while (!Mountmissions.isEmpty())
			{
				if (Mountmissions.dequeue(Mmis) && Mmis->getformulationday() < day)
				{
					c++;

					arrC[i] = Mmis->getid();
					i++;

				}
			}
			i = 0;
			while (!polarmissions.isEmpty())
			{
				if (polarmissions.dequeue(Pmis) && Pmis->getformulationday() < day)
				{
					b++;
					arrB[i] = Pmis->getid();
					i++;
				}

			}
			i = 0;
			while (!Emergmissions.isEmpty())
			{
				if (Emergmissions.dequeue(Emis) && Emis->getformulationday() < day)
				{
					a++;
					arrA[i] = Emis->getid();
					i++;
				}

			}

			cout << a + b + c << "waiting Missions:";
			cout << "  " << '[';
			while (!Emergmissions.isEmpty() && Emis->getformulationday() < day)
			{
				cout << arrA[j] << ',';
				j++;
			}
			cout << ']' << "  " << '(';
			j = 0;
			while (!polarmissions.isEmpty() && Pmis->getformulationday() < day)
			{
				cout << arrB[j] << ',';
				j++;
			}
			cout << ')' << ' ' << '{';
			j = 0;
			while (!Mountmissions.isEmpty() && Mmis->getformulationday() < day)
			{
				cout << arrC[j] << ',';
				j++;
			}
			cout << '}' << endl;





			a = b = c = 0;
			while (!InExecrovers.isEmpty())
			{
				a++;                                            //Here we use the function to get the mission of the passed rover

			}

			cout << a << "In-Execution Missions/Rovers:" << ' ';
			cout << '[';
			while (!InExecrovers.isEmpty())
			{
				if (InExecrovers.dequeue(inexec))
				{
					if (inexec->getrovertype() == 'E')
						cout << inexec->getnomissions() << '/' << inexec << ',';
				}
			}
			cout << ']' << ' ' << '(';
			while (!InExecrovers.isEmpty())
			{
				if (InExecrovers.dequeue(inexec)
				{
					if (inexec->getrovertype() == 'P')
						cout << inexec->getnomissions() << '/' << inexec << ',';
				}
			}
			cout << ')' << ' ' << '{';
				while (!InExecrovers.isEmpty())
				{
					if (InExecrovers.dequeue(inexec)
					{
						if (inexec->getrovertype() == 'M')
							cout << inexec->getnomissions() << '/' << inexec << ',';
					}
				}
			cout << '}' << endl;


				a = b = c = i = j = 0;
				int c1, c2;
				while (!Erovers.isEmpty())                                          //AVAILABLE ROVERS
				{
					a++;

				}
			while (!EInCheckUp.isEmpty())
			{
				b++;
			}

			while (InExecrovers.dequeue(Erover) || !InExecrovers.isEmpty() && Erover->getrovertype() == 'E')

			{
				c++;
			}
			c1 = a - b - c;
			c2 = c1;
			a = b = c = c1 = 0;
			while (!Provers.isEmpty())                                          //AVAILABLE ROVERS
			{
				a++;

			}
			while (!PInCheckUp.isEmpty())
			{
				b++;
			}

			while (InExecrovers.dequeue(Prover) || !InExecrovers.isEmpty() && Prover->getrovertype() == 'P')

			{
				c++;
			}
			c1 = a - b - c;
			c2 += c1;
			a = b = c = c1 = 0;
			while (!Mrovers.isEmpty())                                          //AVAILABLE ROVERS
			{
				a++;

			}
			while (!MInCheckUp.isEmpty())
			{
				b++;
			}

			while (InExecrovers.dequeue(Mrover) || !InExecrovers.isEmpty() && Mrover->getrovertype() == 'M')
			{
				c++;
			}
			c1 = a - b - c;
			c2 += c1;
			cout << c2 << "Available rovers" << endl;





			a = b = c = 0;               //incheckup rovers
			while (!PInCheckUp.isEmpty())
			{
				a++;

			}
			while (!MInCheckUp.isEmpty())
			{
				b++;

			}
			while (!EInCheckUp.isEmpty())
			{
				c++;


			}

			cout << a + b + c << "In-checkup Rovers:";
			cout << '[';
			while (!EInCheckUp.isEmpty())
			{
				if (EInCheckUp.dequeue(Echeck))
				{
					cout << Echeck->getnomissions() << ',';
				}
			}
			cout << ' ' << ']' << '(' << ;
			while (!PInCheckUp.isEmpty())
			{
				if (PInCheckUp.dequeue(Pcheck))
				{
					cout << pcheck->getnomissions() << ',';
				}
			}
			cout << ')' << ' ' << '{';
			while (!MInCheckUp.isEmpty())
			{
				if (MInCheckUp.dequeue(Mcheck))
				{
					cout << Mcheck->getnomissions() << ',';
				}
			}
			cout << '}' << endl;


			a = b = c = i = 0;                       //IMPLEMENTAION FOR COMPLETED MISSIONS
			int k, m, d;
			while (!Compmissions.isEmpty())
			{
				a++;
				if (compmissions.dequeue(Mmis) && Mmis->getmissiontype() == 'M')
				{
					arrA[i] = Mmis->getid();
					i++;
				}
				else if (compmissions.dequeue(Emis) && Emis->getmissiontype() == 'E')
				{
					arrB[k] = Emis->getid();
					k++;
				}
				else if (compmissions.dequeue(Pmis) && Pmis->getmissiontype() == 'P')
				{
					arrC[m] = Pmis->getid();
					m++;
				}
				else
				{
					rerurn;
				}
			}

			cout << a << "completed missions:";
			cout << ' ' << '{';
			i = 0;
			while (!Compmissions.isEmpty() && compmissions.dequeue(Mmis) && Mmis->getmissiontype() == 'M')
			{
				cout << arrA[i] << ',';
				i++;
			}
			i = 0;
			cout << '}' << ' ' << '[';
			while (!Compmissions.isEmpty() && compmissions.dequeue(Emis) && Emis->getmissiontype() == 'E')
			{
				cout << arrB[i] << ',';
				i++;
			}
			cout << ']' << ' ' << '(';
			while (!Compmissions.isEmpty() && compmissions.dequeue(Pmis) && Pmis->getmissiontype() == 'P')
			{
				cout << arrB[i] << ',';
				i++;
			}
			cout << ')' << endl;

			day++;
		}
	}
	
		
};



class silentmode 
{
	void display()
	{
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts...." << endl;
		PrintOutPutFile();
		cout << "Simulation ends,  output file created" << endl;
		
	}
};


int main()
{
	int indic;
	interacmode* ptr1;
	stepbystepmode* ptr2;
	silentmode* ptr3;
	cout << "To select iteractive mode Enter 0 , step by step mode Enter 1 and silent mode Enter 2" << endl;
	cin >> indic;
	if (indic == 0)
		ptr1->display();
	else if (indic == 1)
	{
		Sleep(1000);                                         // the property for step by step mode
		system("cls");
		ptr2->display();
	}
	else if (indic == 2)
		ptr3->display();
	else return;
	


	return 0;
}