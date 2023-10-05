#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

int main() { 
	std::string strPrompt = ("If i am printed, something went wrong.");
	std::cout << "CWU SHELL";
	//std::cout << myPrompt;
	while(strPrompt != "exit"){
		std::cout << " > ";
		std::getline(std::cin,strPrompt);
		int myLength = strPrompt.length();
		
		
		
		const char* arrPrompt = strPrompt.data();
		
// ensure lowercase
	
	for (int x = 0; x < myLength; x++){
		putchar(tolower(arrPrompt[x]));
	}
		
		
		
		
		
		// space formatter
		int numSpaces = 0;
		int iterator = 0;
		bool started = false;
		std::string stringBuild = "";
		

		
		while (iterator <=  myLength){
			if (started == false){
				// spaces before
				if (arrPrompt[iterator] != ' '){ // if not a space, add to string
					started = true;
				}
				else{
					iterator = iterator + 1; // if false, increment iterator
				}
			}
			else{ // after started
				// spaces during
				if (arrPrompt[iterator] != ' '){ // if not a space, add to string

					stringBuild = stringBuild + arrPrompt[iterator];
					numSpaces = 0;
					iterator = iterator + 1;
				}
				if (arrPrompt[iterator] == ' ' && numSpaces == 0){ // space, count 0
					stringBuild = stringBuild + ' ';//arrPrompt[iterator];
					numSpaces = 1;
					iterator = iterator + 1;
				}
				else if (arrPrompt[iterator] == ' ' && numSpaces == 1){ // space, count 1
					iterator = iterator + 1;
				}
			}

		}
	
		// spaces after: if last char is a space, use erase method.
		if(stringBuild[stringBuild.length()-1] == ' '){
			strPrompt = stringBuild.substr(0, stringBuild.length()-1);
		}
		else{
			strPrompt = stringBuild;
		}
			

		
		// osifo
		
		std::string osA = "osinfo -a";
		
		std::string osS =  "osinfo -s";
		
		std::string osV = "osinfo -v";
		
		//std::cout << strPrompt;
		//std::cout << osA;
		
		const char *str_inp1 = strPrompt.data();
		const char *str_inp2 = osA.data();
		const char *str_inp3 = osS.data();
		const char *str_inp4 = osV.data();
		
		
		if (strcmp(str_inp1, str_inp2) == 0){
			system("uname -m");
			continue;
		}
		
		if (strcmp(str_inp1, str_inp3) == 0){
			system("uname -o");
			continue;
		}
		if (strcmp(str_inp1, str_inp4  ) == 0){
			system("cat /etc/os-release");
			continue;
		}
		
		
		
		
		
		
		
		
		
		// fileinfo (just try to run it. if it works it works, if not, it doesnt.
		
		// string division?
		// chunks of string for the command, switch and filename.
		
		int ogLength = strPrompt.length();
		if (ogLength > 13){
			std::cout << "big let thru";
			
		
		std::string fiCommand = strPrompt.substr(0, 9);
		std::string fiSwitch = strPrompt.substr(0, 12);
		
		
		
		std::string remainderSwitch = strPrompt.substr(12, ogLength);
		std::string remainderCommand = strPrompt.substr(9, ogLength);
		
		/*std::cout << fiCommand;
		std::cout << fiSwitch;
		std::cout << "\n";
		std::cout << ogLength;
		std::cout << "\n";
		std::cout << remainderSwitch;
		*/
		const char *str_fiCommand = fiCommand.data();
		const char *str_fiSwitch = fiSwitch.data();
		const char *str_RemainC = remainderCommand.data();
		const char *str_RemainS = remainderSwitch.data();
		
		
		
		// need a way to isolate the command
		// take 11, run all else
		// take 8 run all else
		
		
		
		
		
		
		
		// string comparator

		std::string fiI = "fileinfo -i ";
		
		std::string fiT =  "fileinfo -t ";
		
		std::string fiM = "fileinfo -m ";
		
		std::string fiN = "fileinfo ";
		
		const char *str_inp5 = fiI.data();
		const char *str_inp6 = fiT.data();
		const char *str_inp7 = fiM.data();
		const char *str_inp8 = fiN.data();
		
		// adding the file name
		std::string cmd1 = "ls -i " + remainderSwitch;
		//std::cout << cmd1;
		const char *str_cmd1 = cmd1.data();
		
		std::string cmd2 =  "stat -c \"%F\" " + remainderSwitch;
		//std::cout << cmd2;
		const char *str_cmd2 = cmd2.data();
		
		std::string cmd3 =  "stat -c \"%Y\" " + remainderSwitch;
		std::cout << cmd3;
		const char *str_cmd3 = cmd3.data();
		
		// adding the file name
		std::string cmd4 = "ls -i " + remainderCommand;
		//std::cout << cmd1;
		const char *str_cmd4 = cmd4.data();
		
		std::string cmd5 =  "stat -c \"%F\" " + remainderCommand;
		std::cout << cmd5;
		const char *str_cmd5 = cmd5.data();
		
		std::string cmd6 =  "stat -c \"%Y\" " + remainderCommand;
		//std::cout << cmd2;
		const char *str_cmd6 = cmd6.data();
		std::cout << str_cmd6;
		
		
		
		
		
		// string comparisons
		if (strcmp(str_fiSwitch, str_inp5) == 0){
			system(str_cmd1);
			continue;
		}
		
		else if (strcmp(str_fiSwitch, str_inp6) == 0){
			system(str_cmd2);
			continue;
		}
		else if (strcmp(str_fiSwitch, str_inp7) == 0){
			system(str_cmd3);
			continue;
		} 
		else if (strcmp(str_fiCommand, str_inp8) == 0){
			system(str_cmd4);
			system(str_cmd5);
			system(str_cmd6);
			continue;
		} 
		
		
		// a horribly rough, but functional way to else if the lengths
		
	}else if(ogLength > 10){
				std::cout << "smol let thru";
		
		std::string fiCommand = strPrompt.substr(0, 9);
		
		
		
		
		
		std::string remainderCommand = strPrompt.substr(9, ogLength);
		
		/*std::cout << fiCommand;
		std::cout << fiSwitch;
		std::cout << "\n";
		std::cout << ogLength;
		std::cout << "\n";
		std::cout << remainderSwitch;
		*/
		const char *str_fiCommand = fiCommand.data();

		
		
		
		// need a way to isolate the command
		// take 11, run all else
		// take 8 run all else
		
		
		
		
		
		
		
		// string comparator

		std::string fiI = "fileinfo -i ";
		
		std::string fiT =  "fileinfo -t ";
		
		std::string fiM = "fileinfo -m ";
		
		std::string fiN = "fileinfo ";
		

		const char *str_inp8 = fiN.data();
		
		// adding the file name

		
		// adding the file name
		std::string cmd4 = "ls -i " + remainderCommand;
		//std::cout << cmd1;
		const char *str_cmd4 = cmd4.data();
		
		std::string cmd5 =  "stat -c \"%F\" " + remainderCommand;
		std::cout << cmd5;
		const char *str_cmd5 = cmd5.data();
		
		std::string cmd6 =  "stat -c \"%Y\" " + remainderCommand;
		//std::cout << cmd2;
		const char *str_cmd6 = cmd6.data();
		std::cout << str_cmd6;
		
		
		
		
		
		
		
		
		 if (strcmp(str_fiCommand, str_inp8) == 0){
			system(str_cmd4);
			system(str_cmd5);
			system(str_cmd6);
			continue;
		} 
		
	}

	
	
		
		
		
		
		
		

	}
	
	
	return 0;
}
