#include <iostream>
#include <fstream>

using namespace std;

string user, pass, users[100][2], name, pas, id, id2, bal, tgid;
int tryy=0, acc, k=0;

void login (string user, string pass, int tryy){
    cout<<endl;
cout<<"Login: "<<endl;
cout<<endl;
cout<< "User: ";
cin>>user;
cout<<"Password: ";
cin>>pass;

ifstream ReadInfo("UserInfo.txt");
for(int i=0; i<100; i++){
getline(ReadInfo, id);
getline(ReadInfo, name);
getline(ReadInfo, pas);
getline(ReadInfo, bal);
if(name=="UserName: " + user && pas=="Password: " + pass){
        tgid=id;
    cout<<"Welcome"<<endl;
    cout<<endl;
    ReadInfo.close();
    return;
}
}
    tryy=tryy+1;
    if(tryy!=3){
    cout<<endl;
    cout<<"Wrong, "<<3-tryy<<" tries left:"<<endl;
    login(user, pass, tryy);
    }
    else{
    cout<<"Locked out";
    abort();
    }
}


void Users(){
ifstream ReadInfo("UserInfo.txt", ios::app);
cout<<"Create a account:"<<endl;
for(int i=1; i<101; i++){
getline(ReadInfo, id);
getline(ReadInfo, name);
getline(ReadInfo, pas);
getline(ReadInfo, bal);
if(id==""){
cout<<"\nUsername: ";
cin>>users[i][0];
cout<<"Password: ";
cin>>users[i][1];
cout<<endl;
ofstream Info("UserInfo.txt", ios::app);
Info<<i<<": \n"<<"UserName: "<<users[i][0]<<"\nPassword: "<<users[i][1]<<"\nBalance: "<<0<<"\n";
Info.close();
ReadInfo.close();
login(user, pass, tryy);
return;
}
}
}


void InPut(int nauda){

fstream ReadInfo("UserInfo.txt");

for(int i=0; i<9999; i++){

getline(ReadInfo, id);


if(id==tgid){

ReadInfo.close();
string textt[9999], line;
int x=0;
ifstream Info("UserInfo.txt");

while(getline(Info, line)){
textt[x]=line;
x=x+1;
}

size_t pos = textt[i+3].find(":");
if (pos != string::npos) {
int curbal = stoi(textt[i+3].substr(pos + 2));
int newbal = curbal + nauda;
textt[i + 3] = "Balance: " + to_string(newbal);
}

Info.close();
ofstream ReadInfo("UserInfo.txt", ios::trunc);
for(int j=0; j<x; j++){
ReadInfo<<textt[j]<<endl;

}
ReadInfo.close();
return;
}
}
}


void Balance(){

fstream ReadInfo("UserInfo.txt");

for(int i=0; i<9999; i++){

getline(ReadInfo, id);

if(id==tgid){
getline(ReadInfo, name);
getline(ReadInfo, pas);
getline(ReadInfo, bal);
cout<<bal<<endl;
ReadInfo.close();
return;
}
}
}


void output(int nauda){

fstream ReadInfo("UserInfo.txt");

for(int i=0; i<9999; i++){

getline(ReadInfo, id);

if(id==tgid){

ReadInfo.close();
string textt[9999], line;
int x=0;
ifstream Info("UserInfo.txt");

while(getline(Info, line)){
textt[x]=line;
x=x+1;
}

size_t pos = textt[i+3].find(":");
if (pos != string::npos) {
int curbal = stoi(textt[i+3].substr(pos + 2));
if (curbal >= nauda) {
int newbal = curbal - nauda;
textt[i + 3] = "Balance: " + to_string(newbal);}

else {
cout << "Not enough Money!" << endl;
Info.close();
return;

}
}

Info.close();

ofstream ReadInfo("UserInfo.txt", ios::trunc);

for(int j=0; j<x; j++){
ReadInfo<<textt[j]<<endl;
}
ReadInfo.close();
return;
}
}
}



int main()
{
ofstream Info("UserInfo.txt", ios::app);
int comand=0;

if(k==0){
login(user, pass, tryy);
k=k+1;
}

cout<<"Options:\n (+)Balance: 1 \n (+)Withdraw: 2 \n (+)Deposit: 3 \n (+)Logout: 4 \n";
cout<<"input: ";
cin>>comand;
if(comand==4){
cout<<"\n (+)Login: 1 \n (+)Create new account: 2 \n";
cout<<"input: ";
cin>>comand;
cout<<endl;
if(comand==1)login(user, pass, tryy);
else if(comand==2)Users();
main();
}

else if(comand==3){
int nauda;
cout<<endl;
cout<<"Naudas suma: ";
cin >> nauda;
cout<<endl;
InPut(nauda);
main();
}

else if(comand==2){
int nauda;
cout<<endl;
cout<<"Naudas suma: ";
cin >> nauda;
cout<<endl;
output(nauda);
cout<<endl;
main();
}

else if(comand==1){
cout<<endl;
Balance();
cout<<endl;
main();
}
}
