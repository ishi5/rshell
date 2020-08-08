#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <vector>
#include <string>

class Executor{

        public:
                Executor();
                //Executor(const std::vector<Token*>& t);
                int execute(char* argv, char **args);
                //int execute(std::vector <std::string> tokens);
                int testExecute(char** args);
        private:
                std::vector<char*> chline;


};

#endif
                                                                                                                                                            
