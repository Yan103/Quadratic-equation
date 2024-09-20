/*!
    \file
    A file with a description of the returned codes
*/

#ifndef RETURN_CODES_H
#define RETURN_CODES_H

/// Information about return codes
enum return_codes {
    MEMORY_ERROR   = -6,   ///< Not enough memory
    NULL_          = -5,   ///< Received NULL
    FILE_ERROR     = -4,   ///< Error reading a text file
    PROGRAMM_ERROR = -3,   ///< Program execution error
    INPUT_ERROR    = -2,   ///< Input error (INF or NAN entered)
    UNKNOWN_FLAG   = -1,   ///< Unknown flag was received
    SUCCESS        =  0,   ///< Programm was successfully completed
    USER_OUT       =  1,   ///< Programm was forcibly terminated by user
};

#endif // RETURN_CODES_H
