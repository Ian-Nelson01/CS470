#include <iostream>
#include <string>
#include <cstring>

int main() { 
	std::string strPrompt = ("If i am printed, something went wrong.");
	std::cout << "CWU SHELL";
	//std::cout << myPrompt;
	while(strPrompt != "exit"){
		std::cout << " > ";
		std::getline(std::cin,strPrompt);
		
		const char* arrPrompt = strPrompt.data();
		
		// test prints dont need
		//std::cout << strPrompt;
		int myLength = strPrompt.length();
		// osinfo
		
		//const char* arrPrompt = strPrompt.data();
		
		// redo on string tokenizer
		//int strLength = strPrompt.length();
		
		
		//strcpy(arrPrompt, strPrompt.c_str()); // copies string to arr
		
		
		/*
		
		//shit above dont fucking work
		int n = 0;
		while (n <= strLength){
		arrPrompt[n] = strPrompt[n];
		n = n+1;
		}
		*//*
		
		int ccounter = 0;
		for (arrPrompt, ){
			ccounter = ccounter+1;
		}
		
		*/
		
		
		/*
		// test section: we need to determine what my array even is, as it is being SUS
		int i = 0;
		while (i <= arrPrompt.length()){
			std::cout << arrPrompt[i];
			std::cout << "\n";
			i = i +1;
		}
		*/
		
		
		
		
		// space formatter
		int numSpaces = 0;
		int iterator = 0;
		bool started = false;
		std::string stringBuild = "";
		
		//tester
		std::cout << ((signed)(sizeof(arrPrompt))/((signed)(sizeof(arrPrompt[0]))));
		std::cout << myLength;
		
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
			//std::string testStr = "building: " + stringBuild;
			//std::cout << testStr;
		}
	
		// spaces after: if last char is a space, use erase method.
		if(stringBuild[stringBuild.length()-1] == ' '){
			strPrompt = stringBuild.substr(0, stringBuild.length()-1);
		}
		else{
			strPrompt = stringBuild;
		}
			
				// test prints dont need
	
		std::string testStr = "formatted" + strPrompt;
		std::cout << testStr;

		
		// osifo
		
		std::string osA = "osinfo -a";
		
		std::string osS =  "osinfo -s";
		
		std::string osV = "osinfo -v";
		
		
		if (strPrompt.compare(osA)){
			system("uname -m");
		}
		if (strPrompt.compare(osS)){
			system("uname -o");
		}
		if (strPrompt.compare(osV)){
			system("cat /etc/os-release");
		}
		

	}
	
	
	return 0;
}
