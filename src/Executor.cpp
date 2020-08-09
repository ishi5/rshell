#include "../header/Executor.h"
#include "../src/Tokenizer.cpp"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <array>
#include <sys/stat.h>
#include <string.h>

Executor::Executor(){

	chline.clear();

}

//Executor::Executor(const std::vector<Token*>& t){

//	Tokenizer call;

//	call.parsing(t);

//}


int Executor::execute(char* argv, char **args){

	//std::cout << "";

// std::cout << "In execute, argv is \"" << argv << "\"" << std::endl;

// std::cout << '\"' << argv << '\"' << std::endl;
	// If they gave us an empty line to execute

	if (strcmp(argv, "") == 0) {
		return 0;
	} 

	//if test then don't go through execvp ->call other fxn
	if( strcmp(argv, "test") == 0){
		return testExecute(args);
	}
	
	pid_t pid = fork();
	int status;
	
	if (pid  < 0) { //child
       	perror("Error: Child process failed");
           exit(1);
    }
   	else if (pid == 0) { 
        if (execvp(argv, args) != 0) {     
            perror("Error: fork() failed");
            exit(1);
        }
        exit(0);
    }
    else if(pid >0){ 
		if(waitpid(-1,&status,0) <0){ 
			perror("Child still in process");
		}
		if WIFEXITED(status){
			return WEXITSTATUS(status);
		} 
	} 

}                                     


int Executor::testExecute(char** args){
	struct stat buf;
	char* pfile;

	if(strcmp(args[1], "-d") == 0) {
		stat(args[2], &buf);	
		if(S_ISDIR(buf.st_mode) != 0) {
			std::cout << "(True)";
			std::cout << std::endl;
			return 0;

		}
		else {
			std::cout << "(False)";
			std::cout << std::endl;	
			return 1;
		}
	}

	/*else if(strcmp(args[1], "-e") == 0) {
		stat(args[2], &buf);	
		if(S_ISREG(buf.st_mode) != 0) {
			std::cout << "(True)";
			std::cout << std::endl;
			return 0;

		}

		else if(S_ISDIR(buf.st_mode) !=0){
			std::cout<<"(True)";
			return 0;
		}
		else {
			std::cout << "(False)";
			std::cout << std::endl;
			return 1;
		}

	
	}
	*/
    else if(strcmp(args[1], "-f")== 0) {
		stat(args[2], &buf);	
		if(S_ISREG(buf.st_mode) != 0) {
			std::cout << "(True)";
			std::cout << std::endl;
			return 0;
		}
		else {
			std::cout << "(False)";
			std::cout << std::endl;
			return 1;
		}	
	}

	else {
		if(strcmp(args[1], "-e") == 0) {
			stat(args[2], &buf);
		}		
		else { 
			stat(args[1], &buf);
		}

		if(S_ISDIR(buf.st_mode) != 0) {
			std::cout << "(True)";
			std::cout << std::endl;
			return 0;
		}

		else if(S_ISREG(buf.st_mode) !=0){
			std::cout<<"(True)";
			std::cout << std::endl;
			return 0;

		}
		else {
			std::cout << "(False)";
			std::cout << std::endl;
			return 1;
		}	
	}
}
	
