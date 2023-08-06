#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

struct p_info{
    int name;
    vector<int> max;
    vector<int> alloc;
    vector<int> need;
};
int end_p=0;
int n=0;
queue<int> que_p_n;
queue<vector<int>> que_r_vec;
string result_string="";
//safe squence생성 여부를 보고 deadlock 판단 deadlock이 생기면 0 아니면 1
int deadlock(int m, struct p_info pi[], vector<int>av){
    vector<int> safe_s(m,0);
    vector<bool> bl(n,false);
    for(int i=0; i<n; i++){
        int count=0;
        if(bl[i]==false){
            for(int j=0; j<m; j++){
                if(pi[i].need[j] <= av[j]){
                    count++;
                }
                else
                    break;
            }
            if(count==m){
                bl[i]=true;
                for(int k=0; k<m; k++){
                    av[k]+=pi[i].alloc[k];
                }
                i=-1;
            }
        
        }
    
    }

    for(int i=0; i<n; i++){
        if(bl[i]==true)
            continue;
        else
            return 1;
    }
    return 0;
            
}
   
//rq와 rl연산 후 deadlock 판단 deadlock생기면 queue에 정보 넣기, rq_or_rl==1 request else ==0 release
int rq_rl(int m,int p_n, struct p_info pi[], vector<int>av,vector<int> r){
    for(int i=0; i<m; i++){
        if(r[i]<=av[i]){
            continue;
        }
        else{
            que_p_n.push(p_n);
            que_r_vec.push(r);
            return 2;
        }
    }

    //need와 available에 r연산
    for(int i=0; i<m; i++){
        pi[p_n].need[i]-=r[i];
        pi[p_n].alloc[i]+=r[i];
        av[i]-=r[i];
    }
    if(deadlock(m,pi,av)==0){
        return 1;
    }
    else{
        que_p_n.push(p_n);
        que_r_vec.push(r);
        return 0;
    }
        
   
}

int main(){
    string filePath = "banker.inp";
    ifstream Fin(filePath.data());
    string c="";
    int m;
    Fin>>n;
    Fin>>m;
    struct p_info pi[n];
    vector <int> t_n_of_source(m,0);
    for (int i=0; i<m; i++){
        Fin >> t_n_of_source[i];

    }
    //max vector and input pi struct
    vector <int> max1(m,0);
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            Fin >> max1[j];

        }
        pi[i].name=i;
        pi[i].max=max1;
    }
    //alloc vector and input pi struct
    vector <int> alloc1(m,0);
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            Fin >> alloc1[j];
        }
        pi[i].alloc=alloc1;
    }
    // need vector
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            pi[i].need.push_back(pi[i].max[j]-pi[i].alloc[j]);
    }
    vector <int>avail=t_n_of_source;
    for(int i=0; i<m; i++){
        for(int j=0;j<n; j++){
            avail[i]-=pi[j].alloc[i];
        }
    }
    //request,release vector
    dooli:
    while(true){
        vector<int> r;
        Fin >> c;
        if(c=="quit"){
            break;
        }
        int bo=0;
        int rq_p_num=0;
        Fin >> rq_p_num;
        for(int i=0; i<m; i++){
            int v;
            Fin >> v;
            r.push_back(v);
        }

        if(c=="request"){
            // 여기에 deadlock 판단
            // request와 need 비교 request가 크면 무시
            for (int i=0; i<m; i++){
                if(r[i]<=pi[rq_p_num].need[i])
                    continue;
                else
                    goto dooli;
            }
            // 여기에 request후 deadlock판단
            // deadlock없으면 update 연산
            // deadlock(m,pi,avail);
            int result = rq_rl(m,rq_p_num,pi,avail,r);
            if(result==1){
                for(int i=0; i<m; i++){
                        avail[i]-=r[i];
                    }
            }
            else if(result == 2){
                for(int i=0; i<m; i++){
                    result_string+=(to_string(avail[i])+" ");
                } 
                result_string+="\n";
                continue;
            }
            else{
                for(int i=0; i<m; i++){
                    pi[rq_p_num].need[i]+=r[i];
                    pi[rq_p_num].alloc[i]-=r[i];
                }
            }
        }
        else if(c=="release"){
            for(int i=0; i<m; i++){
                pi[rq_p_num].need[i]+=r[i];
                pi[rq_p_num].alloc[i]-=r[i];
                avail[i]+=r[i];
            }
            int q_size=que_p_n.size();
            if(q_size!=0){
                dooli2:
                for(int i=0; i<q_size; i++){
                    rq_p_num=que_p_n.front();
                    que_p_n.pop();
                    r=que_r_vec.front();
                    que_r_vec.pop();
                    for (int i=0; i<m; i++){
                        if(r[i]<=pi[rq_p_num].need[i])
                            continue;
                        else
                            goto dooli2;
                    }
                    
                    // 여기에 request후 deadlock판단
                    // deadlock없으면 update 연산
                    // deadlock(m,pi,avail);
                    int result2=rq_rl(m,rq_p_num,pi,avail,r);
                    if(result2==1){
                        for(int i=0; i<m; i++){
                                avail[i]-=r[i];
                            }
                    }
                    else if(result2 ==2){
 
                    }
                    else{
                        for(int i=0; i<m; i++){
                            pi[rq_p_num].need[i]+=r[i];
                            pi[rq_p_num].alloc[i]-=r[i];
                        }
                    }
                    
                }
            }
        }
       for(int i=0; i<m; i++){
           result_string+= (to_string(avail[i])+" ");
       } 
        result_string+="\n";
       
       if(c=="quit"){
           break;
       }
    }
// cout << result_string;
string filepath = "banker.out";
ofstream writeFile(filepath.data());
if(writeFile.is_open()){
    writeFile << result_string;
    writeFile.close();
}
return 0;
}


