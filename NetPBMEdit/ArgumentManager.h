#pragma once
class ArgumentManager
{
	char** files;
	char*  current_file;
	char** command;
	char*  current_command;
public:
	ArgumentManager(char** ARGV, int ARGC);
	~ArgumentManager();
	char* nextFile();
	char* nextCommand();
	void resetFilePointer();
	void resetCommandPointer();

private:
	ArgumentManager();
};

