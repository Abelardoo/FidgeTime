#include <iostream>
#include <vector>
using namespace std;

class Thread{
private:
    int id;
    int nt;
    vector<int> pos;
public:
    Thread(int a,int b)
    {
        id=a;
        nt=b;
        pos.insert(pos.begin(),nt,0);

    }
    vector<int> getPos()
    {
        return pos;
    }
    void updatePos(int a,int b)
    {
        pos[a]=b;
    }

    void dotask()
    {
        pos[id]++;
        printT();
    }

    void printT()
    {
        cout<<"id del proceso "<<id<<endl;
        for(int a:pos)
        {
            cout<<a<<endl;
        }
    }
    void sendMesaage(Thread t)
    {
        int aux=0;
        for(int i=0;i<nt;i++)
        {

            cout<<"testing recv current "<<t.getPos()[i]<<" send current "<<pos[i]<<endl;
            aux=t.getPos()[i]>=pos[i]?t.getPos()[i]:pos[i];
            t.updatePos(i,aux);
        }
        t.printT();
    }


};
int main() {
   int nt,opcion0=1,opcion1,opcion2,opcion3;
    cout<<"Give me the number of threads you need"<<endl;
    cin>>nt;
    vector<Thread> vt;
    for(int i=0;i<nt;i++)
    {
        vt.push_back(Thread(i,nt));
    }
    while(opcion0)
    {
        cout<<"Press 1 to select a thread or 0 to exit"<<endl;
        cin>>opcion0;
        if(opcion0!=0)
        {
            cout<<"Write the number of the thread you want to select where the first Thread is 0"<<endl;
            cin>>opcion1;
            if(opcion1>=0 && opcion1<nt)
            {
                cout<<"Press 1 to do a task with the Thread of 2 to send a Message to other Thread"<<endl;
                cin>>opcion2;
                if(opcion2==1)
                {
                    vt[opcion1].dotask();
                }
                if(opcion2==2)
                {
                    cout<<"Write the number of the thread you want to send the Message"<<endl;
                    cin>>opcion3;
                    if(opcion3!=opcion1 && opcion3>=0 && opcion3<nt)
                    {
                        vt[opcion1].sendMesaage(vt[opcion3]);
                    }
                }
            }
            for(Thread a:vt)
            {
                a.printT();
            }
        }
    }
    return 0;


}
    
