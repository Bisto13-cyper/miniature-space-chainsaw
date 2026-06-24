# start to try using Data types in Python 
#Lists
"""
def empty(Do):
    for x in range(5):
        if not Do[x][0]=="":
            return False
    return True
def fouemp (Do) :
    if Do=="": return("Empty")
    else :return("Found")
def UI (Do):
    while True :

        print(f"Hello {Do[0]} In  To Do list")
        print("What do want \n1- Add task \n2- delete task \n3- Show tasks \n4- add task with his number\n5- show next task \n6- clear list \n0- exit")
        ch=input("Select  ").strip()
        
        if len(Do[2])==0 and ch!="1" and ch!="0" :
            print("please add task first ")
        elif ch=="1":
            task=input("Wtrite the task  ")
            Do[2].append(task)
        elif ch=="2"  :
            x=1
            for task in Do[2]:
                print(f"{x}- {task}")
                x=x+1
            delt=input("Select the task to delete  ")
            if not delt.isdigit() :
                print("Please add number ")
            elif delt.isdigit() :
                delt=int(delt)
                if delt<=len(Do[2]) and delt != 0:
                    Do[2].pop(delt-1)
                    print("Deleted ")
                else :
                    print("Add task number found ")
        elif ch=="3" :
            x=1
            for show in Do[2]:
                print(f"{x}- {show} ")
                x+=1
        elif ch=="4" :
            task=input("Add the task  ")
            while True:
                num=input("Add his number  ")
                if num.isdigit():
                    num=int(num)
                    if  num<=len(Do[2]) :
                        Do[2].insert(num-1,task)
                        break
                    else :
                        continue 
                    
                    
                else :
                    continue 
        elif ch=="5": 
            end=input(Do[2][0]+" end it(Y)")
            if end=="Y" or end=="y" :
                Do[2].pop(0)
        elif ch=="6" :
            ok=input("Are you sure to clear all tasks (y/n)  ")
            if ok=="Y" or ok=='y':
                Do[2].clear()
                print(" List have been cleared")
            elif ok=="n"or ok=="N" :
                print()
            else :
                print("Wrong input")
        elif ch=="0" :
            break
        else :
            print("Wrong Input")
        print()
# tupple



name1=name2=name3=name4=name5=""
pas1=pas2=pas3=pas4=pas5=Apas=""
Do=([name1,pas1,[]],[name2,pas2,[]],[name3,pas3,[]],[name4,pas4,[]],[name5,pas5,[]])
while True:
    print("Hello family to families To Do list")
    print("1-sign in with member\n2-Admin \n0-exit")
    se=input("").strip()
    if se=="1" and Do[0][0]=="":
        print("No members found ")
    elif se=="0":
        break
    elif se=="1": 
        for i in range(5):
            print(f"Member {i+1}: {Do[i][0]}")
        while True :
            indn=input("Select your account ")
            if indn.isdigit():
                indn=int(indn)
                indn-=1
            else:
                print("please enter number")
                continue
            if indn <0 or indn>5 or Do[indn][0]=="":
                print("Wrong choise")
                continue
            else :
                print("enter your password " )
                chp=input("")
            if chp==Do[indn][1] :
                print("Wellcome back ")
                UI(Do[indn])
                break
            else:
                print("Wrong pas !!")
                continue
    elif se=="2":
        if Apas=="":
            print("Hello Admin please add password ")
            Apas=input("")
        else:
            check=input("Add password ")
            if check==Apas :
                while True :
                    print("1-Add member \n2-show members \n3-delete member  \n4-Add member with (1/5) \n0-exit ")
                    ch=input("").strip()
                    if (ch=="2" or ch=="3") and empty(Do)==True:
                        print("Add members first ")
                        continue
                    elif ch=="1" :
                        ind=-1
                        for i in range(5) :
                            if Do[i][0]=="" :
                                ind=i
                                break
                        if ind==-1 :
                            print("Members full")
                        else:
                            print(f"Hello member {ind+1}")
                            while True :
                                Do[ind][0]=input("Enter your name ")
                                if Do[ind][0].isspace() or Do[ind][0]=="":
                                    continue
                                Do[ind][1]=input("Enter your password ")
                                print("Added complete".center(28))
                                break
                    elif ch=="2" :
                        for i in range(5):
                            print(f"Member {i+1} : {Do[i][0]}")
                    elif ch=="3": 
                        for i in range(5):
                            print(f"Member {i+1} : {Do[i][0]}")
                        print("\n which member do want to delete ?")
                        while True:
                            delt=input("").strip()
                            if delt.isdigit():
                                delt=int(delt)
                            else :
                                print("please enter number ")
                                continue
                            if delt>5 or delt<=0 or Do[delt-1][0]=="":
                                print("Enter right number")
                                continue
                            else :
                                Do[delt-1][0]=""
                                Do[delt-1][1]=""
                                Do[delt-1][2].clear()
                                print("Deleted")
                                break
                        
                        
                    elif ch=="4":
                        ind=-1
                        for i in range(5) :
                            if Do[i][0]=="" :
                                ind=i
                                break
                        if ind==-1 :
                            print("Members full")
                        else:
                            for x in range(5):
                                print(f"Member {x+1} : {fouemp(Do[x][0])}")
                            while True: 
                                ind=input("select your number(1/5)  ").strip()
                                if ind.isdigit():
                                    ind=int(ind)
                                else:
                                    print("Please write right number")
                                    continue
                                if ind>5 or ind<=0 or not Do[ind-1][0]=="":
                                    print("write right number")
                                    continue
                                break
                            while True :
                                Do[ind-1][0]=input("Enter your name ")
                                if Do[ind-1][0].isspace() or Do[ind-1][0]=="":
                                    continue
                                Do[ind-1][1]=input("Enter your password ")
                                print("Added complete".center(28))
                                break
                    elif ch=="0":
                        break
            else:
                print("Wrong password")
    else:
        print("Wrong Input ") """
#Set
def admin(pas,football,basket,swim):
    while True:
        if pas=="":
            print("Hello admin sign in ")
            pas=input("Enter new password ")
            continue
        print("Enter password ")
        chpas=input("")
        if pas==chpas :
            while True:
                print("Hello admin ")
        else :
            print("wrong pasword")
            continue
def menu():
    while True:
        print("Enter username ")
        user=input()
        
def signin(Pas:dict,user:list):
    print("Hello to new account")
    while True:
        name=input("Enter username     ").strip()
        if name in user:
            print("ueername is used enter another username")
            continue
        print("Enter new password ")
        pas=input()
        if pas=="":
            print("weak password try again")
            continue
        Passwords[name]=pas
        print("Sign in successfully ")
        break


users=[]
swimmers={}
Basketball_players={}
Fottball_players={}
Passwords={"name":"password"}
admpws=""
while True:
    print("Hello To Bisto sportsclub Are you \n1-admin\n2-sign in \n3-login \n4-exit")
    ch=input("").strip()
    if ch=="1":admin(admpws,Fottball_players,Basketball_players,swimmers)
    elif ch=="2":signin(Passwords,users)
    elif ch=="3":menu()
    elif ch=="4": break
    else :print("Wrong choise ")