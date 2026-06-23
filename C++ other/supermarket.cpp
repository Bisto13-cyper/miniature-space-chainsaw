#include <iostream>
#include<string>
#include <vector>
#include<ctime>

class product{
protected:
double price;
std::string name;
int id;
std::string maker;
public:
product (double p,std::string n,int i,std::string m){
	price=p;
	name=n;
	id=i;
	maker=m;
	
}
virtual void getinfo(){
std::cout<<"name: "<<name<<"\n ";	
std::cout<<"maked by: "<<maker<<"\n ";
std::cout<<"id: "<<id<<"\n ";
std::cout<<"price: "<<price<<"\n ";
}
int virtual checkid(int chid){
    if(chid==id){
return 1;

    }
    else 
    return 0;


}
float virtual sell (int chid){
if (chid==id)
return price;
else
return 0;




}
virtual void  change(){
int se;
while(true){
std::cout<<"1-name \n 2-maker \n 3-ID \n 4-price \n  All 5 \n end 0 \n";

std::cin>>se;
switch (se){
	case 1:
std::cout<<"enter new name \n";
std::cin>>name;
break;
case 2:
std::cout<<"enter new maker \n";
std::cin>>maker;
break;
case 3:
std::cout<<"enter new ID \n";
std::cin>>id;
break;
case 4:
std::cout<<"enter new price \n";
std::cin>>price;
break;
case 5:
std::cout<<"enter new name \n";
std::cin>>name;
std::cout<<"enter new Id \n";
std::cin>>id;
std::cout<<"enter new price \n";
std::cin>>price;
std::cout<<"enter new maker \n";
std::cin>>maker;
break;
case 0:
break;
default :
std::cout<<"wrong choise";





}
if (se==0)
break;
}

	
}
virtual ~product (){}
	
};
class food:public product{
	private:
	int expiry;
	time_t exp;
	public:
 food (double p,std::string n,int i,std::string m,int e):	product (p,n,i,m) {

    expiry=e;
    exp=time(0);	
}
	

void getinfo ()	override{
	bool disc=false;
	product::getinfo();
	time_t end=time(0);
	if(!disc && expiry*0.5<=difftime (end,exp)){
price=price-(price*0.2);
disc=true;
	}
		std::cout<<"price after dicussing is "<<price<<"\n ";

		}	
};
class elctronics:public product{
private:

 int warrnty;
std::string type;

public	:
 elctronics (std::string n,int i,double p,std::string m,std:: string ty,int w):	product (p,n,i,m){

type=ty;
warrnty=w;
}

void getinfo ()override{
	product::getinfo();
	std::cout<<"type is "<<type<<"\n warrnty is "<<warrnty<<" months \n";
}
};

void	mangermenu(std:: vector <product*> &inventory);
void    addfood (std:: vector <product*>& inventory);
void    addelc(std::vector<product*> &inventory );
void removeproduct(std::vector<product*>&inventory);
void	mangermenu(std:: vector <product*> &inventory,std::string* name,std::string* pas);
void   customermenu(std::vector <product*> &inventory);
void   showfp (std::vector <product*> &inventory);
void   showep (std::vector <product*> &inventory);
void   buy(std::vector <product*> &inventory);
void  complain(int);
void  changeproudct (std::vector <product*> &inventory);

int main(){
std::string name,pas;
int ch;

std::vector <product*> inventory;
std::cout<<"enter your supermaket's name";
  std::getline(std::cin >> std::ws, name);
std::cout<<"enter a new password";
std::cin>>pas;
while (true){
std::cout<<"wellcome to "<<name<<" supermarket \n ~~~~~~what do you wanna to do~~~~~~ \n";
std::cout<<"first ! Are you \n 1- manger \n 2- customer \n";
std::cin>>ch;
switch(ch){
case 1:{
	std::string pasch;
	int wrong=0;
	while(true){
std::cout<<"enter password";
std::cin>>pasch;
if (pasch==pas){
std::cout<<"hello manger what do wanna do";
	mangermenu(inventory,&name,&pas);
	break;
}
else{
	std::cout<<"wrong pas pleas try again later \n";
if(wrong==3)
{
	std::cout<<"errrrrrrrroer! \n";
	break;
}
else
wrong++;

	
		
		
}
	}
}
break;
case 2:
customermenu (inventory);
break;
	

	
}
}



};

void	mangermenu(std:: vector <product*> &inventory,std::string* name,std::string* pas){
	int ch;
	std::cout<<" \n 1- add product \n 2-remove product \n 3-change proudct info \n 4-settings market  5-see complaints  \n ";
std::	cin>>ch;
	switch (ch){
	case 1: {
	int ch1;	
std::		cout<<"enter type of prouduct \n food (1) \n elctronics (2) \n ";
std::		cin>>ch1;
switch (ch1){
case 1:
addfood(inventory);
break;	
case 2:
addelc(inventory);
break;
default:
std::cout <<"wrong choise ";
}
		   
	
	
	
	}
break;
    case 2:
 removeproduct(inventory);



break;
	case 3:
changeproudct (inventory);
break;
	case 4 :{
		int ch1;
	std::cout<<"change name (1) password (2)";
	std::cin>>ch1;
	switch (ch1){
case 1:
std::cout<<"enter new name";
std::cin>> *name;
break;
	case 2: 
std::cout<<"enter new password";
std::cin>> *pas;

	break;

	}
	}
break;	
case 5:
complain(2);
break;
	}

}

void addfood (std:: vector <product*> &inventory) {
	double price;
std::string name;
int id;
std::string maker;
	int expiry;
std::cout<< "enter name";
std::cin>>name;
std::cout<< "enter price";
std::cin>>price;
std::cout<< "enter maker";
std::cin>>maker;
std::cout<< "enter id";
std::cin>>id;
std::cout<< "enter expiry";
std::cin>>expiry;
inventory.push_back (new food  (price, name, id, maker, expiry));



}

void addelc(std::vector<product*> &inventory){
	
		double price;
std::string name;
int id;
std::string make,type;
	int expiry;
	int warrnty;
std::cout<< "enter name";
std::cin>>name;
std::cout<< "enter price";
std::cin>>price;
std::cout<< "enter maker";
std::cin>>make;
std::cout<< "enter id";
std::cin>>id;
std::cout<< "enter type";
std::cin>>type;
std::cout<< "enter warrnty";
std::cin>>warrnty;
inventory.push_back (new elctronics (  name, id, price, make, type, warrnty));



}
void removeproduct(std::vector<product*>&inventory){
std::cout<<"Enert id \n";
int chid;
std::cin>>chid;
for (auto i=inventory.begin();i!=inventory. end();i++){
if(((*i)->checkid(chid))==1){
delete *i;
inventory.erase(i);
std::cout<<"Proudct removed \n";
return;

}


}
std::cout<<"Id not founded";





}

void changeproudct (std::vector <product*> &inventory){
	std::cout<<"enter ID";
	int chid,yes=0;
	std::cin>>chid;
for (auto i=inventory.begin();i!=inventory. end();i++){
if(((*i)->checkid(chid))==1){

(*i)->getinfo();
std::cout<<"which info want you to change \n ";
(*i)->change ();
yes=1;
break;
}


}
if(yes==0)
std::cout<<"Id not founded \n";
}
void  customermenu(std::vector <product*> &inventory){
	int che;
std::cout<<"Hello sir how can i help you today \n show food info (1) \n show elctronics info (2) \n buy proudcts (3) \n make a compliant (4) \n";
std::cin>>che;
switch (che){
case 1:
showfp(inventory);
break;
case 2:
showep(inventory);
break;
case 3:
buy(inventory);
break;
case 4: 
complain(1);
break;


}

}
void   showfp (std::vector <product*> &inventory){
std::cout<<"The food menu \n";
bool found=false;

for(auto* it :inventory){



food* foodPtr = dynamic_cast<food*> (it);
if (foodPtr!=nullptr){
foodPtr-> getinfo();
found =true;
}




}
if (found==false)
std::cout<<"No food here";
}






void   showep (std::vector <product*> &inventory){
std::cout<<"the electronic menu \n";
bool found=false;
for (auto* i:inventory){
elctronics* elcPtr =dynamic_cast <elctronics*> (i);

if (elcPtr !=nullptr){
elcPtr->getinfo();
found=true;


}





}
if (found==false)
std::cout<<"No elctronics here";


}

void buy(std::vector <product*> &inventory){
	int menu;
		float total=0 ;

std::cout<<"Do you wanna see menu \n yes (1) No (0) \n";
std::cin>>menu;

if (menu==1){

showfp(inventory);
showep (inventory);



}
else if (menu==0){}

else 
std::cout <<"wrong choise";

while (true){
	float id;
std::cout<<"enter id \n end shopping 0 \n";
std::cin>> id;

if (id==0)
break;

for (auto* it:inventory){
	if (it->checkid(id)==1){
total+= it->sell(id);
break;
	}


}



}
std::cout<<"total price is"<<total<<std::endl;






}
void complain (int check){
	int x=0;
static std::vector <std::string> complain;
std::string comp;
if(check==1){
std::cout<<"write a complaint \n";
std::cin.ignore();
getline(std::cin, comp);
complain.push_back (comp);


}
else if (check==2){

for (auto i:complain){
	
std::cout<<x++<<"- "<<i<<std::endl;



}
std::cout<<"Do you wanna delet it ? \n yes (1)  No (2)  \n";
int ch;
std::cin>>ch;
if (ch==1){
complain.clear();
x=0;
}
else if (ch==2);

else 
std::cout<<"wrong choise ";




}



}



