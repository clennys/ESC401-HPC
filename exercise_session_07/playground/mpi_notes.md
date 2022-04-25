# Message Passing Interface (MPI) Notes

## Doc

- [MPI documentation](https://www.open-mpi.org/doc/v4.1/)

## Message-passing paradigm

- All variables are _private_ and reside in the _local memory_ of each process.
- Each process can execute a different part of the program.
- Variables can be exchanged between processes via a call to the message passing routine.

## Message Passing concepts

- __Environment__:
	- Manages and interprets messages (postal company, email system)
	- Messages sent to specific address.
	- Receiving processes must be able to classify and interpret incoming messages.
	- Group of autonomous processes deployed on different nodes

- __Message attributes__:
	- source process (sender address) -> target process (recipient address)
	- Header: senderId, Datatype, data length, receiverId
	- Message

## MPI Environment
```c
//Header
#include "mpi.h"

// Launch MPI environment
int MPI_Init(int *argc_char ***argv)

//Terminate MPI environment
int MPI_Finalize(void);
```
