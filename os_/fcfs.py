f = open("fcfs.inp","r")
fw = open("fcfs.out","w")
data = list()

while(True):
    rl = f.readline()
    if not rl:
        break
    rl.strip();
    if(len(rl)==0):
        continue;

    data.append(list(map(int,rl.split())))

idle_time=0
n = data[0][0]
del(data[0])
datadict=dict()
queue = [] # 대기 큐 program number가 들어감
inputtime=dict()
ttime = dict()
current_p = 0
current_cputime=0
current_cpuiotime=0

for i in range(n):
    ttime[i]=0;
    
for i in range(n):
    inputtime[i]=data[i][0]
    del(data[i][0])
    datadict[i]=data[i]

while(True):
    
    if(len(inputtime)==0):
        break
    
    sorted_dict = sorted(inputtime.items(),key = lambda item: item[1])
    
    for i in range(len(sorted_dict)):
        if(sorted_dict[i][1]==0):
            queue.append(sorted_dict[i][0])
            break
        elif(sorted_dict[i][1]<=current_cputime):
            queue.append(sorted_dict[i][0])

    if sorted_dict[0][1]>current_cputime:
        
        idle_time+=(sorted_dict[0][1]-current_cputime)
        current_cputime=sorted_dict[0][1] 
        # print(idle_time)
    if(idle_time==29):
        
        pass
    if(len(queue)>0):
        for i in range(len(queue)):
            current_p = queue.pop(0)
            cpu = datadict[current_p].pop(0)
            

            if (cpu!=-1):
                io = datadict[current_p].pop(0)
                
            # if len(datadict[current_p])==1:
            #        io = datadict[current_p].pop(0)
                    
            else:
                del(inputtime[current_p])
                continue
            if(io ==-1):
                inputtime[current_p]+= cpu
                current_cputime += cpu          
                current_cpuiotime =current_cputime
                ttime[current_p]=current_cpuiotime
                del(inputtime[current_p])

            else:
                inputtime[current_p]+= cpu
                current_cputime += cpu
                inputtime[current_p]=current_cputime+io            
                current_cpuiotime=inputtime[current_p]
                ttime[current_p]=current_cpuiotime

    # print(inputtime)
result = str(idle_time-1)+"\n"+"\n".join(list(map(str,ttime.values())))

fw.write(result)
fw.close()
f.close()