
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <syslog.h>

#include <fcntl.h>
#include <unistd.h>

#define ARGUMENTS 3
#define MODE 0644

int main(int argc, char *argv[])
{

	// Open the logger
    openlog("AESD Assignment 2", LOG_PID, LOG_USER);

	// Check if arguments are insufficient
    if(argc < ARGUMENTS)
    {
        // Log the error message
        syslog(LOG_ERR, "ERROR: Insufficient arguments");
        exit(1);
        
    }
    // Check if there are too many arguments
    else if(argc > ARGUMENTS)
    {
        // Log the error message
        syslog(LOG_ERR, "ERROR: Too many arguments");
        exit(1);
    }

    int fd;
    char *path = argv[1];
    char *data = argv[2];
    
    fd = creat(path, MODE);

	// Check if the file creation was successful
    if(fd == -1)
    {
    	// Log the error message
    	syslog(LOG_ERR, "ERROR: File not created");       
    }

    int string_length = strlen(data);

    int bytes_written = 0;
    
    // Write the given string to the file
    bytes_written = write(fd, data, string_length);

	// Check if the write operation was successful
    if(bytes_written == -1)
    {
    	// Log the error message
    	syslog(LOG_ERR, "ERROR: Writing unsuccessful");
    	exit(1);
    }
    
    // Check if the string was written completely
    if(bytes_written != string_length)
    {
    	// error message
    	syslog(LOG_ERR, "ERROR: String partially written");
    	exit(1); 
    }
    
    // Log the debug message
    syslog(LOG_DEBUG, "Writing %s to %s", data, path);
	
	// Close the file
	if(close(fd) == -1)
	{
		// Log the error message
    	syslog(LOG_ERR, "ERROR: Error in closing file %s", path);
    	exit(1);
	}
	
	// Close the logger
	closelog();
	
    return 0;
}
