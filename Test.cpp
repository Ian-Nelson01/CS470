#include <iostream>
#include <string>

int main() { 
	std::string myPrompt = ("chug");
	std::cout << "CWU SHELL";
	//std::cout << myPrompt;
	while(myPrompt != "exit"){
		std::cout << " ligma ";
		std::cin >> myPrompt;
		
		

		std::cout << myPrompt;
		// osinfo
		if (myPrompt == "osinfo-a"){
			system("uname -m");
		}
		if (myPrompt == "osinfo -s"){
			system("uname -o");
		}
		if (myPrompt == "osinfo -v"){
			system("cat /etc/os-release");
		}
		

	}
	
	
	return 0;
}
