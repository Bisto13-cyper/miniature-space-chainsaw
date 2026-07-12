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
def Show(player:set):
    for X in player:
        print(X)
def Show2(player1:set,player2:set,name1:str,name2:str):
    player=player1&player2
    player1-=player
    player2-=player
    for Z in player:
        print(f"{Z}   ({name1})({name2})")
    for X in player1:
        print(f"{X}   ({name1})")
    for Y in player2:
        print(f"{Y}   ({name2})")
def Show3(F:set,B:set,S:set):
    A=F&B&S
    F-=A
    B-=A
    S-=A
    for X in A:
        print(f"{X}  (Football)(Basketball)(Swimming)")
    FB=F&B
    for X in FB:
        print(f"{X}  (Football)(Basketball)")
    FS=F&S
    for X in FS:
        print(f"{X}  (Football)(Swimming)")
    SB=S&B
    for X in SB:
        print(f"{X}  (Basketball)(Swimming)")
    F-=FB
    F-=FS
    for X in F:
        print(f"{X}  (Football)")
    B-=FB
    B-=SB
    for X in B:
        print(f"{X}  (Basketball)")
    S-=FS
    S-=SB
    for X in S:
        print(f"{X}  (Swimming)")
def Showshare2(player1:set,player2:set):
    player=player1&player2
    for X in player:
        print(X)
def Showshare3(F:set,B:set,S:set):
    A=F&B&S
    for X in A:
        print(X)
def admin(pas,users:dict,football:set,basket:set,swim:set,Want:dict,complains:list,favorites:list,masseges:dict):
    allowed=True
    while allowed:
        if pas=="":
            print("Hello admin sign in ")
            pas=input("Enter new password ")
            continue
        print("Enter password ")
        chpas=input("")
        if pas==chpas :
            while allowed:
                On=""
                if not len(Want)==0: On="●" 
                print("Hello admin ")
                S=input(f"What do want  \n1-see accounts\n2-see players \n3-look at believes {On}\n4-Ban \n5-read complains \n6-send massege to someone \n0-Exit  ")
                if S=="0":
                    return pas
                    allowed=False
                if S=="3" and len(Want)==0:
                    print("There is no believes right now")
                    continue
                match S :
                    case "1":
                        print("F=football\tB=Basketball\tS=Swimming")
                        for X in users.keys():
                            F=B=S=""
                            if X in football:F="F"
                            if X in basket:B="B"
                            if X in swim:S="S"
                            print(f"Name: {X}  \t\t\tSub in: {F}\t\t\t{B}\t\t\t{S}")
                    case "2":
                        print("Football  (1)\nBasketball  (2)\nSwimming   (3)\nShared in two sport   (4)\nShared in all sports  (5)\nSubscriber in two sport   (6)\nAll players(7)")
                        Se=input("")
                        match Se:
                            case "1":
                                print("Football Players: ")
                                Show(football.copy())
                            case "2":
                                print("Basketball Players: ")
                                Show(basket.copy())
                            case "3":
                                print("Swimming Players: ")
                                Show(swim.copy())
                            case "6":
                                print('Football "1"  Basketball "2"  Swimming"3"  ')
                                while True:
                                    S1=input("Select first  <").strip()
                                    if  not (S1=="1" or S1=="2" or S1=="3"):
                                        print("Wrong input")
                                        continue
                                    match S1:
                                        case "1":
                                            S1=football.copy()
                                            n1="Football"
                                        case "2":
                                            S1=basket.copy()
                                            n1="Basketball"
                                        case "3":
                                            S1=swim.copy()
                                            n1="Swimming"
                                    break
                                while True:
                                    S2=input("Select second  <").strip()
                                    if  not (S2=="1" or S2=="2" or S2=="3") or S1==S2:
                                        print("Wrong input")
                                        continue
                                    match S2:
                                        case "1":
                                            S2=football.copy()
                                            n2="Football"
                                        case "2":
                                            S2=basket.copy()
                                            n2="Basketball"
                                        case "3":
                                            S2=swim.copy()
                                            n2="Swimming"
                                    break
                                Show2(S1,S2,n1,n2)
                            case "5":
                                print("Accounts how subscribe in all sports:  ")
                                Showshare3(football,basket,swim)
                            case "4":
                                print('Football "1"  Basketball "2"  Swimming"3"  ')
                                while True:
                                    S1=input("Select first  <").strip()
                                    if  not (S1=="1" or S1=="2" or S1=="3"):
                                        print("Wrong input")
                                        continue
                                    match S1:
                                        case "1":S1=football.copy()
                                        case "2":S1=basket.copy()
                                        case "3":S1=swim.copy()
                                    break
                                while True:
                                    S2=input("Select second  <").strip()
                                    if  not (S2=="1" or S2=="2" or S2=="3") or S1==S2:
                                        print("Wrong input")
                                        continue
                                    match S2:
                                        case "1":S2=football.copy()
                                        case "2":S2=basket.copy()
                                        case "3":S2=swim.copy()
                                    break
                                Showshare2(S1,S2)
                            case "7":
                                Show3(football.copy(),basket.copy(),swim.copy())
                    case "3":
                        time=dict()
                        counter=1
                        for name in Want.keys():
                            print(f"{name} Want to enter to {Want[name][-12:-1]}")
                            print(f"Massge is [{Want [name]}]")
                            acces=input("Do you want accept them? (Y/N)  <").strip().lower()
                            if acces=="y":
                                print("accepted Done !")
                                time[str(counter)+"-"+name+"(Suc)"]=Want[name]
                                counter+=1
                            else:
                                print("Deind Done !")
                                time[str(counter)+"-"+name+"(Fal)"]=Want[name]
                                counter+=1
                        while True:
                            for last in time:
                                print(f"{last}")
                            sure=input("Are you sure?(y/n)").strip().lower()
                            if sure=="y":
                                print("Great !!")
                                x,y,checkcount=2,12,1
                                sendmassege=lambda name:masseges[name].append("You've accepted !")
                                for name in time.keys():
                                    #try here
                                    if checkcount%10==0:
                                        x+=1
                                        y+=1
                                    if name[-4:-1].strip()=="Fal":pass
                                    elif time[name][-y:].strip().lower().strip("'")=="football":
                                        football.add(name[x:len(name)-5])
                                        sendmassege(name[x:len(name)-5])
                                    elif time[name][-y:].strip().lower().strip("'")=="basketball":
                                        basket.add(name[x:len(name)-5])
                                        sendmassege(name[x:len(name)-5])
                                    elif time[name][-y:].strip().lower().strip("'")=="swimming":
                                        swim.add(name[x:len(name)-5])
                                        sendmassege (name[x:len(name)-5])
                                    else :print(f"{name} Have an error")
                                    Want.pop(name[2:len(name)-5])
                                break
                            elif sure=="n":
                                while True:
                                    print("1-See massege again   2-retry someone 0-exit")
                                    notsure=input("")
                                    if notsure=="1":
                                        for last in time:
                                            print(f"{last}")
                                        M=input("Select who.(Them name) ").strip()
                                        if M in Want:
                                            print(f"Them massege is:{Want[M]}")
                                            continue
                                        else:
                                            print("Wrong name")
                                            continue
                                    elif notsure=="2":
                                        for last in time:
                                            print(f"{last}")
                                        N=input("Select who.(Them number) ").strip()
                                        try :
                                            N=int(N)
                                        except:
                                            print("Plaese enter number")
                                            continue
                                        if N>len(time) or N<=0:
                                            print("Enter right number")
                                            continue
                                        time=list(time.items())
                                        print("He succeeded" if time[N-1][0][-4:-1]=="Fal" else "He banned")
                                        if time[N-1][0][-4:]=="Fal":time[N-1][0]=time[N-1][0].replace("Fal","Suc")
                                        elif time[N-1][0][-4:]=="Suc":time[N-1][0]=time[N-1][0].replace("Suc","Fal")                                    
                                        time=dict(time)
                                        continue
                                    elif notsure=="0":break
                                
                            else:print("Wrong Input")
                    case "4":
                        i=1
                        for Use in users:
                            print(f"{i}:{Use}")
                            i+=1
                        user=input("Who will you ban it  " ).strip()
                        if user in users.keys():
                            print(f"Are you sure that you will ban ({user}) (y/n)")
                            sure=input("").lower()
                            if sure =="y":users.pop(user)
                            else:print("Canceled!")
                    case "5":
                        
                        comp=0
                        while comp<len(complains):
                            print(complains[comp])
                            done=input("Delete(0) or save(1) or favorite(2) ").strip()
                            if done=="0":
                                complains.pop(comp)
                                print("Deleted")
                            elif done=="1":
                                comp+=1
                                print("Saved")
                            elif done=="2":
                                favorites.append(complains[comp])
                                complains.pop(comp)
                                print("Added")
                            else:continue
                            com=input("Read next (anything) or Exit(0)--")
                            if com=="0":break
                    case "6":
                        for user in users.keys():
                            print(users)
                        print("Who is?")
                        send=input("").strip()
                        if send in users:
                            mas=input("Enter massege     ")
                            masseges[send].append(mas)
                        else:print("Wrong name")
                    
                        
        else : 
            print("wrong pasword")
            continue
def menu(users:dict,foot:set,basket:set,swim:set,want:dict,complains:list,masseges:dict):
    allowed=False
    user=""
    while True:
        print("Enter username ")
        user=input().strip()
        if user in users.keys():
            print("Enter your Password ")
            che=input("")
            if che==users[user] :
                allowed=True 
                break 
            else:
                print("Wrong password please try again ")
                continue
        else:
            print("Username isn't found !")
            continue
    while allowed :
        F=B=S="Subscribed"
        theremasseges,there=False,""
        if len(masseges[user])>0:theremasseges,there=True,"●"
        else:theremasseges,there=False,""
        if not user in foot:F="(1)"
        if not user in basket:B="(2)"
        if not user in swim:S="(3)"
        print(f"Hello {user} To Bisto sportsclub ")
        c=input(f"Select What do you need \n1-subscripe new hoppy \n2-make a complaint \n3-see Massage {there} \n0-Exit ").strip()
        if c=="0":break
        if user in want.keys()and c=="1":
            print("You've already sent your Blieve  wait until response ")
            continue
        if not theremasseges and c=="3":
            print("You don't have massegs")
            continue
        match c:
            case "1":
                
                print(f"Football{F}\nBasketball{B}\nSwimming{S}")
                S=input("Select          ").strip()
                if not user in foot and S=="1":
                    print("Enter Massage why and what's your skills and if you're accepted we will send to You(Warn!) (if you already have setn massage it will be deleted))")
                    ms=input("")
                    want[user]=ms+"'Football'  "
                    print("Thanks ><")
                if not user in basket and S=="2":
                    print("Enter Massage why and what's your skills and if you're accepted we will send to You (Warn!) (if you already have setn massage it will be deleted))")
                    ms=input("")
                    want[user]=ms+"'Basketball'"
                    print("Thanks ><")
                if not user in swim and S=="3":
                    print("Enter Massage why and what's your skills and if you're accepted we will send to You (Warn!) (if you already have setn massage it will be deleted))")
                    ms=input("")
                    want[user]=ms+"'Swimming'  "
                    print("Thanks ><")
            case "2":
                print("Make your complaint Write What,Why,How and rating")
                What=input("What's Wrong.    ").strip()
                Why=input("Why this not good.    ").strip()
                How=input("How can we help you.    ").strip()
                rate=input("please rate our totaly service.    ").strip()
                complains.append(f"What has done :{What} \n Why this is disappointing :{Why} \n How can you make abest service :{How} \n Rating :{rate}")
            case "3":
                #complete and test
                for mas in masseges[user]:
                    while True:
                        print(mas)
                        print("Do want del(d)/save it(s)")
                        wanted=input("").lower()
                        if wanted=="d" or wanted=="del":
                            masseges[user].remove(mas)
                            break
                        elif wanted=="s" or wanted=="save":break
                        else:continue
def capmenu(captains:dict):
    print
def signin(Pas:dict,captains: dict,masseges:dict):
    print("Hello to new account Are you (a captain(1) or a trainer(2))")
    U=input("")
    if U=="1":
        while True:
            print("Hello Captain put your name and adress and age and Gender")
            N=input("Name:  ").strip()
            A=input("Age:  ").strip()
            Ad=input("Adresse:  ").strip()
            G=input("Gender:  ").strip()
            if(G=="" or A=="" or N=="" or Ad=="" or not A.isdigit  ):
                print("There is wrong in data please repeat")
                continue
            captains[N]=[int(A),Ad,G,False]
            print("When we accept you we'll send to you")
            break
    if U=="2":
        while True:
            name=input("Enter username     ").strip()
            if name in Pas.keys():
                print("ueername is used enter another username")
                continue
            print("Enter new password ")
            pas=input()
            if pas=="":
                print("weak password try again")
                continue
            users[name]=pas
            masseges[name]=["Wellcome to our club"]
            print("Sign in successfully ")
            break

# everything for captain
swimmers={"Ahmed","Akrm","Ali","Noor","Er"}
Basketball_players={"Ahmed","Saed","Moha","Noor","Er"}
Football_players={"Akrm","Ahmed","Moha","SoSo","Er"}
users=dict()
captains={
    "Name":["Age","Adresse","Gender","Working or No"]
}
believes=dict()
masseges=dict()
complains=list()
favoriteadmin=list()
admpws=""
while True:
    print("Hello To Bisto sportsclub Are you \n1-admin\n2-sign in \n3-login as a trainer \n4-login as a captain\n5-exit")
    ch=input("").strip()
    if ch=="1":admpws=admin(admpws,users,Football_players,Basketball_players,swimmers,believes,complains,favoriteadmin,masseges)
    elif ch=="2":signin(users,captains,masseges)
    elif ch=="3":menu(users,Football_players,Basketball_players,swimmers,believes,complains,masseges)
    elif ch=="4":capmenu(captains)
    elif ch=="5": break
    else :print("Wrong choise ")