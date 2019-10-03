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
            int **row;

        }
        void show_data()
        {
            cout<<m<<" "<<n<<endl;
            for(int i=0;i<10;i++){
                cout<<data[i].getblock()<<" "<<data[i].getstart_col()<<endl;
            }
        }
        void setmatrix()
        {
            row=new int*;
            for(int i=0;i<m;i++){
              row[i]=new int [n];
            }

        }
        void showmatrix()
        {
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    cout << row[i][j] << " ";
                }
                cout << endl;
            }
        }




};


int main()
{
    block_data *data;
    int m,n,i=0;
    ifstream test_case;
    test_case.open("C:\\Users\\ACER\\Desktop\\�굲\\project1\\tetris.data.txt",ios::in);
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
    block.setmatrix();
    block.showmatrix();
    delete []data;


}
