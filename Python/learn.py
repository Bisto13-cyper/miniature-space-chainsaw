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
"""
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
skills("Bisto",21,*programinC,*AcademicC,**skill)"""

def Who(name="unkowon",age=-1,work="In home",*skills,**subjects):
    print(f"Name:{name} \n Age:{age} work:{work} ")
    if skills:
        for count,skill in enumerate(skills):
            print(count,skill,sep="-")
    if subjects:
        for subject,per in subjects.items():
            print(subject,per,sep="-->")

sub={
    "Arbic":100,
    "English":70,
    "Math":50
}
#Who()
#Who("Ahmed","Player")
#Who("Elasyed","Sad",16)
#Who("Adm","Sad",20,"C++","Rust","frontend")
#Who("AM","Sad",20,*["C++","Rust","frontend"],**sub)

#short hand if
"""
love=True
print("I love you" if love else "I hate you")
love=False
print("I love you" if love else "I hate you")
ahmed=["Python ", "Css"]
print("you can join C++ team"if "C++" in ahmed else "You can't join C++ team")
ahmed=["Python ", "Css","C++","Football"]
print("you can join C++ team"if "C++" in ahmed else "You can't join C++ team")
result={
    "Ahmed ":90,
    "Sara ":98,
    "Sayed ":80,
    "Akram":40,
    "Sosa":100,
    "Nora":0
}
for name,deg in result.items():
    print(f"{name} Succed " if deg>50 else f"{name} failed")"""
"""
D=lambda X,Y:X*Y
print(D(12,23))
print("#",50)

students=["Ahmed Shaban","Akrm Shosan","Ashrf nemar","Asad messi"]

students=list(map(lambda student:student[:8],students))
print(*students,sep="\n")

result={
    "Ahmed ":90,
    "Sara ":98,
    "Sayed ":80,
    "Akram":40,
    "Sosa":100,
    "Nora":0,
    "Selam":30
}
print("##"*40)
suc=dict(filter(lambda student:student[1]>50,result.items()))
print(*suc,sep="\n")
print("##"*40)
"""
from rich import print
names=[
"Oliver", "Emma", "Liam", "Amelia", "James", 
"Sophia", "Benjamin", "Lucas", "Mia", "Henry", 
"Charlotte", "Alexander", "Ava", "William", "Evelyn"
]
print("##"*40)

def namelike (name:str):
    return name.strip().capitalize()
    


prices=[1000,20000,300000,4000000,20000,3444,10000,3030,10990,10,1000]
low=list(filter(lambda x:x<1000,prices))
print(low)
Cars=[
    {
        "Name":"BMW M5",
        "Price":10000000,
        "Model":"BMW",
        "Warranty":6
    },
    {
        "Name":"BMW M6",
        "Price":15000000,
        "Model":"BMW",
        "Warranty":7
    },
    {
        "Name":"Toyota Comfort",
        "Price":13000000,
        "Model":"Toyota",
        "Warranty":5
    },
    {
        "Name": "Mercedes C200",
        "Price": 9500000,
        "Model": "Mercedes",
        "Warranty": 5
    },
    {
        "Name": "Mercedes E300",
        "Price": 16000000,
        "Model": "Mercedes",
        "Warranty": 5
    },
    {
        "Name": "Audi A4",
        "Price": 8500000,
        "Model": "Audi",
        "Warranty": 3
    },
    {
        "Name": "Audi RS6",
        "Price": 22000000,
        "Model": "Audi",
        "Warranty": 4
    },
    {
        "Name": "Porsche 911 GT3",
        "Price": 35000000,
        "Model": "Porsche",
        "Warranty": 4
    },
    {
        "Name": "Toyota Corolla",
        "Price": 4500000,
        "Model": "Toyota",
        "Warranty": 3
    },
    {
        "Name": "Hyundai Elantra CN7",
        "Price": 3800000,
        "Model": "Hyundai",
        "Warranty": 5
    },
    {
        "Name": "BMW X5",
        "Price": 18500000,
        "Model": "BMW",
        "Warranty": 5
    }
]

def raise_price(car):
    car["Price"] =round( car["Price"] * 1.10)
    return car

def carlist(price,*Cars):
    result=list()
    for Car in Cars:
        if(Car["Price"]<=price) :result.append(Car)
    return result 

print(carlist(14000000,*Cars))


print(list(filter(lambda C:C["Price"]<14000000,Cars)))
print(list(map(raise_price,Cars)))
#complete