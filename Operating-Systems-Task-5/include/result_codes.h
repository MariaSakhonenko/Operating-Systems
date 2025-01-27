#pragma once

enum ResultCode
{
    OK,
    BadAlloc,
    UnrecognizedInitializationError,
    UnrecognizedOption,
    UnreachableCodeReached,
    EmployeeNotFound,
    ProtocolViolation,
    EmployeeIdTaken,
    PipeReadInvalidSize,
    PipeWriteInvalidSize,
    PipeReadError,
    PipeWriteError,
    PipeDisconnectError,
    ErrorHandled,
    ErrorCannotBeHandled
};