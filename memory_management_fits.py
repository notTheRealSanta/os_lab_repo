import numpy as np
import random

memory_array = np.random.randint(2, size=100)

def print_memory () :
    print("\n")
    for i in range(memory_array.size) :
        if memory_array[i] == -1 :  print ('x', end=' ')
        else : print (memory_array[i],end=' ')

        if (i+1) % 10 == 0 : print (" ")
    print("\n")

for i in range(memory_array.size) :
    
    if memory_array[i] == 0 :  memory_array[i] = -1
    else : memory_array[i] = random.randint(0,1)  

print_memory()