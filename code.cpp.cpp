/* Mohammad Ali Hassan    */
/* Created 07-07-23 */


#include <bits/stdc++.h>
using namespace std;

struct details // structure that contains the data of the customer
{
    string name;
    long long phone;
    string pin;
    int slot;
    details(string n,long long m,string p,int a)
    {
        name=n;
        phone=m;
        pin=p;
        slot=a;
    }
};

void choice() // enter the choice of operation to be performed
{
    cout<<"Enter your choice :"<<endl;
    cout<<"1.park 2 wheeler"<<endl;
    cout<<"2.park 4 wheeler"<<endl;
    cout<<"3.leave from 2 wheeler"<<endl;
    cout<<"4.leave from 4 wheeler"<<endl;
    cout<<"5.print ticket"<<endl;
    cout<<"6.get a overview of parking lot (admins only)"<<endl;
    cout<<"7.Exit"<<endl;
}

void view(int arr[3][10]) // gives the view of the parking place
{
    for(int i=0;i<3;i++) // check the parking place;
    {
        for(int j=0;j<10;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        
                cout
            << endl;
    }
    cout<<endl;
}

int findSlot(int arr[3][10]) // checks for the empty slot and returns the slot no if available or 0 if not available
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i][j]==0)
            {
                return (i+1)*10+(j+1);
            }
        }
    }
    return 0;
}

int main()
{
    
    unordered_map<int,details*>m1; // data of two wheeler 
    unordered_map<int,details*>m2; // data of 4 wheeler

    // array for 2 wheeler parking 
    int two_w[3][10]={0};
    for(int i=0;i<3;i++)
    {
        int flag=0;
        for(int j=0;j<10;j++)
        {
            two_w[i][j]=1;
            if(i==1 && j==5)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    // cout<<"2_wheeler"<<endl;
    // view(two_w);

    // array for 4 wheeler parking
    int four_w[3][10]={0};
    for(int i=0;i<3;i++)
    {
        int flag=0;
        for(int j=0;j<10;j++)
        {
            four_w[i][j]=1;
            if(i==2 && j==3)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    // cout<<"4_wheeler"<<endl;
    // view(four_w);
int flag=0;   
while(flag==0)
{


    int x;
    choice();
    cin>>x;
    
    switch (x) {
    case 1:
    {
        int a=findSlot(two_w);
        if(a==0)cout<<"Sorry! no space available for parking"<<endl;
        else
        {
            cout<<"enter your vehicle no."<<endl;
            int vehicleNO;
            cin>>vehicleNO;
            cout<<"enter your name"<<endl;
            string name;
            cin>>name;
            cout<<"enter your phone no"<<endl;
            long long phoneN;
            cin>>phoneN;
            string s;
            s.append("2");
            string temp=to_string(vehicleNO);
            s.append(temp);
            s.append(to_string (a));

            details * d=new details(name,phoneN,s,a);
            m1[vehicleNO]=d;
            string temp2;
            if(a/10==1)temp2.append("A");
            else if(a/10==2)temp2.append("B");
            else if(a/10==3)temp2.append("c");
            temp2.append(to_string(a%10));
            cout<<endl;
            cout<<"your vehicle parking pin is "<<s<<endl;
            cout<<"DO NOT FORGET TO *Note your parking pin "<<endl;
            cout<<"please park you vehicle at "<<temp2<<endl;
            int i=(a/10)-1;
            int j=(a%10)-1;
            two_w[i][j]=1;
            
        }
        break;
    }

    case 2:
    {

        int a=findSlot(four_w);
        
        if(a==0)cout<<"Sorry! no space available for parking"<<endl;
        else
        {
            cout<<"enter your vehicle no."<<endl;
            int vehicleNO;
            cin>>vehicleNO;
            cout<<"enter your name"<<endl;
            string name;
            cin>>name;
            cout<<"enter your phone no"<<endl;
            long long phoneN;
            cin>>phoneN;
            string s;
            s.append("4");
            string temp=to_string(vehicleNO);
            s.append(temp);
            s.append(to_string (a));

            details * d=new details(name,phoneN,s,a);
            m2[vehicleNO]=d;
            string temp2;
            if(a/10==1)temp2.append("A");
            else if(a/10==2)temp2.append("B");
            else if(a/10==3)temp2.append("c");
            temp2.append(to_string(a%10));
            cout<<endl;
            cout<<"your vehicle parking pin is "<<s<<endl;
            cout<<"DO NOT FORGET TO *Note your parking pin "<<endl;
            cout<<"please park you vehicle at "<<temp2<<endl;
            
            int i=(a/10)-1;
            int j=(a%10)-1;
            four_w[i][j]=1;

            
        }
        break;
    }
    case 3:
    {
        int no;
        cout<<"enter your vehicle no."<<endl;
        cin>>no;
        string s;
        cout<<"enter parking pin"<<endl;
        cin>>s;
        if(m1[no]->pin!=s)cout<<"invalid pin"<<endl;
        else
        {
            cout<<"thankyou for using our service"<<endl;
            cout<<"you can take your vehicle from the parking slot "<<endl;
            int x=m1[no]->slot;
            m1[no]->slot=-1;
            int i=(x/10)-1;
            int j=(x%10)-1;
            two_w[i][j]=0;

        }
        break;
    }
    case 4:
    {
        int no;
        cout<<"enter your vehicle no."<<endl;
        cin>>no;
        string s;
        cout<<"enter parking pin"<<endl;
        cin>>s;
        if(m2[no]->pin!=s)cout<<"invalid pin"<<endl;
        else
        {
            cout<<"thankyou for using our service"<<endl;
            cout<<"you can take your vehicle from the parking slot "<<endl;
            int x=m2[no]->slot;
            m2[no]->slot=-1;
            int i=(x/10)-1;
            int j=(x%10)-1;
            four_w[i][j]=0;

        }
        break;
    }

    case 5:
    {
        cout<<"enter the type of your vehicle that is 2 for two wheeler and 4 for four wheeler :"<<endl;
        int t;
        cin>>t;
        if(t==2)
        {
            int no;
            cout<<"enter your vehicle no"<<endl;
            cin>>no;
            if(m1.find(no)==m1.end())
            {
                cout<<"no data available "<<endl;
                break;
            }
            string p;
            cout<<"enter the parking pin "<<endl;
            cin>>p;
            if(m1[no]->pin!=p)cout<<"incorrect pin "<<endl;
            else 
            {
                cout<<endl;
                cout<<"name : "<<m1[no]->name<<endl;
                cout<<"vehicle no : "<<no<<endl;
                if(m1[no]->slot!=-1)
                {
                    int sl=m1[no]->slot;
                    string temp2;
                    if(sl/10==1)temp2.append("A");
                    else if(sl/10==2)temp2.append("B");
                    else if(sl/10==3)temp2.append("c");
                    temp2.append(to_string(sl%10));
                    cout<<"your vehicle is parked at "<<temp2<<endl;
                }
                else cout<<"vehicle not parked "<<endl;
            }

        }
        else if(t==4)
        {
            int no;
            cout<<"enter your vehicle no"<<endl;
            cin>>no;
            if(m2.find(no)==m2.end())
            {
                cout<<"no data available "<<endl;
                break;
            }
            string p;
            cout<<"enter the parking pin "<<endl;
            cin>>p;
            if(m2[no]->pin!=p)cout<<"incorrect pin "<<endl;
            else 
            {
                cout<<endl;
                cout<<"name : "<<m2[no]->name<<endl;
                cout<<"vehicle no : "<<no<<endl;
                if(m2[no]->slot!=-1)
                {
                    int sl=m2[no]->slot;
                    string temp2;
                    if(sl/10==1)temp2.append("A");
                    else if(sl/10==2)temp2.append("B");
                    else if(sl/10==3)temp2.append("c");
                    temp2.append(to_string(sl%10));
                    cout<<"your vehicle is parked at "<<temp2<<endl;
                }
                else cout<<"vehicle not parked "<<endl;
            }
            
        }
        else cout<<"please enter a valid input"<<endl;
        break;
    }
    case 6:
    {
        cout<<"*Note : only for admin use"<<endl;
        int adminPin;
        cout<<"enter the admin pin"<<endl;
        cin>>adminPin;
        if(adminPin==1234)
        {
            cout<<"2 wheeler parking space"<<endl;
            view(two_w);
            cout<<"4 wheeler parking space";
            cout<<endl;
            view(four_w);
        }
        else cout<<"incorrect pin"<<endl;
    }
    case 7:
    {
        flag=1;
        break;
    }
    default:
        cout<<"invalid input"<<endl;
        break;
    }

    cout<<endl;
}   
    return 0;
}

// admin pin 1234