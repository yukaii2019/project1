#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct shape
{
    int r,c;
}SHAPE;
class block_data
{
    private:
        string block;
        int start_col;
        SHAPE shape[4];
        SHAPE det[4];
        int tall;
        
    public:
        string getblock()
        {
            return block;
        }
        int getstart_col()
        {
            return start_col;
        }
        void setblock( string &a , int &b)
        {
            block=a;
            start_col=b-1;
            for(int i=0;i<4;i++) det[i]={-1,-1};
            if(block[0]=='T'){
                if(block[1]=='1'){
                    shape[0]={0,1};shape[1]={1,0};shape[2]={1,1};shape[3]={1,2};   
                    det[0]={0,1};det[1]={1,0};det[2]={1,2};
                    tall=2;
                }
                else if(block[1]=='2'){
                    shape[0]={0,1};shape[1]={1,0};shape[2]={1,1};shape[3]={2,1};  
                    det[0]={0,1};det[1]={1,0};        
                    tall=3;     
                }
                else if(block[1]=='3'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={0,2};shape[3]={1,1};
                    det[0]={0,0};det[1]={0,1};det[2]={0,2};      
                    tall=2;
                }
                else if(block[1]=='4'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={1,1};shape[3]={2,0};
                    det[0]={0,0};det[1]={1,1};
                    tall=3;
                }
            }
            else if(block[0]=='L'){
                if(block[1]=='1'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={1,0};shape[3]={2,0};   
                    det[0]={0,0};det[1]={0,1};
                    tall=3;
                }
                else if(block[1]=='2'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={1,1};shape[3]={1,2};  
                    det[0]={0,0};det[1]={1,1};det[2]={1,2};       
                    tall=2;  
                }
                else if(block[1]=='3'){
                    shape[0]={0,1};shape[1]={1,1};shape[2]={2,0};shape[3]={2,1};
                    det[0]={0,1};det[1]={2,0};   
                    tall=3;   
                }
                else if(block[1]=='4'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={0,2};shape[3]={1,2};
                    det[0]={0,0};det[1]={0,1};det[2]={0,2};
                    tall=2;
                }
            }
            else if(block[0]=='J'){
                if(block[1]=='1'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={1,1};shape[3]={2,1};   
                    det[0]={0,0};det[1]={0,1};
                    tall=3;
                }
                else if(block[1]=='2'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={0,2};shape[3]={1,0};  
                    det[0]={0,0};det[1]={0,1};det[2]={0,2}; 
                    tall=2;        
                }
                else if(block[1]=='3'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={2,0};shape[3]={2,1};
                    det[0]={0,0};det[1]={2,1};    
                    tall=3;  
                }
                else if(block[1]=='4'){
                    shape[0]={0,2};shape[1]={1,0};shape[2]={1,1};shape[3]={1,2};
                    det[0]={0,2};det[1]={1,0};det[2]={1,1};
                    tall=2;
                }
            }
            else if(block[0]=='S'){
                if(block[1]=='1'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={1,1};shape[3]={1,2};   
                    det[0]={0,0};det[1]={0,1};det[2]={1,2};
                    tall=2;
                }
                else if(block[1]=='2'){
                    shape[0]={0,1};shape[1]={1,0};shape[2]={1,1};shape[3]={2,0};  
                    det[0]={0,1};det[1]={1,0};         
                    tall=3;
                }
            }
            else if(block[0]=='Z'){
                if(block[1]=='1'){
                    shape[0]={0,1};shape[1]={0,2};shape[2]={1,0};shape[3]={1,1};   
                    det[0]={0,1};det[1]={0,2};det[2]={1,0};
                    tall=2;
                }
                else if(block[1]=='2'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={1,1};shape[3]={2,1};  
                    det[0]={0,0};det[1]={1,1};         
                    tall=3;
                }
            }
            else if(block[0]=='I'){
                if(block[1]=='1'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={2,0};shape[3]={3,0};   
                    det[0]={0,0};
                    tall=4;
                }
                else if(block[1]=='2'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={0,2};shape[3]={0,3};  
                    det[0]={0,0};det[1]={0,1};det[2]={0,2};det[3]={0,3};    
                    tall=1; 
                }
            }
            else if(block[0]=='O'){
                shape[0]={0,0};shape[1]={0,1};shape[2]={1,0};shape[3]={1,1};  
                det[0]={0,0};det[1]={0,1}; 
                tall=2; 
            }

        }
        SHAPE getdet(int i)
        {
            return det[i];
        }
        SHAPE getshape(int i)
        {
            return shape[i];
        }
        int gettall()
        {
            return tall;
        }


};

class TETRIS
{
    private:
        int m,n;
        block_data *data;
        int *row;
        int num_of_data=0;
    public:
        TETRIS(int a,int b,block_data *c)
        {
            
            data = new block_data[1000];
            m=a;
            n=b;
            data=c;

        }
        TETRIS(){}
        void show_data()
        {
            cout<<m<<" "<<n<<endl;
            for(int i=0;i<num_of_data;i++){
                cout<<data[i].getblock()<<" "<<data[i].getstart_col()<<endl;
            }   
        }
        void settetris()
        {

            row = new int[m*n];
            for(int i=0;i<m*n;i++){
                *(row+i)=0;
            }  
        }
        void showtetris()
        {
           
           for(int i=m-1;i>=0;i--){
               cout << "row" << i+1 << " ";
                for(int j=0;j<n;j++){
                    cout << *(row+i*n+j);
                }
                cout << endl;
                }      
        }
        bool putblock( block_data &block)
        {
            int touch=0;
            int b=0;
            int gameover=0;
            int exceed = 0;
            int puttingrow;
            for(int i=m-1;i>=0&&touch!=1;i--){
                touch=0;b=0;
                for(int j=0;j<4;j++){
                    if(block.getdet(j).r!=-1){   
                        int r=i+block.getdet(j).r;
                        int c=block.getstart_col()+block.getdet(j).c;
                        if(r<m){
                            if(*(row+r*n+c)==1){
                                touch=1;
                            }   
                        }
                    }
                }
                if(touch==1){
                    puttingrow=i+1;
                    b=1; 
                } 
                else if(i==0&&touch==0){
                    puttingrow=0;
                    b=1;
                } 
                if(puttingrow+block.gettall()>m&&b==1)exceed=1;

                if(exceed==0&&b==1){                           
                    for(int k=0;k<4;k++){
                        int rr=puttingrow+block.getshape(k).r;
                        int cc=block.getstart_col()+block.getshape(k).c;
                        *(row+rr*n+cc)=1;
                    }
                    deleterow(puttingrow,block);
                    return gameover;
                }
                else if(exceed==1&&b==1){
                    int exceedpart[4];
                    int pos=0;
                    int numofdelete;
                    int pointexceed=4;
                    for(int k=0;k<4;k++)exceedpart[k]=-1;
                    for(int k=0;k<4;k++){
                        int rr=puttingrow+block.getshape(k).r;
                        int cc=block.getstart_col()+block.getshape(k).c;
                        if(rr<m)
                            *(row+rr*n+cc)=1;
                        if(rr>=m)
                            exceedpart[pos++]=rr*n+cc;
                    }
                    if(n==1&&m==1){
                        int pe=0;
                        int new_exceedpart[4];
                        int pos=0;
                        for(int p=0;p<4;p++){
                            pe=0;
                            pos=0;
                            numofdelete=deleterow(puttingrow,block);
                            for(int k=0;k<pointexceed;k++){
                                if(exceedpart[k]!=-1){
                                    exceedpart[k]=exceedpart[k]-n*numofdelete;
                                    if(exceedpart[k]<m*n){
                                        *(row+exceedpart[k])=1;
                                    }
                                    else if(exceedpart[k]>=n*m){
                                        new_exceedpart[pos++]=exceedpart[k];
                                        pe++;
                                    }
                                }
                            }
                            pointexceed=pe;
                            for(int k=0;k<4;k++){
                                if(k<pointexceed)
                                    exceedpart[k]=new_exceedpart[k];
                                else if(k>=pointexceed)
                                    exceedpart[k]=-1;
                            }
                            if(p==3&&pointexceed!=0){
                                //cout << "gameover" <<endl;
                                gameover=1;
                                return gameover;
                            }       
                            else if(p==3&&pointexceed==0){
                                return gameover;
                            }                  
                        }
                        
                    }
                    else{
                        int pe=0;
                        int new_exceedpart[4];
                        int pos=0;
                        for(int p=0;p<2;p++){
                            pe=0;
                            pos=0;
                            numofdelete=deleterow(puttingrow,block);
                            for(int k=0;k<pointexceed;k++){
                                if(exceedpart[k]!=-1){
                                    exceedpart[k]=exceedpart[k]-n*numofdelete;
                                    if(exceedpart[k]<m*n){
                                        *(row+exceedpart[k])=1;
                                    }
                                    else if(exceedpart[k]>=n*m){
                                        new_exceedpart[pos++]=exceedpart[k];
                                        pe++;
                                    }
                                }
                            }
                            pointexceed=pe;
                            for(int k=0;k<4;k++){
                                if(k<pointexceed)
                                    exceedpart[k]=new_exceedpart[k];
                                else if(k>=pointexceed)
                                    exceedpart[k]=-1;
                            }
                            if(p==1&&pointexceed!=0){
                                //cout << "gameover" <<endl;
                                gameover=1;
                                return gameover;
                            }       
                            else if(p==1&&pointexceed==0){
                                return gameover;
                            }                  
                        }
                    }
                }
            }   
        }
        int deleterow(int puttingrow, block_data &block)
        {   
            int pos=0;
            int numofone=0;
            int row_delete[4];
            for(int i=0;i<4;i++)row_delete[i]=-1;

            for(int k=puttingrow;k<puttingrow+block.gettall()&&k<m;k++){
                numofone=0;
                for(int p=0;p<n;p++){
                    if(*(row+k*n+p)==1)numofone++;             
                }
                if(numofone==n){
                    row_delete[pos]=k;
                    pos++;
                }
            }
            if(row_delete[0]!=-1){
                int isdeleterow=0;
                int pos=0;
                int *new_matrix;
                new_matrix = new int [m*n];
                for(int k=0;k<m;k++){
                    isdeleterow=0;
                    for(int l=0;l<4;l++){
                        if(row_delete[l]!=-1){
                            if(k==row_delete[l]) isdeleterow=1;
                        }
                    }
                    if(!isdeleterow){
                        for(int l=0;l<n;l++){
                            *(new_matrix+pos*n+l)=*(row+k*n+l);
                        }
                        pos++;                            
                    }
                }
                for(int l=pos;l<m;l++){
                    for(int k=0;k<n;k++)
                        *(new_matrix+l*n+k)=0;
                }
                delete [] row;
                row = new_matrix;
            } 
            return pos;      
        }
                

                    
            
        // void setnum_of_data(int a)
        // {
        //     num_of_data=a;
        // }
        int getnum_of_data()
        {
            return num_of_data;
        }
        void write()
        {
            fstream opfile;
            opfile.open("Tetris.output",ios::out);
            if(!opfile){
                cout << "error";
            }
            for(int i=m-1;i>=0;i--){
                for(int j=0;j<n;j++){
                    opfile << *(row+i*n+j);
                }
                opfile << endl;
                }   
            opfile.close();   
            
        }
        block_data* read()
        {
            ifstream rdfile;
            rdfile.open("Tetris.data",ios::in);
            if(!rdfile){
                cout<<"error";
            }
            rdfile >> m >> n;
            data=new block_data [1000];
            while(!rdfile.eof()){
                string a;
                int b;
                rdfile >> a >> b;
                if(a!="End"){
                data[num_of_data].setblock(a,b);
                num_of_data++;
                }
            }
            rdfile.close();
            return data;
        }

};


int main()
{
    block_data *data;
    int GAMEOVER=0;
    
    TETRIS tetris;
    data=tetris.read();
    //tetris.show_data();
    tetris.settetris();

    for(int i=0;i<tetris.getnum_of_data()&&GAMEOVER==0;i++){
        GAMEOVER=tetris.putblock(data[i]);
        //cout << "number" << i+1 << endl;
        //cout<<data[i].getblock()<<" "<<data[i].getstart_col()+1<<endl;
        //tetris.showtetris();
        //cout << endl;
    }
    tetris.write();
    
    
    delete []data;


}
