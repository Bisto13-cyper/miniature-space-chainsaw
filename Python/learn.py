def ifdigit(number):
    try:
        int(number)
    except:
        return False
    return int(number)
    
    


#print("Hello", end="_")
#print("Hello", end="\t")
#print("Hello" )
#print("Hello" )

#print("Ahmed","Love","Phyton","Match")
#print("Ahmed","Love","Phyton","Match", sep="~~",end="~~")
#print("Ahmed","Loves","Phyton","Very Match")
#sep an end in print
"""
Want=list()

print("Prees","E","To","Stop","Add",sep="     ")
while True:
    item=input("What do want ").strip()
    if item.capitalize()=="E":
        break
    Want.append(item)
print("Your items is")
for i in Want:
    print(i,end="__")
"""

#if and else in print
"""
allow={"Egypt", "Ksa","Aswan","German", "Surui"}
while True:
    name=input("Enter your Name").strip().capitalize()
    age=int(input("Enter your age").strip())
    c=input("Enter your country").strip().capitalize()

    print("you are enderage" if age<18 else "you're in age" )
    print("you are allowed" if c in allow else "you're not allowed" )
"""

#unpacking with Iterator and (sep with unpacking) and(sep with unpacking with zip())
"""
print("##"*20)
tr=(1,2,2,2,4,5,6,7)
print(*tr)
tr=(1,2,2,2,4,5,6,7,"Ahned","Akrm","Asad")
print(*tr)
tr=("Ahedm ","Why")
print(*tr)
tr=(True,True,False)
print(*tr)
tr=(["Ahmed","Ali","Saad"],(1,2,3,4),567,True)
print(*tr[1],*tr[0],sep="\n")
How=["Name",50,10000,"Gender",True]
print(*How,sep="\n")
print("##"*25)
Man={"Ahmed","Ali","Osama","Mosaad","Pro"}
Woman={"Sars","Habiba","Hoor","Rehab","Kro"}
print("WHO will marry WHO")
print(*(f"{man}n,<-->{woman}" for man,woman in zip(Man,Woman)),  sep="\n")
print("##"*25)
det=[["Ahmed",7780,"Football","Engineer",True],["Osama",7980,"Football","Engineer",False],["Sara",7889,"Yoga","Makeup artest",True],["Hala",7000,"reading","Tetcher",False]]
print("Name","ID","Skill","Working","Is work", sep="\t")
for person in det:
    print(*person, sep="\t")

print("##"*20)
"""


#print(*mytuple,*mylist,*myset,*mydict, sep="\n"+"*"*50)
def Sum(*num):
    res=0
    for N in num:
        res+=N
    return res
"""
print(Sum(1,33,7,82,92,92,92))
print(Sum(0,92,92))
print(Sum(1,33,7,82,92,92,92,10,-128,-728,10000))
print(Sum())
"""
#def myskill (name,age,*skill):
"""
    print(f"Hello {name} who has {age} old")
    print("your skills:")
    for C,N in enumerate(skill,1) :
        print(f"{C}-{N}")
myskill("Ahmed",15,"Football", "Basketballer", "tennis")
myskill("Ali",20,"CPP","Java ","Software Engineer")
myskill("Ako",30,"Eat")
myskill("No",10000)"""

def getdigit(digit):
    try :
        digit=int (digit)
    except:
        return False
    return True
"""
nums=list()
while(True):
    print("add")
    num=input("")
    if(num=="0"): break
    if(getdigit(num)):nums.append(int(num))
print(Sum(*nums))
"""
#**dict
mytuple=("Ahmed",12,True)
mylist=["Ahmed",12,True,155,False]
myset={"Ahmed",12,100000,"C"}
mydict={
    "Ahmed":12,
    True:False,
    "love":"She"
    }

def skills (name,age,*certificates,**skill):
    print(f"Hello {name} who has {age} you've certificates")
    for N,C in enumerate(certificates,1):
        print(f"{N}- {C}")
    print("You've skills")
    for N,P in skill.items():
        print(f"Skill: {N}:{P} ")
        
programinC=["CSS","Software engineering","Hello world","Microsoft" ]
AcademicC=["Secondary School","University"]
skill={
    "Python ":"50%",
    "C++ ":"70%",
    "N8N ":"90%",
    "Swimming ":"100%"

}
skills("Bisto",21,*programinC,*AcademicC,**skill)