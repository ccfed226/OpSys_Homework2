# OpSYS
## Author: Jonathan Gillispie

Banker's Algorithm Example
========================
A generic example of Banker's Algorithm for deadlocks. While this code won't prevent deadlocks in a system, it does demonstrate how to detect deadlocks by looking for at least one safe sequence. This sequence has no circular waits, meaning that each process isn't waiting on another process in a chain such that the last process in the chain is waiting on the first process. While deadlocks don't happen often, when they do happen processes may need to be restarted. 

Starting the terminal
----------------------
A version of unix/linux will need installed. Otherwise, you can run this using a unix/linux emulator, or online through **www.github.com**. Regardless, you should see a **Terminal** tab somewhere, under it you'll see something like this:

```
$
```

This is where you type your commands. When you see the ``$`` in the following examples, *don't* type it. It's just there to show you where the commands are being entered. Press enter after typing a command to execute it. 

**Unix/linux doesn't use mousepads in the command line.** Unless you're switching between windows or applications, you likely won't need a mouse the whole time. 

Running and compiling the program
--------------------------
Type or copy the commands below to compile and then run the code. Again, don't type ``$`` into the command line, it's just there to show that the command goes into the command line. "qewpfjkdaa" is just an example of a random string that you can name your shared memory. 
```
$ g++ banker.cpp -pthread -lrt -o banker
$ ./banker
```

Example output
----------------------
Below are some examples of the code running. Five processes exist here, named processes 0-4. We can start anywhere in the safe sequence, as it's just circular and doesn't matter. If we wanted to we could start at process 4, as long as the next one is process 0. Going backwards may not be possible, however. 
```
[jgillis8@wasp ~]$ cd OpSYS/Proj_2/
[jgillis8@wasp Proj_2]$ dir
banker.cpp  input.txt
[jgillis8@wasp Proj_2]$ g++ banker.cpp
[jgillis8@wasp Proj_2]$ ./a.out
System is in safe state.
Safe sequence is: 1 3 4 0 2 [jgillis8@wasp Proj_2]$ ./a.out
System is in safe state.
Safe sequence is: 1 3 4 0 2 [jgillis8@wasp Proj_2]$ ./a.out
System is in safe state.
Safe sequence is: 1 3 4 0 2 [jgillis8@wasp Proj_2]$ 
```
