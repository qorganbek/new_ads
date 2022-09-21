b = [];
n = [];

s = input()
for i in s.split():
    if (int(i) == 0):
        b.append(10)        
    else: b.append(int(i))
a = input()
for i in a.split():
    if (int(i) == 0):
        b.append(10)        
    else: b.append(int(i))
cnt = 0
while True:
    if (len(b) == 0 or len(n) == 0 or cnt > 1000000):
        break
    elif ((b[0] > n[0])):
        b.append(b[0])
        b.append(n[0])
        b.remove(b[0])
        n.remove(n[0])
        cnt += 1
    else:
        n.append(b[0])
        n.append(n[0])
        b.remove(b[0])
        n.remove(n[0])
        cnt += 1
            
if (len(b) == 0):
    print('Nursik '+ str(cnt))
elif (len(n) == 0):
    print('Boris ' + str(cnt))
else: print('blin nichya')                