#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class block_data
{
    private:
        string block;
        int start_col;
    public:
        string getblock()
        {
            return block;
        }
        int getstart_col()
        {
            return start_col;
        }
        void setblock(const string a)
        {
            block=a;
        }

        void setstart_col(const int a)
        {
            start_col=a;
        }
};

class TETRIS
{
    private:
        int m,n;
        block_data *data;
    public:
        TETRIS(int a,int b,block_data *c)
        {
            data = new block_data[1000];
            m=a;
            n=b;
            data=c;

        }
        void show_data()
        {
            cout<<m<<" "<<n<<endl;
            for(int i=0;i<10;i++){
                cout<<data[i].getblock()<<" "<<data[i].getstart_col()<<endl;
            }
        }




};


int main()
{
    block_data *data;
    int m,n,i=0;
    ifstream test_case;
    test_case.open("C:\\Users\\ACER\\Desktop\\¸êµ²\\project1\\tetris.data.txt",ios::in);
    if(!test_case){
        cout<<"error";
    }
    test_case >> m >> n;
    data=new block_data [1000];
    while(!test_case.eof()){
        string a;
        int b;
        test_case >> a >> b;
        if(a!="End"){
            data[i].setblock(a);
            data[i].setstart_col(b);
            i++;
        }
    }
    test_case.close();
    TETRIS block(m,n,data);
    block.show_data();
    delete []data;


}
