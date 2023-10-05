//Honor Code: I pledge that I have neither given nor received help from anyone other than the instructor/TA for all program components included here!
//Student: Xander Thompson - 42046934
#include <iostream>
#include <queue>
#include <sstream>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <fcntl.h>
#include <filesystem>
#include <linux/magic.h>
//User defined header file
#include "man.h"

using namespace std;
namespace fs = std::filesystem;

//Check if something only has digits that are chars
bool is_digits(const string &str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

//Exit function that takes in a queue of strings
void exitor(queue<string> commands) {
    //Drops the exit command
    commands.pop();
    //If the queue is empty, exit the program
    if (commands.empty()) {
        exit(0);
        //If the queue is not empty, exit the program with the number in second place
    } else {
        //Checking if -h or --help is given and returning instead of exiting
        if(commands.front() == "-h" || commands.front() == "--help"){
            manual("exit");
            return;
        }
        commands.pop();
        //Check if digits, else throw error
        if (!is_digits(commands.front())) {
            cout << "Error: exit takes one integer argument" << endl;
        }
        //stoi - string to integer, learned today
        exit(stoi(commands.front()));
    }
}

//Function to split a string into a queue of strings, avoiding excess spaces
queue<string> split(const string &input) {
    queue<string> toparse;
    stringstream str(input);
    string temp;

    while (str >> temp) {
        toparse.push(temp);
    }
    return toparse;
}

//Function for fileinformation, *args wll refer to which command to do
void fileinfo(string switchinfo, string path_name){
    //Checking if -h or --help is given for switch
    //Bad practice, but literally works
    if(path_name == "-h" || path_name == "--help"){
        manual("fileinfo");
        return;
    }

    //remove the - from the switch
    if(switchinfo.front() == '-'){
        switchinfo.erase(0, 1);
    }

    //While there are still switches to check
    while(switchinfo.length() > 0) {

        //inode or -t
        if (switchinfo.front() == 'i') {
            struct stat file;
            stat(path_name.c_str(), &file);
            cout << "inode: " << file.st_ino << endl;
        }

        //filetype or -t
        else if(switchinfo.front() == 't'){
            //Using filesystem library
            //Prints out what kind of filetype
            if(fs::is_directory(path_name)){
                cout << "filetype: directory" << endl;
            }
            else if(fs::is_regular_file(path_name)){
                cout << "filetype: regular file" << endl;
            }
            else if(fs::is_symlink(path_name)){
                cout << "filetype: symbolic link" << endl;
            }
            else if(fs::is_other(path_name)){
                cout << "filetype: other" << endl;
            }
        }

        //modification date or -m
        else if(switchinfo.front() == 'm'){
            struct stat file;
            stat(path_name.c_str(), &file);
            cout << "modification date: " << ctime(&file.st_mtime) << endl;
        }

        else if (!(switchinfo.empty())){
            cout << "Error: invalid switch, check manual for switches" << endl;
            break;
        }
        //removes the letter given
        switchinfo.erase(0, 1);
    }

}
//Gets the filetype using magic.h
string get_filetype(string path_name) {
    //Why on earth is it one file that holds all these magic numbers
    //It took me way too long to figure out how to use these
    //I hate it here in linux land
    struct statfs sysinfo;
    statfs(path_name.c_str(), &sysinfo);
    switch (sysinfo.f_type) {
        case EXT2_SUPER_MAGIC:
            return "EXT";
        case MSDOS_SUPER_MAGIC:
            return "DOS";
        case XFS_SUPER_MAGIC :
            return "XFS";
        default:
            return "unknown / NTFS or other";
    }
}

//Function for osinfo, takes the switch information
void osinfo(string switchinfo) {
    //Checking if -h or --help is given for switch
    if (switchinfo == "-h" || switchinfo == "--help") {
        manual("osinfo");
        return;
    }

    //Remove the '-' from the switch
    if (switchinfo.front() == '-') {
        switchinfo.erase(0, 1);
    }
    //Setting up the struct for stats
    struct stat sysdatainfo;
    struct statfs sysinfo;

    while(switchinfo.length() > 0) {
        //If -T, will print out the type of filesystem currently in use
        if (switchinfo.front() == 'T'){
            string filetype = get_filetype("/");
            cout << "Filesystem type: " << filetype << endl;
        }
        //If -b will print out total number of blocks of file system
        else if (switchinfo.front() == 'b') {
            stat("/", &sysdatainfo);
            cout << "Total number of blocks: " << sysdatainfo.st_blksize << endl;
        }
        //If -s will print out max number of characters that can be used within a filename
        else if(switchinfo.front() == 's'){
            cout << "Max number of characters in a filename: " << FILENAME_MAX << endl;
        }
        //Removes said switch
        switchinfo.erase(0, 1);
    }
}

int main() {
    string prompt = "cwushell> ";
    string input;
    //Basic loop to take input and print it back out.
    while (true) {

        //Get input from the user
        cout << prompt;
        getline(cin, input);

        //Convert string to queue of strings
        queue<string> commands = split(input);

        //MANUAL command (help)
        //prints out manual for cwushell
        if(commands.front() == "man" || commands.front() == "manual"){
            commands.pop();
            manual(commands.front());
        }

        //EXIT - throw error if 1+ arguments, else runs exitor function
        //exits program
        else if (commands.front() == "exit" && commands.size() <= 2) {
            exitor(commands);
        } else if (commands.front() == "exit" && commands.size() > 2) {
            cout << "Error: exit takes one integer argument" << endl;
        }

        //PROMPT - throws error if number given or 1+ arguments
        //sets prompt to default or given string
        else if (commands.front() == "prompt") {
            //If there is no second argument, set prompt to default
            if (commands.size() == 1) {
                prompt = "cwushell> ";
                //If there is a second argument, set prompt to that
            } else if (commands.size() == 2) {
                //Drops 'prompt' from the queue
                commands.pop();
                //Checking if argument given is -h or --help
                if (commands.front() == "-h" || commands.front() == "--help") {
                    manual("prompt");
                }
                //Checks if second argument is digits, if so, throw error
                else if (is_digits(commands.front())) {
                    cout << "Error: prompt takes one string argument" << endl;
                } else {
                    prompt = commands.front() + "> ";
                }
            } else {
                cout << "Error: prompt takes one string argument" << endl;
            }
        }

        //FILEINFO - has switches -i, -t, -m
        //prints out file information, depending on switch
        else if (commands.front() == "fileinfo"){
            //Drops 'fileinfo' from the queue
            commands.pop();
            //Checking argument in second place
            if(commands.empty()){
               cout << "Error: fileinfo requires a file path" << endl;
            }
            //If a switch is in the front
            else{
                //If there is no file path
                if(commands.size() == 0){
                    cout << "Error: fileinfo requires a file path" << endl;
                }
                //If there is a file path
                else if(commands.size() == 2 && (commands.front().at(0) == '-')){
                    string switchcommands = commands.front();
                    commands.pop();
                    fileinfo(switchcommands, commands.front());
                }
                //Indictes that only a path was given
                else if(commands.size() == 1){
                    string switchcommands = "-itm";
                    fileinfo(switchcommands, commands.front());
                }
                //If there is more than one argument
                else{
                    cout << "Error: fileinfo takes a switch and a file path" << endl;
                }
            }
        }

        //OSINFO - has switches -T, -b, and -s
        else if (commands.front() == "osinfo"){
            //Remove osinfo from the queue
            commands.pop();

            //If there is no argument
            if(commands.size() == 0){
                cout << "Error: osinfo takes a switch" << endl;
            }
            //If there is an argument
            else if(commands.size() >= 1){
                //Means a switch is in the front, pass to osinfo
                if(commands.front().at(0) == '-'){
                    string switchcommands = commands.front();
                    commands.pop();
                    osinfo(switchcommands);
                }
            }

            //If there is more than one argument
            else{
                cout << "Error: osinfo requires a switch" << endl;
            }
        }

        //Other existing commands
        //Falls under 5, meaning system() or exec() can be used
        else{
            cout << "Error: command not found in " << prompt << endl;
            cout << "Excute in system shell instead? (y/n)";
            string temp;
            getline(cin, temp);
            if (temp == "y"){
                system(input.c_str());
            } else {
                continue;
            }
        }
    }
    return 0;
}