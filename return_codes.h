/*!
    \file
    A file with a description of the returned codes
*/

#ifndef RETURN_CODES_H
#define RETURN_CODES_H

/// Information about return codes
enum returnCodes {
    SUCCESS        =  0,   //< Programm was successfully completed
    USER_OUT       =  1,   //< Programm was forcibly terminated by user
    UNKNOWN_FLAG   = -1,   //< Unknown flag was received
    INPUT_ERROR    = -2,   //< Input error (INF or NAN entered)
    PROGRAMM_ERROR = -3,   //< Program execution error
    FILE_ERROR     = -4,   //< Error reading a text file
    NULL_          = -5,   //< Received NULL
    MEMORY_ERROR   = -6,   //< 
};

#endif // RETURN_CODES_H
