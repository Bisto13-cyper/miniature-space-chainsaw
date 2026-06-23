name="Ahmed loves Python"
test="AVC 1 ACV 2 ACV \t hhh \t 5"
#slicing
"""print(name[-1])
print(name[0:12])
print(name[12:])
print(name[0:12])
print(name[::3])
print(name[::-1])"""
# string Methodes
"""print(len(name))
print(name.split(" ", 1))
print(name.center (30, "_"))
print(name.count("h"))
print(name.count("h",0,10))
print(name.swapcase())
print(name.startswith("A"))
print(name.startswith("a"))
print(name.startswith("A",2,12))
print(name.endswith("n"))
print(name.endswith("n",0,10))
print(test.strip("ACV"))
print(test.rstrip("ACV"))
print(test.lstrip("ACV"))
print(name.zfill(30))
print(name.index("A"))
print(name.find("P"))
print(name.find("P",0,10))
print(name.rjust(30,"_"))
print(name.ljust(30,"_"))
print(test.expandtabs(10))
print(name.isalpha())
print(name.isdigit())
print(name.isalnum())
print(name.isspace())
print(name.isupper())
print(name.islower())
print(name.istitle())
print(name.replace("Python","C++")) 
list = ["Ahmed", "loves", "himself"]
print (" ".join(list))
print("enter your name and age and country and job")
name = input("name :")
age = input("age :")
country = input("country :")
job = input("job :")
if job[0]=="a" or job[0]=="A" or job[0]=="e" or job[0]=="E" or job[0]=="i" or job[0]=="I" or job[0]=="o" or job[0]=="O" or job[0]=="u" or job[0]=="U":
    art="an"
else : 
    art="a"
print(f"my name is {name} and I am {age} years old and I live in {country} and I work as {art} {job}")
//////////
saved =[] 
while True :
    print("Hello to 'Editor' to edit your text")
    text=input("Enter you text :")
    choise=input("Select 1- make your text big \n 2-make your text small \n 3-Capital  sentence after (....) \n 4-capital all text \n5-sorting your text sentences from a-->z 6- from Z-->a \n7-count your sentences number \n8-split your text to paragraph \n9-saved it \n0- exit  ") 
    if choise== "1" :
        print(text.upper())
        while True:
            ch=input("Do you wanna save it (y/n)  ")
            if ch== "y" or ch== "Y" :
                print("Saved !")
                saved.append(text.upper())
                break
            elif ch=='n' or ch== "N":
                break
            else :
                print("wrong choise try again") 
                continue 
    elif choise == "2" :
        print(text.lower())
        while True :
            ch =input("Do you wanna save it ?(y/n)")
            if ch== "y" or ch=="Y" :
                saved.append(text.lower())
                break
            elif ch=='n' or ch=="N":
                break
            else :
                print("wrong choise try again") 
                continue 
    elif choise== "3" :
        pa=input("What article do wanna Captial if you used it")
        parts=text.split(pa)
        text.capitalize()
        update=[item.capitalize() for item in parts[1:]]
        text=pa.join(update)
        print(text)"""
test="AhmeK Alo00PLM weWeWEMk assd 12 gH"
#print(test.swapcase())
#print(test1.split('\n'))
#print(test1.rsplit('.',2))
#print(test1.splitlines())
#print(test1)
testl=["Ahmed","779",test]
fe="Rjust Is Ver Impossible 66 5Kklp"
xe="44"
#print(fe.center(20,'%'))
33#print(fe.center(10))
#print(fe.count("j",10,-1))
#print(fe.count("j",0,-1))
#$#pr#int(fe.count("j",0,10))
#print(fe.strip("j"))

"""print(xe.zfill(24))
print(fe.index("j"))
print(fe.find("j"))
print(fe.find("gwhj"))
print(fe.rjust(32,'_'))
print(fe.ljust(32,'_'))
print(fe.replace("very","ver6y"))
print(fe.istitle())
print(fe.title())
name="Ahmed"
Age=15
Qge=155
Fal=True
yes="Starte"
print("Hello Mr{0:.4s} Who is {2} old and can kill {5:.2f} person Are you {6}".format(name,Age,Qge,Fal,yes,9,"Ahhh"))

tesat=["Ahmed","Python", 'C++',100,60,10.34,True]
tesat1=["yes","No","Two","jajsjs"]
#print(tesat)
tesat.append(False)
#print(tesat)
#tesat.append(tesat1)
#print(tesat)
#tesat.extend(tesat1)
#print(tesat)
tesat.insert(3,"Java")
copy=tesat.copy()
tesat.insert(5,"jsjshjajhadd")
print(tesat)
print(copy)
How=input("Add thing to search ")
print(tesat.count(How))
if tesat.count(How) != 0 :
    print(tesat.index(How))
else :
    print("Not fou d ")
sg=[1100,82,0.7,18818,100,0]
sg.sort()
print(sg)
sg.sort(reverse=True)
print(sg)
sm=["Wo","Ahhed","Agkso","Klop","Bal","Baa","Flap"]
sm.sort()
print(sm)
sm.sort(reverse=True)
print(sm)
#data types
string1="Ahmed"
list1=["Ahmed",2,True,1.9]
Tuple1=("Ahme",7,8.99,False)
Tuple2="Ahmed",True
Tuple3=5,
Set1={"Ahmed",8}
dictionary={
    "key":"value",
    15   : 1.9
}

print(type(string1))
print(type(list1))
print(type(Tuple1))
print(type(Tuple3))
print(type(Set1))
print(type(dictionary))"""
"""
Sets functions
print(A|B) union 
print(A&B) تقاطع
print(A-B) difference 
print(B-A)
print(A^B) عكسالتقاطع
A|=B
True or False
 issubset(): هل المجموعة الأولى "جزء" من المجموعة الثانية؟ (كل عناصري عندك؟).

.issuperset(): هل المجموعة الأولى "مجموعة أم" وبتحتوي على التانية بالكامل؟

.isdisjoint(): هل المجموعتين "منفصلتين" تماماً؟ (يعني مفيش بينهم أي تقاطع أو عيش وملح.. لو مفيش مشترك ترجع True).

"""

import time
import os

# أشكال الرقصة بالـ ASCII
dance_moves = [
    "   (•_•) / \n   <)   )  \n   /    \ ",  # الحركة الأولى
    "  \(•_•)   \n    (   (> \n   /    \ ",  # الحركة الثانية
    "   (•_•)   \n   <)   (> \n   /    \ "   # الحركة الثالثة
]

print("🎵 شغل مزيكا البستوت.. بايثون هترقص حالاً! 🎵\n")
time.sleep(2)

# هترقص 10 مرات
for i in range(10):
    for move in dance_moves:
        os.system('cls' if os.name == 'nt' else 'clear') # مسح الشاشة
        print("\n" * 5) # ترحيل لتحت عشان الترتيب
        print(move)
        time.sleep(0.3) # سرعة الرقصة

print("\n💃 تعبت وهبطت خلاص يا هندسة.. اروح اكل بستوت بقا!")
see={1,2}

