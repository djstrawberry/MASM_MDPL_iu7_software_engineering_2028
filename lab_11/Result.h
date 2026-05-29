#ifndef RESULT_H
#define RESULT_H

enum class Result {
    Success,
    FileNotFound,
    InvalidFormat,
    ReadError,
    WriteError,
    UnknownError
};

#endif // RESULT_H