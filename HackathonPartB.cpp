// HACKATHON PART B
// GROUP 22 || CPT11

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ifstream listdevice;                            //declaring the file
	string model, make, processor, speed;			//declaring all the phone specs
	int price, ROM, RAM, maincam, frntcam, battery;
	
	int price1, price2, price3;			//THe phone prices that meet the requirements are saved.
	
	int imp1,imp2=0,imp3=0, count=1, display = 0; //user preferences
	
	
	
	listdevice.open("input 2.txt");
	
	cout << "Here's the lisst of available devices:\n\n";
	cout << setw(20) << left << "Model" << setw(20) << "Make" 
         << setw(20) << "Price (RM)" << setw(20) << "Processor" 
         << setw(20) << "Speed (GHz)" << setw(20) << "ROM" 
         << setw(20) << "RAM"   << setw(20) << "Main Camera"
         << setw(20) << "Front Camera" << setw(20) << "Battery" << endl << endl;
	
	//displaying all the available devices
	while(listdevice)
	{
		getline(listdevice, model, '\t');		//reading the input files
		getline(listdevice, make, '\t');
		listdevice >> price;
		listdevice.ignore();
		getline(listdevice, processor, '\t');
		getline(listdevice, speed, '\t');
		listdevice >> ROM;
		listdevice >> RAM;
		listdevice >> maincam;
		listdevice >> frntcam;
		listdevice >> battery;
		listdevice.ignore();
		
		cout << setw(20) << left << model << setw(20) << make 
             << setw(20) << price << setw(20) << processor << setw(20) 
             << speed << setw(20) << ROM << setw(20) << RAM 
             << setw(20) << maincam << setw(20) << frntcam 
             << setw(20) << battery;
            
		cout << endl;
        
	}
	
	system("pause");		//pause
	system("CLS");			//clear screen
	
	for(int count=1; count <=3 ; count++)   	//asking for user input
	{											//user will choose the most important specs
		cout << "From this features, which is the most important specs for you?\n"
			 << "You may enter more than one (press enter after each input.)\n\n";
		cout << "1 --> ROM Size\n"
			 << "2 --> RAM Size\n"
		 	 << "3 --> Battery\n"
		 	 << "4 --> Exit\n\n"
		 	 << "Enter your option: ";
		 
		if(count==1)
			cin >> imp1;
		if(count==2)
			cin >> imp2;
		if(count==3)
			cin >> imp3;
		
		system("CLS");

		if(imp2==4 || imp3 == 4)  //will break for loop if input = exit
			break;
	}
	
	//Displaying the best phone based on user most important specs
	
	cout << "Best phones based on your preference are: \n\n";
	cout << " " << " | " << left << setw(20) << "Model" << setw(20) << "Make" 
         << setw(20) << "Price (RM)" << setw(20) << "Processor" 
         << setw(20) << "Speed (GHz)" << setw(20) << "ROM Size" 
         << setw(20) << "RAM Size"   << setw(20) << "Main Camera"
         << setw(20) << "Front Camera" << setw(20) << "Battery" << endl << endl;
         
	if (imp1 == 1)
	{
		listdevice.clear();				//resting the pointer back to the beggining
		listdevice.seekg(0);
		
		count = 0 ;
		int bestROM;
		
		while(listdevice && display !=3)				//reading and comparing from the input file
		{												//it will stop comparing the file reach the end or 
														//at least 3 devices are already display
			if (count == 0)
				bestROM = 512;
			if (count == 1)
				bestROM = 256;
			
			getline(listdevice, model, '\t');
			getline(listdevice, make, '\t');
			listdevice >> price;
			listdevice.ignore();
			getline(listdevice, processor, '\t');
			getline(listdevice, speed, '\t');
			listdevice >> ROM;
			listdevice >> RAM;
			listdevice >> maincam;
			listdevice >> frntcam;
			listdevice >> battery;
			listdevice.ignore();	
			
			if(ROM == bestROM)
			{
			cout << display + 1 << " | " << setw(20) << left << model << setw(20) << make 
             << setw(20) << price << setw(20) << processor << setw(20) 
             << speed << setw(20) << ROM << setw(20) << RAM 
             << setw(20) << maincam << setw(20) << frntcam 
             << setw(20) << battery;
       		 cout << endl;
       		 
       		if(display == 0)
       		 	price1 = price;
       		if(display == 1)
       		 	price2 = price;
       		if(display == 2)
       			price3 = price;
       			
       		 display++;
			}
			
			if(listdevice.eof())
			{
				listdevice.clear();
				listdevice.seekg(0);
				count++;
			}
		}
	}
	
	//reading and comparing from the input file
	//it will stop comparing the file reach the end or 
	//at least 3 devices are already display
	
	else if(imp1==2)									
	{
		listdevice.clear();
		listdevice.seekg(0);
		
		count = 0 ;
		int bestRAM;
		
		while(listdevice && display !=3)
		{
			
			if (count==0)
				bestRAM=16;
			if (count==1)
				bestRAM=12;
			
			getline(listdevice, model, '\t');
			getline(listdevice, make, '\t');
			listdevice >> price;
			listdevice.ignore();
			getline(listdevice, processor, '\t');
			getline(listdevice, speed, '\t');
			listdevice >> ROM;
			listdevice >> RAM;
			listdevice >> maincam;
			listdevice >> frntcam;
			listdevice >> battery;
			listdevice.ignore();	
			
			if(RAM == bestRAM)
			{
			cout << display + 1 << " | " << setw(20) << left << model << setw(20) << make 
             << setw(20) << price << setw(20) << processor << setw(20) 
             << speed << setw(20) << ROM << setw(20) << RAM 
             << setw(20) << maincam << setw(20) << frntcam 
             << setw(20) << battery;
       		 cout << endl;
       		 
       		if(display == 0)
       		 	price1 = price;
       		if(display == 1)
       		 	price2 = price;
       		if(display == 2)
       			price3 = price;
       			
       		 display++;
			}
			
			if(listdevice.eof())
			{
				listdevice.clear();
				listdevice.seekg(0);
				count++;
			}
		}
	}
	
	//reading and comparing from the input file
	//it will stop comparing the file reach the end or 
	//at least 3 devices are already display
	
	else if(imp1==3)
	{
		listdevice.clear();
		listdevice.seekg(0);
		
		count = 0 ;
		int bestBattery;
		
		while(listdevice && display !=3)
		{
			
			if (count==0)
				bestBattery=4500;
			if (count==1)
				bestBattery=4400;
			
			getline(listdevice, model, '\t');
			getline(listdevice, make, '\t');
			listdevice >> price;
			listdevice.ignore();
			getline(listdevice, processor, '\t');
			getline(listdevice, speed, '\t');
			listdevice >> ROM;
			listdevice >> RAM;
			listdevice >> maincam;
			listdevice >> frntcam;
			listdevice >> battery;
			listdevice.ignore();	
			
			if(battery >= bestBattery)
			{
			cout << display + 1 << " | " << setw(20) << left << model << setw(20) << make 
             << setw(20) << price << setw(20) << processor << setw(20) 
             << speed << setw(20) << ROM << setw(20) << RAM 
             << setw(20) << maincam << setw(20) << frntcam 
             << setw(20) << battery;
       		 cout << endl;
       		 
       		if(display == 0)
       		 	price1 = price;
       		if(display == 1)
       		 	price2 = price;
       		if(display == 2)
       			price3 = price;
       			
       		 display++;
			}
			
			if(listdevice.eof())
			{
				listdevice.clear();
				listdevice.seekg(0);
				count++;
			}
		}
	}

	//code when user choose their prefer device based on the list of 3.
	
	int sum = 0, useroption;
	
	cout << "\nPlease choose your prefer option: ";
	cin >> useroption;

	if(useroption == 1)
		sum=price1;
	else if(useroption == 2)
		sum=price2;
	else if(useroption == 3)
		sum=price3;
		
	system("CLS");	
	
	//extra accessories for user to choose.
	do
	{
		
		cout << "Here the list of various accesories.\nYou may choose more than one" << endl;;
		cout << setw(15) << left << "Option" << setw(30) << "Item" << setw(30) << "Prices(RM)" << endl;
		
		cout << setw(15) << "1." << setw(30) << "Phone Cover" << setw(30) << "10" << endl 
		     << setw(15) << "2." << setw(30) << "Fast Charger" << setw(30) << "25" << endl
			 << setw(15) << "3." << setw(30) << "Screen Protector" << setw(30) << "15" << endl
			 << "\nEnter 0 to exit" << endl << endl;
			 
		cout << "Please enter your option: ";
		cin >> useroption;
		
		if(useroption == 1)
			sum+=10;
		if(useroption == 2)
			sum+=25;
		if(useroption == 3)
			sum+=15;
		
		system("CLS");
		
	}while(useroption!=0);
	
	//show the total amount spent.
	
	cout << "Total price you spent is: RM" << sum;
	
	listdevice.close();
	
	return 0;
}
