
# Round Robin Scheduling-Algorithm (batch file)


 # Compiler Used
 <h2>g++</h2> is a comipler used to run c++ batch files in Linux Terminal 
 <h2> Execution</h2>
   ./a.out is used to excute c++ batch file.
 
 # Explanation
 - Dynamically Allocated 1D array is used to take input (BT & AT) and ] for  CT , TAT , WT 
 -rem_burst[] is an array storing the burst time but value will be decremented accordting to Burst Time
 - Queue used
 
 
 - CALULCATED CT using formula :
        <br>- Push the process in Queue if it has remaining Time
        <br>- Pop the process from Queue if there a differnce between Arival Time of current process  and next process & when all the process are iterated ones then i started poping Queue elements one by one.
        <br>- Store the sum of Burst Time of all process in a variable and used loop 'while(time < sumOFBurstTime)'.

# Ouput of RR for Different Arrival Time
![diff RR](https://user-images.githubusercontent.com/91987110/209712838-e34931c2-83ee-406d-b7a9-8e54cca39ea2.jpg)

# Ouput of RR for Same Arrival Time
![RR_SAME_AT](https://user-images.githubusercontent.com/91987110/209600828-07072bd2-7cb8-4dca-8b4d-11b6d4f3b914.jpg)
