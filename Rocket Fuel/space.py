

n=int(raw_input())
data=[]
score=[0]*(2*n+1)
startSorted={}
ans=[]

def scoreStart(i):
	while i<=(2*n):
		score[i]+=1
		i+= i & -i
		
def scoreEnd(i):
	result=0
	while i:
		result +=score[i]
		i -= i & -i
	return result

for i in range(n):
	intdata=map(int,raw_input().split())
	if intdata[2]<=intdata[1]:
		ans.append((intdata[0],"False"))
	else:
		data.append((intdata[0],intdata[1],"Start"))
		data.append((intdata[0],intdata[2],"End"))


sortdata=sorted(data,key=lambda x:x[1]) 
i=1
for data in sortdata:
	if data[2]=="Start":
		startSorted[data[0]]=i
		
	elif data[2]=="End":
		ans.append((data[0],scoreEnd(i)-scoreEnd(startSorted[data[0]])))
		scoreStart(startSorted[data[0]])
		
	i+=1

sortans=sorted(ans,key=lambda x:x[1],reverse=True)
a=reversed(sortans)
for i in a:
	print " ".join(map(str,i))
