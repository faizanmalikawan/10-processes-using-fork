x=input("Enter no of processes:")
index=0
sum=0
i=0
burst_time=[]
arrival_time=[]
print("Now add burst time and waiting time respectively")
for index in range (int(x)):
	i=input("Enter Burst time : ")
	burst_time.append(i)
burst_time.sort()
finishTime=[]
taTime=[]
waitTime=[]
for index in range (int(x)):
	arrival_time.append(0)
	taTime.append(0)
	finishTime.append(0)
	waitTime.append(0)
print("Process no\tBurst time\t Arrival time\tWaiting time\tTurnaround time")
for index in range (int(x)):
	waitTime[index]=int(burst_time[index-1])+int(waitTime[index-1])
	waitTime[0]=0
	sum=sum+int(burst_time[index])
	finishTime[index]=sum
	taTime[index]=finishTime[index]-int(arrival_time[index])
	print(index+1,'\t\t',burst_time[index],'\t\t',arrival_time[index],'\t\t',waitTime[index],'\t\t',taTime[index],'\n')
sum=0 
sum2=0
for index in range(int(x)):
	sum=sum+int(taTime[index])
	sum2=sum2+int(waitTime[index])
avg=sum/int(x)
avg2=sum2/int(x)
print("Average Turnaround Time",avg)
print("Average Waiting Time",avg2)
