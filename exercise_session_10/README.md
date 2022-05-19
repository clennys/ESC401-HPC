# Exercise Sheet 10 (Dennys Huber)

### Exercise 1
- The GPU needs to startup and the data needs to be transfered, which causes a delay thus the first iteration being the longest.
- The next iterations are pretty much identical, but perform a little bit better after each iteration

### Exercise 3
- Like in Exercise 1 the first iteration always takes the longest due to the data transfer and startup of the gpu.
- The computation get faster and faster if you use more blocks, but the optimal amount of threads needs to be found in order to get the most out of the gpu
- In our case it was usually 64 or 128 threads so the GPU can efficiantly switch between the threads without the gpu waiting for a thread or the thread waiting for available gpu slot
