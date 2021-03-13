#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *cmd_format(int,char **);

int main(int argc, char **argv)
{
	int ret = -1;
	if(argc < 2){
		perror("Command is missing...!\n");
		return ret;
	}
	const char *cmd = cmd_format(argc, argv);
	ret = system(cmd);
	if (ret != 0){
		perror("cmd can not be executed");
		return ret;
	}
	return EXIT_SUCCESS;
}

const char *cmd_format(int nbr, char **string){
	int cmd_len = 0;
	for(int i=1; i<nbr; i++){
		cmd_len += strlen(string[i])+1;
	}	
	--cmd_len;
	char *cmd = (char*)malloc(sizeof(char)*cmd_len);
	for(int i=1; i<nbr; i++){
		strcat(cmd, " ");
		strcat(cmd, string[i]);
	}
	return cmd;
}
