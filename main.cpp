#include <iostream>
#include <vector>
using namespace std;

class Thread{

private:
    int * pos;
    int id;
    int nt;
    Thread(int a,int b)
    {
        id=a;
        nt=b;
        int t[b];
        pos=t;
        for(int i=0;i<b;i++)
        {
            pos[i]=0;
        }
    }
    int *getPos()
    {
        return pos;
    }
    int getId()
    {
        return id;
    }
    void doTask()
    {
        pos[id]++;
    }
    void sendMessage(Thread t)
    {
        int * tmp=t.getPos();
        for(int i=0;i<nt;i++)
        {
            tmp[i]=max(tmp[i],pos[i]);
        }
    }
};
int main() {
    int nt,close=1,opcion,opcion2,opcion3;
    cout<<"Give the number of threads"<<endl;
    cin>>nt;
    vector <Thread> vt;
    for(int i=0;i<nt;i++)
    {

    }
    while(close)
    {
        cout<<"Fidge Time"<<endl<<"Press 1 to select a thread"<<endl;
        cout<<"Press 2 to exit";
        cin>>opcion;
        if(opcion == 1)
        {
            cout<<"Give me the number of thread you want to acces"<<endl;
            cin>>opcion2;
            if(opcion2<=nt && opcion2>0)
            {
                cout<<"Press 1 to Do a task with the thread"<<endl;
                cout<<"Press 2 to send a message to a thread"<<endl;
                cin>>opcion3;
                if(opcion3==1 || opcion3==2)
                {
                    if(opcion3==1)
                    {

                    }
                }
            }

        }
        else
        {
            close=0;
        }

    }

    
    return 0;
}



