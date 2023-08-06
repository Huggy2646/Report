#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

int time=0;
int memory = 1000;

struct ps{
    int pid;
    int input_time;
    int run_time;
    int size;
};

struct in_m_stat{
    int adress=0;
    int pid=0;
    int size=0;
    int out_time=-1;
};

vector<ps>wait_que;

int main(){
    int last_ps_adress;
    // 메모리에 push 할 상태의 값 처음 값을 초기화 할 때 초기값을 넣는다.
    in_m_stat data;
        data.adress=0;
        data.pid=-1;
        data.size=1000;
    // 메모리를 vector로 표현
    vector<in_m_stat>memory_vec;
    // 메모리의 초기상태 초기화
    memory_vec.push_back(data);
    // data processing 
    string filePath = "1.inp";
    ifstream Fin(filePath);
    int t_n_of_ps;
    Fin >> t_n_of_ps;
    vector<ps>ps_s(t_n_of_ps);
    for(int i=0; i<t_n_of_ps; i++){
        ps_s[i].pid = i;
        Fin >> ps_s[i].input_time;
        Fin >> ps_s[i].run_time;
        Fin >> ps_s[i].size;
    }
    int max_time = ps_s[ps_s.size()-1].input_time;
    // for(int k=0; k<t_n_of_ps; k++)
    //     cout << "time: "<<ps_s[k].input_time<<" run_time: "<<ps_s[k].run_time<<" size: "<<ps_s[k].size<<"\n";
    // input time check. if input_time==current_time --> push in the memory vector
    //first fit
    for(int i=0; i<t_n_of_ps; i++){
        for(int j = 0; j<memory_vec.size(); j++){
            if(memory_vec[j].out_time == time){
                memory_vec[j].pid = -1;
                memory_vec[j].out_time=-1;
            }
        
        }
        // hole 합치기
        for(int j=0; j<memory_vec.size()-1; j++){
            if(memory_vec[j].pid==-1 && memory_vec[j+1].pid==-1){
                int size2 = memory_vec[j+1].size;
                memory_vec.erase(memory_vec.begin() + (j+1));
                memory_vec[j].size+=size2;
                
                j--; 
            }
            
        }
        cout <<"\n";

        if(wait_que.size()!=0){
            // cout << "hello";
            int que_size=wait_que.size();
            int memory_vec_size=memory_vec.size();
            for(int x=0; x<wait_que.size(); x++){
                    for(int j = 0; j<memory_vec_size; j++){
                        if(memory_vec[j].pid==-1 && wait_que[x].size<=memory_vec[j].size){
                            int hole_adress=memory_vec[j].adress;
                            int hole_size=memory_vec[j].size;
                            memory_vec.erase(memory_vec.begin()+j);
                            
                            //ps
                            data.adress=hole_adress;
                            data.pid=wait_que[x].pid;
                            data.size=wait_que[x].size;
                            data.out_time = time+wait_que[x].run_time;
                            memory_vec.insert(memory_vec.begin() + j, data);

                            int ps_adress=memory_vec[j].adress;
                            int ps_size=memory_vec[j].size;


                            //hole
                        if(hole_size!=memory_vec[j].size){
                                data.adress=ps_adress+ps_size;
                                data.pid=-1;
                                data.size=hole_size-ps_size;
                                data.out_time = -1;
                                memory_vec.insert(memory_vec.begin() + j+1, data);
                        }
                            last_ps_adress = hole_adress;
                            wait_que.erase(wait_que.begin()+x);
                            x--;
                        }
                        
                    }
            cout << x << "\n";
            cout <<"\n";
            }

        }
        cout << ps_s[i].input_time;
        cout << time <<"\n";

        if(ps_s[i].input_time==time){
            // 만약 hole을 검색했는데 들어갈 곳 없으면 대기큐로 들어감
            // checking hole (first fit)
            int memory_vec_size=memory_vec.size();
            for(int j = 0; j<memory_vec_size; j++){
                if(memory_vec[j].pid==-1 && ps_s[i].size<=memory_vec[j].size){
                    int hole_adress=memory_vec[j].adress;
                    int hole_size=memory_vec[j].size;
                    memory_vec.erase(memory_vec.begin()+j);
                    
                    //ps
                    data.adress=hole_adress;
                    data.pid=ps_s[i].pid;
                    data.size=ps_s[i].size;
                    data.out_time = time+ps_s[i].run_time;
                    memory_vec.insert(memory_vec.begin() + j, data);

                    int ps_adress=memory_vec[j].adress;
                    int ps_size=memory_vec[j].size;

                    //hole
                    if(hole_size!=memory_vec[j].size){
                        data.adress=ps_adress+ps_size;
                        data.pid=-1;
                        data.size=hole_size-ps_size;
                        data.out_time = -1;
                    
                        memory_vec.insert(memory_vec.begin() + j+1, data);
                    }
                    
                    last_ps_adress = hole_adress;
                    break;
                }
                else{
                    if(j==memory_vec_size-1){
                        wait_que.push_back(ps_s[i]);

                    }
                }
                
            }  
            
        }
        else
            i--;
        time++;

    for(int k=0; k<memory_vec.size(); k++)
        cout << "ar: "<<memory_vec[k].adress<<" pid: "<<memory_vec[k].pid<<" size: "<<memory_vec[k].size<<" out_time: " << memory_vec[k].out_time << "\n";
    cout << "\n";
    cout << "quesize : " << wait_que.size() << "\n";
    }

    cout << last_ps_adress;


    return 0;
}