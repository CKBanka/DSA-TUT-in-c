t=int(input())
while(t>0):
    t=t-1;
    n,m=[int(i) for i in input().split()]
    l=[int(i) for i in input().split()]
    k = int(input())

    l1 =[int(i) for i in input().split()]

    a1 = []
    a2 = []

    x = 0
    y = 0
    for i in l:
        if(i == 1):
            x += 1
        else:
            if(i%m == 0):
                x += i/m
            else:
                a1.append(-1)
                if(x == 0):
                    continue
                a1.append(x)
                x = 0
    for i in l1:
        if(i == 1):
            y += 1
        else:
            if(i%m == 0):
                y += i/m
            else:
                a2.append(-1)
                if(y == 0):
                    continue
            
                a2.append(y)
                y = 0
        
    # ma=max(l)
    if(a1 == a2):
        print('yes')
    else:
        print("no")
    # print(len(l));
