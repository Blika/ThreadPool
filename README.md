# ThreadPool

A simple realization of thread pool in C++.

# Usage

You don't need to build this project to use it in your code. Instead just grab related files and use them directly.

Thread pool creates all threads automatically upon initialization.<br />
To assign a new task to some thread, you need to provide the function you need to be done on a separate thread and its weight.<br />
`threadPool.assignNewTask(someFunc, 5)`<br />
Weight should define how much resources this function will probably use. Complex tasks should be given a higher value of weight.<br />
Pool picks the least busy thread (based on weight of its jobs) for your task, so weight is crucial.<br />
If you want to pass function with infinite loop you should set negative weight, thus thread pool wouldn't assign any more jobs to this thread.
